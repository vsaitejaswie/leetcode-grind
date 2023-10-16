# Write your MySQL query statement below
SELECT *
FROM Cinema
WHERE id%2=1 AND (NOT description = 'boring')
ORDER BY rating DESC

# Take a look at pattern matching in strings with SQL