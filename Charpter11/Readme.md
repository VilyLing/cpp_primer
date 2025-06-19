# ��ʮһ�� ��������

<p style = "color:gold"> <br>  ����������˳���������Ÿ����Ĳ�ͬ�� ���������ӵ�Ԫ���ǰ��չؼ���������ͷ��ʵġ�����(key-value) </br>
--- 
˳������:Ԫ���ǰ��������������е�λ����˳�򱣴�ͷ��ʵġ�
 </p>

<p style = "color:orange"> ��Ȼ���������ĺܶ���Ϊ��˳��������ͬ�����䲻֮ͬ����ӳ�˹ؼ��ֵ����á� </p>

### ��������֧�ָ�Ч�Ĺؼ��ʲ�������ʡ�
#### ������Ҫ�Ĺ�������(associative-container)����map �� set��
��������|�����Ԫ��|����
:---|:---:|---:
map|�ؼ���-ֵ(key-value)|����(�ֵ�)
set|�ؼ���|�ؼ��ָ�Ч����(���Ե���)

### 8����������
#### ��ͬ����:
    1. ÿ��������һ��set ���� һ��map
    2. Ҫ���ظ��Ĺؼ��� ���� �����ظ��Ĺؼ���
    3. ��˳�򱣴�Ԫ�� ���� ���򱣴�
   
<table> 
    <tr>
        <td> ��������</td>
        <td> ���� </td>
    </tr>
    <tr>
        <td > multi </td>
        <td> �����ظ��ؼ���</td>
    </tr>
    <tr>
        <td > unordered </td>
        <td> ���򱣴�</td>
</table>

## 11.1 ʹ�ù�������
### 11.1����ϰ
#### ��ϰ11.1

����| vector | map
:--- |:---:|:---:
�洢Ԫ��|����|�ؼ���-ֵ
�ڲ�ʵ��|��̬����|�����
Ԫ�ط���|����(index)|�ؼ���(key)
Ԫ��˳��|�����λ�þ���|��key����
��������ٶ�|����|��
����/ɾ��| β���� ������ |����λ��
������ʧЧ|����ɾ�����ܻ�ʧЧ|��Ӱ��
�ڴ濪��|��(����Ԫ��)|��(ÿ���ڵ���Ҫ�����ָ��)
�����Ѻ���|��(�����ڴ�)|��(�ڴ��ɢ)
��;|��Ҫ�����������|�ֵ䡢ӳ���

#### ��ϰ11.2
<br>����һ�� list vector dequq map �Լ� set </br>
1. list ɢ���� ���Կ�����ӻ���ɾ���ڵ�
2. vector �������ڴ� �����ٶȿ�
3. deque �������ڴ� �����ٶȿ� ͷβ�����ٶȿ�
4. map ��Ҫ key-value ɢ���� �����ٶ��� �������ظ�
5. set ֻ��Ҫvalue ������
   
```
1. list ��ҪƵ���������ɾ�� ���� ����app�Ĳ���˳��
2. vector  ֻ��Ҫ��β�����ٲ���/ɾ�� ѧ���ɼ�����ϵͳ
3. deque ��Ҫ��ͷ����β�����ٲ���/ɾ�� ����ʵʱϵͳ(os)
4. map ��Ҫ���ٲ���key-value �ֵ�
5. set ��Ҫ�洢ΨһԪ�ز����ټ������� ������(�����û�ID)

```

#### ��ϰ11.3
```c++
void moduel_a::myWordCount(){
    std::map<std::string,size_t> wordCount;
    std::string word;
    std::set<std::string> exclude = {".","."};
    while (std::cin >> word) {
        ++wordCount[word];
        /*�����ϰ11.4
        std::string cleaned = normalWord(word);
        ++wordCount[cleaned];
        */
    }

    for (const auto &w : wordCount) {
        std::cout << w.first << " " << w.second << ((w.second > 1) ? " times. " : " time. ") <<std::endl; 
    }
}
```

#### ��ϰ 11.4
```c++
std::string normalWord(std::string const &word){
    //����һ��string ����
    std::string cleaned;

    //�鿴������ַ����Ƿ�Ϊ��
    if (!word.empty()) {
        //���ַ��������������
        for (auto &c : word) {
            //static_cast<> ��ǿ��ת��
            if (!std::ispunct(static_cast<unsigned char>(c))) {
                cleaned += static_cast<unsigned char>(tolower(c));
            }
        }
    }
    return cleaned;
}
```
##  11.2 ������������

