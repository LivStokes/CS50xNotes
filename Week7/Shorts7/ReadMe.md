# SQL
## What is a database
- what a database is, why we would use it, and how we might manipulate it?
- To build websites that are more complex than just a page, we might need a database to store information, such as username and password combinations so that a user attempts to log in. 
- That log-in information is sent to the database. 
- It is checked against information in the database to see whether that username-password combination matches. If so, it lets the user in.
- We might also store other stuff for users, like their shopping history or really any other information that you might want to keep long-term for a user.
- programs like Microsoft Excel or Google Sheets or Numbers have a database.
- A database consists of a couple of different levels of hierarchy.
-  Within a database, we have tables. And within each of those tables, we have rows and columns.
- with Excel, we can draw an analogy for what a database, a table, a row, a column is.
- And then we can translate that in just a moment to the same idea in SQL.

## What are sheets
- After opening an Excel file, across the top you can see the names of the different columns.
- Down the left is the numbered rows, where information goes.
- for example, puting name in cell A1. So it's in the A column in the first row. (top right).
- Down at the bottom left is a notion of sheets. 
- Sheets are akin to differennt tables.
-  each sheet has its own unique set of rows and columns.
- But all of these sheets are still bound up in one single file.
- So the analogy here is that Book 1 is our database (name of file), which contains a different number of tables, which in Excel parlance is just a sheet.
- And each sheet has columns that we can put data in and rows that we can put data in, as well.

## Types of database engines
- there are a couple of different types of database engines that we can use in our programs.
- We're going to talk about SQL which stands for the Structured Query Language.
- The Structure Query Language is a programming language whose sole purpose in life is to query or ask questions of or retrieve data from a database.
- there are many different implementations of SQL.
- Two of the most popular: 
1. MySQL which is an open-source platform. 
- It is very commonly used to establish relational databases. 
- There are more than one type, and we cover relational databases in this course.
2. SQLite, which has a very similar feature set to MySQL. 
- It's a little more lightweight than MySQL and easier to use on CS50 IDE.
- Regardless of which implementation of SQL you use, they will come with a tool called phpMyAdmin, which is a GUI or Graphical User Interface tool that is used to execute some of the more tedious or mundane database queries in a more user friendly way.
- The first thing you're going to do once you get your database configured, is to create a table.
- Without a table we have no rows and columns, without rows and columns we can't store any data.
- Tables have very cumbersome syntax that is used to set them up, so using phpMyAdmin to build a table will help.
- In the process of building your table, you're going to have to specify exactly which columns are going to be stored in that table.
- When you create your table, you say, my table's going to store usernames and passwords and whatever sort of other information you want. Must specify that, before you have inserted any data into the table.
- Design ahead of time what your table is going to look like.
- All queries will refer to rows of the table.

## Data types
- Each column of your SQL table is capable of holding data of a particular type.
- Examples of datatypes:
- INT
- SMALL INT
- TINYINY
- MEDIUMINT
- BIGINT
- DECIMAL
- FLOAT
- BIT
- DATE
- TIME
- DATETIME
- TIMESTAMP
- CHAR
- VARCHAR
- BINARY
- BLOB
- TEXT
- ENUM
- GEOMETRY
- LINESTRING
- etc...

- We have int, but we also have these four other types, which can hold integers with different upper bounds.
- Recall from C that the upper bound of integer is 2 to the 31st power, or 2 to the 32nd power if they're unsigned integers.
- But here we can say small ints or tiny ints or medium or big ints, each of which have different upper bounds on the values.

- geometry and line strings can be used to store in a SQL database a mapping out or a drawing out of an area on a map, such as using GIS data.
- And we can actually store that in our SQL table and recreate that exact drawing a little bit later on.

- Text sort of stands in the stead of strings for just arbitrarily large chunks of text.

- an enum is is it is a column of your table that can be used to store a limited set of values.
    - For example, I could have an enum that is called favorite colors. 
    - And I could specify when I'm building my table that it can only be capable of holding red, green, and blue.
    -  If you tried to insert a row that had purple in that place, that wouldn't work because it is not one of the enumerated values that can be stored in that column.

- Char is akin to our notion of a string, but with a fixed length. When we specify a char or a varchar type, we have to specify the length of that string at the outset.
    - For example, my column type might be a CHAR(10). That means that I can store 10 character strings in that column of my table, exactly 10 character strings.
    - it's always going to be 10, every time.
    - Fixed length strings.

