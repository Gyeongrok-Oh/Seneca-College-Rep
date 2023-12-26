-- ***************************************
-- DBS311 - Fall 2022
-- Lab 1b
-- Review of JOIN statements
-- 
-- Gyeongrok Oh
-- 119140226
-- 
-- ***************************************

/* 
NOTES
-- Make sure you follow the course style guide for SQL as posted on blackboard.
-- Data should always be sorted in a logical way, for the question, even if the 
   question does not specify to sort it.
*/

-- Q1
/* 
Provide a list of ALL departments, what city they are located in, and the name
of the current manager, if there is one.  
*/
SELECT
    D.DEPARTMENT_NAME AS "Department", D.DEPARTMENT_ID, D.MANAGER_ID, D.LOCATION_ID,
    L.CITY AS "City",
    E.FIRST_NAME || ' ' || E.LAST_NAME AS "Manager"
FROM
    DEPARTMENTS D
JOIN
    LOCATIONS L
ON
    D.LOCATION_ID = L.LOCATION_ID
LEFT JOIN
    EMPLOYEES E
ON
    D.MANAGER_ID = E.MANAGER_ID
ORDER BY
    "Department";

-- Q2
/*
Allow the user to enter the name of a country, or any part of the name, and 
then list all employees, with their job title, currently working in that country.
*/

-- Prompt the user to enter a country name or part of the name
ACCEPT country_name PROMPT 'Enter a country name or part of the name: '

-- Query to list employees and their job titles in the specified country
SELECT
    E.LAST_NAME AS "Employee Last Name",
    E.FIRST_NAME AS "Employee First Name",
    E.JOB_ID AS "JOB TITLE",
    C.COUNTRY_NAME
FROM
    EMPLOYEES E
JOIN
    DEPARTMENTS D ON E.DEPARTMENT_ID = D.DEPARTMENT_ID
JOIN
    LOCATIONS L ON D.LOCATION_ID = L.LOCATION_ID
JOIN
    COUNTRIES C ON L.COUNTRY_ID = C.COUNTRY_ID
WHERE
    UPPER(C.COUNTRY_NAME) LIKE '%' || UPPER('&country_name') || '%'
ORDER BY
    E.FIRST_NAME;


-- Q3
/*
Provide a contact list of all employees, and if they have a manager, 
the name of their direct manager.
*/
SELECT
    E.EMPLOYEE_ID,
    E.FIRST_NAME || ' ' || E.LAST_NAME AS "Employee Name",
    E.EMAIL AS "Employee Email",
    E.PHONE_NUMBER AS "Employee Phone",
    M.FIRST_NAME || ' ' || M.LAST_NAME AS "Manager Name",
    M.EMAIL AS "Manager Email",
    M.PHONE_NUMBER AS "Manager Phone"
FROM
    EMPLOYEES E
LEFT JOIN
    EMPLOYEES M ON E.MANAGER_ID = M.EMPLOYEE_ID
ORDER BY
    E.EMPLOYEE_ID;


-- Q4
/*
Provide a list of locations in the database, that currently do not have 
any employees working there.
*/
SELECT
    L.LOCATION_ID,
    L.STREET_ADDRESS,
    L.POSTAL_CODE,
    L.CITY,
    L.STATE_PROVINCE,
    L.COUNTRY_ID,
    JH.JOB_ID AS "ORIGINAL JOB",
    E.JOB_ID  AS "CURRENT JOB"
FROM
    LOCATIONS L
JOIN
    DEPARTMENTS D ON L.LOCATION_ID = D.LOCATION_ID
JOIN
    EMPLOYEES E ON D.DEPARTMENT_ID = E.DEPARTMENT_ID
JOIN
    JOB_HISTORY JH ON E.EMPLOYEE_ID = JH.EMPLOYEE_ID
ORDER BY
    L.LOCATION_ID;



-- Q5
/*
Provide a list of employees whom are currently still in the same job that they
started in (i.e. they have never changed job titles).
*/
SELECT  DISTINCT
    E.EMPLOYEE_ID,
    E.FIRST_NAME,
    E.LAST_NAME,
    E.JOB_ID AS "Original Job",
    JH.JOB_ID as "CURRENT JOB"
FROM
    EMPLOYEES E
RIGHT JOIN 
    JOB_HISTORY JH ON E.JOB_ID = JH.JOB_ID
ORDER BY 
     E.EMPLOYEE_ID;