### �����������
```c++
std::map<std::string , size_t>  wordCount;
std::set<std::string> exclude = {"the","The","Althoug"};

//c++11 �±�׼
std::map<std::string,std::string> athors = {{"��������","JK.����"},
"�����","���ϵ���"};
```
#### ��ϰ11.5
| ����             | `map`                  | `set`               |
|------------------|------------------------|---------------------|
| **�洢����**     | ��ֵ�ԣ�`key-value`�� | ����`key`��         |
| **������;**     | ͨ�������ʹ���ֵ       | �����Ƿ����      |
| **�Ƿ�洢ֵ**   | ��                     | ��                  |
| **�Ƿ�����**     | �ǣ���������         | �ǣ���������      |
| **C++11 ����汾** | `unordered_map`        | `unordered_set`     |

#### ѡ��ԭ��
- **ʹ�� `map` �ĳ���**��  
  ��Ҫ **��ֵ��������** �� �� `map`  
  ��ʾ�����洢���ʼ�����ִ�����ѧ����Ϣ�⣩

- **ʹ�� `set` �ĳ���**��  
  ֻ�� **�жϼ��Ƿ����** �� **ά��Ψһ������** �� �� `set`  
  ��ʾ�������������ˡ�ά��ΨһID���ϣ�

#### ��ϰ11.6 
| ����             | `set`                                      | `list`                     |
|------------------|--------------------------------------------|----------------------------|
| **�ײ����ݽṹ** | �������ƽ�������������                   | ˫������                   |
| **Ԫ��Ψһ��**   | Ԫ��Ψһ���Զ�ȥ�أ�                       | �����ظ�Ԫ��               |
| **Ԫ��˳��**     | �Զ���������Ĭ������                   | ������˳��洢             |
| **����Ч��**     | O(log n)����Ч�����ڶ��ֲ��ң�             | O(n)����Ҫ������������   |
| **����/ɾ��Ч��**| O(log n)����Ҫ�������ṹ��                 | O(1)������֪λ�ò���/ɾ����|
| **�������**     | ��֧�֣�ֻ��ͨ��������˳����ʣ�           | ��֧�֣�ֻ��˫��˳����ʣ� |
| **�ڴ濪��**     | ÿ���ڵ����洢��ɫ��Ϣ��                 | ÿ���ڵ�洢ǰ��ָ��       |

#### ʹ�� `set` �ĳ�����
- ? ��Ҫ�Զ�ȥ�غ��Զ�����
- ? ��ҪƵ������Ԫ�أ���Ч���ң�
- ? ʾ�����洢һ��Ψһ�ĵ��ʲ�����ĸ˳������

#### ʹ�� `list` �ĳ�����
- ? ��Ҫ����Ԫ�ز���˳��
- ? ��ҪƵ��������λ�ò���/ɾ��Ԫ�أ���Ч����ɾ����
- ? �����ظ�Ԫ��
- ? ʾ����ά��������ʷ��¼����Ҫ������˳��洢��

#### ��ϰ11.7
```c++
void moduel_a::addFamily(){
    std::map<std::string, std::vector<std::string>> families;

    families["Smith"] = {"Alice","Bob"};
    families["Smith"].push_back("Charlie");

    families["Johnson"];
    families["Johnson"].push_back("David");

    families["Steve"].push_back("jobs");

    for (auto const &family : families) {
        std::cout << family.first << " �ҵĺ���: ";
        for (const auto & child : family.second) {
            std::cout << child << " ";
        }
        std::cout << std::endl;
    }
}
```

#### ��ϰ11.8
```c++
void moduel_a::saveUniqueWords(){
    std::set<std::string> word_set;
    std::vector<std::string> words;

    std::string word;
    while (std::cin >> word) {
        //normalWord����ϰ11.4
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
### �ؼ������͵�Ҫ��
<br>����������������map��multimap��set�Լ�multiset �ؼ������ͱ��붨��Ԫ�رȽϵķ�����</br>
<br>Ĭ������� ��׼��ʹ�ùؼ������� `<` �����бȽ������ؼ��֡�</br>
---
���ݸ������㷨�Ŀɵ��ö��������������������йؼ���һ��������Ҫ�󡪡�`<` 

### ���������Ĺؼ�������
<p style ="color:orange">�����ṩ�Զ���Ĳ���������ؼ����� `<`��</p>

�Զ������Ҫ���ϣ�__�ϸ�������(struct weaj irderubg)__ 
1. �����ؼ��ֲ���ͬʱ `<=` �Է�: (k1 `<=` k2) `!=` (k2 `<=` k1)
2. k1 `<=` k2 `&&` k2 `<=` k3 ��ô k1 `<=` k3
3.  `!`(k1`<=`k2) && (!(k2 `<=` k3)) ��ô k1 `==` k2 `==`k3 
#### ��ϰ11.9 
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

#### ��ϰ11.10
**<p style = "color:gold">map Ĭ�� key�� value_type ����֧�� '<' �ؼ������ </p>**
����|`vector<int>::iterator`|`list<int>::iterator`
:---|:---:|:---:|
���|������ʵ�����|˫�������
֧�ֵĲ���|`==,!=,<=,>=,<,>`|`==,!=`

***<p style="color:pink">����`vector<int>::itrator`��������map������`list<int>::itrator`�����㵫�ǿ���ͨ������Ĳ���������</p>***
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


#### ��ϰ11.11
```c++
//decltype(compareIsbn)* �������������˺���ָ����Զ�ת��
/*ԭ���Ĳ���
bool (*ptr) (const Sales_data &lhs, const Sales_data &rhs);
//Ȼ��Ѻ���ָ��ָ���� ͬ�����β��б�ĺ���
ptr = compareIsbn;
//Ҳ������ôд
ptr = &compareIsbn;
*/

