#include <iostream>
#include <vector>
using namespace std;

int n;
int grid[101][101];
bool visited[101][101];
int bombbomb;
vector <pair<int,int>> a;

bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool CanGo(int x, int y, int k) {
    if (!InRange(x, y))
        return false;

    if (visited[x][y] || grid[x][y] != k)
        return false;

    return true;
}

void DFS(int x, int y, int k) {
    int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { 1, 0, -1, 0 };

    for (int dir = 0; dir < 4; dir++) {
        int new_x = x + dx[dir];
        int new_y = y + dy[dir];

        if (CanGo(new_x, new_y, k)) {
            visited[new_x][new_y] = true;
            bombbomb++;
            DFS(new_x, new_y, k);
        }
    }
}

void bomb(int k) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (CanGo(i, j, k)) {
                visited[i][j] = true;
                bombbomb = 1;
                DFS(i, j, k);
                a.push_back(make_pair(k, bombbomb));
            }
        }
    }
}

int main() {
    int max_block = 0;
    int bomb_cnt = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

   for (int k = 1; k <= 100; k++) {
        bombbomb = 1;
        bomb(k);
    }
    

   for (int i = 0; i < a.size(); i++) {
       if (a[i].second > 3) {
           bomb_cnt++;
       }
       if (a[i].second > max_block) {
           max_block = a[i].second;
       }
   }
      
   cout << bomb_cnt << " " << max_block ;
}