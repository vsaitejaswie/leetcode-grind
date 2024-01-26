-- Working Solution - Redundant Script
-- SELECT n.Day As Day,
--         ROUND( SUM(IF(n.Status IN ('cancelled_by_client', 'cancelled_by_driver'),1,0))/COUNT(n.Status), 2) AS 'Cancellation Rate'
-- FROM (

--     SELECT t.id, t.request_at AS Day, t.status As Status
--     FROM Trips t
--     JOIN Users u
--     ON t.client_id = u.users_id
--     WHERE u.banned = 'No'
--         AND t.request_at BETWEEN "2013-10-01" AND "2013-10-03"

--     INTERSECT

--     SELECT t.id, t.request_at AS Day, t.status As Status
--     FROM Trips t
--     JOIN Users u
--     ON t.driver_id = u.users_id
--     WHERE u.banned = 'No'
--         AND t.request_at BETWEEN "2013-10-01" AND "2013-10-03"

-- ) n
-- GROUP BY n.Day

# Optimal Solution
SELECT t.request_at As Day,
        ROUND( SUM(IF(t.status IN ('cancelled_by_client', 'cancelled_by_driver'),1,0))/COUNT(t.Status), 2) AS 'Cancellation Rate'
FROM Trips t
JOIN Users uc
ON t.client_id = uc.users_id
JOIN Users ud
ON t.driver_id = ud.users_id
WHERE uc.banned = 'No' AND ud.banned = 'No'
    AND t.request_at BETWEEN "2013-10-01" AND "2013-10-03"
GROUP BY Day




