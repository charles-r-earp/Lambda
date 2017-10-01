#include <lambda/lambda.hpp>

#include <string>
#include <iostream>
#include <sstream>

struct thing {
    lambda::lambda<std::string(int x)> func; 
};

int main() {
    
    thing thing1 { { [](int u) -> std::string {
        std::stringstream ss;
        ss << "u = " << u << std::endl;
        return ss.str();
    }} };
    
    std::cout << thing1.func(5);
    
    return 0;
}