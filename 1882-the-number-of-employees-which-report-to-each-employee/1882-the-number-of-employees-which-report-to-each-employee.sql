# Write your MySQL query statement below
SELECT ne.employee_id, ne.name, COUNT(*) AS reports_count, ROUND(AVG(e.age), 0) AS average_age
FROM Employees e
INNER JOIN Employees ne
    ON e.reports_to = ne.employee_id
GROUP BY ne.employee_id
ORDER BY ne.employee_id