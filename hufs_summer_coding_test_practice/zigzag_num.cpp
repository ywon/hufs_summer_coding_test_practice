#include <iostream>
using namespace std;

int main() {
	int n, m;
	int num = 0;
	cin >> n >> m;
	int arr[100][100] = { 0, };
	
	for (int i = 0; i < m; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < n; j++) {
				arr[j][i] = num;
				num++;
			}
		}
		else {
			for (int j = n - 1; j >= 0; j--) {
				arr[j][i] = num;
				num++;
			}
		}
		
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}