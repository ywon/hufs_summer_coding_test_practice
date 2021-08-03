#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string st;

string num_1() {
	char front = st[0];
	for (int i = 0; i < st.length()-1; i++) {
		st[i] = st[i + 1];
	}
	st[st.length() - 1] = front;

	return st;
}

string num_2() {
	char end = st[st.length() - 1];
	for (int i = st.length()-1; i>0; i--) {
		st[i] = st[i - 1];
	}
	st[0] = end;

	return st;
}

string num_3() {
	reverse(st.begin(), st.end());

	return st;
}

int main() {
	int q, n;
	int arr[1000];
	cin >> st >> q;

	for (int i = 0; i < q; i++) {
		cin >> n;
		if (n == 1) {
			cout << num_1() << endl;
		}
		else if (n == 2) {
			cout << num_2() << endl;
		}
		else {
			cout << num_3() << endl;
		}
	}


}