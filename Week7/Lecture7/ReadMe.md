# SQL
- Structured Query Language
- It is a programming language specifically for talking to databases.

## Flat-File Databases
- From a google forms page, we see 2 questions.
1. What is your favourite language
    - Scratch
    - C
    - Python

2. Whats your  favourite problem from recent problem sets?

- The responses get collected as they come in through to a google spreadsheet.

### What is a flat-file database?
- It is the simplist type of database using a text file which stores rows and collums.
- It is delineated by CSV, comma seperated values.
- It is a file format via which we can store simplistic databases in purely an ASCII or Unicode file.
- This means all the data in CSV file is stored row by row where each entry has a line of its own.
- For the notion of collums, there is a number of ways it can be implemented.
- The simplist way is to put a comma inbetween the values you are collecting.
- You can tell the software to interperate those commas as delineating where one collumn ends and one collumn begins.
- It is a lightweight format using a very familiar tool like a text editor to store data.
- The pros of collecting data with forms is that you can export all of that data in exactly that format CSV.
- So you can download from whatever form page your using and translate it to excel, pdf, html, csv, tsv.
- When click csv, it drops a file into downloads folder on your computer.
- We can translate this to vscode and open the file downloads folder and upload the file to the vscode account.
- This will give you for example:
```
Timestamp,language,problem
11/27/2025 11:56,C,DNA
11/27/2025 11:56,Python,"Hello, World"
11/27/2025 11:56,C,Tideman
etc.
```
- In each of the lines we have commas delineating one piece of data from another.
- The first row is the headers which is interperated as describing the data.
- Notice how in the second data, there are 3 commas instead of 2.
- There are quoues around the data because the name of the pset has a comma in it, so we need to make sure the value escapes any software thats processing this data so that the comma should not be confused with other commas which delineate data.

- Lets write a program in python that iterates over this data.
> code favourites.py
```
import csv

with open("favourites.csv", "r") as file: // opens favourites.cvs and reads data. creating a variable name of file to reffer to.
    reader = csv.reader(file) // create a variable reader and set to return value of csv.reader to read through all the csv file.
    for row in reader: // iterate through all the rows line by line.
        print(row[1]) // printing second collumn in that list (0 indexed).
```
- When run in terminal this will give me in rows, language, C, Python, C (list of language in that collumn).
- The first will be language as it is the metadata, the collumn name.
- How to fix this?
```
import csv

with open("favourites.csv", "r") as file:
    reader = csv.reader(file)
    next(reader) // this is a function that skips the first line if this file.
    for row in reader:
        print(row[1])
```
- Instead of running python favourites.py which will give us all the data, we can:
- python favourites.py | less
- This will show less output from top to bottom.
- When run in terminal this will give me in rows, C, Python, C.
- The first row languages will not be shown due to the next(reader).
- With this information we can now access all the rows by doing row[0] or row[1] or row[2] or row[3] etc.

