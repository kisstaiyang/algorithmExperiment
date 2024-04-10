#include <iostream>
#include <vector>

using namespace std;

/*******************************************************************************************************************************
 * @description： 模仿二分查找算法，实现三分查找；找到返回目标值的下标，没找到返回-1
 * @param：arr    整数序列
 * @param：left   左下标
 * @param：right  右下标
 * @param：target 目标值
 * @return：
 */
int threePointSearch(vector<int>& arr, int left, int right, int target)
{
	if (left > right) {
		return -1;
	}
	int mid1 = left + (right - left) / 3;
	int mid2 = right - (right - left) / 3;
	if (arr[mid1] == target) {
		return mid1;
	}
	else if (arr[mid2] == target) {
		return mid2;
	}
	else if (target < arr[mid1]) {
		return threePointSearch(arr, left, mid1 - 1, target);
	}
	else if (target > arr[mid2]) {
		return threePointSearch(arr, mid2 + 1, right, target);
	}
	else {
		return threePointSearch(arr, mid1 + 1, mid2 - 1, target);
	}
}



void question_16_main()
{
	vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	cout << "Array: ";
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	int target = 8;
	cout << "Target: " << target << endl;
	int index = threePointSearch(arr, 0, arr.size() - 1, target);
	if (index == -1) {
		cout << "The target value is not found." << endl;
	}
	else {
		cout << "The target value is found at index " << index << "." << endl;
	}
}
