#include <iostream>

#define MAX_NUM 100
#define DIR_NUM 2

using namespace std;

int n, m;
int grid[MAX_NUM][MAX_NUM];
bool visited[MAX_NUM][MAX_NUM];

bool InRange(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}

bool CanGo(int x, int y) {
    if (!InRange(x, y))
        return false;

    if (visited[x][y] || grid[x][y] == 0)
        return false;

    return true;
}

void DFS(int x, int y) {
    int dx[DIR_NUM] = { 0, 1 };
    int dy[DIR_NUM] = { 1, 0 };

    for (int i = 0; i < DIR_NUM; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (CanGo(new_x, new_y)) {
            visited[new_x][new_y] = 1;
            DFS(new_x, new_y);
        }
    }

}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    visited[0][0] = 1;
    DFS(0, 0);

    cout << visited[n - 1][m - 1];
    return 0;
}