We can play around with the data by doing this:
```
import csv

with open("favourites.csv", "r") as file:
    reader = csv.reader(file)
    next(reader)
    for row in reader:
        favourite = row[1]
        print(favourite)
```
- Instead of printing out row[1], we create a variable called favourite and set it to row[1] and print out favourite.
- This makes it more user friendly to output data.
- The reason for this is to improve this program.
- The program as written is vulnerable to changes in the csv file as in places like google sheets, you can drag collumns to left or right to reorder.
- The problem of that is if the programmer gets a csv file whose collumns are in a different order, it creates problems for the code.
- To make  it more robust to changes, we can introduce another feature called dictionary reader which give back a dictionary for each row so instead of numeric indicies, we can use strings as keys to get the data we want.
- We can instead use the names of the collumns.
- The dictionary reader assumes the first line of the csv file has the headers of the data.
```
import csv

with open("favourites.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        favourite = row["language"]
        print(favourite)
```
- We remove the next(reader) as we need the first line for the headers.
- Then we insert csv.DictReader(fie) to use the function.
- Then we insert favourite = row["language"] to index into this collumn.
- This code will still work if the files in the spreadsheet get moved around.
- Unless the collumn header names are changed.
- We didnt need that favourite variable so we can do:
```
import csv

with open("favourites.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        print row["language"]
```
- This code iterates through all of the data in the csv file which isnt really a step forward as we can just visually see that in the spreadsheet.
- It would be nice to crunch numbers.
- So we want data such as in the collumn language, how many people chose C, or Python, or Scratch etc.
- To quantify that, we can:
```
import csv

with open("favourites.csv", "r") as file:
    reader = csv.DictReader(file)
    scratch, c, python = 0, 0, 0
    for row in reader:
        favourite = row["langauge"]
        if favourite == "Scratch":
            scratch += 1 // increments by 1.
        elif favourite == "C":
            c += 1 // increment by 1.
        elif favourite == "Python":
            python += 1 // increment by 1.

print(f"Scratch: {scratch}")
print(f"C: {c}")
print(f"Python: {python}")

```
- Create variables of scratch, c, python and set to 0.
- This allows us to count in these variables.
- We create a for loop so that in each row in that dictionary reader, we seet favourite to row["language"], then we grab the current rows favourite language and use conditionals to check what that favourite is.
- We increment 1 time each time it == to that language e.g. "C".
- Then we print each of these languages out and it gives me the data:
- Scratch: 11
- C: 59
- Python: 243
- We can even condense this code by doing something different:
- Revisit the idea of dictionary reader where we get handed back user friendly dictionary objects instead of rows.
- A dictionary is a set of key value pairs.
- Instead of having for insteance 3 seperate variables to keep track of those counts. We can get one dictionary to keep track of all 3 of those languages.
```
import csv

with open("favourites.csv", "r") as file:
    reader = csv.DictReader(file)
    counts = {}
    for row in reader:
        favourite = row["language"]
        counts[favourite] += 1

print(f"Scratch: {scratch}")
print(f"C: {c}")
print(f"Python: {python}")
```
- Get rid of all the variables and the for loop code.
- Introduce a variable called counts that is going to be an empty dictionary.
- {} with nothing inside gives me an empty dictionary, sort if a table that is ready to go.
- Then iterate through each row in that reader.
- Grab current rows favourite by setting variable favourite = row["language"]
- Instead of 3 conditionals, we go into the counts dictionary and index into favourite and increment it by 1. by doing counts[favourite] += 1.
- In otherwords, use the current language, as a key into the counts dictionary, whatever the value is, increment it by 1. 
- This works but is buggy as there could be key errors.
- So instead create an if statement:
```
import csv

with open("favourites.csv", "r") as file:
    reader = csv.DictReader(file)
    counts = {}
    for row in reader:
        favourite = row["language"]
        if favourite in counts:
            counts[favourite] += 1
        else:
            counts[favourite] = 1

for favourite in counts:
    print(f"{favourite}: {counts[favourite]}")
```
- if favourite in counts: // If the count is already there,
- counts[favourite] += 1 // Increment it by one
- else: // If the count is not there,
- counts[favourite] = 1 // Assign it a value.
- Instead of print, we can iterate through every favourite key in that counts dictionary.
- print(f"{favourite}: {counts[favourite]}") This will give me, language.. count, language.. count, etc. by iterating over that dictionary.
- The output will be:
- Python: 243
- C: 59
- Scratch: 11
- But why does the ordering suddenly change?
- It gets ordered by default based on the order in which we inserted those keys.
- So if someone inputs python first, then that will appear first.
- If we want to sort the data, we can say:
- for favourite in sorted(counts)
```
import csv

with open("favourites.csv", "r") as file:
    reader = csv.DictReader(file)
    counts = {}
    for row in reader:
        favourite = row["language"]
        if favourite in counts:
            counts[favourite] += 1
        else:
            counts[favourite] = 1

for favourite in sorted(counts):
    print(f"{favourite}: {counts[favourite]}")
```
- This sorts the key data albhabetically.
- The output will be:
- C: 59
- Python: 243
- Scratch: 11

