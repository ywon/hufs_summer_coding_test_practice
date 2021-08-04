#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
    int answer = 0;
    while (n > 0) {
        answer = answer * 10 + n % 10;
        n /= 10;
    }

    cout << answer;
    return 0;
}