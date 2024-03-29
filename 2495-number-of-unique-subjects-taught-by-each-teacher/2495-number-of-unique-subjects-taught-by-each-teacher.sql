# Write your MySQL query statement below
SELECT teacher_id, COUNT(*) AS cnt
FROM (
    SELECT teacher_id, subject_id
    FROM Teacher
    GROUP BY teacher_id, subject_id
) a
GROUP BY teacher_id

# Do this instead
# SELECT teacher_id, COUNT(DISTINCT subject_id) as cnt
# FROM Teacher
# GROUP BY teacher_id