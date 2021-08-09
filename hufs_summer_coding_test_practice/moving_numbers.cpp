#include <iostream>
using namespace std;

int n, m;
int arr[20][20] = {};
int row, col;
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = { -1, 0, 1, 1, 1, 0, -1,-1 };

void location(int num) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == num) {
				row = i;
				col = j;
			}
		}
	}
}

void moving() {
	int max = 0;
	int row_change;
	int col_change;
	
	for (int i = 0; i < 8; i++) {
		int row_temp = row;
		int col_temp = col;
		if (row_temp + dx[i] >= 0 && row_temp + dx[i] < n && col_temp + dy[i] >= 0 && col_temp + dy[i] < n) {
			if (arr[row_temp + dx[i]][col_temp + dy[i]] > max) {
				max = arr[row_temp + dx[i]][col_temp + dy[i]];
				row_change = row_temp + dx[i];
				col_change = col_temp + dy[i];
			}
		}		
	}

	int temp = arr[row][col];
	arr[row][col] = arr[row_change][col_change];
	arr[row_change][col_change] = temp;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	while (m--) {
		for (int i = 1; i <= n * n; i++) {
			location(i);
			moving();
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

}