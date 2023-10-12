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
    this->rowHead = c.rowHead != nullptr ? new Cell(*c.rowHead) : nullptr;
}

// Task 4
Column::~Column() {
    while (rowHead != nullptr) {
        Cell *temp = rowHead;
        rowHead = rowHead->next;
        temp = nullptr;
        delete temp;
    }
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
                // append new at the end
                Cell *newCell = new Cell();
                // TODO nullptr may cause edge case
                newCell->value = "";
                current->next = newCell;
                newCell->prev = current;
            }
            current = current->next;
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
    } else {
        // 3: Cell to be cleared is the last cell in the column
        delete cellToClear;
        totalRows--;
        // Iteratively delete empty cells from the end of the column
        while (rowHead != nullptr && rowHead->next != nullptr && rowHead->next->value.empty()) {
            Cell *temp = rowHead->next;
            rowHead->next = nullptr;
            delete temp;
        }
    }
}

// Task 8
void Column::clearAllCells() {
    // do while loop or while
    while (rowHead != nullptr) {
        Cell *temp = rowHead;
        rowHead = rowHead->next;
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