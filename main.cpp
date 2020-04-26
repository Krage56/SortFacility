#include <iostream>
#include "SortStation.h"
using namespace std;
#define mem_block 1024
int main() {
    char buff[mem_block];
    cin.getline(buff, mem_block - 1);
    string input(buff);
    SortStation first(input);
    cout << first.getResult() << endl;
    return 0;
}