#include "exercise_10_1.h"


void exercise_10_1() {
    // This function is intentionally left empty.
    // The implementation should be provided in the corresponding header file.

    std::vector<int> ivec = {1,9,1,9,5,2,3,4,5,6,7,8,9,0};

    std::cout << std::count(ivec.cbegin(), ivec.cend(), 9) << std::endl;
    
    std::list<std::string> slist = {"hello", "world", "hello", "c++"};
    std::cout << std::count(slist.cbegin(), slist.cend(), "hello") << std::endl;
}