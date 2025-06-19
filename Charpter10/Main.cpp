#include "exercise_10_2_3.h"
#include "exercise_10_4_1.h"
#include "exercise_10_4_3.h"
#include "exercise_10_5_1.h"
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <ostream>
#include <string>
#include <vector>


bool strLengthCompare(const std::string &s1) { return s1.size() >= 5; }

void printWords(std::vector<std::string> &words, std::ostream &os = std::cout,
                char c = ' ') {
  // 输出words中的所有字符串
  for (const auto &word : words) {
    os << word << c;
  }
  os << std::endl;
}
bool check_size(std::string const &s, std::vector<std::string>::size_type sz) {
  return s.size() >= sz;
}

std::string make_plural(std::vector<std::string>::size_type ctr,
                        const std::string &word, const std::string &ending) {
  return (ctr > 1) ? word + ending : word;
}

void biggies(std::vector<std::string> &words,
             std::vector<std::string>::size_type sz) {
  // 按照字符串长度进行分区
  elimDups(words);
  // 按照字符串长度进行排序
  // 使用lambda表达式进行排序
  std::stable_sort(words.begin(), words.end(),
                   [](std::string const &s1, std::string const &s2) {
                     return s1.size() < s2.size();
                   });

  auto wc = std::find_if(words.begin(), words.end(),
                         [sz](std::string const &s) { return s.size() >= sz; });

  auto count = words.end() - wc; // 计算大于等于5个字符的字符串数量
  std::cout << count << " " << make_plural(count, "word", "s") << " of length "
            << sz << " or longer" << std::endl;
  // 输出大于等于5个字符的字符串
  std::for_each(wc, words.end(),
                [](const std::string &s) { std::cout << s << " "; });
  std::cout << std::endl;
}

// 重写我的biggies函数
void my_biggies(std::vector<std::string> &words,
                std::vector<std::string>::size_type sz) {
  // 首先对words进行去重和排序
  std::sort(words.begin(), words.end());
  // 使用end_unique来排列重复元素
  auto end_unique = std::unique(words.begin(), words.end());
  // 删除重复元素
  words.erase(end_unique, words.end());

  // 按照字符串长度进行排序
  std::stable_sort(words.begin(), words.end(),
                   [](std::string const &s1, std::string const &s2) {
                     return s1.size() < s2.size();
                   });

  printWords(words);
  // 使用捕获 查找第一个大于等于sz的字符串
  // auto wc = std::find_if(words.begin(), words.end(), [sz](std::string const
  // &s){
  //     return s.size() >= sz;
  // });

  // 使用partition来分区
  //  auto pack = std::partition(words.begin(), words.end(), [sz](const
  //  std::string &s){
  //      return s.size() < sz;
  //  });

  // 练习10.25

  auto checkSizeWithSz = std::bind(check_size, std::placeholders::_1, 5);
  auto pack = std::partition(words.begin(), words.end(), checkSizeWithSz);

  // 计算大于等于sz的字符串数量
  //  auto count = words.end() - wc;

  // auto count = words.end() - pack;
  auto count = pack - words.begin();
  std::cout << count << " " << make_plural(count, "word", "s") << " of length "
            << sz << " or longer" << std::endl;
  // 输出大于等于sz的字符串
  // std::for_each(pack, words.end(), [](const std::string &s){
  //     std::cout << s << " ";
  // });
  std::for_each(words.begin(), pack,
                [](const std::string &s) { std::cout << s << " "; });
}

