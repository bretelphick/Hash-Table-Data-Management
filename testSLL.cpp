#include <iostream>
#include "SLL.h"

using namespace std;

int main(int argc, char* argv[]){
    SLL<int> list;

    list.insert(10, 10);
    list.insert(20, 20);
    list.insert(30, 30);
    list.insert(40, 40);
    list.insert(50, 50);

    list.display();
    cout << list.getSize() << endl;

    cout << endl << list.search(30) << endl << endl;

    list.remove(10);
    list.remove(30);
    list.remove(50);

    list.display();
    cout << list.getSize() << endl;
    cout << endl;
    
    return 0;
}