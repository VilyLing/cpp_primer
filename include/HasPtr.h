#pragma once

#include <ostream>
#include <string>
class HasPtr{
    public:
    friend std::ostream& print(std::ostream &os, const HasPtr &it);

    HasPtr(const std::string &s = std::string()):ps(new std::string(s)),i(0){}
    HasPtr(const HasPtr& origin):ps(new std::string(*origin.ps)),i(origin.i){}

    ~HasPtr(){
        delete ps;
    }
    private:
        std::string *ps;
        int i;
};

std::ostream& print(std::ostream& os ,const HasPtr& it){
    os << it.ps << std::endl;
    return os;
}