void use_stable_patition_biggies(std::vector<std::string> &words,
                                 std::vector<std::string>::size_type sz,
                                 std::ostream &os = std::cout, char c = ' ') {

  // 首先对words进行去重和排序
  std::sort(words.begin(), words.end());
  // 使用end_unique来排列重复元素
  auto end_unique = std::unique(words.begin(), words.end());
  // 删除重复元素
  words.erase(end_unique, words.end());
  // 按照字符串长度进行分组
  std::stable_sort(words.begin(), words.end(),
                   [](std::string const &s1, std::string const &s2) {
                     return s1.size() < s2.size();
                   });

  std::for_each(words.begin(), words.end(),
                [](const std::string &s) { std::cout << s << " "; });
  std::cout << std::endl;

  // 使用stable_partition来分区
  auto it = std::stable_partition(
      words.begin(), words.end(),
      [=](std::string const &s) { return s.size() < sz; });
  // 计算大于等于sz的字符串数量
  auto count = words.end() - it;
  std::cout << count << " " << ((count > 1) ? "words" : "word") << " of Length"
            << sz << " or Longer" << std::endl;

  std::for_each(it, words.end(),
                [&, c](std::string const &s) { os << s << c; });
  os << std::endl;
}

void countIfLen(std::vector<std::string> &words,
                std::vector<std::string>::size_type sz) {
  // 使用count_if来计算大于等于sz的字符串数量
  auto count =
      std::count_if(words.cbegin(), words.cend(),
                    [=](std::string const &s) { return s.size() > sz; });
  std::cout << count << " " << make_plural(count, "word", "s") << " of length "
            << sz << " or longer" << std::endl;
}

bool strLengthCompare(std::string const &lhs, std::string const &rhs) {
  return lhs.size() < rhs.size();
}

bool compareLength(const std::string &s,
                   std::vector<std::string>::size_type sz) {
  return s.size() >= sz;
}

std::ostream &print(std::ostream &os, std::string const &s, char c) {
  return os << s << c;
}

void aboutInserterIterator() {
  std::list<int> lst = {1, 2, 3, 4};
  std::list<int> lst1, lst2;
  std::copy(lst.cbegin(), lst.cend(), std::front_inserter(lst1));

  for (auto &i : lst1)
    std::cout << i << " ";
  std::cout << std::endl;

  std::copy(lst.cbegin(), lst.cend(), std::inserter(lst2, lst2.begin()));

  for (auto &i : lst2)
    std::cout << i << " ";
  std::cout << std::endl;
}

