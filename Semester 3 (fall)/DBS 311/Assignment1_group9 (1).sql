-- ***********************
-- Name: Kittikom Kornmanakij
-- ID: 101169233
-- Date: 13 October 2023
-- Purpose: Assignment 1 - DBS301
-- ***********************

-- ***********************
-- Name: Supachai Ruknuy
-- ID: 121707228
-- Date: 13 October 2023
-- Purpose: Assignment 1 - DBS301
-- ***********************

-- ***********************
-- Name: GYEONGROK OH
-- ID: 119140226
-- Date: 13 October 2023
-- Purpose: Assignment 1 - DBS301
-- ***********************

-- Question 1
--Display the employee number, full employee name, job and hire date 
--of all employees hired in May or November of 
--any year, with the most recently hired employees displayed first.

-- Q1 SOLUTION --
SELECT
     employee_id,
     RPAD((last_name || ', ' || first_name), 25) as FullName,
     job_id,
     TO_CHAR(last_day(hire_date), '"["fmMonth ddth "of" YYYY"]"') as start_date
FROM employees
WHERE 
    EXTRACT(MONTH FROM hire_date) IN (5, 11)
    AND EXTRACT(YEAR FROM hire_date) NOT IN (2015, 2016) -- exclude people hire in 2015, 2016 
ORDER BY start_date DESC;

-- Question 2
--List the employee number, full name, job and the modified salary for all 
--employees whose monthly earning (without this increase) is outside the range 
--$6,500 – $11,500 and who are employed as Vice Presidents or Managers 
--(President is not counted here).  

-- Q2 SOLUTION --
SELECT
    'Emp# ' || employee_id || ' named ' || first_name || ' ' || last_name || ' who is ' || job_id ||
    ' will have a new salary of $' || TO_CHAR(
    ROUND(
        salary * (
            1 + 
            0.25 * DECODE(INSTR(job_id, 'VP'), 0, 0, 1) +
            0.18 * DECODE(INSTR(job_id, 'MGR'), 0, 0, 1) -- REVISED THIS FROM MAN TO MGR
        ),2)) AS "New Salary"
FROM
    employees
WHERE
    salary NOT BETWEEN 6500 AND 11500
    AND (job_id LIKE '%VP%' OR job_id LIKE '%MGR%') -- REVISED THIS FROM MAN TO MGR
ORDER BY "New Salary" DESC;

-- Question 3
--Display the employee last name, salary, job title and manager# of all 
--employees not earning a commission OR if they work in the SALES department, 
--but only if their total monthly salary with $1000 included bonus and 
--commission (if earned) is greater than $15,000. 

-- Q3 SOLUTION --
SELECT 
    last_name,
    salary,
    job_id,
    NVL(TO_CHAR(manager_id), 'NONE') AS "Manager#",
    TO_CHAR((salary*(NVL(commission_pct,0))+ salary)*12 + 1000, '$999,999.99') as "Total Income" --include bonus 
FROM employees
WHERE 
    commission_pct IN (  -- not earn commission
        SELECT commission_pct
        FROM employees
        WHERE commission_pct IS NULL
        AND ((salary*(NVL(commission_pct,0)) + salary) + 1000) > 15000 --validate salary
    )
    OR department_id IN ( -- work for sales department
        SELECT department_id
        FROM employees
        WHERE department_id = 80
        AND ((salary*(NVL(commission_pct,0)) + salary) + 1000) > 15000 --validate salary
    )
ORDER BY "Total Income" DESC;

-- Question 4
--Display Department_id, Job_id and the Lowest salary for this 
--combination under the alias Lowest Dept/Job Pay, but only if that Lowest Pay 
--falls in the range $6500 - $16800. Exclude people who work as some kind of 
--Representative job from this query and departments IT and SALES as well. 

-- Q4 SOLUTION --
SELECT
    e.department_id,
    e.job_id,
    MIN(e.salary) as "Lowest Dept/Job Pay"
FROM
    employees e
    JOIN departments d ON e.department_id = d.department_id
WHERE d.department_name NOT IN ('IT', 'Sales')
GROUP BY
    e.department_id,
    e.job_id
HAVING
    MIN(e.salary) BETWEEN 6500 AND 16800
