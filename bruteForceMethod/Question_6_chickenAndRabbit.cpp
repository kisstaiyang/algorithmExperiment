/*
* ��һȺ����һȺ��,���ǵ�ֻ����ͬ,���ǵĽ���������λ��,����������λ���ĸ�λ����ֻ����0��1��2��3��4��5��
* ���һ���㷨���������󼦺�����ж���ֻ?���ǵĽ������Ƕ���?
*/



#include <iostream>
using namespace std;


/*******************************************************************************************************************************
 * @description���ж�һ�����Ƿ���������
 * @param��num
 * @return��
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
				cout << "���� " << chicken << " ֻ�������� " << rabbit << " ֻ" << endl;
				cout << "���� " << chicken * 2 << " ֻ�ţ������� " << rabbit * 4 << " ֻ��" << endl;
				cout << endl;
			}
		}
	}
}


