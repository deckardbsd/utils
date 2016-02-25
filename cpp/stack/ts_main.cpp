#include <iostream>
#include <string>
#include "ts_stack.hpp"


int main()
{
    // on za-stack ;)
    ts_stack<std::string> pile;

    // on za-heap
    // ts_stack<std::string> *pl = new ts_stack<std::string>();
    
    pile.push("Amalia");
    pile.push("Sabin");
    pile.push("Andrei");
    pile.push("Miranda");
    pile.push("Clatite");


    std::cout << "Last elem: " << pile.pop() << std::endl;

    
    return 0;
}
