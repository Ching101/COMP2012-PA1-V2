#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Column.h"
using namespace std;


class Table
{
    public:
    
        // ------------------------- Note --------------------------
        // All negative integer inputs of colNum and rowNum will be handled in main.cpp
        // All the cells are of type string. if the cell is empty, the value of the cell is ""

        // ------------------------- part 1 ------------------------
        
        // Task 9
        Table();
        // Task 10
        ~Table();


        // -------------- part 2: work on column level -------------
        // Task 11
        Column* findColumn(int colNum) const;
        // Task 12
        void copyInsertColumn(int fromColNum, int toColNum);
        // Task 13
        void deleteColumn(int colNum);
        
        
        // -------------- part 3: work on cell level -------------
        // Task 14
        Cell *findCell(int colNum, int rowNum) const;
        // Task 15
        void modifyCell(int colNum, int rowNum, const string &value);
        // Task 16
        void clearCell(int colNum, int rowNum);

        // -------------- helper functions: do not modify --------------
        /**
        @brief Prints the table to the console.
        */
        void printTable() const;


    private:
        // Pointer to the column 0
        Column* columnHead; 
        // The total number of allocated columns in the table
        int totalColumns; 
};

#endif

