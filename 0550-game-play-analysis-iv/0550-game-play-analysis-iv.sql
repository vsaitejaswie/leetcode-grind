# Write your MySQL query statement below
# SELECT ROUND(COUNT(DISTINCT a.player_id)/(SELECT COUNT(DISTINCT player_id) FROM Activity), 2) as fraction
# FROM Activity a, Activity b
# WHERE DATEDIFF(a.event_date,b.event_date) = 1
#       AND a.player_id = b.player_id

  SELECT ROUND(COUNT(DISTINCT Activity.player_id) / (SELECT COUNT(DISTINCT player_id) from Activity), 2) as fraction 
  FROM Activity, 
  (
    SELECT player_id, min(event_date) as startEventDate
    FROM Activity 
    GROUP BY player_id
  ) firstLogin 
  WHERE datediff(event_date, startEventDate) = 1 and Activity.player_id = firstLogin.player_id