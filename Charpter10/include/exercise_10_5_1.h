
/* 练习 10.38
 *   5个迭代器类别
 *       1. 输入迭代器 只读，不屑 单遍扫描，只递增 ++，==、！=、*、->
 *       2. 输出迭代器 只写，不读 单遍扫描，只递增 ++、*
 *       3. 前向迭代器 可读写 多遍扫描、只能沿着一个方向移动 上述所有
 *       4. 双向迭代器 可读写 多遍扫描、 可以--、++
 *       5. 随机访问迭代器 可读写 多变扫描 上述所有 还可以 it+n it-n
 */

/*  练习10.39
    list的迭代器属于 双向迭代器 list的迭代器不能满足 it+n的操作
   因为数组存储不连贯 vector的迭代器属于随机访问迭代器 数组存储连贯 可以快速访问
*/

/* 练习10.40
    需要 输入迭代器来读取数据
    需要 输出迭代器来输出数据
*/

/*  10.5.3节练习

练习 10.41
    replace(beg.end,old_val,new_val) 在[beg,end)范围内的 old_val 替换成 new_val
    replace_if(beg,end,pred,new_val) 在[beg,end)范围内的 符合 pred(谓词)
的替换成 new_val replace_copy(beg,end,dest,old_val,new_val) 在[beg,end)范围内的
如果是等于old_val的 替换成new_val然后 复制到 dest
    replace_copy_if(beg,end,dest,pred,new_val) 在[beg,end)范围内
如果符合pred(谓词)替换成new_val然后 复制到 dest

*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#define LOG() std::cout << std::endl

bool isSmaller(int i) { return i < 2; }

void replace_test() {
  std::vector<int> before = {1, 3, 6, 8, 9, 10}, dest;

  auto func = [](int i) { std::cout << i << " "; };

  std::for_each(before.cbegin(), before.cend(), func);
  LOG();

  auto beg = before.begin();
  auto end = before.end();

  //   std::replace(beg, end, 6, 777);
  //   std::for_each(before.cbegin(), before.cend(), func);
  //   LOG();
  //     std::replace_if(beg, end, isSmaller, 777);
  //     std::for_each(before.cbegin(), before.cend(), func);
  //   LOG();
//   std::replace_copy(beg, end, std::back_inserter(dest), 10, 777);
//   std::for_each(before.cbegin(), before.cend(), func);
//   LOG();
//   std::for_each(dest.cbegin(), dest.cend(), func);
//   LOG();
    std::replace_copy_if(beg, end, std::back_inserter(dest), isSmaller, 777);
    std::for_each(dest.cbegin(), dest.cend(), func);
}