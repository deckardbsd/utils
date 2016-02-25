#include <iostream>

int main()
{
    unsigned int total = 22;

    [&](unsigned int m) { total += m; } (33);

    std::cout << total << std::endl;
    
    return 0;
}
