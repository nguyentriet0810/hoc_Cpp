#include <iostream>
#include <vector>
#include <string>

std::string name = "Test1";

char dummy = [](){
    std::cout << "Static initialization in test1.cpp\n";
    return 0;
}();

int main()
{
    std::cout << "Hello, wold! " << name << '\n';
    return 0;
}
