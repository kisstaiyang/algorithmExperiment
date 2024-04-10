#include <iostream>
#include <vector>

using namespace std;


/*******************************************************************************************************************************
 * @description：分治法求最大值和最小值
 * @param：arr   整数序列
 * @param：left  左下标
 * @param：right 右下标
 * @param：max   最大值
 * @param：min   最小值
 */
void GetMaxAndMinElement(vector<int>& arr, int left, int right, int& max, int& min)
{
	if (left == right) {
		max = arr[left];
		min = arr[left];
	}
	else if (left + 1 == right) {
		max = arr[left] > arr[right] ? arr[left] : arr[right];
		min = arr[left] < arr[right] ? arr[left] : arr[right];
	}
	else {
		int mid = (left + right) / 2;
		int max1, min1, max2, min2;
		GetMaxAndMinElement(arr, left, mid, max1, min1);
		GetMaxAndMinElement(arr, mid + 1, right, max2, min2);
		max = max1 > max2 ? max1 : max2;
		min = min1 < min2 ? min1 : min2;
	}
}



void question_10_main()
{
	vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 8 };
	cout << "Array: ";
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	int max, min;
	GetMaxAndMinElement(arr, 0, arr.size() - 1, max, min);
	cout << "Max: " << max << endl;
	cout << "Min: " << min << endl;
}
