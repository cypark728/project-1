This project is for <2020 - 1 Open Source software Lab, Handong Global University>

Authoer : Park, ChanYoung
Project : Kartrider track record report program

The program consists of three files.

1. main.c
   - Managing all of the menus. 

2. track_record.c
   - Library functions.

3. track_record.h
   - Structures, Macro, Function prototypes.


<Details>


1. main.c
    1) Create
        : Create a new record, and the informaiton of data is input by user
    2) Read
        :   Read all of the records
    3) Update
        :   Update the record searched by id
    4) Delete
        :   Delete the record searched by id
    5) Search
        :   Print the record searched by id
    6) Search(name)
        :   Print the record searched by name
    7) Rank
        :   Print the ranking of the tracks enterd
    8) Sort
        :   print records sorted by track name
    9) Load
        :   Load records from a certain data file
    10) Save
        :   Save records to a certain data file
    

2. track_record.c
    1) It contains track_record pointer array.
    2) It contains functions that used in main.c.

3. track_record.h
    1) It contains a structure type for track_record, and funtion declarations(prototypes)


4. MakeFile
    1) make main
        : main executable file is made.
    2) make main_debug
        : main executable file applied DEBUG is made.
    3) make clean
        : remove all of the executable files

5. track_record.txt
    1) This file have 50 track_record for test.
