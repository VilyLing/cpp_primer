#pragma once

// 练习10.26 解释三种迭代器的区别

/*
 1. back_insert : 一个使用push_back()的迭代器 往容器尾部添加元素
 2. front_insert : 一个使用push_front()的迭代器 往容器首元素之前添加元素
 使其成为首元素
 3. insert : 一个使用insert()的迭代器 接受2个参数会向第二个参数的迭代器添加元素
*/

// 练习 10.27
#include <algorithm>
#include <deque>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <list>
#include <ostream>
#include <string>
#include <vector>
void practice10_22(std::vector<std::string> &svec) {
  // 原本的容器内元素
  std::cout << "原容器的元素: ";
  for (auto &s : svec)
    std::cout << s << " ";
  std::cout << std::endl;

  std::list<std::string> lst;
  std::unique_copy(svec.begin(), svec.end(), std::inserter(lst, lst.begin()));
  std::cout << "复制后的容器元素： ";
  for (auto &s : lst)
    std::cout << s << " ";
  std::cout << std::endl;
}

void practice10_23() {
  std::vector<int> ivec;
  for (int i = 1; i < 10; ++i) {
    ivec.push_back(i);
  }

  std::list<int> lst;
  std::deque<int> deq;
  std::forward_list<int> fw_lst;


  // vector无法使用front_inserter
  // array和forward_list无法使用push_back
  std::copy(ivec.cbegin(), ivec.cend(), std::inserter(lst, lst.begin()));

  for (auto &s : lst) {
    std::cout << s << " ";
  }
  std::cout << std::endl;

  std::copy(ivec.cbegin(), ivec.cend(), std::front_inserter(fw_lst));
  for (auto &s : fw_lst) {
    std::cout << s << " ";
  }
  std::cout << std::endl;
  std::copy(ivec.cbegin(), ivec.cend(), std::back_inserter(deq));
  for (auto &s : deq) {
    std::cout << s << " ";
  }
  std::cout << std::endl;
  std::cout << std::endl;
}