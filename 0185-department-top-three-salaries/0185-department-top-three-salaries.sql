# Write your MySQL query statement below
SELECT temp.Department, temp.Employee, temp.Salary
FROM (
    SELECT 
    d.name AS Department, 
    e.name AS Employee,
    e.salary AS Salary,
    DENSE_RANK() OVER (PARTITION BY d.name ORDER BY e.salary DESC) AS 'Rank'
    FROM Employee e
    JOIN Department d
    ON e.departmentId = d.id
) temp
WHERE temp.Rank<=3
