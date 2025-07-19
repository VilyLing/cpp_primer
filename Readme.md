# ��ʮ���� ��������
```mermaid
graph LR
A[������������Ա����] --> B["�������캯��(copy constructor)"]
A --> C["������ֵ�����(copy-assignmenet operator)"] 
A --> D["�ƶ����캯��(move constructor)"]
A --> E["�ƶ���ֵ�����(move-assignment operator)"]
A --> F["��������(destructor)"]
```

## 13.1 ��������ֵ������
������Ĳ���
### 13.1.1 �������캯��
```c++
class Foo{
    Foo();          //Ĭ�Ϲ��캯��
    Foo(const Foo&);//�������캯��
};
```
<p style = "color:gold">�������캯��:��һ������������һ���������ͣ����κζ����������Ĭ��ֵ��(�������캯��ͨ����Ӧ����`explicit`)</p>

������ʼ��������������=�������ʱ�ᷢ�����������Ҳ�´����ʼ��
1. ��һ��������Ϊʵ�δ��ݸ�һ�����������͵��β�
2. ��һ����������Ϊ���������͵ĺ�������һ������
3. �û������б��ʼ��һ�������е�Ԫ�ػ�ۺ����еĳ�Ա

#### ��ϰ13.1
�������캯��: ��һ������������һ���������͡�
ʲôʱ��ʹ�������������һ������ĳ�Ա���Ƹ���һ���������������󲻻��໥�漰��ʱ��

#### ��ϰ13.2
```c++
//Sales_data:: Sales_data(Sales_data rhs);
//��ȷ�Ŀ������캯��
Sales_data::Sales_data(const Sales_data& rhs);
```
�����ֵ���ݵĻ� ������ѭ����

#### ��ϰ13.3
~~~c++
class StrBlob{
    private:
        shared_ptr<vector<string>> data;
};
//����StrBlob�ĵײ���һ��ָ��ָ�룬�����ǿ�����ʱ�� ������+1��

class StrBlobPtr{
    private:
        weak_ptr<vector<string>> ps;
}
//StrBlobPtr�ĵײ���һ�� weak_ptr��һ����ָ��,�䲢�������� StrBlob��������
~~~
 ���� StrBlob ����
1. �ײ���ƣ�
StrBlob �ڲ�ʹ�� std::shared_ptr<std::vector<std::string>> ����̬������ַ���������

2. ������Ϊ��
������һ�� StrBlob ����ʱ���� StrBlob b2 = b1;����

���úϳɵĿ������캯���������ڲ��� shared_ptr��

shared_ptr �����ü������� 1��

ԭ������¶�����ͬһ���ײ� vector��

3. �����

�޸��������� vector�������/ɾ���ַ�������Ӱ����һ������

������ StrBlob ��������ʱ��vector ���ڴ�Ż��ͷš�

 ���� StrBlobPtr ����
1. �ײ���ƣ�
StrBlobPtr �ڲ�������

std::weak_ptr<std::vector<std::string>>���۲� StrBlob �� vector�����������ü�������

size_t curr����¼��ǰԪ���±ꡣ

2. ������Ϊ��
������һ�� StrBlobPtr ����ʱ���� StrBlobPtr p2 = p1;����

���úϳɵĿ������캯�������� weak_ptr �� curr ֵ��

weak_ptr �Ŀ������ı����ü�������Ӱ�� vector ���������ڣ���

�¶�����ԭ����ָ����ͬ�� vector ���±�λ�á�

3. �����

���� StrBlobPtr ��������ƶ����� ++p1 ��Ӱ�� p2 ���±꣩��

���ԭ StrBlob �����٣����й����� StrBlobPtr ���⵽ vector ���ͷţ�ͨ�� expired()����


#### ��ϰ13.4
~~~c++
//Pointͷ�ļ�
#ifndef _POINT_H_
#define _POINT_H_
#include <iostream>
class Point{
    private:
        int x;  
        int y;
    public:
        Point(int x, int y);
        Point(const Point& p);
};

Point::Point(int x, int y):x(x), y(y){
    std::cout << "Constructor called" << std::endl;
}

Point::Point(const Point& p):x(p.x), y(p.y){
    std::cout << "Copy constructor called" << std::endl;
}

#endif _POINT_H_

//main

#include "Point.h"
#include "include/HasPtr.h"
#include <iostream>

Point global(3,5);

Point foo_bar(Point p) {
    Point local = p , *heap = new Point(global); // heap = &local;
    *heap = local;
    // Point pa[4] = {local, *heap};   
    return *heap;
}

int main() {
    // // ����һ��Point����p1������Ϊ(1, 2)
    // Point p1(1, 2);
    // // ����foo_bar����������p1����
    // foo_bar(p1);
    // // �ȴ��û����룬��ֹ���������˳�


    std::cin.get();
}
~~~
1. ֵ���ݵ�(Point arg)
2. Point local = arg;
3. Point *heap = new Point(global);
4. returan *heap;

#### ��ϰ13.5
~~~c++
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
~~~

#### ��ϰ13.6
