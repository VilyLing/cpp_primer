#pragma once

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <ostream>
#include <vector>

void reversePrint(){
    std::vector<int> ivec = {1,2,3,4,5,6,7,8,9};
    
    // std::reverse_iterator<std::vector<int>::iterator> rever_iter(ivec.end());
    // while (rever_iter != ivec.rend()) {
    //     std::cout << * rever_iter << std::endl;
    //     ++rever_iter;
    // }

    // auto it = ivec.crbegin();
    // while (it != ivec.crend()) {
    //     std::cout << *it << std::endl;
    //     ++it;
    // }
    
    for (auto it = std::prev(ivec.cbegin()); it != std::prev(ivec.cend()); --it) {
        std::cout << *it << std::endl;
    }
}

void findInList(){
    std::list<int> lst = {1,0,6,9,8,5,6,3,5,0};

    std::list<int>::iterator it;

    auto beg = lst.begin();
    while (beg != lst.end()) {
        if (*beg == 0) {
            it = beg;
        }
        ++beg;
    }
    
    std::cout << "The final appear 0 the distance is " << std::distance(lst.begin(), it) << std::endl;



    // auto rit = std::find(lst.rbegin(), lst.rend(), 0);

    // if (rit != lst.rend()) {
    //     auto it = rit.base();
    //     std::cout << "The final appear 0 the distance is " << std::distance(lst.begin(), it) << std::endl;
    // }else {
    //     std::cout << "The list is not appera 0." << std::endl;
    // }
}

void copyVectorNum(std::vector<int> &ivec){


    std::list<int> lst;

    std::copy(ivec.crbegin()+3,ivec.crbegin()+7,std::back_inserter(lst));
    
    auto it = lst.cbegin();
    while (it != lst.cend()) {
        std::cout << *it++ << std::endl;
    }
    
}