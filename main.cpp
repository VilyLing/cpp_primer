
#include "Point.h"
#include "include/HasPtr.h"
#include <iostream>

Point global(3,5);

Point foo_bar(Point p) {
    Point local = p , *heap = new Point(global); // heap = &local;
    *heap = local;
    // Point pa[4] = {local, *heap};   
    return *heap;
}

int main() {
    // ����һ��Point����p1������Ϊ(1, 2)
    Point p1(1, 2);
    // ����foo_bar����������p1����
    foo_bar(p1);
    // �ȴ��û����룬��ֹ���������˳�

    // HasPtr hp1("Hello");
    // HasPtr hp2(hp1);

    // print(std::cout, hp1);
    // print(std::cout, hp2);


    std::cin.get();
}