#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int price[1000] = {};
	vector<int> diff;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> price[i];
	}

	int max = 0;
	for (int i = 1; i < n ; i++) {
		for (int j = 0; j < i; j++) {
			int profit = price[i] - price[j];
			if (profit > max) {
				max = profit;
			}
		}
	}

	cout << max;
}