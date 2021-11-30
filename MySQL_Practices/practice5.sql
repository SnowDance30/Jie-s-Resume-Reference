-- Question5:
-- Write an SQL query to delete all duplicate email addresses in the email table. Only the one with the smallest ID is reserved in the duplicate email address.

DROP TABLE IF EXISTS Question5;

CREATE TABLE Question5 ( 
Id INT PRIMARY KEY, 
Email VARCHAR ( 255 ) 
);
INSERT INTO Question5 
VALUES( 1, 'a@b.com' ),( 2, 'c@d.com' ),( 3, 'a@b.com' );

select Email,
count(*) as count 
from Question5 
group by Email 
having count > 1;

DELETE FROM Question5 
WHERE Id NOT IN 
	( SELECT a.min_id 
		FROM ( SELECT MIN( Id ) AS min_id 
				FROM Question5 GROUP BY Email ) a );