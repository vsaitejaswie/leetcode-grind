# Write your MySQL query statement below
SELECT ROUND(COUNT(*)/ (SELECT COUNT(*) 
                FROM (SELECT 
                         customer_id AS cust,
                        MIN(order_date) AS pref
                        FROM Delivery
                        GROUP BY customer_id) e
                    ) * 100, 2)
        AS immediate_percentage
FROM Delivery, (SELECT 
    customer_id AS cust,
    MIN(order_date) AS pref
FROM Delivery
GROUP BY customer_id) d
WHERE customer_id = d.cust AND customer_pref_delivery_date = d.pref