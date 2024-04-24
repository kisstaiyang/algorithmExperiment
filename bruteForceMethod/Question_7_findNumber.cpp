/*
* ��һ����λ��, ��λ���ֱȰ�λ���ִ�, ��λ�����ֱ�ʮλ���ִ�, ���Ҹ�λ����֮�͵��ڸ�λ�������֮��,
* ���һ���㷨����ٷ������λ����
*/

#include <iostream>

using namespace std;


/*******************************************************************************************************************************
 * @description���ж�һ�����Ƿ���������
 * @param��num
 * @return��
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
			cout << "������������λ���ǣ�" << num << endl;
			return;
		}
	}
	cout << "δ�ҵ�������������λ����" << endl;
}


