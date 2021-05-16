-- Nth Highest Salary Total Accepted: 2355 Total Submissions: 15382 My Submissions Question Solution
-- Write a SQL query to get the nth highest salary from the Employee table.

-- +----+--------+
-- | Id | Salary |
-- +----+--------+
-- | 1  | 100    |
-- | 2  | 200    |
-- | 3  | 300    |
-- +----+--------+
-- For example, given the above Employee table, the nth highest salary where n = 2 is 200. If there is no nth highest salary, then the query should return null.

#	利用order by排序和limit限制显示
#	注意：行号从0开始，所以limit 1, 1表示第二行
#	查询第nth大数,要求不能出现重复的数字
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  	DECLARE M INT; # 声明
  	SET M = N-1; # 赋值
  	RETURN (
     	# Write your MySQL query statement below.
      	SELECT DISTINCT Salary
      	FROM Employee
      	ORDER BY Salary DESC
      	LIMIT M, 1
  );
END
