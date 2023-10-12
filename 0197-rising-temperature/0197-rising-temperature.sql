# Write your MySQL query statement below
SELECT w.id
FROM Weather w, Weather nw
WHERE w.temperature > nw.temperature
AND DATEDIFF(w.recordDate,nw.recordDate) = 1

