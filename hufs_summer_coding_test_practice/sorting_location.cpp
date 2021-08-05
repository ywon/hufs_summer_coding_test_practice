#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_NUM 1000

using namespace std;

int main() {
    int n, num_cache;
    int answer[MAX_NUM];
    vector<pair<int, int> > numbers;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num_cache;
        numbers.push_back(make_pair(num_cache, i));
    }

    sort(numbers.begin(), numbers.end());

    for (int i = 0; i < n; i++)
        answer[numbers[i].second] = i + 1;

    for (int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }

    return 0;
}