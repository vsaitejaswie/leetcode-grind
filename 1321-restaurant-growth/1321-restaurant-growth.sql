# Write your MySQL query statement below

SELECT 
    visited_on,
    (
        SELECT SUM(amount)
        FROM Customer
        WHERE visited_on BETWEEN DATE_SUB(c.visited_on, INTERVAL 6 DAY) AND c.visited_on 
        # BETWEEN has inclusive range
    ) AS amount,
    ROUND(
        (
        SELECT SUM(amount)/7
        FROM Customer
        WHERE visited_on BETWEEN DATE_SUB(c.visited_on, INTERVAL 6 DAY) AND c.visited_on 
        # BETWEEN has inclusive range
    ), 2) AS average_amount
FROM Customer c
WHERE visited_on >= (                                 # '=' is not same as '>='
    SELECT DATE_ADD(MIN(visited_on), INTERVAL 6 DAY)
    FROM Customer
) 
GROUP BY visited_on





# This feels complex to answer, tackle it by keeping in mind that filtering can be done in the SELECT statement as well.