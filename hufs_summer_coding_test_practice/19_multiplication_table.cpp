#include <iostream>
using namespace std;
int main() {
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j+=2) {
			if (j == 19) {
				cout << i << " * " << j << " = " << i * j << endl;
			}
			else {
				cout << i << " * " << j << " = " << i * j << " / ";
				cout << i << " * " << j + 1 << " = " << i * (j + 1) << endl;
			}
		}
	}
}