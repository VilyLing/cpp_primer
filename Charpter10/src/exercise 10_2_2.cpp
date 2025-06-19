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
    ��ʱivec��Ԫ������Ϊ0;
    ����Ҫʹ��resize()�������������С��
    ��������ȷ����ʹ��copy()����ʱ��ivec���㹻�Ŀռ����洢��lst���Ƶ�Ԫ�ء�
    a). vector<int> ivec;
        list<int> lst;
        int i;
        while (std::cin >> i) {
            lst.push_back(i);
        }
            copy(lst.begin(), lst.end(), ivec.begin());
    */
    //�޸ĵĴ���:
    std::vector<int> ivec;
    std::list<int> lst;
    int i;
    while (std::cin >> i) {
        lst.push_back(i);
    }
    ivec.resize(lst.size()); // ȷ��ivec���㹻�Ŀռ�
    std::copy(lst.begin(), lst.end(), ivec.begin());

    printContainer(ivec);
    //����ͨ�������������в���
    // std::copy(lst.begin(), lst.end(), std::back_inserter(ivec));

    /*
    ����ԭ��: reserverve()���������������������������ı����С��
    ��ˣ�ʹ��reserve()�����������Ĵ�С��ȻΪ0��
    b). vector<int> ivec;
        vec.reserve(10);
        fill_n(ivec.begin(), 10, 0);
    */
    //�޸ĵĴ���:
    std::vector<int>   vec;
    vec.resize(10);
    // fill_n(vec.begin(), 10, 0);
    //����ʹ�ò�����
    std::fill_n(std::back_inserter(vec), 10, 0);
    printContainer(vec);
}

void practice10_2_2() {
    //��ϰ10.6
    fill_vector();

    //��ϰ10.7
    alterProgram();

    //��ϰ10.8
    /*
    ��׼���㷨 ��ͨ����������������Ԫ�صġ�
    �����������ڳ���㣬���ṩ������Ԫ�صķ��ʷ�ʽ��
    ��ˣ���׼���㷨�������κ��ṩ������������һ��ʹ�á�
    ���Ա�׼���㷨������vector��list��deque������һ��ʹ�á�
    ʵ����2���ؼ�Ŀ��
    1. �ṩ��һ��ͨ�õĽӿڣ������㷨�벻ͬ���͵�����һ������
    2. �����㷨�벻ͬ���͵ĵ�����һ�������Ӷ�֧�ֲ�ͬ���������͡�
    */
}