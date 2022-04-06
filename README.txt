Timothy Queva
CS2910 Lab1
January 28, 2021

IN PROGRESS-NOT COMPLETED

Description: These two programs are a database management system. The first program will convert .csv
files into a .xml format while the second program is the true database management system in that it
allows for manipulation of the database.

Limitation: Only .csv files can be used with first program (part1) and only .xml files can be used with
second program (part2). It is assumed that the ID field is first and the schema is on the first line of
the .csv file. It is also assumed that "ID" is one key in the .xml file with its attributes being the
schema.

-------------------------------------------------------------------------------------------------------------

Instructions: Navigate to the correct file folder.
	1. Compile and link by typing: make
	2. Run first program by typing: ./part1 < Test.csv
	3. Run second program by typing: ./part2

Note: the "Test.csv" in point #2 can be substituted for any .csv file. The default .xml file for the second
program is the Test.xml file which would normally be created by the first program. If you wish to use a 
different .xml file, simply ensure that the Test.xml file is not in the same folder (either move or delete)
and the program will prompt you to provide an .xml for it to use instead.