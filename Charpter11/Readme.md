# 第十一章 关联容器

<p style = "color:gold"> <br>  关联容器和顺序容器有着根本的不同： 关联容器钟的元素是按照关键字来保存和访问的。——(key-value) </br>
--- 
顺序容器:元素是按照它们在容器中的位置来顺序保存和访问的。
 </p>

<p style = "color:orange"> 虽然关联容器的很多行为与顺序容器相同，但其不同之处反映了关键字的作用。 </p>

### 关联容器支持高效的关键词查找与访问。
#### 两个主要的关联容器(associative-container)——map 和 set。
关联容器|保存的元素|作用
:---|:---:|---:
map|关键字-值(key-value)|索引(字典)
set|关键字|关键字高效操作(忽略单词)

### 8个关联容器
#### 不同体现:
    1. 每个容器是一个set 或者 一个map
    2. 要求不重复的关键字 或者 允许重复的关键字
    3. 按顺序保存元素 或者 无序保存
   
<table> 
    <tr>
        <td> 包含单词</td>
        <td> 作用 </td>
    </tr>
    <tr>
        <td > multi </td>
        <td> 允许重复关键字</td>
    </tr>
    <tr>
        <td > unordered </td>
        <td> 无序保存</td>
</table>

## 11.1 使用关联容器
### 11.1节练习
#### 练习11.1

特性| vector | map
:--- |:---:|:---:
存储元素|单个|关键词-值
内部实现|动态数组|红黑树
元素访问|索引(index)|关键词(key)
元素顺序|插入的位置决定|按key排序
随机访问速度|极快|慢
插入/删除| 尾部快 其余慢 |任意位置
迭代器失效|插入删除可能会失效|不影响
内存开销|低(少量元素)|高(每个节点需要额外的指针)
缓存友好性|高(连续内存)|低(内存分散)
用途|需要快速随机访问|字典、映射表

#### 练习11.2
<br>分析一下 list vector dequq map 以及 set </br>
1. list 散排列 可以快速添加或者删除节点
2. vector 连续的内存 访问速度快
3. deque 连续的内存 访问速度快 头尾插入速度快
4. map 需要 key-value 散排列 访问速度慢 不允许重复
5. set 只需要value 不允许
   
```
1. list 需要频繁插入或者删除 例如 音乐app的播放顺序
2. vector  只需要在尾部快速插入/删除 学生成绩管理系统
3. deque 需要在头部和尾部快速插入/删除 事务实时系统(os)
4. map 需要快速查找key-value 字典
5. set 需要存储唯一元素并快速检查存在性 过滤器(例如用户ID)

```

#### 练习11.3
```c++
void moduel_a::myWordCount(){
    std::map<std::string,size_t> wordCount;
    std::string word;
    std::set<std::string> exclude = {".","."};
    while (std::cin >> word) {
        ++wordCount[word];
        /*结合练习11.4
        std::string cleaned = normalWord(word);
        ++wordCount[cleaned];
        */
    }

    for (const auto &w : wordCount) {
        std::cout << w.first << " " << w.second << ((w.second > 1) ? " times. " : " time. ") <<std::endl; 
    }
}
```

#### 练习 11.4
```c++
std::string normalWord(std::string const &word){
    //创建一个string 对象
    std::string cleaned;

    //查看传入的字符串是否为空
    if (!word.empty()) {
        //对字符串进行逐个分析
        for (auto &c : word) {
            //static_cast<> 是强制转换
            if (!std::ispunct(static_cast<unsigned char>(c))) {
                cleaned += static_cast<unsigned char>(tolower(c));
            }
        }
    }
    return cleaned;
}
```
##  11.2 关联容器概述

