#ifndef COLUMN_H
#define COLUMN_H

#include <string>
#include <iomanip>
#include <iostream>
using namespace std;


// This struct represents a cell in a doubly linked list struct Cell
struct Cell
{
    string value;       // The value stored in the cell
    Cell* prev;         // Pointer to the previous cell in the list
    Cell* next;         // Pointer to the next cell in the list
};


class Column
{
    public:

        // ------------------------- part 1 ------------------------
        // Task 1
        Column();
        // Task 2
        Column(Column* prev);
        // Task 3
        Column(const Column& c);
        // Task 4
        ~Column();


        // ------------------------- part 2 ------------------------
        // Task 5
        Cell *findCell(int rowNum);
        // Task 6
        void modifyCell(int rowNum, const string &value);
        // Task 7
        void clearCell(int rowNum);
        // Task 8
        void clearAllCells();
        
        // -------------- helper functions: do not modify --------------

        /**
         * @brief Prints the column to the console.
         */
        void printColumn() const;
        Cell* getRowHead() const {return rowHead;}
        int getTotalRows() const {return totalRows;}
        
        // ---------------------- data members --------------------------
        // Pointer to the previous column
        Column* prev;
        // Pointer to the next column
        Column* next; 


    private:
        // The total number of rows in the column.
        int totalRows;
        // Pointer to the first cell
        Cell* rowHead;


};

#endif
