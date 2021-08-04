#include <iostream>
using namespace std;

int main() {
	int start, end;
	cin >> start >> end;
	int sum;
	int cnt = 0;
	for (int i = start; i <= end; i++) {
		sum = 0;
		for (int j = 1; j < i; j++) {
			if (i % j == 0) {
				sum += j;
			}
		}
		if (i == sum) {
			cnt++;
		}
	}
	cout << cnt;
}