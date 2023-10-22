# Write your MySQL query statement below
# SELECT sp.product_id, MAX(sp.change_date) as low_max_date
# FROM Products sp
# WHERE change_date <= '2019-08-16'
# GROUP BY product_id

# SELECT p.product_id, IF(np.low_max_date IS NULL, 10, p.new_price) AS price
# FROM Products p
# LEFT JOIN (
#     SELECT sp.product_id, MAX(sp.change_date) as low_max_date
#     FROM Products sp
#     WHERE change_date <= '2019-08-16'
#     GROUP BY sp.product_id
# ) np
#     ON p.product_id = np.product_id
# WHERE p.change_date - np.low_max_date <= 0 || np.low_max_date IS null

select distinct product_id, 10 as price
from Products
group by product_id
having (min(change_date) > "2019-08-16")

union

select p2.product_id, new_price
from Products p2
where (p2.product_id, p2.change_date) in

(
select product_id, max(change_date) as recent_date
from Products
where change_date <= "2019-08-16"
group by product_id
)
