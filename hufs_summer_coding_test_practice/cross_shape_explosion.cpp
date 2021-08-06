#include <iostream>
using namespace std;


int n;
int arr[201][201] = {};
int temp[201][201] = {0,};
int r, c;

void explosion() {
	int num = arr[r][c] -1 ;
	for (int i = c - num; i <= c + num; i++) {
		if (i >= 1 && i <= n) {
			arr[r][i] = 0;
		}
	}

	for (int i = r - num; i <= r + num; i++) {
		if (i >= 1 && i <= n) {
			arr[i][c] = 0;
		}
		
	}
}

void down(int col) {
	int j = n;
	int i = n;

	for (i = n; i > 0; i--) {
		if (arr[i][col] != 0) {
			temp[j][col] = arr[i][col];
			j--;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	cin >> r >> c;
	explosion();
	
	for (int i = 1; i <= n; i++) {
		down(i);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << temp[i][j] << " ";
		}
		cout << endl;
	}

}