- A varchar, on the other hand, refers to a variable-length string. 
    - So if I said that my column was VARCHAR(99), I can store 1, 2, 3, 4, 5 character strings, up to 99 characters long, without having to have all of this extra sort of slack space or null bytes or zeros tacked onto the end.
    - Variable length strings.

- Each of those data types is affiliated with what's called a type affinity to simplify things.
- That whole list can be reduced to one of these five different affinities:
1. null, nothing.
2. integer, whole numbers.
3. real, decimal float.
4. text, char varchar
5. blob, geometry or data that isnt really text but a large number of bit or bytes.

## Primary key
- After specifying the columns, it's important in our SQL table to have one other consideration, which is to have one column which is our primary key.
- The primary key is needed as every row of our table, in order to make our SQL queries most effective, should be able to be uniquely and quickly identified.
- The primary key will allow us to make sure that there is one value in every row that is completely unique.
- A joint primary key, which is just a combination of, say, two columns, or can be an arbitrarily large number of columns, that is always guaranteed to be unique.

## Insert
- SQL has a very limited vocabulary. 
- Focus is on INSERT, SELECT, UPDATE, and DELETE.
- We're going to consider a database that contains these two tables called users and moms:
```
Users
idnum | username | password | fullname
11 | jerry | fus!ll! | Jerry Seinfeld
10 | gcostanza | b0sc0 | George Constanza

Moms
username | mother
jerry | Helen Seinfeld
gcostanza | Estelle Costanza
```
- users has four different columns-- idnum, username, password, and fullname. 
- And moms has two different columns, username and mother.
- the first operation we'll cover is insert, it adds information to a table.
- An insert query, looks something like this-- 
```
INSERT INTO 
<table>
(<columns>) 
VALUES
(<values>)
```
- table, So we specify what table we want to insert into.
- columns, which is a comma-separated list of all of the columns of our table that we want to insert data into.
- Values we want to put into those columns.
- So for example, I might want to INSERT INTO users into these three columns: username, password, name. 
- The values, respectively: newman, in lowercase for the username, USMAILwhich is corresponding to the password, and then capital-N Newman for fullname.
- This adds a row to the users table.
```
Users
idnum | username | password | fullname
11 | jerry | fus!ll! | Jerry Seinfeld
10 | gcostanza | b0sc0 | George Constanza
12 | newman | USMAIL | Newman

Moms
username | mother
jerry | Helen Seinfeld
gcostanza | Estelle Costanza
```

### Auto Increment
- But no ID number was specified?
- It added a 12 automatically.
- When defining a column that ultimatly ends up being your tables primary key, its usually a good idea to have that column be an integer.
- To eliminate that situation where you may accidentally forget to specify a real value for the primary key column, you can configure that column to autoincrement, so it will pre-populate that column for you automatically when rows are added to the table.
- When you set up your primary key, you usually want it to be an integer, and you usually want it to autoincrement so that you can completely forget about having to worry about that and let the table do it for you.
- Lets insert more information to the table:
```
INSERT INTO
moms
(username, mother)
VALUES
('kramer', 'Babs Kramer')
```
this is what we would have as a result:
```
Users
idnum | username | password | fullname
11 | jerry | fus!ll! | Jerry Seinfeld
10 | gcostanza | b0sc0 | George Constanza
12 | newman | USMAIL | Newman

Moms
username | mother
jerry | Helen Seinfeld
gcostanza | Estelle Costanza
kramer | Babs Kramer
```

## Select
- select is used to get that information back out of the table so that we can do something with it.
- Select queries also have a very similar skeleton. 
- And they look like this:
```
SELECT
<columns>
FROM
<table>
WHERE
<condition>
ORDER BY
<column>
```
- SELECT and then whatever columns you want to choose 
- FROM whichever table you want to choose them from. 
- And then optionally WHERE some condition is satisfied.
- WHERE in particular is going to be used so that you don't get your entire database back.
- In the context of SQL, refer to a condition as a predicate.
- We're just checking to see that some situation is true.
- ORDER BY to order them by a specific column so they are organised alphabetically by the values in some column or whatever else.
- ORDER BY just helps to keep things a little more organized.- For eample, heres a select query:
```
SELECT
idnum, fullname
FROM users
```
- It will look through each row of the table and pull out the ID number and the full name and give me the list down the entire users table.
- To restrict the query:
```
SELECT
password
FROM
user
WHERE
idnum < 12
```
- The < 12 is a predicate / condition.
- Because idnum is < 12, it will only give me back 10, and 11 which is:
- This will give me back fus!ll!, and b0sc0.
- We can also do this:
```
SELECT
*
FROM
moms
WHERE
username = 'jerry'
```
- (*) is shorthand for every column.
- So instead of having to specify username, mother, the two columns here, or, if I was using the users table, having to specify idnum, username, password, fullname, I can just say SELECT *.
- This will give me back: jerry, Helen Seinfeld.

