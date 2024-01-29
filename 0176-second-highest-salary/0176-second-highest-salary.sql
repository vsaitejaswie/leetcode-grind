# Write your MySQL query statement below
-- SELECT IF(e.salary, e.salary) AS SecondHighestSalary

-- Implementation 1
-- SELECT CASE
--         WHEN e.SecondRank = 2 THEN e.salary
--         WHEN COUNT(*) = 0 THEN NULL
--         END AS SecondHighestSalary
-- FROM (
--     SELECT salary, DENSE_RANK() OVER(ORDER BY salary DESC) AS SecondRank
--     FROM Employee) e
-- WHERE e.SecondRank = 2

-- Implementation 2

SELECT  (
    SELECT DISTINCT salary
    FROM Employee
    ORDER BY salary DESC
    LIMIT 1 OFFSET 1) AS SecondHighestSalary


