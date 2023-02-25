# SQL
**Data** refers to small volume of facts and figures

**Database** refers to large volume of facts and figures.

**DBMS** \
DataBase Management System, This software are used to manage the data in the computer

**SQL**\
SQL stands for Structured Query Language. It is a language which is used to communicate with the database.

**Constraints**
* Unique
* Not Null
* Primary Key
* Foreign Key
* Check
* Default


**Select**
```sql
Select * from user;
Select name from user;
Select name, age from user;
Select name from user where age>25
```

Here `Select` is a command and `from and where` are clauses.

**projection**\
Printing the table, column of all the rows

**selection**\
Printing the records based on the condition

**Q1. Consider you have an employee table, you need to increase the salary by 1000 rupees**
```sql
Select id, name, email, salary+1000 from Employee
```
**Q1. Consider you have an employee table, you need to decrease the salary by 10% of the pervious salary**
```sql
SELECT id, name, email, salary-(salary*10/100) fro Employee
```

**operator precedence in sql**
| operator|
| - |
|*
|/
|+
|-

**Updation**
```SQL
UPDATE bank SET email = "hello@gmail.com"; /*it will change all the email in the column*/

UPDATE bank SET email = "hello@gmail.com" WHERE  name="name"; /*it will update mail only for the record where name="name"*/
```

**Deletion**
```SQL
DELETE FROM amazon; /*Deletes all the record*/

DELETE FROM amazon WHERE account_id=0001; /* Deletes the record with the account id is 0001*/
```
Note: commands are not case sensitive, where as data present in the database are case sensitive

Note: here the index always start from 1


**Functions in SQL**
```sql
SELECT UPPER(name) from student; /*convert to uppercase*/
SELECT LOWER(name) from student; /* convert to Lower case*/
SELECT LENGTH(name) from student; /* shows the length of all the individual name*/
SELECT CONCAT(name,age) from student; /* joins the two column */
SELECT SUBSTR(name,position) from student; /*to get the substring from the position*/
SELECT SUBSTR(name,startPosition, NumberofCharacter) from student; /*to get the substring from the startPosition and prints the NumberofCharacter mention in the function*/
SELECT INSTR(name,'a') from student; /*it tell position of the given character if that present is the giving cell*/
SELECT TRIM(leading '2' from age) from student; /*it remove the occurance of 2 will be trimmed (ex: 23 is trimmed to 3, and 22 is trimmed to NULL, 232 wille timmed to 32)(leading indicates the starting of the number)*/
SELECT TRIM(trailing 'e' from gender) from student; /*it removes the 'e' from the last (helle will trimmed to hell, hee will trimmed to h) (leading indicates the starting of the number)*/
SELECT MIN(age) from student; /* find the minimun in the given column */
SELECT MAX(age) from student; /* find the Maximum in the given column */
SELECT SUM(age) from student; /* give the sum of all the data in the given column column */
SELECT AVG(age) from student; /* give the average of all the data in the given column column */
SELECT COUNT(age) from student; /* give the Count of the data in the given column column */
```

Single row functions | Multiple row functions
-|-
Single row functions are such functions which accepts single row or multiple rows as input but produces 1 result per input. | Multiple row function are such functions single row or multiple rows as input but produces 1 result per group.
ex: if you gives n column and n column as output | ex: if you gives n column and it give 1 column as output.
ex. functions: Upper(),lower(),length(),concat(),substr(),instr(),trim() | ex. functions: min(),max(),sum(),avg(),count()