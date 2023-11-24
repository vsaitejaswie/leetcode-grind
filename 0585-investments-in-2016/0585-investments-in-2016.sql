# Write your MySQL query statement below

# SELECT ROUND(SUM(tiv_2016), 2) AS tiv_2016
# FROM Insurance m
# WHERE m.tiv_2015 IN (
#     SELECT tiv_2015
#     FROM Insurance d
#     WHERE NOT d.pid = m.pid
# )

# AND

# (m.lat, m.lon) NOT IN (
#     SELECT i.lat, i.lon
#     FROM Insurance i
#     WHERE NOT i.pid = m.pid 
#         AND i.lat = m.lat
#         AND i.lon = m.lon
# )

#####
# OPTIMAL CODE
#####

SELECT
    ROUND(SUM(tiv_2016), 2) as tiv_2016
FROM (
    SELECT
        tiv_2016,
        COUNT(pid) OVER (PARTITION BY tiv_2015) as tiv_2015_count,
        COUNT(pid) OVER (PARTITION BY lat, lon) as lat_lon_count
    FROM
        insurance
) AS subquery
WHERE
    tiv_2015_count > 1
    AND lat_lon_count = 1;


# understand that the performence of WHERE in (SUBSELECT) is just one of the worst? You can solve this with just count partition by, please do not use this type of subselects on prod.

