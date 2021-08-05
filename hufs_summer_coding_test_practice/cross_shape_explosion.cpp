#include <iostream>
using namespace std;

int main() {
	int n;
	int arr[201][201] = {};
	//int temp[201][201] = {0,};
	int r, c;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> r >> c;
	int num = arr[r][c]-1;

	arr[r][c] = 0;

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if()
		}
	}

}