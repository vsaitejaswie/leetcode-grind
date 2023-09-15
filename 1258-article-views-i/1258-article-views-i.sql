# Write your MySQL query statement below
SELECT DISTINCT # selects unique values
  author_id as id
FROM Views v
WHERE  author_id = viewer_id
ORDER BY author_id
;