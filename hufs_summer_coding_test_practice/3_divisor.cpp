#include <iostream>
using namespace std;
int divisor_counting(int n) {
	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			cnt++;
		}
	}
	return cnt;
}
int main() {
	int start, end;
	int answer=0;
	cin >> start >> end;

	for (int i = start; i <= end; i++) {
		if (divisor_counting(i) == 3) {
			answer++;
		}
	}

	cout << answer;
}