ORDER BY
    e.department_id,
    e.job_id;

-- Question 5
--Display last_name, salary and job for all employees 
--who earn more than all lowest paid employees per department outside 
--the US locations.

-- Q5 SOLUTION --	
SELECT
    e.last_name,
    e.salary,
    e.job_id
FROM
    (
    employees e 
    JOIN departments d ON e.department_id = d.department_id
    JOIN locations l ON d.location_id = l.location_id
    )
WHERE 
    e.department_id <>90    --Exclude President and Vice Presidents
    AND e.salary > (                        --earn more than all lowest paid employees per dept
        SELECT MAX(minSal)
        FROM (                    
            SELECT MIN(e.salary) as minSal
            FROM employees e 
                JOIN departments d ON e.department_id = d.department_id
                JOIN locations l ON d.location_id = l.location_id
            WHERE  l.country_id <> UPPER('US')         --outside the US locations
            GROUP BY e.department_id)
        )
ORDER BY e.job_id ASC;

-- Question 6
--Who are the employees (show last_name, salary and job) who 
--work either in IT or MARKETING department and earn more than the 
--worst paid person in the ACCOUNTING department.

-- Q6 SOLUTION --
SELECT
    last_name,
    salary,
    job_id
FROM employees
WHERE 
    department_id IN (20, 60)   --Marketing and IT dept.
    AND salary > (  
        SELECT MIN(e.salary)
        FROM employees e
        WHERE e.department_id = 110 --SCALAR, no need to use GROUP BY
        )
ORDER BY last_name;

-- Question 7
--Display alphabetically the full name, job, salary (formatted
--as a currency amount incl. thousand separator, but no decimals) and department
--number for each employee who earns less than the best paid unionized employee 
--(i.e. not the president nor any manager nor any VP), and who work in either 
--SALES or MARKETING department.

-- Q7 SOLUTION --
SELECT
    RPAD((first_name || ' ' || last_name), 24, ' ') as Employee,
    job_id,
    LPAD((TO_CHAR(salary, '$999,999')), 15, '=') AS Salary,
    department_id
FROM employees
WHERE 
    department_id IN (20, 80)   --who work in either SALES or MARKETING department
    AND (NVL(salary,0) + NVL(salary,0) * NVL(commission_pct,0)) < (
        SELECT MAX(NVL(salary,0) + NVL(salary,0) * NVL(commission_pct,0)) as MaxEarn
        FROM employees
        WHERE 
            department_id NOT IN (90)       --not a president nor VP
            AND employee_id NOT IN (        --not a manager
            SELECT e.employee_id
            FROM employees e JOIN departments d ON e.employee_id = d.manager_id
        )   
    )
ORDER BY Employee;
 
-- Question 8
-- Include everybody even no dept.
-- Exclude empty departemnt
-- Display all cites even no dept 
-- Get all department and all city
-- The department that has city

-- Q8 SOLUTION --
(SELECT 
    NVL(dept.department_name,'Not Assigned Yet') AS department_name,
    SUBSTR(loc.city, 1, 22) AS City,
    COUNT(DISTINCT emp.job_id) AS "# of job"
FROM  
    (SELECT -- Create a new table called emp to get all different jobs
        job_id,
        department_id 
    FROM employees) emp 
    FULL JOIN departments dept ON emp.department_id = dept.department_id
    FULL JOIN locations loc ON loc.location_id = dept.location_id
WHERE department_name IS NULL
GROUP BY 
    NVL(dept.department_name,'Not Assigned Yet'),
    loc.city)
UNION
(SELECT 
    NVL(dept.department_name, 'Not Assigned Yet') AS department_name,
    SUBSTR(loc.city, 1, 22) AS City,
    COUNT(DISTINCT emp.job_id) AS "# of job"
FROM  
    (SELECT -- Create a new table called emp to get all different jobs
        job_id,
        department_id 
    FROM employees) emp 
RIGHT JOIN departments dept ON emp.department_id = dept.department_id
LEFT JOIN locations loc ON loc.location_id = dept.location_id
GROUP BY 
    NVL(dept.department_name, 'Not Assigned Yet'),
    loc.city)
ORDER BY "# of job" DESC;