# Write your MySQL query statement below

# SOLUTION 1

# SELECT user_id, CONCAT(UPPER(LEFT(name, 1)), LOWER(RIGHT(name,length(name)-1))) AS name
# FROM Users
# ORDER BY user_id

# SOLUTION 2

select user_id,concat(upper(substr(name,1,1)),lower(substr(name,2,length(name)))) as name from Users order by user_id