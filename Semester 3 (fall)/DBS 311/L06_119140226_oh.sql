-- ***********************
-- Name: Gyeongrok oh
-- ID: 119140226
-- Date: Dec 13,2023
-- Purpose: Lab 6 DBS301
-- ***********************

--Q1

SET SERVEROUTPUT ON;

CREATE OR REPLACE FUNCTION fncCalcFactorial(n IN NUMBER) RETURN NUMBER IS
    result NUMBER := 1;
    expression VARCHAR2(4000) := '';
BEGIN

    IF n < 0 THEN
        RAISE_APPLICATION_ERROR(-20001, 'Input must be a non-negative integer.');
    END IF;

    IF n = 0 THEN
        DBMS_OUTPUT.PUT_LINE(n || '! = fact(' || n || ') = ' || result);
        RETURN result;
    END IF;

    FOR i IN 1..n LOOP
        result := result * i;
        expression := expression || i || ' * ';
    END LOOP;

    expression := RTRIM(expression, ' * ');

    DBMS_OUTPUT.PUT_LINE(n || '! = fact(' || n || ') = ' || expression || ' = ' || result);

    RETURN result;
EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Error: ' || SQLERRM);
        RETURN NULL;
END fncCalcFactorial;
/

CREATE OR REPLACE PROCEDURE executeFactorial IS
    input_values NUMBER := 0;
    result NUMBER;
BEGIN
    FOR i IN 1..3 LOOP

        result := fncCalcFactorial(input_values);
        
        input_values := input_values + 1;
    END LOOP;
EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Error: ' || SQLERRM);
END executeFactorial;
/
EXECUTE executeFactorial;

EXECUTE executeFactorial;

--Q2
SET SERVEROUTPUT ON;

-- Create or replace the stored procedure to calculate current salary and vacation weeks
CREATE OR REPLACE PROCEDURE spCalcCurrentSalary(emp_id IN NUMBER) AS
    v_first_name employees.first_name%TYPE;
    v_last_name employees.last_name%TYPE;
    v_hire_date employees.hire_date%TYPE;
    v_initial_salary employees.salary%TYPE;
    v_current_salary NUMBER;
    v_years_worked NUMBER;
    v_vacation_weeks NUMBER := 2; -- Initial vacation weeks
BEGIN
    -- Initialize vacation weeks
    IF v_vacation_weeks < 6 THEN
        -- Retrieve employee information
        SELECT first_name, last_name, hire_date, salary
        INTO v_first_name, v_last_name, v_hire_date, v_initial_salary
        FROM employees
        WHERE employee_id = emp_id;

        -- Calculate the number of FULL years the employee has been working
        v_years_worked := TRUNC(MONTHS_BETWEEN(SYSDATE, v_hire_date) / 12);

        -- Calculate current salary based on the number of FULL years worked
        v_current_salary := v_initial_salary;
        FOR i IN 1..v_years_worked LOOP
            v_current_salary := v_current_salary * 1.04; -- 4% increase each year
        END LOOP;

        -- Calculate additional vacation weeks after 3 years
        IF v_years_worked >= 3 THEN
            v_vacation_weeks := LEAST(v_vacation_weeks + (v_years_worked - 2), 6);
        END IF;

        -- Display employee information and results
        DBMS_OUTPUT.PUT_LINE('First Name:     ' || v_first_name);
        DBMS_OUTPUT.PUT_LINE('Last Name:      ' || v_last_name);
        DBMS_OUTPUT.PUT_LINE('Hire Date:      ' || TO_CHAR(v_hire_date, 'Mon. DD, YYYY'));
        DBMS_OUTPUT.PUT_LINE('Salary:        ' || TO_CHAR(v_current_salary, '$99999.99'));
        DBMS_OUTPUT.PUT_LINE('Vacation Weeks: ' || v_vacation_weeks);
    ELSE
        DBMS_OUTPUT.PUT_LINE('Employee not found.');
    END IF;
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('Employee not found.');
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Error: ' || SQLERRM);
END spCalcCurrentSalary;
/

