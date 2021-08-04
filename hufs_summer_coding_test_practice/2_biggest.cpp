#include <iostream>
#include <algorithm>
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

	sort(arr, arr + n);

	cout << arr[n - 1] << " " << arr[n - 2];
}