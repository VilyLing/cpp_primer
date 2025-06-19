#include "exercise_10_2_2.h"
#include <algorithm>
#include <iterator>
#include <list>
#include <vector>
#include <iostream>

void printContainer(const std::vector<int>& ivec) {
    for (const auto& i : ivec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void fill_vector(){
    std::vector<int> ivec;
    ivec.resize(10);
    std::fill_n(ivec.begin(), 10, 0);
    printContainer(ivec);
}

void alterProgram() {
    /*
    此时ivec的元素容量为0;
    所以要使用resize()函数来调整其大小。
    这样可以确保在使用copy()函数时，ivec有足够的空间来存储从lst复制的元素。
    a). vector<int> ivec;
        list<int> lst;
        int i;
        while (std::cin >> i) {
            lst.push_back(i);
        }
            copy(lst.begin(), lst.end(), ivec.begin());
    */
    //修改的代码:
    std::vector<int> ivec;
    std::list<int> lst;
    int i;
    while (std::cin >> i) {
        lst.push_back(i);
    }
    ivec.resize(lst.size()); // 确保ivec有足够的空间
    std::copy(lst.begin(), lst.end(), ivec.begin());

    printContainer(ivec);
    //或者通过插入器来进行插入
    // std::copy(lst.begin(), lst.end(), std::back_inserter(ivec));

    /*
    错误原因: reserverve()函数仅调整容器的容量，而不改变其大小。
    因此，使用reserve()函数后，容器的大小仍然为0。
    b). vector<int> ivec;
        vec.reserve(10);
        fill_n(ivec.begin(), 10, 0);
    */
    //修改的代码:
    std::vector<int>   vec;
    vec.resize(10);
    // fill_n(vec.begin(), 10, 0);
    //或者使用插入器
    std::fill_n(std::back_inserter(vec), 10, 0);
    printContainer(vec);
}

void practice10_2_2() {
    //练习10.6
    fill_vector();

    //练习10.7
    alterProgram();

    //练习10.8
    /*
    标准库算法 是通过迭代器操作容器元素的。
    而迭代器属于抽象层，仅提供对容器元素的访问方式。
    因此，标准库算法可以与任何提供迭代器的容器一起使用。
    所以标准库算法可以与vector、list、deque等容器一起使用。
    实现了2个关键目标
    1. 提供了一个通用的接口，允许算法与不同类型的容器一起工作。
    2. 允许算法与不同类型的迭代器一起工作，从而支持不同的容器类型。
    */
}