# Write your MySQL query statement below
SELECT a.id, COUNT(a.id) AS num
FROM(SELECT requester_id AS id FROM RequestAccepted 
UNION ALL
SELECT accepter_id FROM RequestAccepted) a
GROUP BY a.id
ORDER BY num DESC
LIMIT 1