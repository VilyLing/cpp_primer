#pragma once

// ��ϰ10.26 �������ֵ�����������

/*
 1. back_insert : һ��ʹ��push_back()�ĵ����� ������β�����Ԫ��
 2. front_insert : һ��ʹ��push_front()�ĵ����� ��������Ԫ��֮ǰ���Ԫ��
 ʹ���Ϊ��Ԫ��
 3. insert : һ��ʹ��insert()�ĵ����� ����2����������ڶ��������ĵ��������Ԫ��
*/

// ��ϰ 10.27
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
  // ԭ����������Ԫ��
  std::cout << "ԭ������Ԫ��: ";
  for (auto &s : svec)
    std::cout << s << " ";
  std::cout << std::endl;

  std::list<std::string> lst;
  std::unique_copy(svec.begin(), svec.end(), std::inserter(lst, lst.begin()));
  std::cout << "���ƺ������Ԫ�أ� ";
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


  // vector�޷�ʹ��front_inserter
  // array��forward_list�޷�ʹ��push_back
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