#include "Column.h"

// Task 1
Column::Column() : totalRows(0) {
    this->rowHead = nullptr;
    this->next = nullptr;
    this->prev = nullptr;
}

// Task 2
Column::Column(Column *prev) : totalRows(0) {
    this->rowHead = nullptr;
    this->next = nullptr;
    this->prev = prev;
}

// Task 3
Column::Column(const Column &c) : totalRows(c.totalRows) {
    this->next = nullptr;
    this->prev = nullptr;
    if (c.rowHead != nullptr) {
        // Initialize the rowHead of the current column with an empty cell
        this->rowHead = new Cell();
        Cell *currentCell = this->rowHead;

        // Initialize the value of the first cell
        currentCell->value = c.rowHead->value;

        // Initialize the 'next' pointer for the first cell
        currentCell->next = nullptr;

        Cell *sourceCell = c.rowHead->next;

        while (sourceCell != nullptr) {
            // Create a new cell for the current column
            currentCell->next = new Cell();
            currentCell = currentCell->next;

            // Copy the value from the source cell to the current cell
            currentCell->value = sourceCell->value;

            // Initialize the 'next' pointer for the current cell
            currentCell->next = nullptr;

            sourceCell = sourceCell->next;
        }
    } else {
        // If the source column's rowHead is nullptr, set the current column's rowHead to nullptr as well
        this->rowHead = nullptr;
    }
}

// Task 4
Column::~Column() {
//    while (rowHead != nullptr) {
//        Cell *temp = rowHead;
//        rowHead = rowHead->next;
//        temp = nullptr;
//        delete temp;
//    }
    clearAllCells();
}

// Task 5
Cell *Column::findCell(int rowNum) {
    if (rowNum >= totalRows) {
        return nullptr;
    }
    Cell *current = rowHead;
    int i = 0;
    while (i < rowNum) {
        current = current->next;
        i++;
    }
    return current;
}

// Task 6
void Column::modifyCell(int rowNum, const string &value) {
    if (rowNum < totalRows) {
        Cell *cell = findCell(rowNum);
        cell->value = value;
    } else {
        Cell *current = rowHead;
        if (current == nullptr) {
            current = new Cell();
            rowHead = current;
        }
        for (int i = 0; i < rowNum; i++) {
            if (i + 1 >= totalRows) {
                // Append new cell at the end
                Cell *newCell = new Cell();
                newCell->value = "";
                current->next = newCell;
                newCell->prev = current;
                current = newCell;
            } else {
                current = current->next;
            }
        }
        // last row
        current->value = value;
        totalRows = rowNum + 1;
    }
}

// Task 7
void Column::clearCell(int rowNum) {
    if (rowNum >= totalRows) { // 1: Requested Cell does not exist in the column
        return;
    }
    // Cell to be cleared is not the last cell in the column (rowNum < totalRows - 1): sets the value of the found cell to an empty string.
    // Cell to be cleared is the last cell in the column (rowNum == totalRows - 1): after deleting the last cell, the function removes any unnecessary cells from the end of the column. It iteratively deletes cells as long as their values remain empty and there are more cells to delete.

    Cell *cellToClear = findCell(rowNum);

    if (rowNum < totalRows - 1) {
        // 2: Cell to be cleared is not the last cell in the column
        cellToClear->value = "";
    } else if (rowNum == totalRows - 1 && rowNum >= 0) {
        // 3: Cell to be cleared is the last cell in the column
        totalRows--;
        cellToClear = nullptr;
        Cell *prevCellToClear = findCell(rowNum - 1);
        Cell *tmp = prevCellToClear;
        if (tmp == nullptr || tmp->value.empty()) {
            tmp = tmp->next;
            tmp = nullptr;
            delete tmp;
            clearCell(rowNum - 1);
        }
    }
//    if (rowNum >= totalRows) {
//        return;
//    }
//
//    Cell *cellToClear = findCell(rowNum);
//    cellToClear->value = "";
//
//    if (rowNum == totalRows - 1) {
//        // If it's the last cell, remove any unnecessary cells from the end.
//        totalRows--;
//        if (rowNum > 0) {
//            Cell *prevCell = findCell(rowNum - 1);
//            while (prevCell && prevCell->next) {
//                if (prevCell->next->value.empty()) {
//                    Cell *temp = prevCell->next;
//                    prevCell->next = temp->next;
//                    delete temp;
//                } else {
//                    break;
//                }
//            }
//        }
//    }
}

// Task 8
void Column::clearAllCells() {
    // do while loop or while
//    while (rowHead != nullptr) {
//        Cell *temp = rowHead;
//        temp = temp->next;
//        temp = nullptr;
//        delete temp;
//    }
//    totalRows = 0;
//    rowHead = nullptr;
    Cell *current = rowHead;
    // do while loop or while
    while (current != nullptr) {
        Cell *temp = current;
        current = current->next;
        delete temp;
    }
    totalRows = 0;
    rowHead = nullptr;
}

// ---------------------- provided functions: DO NOT MODIFY --------------------------
void Column::printColumn() const {
    // string styles
    string line(12, '-');
    string doubleline(12, '=');
    string space(12, ' ');

    cout << "totalRows: " << totalRows << endl;

    // table header
    cout << doubleline + doubleline << endl;
    cout << " " << std::setw(10) << ""
         << " ";
    cout << "|" << std::setw(10) << "column "
         << "|" << endl;
    cout << doubleline + doubleline << endl;

    // table body (row by row)
    Cell *current = rowHead;
    for (int i = 0; i < totalRows; ++i) {
        cout << " " << std::setw(10) << "row " + to_string(i) + " "
             << " ";
        cout << "|" << std::setw(10) << current->value << "|" << endl;
        current = current->next;
        cout << doubleline + line << endl;
    }

    cout << endl;
}
