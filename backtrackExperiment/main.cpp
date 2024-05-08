#include <iostream>
#include <vector>

using namespace std;


/*******************************************************************************************************************************
 * @description������ڸ������к������Ƿ���Է��ûʺ�
 * @param��board ����
 * @param��row	 ��
 * @param��col	 ��
 * @param��N		 ���̴�С
 * @return��
 */
bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
	// ���ͬһ��
	for (int i = 0; i < row; ++i) {
		if (board[i][col] == 1) return false;
	}

	// ������ϽǶԽ���
	for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
		if (board[i][j] == 1) return false;
	}

	// ������϶Խ���
	for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
		if (board[i][j] == 1) return false;
	}

	return true;
}




/*******************************************************************************************************************************
 * @description����Ҫ���������ڽ��N�ʺ�����
 * @param��board	 ����
 * @param��row	 ��
 * @param��N		 ���̴�С
 * @return��
 */
bool solveNQueensUtil(vector<vector<int>>& board, int row, int N) {
	if (row == N) return true;

	for (int col = 0; col < N; ++col) {
		if (isSafe(board, row, col, N)) {
			board[row][col] = 1;

			if (solveNQueensUtil(board, row + 1, N)) {
				return true;
			}

			board[row][col] = 0; // ����
		}
	}

	return false;
}




/*******************************************************************************************************************************
 * @description��
 * @param��N
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
		cout << "�����ڽ������" << endl;
	}
}






int main() {
	int N;
	cout << "�������̴�С: ";
	cin >> N;

	solveNQueens(N);

	return 0;
}
