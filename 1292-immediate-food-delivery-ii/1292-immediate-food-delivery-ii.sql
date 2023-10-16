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


# ALTERNATE SOLUTION

# WITH FirstOrders AS (
#     SELECT
#         customer_id,
#         MIN(order_date) AS first_order_date
#     FROM Delivery
#     GROUP BY customer_id
# )

# SELECT
#     ROUND(COUNT(CASE WHEN DATEDIFF(customer_pref_delivery_date, first_order_date) = 0 THEN 1 ELSE NULL END) / COUNT(1) * 100, 2) AS immediate_percentage
# FROM FirstOrders;