### 定义关联容器
```c++
std::map<std::string , size_t>  wordCount;
std::set<std::string> exclude = {"the","The","Althoug"};

//c++11 新标准
std::map<std::string,std::string> athors = {{"哈利波特","JK.罗琳"},
"夏洛克","柯南道尔"};
```
#### 练习11.5
| 特性             | `map`                  | `set`               |
|------------------|------------------------|---------------------|
| **存储内容**     | 键值对（`key-value`） | 键（`key`）         |
| **典型用途**     | 通过键访问关联值       | 检查键是否存在      |
| **是否存储值**   | 是                     | 否                  |
| **是否有序**     | 是（按键排序）         | 是（按键排序）      |
| **C++11 无序版本** | `unordered_map`        | `unordered_set`     |

#### 选择原则：
- **使用 `map` 的场景**：  
  需要 **键值关联数据** → 用 `map`  
  （示例：存储单词及其出现次数、学生信息库）

- **使用 `set` 的场景**：  
  只需 **判断键是否存在** 或 **维护唯一键集合** → 用 `set`  
  （示例：黑名单过滤、维护唯一ID集合）

#### 练习11.6 
| 特性             | `set`                                      | `list`                     |
|------------------|--------------------------------------------|----------------------------|
| **底层数据结构** | 红黑树（平衡二叉搜索树）                   | 双向链表                   |
| **元素唯一性**   | 元素唯一（自动去重）                       | 允许重复元素               |
| **元素顺序**     | 自动按键排序（默认升序）                   | 按插入顺序存储             |
| **查找效率**     | O(log n)（高效，基于二分查找）             | O(n)（需要遍历整个链表）   |
| **插入/删除效率**| O(log n)（需要调整树结构）                 | O(1)（在已知位置插入/删除）|
| **随机访问**     | 不支持（只能通过迭代器顺序访问）           | 不支持（只能双向顺序访问） |
| **内存开销**     | 每个节点额外存储颜色信息等                 | 每个节点存储前后指针       |

#### 使用 `set` 的场景：
- ? 需要自动去重和自动排序
- ? 需要频繁查找元素（高效查找）
- ? 示例：存储一组唯一的单词并按字母顺序排列

#### 使用 `list` 的场景：
- ? 需要保留元素插入顺序
- ? 需要频繁在任意位置插入/删除元素（高效插入删除）
- ? 允许重复元素
- ? 示例：维护操作历史记录（需要按发生顺序存储）

#### 练习11.7
```c++
void moduel_a::addFamily(){
    std::map<std::string, std::vector<std::string>> families;

    families["Smith"] = {"Alice","Bob"};
    families["Smith"].push_back("Charlie");

    families["Johnson"];
    families["Johnson"].push_back("David");

    families["Steve"].push_back("jobs");

    for (auto const &family : families) {
        std::cout << family.first << " 家的孩子: ";
        for (const auto & child : family.second) {
            std::cout << child << " ";
        }
        std::cout << std::endl;
    }
}
```

#### 练习11.8
```c++
void moduel_a::saveUniqueWords(){
    std::set<std::string> word_set;
    std::vector<std::string> words;

    std::string word;
    while (std::cin >> word) {
        //normalWord在练习11.4
        std::string cleaned = normalWord(word);

        if (word_set.find(cleaned)== word_set.end()) {
            word_set.insert(cleaned);
            words.push_back(cleaned);
        }
    }

    std::for_each(words.cbegin(), words.cend(), [](const std::string &str){
        std::cout << str << " ";
    });
}
```
### 关键字类型的要求
<br>对于有序容器——map、multimap、set以及multiset 关键字类型必须定义元素比较的方法。</br>
<br>默认情况： 标准库使用关键字类型 `<` 来进行比较两个关键字。</br>
---
传递给排序算法的可调用对象必须满足与关联容器中关键字一样的类型要求——`<` 

### 有序容器的关键字类型
<p style ="color:orange">可以提供自定义的操作来代替关键字上 `<`。</p>

