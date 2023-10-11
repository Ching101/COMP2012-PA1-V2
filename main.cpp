#include <iostream>
#include <string>
#include "Column.h"
#include "Table.h"

using namespace std;

string getStringInput(const string &msg = {})
{
    string input = "";
    cout << msg;
    cin >> input;
    return input;
}

int getIntInput(const string &msg = {})
{
    int input;
    cout << msg;
    cin >> input;

    if (cin.fail() || input < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        return getIntInput(msg);
    }

    return input;
}

void testCol()
{

    string menu = "Options:\n1. Modify cell\n2. Clear cell\n3. Clear all cells\n";
    menu += "4. Exit program\n\nOption: ";

    Column *col = new Column;
    while (true)
    {

        int option = getIntInput(menu);
        if (option == 1)
        {
            int row = getIntInput("position (row):");
            string value = getStringInput("value: ");
            col->modifyCell(row, value);
            col->printColumn();

            continue;
        }

        if (option == 2)
        {
            int row = getIntInput("position (row): ");
            col->clearCell(row);
            col->printColumn();

            continue;
        }

        if (option == 3)
        {
            col->clearAllCells();
            col->printColumn();

            continue;
        }

        if (option == 4)
        {
            cout << "Exit program." << endl;
            break;
        }

        cout << "Invalid input. Please try again." << endl;
        cout << endl;
    }
    delete col;
}

void testTable()
{

    Table *table = new Table;
    cout << "Table initial state:" << endl;
    table->printTable();

    string menu = "Options:\n1. Modify cell\n2. Clear cell\n3. Copy and insert column\n";
    menu += "4. Delete column\n5. Exit program\n\nOption: ";

    while (true)
    {

        int option = getIntInput(menu);

        if (option == 1)
        {
            int col = getIntInput("position (col): ");
            int row = getIntInput("position (row): ");
            string value = getStringInput("value: ");
            table->modifyCell(col, row, value);
            table->printTable();
            continue;
        }

        if (option == 2)
        {
            int col = getIntInput("position (col): ");
            int row = getIntInput("position (row): ");
            table->clearCell(col, row);
            table->printTable();
            continue;
        }

        if (option == 3)
        {

            int col = getIntInput("position (col to copy): ");
            int row = getIntInput("position (col to insert): ");
            table->copyInsertColumn(col, row);
            table->printTable();
            continue;
        }

        if (option == 4)
        {
            int col = getIntInput("position (col): ");
            table->deleteColumn(col);
            table->printTable();
            continue;
        }

        if (option == 5)
        {
            cout << "Exit program." << endl;
            break;
        }

        cout << "Invalid input. Please try again." << endl;
        cout << endl;
    }

    delete table;
}

int main()
{

    string menu = "Options:\n1. Create Column\n2. Create Table\n\nOption: ";
    int option = getIntInput(menu);

    if (option == 1)
    {
        testCol();
    }
    else if (option == 2)
    {
        testTable();
    }
    else
    {
        cout << "Invalid input. Exit program." << endl;
    }

    return 0;
}