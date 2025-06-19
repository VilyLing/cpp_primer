#include "exercise_10_2_3.h"
#include "exercise_10_3_1.h"

#include <algorithm>
#include <iostream>

bool isShorter(const std::string& s1, const std::string& s2) {
    return s1.size() < s2.size();
}

void practice10_11(){
    std::vector<std::string> vec = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(vec);
    std::stable_sort(vec.begin(), vec.end(), isShorter);

    // 输出去重后的结果
    for (const auto& s : vec) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}
