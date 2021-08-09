#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> answer;

int same() {
	int cnt = 0;
	for (int i = 0; i < n-2; i++) {
		if (answer[i] == answer[i + 1] && answer[i + 1] == answer[i + 2]) {
			cnt++;
		}
	}

	if (cnt > 0) {
		return 1;
	}
	else {
		return 0;
	}
}

void print_answer(){
	for (int i = 0; i < (int)answer.size(); i++) {
		cout << answer[i] << " ";
	}
	cout << endl;

}

void combination(int cnt) {
	if (cnt == n) {
		if (same() == 0) {
			print_answer();
		}
		return;
	}

	for (int i = 1; i <= k; i++) {
		answer.push_back(i);
		combination(cnt + 1);
		answer.pop_back();
	}
}
int main() {
	cin >> k >> n;
	combination(0);

	return 0;
}
