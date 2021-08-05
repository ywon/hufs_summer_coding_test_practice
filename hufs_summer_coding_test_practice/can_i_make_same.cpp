#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	int size_a = a.size();
	int size_b = b.size();

	int arr_a[128] = {};
	int arr_b[128] = {};
	int cnt = 0;

	if (size_a == size_b) {
		for (int i = 0; i < size_a; i++) {
			arr_a[(int)a[i]]++;
			arr_b[(int)b[i]]++;
		}

		for (int i = 0; i < 128; i++) {
			if (arr_a[i] == arr_b[i]) {
				cnt++;
			}
		}
	}
		
	if (cnt == 128) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}