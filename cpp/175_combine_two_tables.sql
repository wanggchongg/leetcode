-- Combine Two Tables Total Accepted: 5499 Total Submissions: 16028 My Submissions Question Solution
-- Table: Person

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | PersonId    | int     |
-- | FirstName   | varchar |
-- | LastName    | varchar |
-- +-------------+---------+
-- PersonId is the primary key column for this table.
-- Table: Address

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | AddressId   | int     |
-- | PersonId    | int     |
-- | City        | varchar |
-- | State       | varchar |
-- +-------------+---------+
-- AddressId is the primary key column for this table.

-- Write a SQL query for a report that provides the following information for each person in the Person table, regardless if there is an address for each of those people:

-- FirstName, LastName, City, State

# Write your MySQL query statement below
#  使用外部连接OUTER JOIN值，包含没有关联行的那些行，其中，LEFT指出OUTER JOIN
#  左边的表中没有关联的行，RIGHT指出右边表中没有关联的行
SELECT FirstName, LastName, City, State
FROM Person LEFT OUTER JOIN Address
ON Person.PersonId = Address.PersonId;


#	延伸：使用内部连接INNER JOIN，基于两个表之间的相等测试
#	查询公共行
SELECT FirstName, LastName, City, State
FROM Person INNER JOIN Address
ON Person.PersonId = Address.PersonId