- What if we want to sort them in order of their values?
- We can specify what key to use to sort the dictionary by using key=counts.get which tells the sorted function that we want to get the value from the counts dictionary and use that as sorting key.
- So it sets the key as whatever the value of the counts is of the dictionary.
```
import csv

with open("favourites.csv", "r") as file:
    reader = csv.DictReader(file)
    counts = {}
    for row in reader:
        favourite = row["language"]
        if favourite in counts:
            counts[favourite] += 1
        else:
            counts[favourite] = 1

for favourite in sorted(counts, key=counts.get):
    print(f"{favourite}: {counts[favourite]}")
```
- This outputs:
- Scratch: 11
- C: 59
- Python: 243
- It seems to be sorted from lowest to highest.
- To sort it from highest to lowest, we can change the code to say whatever we do with sorting, reverse it.
- We do this by setting reverse=True.
```
import csv

with open("favourites.csv", "r") as file:
    reader = csv.DictReader(file)
    counts = {}
    for row in reader:
        favourite = row["language"]
        if favourite in counts:
            counts[favourite] += 1
        else:
            counts[favourite] = 1

for favourite in sorted(counts, key=counts.get, reverse=True):
    print(f"{favourite}: {counts[favourite]}")
```
- This now outputs
- Python: 243
- C: 59
- Scratch: 11

## Relational Databases
- Allows us to store data in such a way we can relate some data to other data.
- SQL supports 4 key pieces of functionality:
1. C - Create
2. R - Read
3. U - Update
4. D - Delete
- CRUD is a helpful mnemonic for keeping track of what you can do with SQL.
- SQL does these 4 things, 3 in which does the exact same terminology - C, U, D
- CRUD is a more general concept in databases more generally in SQL specifically, the command were going to see and use for reading data is select.
- You can insert data in create, or drop data in delete. etc.
- What can we do in SQL.
- We need a database to start playing with.
- The data in databases are stored in tables, which have rows and collumns.
- If there are multiple sets of data inside the same file, we can create more sheets.
- In the world of relational databases, which are used for mobile applications, web applications, business applications, etc. we can have an analogue of that same idea.
- In relational databases, we call sets of data tables, which have rows and collumns, which is really an analogue of sheets in the world of spread sheets.
- The command which we can create such a table is:
```
CREATE TABLE table (column type, ...);
```
- Where do we run this?
- A command line programm to access a database, sqlite3.
- This is a light base version of SQL.
- It stores all of your data onto a file in your hardware.
- There are so many SQL databases that have different dialects.
- Sqlite3 have the core features of any SQL databases.
- How do we use sqlite3?
- We install the software and run command line programm called sqlite3.
- It is a command line program which we can create a database and execute commands inside that database.
- PREWARNING
    - If ...> appears after running a command, type Control-D to escape.
- The syntax for creating new databse with the sqlite3 command is:
```
sqlite FILE (the name of the database you want to create)
e.g. sqlite3 favourites.db
```
- It will then as are you sure you want to create it? which you reply yes.
- It is inside a program that is running until you quit out of it.
- Then we do:
```
.mode csv
```
- This can import different text files such as csv tsv etc.
- The command starts with a . beacuse it is configuring sqlite program itself.
- Then we can:
```
.import favourites.csv favourites
```
- We have a file called favourites.csv, we created a new file called favourites.db, and we are storing inside the favourites.db file, a table called favourites.
- This is like having a sheet called favourites inside of a file called favourites.xlsx
- After import, we can 
```
.quit
```
- Which gets us back to the terminal.
- Now when we do ls, we see favourites,csv, favourites.db, favourites.py
- We can return sqlite3 favourites.db which brings us back into the prompt.
- We can do
```
.schema
```
- This is the design of the database, showing the tables in there.
- The output of .schema is:
```
CREATE TABLE IFNOT EXISTS "favourites"("Timestamp" TEXT, "language", TEXT, "problem", TEXT);
```
- What type of data was imported?
- The .import command is naive and if it just sees data, its going to assume its text, text, text. Even if it looks like numbers, it will still assume its text.
- Theres actually proper data types we can do.
- The .import command automatically gets going with a SQLite database containing all of the same data as a CSV.
- If for work, you have a csv file that is part of the task, you can quickly import it into your own SQLite database and instantly start executing the following types of SQL commands on it to answer questions about that data.

