#include <iostream>
#include <algorithm>

#define MAX_N 50
#define MAX_M 50
#define MAX_HEIGHT 100
#define DIR_NUM 4

using namespace std;

int n, m;
int grid[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M];
int zone_num;

void InitializeVisited() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            visited[i][j] = false;
}


bool InRange(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}

bool CanGo(int x, int y, int k) {
    if (!InRange(x, y))
        return false;

    if (visited[x][y] || grid[x][y] <= k)
        return false;

    return true;
}

void DFS(int x, int y, int k) {
    int dx[DIR_NUM] = { 0, 1, 0, -1 };
    int dy[DIR_NUM] = { 1, 0, -1, 0 };

    for (int dir = 0; dir < DIR_NUM; dir++) {
        int new_x = x + dx[dir];
        int new_y = y + dy[dir];

        if (CanGo(new_x, new_y, k)) {
            visited[new_x][new_y] = true;
            DFS(new_x, new_y, k);
        }
    }
}

void GetZoneNum(int k) {
    zone_num = 0;
    InitializeVisited();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (CanGo(i, j, k)) {
                visited[i][j] = true;
                zone_num++;
                DFS(i, j, k);
            }
        }
}

int main() {
    int max_zone_num = -1;
    int answer_k = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    for (int k = 1; k <= MAX_HEIGHT; k++) {
        GetZoneNum(k);
        cout << zone_num << " ";
        if (zone_num > max_zone_num) {
            max_zone_num = zone_num;
            answer_k = k;
        }
    }

    cout << answer_k << " " << max_zone_num;
    return 0;
}