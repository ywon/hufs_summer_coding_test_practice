#include <iostream>
#include <vector>
using namespace std;

int n, m;
int arr[100] = {};
int temp[100] = {};
vector<pair<int, int>> bomb;

void array_copy() { //배열 복사 함수
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] != 0) {
			temp[index] = arr[i];
			index++;
		}
	}
}

bool any_bomb_left() { //더 터트릴 폭탄이 남았는지 확인
	int count = 0;
	for (int i = 0; i < n-1; i++) {
		if (temp[i] == temp[i + 1]) {
			count++;
		}
	}

	if (count == 0) {
		return false;
		
	else {
		return true;
	}
}

void explosion() {
	int count = 0;
	for (int i = 2; i < n; i++) {
		if (arr[i - 2] == arr[i - 1]) {
			count++;
			if (arr[i - 1] != arr[i]) {
				bomb.push_back(make_pair(arr[i - 1], count));
				count = 0;
			}

		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < bomb.size(); j++) {
			if (arr[i] == bomb[j].first && bomb[j].second >= m - 1) {
				arr[i] = 0;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	while (1) {
		if (any_bomb_left() == true) {
			explosion();
			array_copy();

		}
		else {
			break;
		}
	}
	


	//cout << index << endl;
	//for (int i = 0; i < index; i++) {
		//cout << temp[i] << endl;
	//}
}