- Lets introduce the first of those CRUD commands which we can read data from a database.
- The command for reading data is SELECT.
```
SELECT columns FROM table;
```
- It selects data from a database and reads it.
- Then specify one or more collumns you want to select data from.
- You specify what table you want those columns to come from.
- This is the simplest form of the select statement in SQL.
- To test this:
```
SELECT * FROM favourites;
```
- (*) in this case is a wild card representing ever column in the table.
- This allows you to glance at a file from the screen.
- We see an ASCII art version of the tabular data.
- The commas have been interperated in advance as deliniating columns which allow us to visually see vertical columns/pipes.
- If we want to select only one column:
```
SELECT language FROM favourites
```
- We are creating a temporarily in memory a virtual table of the data that we care about. We are dumping it to the screen.
- Besides from just selecting the data, we have functions built in:
- AVG
- COUNT
- DISTINCT
- LOWER
- MAX
- MIN
- UPPER
- SQL is commenly used in data science because it lets us answer questions about data.
- E.G. If we want to compute averages, or count the number of rows, or unique or distinct values in a dataset etc...
- To see how many people submitted the form before downloading it into codespace:
```
SELECT COUNT(*) FROM favourites;
```
- This gives us back a temporary table that contains one value of interest, 13 submissions.
- If we want to get the unique values of everyones favourite language, use DISTINCT
```
SELECT DISTINCT language FROM favourites;
```
- This gives me back Python, C, Scratch.
- What if we want to count how many unique languages there are?
```
SELECT COUNT(DISTINCT langauge) FROM favourites;
```
- This gives me back 3.
- There are even more functions and keywords we can use:
- GROUP BY
- LIKE
- LIMIT
- ORDER BY
- WHERE
- We can group data. look for dara thats LIKE a certain value not exactly equal to, we can limit how much data comes back, we can order or sort the data, and we can also use conditionals, filters, otherwise known as predicates, to get back subsets of data.
- For example, how many like C?:
```
SELECT COUNT(*) FROM favourites WHERE language = 'C';
```
- We use quotes when we want to quote a string value, a tectual value, a literal, we use single quotes.
- This is saying seect the count of all of the rows from favourite where the language from that row = C.
- This gives me: 3, as there were 3 C inputs.
- How to find out how many peopleliked a particular problem?
```
SELECT COUNT(*) FROM favourites WHERE language = 'C' AND problem = 'Mario';
```
- Key word is AND. This is giving me some booleon average.
- The output is 2, as Mario shows up 2 times in the database.
- What have we been doing stylistically?
- We have kept capitalizing SELECT and COUNT and FROM and WHERE and AND, then using lowercase as appropriate for everything else.
- This is a stylistic convention.
- Use uppercase keywords for anthing thats built into SQL itself.
- Then use proper capitalization for any tables you yourself have created, for any values youre searching from, this is so it is more readable when you can distinguish what is SQL code.
- If we want to check for popularity of two different problems, we can say:
```
SELECT COUNT(*) FROM favourites WHERE language = 'Python' AND (problem = 'Scratch' OR problem = 'Caesar');
```
- The probem here is that there are 