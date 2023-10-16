# Write your MySQL query statement below
SELECT 
    query_name, 
    ROUND(SUM(rating/position)/COUNT(*), 2) AS quality,
    ROUND(SUM(rating<3)/COUNT(*)*100, 2) AS poor_query_percentage
FROM Queries
GROUP BY query_name

# When "rating < 3" is evaluated, it produces a boolean result (true or false) for each row in the table based on whether the rating is less than 3. 

# For example, these rows have "2, 1, 2, 2, 4, 5" as rating values. The "sum(rating < 3)" function would result in true, true, true, true, false, false. that means it treats true as 1 and false as 0. Therefore, the SUM(rating < 3) would calculate the sum of 1+1+1+1+0+0, which equals 4. which is the same result as if we used case when rating < 3 then 1 else 0 end