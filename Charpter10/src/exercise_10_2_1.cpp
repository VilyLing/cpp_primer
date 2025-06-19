#include "exercise_10_2_1.h"
#include <iostream>
#include <list>
#include <numeric>
#include <vector>
#include <algorithm>

int exercise_10_3(std::vector<int> ivec) {
  auto sum = std::accumulate(ivec.cbegin(), ivec.cend(), 0);
  std::cout << "The sum of the vector is: " << sum << std::endl;
  return sum;
}

/*
�ᶪʧС������
�����Ҫ����С�����֣����Խ���ʼֵ��Ϊ0.0
*/
void exercise_10_4(std::vector<double> dvec) {
  std::cout << "Calculating sum of doubles...error version: " << std::endl;
  auto sum = std::accumulate(dvec.cbegin(), dvec.cend(), 0);
  std::cout << "The sum of the vector is: " << sum << std::endl;
  std::cout << "Calculating sum of doubles...correct version: " << std::endl;
  auto correct_sum = std::accumulate(dvec.cbegin(), dvec.cend(), 0.0);
  std::cout << "The sum of the vector is: " << correct_sum << std::endl;
}

/*
cont char* ���͵��ַ�������ֱ��ʹ�� std::equal ���бȽ�
���ǲ���ʹ�õ���������Ҫ��ָ��
������һ�����ɱ����������
������˵�Ǵ洢��������ͬ���ڴ��ַ
����� std::string ���͵��ַ�������ֱ��ʹ�� std::equal ���бȽ�
����� std::vector<char const *> ���͵��ַ���Ҳ����ֱ��ʹ�� std::equal ���бȽ�
*/
void exercise_10_5() {
  char const *roster1 = "John,Paul,George,Ringo";
  char const *roster2 = "John,Paul,George,Ringo";
  auto result = std::equal(roster1, roster1 + 24, roster2);
  if (result) {
    std::cout << "The two rosters are equal." << std::endl;
  } else {
    std::cout << "The two rosters are not equal." << std::endl;
  }

  std::vector<char const *> vec_roster1 = {"John", "Paul", "George", "Ringo"};
  std::vector<char const *> vec_roster2 = {"John", "Paul", "George", "Ringo"};
  auto vec_result = std::equal(vec_roster1.cbegin(), vec_roster1.cend(), vec_roster2.cbegin());
  std::cout << vec_result << std::endl;
  if (vec_result) {
    std::cout << "The two vectors are equal." << std::endl;
  } else {
    std::cout << "The two vectors are not equal." << std::endl;
  }
}

void practive_10_2_1() {
  // std::vector<int> ivec = {1, 2, 3, 4, 5};
  // std::vector<double> dvec = {1.1, 2.2, 3.3, 4.4, 5.5};
  std::vector<double> dvec = {0.1,0.2,0.3,0.4,0.5};

  // exercise_10_3(ivec);
  exercise_10_4(dvec);
  // exercise_10_5();
}
