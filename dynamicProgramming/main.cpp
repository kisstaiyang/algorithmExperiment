#include <iostream>
#include <vector>

using namespace std;

// һ��������ֻ�����º������ƶ���ÿ��ֻ���ƶ�һ�������һ���㷨�����ӣ�0��0���ƶ�����m, n���ж�����·��


/*******************************************************************************************************************************
 * @description�� ��(0,0)��(m,n)��·������
 * @param��m	 ��
 * @param��n	 ��
 * @return�� ���ص���(m,n)��·������
 */
int uniquePaths(int m, int n) {
	// ����һ����СΪ(m+1) x (n+1)�Ķ�ά����
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

	// ��ʼ�����
	dp[0][0] = 1;

	// ���dp����
	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= n; ++j) {
			// ���������㣬����·������
			if (i > 0) {
				dp[i][j] += dp[i - 1][j];
			}
			if (j > 0) {
				dp[i][j] += dp[i][j - 1];
			}
		}
	}

	// ���ص���(m,n)��·������
	return dp[m][n];
}




int main() {
	int m, n;
	cout << "������Ŀ�ĵ�����(m, n): ";
	cin >> m >> n;

	int result = uniquePaths(m, n);
	cout << "��(0,0)��(" << m << "," << n << ")��·��������: " << result << endl;

	return 0;
}
