#include <iostream>
#include <vector>

using namespace std;

// 一个机器人只能向下和向右移动，每次只能移动一步，设计一个算法求它从（0，0）移动到（m, n）有多少条路径


/*******************************************************************************************************************************
 * @description： 从(0,0)到(m,n)的路径总数
 * @param：m	 行
 * @param：n	 列
 * @return： 返回到达(m,n)的路径总数
 */
int uniquePaths(int m, int n) {
	// 创建一个大小为(m+1) x (n+1)的二维数组
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

	// 初始化起点
	dp[0][0] = 1;

	// 填充dp数组
	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= n; ++j) {
			// 如果不是起点，计算路径总数
			if (i > 0) {
				dp[i][j] += dp[i - 1][j];
			}
			if (j > 0) {
				dp[i][j] += dp[i][j - 1];
			}
		}
	}

	// 返回到达(m,n)的路径总数
	return dp[m][n];
}




int main() {
	int m, n;
	cout << "请输入目的地坐标(m, n): ";
	cin >> m >> n;

	int result = uniquePaths(m, n);
	cout << "从(0,0)到(" << m << "," << n << ")的路径总数是: " << result << endl;

	return 0;
}
