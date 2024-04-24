/*
* 有一个三位数, 个位数字比百位数字大, 百位数字又比十位数字大, 并且各位数字之和等于各位数字相乘之积,
* 设计一个算法用穷举法求此三位数。
*/

#include <iostream>

using namespace std;


/*******************************************************************************************************************************
 * @description：判断一个数是否满足条件
 * @param：num
 * @return：
 */
bool isConditionMet(int num)
{
	int units = num % 10;
	int tens = (num / 10) % 10;
	int hundreds = num / 100;

	return units > hundreds && hundreds > tens && (units + tens + hundreds) == (units * tens * hundreds);
}



void findNumber()
{
	for (int num = 100; num < 1000; ++num) {
		if (isConditionMet(num)) {
			cout << "满足条件的三位数是：" << num << endl;
			return;
		}
	}
	cout << "未找到满足条件的三位数。" << endl;
}


