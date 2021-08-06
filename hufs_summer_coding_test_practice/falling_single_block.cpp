#include <iostream>
using namespace std;

int n, m, k;
int arr[101][101] = {};

bool block(int row) {
	int count_1 = 0;
	int count_2 = 0;
	for (int i = k; i <= m + k - 1; i++) {
		if (arr[row][i] == 0) {
			count_1++;
		}
		if (arr[row + 1][i] == 1) {
			count_2++;
		}
	}

	if (count_1 == m && (count_2 > 0 || row==n)) { return true; }
	else { return false; }
}

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <=n ; i++) {
		if (block(i) == true) {
			for (int j = k; j <= m + k - 1; j++) {
				arr[i][j] = 1;
			}
			break;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	

}