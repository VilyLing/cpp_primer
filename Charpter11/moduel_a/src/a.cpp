#include "a.h"
#include <algorithm>
#include <cctype>
#include <cstddef>
#include <iostream>
#include <istream>
#include <iterator>
#include <list>
#include <map>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

std::string normalWord(std::string const &word) {
  std::string cleaned;

  if (!word.empty()) {
    for (auto &c : word) {
      if (!std::ispunct(static_cast<unsigned char>(c))) {
        cleaned += static_cast<unsigned char>(tolower(c));
      }
    }
  }
  return cleaned;
}

void moduel_a::myWordCount() {
  std::map<std::string, size_t> wordCount;

  std::string word;
  std::set<std::string> exclude = {".", "."};
  while (std::cin >> word) {
    std::string cleaned = normalWord(word);
    ++wordCount[cleaned];
  }

  for (const auto &w : wordCount) {
    std::cout << w.first << " " << w.second
              << ((w.second > 1) ? " times. " : " time. ") << std::endl;
  }
}

void moduel_a::reWriteMyWordCount(){
  std::map<std::string, size_t> wordCount;
  std::string word;

  while (std::cin >> word) {
    std::string cleaned = normalWord(word);

    if (!cleaned.empty()) {
      //ret ����һ�� pair���� (һ����������һ��boolֵ)
      auto ret = wordCount.insert({cleaned , 1});
      //�������ɹ���ret.second -> true ��ô������ʵĴ�����Ϊ1
      //�������ʧ�ܣ�˵�������к���������ʣ�����ret.second -> false
      //���ʱ������Ӧ���� ���������ָ��ĵ��ʵĴ���+1
      if (!ret.second) {
        ++((ret.first)->second);
      }
    }
  }
}


void moduel_a::addFamily() {
  //δ��չ
  // std::map<std::string, std::vector<std::string>> families;
  //��չ
  std::map<std::string, std::pmr::vector<std::pair<std::string, std::string>>> families;
  //δ��չ�汾
  // families["Smith"] = {"Alice", "Bob"};
  // families["Smith"].push_back("Charlie");

  // families["Johnson"];
  // families["Johnson"].push_back("David");

  // families["Steve"].push_back("jobs");

  //��չ�汾
  //���Դ�������  
  families["Smith"] = {{"Bob","11/12"}};
  families["Smith"].push_back(std::pair<std::string, std::string> {"Alice","11/11"});

  //���Դ�������
  families["Steve"].push_back({"jobs","2.24"});

  families["Johnson"].emplace_back("David","12.12");

  //δ��չ�汾
  // for (auto const &family : families) {
  //   std::cout << family.first << " �ҵĺ���: ";
  //   for (const auto &child : family.second) {
  //     std::cout << child << " ";
  //   }
  //   std::cout << std::endl;
  // }
  for(auto const &family : families){
    std::cout << family.first << ((family.second.size() > 1) ?" family's kids ":" family's kid ");
      for (auto &kids : family.second) {
          std::cout << "name is " << kids.first << " and the birth is " << kids.second << std::endl;
      }
  }
}

void moduel_a::saveUniqueWords() {
  std::set<std::string> word_set;
  std::vector<std::string> words;

  std::string word;
  while (std::cin >> word) {

    std::string cleaned = normalWord(word);

    if (word_set.find(cleaned) == word_set.end()) {
      word_set.insert(cleaned);
      words.push_back(cleaned);
    }
  }

  std::for_each(words.cbegin(), words.cend(),
                [](const std::string &str) { std::cout << str << " "; });
}

std::string toLower(const std::string &str) {
  std::string lower;

  for (const auto &c : str) {
    lower += tolower(static_cast<unsigned char>(c));
  }

  return lower;
}

