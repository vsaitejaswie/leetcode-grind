# Write your MySQL query statement below
SELECT a.machine_id, ROUND(SUM(na.timestamp - a.timestamp)/COUNT(a.process_id), 3) AS processing_time
FROM Activity a, Activity na
WHERE a.activity_type = 'start' AND na.activity_type = 'end' AND a.machine_id = na.machine_id 
GROUP BY a.machine_id