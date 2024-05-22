/* 有一个含n个顶点（顶点编号为0~n一1）的带权图，用邻接矩阵数组A表示，采用
 * 分枝限界法求从起点：到目标点t的最短路径长度，以及具有最短路径长度的路径条数
 */

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int, int> P; // P表示一个pair，first是距离，second是节点编号


/*******************************************************************************************************************************
 * @description：分枝限界法求从起点：到目标点t的最短路径长度，以及具有最短路径长度的路径条数
 * @param：n		节点个数
 * @param：A		邻接矩阵
 * @param：s		起点
 * @param：t		终点
 */
void shortest_paths_branch_and_bound(int n, const vector<vector<int>>& A, int s, int t) {
	vector<int> dist(n, INT_MAX);  // 存储从起点到各个顶点的最短距离
	vector<int> count(n, 0);       // 存储从起点到各个顶点的最短路径条数
	dist[s] = 0;
	count[s] = 1;

	priority_queue<P, vector<P>, greater<P>> pq; // 小顶堆，按照距离最小优先
	pq.push({ 0, s });

	while (!pq.empty()) {
		int d_u = pq.top().first;
		int u = pq.top().second;
		pq.pop();

		// 如果取出的距离比已知的最短距离大，跳过（剪枝）
		if (d_u > dist[u]) continue;

		// 遍历所有与 u 相邻的节点 v
		for (int v = 0; v < n; ++v) {
			// 判断是否有边
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

	cout << "从起点 " << s << " 到目标点 " << t << " 的最短路径长度: " << dist[t] << endl;
	cout << "具有最短路径长度的路径条数: " << count[t] << endl;
}




int main() {
	int n = 5; // 顶点个数
	vector<vector<int>> A = {
		{0, 10, INT_MAX, 30, 100},
		{INT_MAX, 0, 50, INT_MAX, INT_MAX},
		{INT_MAX, INT_MAX, 0, INT_MAX, 10},
		{INT_MAX, INT_MAX, 20, 0, 60},
		{INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0}
	};
	int s = 0; // 起点
	int t = 4; // 终点

	shortest_paths_branch_and_bound(n, A, s, t);

	return 0;
}

