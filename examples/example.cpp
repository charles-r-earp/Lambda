

#include <lambda>


#include <string>
#include <iostream>
#include <sstream>

// Select naming convention
// Lambda and lambda will not clash, but typically only one will be used
// a using declaration isn't required, it's simply convenient for local code 

#define LOWER_CASE 1

#if LOWER_CASE
    using lambda::lambda;
#else
    using lambda::Lambda;
#endif


struct thing {
     
#if LOWER_CASE
    lambda<std::string(int x)> func;
#else
    Lambda<std::string(int x)> func;
#endif
    
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