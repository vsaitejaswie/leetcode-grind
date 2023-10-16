# Write your MySQL query statement below
SELECT 
    p.product_id, 
    CASE WHEN
        SUM(u.units) IS NULL
        THEN 0
        ELSE ROUND(SUM(u.units*p.price)/SUM(u.units), 2)
        END
    AS average_price
FROM Prices p
LEFT JOIN UnitsSold u
    ON u.product_id = p.product_id 
    AND u.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY p.product_id

# LEFT JOIN on Prices
# If I want null value against a column in the joined table, I need to use the condition as part of JOIN statement and not as part of WHERE clause