### Relational databases
- We dont have to have just 2 tables.
-  We also don't have to have just one table that stores every relevant piece of information about a user.
- If we wanted to store, in addition to what we have there, information like their address and their date of birth and their social security number etc, this table could get bigger.
- It could get annoying, so we can use relationships between different tables which is where the term relational comes into play for a relational database.
- We can set up our tables within our databases carefully enough that we can use relationships between them to pull information from where we need it without all that information having to be located in the same table in the first place.

- For example, this is our previous database:
```
Users
idnum | username | password | fullname
11 | jerry | fus!ll! | Jerry Seinfeld
10 | gcostanza | b0sc0 | George Constanza
12 | newman | USMAIL | Newman

Moms
username | mother
jerry | Helen Seinfeld
gcostanza | Estelle Costanza
kramer | Babs Kramer
```
- Say if we want to pair a user's full name, with their mother's name, but they're not on the same table. 
- We can't use the same sort of select query that we used before, we have to use what's called a **select join query**.
- SELECT (JOIN), thich extracts information from multiple tables.
```
SELECT
<column>
FROM
<table1>
JOIN
<table2>
ON
<predicate>
```
- So I want to select a specific set of columns from one table, joining another table onto it just temporarily.
- It doesnt merge them, but creates a hypothetical table that does merge them.
- We're trying to find where the two tables overlap so that we can create this merged table just temporarily for purposes of this query, and then have them separate again.
- For example:
```
SELECT
users.fullname, moms.mother
FROM
moms
ON
users.username = moms.username
```
- I'm now prepending some of my column names with table names
- This is because in each of those two tables I had a column called username, I need to disamiguate between them to specify what table and what column.
- What happens on execusion:
```
users
username
jerry
gcostanza

moms
username
jerry
gcostanza
```
```
users & moms
users.idnum | users.username moms.username | users.password | users.fullname | moms.mother
10 | jerry | fus!ll! | Jerry Seinfeld | Helen Seinfeld
11 | gcostanza | b0sc0 | Geoge Costanza | Estelle Costanza
```
- This query didnt want to select everything, just fullname and mothers name whcih gives us this information:
```
users & moms
users.fullname | moms.mother
Jerry Seinfeld | Helen Seinfeld
George Costanza | Estelle Costanza
```

## Update
- This modifys information in a table.
- The skeleton looks like this:
```
UPDATE
<table>
SET
<column> = <value>
WHERE
<predicate>
```
- we're updating some column to have a new piece of data in it
-  We're trying to figure out which row we want to update, and then we're updating that column.
- For eample, I want to UPDATE users SET password equals yadayada WHERE idnum equals 10.
```
UPDATE
users
SET
password = 'yadayada'
WHERE
idnum = 10
```
- This will change the table to look like this:
```
Users
idnum | username | password | fullname
11 | jerry | yadayada | Jerry Seinfeld
10 | gcostanza | b0sc0 | George Constanza
12 | newman | USMAIL | Newman

Moms
username | mother
jerry | Helen Seinfeld
gcostanza | Estelle Costanza
kramer | Babs Kramer
```

## Delete
- This strikes or cimpletely removes information from a table.
- The framework looks like this:
```
DELETE FROM
<table>
WHERE
<predicate> 
```
- For example:
```
DELETE FROM
users
WHERE
username = 'newman'
```
- This will make the table look like this:
```
Users
idnum | username | password | fullname
11 | jerry | yadayada | Jerry Seinfeld
10 | gcostanza | b0sc0 | George Constanza

Moms
username | mother
jerry | Helen Seinfeld
gcostanza | Estelle Costanza
kramer | Babs Kramer
```

## Conclusion
- All the operations are pretty easy to do in the graphical interface of phpMyAdmin.
- We want a way to do this programmatically, not just typing SQL commands into the SQL tab of phpMyAdmin.
- SQL integrates with other programming languages such as Python or PHP very easily.
- phpMyAdmin, despite being very user-friendly to use, requires manual intervention. Instead, we want to write code that does this.