#pragma once

#include <iostream>
class Y;

class X{
    private:
        Y *ptr;
};

class Y{
    private:
    X obj;
};

class NoDefault{
    public:
        NoDefault(int a):data(a){}
        void print(){std::cout << data << std::endl;}
    private:
        int data;
};

class C{
    public:
        C():nd(0){} 
        void print(){nd.print();}
    private:
        NoDefault nd;
};