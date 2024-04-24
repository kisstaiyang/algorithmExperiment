/*
* 有一群鸡和一群兔,它们的只数相同,它们的脚数都是三位数,且这两个三位数的各位数字只能是0、1、2、3、4、5。
* 设计一个算法用蛮力法求鸡和免各有多少只?它们的脚数各是多少?
*/



#include <iostream>
using namespace std;


/*******************************************************************************************************************************
 * @description：判断一个数是否满足条件
 * @param：num
 * @return：
 */
bool isValid(int num) {
	while (num > 0) {
		int digit = num % 10;
		if (digit > 5) {
			return false;
		}
		num /= 10;
	}
	return true;
}



void chickenAndRabbit() {
	for (int chicken = 50; chicken < 500; ++chicken) {
		for (int rabbit = 50; rabbit < 250; ++rabbit) {
			if (chicken + rabbit == chicken * 2 &&
				isValid(chicken * 2) && isValid(rabbit * 4)) {
				cout << "鸡有 " << chicken << " 只，兔子有 " << rabbit << " 只" << endl;
				cout << "鸡有 " << chicken * 2 << " 只脚，兔子有 " << rabbit * 4 << " 只脚" << endl;
				cout << endl;
			}
		}
	}
}