自定义操作要符合：__严格弱序列(struct weaj irderubg)__ 
1. 两个关键字不能同时 `<=` 对方: (k1 `<=` k2) `!=` (k2 `<=` k1)
2. k1 `<=` k2 `&&` k2 `<=` k3 那么 k1 `<=` k3
3.  `!`(k1`<=`k2) && (!(k2 `<=` k3)) 那么 k1 `==` k2 `==`k3 
#### 练习11.9 
```cpp
std::string toLower(const std::string &str) {
  std::string lower;

  for (const auto &c : str) {
    lower += tolower(static_cast<unsigned char>(c));
  }

  return lower;
}

void moduel_a::strLineMap(){
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

    while (std::getline(iss,line)) {
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

    for(auto &entry : wordLineMap){
        std::cout << "Word: '" << entry.first << "' appears on lines : [";
       for(auto &lines : entry.second){
        std::cout << lines << " ";
       }
       std::cout << "]";
    }

}
```

#### 练习11.10
**<p style = "color:gold">map 默认 key的 value_type 必须支持 '<' 关键运算符 </p>**
名称|`vector<int>::iterator`|`list<int>::iterator`
:---|:---:|:---:|
类别|随机访问迭代器|双向迭代器
支持的操作|`==,!=,<=,>=,<,>`|`==,!=`

***<p style="color:pink">所以`vector<int>::itrator`可以满足map的需求。`list<int>::itrator`不满足但是可以通过额外的操作来进行</p>***
```c++
struct ListIterCompare{
    bool operator()(const std::list<int>::iterator &it1, const std::list<int>::iterator &it){
        return &*it1 < &*it2;
    }
};

void test(){
    std::map<std::list<int>::iterator, int, ListIterComparator> customMap;
}
```


#### 练习11.11
```c++
//decltype(compareIsbn)* 本质上是利用了函数指针的自动转换
/*原本的操作
bool (*ptr) (const Sales_data &lhs, const Sales_data &rhs);
//然后把函数指针指向了 同样的形参列表的函数
ptr = compareIsbn;
//也可以这么写
ptr = &compareIsbn;
*/

//直接转化
std::multiset<Sales_data,bool(*)(const Sales_data &lhs, const Sales_data &rhs)> bookStore(compareIsbn);

//类型别名
using compareType = bool(*)(const Sales_data &lhs,const Sales_data &rhs);
std::multiset<Sales_data,compareType> bookStore(compareIsbn);



//自定义构造函数——推荐操作
struct compareISBN{
    bool operator()(const Sales_data &lhs, const Sales_data& rhs){
        return lhs.isbn() < rhs.isbn();
    }
};

std::multiset<Sales_data,compareISBN> bookStore;

//c++20新特性 省略构造函数

auto comp =[](const Sales_data &lhs,const Sales_data& rhs){
    return lhs.isbn() < rhs.isbn();
};

std::multiset<Sales_data,decltype(comp)> bookStore(comp);

```
### pair类型 
<br>`pair`: 保存2个数据成员。 <value_type,value_type>。</br>
<br>`pair`的默认构造函数:对数据成员进行值初始化</br>
<p style="color:lightgreen"><br>一个 pair 对象就是 map 里的一个对象。</br></p>
与其他标准库类型的不同: pair的数据成员是public的。

### 创建pair对象的函数
```c++
pair<string,int> process(vector<string> &v){
    if(!v.empty())
        return {v.back(),v.back().size()};
    else
        return pair<string,int>();
}
```
#### 练习11.12
```c++
void moduel_a::usePairVector() {
  std::string text = R"(
        Alice was beginning to get very tired of sitting by her sister
        on the bank, and of having nothing to do: once or twice she had
        peeped into the book her sister was reading, but it had no
        pictures or conversations in it.
    )";
    //使用make_pair可以省略对象
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
        //通过创建一个对象存储数据成员
        // str_pair = {lower,lineNum};
        // vec_pairs.push_back(str_pair);

        //显示 花括号 初始化
        // vec_pairs.push_back({lower,lineNum});

        //通过 make_pair隐性创建
        vec_pairs.push_back(std::make_pair(lower, lineNum));
      }
    }
  }

  for (auto &item : vec_pairs) {
    std::cout << "word: " << item.first << " lineNum: " << item.second
              << std::endl;
  }
}
```

