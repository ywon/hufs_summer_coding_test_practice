#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

#define MAX_N 100
#define MAX_M 100

using namespace std;

int n, m;

int a[MAX_N][MAX_M];

queue<pair<int, int> > q;
bool visited[MAX_N][MAX_M];
int step[MAX_N][MAX_M]; 
                       

int ans = INT_MAX;

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

bool CanGo(int x, int y) {
    return InRange(x, y) && a[x][y] && !visited[x][y];
}

void Push(int nx, int ny, int new_step) {
    q.push(make_pair(nx, ny));
    visited[nx][ny] = true;
    step[nx][ny] = new_step;
}

void FindMin() {
    while (!q.empty()) {
        pair<int, int> curr_pos = q.front();
        int x = curr_pos.first, y = curr_pos.second;
        q.pop();

        int dx[4] = { 1, -1, 0, 0 };
        int dy[4] = { 0, 0, 1, -1 };

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir], ny = y + dy[dir];

            if (CanGo(nx, ny))
                Push(nx, ny, step[x][y] + 1);
        }
    }

    if (visited[n - 1][m - 1])
        ans = step[n - 1][m - 1];
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    Push(0, 0, 0);
    FindMin();

    if (ans == INT_MAX) 
        ans = -1;      

    cout << ans;

    return 0;
}