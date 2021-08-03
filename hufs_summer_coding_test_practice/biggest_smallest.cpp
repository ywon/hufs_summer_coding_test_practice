#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int arr[100] = { 0, };
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr[i] = num;
	}

	int min = arr[0];
	int cnt = 1;

	for (int i = 1; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
			cnt = 1;
		}
		else if (min == arr[i]) {
			cnt++;
		}
	}

	cout << min << " " << cnt;
}