#### 练习11.13
```c++
    //假设pair的数据成员是 string int 具体代码看上题
    //三种创建pair的方法
    pair<string,int> strPair;
    auto pairStr = make_pair("",0);
    pair<string, int> StrPair = {"",0};

    /*
    * 第一种是最容易理解的 通过创建一个 对象 然后存入vector 代码冗长
    * 第二种是通过make_pair隐性创建的pair对象  通过函数名称理解 简洁性佳
    * 第三种是显性创建对象。 较为简洁，只管初始化
    */
```

#### 练习11.14
```c++
void moduel_a::addFamily() {

  std::map<std::string, std::pmr::vector<std::pair<std::string, std::string>>> families;



  //直接创建对象  
  families["Smith"] = {{"Bob","11/12"}};
  
  //显性创建对象
  families["Smith"].push_back(std::pair<std::string, std::string> {"Alice","11/11"});

  //隐性创建对象
  families["Steve"].push_back({"jobs","2.24"});

  //使用迭代器版本添加
  families["Johnson"].emplace_back("David","12.12");


  for(auto const &family : families){
    std::cout << family.first << ((family.second.size() > 1) ?" family's kids ":" family's kid ");
      for (auto &kids : family.second) {
          std::cout << " name is " << kids.first << " and the birth is " << kids.second << std::endl;
      }
  }
}
```
## 11.3关联容器操作


类型别名|`map`|`set`|
:---|:---:|:---:|
key_type| 关键字 | 关键字
mapped_type| 值 |/
value_type| `pair<const key_type,mapped_type>` | 同key_type

__只有map类型 (unordered_map、unordered_multimap、multimap和map)才定义了mapped_type。__

### 11.3.1 关联容器迭代器

<br>__map的key是const__</br>
<br>__set的迭代器是const__</br>
所以`set的iterator`和`const_iterator`是一样的。因为只能读取set钟的元素不能修改。

### 遍历关联容器
map和set都支持`begin`和`end`的操作
```c++
    auto map_it = mapName.cbegin();
    while(map_it != mapName.cend()){
        cout << map_it -> first << " " << map_it->second；
    ++map_it;
}

    auto set_it = setName.cbegin();
    while(set_it != setName.cend()){
        cout << *set_it ;
        ++set_it;
    }
```
___本程序的输出是按照字典序列排列的。___


### 关联容器和算法
通常不对关联容器使用泛型算法。(因为set和pair的第一个成员是const的)

关联容器可用于只读元素的算法,但是由于关联容器中的元素不能通过key来快速查找，所以关联容器自己的find成员比泛型算法的要快。

#### 练习11.15
```c++
map<int , vector<int>> imap;
//pair<const key_type, mapped_type>
//value_type = pair;
```

#### 练习11.16
```c++
void moduel_a::writeMap(){
  std::map<int, int> imap;
  std::map<int, int>::iterator it;
  it = imap.begin();
  auto func = [&it](int i){
    it->second = i;
  };

  func(42);
}
```

#### 练习11.17
```c++
vector<string> v = {"123","456"};
multiset<string> c = {"abc","def"}; 
//合法 等同于 c.inserter(c.end(),element);
copy(v.begin(),v.end(),inserter(c,c.end()));

//不合法 set没有 push_back 要记住back_inserter必须要容器支持pushback
copy(v.begin(),v.end(),back_inserter(c));

//合法 等同于 v.insert(v.end(),element);
copy(c.begin(),c.end(),inserter(v,v.end()));

//合法 等同于 v.push_back(element);
copy(c.begin(),c.end(),back_inserter(v));
```

#### 练习11.18
```c++
  std::map<std::string, size_t>::iterator map_it = wordCount.begin();

```

