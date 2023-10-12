#include "Table.h"

// Task 9
Table::Table()
{
    this->totalColumns = 0;
    this->columnHead = nullptr;
}

// Task 10
Table::~Table()
{
    while (columnHead != nullptr)
    {
        Column *temp = columnHead;
        columnHead = columnHead->next;
        delete temp;
    }
}

// Task 11
Column *Table::findColumn(int colNum) const
{
    if (colNum + 1 > totalColumns)
    {
        return nullptr;
    }
    Column *current = columnHead;
    int i = 0;
    while (i < colNum)
    {
        current = current->next;
        i++;
    }
    return current;
}

// Task 12
void Table::copyInsertColumn(int fromColNum, int toColNum)
{
    // Handle the first scenario (source column not created)
    if (fromColNum >= totalColumns)
    {
        // Create an empty column
        Column *newColumn = new Column();

        // Insert at the specified position (toColNum)
        if (toColNum == 0)
        {
            newColumn->next = columnHead;
            columnHead = newColumn;
        }
        else
        {
            Column *prevColumn = findColumn(toColNum - 1);
            if (prevColumn)
            {
                newColumn->next = prevColumn->next;
                prevColumn->next = newColumn;
            }
            else
            {
                // Invalid 'toColNum', do nothing
                delete newColumn;
                return;
            }
        }

        totalColumns++;
    }
    else
    {
        // Handle the second scenario (empty source column and toColNum not created)
        if (fromColNum >= 0 && toColNum >= totalColumns)
        {
            return;
        }

        // Find the source column
        Column *sourceColumn = findColumn(fromColNum);
        if (!sourceColumn)
        {
            return; // Source column not found
        }

        // Create a new column by copying the source column
        Column *newColumn = new Column(*sourceColumn);

        // Handle the third and fourth scenarios
        if (toColNum < totalColumns)
        {
            // Insert in the middle of existing columns
            if (toColNum == 0)
            {
                newColumn->next = columnHead;
                columnHead = newColumn;
            }
            else
            {
                Column *prevColumn = findColumn(toColNum - 1);
                if (prevColumn)
                {
                    newColumn->next = prevColumn->next;
                    prevColumn->next = newColumn;
                }
            }
            totalColumns++;
        }
        else
        {
            // Insert at or beyond total columns
            if (totalColumns == 0)
            {
                columnHead = newColumn;
            }
            else
            {
                Column *lastColumn = findColumn(totalColumns - 1);
                lastColumn->next = newColumn;
            }
            totalColumns = toColNum + 1;
        }
    }
}

// Task 13
void Table::deleteColumn(int colNum)
{
    if (colNum >= totalColumns)
    {
        return; // Column does not exist
    }

    // Handle the case where colNum is 0 (deleting the first column)
    if (colNum == 0)
    {
        Column *temp = columnHead;
        columnHead = columnHead->next;
        delete temp;
        totalColumns--;
    }
    else
    {
        Column *prevColumn = findColumn(colNum - 1);
        if (!prevColumn)
        {
            return; // Invalid column number
        }

        Column *columnToDelete = prevColumn->next;
        if (columnToDelete)
        {
            prevColumn->next = columnToDelete->next;
            delete columnToDelete;
            totalColumns--;

            // Check if the deleted column is the last one, and if it's empty
            if (colNum == totalColumns - 1)
            {
                // Find the new last column
                Column *lastColumn = prevColumn;
                while (lastColumn->next)
                {
                    lastColumn = lastColumn->next;
                }

                // Check if the new last column is empty and delete recursively
                while (lastColumn && (!lastColumn->getTotalRows()) == 0)
                {
                    // Delete the last empty column
                    Column *prevLastColumn = findColumn(totalColumns - 2);
                    prevLastColumn->next = nullptr;
                    delete lastColumn;
                    lastColumn = prevLastColumn;
                    totalColumns--;
                }
            }
        }
    }
}

// Task 14
Cell *Table::findCell(int colNum, int rowNum) const
{
    Column *col = findColumn(colNum);
    if (col == nullptr)
    {
        return nullptr;
    }
    return col->findCell(rowNum);
}

// Task 15
void Table::modifyCell(int colNum, int rowNum, const string &value)
{
    if (colNum < totalColumns)
    {
        Column *col = findColumn(colNum);
        if (col == nullptr)
        {
            return;
        }
        col->modifyCell(rowNum, value);
    }
    else
    {
        Column *current = columnHead;
        for (int i = 0; i < colNum; i++)
        {
            if (i + 1 >= totalColumns)
            {
                Column *newCol = new Column();
                current->next = newCol;
                newCol->prev = current;
            }
            current = current->next;
        }
        // last column, i.e. current = colNum
        current->modifyCell(rowNum, value);
        totalColumns = colNum + 1;
    }
}

// Task 16
void Table::clearCell(int colNum, int rowNum)
{
    Cell *cell = findCell(colNum, rowNum);
    if (cell == nullptr) //Cell does not exist
    {
        return;
    }
    if (colNum < totalColumns)
    {
        Column *col = findColumn(colNum);
        if (col == nullptr) // Column does not exist
        {
            return;
        }
        col->clearCell(rowNum);
        // the function also checks if the previous Column is also empty. If the previous Column is empty, a recursive deletion of empty columns
        if (colNum + 1 == totalColumns) {
            // Check if the previous Column is also empty
            if (colNum == 0) {
                // If this is the first column, check if it's empty
                if (col->getTotalRows() == 0) {
                    // Recursive deletion of empty columns
                    deleteColumn(colNum);
                }
            } else {
                // If it's not the first column, check the previous column
                Column *prevCol = findColumn(colNum - 1);
                if (prevCol && prevCol->getTotalRows() == 0) {
                    // Recursive deletion of empty columns
                    deleteColumn(colNum - 1);
                }
            }
        }
    }
}

// ---------------------- provided functions: DO NOT MODIFY --------------------------
void Table::printTable() const
{

    // find the max number of rows
    int maxRows = 0;
    Column *currCol = columnHead;
    while (currCol != nullptr)
    {
        if (currCol->getTotalRows() > maxRows)
        {
            maxRows = currCol->getTotalRows();
        }
        currCol = currCol->next;
    }

    cout << "totalColumns: " << totalColumns << "\t ";
    cout << "maxRows: " << maxRows << endl;

    // string styles
    string line(12, '-');
    string doubleline(12, '=');
    string space(12, ' ');
    string headerline((totalColumns + 1) * 12, '=');

    // print table table header
    cout << headerline << endl;
    cout << " " << std::setw(10) << ""
         << "|";
    for (int i = 0; i < totalColumns; ++i)
    {
        cout << "|" << std::setw(10) << "column " + to_string(i) + " "
             << "|";
    }
    cout << endl;
    cout << headerline << endl;

    // print table body (row by row)
    string hline;
    for (int i = 0; i < maxRows; ++i)
    {
        hline = doubleline;
        cout << " " << std::setw(10) << "row " + to_string(i) + "  "
             << " ";

        currCol = columnHead;

        while (currCol != nullptr)
        {
            Cell *currCell = currCol->findCell(i);
            if (currCell == nullptr)
            {
                hline += space;
                cout << " " << std::setw(10) << ""
                     << " ";
            }
            else
            {
                hline += line;
                cout << "|" << std::setw(10) << currCell->value << "|";
            }
            currCol = currCol->next;
        }
        cout << endl;

        cout << hline << endl;
    }

    cout << endl;
    return;
}