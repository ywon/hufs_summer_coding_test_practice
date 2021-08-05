#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[2000] = {};

	for (int i = 0; i < 2 * n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + (n * 2));

	int max = arr[0] + arr[2 * n - 1];
	for (int i = 1; i < n; i++) {
		if (arr[i] + arr[2 * n - i - 1] > max) {
			max = arr[i] + arr[2 * n - i - 1];
		}
	}
	cout << max;
}