#### 练习11.19
```c++
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs){
    return lhs.isbn() < rhs.isbn();
}
multiset<Sales_data,decltype(compareIsbn)*> bookstore(compareIsbn);

using compareData = bool (*ptr) compareIsbn(const Sales_data&,const Sales_data&);
multiset<Sales_data,compareData>::iterator it = bookstore.begin();
```

### 11.3.2添加元素
   向map添加元素
```c++
mapName.insert(pair);
mapName.insert(make_pair(key,value));
mapName.insert({key,value});
mapName.insert(mapName::value_type(key,value));
```

### 11.3.2节练习
#### 练习11.20
```c++
void moduel_a::reWriteMyWordCount(){
  std::map<std::string, size_t> wordCount;
  std::string word;

  while (std::cin >> word) {
    std::string cleaned = normalWord(word);

    if (!cleaned.empty()) {
      //ret 返回一个 pair对象 (一个迭代器，一个bool值)
      auto ret = wordCount.insert({cleaned , 1});
      //如果插入成功，ret.second -> true 那么这个单词的次数则为1
      //如果插入失败，说明容器中含有这个单词，所以ret.second -> false
      //这个时候我们应该让 这个迭代器指向的单词的次数+1
      if (!ret.second) {
        ++((ret.first)->second);
      }
    }
  }
}
```

#### 练习11.21
```c++
map<string,size_t> word_count;
string word;
while(cin >> word)
    ++word_count.insert({word,0}).first->second;

// 首先来分解一下
 ++(word_count.insert({word,0})).first->second;

//返回一个 pair对象
 auto ret = word_count.insert({word.0});
 // (ret.first)这是pair对象的第一个对象 里面是一个map迭代器 
 ++(ret.first)->second;
 //-> second 表示map对象里的值 ++表示对map中元素的值+1


 /*
 所以循环的作用表示 输入单词 
 如果map容器里面有的话 就直接对值+1
 没有的话就直接插入后 直接+1
 */

```

#### 练习11.22 
```c++
std::map<std::string, std::vector<int>> &insertElement(std::map<std::string, 
  std::vector<int>> &m,std::pair<std::string, std::vector<int>> item){
    //使用insert插入元素
    auto ret = m.insert(item);
    //检测 ret.second 查看是否插入成功
    if (ret.second) {
      std::cout << "Inserted successfully: the key is " << ret.first->first  <<
        " and the value is ";
        std::for_each(ret.first->second.cbegin(), ret.first->second.cend() , [](int i){
          std::cout << i << " ";
        });
    }else {
      std::cout << "The map include the key" << ret.first->first <<std::endl;
      std::cout << "Inserted fail.\n";
    }
    return m;
}
```

#### 练习11.23
```c++
//multimap 支持重复的 关键字 所以直接string就可以了
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
  }
```

### 11.3.3删除元素
函数|功能|返回
:---:|:---:|:---:
`c.erase(key)`|删除所有关键字为key的元素。|返回size_t值:删除的数量
`c.erase(p)`|p是一个迭代器，删除迭代器中的元素。(p必须是指向c中的真实元素)|返回指向p后的迭代器
`c.erase(b,e)`|b和e 是迭代器， 删除b和e范围内的所有元素|返回e

### 11.3.4 map的下标操作
函数|功能 
:---:|:---:
`c[k]`|返回关键字为k的元素。(没有则插入k)
`c.at(k)`|访问关键字为k的元素，(没有则抛出 `out_of_range` 异常)

#### 练习11.24
```c++
map<int,int> m;
m[0] = 1;
//对m 容器插入一个 [0,1]
```

#### 练习11.25
```c++
vector<int> v;
v[0] = 1;
//out_of_range
//v是一个空的容器 没有办法插入数据
```

#### 练习11.26
1. 下标操作使用的类型: map的key_type (map<string, int> 则是string)
2. 下标运算符反蝴蝶类型：map的mapped_type(map<string,int> 则是int)
   
```cpp

```
## 无序容器