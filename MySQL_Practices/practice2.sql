-- Question2:
-- Swap all F and m values (for example, change all F values to m and vice versa). Requires an update query with no intermediate temporary tables.

CREATE TABLE Question2(
    num INT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(255),
    sex VARCHAR(255),
    salary INT
);

INSERT INTO Question2(name,sex,salary)
VALUES('1','m','2500'),('2','f','1500'),
      ('3','m','5500'),('4','f','5500');
UPDATE Question2 
set sex = case sex
    when 'm' then 'f'
    when 'f' then 'm'
end;   

SELECT ID，name,sex,salary
FROM Question2;