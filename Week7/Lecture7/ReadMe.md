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