# Write your MySQL query statement below
SELECT ns.product_id, s.year AS first_year, s.quantity, s.price
FROM Sales s,(
  SELECT product_id, MIN(year) AS first_year, quantity, price
  FROM Sales
  GROUP BY product_id
) ns
WHERE ns.product_id = s.product_id AND year = first_year