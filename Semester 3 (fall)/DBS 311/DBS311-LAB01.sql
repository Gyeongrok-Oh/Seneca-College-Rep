-- ***********************
-- Name: GYEONGROK OH
-- ID: #########
-- Date: September 11 2023
-- Purpose: Lab 1 DBS311
-- ***********************

-- Q1
SELECT last_name AS "LName", job_id AS "Job Title", 
       hire_date AS "Job Start" 
FROM employees;

-- Q2
SELECT EMPLOYEE_ID, 
       LAST_NAME, 
       CONCAT('$',TO_CHAR(SALARY, 'FM99999999.90')) AS "formatted_salary"
FROM EMPLOYEES
WHERE SALARY
      BETWEEN 8000
      AND 11000
ORDER BY SALARY DESC, LAST_NAME;

--Q3
SELECT EMPLOYEE_ID, 
       LAST_NAME, 
       TO_CHAR(SALARY, 'FM99999999.90') AS "formatted_salary"
FROM EMPLOYEES
WHERE SALARY
      BETWEEN 8000
      AND 11000
ORDER BY SALARY DESC, LAST_NAME;

--Q4
SELECT JOB_ID AS "JOB_TITLE",
       CONCAT(FIRST_NAME, LAST_NAME) AS "Full_NAME"
FROM EMPLOYEES
WHERE REGEXP_LIKE(FIRST_NAME, '[eE]');

--Q5
-- Declare a parameter where you can enter a city name or part of it.
SET SERVEROUTPUT ON;

DECLARE
  SearchCity VARCHAR2(30); -- Adjust data format and length as needed
BEGIN
  -- Initialize the SearchCity variable with the desired city name or part of it.
  SearchCity := 'ROMA'; -- Enter the desired city name or part of it
  
  -- A query that displays the address of a location based on the city name parameter entered by the user.
  FOR loc_rec IN (SELECT STREET_ADDRESS, CITY, STATE_PROVINCE, COUNTRY_ID
                  FROM LOCATIONS
                  WHERE UPPER(CITY) LIKE '%' || UPPER(SearchCity) || '%') 
  LOOP
    DBMS_OUTPUT.PUT_LINE('Street Address: ' || loc_rec.STREET_ADDRESS);
    DBMS_OUTPUT.PUT_LINE('City: ' || loc_rec.CITY);
    DBMS_OUTPUT.PUT_LINE('State/Province: ' || loc_rec.STATE_PROVINCE);
    DBMS_OUTPUT.PUT_LINE('Country ID: ' || loc_rec.COUNTRY_ID);
  END LOOP;
END;

--Q6
SELECT TO_CHAR(SYSDATE + 1, 'Month DD "of year" YYYY') AS "Tomorrow" 
FROM DUAL;

--Q7
SELECT
    e.LAST_NAME,
    e.FIRST_NAME,
    d.DEPARTMENT_NAME,
    e.SALARY,
    ROUND(e.SALARY * 1.04) AS "Good Salary",
    ((ROUND(e.SALARY * 1.04) - e.SALARY) * 12) AS "Annual Pay Increase"
FROM
    EMPLOYEES e
JOIN
    DEPARTMENTS d
ON
    e.DEPARTMENT_ID = d.DEPARTMENT_ID
WHERE
    e.DEPARTMENT_ID IN (20, 50, 60);

--Q8
SELECT
    LAST_NAME,
    HIRE_DATE,
    FLOOR(MONTHS_BETWEEN(SYSDATE, TO_DATE(HIRE_DATE, 'DD-MON-YY')) / 12) AS "Years Worked"
FROM
    EMPLOYEES
WHERE
    TO_DATE(HIRE_DATE, 'DD-MON-YY') < TO_DATE('01-JAN-14', 'DD-MON-YY')
ORDER BY
    "Years Worked" DESC;

--Q9
SELECT
    CITY,
    COALESCE(STATE_PROVINCE, 'Unknown Province') AS STATE_PROVINCE,
    COUNTRY_ID
FROM
    LOCATIONS
WHERE
    UPPER(CITY) LIKE 'S%' AND LENGTH(CITY) >= 8;

--Q10
SELECT
    LAST_NAME,
    HIRE_DATE,
    TO_CHAR(HIRE_DATE, 'FMDay, Month "the" DDSP "of year" YYYY') AS "REVIEW DAY"
FROM
    EMPLOYEES
WHERE
    HIRE_DATE >= TO_DATE('01-JAN-2018', 'DD-MON-YYYY')
ORDER BY
    "REVIEW DAY";

