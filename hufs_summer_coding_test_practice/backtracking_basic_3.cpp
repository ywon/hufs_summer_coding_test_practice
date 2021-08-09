#include <iostream>

#define MAX_NUM 10

using namespace std;

int n, m;
bool visited[MAX_NUM + 1];

void PrintCombination() {
    for (int i = 1; i <= n; i++)
        if (visited[i])
            cout << i << " ";
    cout << endl;

}

void FindCombination(int cnt, int last_num) {
    if (cnt == m) {
        PrintCombination();
        return;
    }

    for (int i = last_num + 1; i <= n; i++) {
        visited[i] = true;
        FindCombination(cnt + 1, i);
        visited[i] = false;
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        visited[i] = true;
        FindCombination(1, i);
        visited[i] = false;
    }

    return 0;
}