# Write your MySQL query statement below
SELECT DISTINCT(l1.num) AS ConsecutiveNums
FROM Logs l1, Logs l2, Logs l3
WHERE l1.id-2 = l3.id 
    AND l2.id-1 = l3.id
    AND l1.num = l2.num 
    AND l2.num = l3.num

# If we want to perform comparisons within the table, you always declare the table multiple times (I think this results in outer join) and perform the comparisons

#ALTERNATE SOLUTION WITHOUT MULTIPLE TABLES

# Select distinct(num) as ConsecutiveNums
# from(
# Select id,num,
# lag(num) over(order by id) as prev_num,
# lead(num) over(order by id) as next_num
# from Logs
# ) sq
# where sq.num = sq.prev_num and sq.prev_num = sq.next_num