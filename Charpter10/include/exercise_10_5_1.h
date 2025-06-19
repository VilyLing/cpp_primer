
/* ��ϰ 10.38
 *   5�����������
 *       1. ��������� ֻ������м ����ɨ�裬ֻ���� ++��==����=��*��->
 *       2. ��������� ֻд������ ����ɨ�裬ֻ���� ++��*
 *       3. ǰ������� �ɶ�д ���ɨ�衢ֻ������һ�������ƶ� ��������
 *       4. ˫������� �ɶ�д ���ɨ�衢 ����--��++
 *       5. ������ʵ����� �ɶ�д ���ɨ�� �������� ������ it+n it-n
 */

/*  ��ϰ10.39
    list�ĵ��������� ˫������� list�ĵ������������� it+n�Ĳ���
   ��Ϊ����洢������ vector�ĵ���������������ʵ����� ����洢���� ���Կ��ٷ���
*/

/* ��ϰ10.40
    ��Ҫ �������������ȡ����
    ��Ҫ ������������������
*/

/*  10.5.3����ϰ

��ϰ 10.41
    replace(beg.end,old_val,new_val) ��[beg,end)��Χ�ڵ� old_val �滻�� new_val
    replace_if(beg,end,pred,new_val) ��[beg,end)��Χ�ڵ� ���� pred(ν��)
���滻�� new_val replace_copy(beg,end,dest,old_val,new_val) ��[beg,end)��Χ�ڵ�
����ǵ���old_val�� �滻��new_valȻ�� ���Ƶ� dest
    replace_copy_if(beg,end,dest,pred,new_val) ��[beg,end)��Χ��
�������pred(ν��)�滻��new_valȻ�� ���Ƶ� dest

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