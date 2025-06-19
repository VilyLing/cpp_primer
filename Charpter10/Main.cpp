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
  // ���words�е������ַ���
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
  // �����ַ������Ƚ��з���
  elimDups(words);
  // �����ַ������Ƚ�������
  // ʹ��lambda���ʽ��������
  std::stable_sort(words.begin(), words.end(),
                   [](std::string const &s1, std::string const &s2) {
                     return s1.size() < s2.size();
                   });

  auto wc = std::find_if(words.begin(), words.end(),
                         [sz](std::string const &s) { return s.size() >= sz; });

  auto count = words.end() - wc; // ������ڵ���5���ַ����ַ�������
  std::cout << count << " " << make_plural(count, "word", "s") << " of length "
            << sz << " or longer" << std::endl;
  // ������ڵ���5���ַ����ַ���
  std::for_each(wc, words.end(),
                [](const std::string &s) { std::cout << s << " "; });
  std::cout << std::endl;
}

// ��д�ҵ�biggies����
void my_biggies(std::vector<std::string> &words,
                std::vector<std::string>::size_type sz) {
  // ���ȶ�words����ȥ�غ�����
  std::sort(words.begin(), words.end());
  // ʹ��end_unique�������ظ�Ԫ��
  auto end_unique = std::unique(words.begin(), words.end());
  // ɾ���ظ�Ԫ��
  words.erase(end_unique, words.end());

  // �����ַ������Ƚ�������
  std::stable_sort(words.begin(), words.end(),
                   [](std::string const &s1, std::string const &s2) {
                     return s1.size() < s2.size();
                   });

  printWords(words);
  // ʹ�ò��� ���ҵ�һ�����ڵ���sz���ַ���
  // auto wc = std::find_if(words.begin(), words.end(), [sz](std::string const
  // &s){
  //     return s.size() >= sz;
  // });

  // ʹ��partition������
  //  auto pack = std::partition(words.begin(), words.end(), [sz](const
  //  std::string &s){
  //      return s.size() < sz;
  //  });

  // ��ϰ10.25

  auto checkSizeWithSz = std::bind(check_size, std::placeholders::_1, 5);
  auto pack = std::partition(words.begin(), words.end(), checkSizeWithSz);

  // ������ڵ���sz���ַ�������
  //  auto count = words.end() - wc;

  // auto count = words.end() - pack;
  auto count = pack - words.begin();
  std::cout << count << " " << make_plural(count, "word", "s") << " of length "
            << sz << " or longer" << std::endl;
  // ������ڵ���sz���ַ���
  // std::for_each(pack, words.end(), [](const std::string &s){
  //     std::cout << s << " ";
  // });
  std::for_each(words.begin(), pack,
                [](const std::string &s) { std::cout << s << " "; });
}

void use_stable_patition_biggies(std::vector<std::string> &words,
                                 std::vector<std::string>::size_type sz,
                                 std::ostream &os = std::cout, char c = ' ') {

  // ���ȶ�words����ȥ�غ�����
  std::sort(words.begin(), words.end());
  // ʹ��end_unique�������ظ�Ԫ��
  auto end_unique = std::unique(words.begin(), words.end());
  // ɾ���ظ�Ԫ��
  words.erase(end_unique, words.end());
  // �����ַ������Ƚ��з���
  std::stable_sort(words.begin(), words.end(),
                   [](std::string const &s1, std::string const &s2) {
                     return s1.size() < s2.size();
                   });

  std::for_each(words.begin(), words.end(),
                [](const std::string &s) { std::cout << s << " "; });
  std::cout << std::endl;

  // ʹ��stable_partition������
  auto it = std::stable_partition(
      words.begin(), words.end(),
      [=](std::string const &s) { return s.size() < sz; });
  // ������ڵ���sz���ַ�������
  auto count = words.end() - it;
  std::cout << count << " " << ((count > 1) ? "words" : "word") << " of Length"
            << sz << " or Longer" << std::endl;

  std::for_each(it, words.end(),
                [&, c](std::string const &s) { os << s << c; });
  os << std::endl;
}

void countIfLen(std::vector<std::string> &words,
                std::vector<std::string>::size_type sz) {
  // ʹ��count_if��������ڵ���sz���ַ�������
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

  // ��ϰ10.42
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
   //��ϰ10.33
   if (argc != 5) {
       std::cerr << "�÷�" << argv[0] << "�����ļ� �����ļ� ż���ļ�"<<
   std::endl;

       return EXIT_FAILURE;
   }
   //�������ļ���
   std::ifstream in(argv[2]);
   if (!in) {
       std::cerr << "�޷����ļ���: " << argv[2] << std::endl;
       return EXIT_FAILURE;
   }
   std::istream_iterator<int> in_iter(in) , efo;
   std::ofstream odd_out(argv[3]),even_out(argv[4]);
   std::cout <<"��д�������\n";
   if (!even_out || !odd_out) {
       std::cerr << "�޷�������ļ�" << std::endl;
       return EXIT_FAILURE;
   }
   std::ostream_iterator<int> even_iter(even_out," ");
   std::ostream_iterator<int> odd_iter(odd_out, "\n");
   std::cout <<"�����������\n";
   std::for_each(in_iter, efo, [&](int n){
       // std::cout << "д���ļ�"<< "\n";
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

  // //��ϰ10.22
  // auto fun_10_22 = std::bind(check_size, std::placeholders::_1,6);

  // //��ϰ10.23
  // /*
  // * bind���ٰ���1������
  // * ������Ϊ 1+n
  // * ����nΪ ���ú����Ĳ�������
  // */

  // // ��ϰ10.24

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
  // auto count = words.end() - wc; // ������ڵ���7���ַ����ַ�������
  // std::cout << count << " " << make_plural(count, "word", "s") << " of length
  // 7 or longer" << std::endl;

  // std::for_each(wc, words.end(), std::bind(print,
  // std::ref(std::cout),std::placeholders::_1, ' '));

  // my_biggies(words, 5);
  // use_stable_patition_biggies(words, 5);
  // ��ϰ10.13
  // ����һ�������� �Ѵ���5���ַ����ַ����ֵ�ǰ�� (true�ķ�����ǰ��)

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
  // std::cout << func() << std::endl; // ��� true
  // i = 0;
  // // �ٴε��� func
  // std::cout << func() << std::endl; // ��� false

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
  //         return -i; // ����Ǹ��������������ֵ
  //     }else {
  //         return i; // ����������������䱾��
  //     }
  // })

  std::cin.get();
}