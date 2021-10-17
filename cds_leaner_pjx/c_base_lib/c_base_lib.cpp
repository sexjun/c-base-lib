extern "C" {
    #include "../../src/list.h"
}

#include <iostream>

typedef struct {
    char* name;
    int age;
    int sex;
}Persion;

typedef ListEntry PersionItem;
typedef ListIterator PersionItor;
typedef ListValue Persion;


int main()
{
    PersionItem a = { 0 };
    std::cout << "Hello World!\n";
}