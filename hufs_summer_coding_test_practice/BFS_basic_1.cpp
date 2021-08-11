#include <iostream>
#include <queue>
using namespace std;
#define MAX_NUM 100

int n, m;
int grid[MAX_NUM][MAX_NUM];

queue<pair<int, int> > q;
bool visited[MAX_NUM][MAX_NUM];

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

bool CanGo(int x, int y) {
	if (!InRange(x, y))
		return false;

	if (visited[x][y] || grid[x][y] == 0)
		return false;

	return true;
}

void BFS() {
    while (!q.empty()) {
        pair<int, int> curr_pos = q.front();
        int x = curr_pos.first, y = curr_pos.second;
        q.pop();

        int dx[4] = { 1, -1, 0, 0 };
        int dy[4] = { 0, 0, 1, -1 };

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir], ny = y + dy[dir];

            if (CanGo(nx, ny)) {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

    q.push(make_pair(0, 0));
    visited[0][0] = true;

    BFS();

    cout << visited[n - 1][m - 1];

    return 0;

}