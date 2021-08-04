#include <iostream>
#include <string>
using namespace std;

string input;
string find_str;

bool IsMatch(int s_idx1, int e_idx1, int s_idx2, int e_idx2) {
	for (int i = s_idx1, j = s_idx2; i <= e_idx1 && j <= e_idx2;
		i++, j++) {
		if (input[i] != find_str[j])
			return false;
	}

	return true;
}

int main() {
	cin >> input;
	cin >> find_str;

	int input_length = input.size();
	int find_length = find_str.size();

	for (int i = 0; i < input_length; i++) {
		if (i + find_length - 1 >= input_length)
			continue;

		if (IsMatch(i, i + find_length - 1, 0, find_length - 1)) {
			cout << i;
			
			return 0;
		}
	}

	cout << -1;

	return 0;

}