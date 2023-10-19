# Write your MySQL query statement below
SELECT MAX(nn.num) AS num
FROM (
  SELECT num, COUNT(num) AS cnt
  FROM MyNumbers
  GROUP BY num
) nn
WHERE nn.cnt = 1
