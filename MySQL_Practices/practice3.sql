-- Question 3:
-- As the director of the Information Department of the cinema, you need to write an SQL query to find out all films with non boring descriptions and odd IDs. Please arrange the results by rating.

CREATE TABLE Question3(
    id INT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
    movie VARCHAR(255),
    description VARCHAR(255),
    rating FLOAT
);

INSERT INTO Question3(movie,description,rating)

VALUES('LoveLive','great 3D','8.9'),('Universe','fiction','8.5'),
      ('irish','boring','6.2'),('Ice Song','Fantacy','8.2'),
      ('House card','interesting','9.1');
	  
select * 
from Question3 
where description != 'boring' and 
		id % 2 = 1 
ORDER BY rating DESC;
