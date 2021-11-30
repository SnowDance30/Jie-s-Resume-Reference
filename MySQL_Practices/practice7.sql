-- Question7:
-- The employee table contains all employees, and their managers also belong to employees. Each employee has an ID and a list of the ID of the manager corresponding to the employee. Given the employee table, write an SQL query that gets the names of employees whose income exceeds their managers. In the above table, Joe is the only employee whose income exceeds his manager.

CREATE TABLE Employee (
  Id int,
  Name varchar(255), 
  Salary int, 
  ManagerId int
);

INSERT INTO Employee 
VALUES ('1', 'Joe', '70000', '3'),
       ('2', 'Henry', '80000', '4'),
       ('3', 'Sam', '60000', Null),
       ('4', 'Max', '90000', Null);
	   
Select e1.Name as Employee 
from Employee e1 , Employee e2  
where e1.ManagerId = e2.Id and e1.Salary > e2.Salary;
