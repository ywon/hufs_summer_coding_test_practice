#include <iostream>
using namespace std;

int main() {
	int arr[100][100] = {};
	int n, r, c;

	cin >> n >> r >> c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };

	int row = r - 1;
	int col = c - 1;

	cout << arr[row][col] << " ";

	while (1) {
		int answer = 0;
		for (int i = 0; i < 4; i++) {
			if (row + dx[i] >= 0 && row + dx[i] < n && col + dy[i] >= 0 && col + dy[i] < n) {
				if (arr[row + dx[i]][col + dy[i]] > arr[row][col]) {
					row += dx[i];
					col += dy[i];
					answer = arr[row][col];
					cout << answer << " ";
					break;
				}
			}
			else {
				continue;
			}
			
		}
		if (answer == 0) {
			break;
		}

	}
	
}