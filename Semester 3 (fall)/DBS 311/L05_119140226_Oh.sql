-- ***********************
-- Name: Gyeongrok oh
-- ID: 119140226
-- Date: Dec 3,2023
-- Purpose: Lab 5 DBS301
-- ***********************
--Q1
SET SERVEROUTPUT ON;

CREATE OR REPLACE PROCEDURE CheckEvenOdd (
    p_number IN NUMBER
)
AS
    is_even BOOLEAN := TRUE; -- Initialize as even
    i NUMBER := 0;
BEGIN
    WHILE i < p_number LOOP
        is_even := NOT is_even;
        i := i + 1;
    END LOOP;

    IF is_even THEN
        DBMS_OUTPUT.PUT_LINE('The number ' || ' is even.');
    ELSE
        DBMS_OUTPUT.PUT_LINE('The number '||'is odd.');
    END IF;
END CheckEvenOdd;
/
BEGIN
    CheckEvenOdd(7);
END;
/


--Q2
CREATE OR REPLACE PROCEDURE find_employee(
    p_employee_id IN NUMBER
)
AS
    v_first_name employees.first_name%TYPE;
    v_last_name employees.last_name%TYPE;
    v_email employees.email%TYPE;
    v_phone employees.phone_number%TYPE;
    v_hire_date employees.hire_date%TYPE;
    v_job_title employees.job_id%TYPE;
BEGIN
 
    SELECT first_name, last_name, email, phone_number, hire_date, job_id
    INTO v_first_name, v_last_name, v_email, v_phone, v_hire_date, v_job_title
    FROM employees
    WHERE employee_id = p_employee_id;


    DBMS_OUTPUT.PUT_LINE('First name: ' || v_first_name);
    DBMS_OUTPUT.PUT_LINE('Last name: ' || v_last_name);
    DBMS_OUTPUT.PUT_LINE('Email: ' || v_email || '@example.com');
    DBMS_OUTPUT.PUT_LINE('Phone: ' || v_phone);
    DBMS_OUTPUT.PUT_LINE('Hire date: ' || TO_CHAR(v_hire_date, 'DD-MON-YY'));
    DBMS_OUTPUT.PUT_LINE('Job title: ' || v_job_title);
    
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('Employee not found for ID: ' || p_employee_id);
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('An error occurred: ' || SQLERRM);
END find_employee;
/
BEGIN
    find_employee(107); 
END;
/
--Q3
CREATE OR REPLACE PROCEDURE update_salary_by_dept(
    p_department_id IN employees.department_id%TYPE,
    p_percentage_increase IN NUMBER,
    p_rows_updated OUT NUMBER
)
AS
BEGIN
    IF p_percentage_increase <= 0 THEN
        RAISE_APPLICATION_ERROR(-20001, 'Percentage increase should be greater than 0.');
    END IF;

    UPDATE employees
    SET salary = salary + (salary * (p_percentage_increase / 100))
    WHERE department_id = p_department_id
    AND salary > 0;

    p_rows_updated := SQL%ROWCOUNT;

    DBMS_OUTPUT.PUT_LINE('Number of rows updated: ' || p_rows_updated);
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('No employees found for the provided department.');
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('An error occurred: ' || SQLERRM);
END update_salary_by_dept;
/

SET SERVEROUTPUT ON;

DECLARE
    v_updated_rows NUMBER;
BEGIN
    update_salary_by_dept(10, 2.5, v_updated_rows); 
END;
/

--Q4
CREATE OR REPLACE PROCEDURE spUpdateSalary_UnderAvg AS
    v_avg_salary employees.salary%TYPE; 
    v_rows_updated NUMBER; 
    

    v_percent_increase NUMBER(4, 2);
    v_error_message VARCHAR2(100);

BEGIN

    SELECT AVG(salary) INTO v_avg_salary FROM employees;

 
    IF v_avg_salary <= 9000 THEN
        v_percent_increase := 0.02; -- 2% increase if average salary is <= $9000
    ELSE
        v_percent_increase := 0.01; -- 1% increase if average salary is > $9000
    END IF;


    UPDATE employees
    SET salary = salary * (1 + v_percent_increase)
    WHERE salary < v_avg_salary;


    v_rows_updated := SQL%ROWCOUNT;


    DBMS_OUTPUT.PUT_LINE('Number of rows updated: ' || v_rows_updated);

EXCEPTION
    WHEN NO_DATA_FOUND THEN
        v_error_message := 'No data found.';
        DBMS_OUTPUT.PUT_LINE(v_error_message);
    WHEN OTHERS THEN
        v_error_message := 'An error occurred: ' || SQLERRM;
        DBMS_OUTPUT.PUT_LINE(v_error_message);
END spUpdateSalary_UnderAvg;
/


SET SERVEROUTPUT ON;


BEGIN
    spUpdateSalary_UnderAvg;
END;

--Q5
CREATE OR REPLACE PROCEDURE spSalaryReport AS
    v_low_count NUMBER := 0;
    v_fair_count NUMBER := 0;
    v_high_count NUMBER := 0;
    v_avg_salary NUMBER := 0;
    v_min_salary NUMBER := 0;
    v_max_salary NUMBER := 0;

BEGIN
    
    SELECT AVG(salary), MIN(salary), MAX(salary)
    INTO v_avg_salary, v_min_salary, v_max_salary
    FROM employees;

   
    FOR emp IN (SELECT salary FROM employees) LOOP
        IF emp.salary < (v_avg_salary - v_min_salary) / 2 THEN
            v_low_count := v_low_count + 1;
        ELSIF emp.salary > (v_max_salary - v_avg_salary) / 2 THEN
            v_high_count := v_high_count + 1;
        ELSE
            v_fair_count := v_fair_count + 1;
        END IF;
    END LOOP;


    DBMS_OUTPUT.PUT_LINE('Low: ' || v_low_count);
    DBMS_OUTPUT.PUT_LINE('Fair: ' || v_fair_count);
    DBMS_OUTPUT.PUT_LINE('High: ' || v_high_count);

EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('No data found.');
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('An error occurred: ' || SQLERRM);
END spSalaryReport;
/


BEGIN
    spSalaryReport;
END;
/


