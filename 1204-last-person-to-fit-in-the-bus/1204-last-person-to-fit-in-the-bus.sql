# Write your MySQL query statement below
SELECT temp.person_name
FROM (SELECT person_name, SUM(weight) OVER (ORDER BY turn ASC) as run
      FROM Queue) temp
WHERE run<=1000
ORDER BY run DESC
LIMIT 1

# In SQL, the OVER keyword is used in conjunction with window functions to perform calculations across a specified range of rows related to the current row. Window functions allow you to perform calculations over a "window" or a subset of rows defined by an OVER clause. This can be particularly useful for tasks like calculating running totals, averages, and other aggregate functions within a specific context.