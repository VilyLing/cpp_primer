#pragma once
#include <iostream>
#include <iterator>


void practive10_29(){
/*
    练习10.29
    if (argc != 2) {
     return -1;
    }
    std::ifstream fs(argv[1]);
    std::istream_iterator<std::string> item_iter(fs),efo;

    std::vector<std::string> svec;
    while (item_iter != efo) {
        svec.push_back(*item_iter++);
    }
    
    std::for_each(svec.cbegin(), svec.cend(),[](std::string const &ss){
        std::cout << ss << " ";
    });

    //记得关闭文件流
    if (fs.is_open()) {
        fs.clear();
        fs.close();
    }
*/
}

void practive10_30(){
     std::istream_iterator<int> in_iter(std::cin) , in_efo;

    std::vector<int> ivec_before,ivec_after;
    //将数据写入 ivec_before
    while (in_iter != in_efo) {
        ivec_before.push_back(*in_iter++);
    }

    //从低到高排序
    std::sort(ivec_before.begin(),ivec_before.end(),[](int i, int j){
        return  i <= j;
    });

    // std::copy(ivec_before.cbegin(),ivec_before.cend(), std::back_inserter(ivec_after));

    std::unique_copy(ivec_before.cbegin(),ivec_before.cend(),std::inserter(ivec_after, ivec_after.begin()));

    std::for_each(ivec_after.cbegin(), ivec_after.cend(), [](int i){
        std::cout << i << " ";
    });

    std::cout << std::endl;
}