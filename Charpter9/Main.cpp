#include "inc/MyDate.h"
#include <cctype>
#include <cstddef>
#include <deque>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <list>
#include <ostream>
#include <stack>
#include <string>
#include <vector>

void fun(std::list<int> &list, std::deque<int> &odd, std::deque<int> &eve) {
  for (auto num : list) {
    if (num & 1) {
      odd.push_back(num);
    } else {
      eve.push_back(num);
    }
  }
}
void printDeque(std::deque<int> &item) {
  for (auto &num : item) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}

void method_forward_list(std::forward_list<std::string> &flst_str,
                         std::string const &str1, std::string const &str2) {
  auto prev = flst_str.before_begin();
  auto cur = flst_str.begin();

  bool b = false;
  while (cur != flst_str.end()) {
    if ((*cur == str1)) {
      flst_str.insert_after(cur, str2);
      b = true;
      return;
    } else {
      prev = cur;
      ++cur;
    }
  }

  if (!b) {
    flst_str.insert_after(prev, str2);
  }
}

// 返回一个迭代器的引用判断
std::string::iterator &useInsertAndEarse(std::string &s,
                                         std::string const &oldVal,
                                         std::string const &newVal,
                                         std::string::iterator &it) {
  // 使用迭代器和insert erase函数的实现方式
  //  获得字符串大小 用来删除 和 插入后迭代器 向前移动的数据
  auto oldLen = oldVal.size();
  auto newLen = newVal.size();

  // 判断同样的长度字符串是否匹配 且 跟要替换的字符串是否匹配

  if ((std::string{it, it + oldLen} == oldVal) &&
      std::string{it, it + newLen} != newVal) {
    // it = s.erase(it, it + oldLen);
    // it = s.insert(it, newVal.begin(), newVal.end());

    // 等效语句 replace版本
    s.replace(it, it + oldLen, newVal);
    std::advance(it, newLen);
    // it += newLen;
  } else {
    // 如果不匹配的话 迭代器向前移动
    ++it;
  }

  return it;
}

void useIndexAndReplace(std::string &s, std::string const &oldVal,
                        std::string const &newVal) {
  if (oldVal.empty()) {
    return;
  }

  auto oldLen = oldVal.size();
  auto newLen = newVal.size();

  // 通过下标判断 字符串是否匹配 可以使用find函数 另类的实现方式
  for (size_t index = 0; index <= s.size() - oldLen;) {
    // 判断是否匹配
    bool match = false;

    for (size_t i = 0; i < oldLen; ++i) {
      if (s[i + index] != oldVal[i]) {
        match = false;
        break;
      } else {
        match = true;
      }
    }

    // 如果匹配则替换字符串 否则 下标向前移动
    if (match) {
      s.replace(index, oldLen, newVal);
      index += newLen;
    } else {
      ++index;
    }
  }
}

void replace_string(std::string &str, std::string const oldVal,
                    std::string const &newVal) {
  // 判断需要删除的元素不为空s
  if (oldVal.empty()) {
    return;
  }

  // 创建一个迭代器对象
  auto it = str.begin();

  // 确保str的长度能够 >= 需要替换的字符串长度
  while (it <= str.end() - oldVal.size()) {
    useInsertAndEarse(str, oldVal, newVal, it);
  }
}

void printStr(std::string const &s) { std::cout << s << std::endl; }

std::string &replaceName(std::string &s, std::string const &prevfix,
                         std::string const &suffix) {

  s.insert(s.begin(), 1, ' ');
  s.insert(s.begin(), prevfix.begin(), prevfix.end());

  s.append(" " + suffix);

  return s;
}

std::string &replaceNameWithIndex(std::string &s, std::string const &prevfix,
                                  std::string const &suffix) {
  s.insert(0, 1, ' ');
  s.insert(0, prevfix);
  s.insert(s.size(), " ");
  s.insert(s.size(), suffix);
  return s;
}

void findArgs(std::string const &findStr, std::string const &beFind) {
  std::string::size_type pos = 0;
  // while ((pos = findStr.find_first_of(beFind,pos))!=std::string::npos) {
  //   std::cout << "The index is " << pos << " The value is " << findStr[pos]
  //   << std::endl;
  //   ++pos;
  // }

  while ((pos = findStr.find_first_not_of(beFind, pos)) != std::string::npos) {
    std::cout << "The index is " << pos << " The value is " << findStr[pos]
              << std::endl;
    ++pos;
  }
}

void AboutDate() {

  MyDate date1("Janary 1, 1990");
  date1.print();

  MyDate date2("1/1/1990");
  date2.print();

  MyDate date3("Jan 1 1990");
  date3.print();
}

void caculator(std::stack<int> &operands,std::stack<char> &operators)
{
    char op = operators.top();
    operators.pop();

    int right = operands.top();
    operands.pop();
    int left = operands.top();
    operands.pop();

    switch (op) {
      case '+': 
        operands.push(left + right);
        break;
        case '-':
        operands.push(left - right);
        break;
        case '*':
        operands.push(left * right);
        break;
        case '/': 
        operands.push(left / right);  
        break;
    }
}

