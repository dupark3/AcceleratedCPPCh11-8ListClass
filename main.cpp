#include <iostream>

#include "MyList.h"

int main()
{
    myList<int> defaultConst;
    /*myList<int> copyConst(defaultConst);
    myList<int> argConst(3, 15);*/
    defaultConst.push_back(5);

    for (myList<int>::iterator i = defaultConst.begin(); i != defaultConst.end(); ++i){
        std::cout << *i << " ";
    }
    return 0;
}
