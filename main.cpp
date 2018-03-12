#include <iostream>

#include "MyList.h"

int main()
{
    myList<int> defaultConst;
    myList<int> copyConst(defaultConst);
    myList<int> argConst(3, 15);
    return 0;
}
