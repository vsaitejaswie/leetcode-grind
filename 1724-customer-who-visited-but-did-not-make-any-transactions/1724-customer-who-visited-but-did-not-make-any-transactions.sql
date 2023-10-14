# Write your MySQL query statement below
SELECT a.customer_id, COUNT(a.customer_id) AS count_no_trans
FROM Visits a
LEFT JOIN Transactions t
    ON a.visit_id = t.visit_id
WHERE t.amount IS NULL
GROUP BY a.customer_id

# Do not write COUNT(t.amount) as null will not be counted for (??)
# *** variable = NULL WILL NOT WORK!! variable IS NULL is the right form of usage ***