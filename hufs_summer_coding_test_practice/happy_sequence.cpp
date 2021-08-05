#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100

int n, m;
int grid[MAX_N][MAX_N];

int seq[MAX_N];

bool IsHappySequence() {
    int consecutive_count = 1, max_ccnt = 1;
    for (int i = 1; i < n; i++) {
        if (seq[i - 1] == seq[i])
            consecutive_count++;
        else
            consecutive_count = 1;

        max_ccnt = max(max_ccnt, consecutive_count);
    }

    return max_ccnt >= m;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    int num_happy = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            seq[j] = grid[i][j];

        if (IsHappySequence())
            num_happy++;
    }

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++)
            seq[i] = grid[i][j];

        if (IsHappySequence())
            num_happy++;
    }

    cout << num_happy;

    return 0;
}