void moduel_a::strLineMap() {
  std::map<std::string, std::list<int>> wordLineMap;
  std::string line;

  std::string text = R"(        
        Alice was beginning to get very tired of sitting by her sister
        on the bank, and of having nothing to do: once or twice she had
        peeped into the book her sister was reading, but it had no
        pictures or conversations in it.
    )";

  std::istringstream iss(text);

  int lineNum = 0;

  while (std::getline(iss, line)) {
    ++lineNum;
    std::istringstream lineStream(line);
    std::string word;

    while (lineStream >> word) {
      std::string cleanword;
      for (auto &c : word) {
        if (std::isalpha(c)) {
          cleanword += c;
        }
      }

      std::string lower = toLower(cleanword);

      if (!lower.empty()) {
        wordLineMap[cleanword].push_back(lineNum);
      }
    }
  }

  for (auto &entry : wordLineMap) {
    std::cout << "Word: '" << entry.first << "' appears on lines : [";
    for (auto &lines : entry.second) {
      std::cout << lines << " ";
    }
    std::cout << "]";
  }
}

void moduel_a::usePairVector() {
  std::string text = R"(
        Alice was beginning to get very tired of sitting by her sister
        on the bank, and of having nothing to do: once or twice she had
        peeped into the book her sister was reading, but it had no
        pictures or conversations in it.
    )";
    //ʹ��make_pair����ʡ�Զ���
  // std::pair<std::string, int> str_pair;
  std::vector<std::pair<std::string, int>> vec_pairs;
  int lineNum = 0;
  std::istringstream iss(text);
  std::string line;
  while (std::getline(iss, line)) {
    ++lineNum;
    std::istringstream linestream(line);
    std::string word;
    while (linestream >> word) {
      std::string cleanedWord;
      for (auto &c : word) {
        if (std::isalpha(c)) {
          cleanedWord += c;
        }
      }
      std::string lower = toLower(cleanedWord);
      if (!lower.empty()) {
        // str_pair = {lower,lineNum};
        // vec_pairs.push_back(str_pair);

        //���Դ�������
        // vec_pairs.push_back({lower,lineNum});

        vec_pairs.push_back(std::make_pair(lower, lineNum));

        // ʹ�õ������ĳ��󷽷�
        // vec_pairs.emplace_back(lower,lineNum);
      }
    }
  }

  for (auto &item : vec_pairs) {
    std::cout << "word: " << item.first << " lineNum: " << item.second
              << std::endl;
  }
}

void moduel_a::writeMap(){
  std::map<int, int> imap;
  std::map<int, int>::iterator it;
  it = imap.begin();
  auto func = [&it](int i){
    it->second = i;
  };

  func(42);
}


std::map<std::string, std::vector<int>> &insertElement(std::map<std::string, 
  std::vector<int>> &m,std::pair<std::string, std::vector<int>> item){
    //ʹ��insert����Ԫ��
    auto ret = m.insert(item);
    //��� ret.second �鿴�Ƿ����ɹ�
    if (ret.second) {
      std::cout << "Inserted successfully: the key is " << ret.first->first  <<
        " and the value is ";
        std::for_each(ret.first->second.cbegin(), ret.first->second.cend() , [](int i){
          std::cout << i << " ";
        });
    }else {
      std::cerr << "Inserted fail.\n"
               << "The map include the key" << ret.first->first <<std::endl;
    }
    return m;
}

void moduel_a::addFamilyMuilt(){
    std::multimap<std::string, std::string> families;

    families.insert(std::make_pair("Smith", "Bob"));
    families.insert(std::make_pair("Smith", "Alice"));
  
   families.insert({"Steve","Jobs"});

   for (auto it = families.begin(); it != families.end(); ) {
      const auto &lastName = it->first;
      auto range = families.equal_range(lastName);

      std::cout << lastName << "'s family: ";
      for (auto nameIt = range.first; nameIt != range.second; ++nameIt) {
        std::cout << nameIt->second ;
        if (std::next(nameIt) != range.second) {
          std::cout << " ";
        }
      }
      std::cout << "\n";
      it = range.second;
   }
      
  // for (auto &key : families) {
  //       auto lastName = key.first;
  //       std::cout << lastName << "'s family: ";
  //       for (auto &name : lastName) {
  //           std::cout << name;
  //       }
  //       std::cout <<"\n";
  //     }
  }