/* ��һ����n�����㣨������Ϊ0~nһ1���Ĵ�Ȩͼ�����ڽӾ�������A��ʾ������
 * ��֦�޽編�����㣺��Ŀ���t�����·�����ȣ��Լ��������·�����ȵ�·������
 */

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int, int> P; // P��ʾһ��pair��first�Ǿ��룬second�ǽڵ���


/*******************************************************************************************************************************
 * @description����֦�޽編�����㣺��Ŀ���t�����·�����ȣ��Լ��������·�����ȵ�·������
 * @param��n		�ڵ����
 * @param��A		�ڽӾ���
 * @param��s		���
 * @param��t		�յ�
 */
void shortest_paths_branch_and_bound(int n, const vector<vector<int>>& A, int s, int t) {
	vector<int> dist(n, INT_MAX);  // �洢����㵽�����������̾���
	vector<int> count(n, 0);       // �洢����㵽������������·������
	dist[s] = 0;
	count[s] = 1;

	priority_queue<P, vector<P>, greater<P>> pq; // С���ѣ����վ�����С����
	pq.push({ 0, s });

	while (!pq.empty()) {
		int d_u = pq.top().first;
		int u = pq.top().second;
		pq.pop();

		// ���ȡ���ľ������֪����̾������������֦��
		if (d_u > dist[u]) continue;

		// ���������� u ���ڵĽڵ� v
		for (int v = 0; v < n; ++v) {
			// �ж��Ƿ��б�
			if (A[u][v] != INT_MAX) {
				int new_dist = d_u + A[u][v];

				if (new_dist < dist[v]) {
					dist[v] = new_dist;
					count[v] = count[u];
					pq.push({ new_dist, v });
				}
				else if (new_dist == dist[v]) {
					count[v] += count[u];
				}
			}
		}
	}

	cout << "����� " << s << " ��Ŀ��� " << t << " �����·������: " << dist[t] << endl;
	cout << "�������·�����ȵ�·������: " << count[t] << endl;
}




int main() {
	int n = 5; // �������
	vector<vector<int>> A = {
		{0, 10, INT_MAX, 30, 100},
		{INT_MAX, 0, 50, INT_MAX, INT_MAX},
		{INT_MAX, INT_MAX, 0, INT_MAX, 10},
		{INT_MAX, INT_MAX, 20, 0, 60},
		{INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0}
	};
	int s = 0; // ���
	int t = 4; // �յ�

	shortest_paths_branch_and_bound(n, A, s, t);

	return 0;
}

