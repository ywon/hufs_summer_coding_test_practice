#include <iostream>

#define DIR_NUM 4
#define MAX_N 20

using namespace std;

int t, n, m;

int a[MAX_N + 1][MAX_N + 1];
int counting[MAX_N + 1][MAX_N + 1];
int next_count[MAX_N + 1][MAX_N + 1];

bool InRange(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

pair<int, int> GetMaxNeighborPos(int curr_x, int curr_y) {
    int dx[DIR_NUM] = { -1, 1, 0, 0 };
    int dy[DIR_NUM] = { 0, 0, -1, 1 };

    int max_num = 0;
    pair<int, int> max_pos;

    for (int i = 0; i < DIR_NUM; i++) {
        int next_x = curr_x + dx[i];
        int next_y = curr_y + dy[i];

        if (InRange(next_x, next_y) && a[next_x][next_y] > max_num) {
            max_num = a[next_x][next_y];
            max_pos = make_pair(next_x, next_y);
        }
    }

    return max_pos;
}


void Move(int x, int y) {
    
    pair<int, int> next_pos = GetMaxNeighborPos(x, y);
    int next_x = next_pos.first, next_y = next_pos.second;


    next_count[next_x][next_y]++;
}



void MoveAll() {

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            next_count[i][j] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (counting[i][j] == 1)
                Move(i, j);


    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            counting[i][j] = next_count[i][j];
}

void RemoveDuplicateMarbles() {

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (counting[i][j] >= 2)
                counting[i][j] = 0;
}

void Simulate() {

    MoveAll();
    RemoveDuplicateMarbles();
}

int main() {
    cin >> n >> m >> t;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        counting[x][y] = 1;
    }

    while (t--)
        Simulate();

    int ans = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ans += counting[i][j];

    cout << ans;
    return 0;
}