#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	int arr[1000] = {};
	int count[1000] = {};
	int answer = -1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		count[arr[i] - 1]++;
	}

	for (int i = 999; i >= 0; i--) {
		if (count[i] == 1) {
			answer = i + 1;
			break;
		}
	}
	cout << answer;
}