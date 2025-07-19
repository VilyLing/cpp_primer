
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
    // 创建一个Point对象p1，坐标为(1, 2)
    Point p1(1, 2);
    // 调用foo_bar函数，传入p1对象
    foo_bar(p1);
    // 等待用户输入，防止程序立即退出

    // HasPtr hp1("Hello");
    // HasPtr hp2(hp1);

    // print(std::cout, hp1);
    // print(std::cout, hp2);


    std::cin.get();
}