#include <iostream>
using namespace std;

int main() {
	int n;
	int arr[100][100] = {};
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int j = 0; j < n; j++) {
		for (int i = n - 1; i >= 0; i--) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}