void useStack(){
  std::string expr = "(13+2) * 4-(32-12) /2";
  std::cout << expr << " = ";

  std::stack<int> operands;
  std::stack<char> operators;

  for (size_t i = 0;  i < expr.size(); ++i) {
    // 跳过空格
    if (expr[i] == ' ') {
      continue;
    }    
    // 如果是数字 则将数字入栈
    // 这里需要注意的是数字可能是多位数 所以需要将数字转换为整数
   if (isdigit(expr[i])) {
    int num = 0;
    while (i < expr.size() && isdigit(expr[i])) {
      // 将字符转换为数字
      // 这里需要注意 '0' 的 ASCII 值是 48 所以需要减去 '0' 的 ASCII 值
      num = num * 10 + (expr[i] - '0');
        ++i;
      }
      // 这里需要注意 i++ 的问题
      // 因为 i++ 在循环中会自增 所以需要将 i-- 回退到上一个数字
      --i;
      // 将数字入栈
      // std::cout << "The number is " << num << std::endl;
      operands.push(num);
   }
   // 如果是运算符 则将运算符入栈
   // 这里需要注意的是括号的优先级
   else if (expr[i] == '(') {
      operators.push(expr[i]);
   }else if (expr[i] == ')') {
    // 如果是右括号 则需要将栈中的运算符计算到左括号为止
    // 这里需要注意的是左括号不参与计算
    while (operators.top()!= '(') {
      caculator(operands, operators);
    }
    // 弹出左括号
    operators.pop();
   }
   // 如果是运算符 则需要将栈中的运算符计算
   // 这里需要注意的是运算符的优先级
   else if (expr[i] == '+' || expr[i] == '-' ||
              expr[i] == '*' || expr[i] == '/') {
                //需要判断 运算符的优先级
                //1. 首先判断运算符是否为空
                //2.如果运算符不为空，判断运算符的优先级
                //3.判断栈顶是否为(
                //4.如果栈顶不是(
                //5.则继续判断栈顶是否为 *或者/号 并且判断 与表达式的优先级

     while (!operators.empty() && 
            operators.top() != '(' &&
            ((expr[i] == '+' || expr[i] == '-') && 
             (operators.top() == '*' || operators.top() == '/'))){
              caculator(operands, operators);
     }

     operators.push(expr[i]);
   }
  }

  // 计算栈中的运算符
  while (!operators.empty()) {
    caculator(operands, operators);
  }

  std::cout << operands.top() << std::endl;
  operands.pop();
}

int main(int argc, char *arv[]) {

  // std::list<std::string> de_string;
  // std::string word;
  // while (std::cin >> word) {
  //         de_string .push_back(word);
  // }

  // for (auto it = de_string.cbegin(); it!= de_string.cend(); ++it) {
  //     std::cout << *it << std::endl;
  // }

  //   std::list<int> lst = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  //   std::deque<int> odd, eve;
  //   fun(lst, odd, eve);

  //   printDeque(odd);
  //   printDeque(eve);

  // std::string word;

  // std::vector<std::string> lst;
  // auto item = lst.begin();
  // while (std::cin >> word) {
  //     item = lst.insert(item,word);
  // }

  // std::list<int> c(1,99);
  // if (!c.empty()) {
  //   auto val = *c.begin(), val2 = c.front();
  //   auto last = c.end();
  //   auto val3 = *(--last);
  //   auto val4 = c.back();

  //   // c.front() = 42;
  //   // auto& v = c.back();
  //   // v = 1024;
  //   // auto v2 = c.back();
  //   // v2 = 0;
  // }

  // std::vector<int> ivec;
  // auto a = ivec.at(0);

  // int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
  // std::vector<int> ivec(ia,ia+sizeof(ia)/sizeof(ia[0]));
  // std::list<int> ilst(ia,ia+sizeof(ia)/sizeof(ia[0]));

  // auto iterV = ivec.begin();
  // while (iterV != ivec.end()) {
  //   if (!(*iterV & 1)) {
  //     iterV = ivec.erase(iterV);
  //   }else {
  //     ++iterV;
  //   }
  // }

  // auto itb = ilst.begin();

  // while (itb != ilst.end()) {
  //   //   if (*itb & 1) {
  //     itb = ilst.erase(itb);
  //   }
  //   else {
  //   ++itb;
  //   }
  // }

  // std::forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9};
  // auto prev = flst.before_begin();
  // auto curr = flst.begin();
  // while (curr != flst.end()) {
  //   if ((*curr & 1)) {
  //     curr = flst.erase_after(prev);
  //   }else {
  //     prev = curr;
  //     ++curr;
  //   }
  // }

  // for (auto &it : flst) {
  //   std::cout << it  << std::endl;
  // }

  // std::forward_list<std::string> flst_str = {"Hello","world","!!!","LoL"};
  // for (auto &it:flst_str) {
  //   std::cout << it << " ";
  // }
  // method_forward_list(flst_str, "Hello", "vily");
  // for (auto &it:flst_str) {
  //   std::cout << it << " ";
  // }

  //  std::vector<char> cvec = {'h','e','l','l','o'};

  //  std::string s(cvec.begin(),cvec.end());

  //  std::cout << s << std::endl;

  // std::string str = "tho thru hello tho";
  // std::string rep_it1 = "though";
  // std::string rep_it2 = "through";

  // printStr(str);

  // useIndexAndReplace(str, "tho", rep_it1);
  // // replace_string(str, "tho", rep_it2);
  // printStr(str);

  // useIndexAndReplace(str, "thru", rep_it2);

  // std::string name = "AnnaBell";
  // printStr(name);
  // replaceNameWithIndex(name, "Ms.", "Jr.");
  // printStr(name);

  // // replace_string(str, "thru", rep_it2);
  // printStr(str);

  // std::string numStr = "0123456789";
  // std::string alphaStr = "abcdeER";

  // std::string exampleStr = "ab2c3d7R4E6";

  // findArgs(exampleStr, numStr);
  // findArgs(exampleStr, alphaStr);


  // std::stack<int> intStack;
  // for (int i = 0; i < 10; ++i) {
  //   intStack.push(i);
  // }

  // while (!intStack.empty()) {
  //   int vaule = intStack.top();
  //   std::cout << vaule << " ";
  //   intStack.pop();
  //   std::cout << intStack.size() << std::endl;
  // }


  useStack();
  std::cin.get();
}
