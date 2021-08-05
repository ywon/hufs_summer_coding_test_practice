#include <iostream>
using namespace std;

int n;
int arr[20][20] = {};

int how_many_gold(int row, int col) {
	int sum = 0;
	for (int i = row; i < row + 3; i++) {
		for (int j = col; j < col + 3; j++) {
			sum += arr[i][j];
		}
	}

	return sum;
}

int main() {
	int max = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i <= n - 3; i++) {
		for (int j = 0; j <= n - 3; j++) {
			if (how_many_gold(i, j) > max) {
				max = how_many_gold(i, j);
			}
		}
	}

	cout << max;

}