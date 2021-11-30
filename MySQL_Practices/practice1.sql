-- Question:
-- Write an SQL query to list all classes with more than or equal to 5  -- students.
-- Students should not be double counted in each class

create database Question1;
use Question1;
CREATE TABLE IF NOT EXISTS courses (
student VARCHAR(255),
subject VARCHAR(255)
);

INSERT INTO courses(student,subject)
VALUES('A','Math'),
('B','English'),
('C','Math'),
('D','Biology'),
('E','Math'),
('F','Computer'),
('G','Math'),
('H','Math'),
('I','Math'),
('A','Math');
SELECT subject 
FROM courses
GROUP BY subject
HAVING COUNT(DISTINCT student) >= 5;