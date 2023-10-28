# Write your MySQL query statement below
SELECT e.employee_id
FROM Employees e
WHERE e.salary < 30000 AND
    e.manager_id NOT IN (
    SELECT ne.employee_id
    FROM Employees ne
    )
ORDER BY e.employee_id