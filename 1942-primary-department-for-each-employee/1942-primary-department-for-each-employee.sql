# Write your MySQL query statement below
SELECT employee_id, department_id
FROM Employee
WHERE primary_flag = 'Y'
UNION
SELECT employee_id, department_id
FROM Employee
GROUP BY employee_id
HAVING COUNT(*) = 1

# learn which is more optimal
# the above query or 

# select employee_id, department_id
# from Employee
# where primary_flag = 'Y' or employee_id in (
# select employee_id from employee group by employee_id having count(department_id) = 1)