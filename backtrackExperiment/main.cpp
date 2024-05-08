#include <iostream>
#include <vector>

using namespace std;


/*******************************************************************************************************************************
 * @description：检查在给定的行和列上是否可以放置皇后
 * @param：board 棋盘
 * @param：row	 行
 * @param：col	 列
 * @param：N		 棋盘大小
 * @return：
 */
bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
	// 检查同一列
	for (int i = 0; i < row; ++i) {
		if (board[i][col] == 1) return false;
	}

	// 检查左上角对角线
	for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
		if (board[i][j] == 1) return false;
	}

	// 检查右上对角线
	for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
		if (board[i][j] == 1) return false;
	}

	return true;
}




/*******************************************************************************************************************************
 * @description：主要函数，用于解决N皇后问题
 * @param：board	 棋盘
 * @param：row	 行
 * @param：N		 棋盘大小
 * @return：
 */
bool solveNQueensUtil(vector<vector<int>>& board, int row, int N) {
	if (row == N) return true;

	for (int col = 0; col < N; ++col) {
		if (isSafe(board, row, col, N)) {
			board[row][col] = 1;

			if (solveNQueensUtil(board, row + 1, N)) {
				return true;
			}

			board[row][col] = 0; // 回溯
		}
	}

	return false;
}




/*******************************************************************************************************************************
 * @description：
 * @param：N
 */
void solveNQueens(int N) {
	vector<vector<int>> board(N, vector<int>(N, 0));

	if (solveNQueensUtil(board, 0, N)) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
	}
	else {
		cout << "不存在解决方案" << endl;
	}
}






int main() {
	int N;
	cout << "输入棋盘大小: ";
	cin >> N;

	solveNQueens(N);

	return 0;
}
