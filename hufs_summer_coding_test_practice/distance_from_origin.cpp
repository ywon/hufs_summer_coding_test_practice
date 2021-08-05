#include <iostream>
#include <vector>
#include <algorithm>
#include<cstdlib>
using namespace std;

int main() {
	int n;
	vector<pair<int, int> >distance_seq;
	int answer[1000] = {};
	cin >> n;
	int x, y, distance;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		distance = abs(x) + abs(y);
		distance_seq.push_back(make_pair(distance, i+1));
	}

	sort(distance_seq.begin(), distance_seq.end());

	for (int i = 0; i < n; i++) {
		cout << distance_seq[i].second << endl;

	}
}