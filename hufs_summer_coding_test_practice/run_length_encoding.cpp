#include <iostream>
#include <string>
using namespace std;

int main() {
	string a;
	string answer="";
	cin >> a;
	int count[50] = {};
	int cnt = 0;
	char letter[50] = {};
	int i = 0;
	int index = 0;
	int temp = 0;


	while (index < a.length()-1) {

	}

	for (int i = 0; i < temp; i++) {
		answer = answer + letter[i] + to_string(count[i]);
	}

	cout << answer.length() << endl;
	cout << answer;

	return 0;
}