#include "exercise_10_2_3.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

void elimDups(std::vector<std::string>& words) {
    std::sort(words.begin(), words.end());// 排序

    auto end_unique = std::unique(words.begin(), words.end()); // 删除重复元素
    words.erase(end_unique, words.end()); // 移除多余的元素
}

void practice10_9() {
   std::vector<std::string> vec = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
   elimDups(vec);
   for (const auto& s : vec) {
       std::cout << s << " ";
   }
   std::cout << std::endl;
}
