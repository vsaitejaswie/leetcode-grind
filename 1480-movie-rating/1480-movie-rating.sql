# Write your MySQL query statement below
(SELECT u.name AS results
FROM MovieRating m
JOIN Users u
    on m.user_id = u.user_id
GROUP BY m.user_id
ORDER BY COUNT(u.name) DESC, u.name 
LIMIT 1)

UNION ALL

(SELECT mv.title
FROM MovieRating m
JOIN Movies mv
    on m.movie_id = mv.movie_id
WHERE DATE_FORMAT(m.created_at, '%m-%Y') = '02-2020'
GROUP BY m.movie_id
ORDER BY SUM(rating)/COUNT(rating) DESC, mv.title 
LIMIT 1)
