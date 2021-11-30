-- Question4:
-- Write an SQL query that meets the following conditions: whether a person has address information or not, the following information of the person needs to be provided based on the above two tables: firstname, LastName, city and state

CREATE TABLE IF NOT EXISTS Question4 (
    IdPerson INT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
    FirstName VARCHAR(255),
    LastName VARCHAR(255)
);
INSERT INTO Question4 (FirstName, LastName)
VALUES('Kevin','Yes'),('Honoka','Kousaka'),('Ashley','Java');


CREATE TABLE IF NOT EXISTS Address (
    IdAddress INT PRIMARY KEY,
    IdPerson INT,
    City VARCHAR(255),
    State VARCHAR(255)
);
INSERT INTO Address(IdAddress,IdPerson,City,State)
VALUES('55','2','Oakville','Ontario'),('24','1','Edmoton','Alberta'),('66','5','Montreal','Quebec');

SELECT FirstName, LastName, City, State FROM 
Question4 LEFT JOIN Address ON Person.IdPerson=Address.IdPerson