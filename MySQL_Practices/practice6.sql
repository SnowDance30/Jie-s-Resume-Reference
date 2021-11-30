-- Question6:
-- It contains two tables, the customers table and the orders table. Write an SQL query to find all customers who never order anything.

CREATE TABLE Customers (
  Id int UNSIGNED AUTO_INCREMENT PRIMARY KEY,
  Name varchar(255)
);

INSERT INTO Customers(Name)
 VALUES('Joe'),('Henry'),('Sam'),('Max');
 
CREATE TABLE Orders (
  Id int, 
  CustomerID int
);

INSERT INTO Orders(Id,CustomerID)
 VALUES('1','3'),('2','1');


SELECT Name 
from Customers c
left join Orders o
ON Orders.CustomerId = c.ID 
where o.ID is Null;