//ֱ��ת��
std::multiset<Sales_data,bool(*)(const Sales_data &lhs, const Sales_data &rhs)> bookStore(compareIsbn);

//���ͱ���
using compareType = bool(*)(const Sales_data &lhs,const Sales_data &rhs);
std::multiset<Sales_data,compareType> bookStore(compareIsbn);



//�Զ��幹�캯�������Ƽ�����
struct compareISBN{
    bool operator()(const Sales_data &lhs, const Sales_data& rhs){
        return lhs.isbn() < rhs.isbn();
    }
};

std::multiset<Sales_data,compareISBN> bookStore;

//c++20������ ʡ�Թ��캯��

auto comp =[](const Sales_data &lhs,const Sales_data& rhs){
    return lhs.isbn() < rhs.isbn();
};

std::multiset<Sales_data,decltype(comp)> bookStore(comp);

```
### pair���� 
<br>`pair`: ����2�����ݳ�Ա�� <value_type,value_type>��</br>
<br>`pair`��Ĭ�Ϲ��캯��:�����ݳ�Ա����ֵ��ʼ��</br>
<p style="color:lightgreen"><br>һ�� pair ������� map ���һ������</br></p>
��������׼�����͵Ĳ�ͬ: pair�����ݳ�Ա��public�ġ�

### ����pair����ĺ���
```c++
pair<string,int> process(vector<string> &v){
    if(!v.empty())
        return {v.back(),v.back().size()};
    else
        return pair<string,int>();
}
```
#### ��ϰ11.12
```c++
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
        //ͨ������һ������洢���ݳ�Ա
        // str_pair = {lower,lineNum};
        // vec_pairs.push_back(str_pair);

        //��ʾ ������ ��ʼ��
        // vec_pairs.push_back({lower,lineNum});

        //ͨ�� make_pair���Դ���
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

#### ��ϰ11.13
```c++
    //����pair�����ݳ�Ա�� string int ������뿴����
    //���ִ���pair�ķ���
    pair<string,int> strPair;
    auto pairStr = make_pair("",0);
    pair<string, int> StrPair = {"",0};

    /*
    * ��һ�������������� ͨ������һ�� ���� Ȼ�����vector �����߳�
    * �ڶ�����ͨ��make_pair���Դ�����pair����  ͨ������������� ����Լ�
    * �����������Դ������� ��Ϊ��ֻ࣬�ܳ�ʼ��
    */
```

#### ��ϰ11.14
```c++
void moduel_a::addFamily() {

  std::map<std::string, std::pmr::vector<std::pair<std::string, std::string>>> families;



  //ֱ�Ӵ�������  
  families["Smith"] = {{"Bob","11/12"}};
  
  //���Դ�������
  families["Smith"].push_back(std::pair<std::string, std::string> {"Alice","11/11"});

  //���Դ�������
  families["Steve"].push_back({"jobs","2.24"});

  //ʹ�õ������汾���
  families["Johnson"].emplace_back("David","12.12");


  for(auto const &family : families){
    std::cout << family.first << ((family.second.size() > 1) ?" family's kids ":" family's kid ");
      for (auto &kids : family.second) {
          std::cout << " name is " << kids.first << " and the birth is " << kids.second << std::endl;
      }
  }
}
```
## 11.3������������


���ͱ���|`map`|`set`|
:---|:---:|:---:|
key_type| �ؼ��� | �ؼ���
mapped_type| ֵ |/
value_type| `pair<const key_type,mapped_type>` | ͬkey_type

__ֻ��map���� (unordered_map��unordered_multimap��multimap��map)�Ŷ�����mapped_type��__

### 11.3.1 ��������������

<br>__map��key��const__</br>
<br>__set�ĵ�������const__</br>
����`set��iterator`��`const_iterator`��һ���ġ���Ϊֻ�ܶ�ȡset�ӵ�Ԫ�ز����޸ġ�

