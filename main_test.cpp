#include <iostream>
#include <string>
#include "Column.h"
#include "Table.h"

using namespace std;


string getStringInput(const string& msg = {}){
    string input = "";
    cout << msg;
    cin >> input;
    return input;
}

int getIntInput(const string& msg = {}){
    int input;
    cout << msg;
    cin >> input;

    if (cin.fail() || input<0){
        cin.clear();
        cin.ignore(1000, '\n');
        return getIntInput(msg);
    }

    return input;
}

void testCases(int option){
    
    if (option == 1){
        Column* col = new Column;
        col->modifyCell(0, "a"); cout<< "modifyCell(0, \"a\")"<< endl;
        col->modifyCell(3, "b"); cout<< "modifyCell(3, \"b\")"<< endl;
        col->modifyCell(2, "b"); cout<< "modifyCell(2, \"b\")"<< endl;
        col->modifyCell(3, "a"); cout<< "modifyCell(3, \"a\")"<< endl;
        col->printColumn();
        delete col; return;
    }


    if (option == 2){
        Column* col = new Column;
        col->modifyCell(2, "a"); cout << "modifyCell(2, \"a\")" << endl;
        col->modifyCell(1, "x"); cout << "modifyCell(1, \"x\")" << endl;
        col->modifyCell(3, "b"); cout << "modifyCell(3, \"b\")" << endl;
        col->clearCell(1); cout << "clearCell(1)" << endl;
        col->clearCell(2); cout << "clearCell(2)" << endl;
        col->printColumn();
        delete col; return;
    }

    if (option == 3){
        Column* col = new Column;
        col->modifyCell(2, "a"); cout << "modifyCell(2, \"a\")" << endl;
        col->modifyCell(1, "x"); cout << "modifyCell(1, \"x\")" << endl;
        col->modifyCell(3, "b"); cout << "modifyCell(3, \"b\")" << endl;
        col->clearCell(3); cout << "clearCell(3)" << endl;
        col->clearCell(1); cout << "clearCell(1)" << endl;
        col->printColumn();
        delete col; return;
    }


    if (option == 4){
        Column* col = new Column;
        col->modifyCell(0, "a"); cout << "modifyCell(0, \"a\")" << endl;
        col->modifyCell(1, "b"); cout << "modifyCell(1, \"b\")" << endl;
        col->clearAllCells(); cout << "clearAllCells()" << endl;
        col->printColumn();
        delete col; return;
    }

    if (option ==5){
        Column* col = new Column;

        col->modifyCell(0, "a"); cout << "modifyCell(0, \"a\")" << endl;
        col->modifyCell(6, "b"); cout << "modifyCell(6, \"b\")" << endl;
        col->modifyCell(2, "c"); cout << "modifyCell(2, \"c\")" << endl;
        col->modifyCell(3, "d"); cout << "modifyCell(3, \"d\")" << endl;

        Column* col2 = new Column(*col); 
        col2->modifyCell(0, "x"); cout << "copied: modifyCell(0, \"x\")" << endl;
        col->clearCell(6); cout << "original: clearCell(6)" << endl;

        cout<<"original: \n"<<endl;
        col->printColumn();
        cout<<"copied: \n"<<endl;
        col2->printColumn();
        delete col; delete col2; return;
    }

    if (option == 6){
        Column* col = new Column;
        col->modifyCell(0, "a"); cout << "modifyCell(0, \"a\")" << endl;
        col->modifyCell(6, "b"); cout << "modifyCell(6, \"b\")" << endl;
        col->modifyCell(2, "c"); cout << "modifyCell(2, \"c\")" << endl;
        col->modifyCell(3, "d"); cout << "modifyCell(3, \"d\")" << endl;
        col->printColumn();
        Cell* cell = col->findCell(6); cout << "findCell(6): " << endl;
        if (cell != nullptr) cout << cell->value << endl; else cout << "nullptr" << endl;
        cell = col->findCell(0); cout << "findCell(0): " << endl;
        if (cell != nullptr) cout << cell->value << endl; else cout << "nullptr" << endl;        
        delete col; return;
    }

    if (option == 7){
        Table* table = new Table;
        table->modifyCell(4, 2, "a"); cout << "modifyCell(4, 2, \"a\")" << endl;
        table->modifyCell(0, 0, "a"); cout << "modifyCell(0, 0, \"a\")" << endl;
        table->printTable();
        delete table; return;
    }

    if (option == 8){
        Table* table = new Table;
        table->modifyCell(3, 2, "a"); cout << "modifyCell(3, 2, \"a\")" << endl;
        table->modifyCell(2, 4, "b"); cout << "modifyCell(2, 4, \"b\")" << endl;
        table->modifyCell(3, 4, "c"); cout << "modifyCell(3, 4, \"c\")" << endl;
        table->modifyCell(0, 0, "d"); cout << "modifyCell(0, 0, \"d\")" << endl;
        table->printTable();
        delete table; return;
    }

    if (option == 9 ){
        Table *table = new Table;
        table->modifyCell(1, 0, "b"); cout << "modifyCell(1, 0, \"b\")" << endl;
        table->modifyCell(3, 4, "c"); cout << "modifyCell(3, 4, \"c\")" << endl;
        table->modifyCell(3, 0, "d"); cout << "modifyCell(3, 0, \"d\")" << endl;
        table->modifyCell(2, 2, "e"); cout << "modifyCell(2, 2, \"e\")" << endl;
        table->printTable();

        table->clearCell(4, 4); cout << "clearCell(4, 4)" << endl;
        table->clearCell(0, 0); cout << "clearCell(0, 0)" << endl;
        table->clearCell(3, 0); cout << "clearCell(3, 0)" << endl;
        table->clearCell(2, 3); cout << "clearCell(2, 3)" << endl;
        table->printTable();
        delete table; return;
    }

    if (option == 10){
        Table *table = new Table;
        table->modifyCell(1, 0, "b"); cout << "modifyCell(1, 0, \"b\")" << endl;
        table->modifyCell(3, 4, "c"); cout << "modifyCell(3, 4, \"c\")" << endl;
        table->modifyCell(3, 2, "d"); cout << "modifyCell(3, 2, \"d\")" << endl;
        table->clearCell(3, 4); cout << "clearCell(3, 4)" << endl;
        table->printTable();
        table->clearCell(3, 2); cout << "clearCell(3, 2)" << endl;
        table->printTable();
        table->clearCell(1, 0); cout << "clearCell(1, 0)" << endl;
        table->printTable();
        delete table; return;
    }

    if (option == 11){
        Table *table = new Table;
        table->modifyCell(0, 6, "b"); cout << "modifyCell(0, 6, \"b\")" << endl;
        table->modifyCell(0, 3, "c"); cout << "modifyCell(0, 3, \"c\")" << endl;
        table->modifyCell(0, 2, "d"); cout << "modifyCell(0, 2, \"d\")" << endl;
        table->clearCell(0, 3); cout << "clearCell(0, 3)" << endl;
        table->printTable();
        table->clearCell(0, 6); cout << "clearCell(0, 6)" << endl;
        table->printTable();
        table->modifyCell(0, 0, "x"); cout << "modifyCell(0, 0, \"x\")" << endl;
        table->clearCell(0, 2); cout << "clearCell(0, 2)" << endl;
        table->printTable();
        table->clearCell(0, 0); cout << "clearCell(0, 0)" << endl;
        table->printTable();

        delete table; return;
    }


    if (option == 12){
        Table* table = new Table;
        table->modifyCell(1, 4, "n"); cout << "modifyCell(1, 4, \"n\")" << endl;
        table->modifyCell(3, 0, "o"); cout << "modifyCell(3, 0, \"o\")" << endl;
        table->modifyCell(2, 3, "p"); cout << "modifyCell(2, 3, \"p\")" << endl;
        table->modifyCell(0, 1, "q"); cout << "modifyCell(0, 1, \"q\")" << endl;
        table->modifyCell(1, 0, "r"); cout << "modifyCell(1, 0, \"r\")" << endl;
        table->modifyCell(3, 3, "s"); cout << "modifyCell(3, 3, \"s\")" << endl;
        table->modifyCell(2, 2, "t"); cout << "modifyCell(2, 2, \"t\")" << endl;
        table->printTable();

        Cell* cell = table->findCell(1, 4); cout << "findCell(1, 4)" << endl;
        if (cell != nullptr) cout << cell->value << endl; else cout << "nullptr" << endl;
        cell = table->findCell(3, 3); cout << "findCell(3, 3)" << endl;
        if (cell != nullptr) cout << cell->value << endl; else cout << "nullptr" << endl;
        delete table; return;
    }

    if (option == 13){
        Table* table = new Table;
        table->modifyCell(2, 2, "a"); cout << "modifyCell(2, 2, \"a\")" << endl;
        table->modifyCell(3, 4, "b"); cout << "modifyCell(3, 4, \"b\")" << endl;
        table->copyInsertColumn(2, 0); cout << "copyInsertColumn(2, 0)" << endl;
        table->printTable();
        table->copyInsertColumn(3, 1); cout << "copyInsertColumn(3, 1)" << endl;
        table->copyInsertColumn(3, 1); cout << "copyInsertColumn(3, 1)" << endl;
        table->printTable();
        delete table; return;
    }

    if (option == 14){
        Table* table = new Table;
        table->modifyCell(2, 2, "a"); cout << "modifyCell(2, 2, \"a\")" << endl;
        table->modifyCell(3, 4, "b"); cout << "modifyCell(3, 4, \"b\")" << endl;
        table->copyInsertColumn(2, 3); cout << "copyInsertColumn(2, 3)" << endl;
        table->printTable();
        table->copyInsertColumn(3, 6); cout << "copyInsertColumn(3, 6)" << endl;
        table->printTable();
        table->copyInsertColumn(3, 1); cout << "copyInsertColumn(3, 1)" << endl;
        table->printTable();
        table->copyInsertColumn(0, 8); cout << "copyInsertColumn(0, 8)" << endl;
        table->printTable();
        delete table; return;
    }

    if (option == 15 ){
        Table* table = new Table;
        table->modifyCell(2, 0, "a"); cout << "modifyCell(2, 0, \"a\")" << endl;
        table->modifyCell(3, 2, "b"); cout << "modifyCell(3, 2, \"b\")" << endl;
        table->modifyCell(5, 2, "b"); cout << "modifyCell(5, 2, \"b\")" << endl;
        table->printTable();

        table->deleteColumn(5); cout << "deleteColumn(5)" << endl;
        table->printTable();
        table->deleteColumn(3); cout << "deleteColumn(3)" << endl;
        table->printTable();
        delete table; return;
    }

    if (option == 16 ){
        Table* table = new Table;
        table->modifyCell(1, 0, "a"); cout << "modifyCell(1, 0, \"a\")" << endl;
        table->modifyCell(3, 4, "b"); cout << "modifyCell(3, 4, \"b\")" << endl;
        table->deleteColumn(4); cout << "deleteColumn(4)" << endl;
        table->deleteColumn(2); cout << "deleteColumn(2)" << endl;
        table->printTable();
        delete table; return;
    }

    if (option == 17){
        
        Table* table = new Table;
        table->modifyCell(0, 0, "a"); cout << "modifyCell(0, 0, \"a\")" << endl;
        table->modifyCell(1, 2, "b"); cout << "modifyCell(1, 2, \"b\")" << endl;
        table->modifyCell(3, 1, "c"); cout << "modifyCell(3, 1, \"c\")" << endl;
        table->modifyCell(2, 4, "d"); cout << "modifyCell(2, 4, \"d\")" << endl;
        table->modifyCell(0, 3, "e"); cout << "modifyCell(0, 3, \"e\")" << endl;
        table->modifyCell(1, 1, "f"); cout << "modifyCell(1, 1, \"f\")" << endl;
        table->modifyCell(3, 2, "g"); cout << "modifyCell(3, 2, \"g\")" << endl;
        table->printTable();

        Column* col = table->findColumn(0); cout << "findColumn(0)" << endl;
        if (col != nullptr) col->printColumn(); else cout << "nullptr" << endl;

        col = table->findColumn(3); cout << "findColumn(3)" << endl;
        if (col != nullptr) col->printColumn(); else cout << "nullptr" << endl;
        delete table; return;

    }

    if (option == 18){
        Table* table = new Table;

        table->modifyCell(0, 0, "a"); cout << "modifyCell(0, 0, \"a\")" << endl;
        table->modifyCell(5,2 , "b"); cout << "modifyCell(5,2 , \"b\")" << endl;
        table->copyInsertColumn(2, 0); cout << "copyInsertColumn(2, 0)" << endl;
        table->printTable();
        table->clearCell(1, 2); cout << "clearCell(1, 2)" << endl;
        table->copyInsertColumn(3, 1); cout << "copyInsertColumn(3, 1)" << endl;
        table->copyInsertColumn(1000, 4); cout << "copyInsertColumn(1000, 4)" << endl;
        table->clearCell(8, 2); cout << "clearCell(8, 2)" << endl;
        table->printTable();
        table->copyInsertColumn(1, 3); cout << "copyInsertColumn(1, 3)" << endl;
        table->copyInsertColumn(7, 2); cout << "copyInsertColumn(7, 2)" << endl;
        table->modifyCell(1, 0, "a"); cout << "modifyCell(1, 0, \"a\")" << endl;
        table->modifyCell(1, 3, "a"); cout << "modifyCell(1, 3, \"a\")" << endl;
        table->modifyCell(1,2 , "b"); cout << "modifyCell(1, 2, \"b\")" << endl;
        table->clearCell(1, 0); cout << "clearCell(1, 0)" << endl;
        table->printTable();
        table->copyInsertColumn(2, 1); cout << "copyInsertColumn(2, 1)" << endl;
        table->clearCell(4, 0); cout << "clearCell(4, 0)" << endl;
        table->printTable();
        table->copyInsertColumn(3, 4); cout << "copyInsertColumn(3, 4)" << endl;
        table->copyInsertColumn(9, 1); cout << "copyInsertColumn(9, 1)" << endl;
        table->copyInsertColumn(1, 4); cout << "copyInsertColumn(1, 4)" << endl;    
        table->clearCell(3, 3); cout << "clearCell(3, 3)" << endl;
        table->clearCell(3, 2); cout << "clearCell(3, 2)" << endl;
        table->printTable();
        table->copyInsertColumn(2, 2); cout << "copyInsertColumn(2, 2)" << endl;
        table->printTable();
        delete table; return;
    }

    if (option == 19){
        Table* table = new Table;
        table->modifyCell(0, 0, "a"); cout << "modifyCell(0, 0, \"a\")" << endl;
        table->copyInsertColumn(0, 1); cout << "copyInsertColumn(0, 1)" << endl;
        table->clearCell(0, 0); cout << "clearCell(0, 0)" << endl;
        table->printTable();

        table->copyInsertColumn(0, 2); cout << "copyInsertColumn(0, 2)" << endl;
        table->printTable();

        table->copyInsertColumn(1, 2); cout << "copyInsertColumn(1, 2)" << endl;
        table->modifyCell(4, 0, "b"); cout << "modifyCell(4, 0, \"b\")" << endl;
        table->modifyCell(4, 3, "b"); cout << "modifyCell(4, 3, \"b\")" << endl;
        table->printTable();

        table->clearCell(4, 3); cout << "clearCell(4, 3)" << endl;
        table->copyInsertColumn(3, 0); cout << "copyInsertColumn(3, 0)" << endl;
        table->printTable();

        table->clearCell(5,0); cout << "clearCell(5,0)" << endl;
        table->printTable();
        table->deleteColumn(0); cout << "deleteColumn(0)" << endl;
        table->deleteColumn(2); cout << "deleteColumn(2)" << endl;
        table->printTable();

        table->clearCell(1,0); cout << "clearCell(1,0)" << endl;
        table->printTable();

        delete table; return;
    }
    
    if (option == 20){
        Table* table = new Table;
        table->modifyCell(3, 3, "b"); cout << "modifyCell(3, 3, \"b\")" << endl;
        table->modifyCell(4, 2, "c"); cout << "modifyCell(4, 2, \"c\")" << endl;
        table->printTable();
        table->deleteColumn(4); cout << "deleteColumn(4)" << endl;
        table->deleteColumn(2); cout << "deleteColumn(2)" << endl;
        table->printTable();
        table->deleteColumn(0); cout << "deleteColumn(0)" << endl;
        table->copyInsertColumn(0, 0); cout << "copyInsertColumn(0, 0)" << endl;
        table->modifyCell(0, 0, "a"); cout << "modifyCell(0, 0, \"a\")" << endl;
        table->deleteColumn(4); cout << "deleteColumn(4)" << endl;
        table->printTable();
        table->modifyCell(2, 5, "h"); cout << "modifyCell(2, 5, \"h\")" << endl;
        table->copyInsertColumn(4, 0); cout << "copyInsertColumn(4, 0)" << endl;
        table->modifyCell(3, 0, "i"); cout << "modifyCell(3, 0, \"i\")" << endl;
        table->printTable();
        table->modifyCell(0, 3, "s"); cout << "modifyCell(0, 3, \"s\")" << endl;
        table->printTable();
        table->clearCell(2, 4); cout << "clearCell(2, 4)" << endl;
        table->printTable();
        table->clearCell(3, 0); cout << "clearCell(3, 0)" << endl;
        table->clearCell(2, 5); cout << "clearCell(2, 5)" << endl;
        table->printTable();
        table->deleteColumn(1); cout << "deleteColumn(1)" << endl;
        table->printTable();
        delete table; return;
    }

    if (option >20){
        cout << "The test case is private." << endl;
        return;
    }

}

int main(){

    int option = getIntInput("Enter ZINC test case id ( <=20 ): ");
    testCases(option);
    
    return 0;
}