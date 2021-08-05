#include <iostream>
using namespace std;
int n, t;
int arr[3][200] = {};

void move() {
	for (int i = 0; i < 3; i++) {
		for (int j = n - 2; j >= 0; j--) {
			arr[i][j+1] = arr[i][j];
		}
	}
}
int main() {
	
	cin >> n >> t;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	
	while (t--) {
		int temp_1 = arr[0][n - 1];
		int temp_2 = arr[1][n - 1];
		int temp_3 = arr[2][n - 1];

		move();

		arr[0][0] = temp_3;
		arr[1][0] = temp_1;
		arr[2][0] = temp_2;

	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			cout <<  arr[i][j] <<" ";
		}
		cout << endl;
	}

}