int main(int argc, char *argv[]) {

  // 练习10.42
  std::list<std::string> lst = {"the",  "quick", "red",  "fox", "jumps",
                                "over", "the",   "slow", "red", "turtle"};
    std::cout << "Before: ";
  for (auto &a : lst) {
    std::cout << a << " ";
  }
  std::cout << "\n";
std::cout << "After sort: ";
  lst.sort();
  for (auto &a : lst) {
    std::cout << a << " ";
  }
  std::cout << "\n";
  std::cout << "After sort comp: ";
  lst.sort([](std::string const &lhs, std::string const &rhs) {
    return lhs.size() < rhs.size();
  });
  for (auto &a : lst) {
    std::cout << a << " ";
  }
  std::cout << "\n";
  lst.unique();
  std::cout << "After unique: ";
  for (auto &a : lst) {
    std::cout << a << " ";
  }
  std::cout << "\n";
  // replace_test();

  // std::vector<int> ivec={1,2,3,4,5,6,7,8,9,};
  // reversePrint();
  // findInList();
  // copyVectorNum(ivec);

  // std::vector<std::string> words =
  // {"Apple","Banana","Banana","Cherry","Date","Elderberry","Fig","Grape","Honeydew"};
  // printWords(words);
  // practice10_22(words);

  // practice10_23();

  /*
   //练习10.33
   if (argc != 5) {
       std::cerr << "用法" << argv[0] << "输入文件 奇数文件 偶数文件"<<
   std::endl;

       return EXIT_FAILURE;
   }
   //打开输入文件流
   std::ifstream in(argv[2]);
   if (!in) {
       std::cerr << "无法打开文件流: " << argv[2] << std::endl;
       return EXIT_FAILURE;
   }
   std::istream_iterator<int> in_iter(in) , efo;
   std::ofstream odd_out(argv[3]),even_out(argv[4]);
   std::cout <<"绑定写入迭代器\n";
   if (!even_out || !odd_out) {
       std::cerr << "无法打开输出文件" << std::endl;
       return EXIT_FAILURE;
   }
   std::ostream_iterator<int> even_iter(even_out," ");
   std::ostream_iterator<int> odd_iter(odd_out, "\n");
   std::cout <<"绑定输出迭代器\n";
   std::for_each(in_iter, efo, [&](int n){
       // std::cout << "写入文件"<< "\n";
       *(n % 2 == 0 ? even_iter :odd_iter)++ = n;
       return EXIT_SUCCESS;
   });
   */

  // if (in.is_open()) {
  //     in.clear();
  //     in.close();
  // }
  // if (odd_out.is_open() || even_out.is_open()) {
  //     odd_out.clear();
  //     even_out.clear();
  //     odd_out.close();
  //     even_out.close();
  // }

  // //练习10.22
  // auto fun_10_22 = std::bind(check_size, std::placeholders::_1,6);

  // //练习10.23
  // /*
  // * bind至少包含1个参数
  // * 最大参数为 1+n
  // * 其中n为 调用函数的参数数量
  // */

  // // 练习10.24

  // std::vector<int> ivec = {1,5,6,2,3};
  // std::sort(ivec.begin(),ivec.end(),[](int &a, int &b){
  //     return a > b;
  // });
  // for(auto &a : ivec)
  //     std::cout << a << " ";
  // std::cout << std::endl;
  // std::string str = "Hello";
  // auto wc = std::find_if(ivec.begin(), ivec.end(),
  // std::bind(check_size,str,std::placeholders::_1)); std::cout << *wc <<
  // std::endl;

  // std::sort(words.begin(), words.end(),isShorter);
  // printWords(words);

  // // std::sort(words.begin(),
  // words.end(),std::bind(isShorter,std::placeholders::_2,std::placeholders::_1));
  // // printWords(words);

  // auto end_unique = std::unique(words.begin(), words.end());
  // printWords(words);
  // words.erase(end_unique, words.end());
  // printWords(words);
  // std::stable_sort(words.begin(),words.end(),[](std::string const &s1,
  // std::string const &s2){
  //     return s1.size() < s2.size();
  // });
  // auto check7 = std::bind(compareLength, std::placeholders::_1,7);
  // auto wc = std::find_if(words.begin(), words.end(), check7);
  // auto count = words.end() - wc; // 计算大于等于7个字符的字符串数量
  // std::cout << count << " " << make_plural(count, "word", "s") << " of length
  // 7 or longer" << std::endl;

  // std::for_each(wc, words.end(), std::bind(print,
  // std::ref(std::cout),std::placeholders::_1, ' '));

  // my_biggies(words, 5);
  // use_stable_patition_biggies(words, 5);
  // 练习10.13
  // 返回一个迭代器 把大于5个字符的字符串分到前面 (true的放置于前面)

  // auto it = std::partition(words.begin(), words.end(), strLengthCompare);
  // std::cout << "Words shorter than 5 characters:" << std::endl;
  // for (auto iter = words.cbegin(); iter != it; ++iter) {
  //     std::cout << *iter << " ";
  // }

  // biggies(words, 5);

  // countIfLen(words, 6);

  // int i = 3;
  // auto func = [&]() mutable ->bool{
  //     if (i == 0) {
  //         return false;
  //     }
  //         --i;
  //         return i == 0?false:true;
  // };
  // std::cout << func() << std::endl; // 输出 true
  // i = 0;
  // // 再次调用 func
  // std::cout << func() << std::endl; // 输出 false

  // auto f = [](int a, int b){
  //     return a + b;
  // };
  // // f(5, 10);
  // int x = 5;
  // auto f2 = [x](int y){
  //         return x + y;
  //     };

  // std::vector<int> vi = {-1, 2, 3, 4, 5};
  // std::transform(vi.begin(), vi.end(),vi.begin(), [](int i)-> int {
  //     if (i < 0) {
  //         return -i; // 如果是负数，返回其绝对值
  //     }else {
  //         return i; // 如果是正数，返回其本身
  //     }
  // })

  std::cin.get();
}