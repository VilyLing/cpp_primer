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

// ����һ���������������ж�
std::string::iterator &useInsertAndEarse(std::string &s,
                                         std::string const &oldVal,
                                         std::string const &newVal,
                                         std::string::iterator &it) {
  // ʹ�õ�������insert erase������ʵ�ַ�ʽ
  //  ����ַ�����С ����ɾ�� �� ���������� ��ǰ�ƶ�������
  auto oldLen = oldVal.size();
  auto newLen = newVal.size();

  // �ж�ͬ���ĳ����ַ����Ƿ�ƥ�� �� ��Ҫ�滻���ַ����Ƿ�ƥ��

  if ((std::string{it, it + oldLen} == oldVal) &&
      std::string{it, it + newLen} != newVal) {
    // it = s.erase(it, it + oldLen);
    // it = s.insert(it, newVal.begin(), newVal.end());

    // ��Ч��� replace�汾
    s.replace(it, it + oldLen, newVal);
    std::advance(it, newLen);
    // it += newLen;
  } else {
    // �����ƥ��Ļ� ��������ǰ�ƶ�
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

  // ͨ���±��ж� �ַ����Ƿ�ƥ�� ����ʹ��find���� �����ʵ�ַ�ʽ
  for (size_t index = 0; index <= s.size() - oldLen;) {
    // �ж��Ƿ�ƥ��
    bool match = false;

    for (size_t i = 0; i < oldLen; ++i) {
      if (s[i + index] != oldVal[i]) {
        match = false;
        break;
      } else {
        match = true;
      }
    }

    // ���ƥ�����滻�ַ��� ���� �±���ǰ�ƶ�
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
  // �ж���Ҫɾ����Ԫ�ز�Ϊ��s
  if (oldVal.empty()) {
    return;
  }

  // ����һ������������
  auto it = str.begin();

  // ȷ��str�ĳ����ܹ� >= ��Ҫ�滻���ַ�������
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
    // �����ո�
    if (expr[i] == ' ') {
      continue;
    }    
    // ��������� ��������ջ
    // ������Ҫע��������ֿ����Ƕ�λ�� ������Ҫ������ת��Ϊ����
   if (isdigit(expr[i])) {
    int num = 0;
    while (i < expr.size() && isdigit(expr[i])) {
      // ���ַ�ת��Ϊ����
      // ������Ҫע�� '0' �� ASCII ֵ�� 48 ������Ҫ��ȥ '0' �� ASCII ֵ
      num = num * 10 + (expr[i] - '0');
        ++i;
      }
      // ������Ҫע�� i++ ������
      // ��Ϊ i++ ��ѭ���л����� ������Ҫ�� i-- ���˵���һ������
      --i;
      // ��������ջ
      // std::cout << "The number is " << num << std::endl;
      operands.push(num);
   }
   // ���������� ���������ջ
   // ������Ҫע��������ŵ����ȼ�
   else if (expr[i] == '(') {
      operators.push(expr[i]);
   }else if (expr[i] == ')') {
    // ����������� ����Ҫ��ջ�е���������㵽������Ϊֹ
    // ������Ҫע����������Ų��������
    while (operators.top()!= '(') {
      caculator(operands, operators);
    }
    // ����������
    operators.pop();
   }
   // ���������� ����Ҫ��ջ�е����������
   // ������Ҫע���������������ȼ�
   else if (expr[i] == '+' || expr[i] == '-' ||
              expr[i] == '*' || expr[i] == '/') {
                //��Ҫ�ж� ����������ȼ�
                //1. �����ж�������Ƿ�Ϊ��
                //2.����������Ϊ�գ��ж�����������ȼ�
                //3.�ж�ջ���Ƿ�Ϊ(
                //4.���ջ������(
                //5.������ж�ջ���Ƿ�Ϊ *����/�� �����ж� ����ʽ�����ȼ�

     while (!operators.empty() && 
            operators.top() != '(' &&
            ((expr[i] == '+' || expr[i] == '-') && 
             (operators.top() == '*' || operators.top() == '/'))){
              caculator(operands, operators);
     }

     operators.push(expr[i]);
   }
  }

  // ����ջ�е������
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
