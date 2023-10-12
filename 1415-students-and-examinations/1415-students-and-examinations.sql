# Write your MySQL query statement below
SELECT s.student_id, s.student_name, z.subject_name, COUNT(e.subject_name) AS attended_exams
FROM Students s
CROSS JOIN Subjects z
LEFT JOIN Examinations e
    ON e.student_id = s.student_id AND e.subject_name = z.subject_name
GROUP BY s.student_id, z.subject_name
ORDER BY s.student_id, z.subject_name