-- Create a non-saved procedure to execute spCalcCurrentSalary for 3 different input values
CREATE OR REPLACE PROCEDURE executeCalcCurrentSalary AS
BEGIN
    -- Execute the stored procedure for three different employee IDs
    spCalcCurrentSalary(101); -- Replace with actual employee IDs
    spCalcCurrentSalary(102);
    spCalcCurrentSalary(103);
END executeCalcCurrentSalary;
/

EXECUTE executeCalcCurrentSalary;

--Q3
SET SERVEROUTPUT ON;

CREATE OR REPLACE PROCEDURE spDepartmentsReport AS
    v_deptID        departments.department_id%TYPE;
    v_department    departments.department_name%TYPE;
    v_city          locations.city%TYPE;
    v_numEmp        NUMBER;

BEGIN
  FOR dept_info IN (SELECT d.department_id,
                              d.department_name,
                              l.city,
                              NVL(COUNT(e.employee_id), 0) AS NumEmp
                       FROM departments d
                       LEFT JOIN employees e ON d.department_id = e.department_id
                       LEFT JOIN locations l ON d.location_id = l.location_id
                       GROUP BY d.department_id, d.department_name, l.city
                       ORDER BY d.department_id)
    LOOP
        -- Assign values to variables
        v_deptID := dept_info.department_id;
        v_department := dept_info.department_name;
        v_city := dept_info.city;
        v_numEmp := dept_info.NumEmp;

        DBMS_OUTPUT.PUT_LINE(
            LPAD('DeptID    ', 10) || RPAD('Department          ', 20) || RPAD('City                     ', 25) || RPAD('NumEmp', 10)
        );
        DBMS_OUTPUT.PUT_LINE(
            LPAD(' ', CASE WHEN LENGTH(TO_CHAR(v_deptID)) = 2 THEN 4 ELSE 3 END) || RPAD(TO_CHAR(v_deptID),3) || 
            LPAD(' ', CASE WHEN LENGTH(TO_CHAR(v_deptID)) = 2 THEN 3 ELSE 4 END) || RPAD(v_department, 20) || 
            RPAD(v_city, 25) || 
            RPAD(TO_CHAR(v_numEmp), 10)
        );

        DBMS_OUTPUT.NEW_LINE;
    END LOOP;
END spDepartmentsReport;
/

EXEC spDepartmentsReport;

--Q4
-- Step A: Create the UDF
CREATE OR REPLACE FUNCTION spDetermineWinningTeam(p_gameID IN NUMBER) RETURN NUMBER IS
    v_winner_teamID NUMBER;
BEGIN
    SELECT CASE
               WHEN g.isplayed = 0 THEN -1  -- Game not played yet
               WHEN g.homescore = g.visitscore THEN 0  -- Tie
               WHEN g.homescore > g.visitscore THEN g.hometeam
               ELSE g.visitteam
           END
    INTO v_winner_teamID
    FROM games g
    WHERE g.gameid = p_gameID;

    RETURN v_winner_teamID;
END spDetermineWinningTeam;
/
-- Example usage of the function
DECLARE
    v_result NUMBER;
BEGIN
    v_result := spDetermineWinningTeam(59); -- Replace 1 with an actual game ID
    DBMS_OUTPUT.PUT_LINE('Return: ' || v_result);
END;
/
-- Step B: Create the SQL statement to output ALL teams and the total number of games they have won
-- Handle ties and games not played using the UDF
SELECT
    t.teamid,
    t.teamname,
    COUNT(g.gameid) AS total_games,
    NVL(SUM(CASE WHEN spDetermineWinningTeam(g.gameid) = t.teamid THEN 1 ELSE 0 END), 0) AS total_wins,
    NVL(SUM(CASE WHEN spDetermineWinningTeam(g.gameid) = 0 THEN 1 ELSE 0 END), 0) AS total_ties
FROM
    teams t
    LEFT JOIN games g ON t.teamid = g.hometeam OR t.teamid = g.visitteam
GROUP BY
    t.teamid, t.teamname;