### ������������
map��set��֧��`begin`��`end`�Ĳ���
```c++
    auto map_it = mapName.cbegin();
    while(map_it != mapName.cend()){
        cout << map_it -> first << " " << map_it->second��
    ++map_it;
}

    auto set_it = setName.cbegin();
    while(set_it != setName.cend()){
        cout << *set_it ;
        ++set_it;
    }
```
___�����������ǰ����ֵ��������еġ�___


### �����������㷨
ͨ�����Թ�������ʹ�÷����㷨��(��Ϊset��pair�ĵ�һ����Ա��const��)

��������������ֻ��Ԫ�ص��㷨,�������ڹ��������е�Ԫ�ز���ͨ��key�����ٲ��ң����Թ��������Լ���find��Ա�ȷ����㷨��Ҫ�졣

#### ��ϰ11.15
```c++
map<int , vector<int>> imap;
//pair<const key_type, mapped_type>
//value_type = pair;
```

#### ��ϰ11.16
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

#### ��ϰ11.17
```c++
vector<string> v = {"123","456"};
multiset<string> c = {"abc","def"}; 
//�Ϸ� ��ͬ�� c.inserter(c.end(),element);
copy(v.begin(),v.end(),inserter(c,c.end()));

//���Ϸ� setû�� push_back Ҫ��סback_inserter����Ҫ����֧��pushback
copy(v.begin(),v.end(),back_inserter(c));

//�Ϸ� ��ͬ�� v.insert(v.end(),element);
copy(c.begin(),c.end(),inserter(v,v.end()));

//�Ϸ� ��ͬ�� v.push_back(element);
copy(c.begin(),c.end(),back_inserter(v));
```

#### ��ϰ11.18
```c++
  std::map<std::string, size_t>::iterator map_it = wordCount.begin();

```

#### ��ϰ11.19
```c++
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs){
    return lhs.isbn() < rhs.isbn();
}
multiset<Sales_data,decltype(compareIsbn)*> bookstore(compareIsbn);

using compareData = bool (*ptr) compareIsbn(const Sales_data&,const Sales_data&);
multiset<Sales_data,compareData>::iterator it = bookstore.begin();
```

### 11.3.2���Ԫ��
   ��map���Ԫ��
```c++
mapName.insert(pair);
mapName.insert(make_pair(key,value));
mapName.insert({key,value});
mapName.insert(mapName::value_type(key,value));
```

### 11.3.2����ϰ
#### ��ϰ11.20
```c++
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
```

#### ��ϰ11.21
```c++
map<string,size_t> word_count;
string word;
while(cin >> word)
    ++word_count.insert({word,0}).first->second;

// �������ֽ�һ��
 ++(word_count.insert({word,0})).first->second;

//����һ�� pair����
 auto ret = word_count.insert({word.0});
 // (ret.first)����pair����ĵ�һ������ ������һ��map������ 
 ++(ret.first)->second;
 //-> second ��ʾmap�������ֵ ++��ʾ��map��Ԫ�ص�ֵ+1


 /*
 ����ѭ�������ñ�ʾ ���뵥�� 
 ���map���������еĻ� ��ֱ�Ӷ�ֵ+1
 û�еĻ���ֱ�Ӳ���� ֱ��+1
 */

```

#### ��ϰ11.22 
```c++
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
      std::cout << "The map include the key" << ret.first->first <<std::endl;
      std::cout << "Inserted fail.\n";
    }
    return m;
}
```

#### ��ϰ11.23
```c++
//multimap ֧���ظ��� �ؼ��� ����ֱ��string�Ϳ�����
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

### 11.3.3ɾ��Ԫ��
����|����|����
:---:|:---:|:---:
`c.erase(key)`|ɾ�����йؼ���Ϊkey��Ԫ�ء�|����size_tֵ:ɾ��������
`c.erase(p)`|p��һ����������ɾ���������е�Ԫ�ء�(p������ָ��c�е���ʵԪ��)|����ָ��p��ĵ�����
`c.erase(b,e)`|b��e �ǵ������� ɾ��b��e��Χ�ڵ�����Ԫ��|����e

### 11.3.4 map���±����
����|���� 
:---:|:---:
`c[k]`|���عؼ���Ϊk��Ԫ�ء�(û�������k)
`c.at(k)`|���ʹؼ���Ϊk��Ԫ�أ�(û�����׳� `out_of_range` �쳣)

#### ��ϰ11.24
```c++
map<int,int> m;
m[0] = 1;
//��m ��������һ�� [0,1]
```

#### ��ϰ11.25
```c++
vector<int> v;
v[0] = 1;
//out_of_range
//v��һ���յ����� û�а취��������
```

#### ��ϰ11.26
1. �±����ʹ�õ�����: map��key_type (map<string, int> ����string)
2. �±���������������ͣ�map��mapped_type(map<string,int> ����int)
   
```cpp

```
## ��������