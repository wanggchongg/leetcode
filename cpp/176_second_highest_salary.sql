-- Second Highest Salary Total Accepted: 4929 Total Submissions: 19921 My Submissions Question Solution
-- Write a SQL query to get the second highest salary from the Employee table.

-- +----+--------+
-- | Id | Salary |
-- +----+--------+
-- | 1  | 100    |
-- | 2  | 200    |
-- | 3  | 300    |
-- +----+--------+
-- For example, given the above Employee table, the second highest salary is 200. If there is no second highest salary, then the query should return null.

#	利用子查询和聚集函数MAX
#	方法一：
SELECT MAX(Salary)
FROM Employee
WHERE Salary < (SELECT MAX(Salary)
				FROM Employee)

#	方法二：
SELECT MAX(Salary)
FROM Employee
WHERE Salary <> (SELECT MAX(Salary)
				 FROM Employee)
