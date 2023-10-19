# Write your MySQL query statement below
SELECT MAX(nn.num) AS num
FROM (
  SELECT num, COUNT(num) AS cnt
  FROM MyNumbers
  GROUP BY num
) nn
WHERE nn.cnt = 1

# Only one level of aggregation is possible per query
