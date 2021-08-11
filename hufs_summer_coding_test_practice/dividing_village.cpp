#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_NUM 25
using namespace std;

int n;
int grid[MAX_NUM + 1][MAX_NUM + 1];
bool visited[MAX_NUM + 1][MAX_NUM + 1];
vector<int> people_nums;
int people_num;

bool InRange(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < n;
}

bool CanGo(int x, int y) {
	if (!InRange(x, y))
		return false;

	if (visited[x][y] || grid[x][y] == 0)
		return false;

	return true;
}

void DFS(int x, int y) {
	int dx[4] = { -1,1,0, 0 };
	int dy[4] = { 0,0,-1, 1 };

	for (int i = 0; i <4; i++) {
		int new_x = x + dx[i];
		int new_y = y + dy[i];

		if (CanGo(new_x, new_y)) {
			visited[new_x][new_y] = true;
			people_num++;
			DFS(new_x, new_y);
		}
	}

}

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (CanGo(i, j)) {
				visited[i][j] = true;
				people_num = 1;

				DFS(i, j);

				people_nums.push_back(people_num);
			}
		}
	}

	sort(people_nums.begin(), people_nums.end());

	cout << (int)people_nums.size() << endl;
	for (int i = 0; i < (int)people_nums.size(); i++)
		cout << people_nums[i] << endl;

	return 0;
}