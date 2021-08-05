#include <iostream>

using namespace std;

int n, m;
int answer[100][100] = {};
int cnt = 1;

void FillDiagonal(int curr_row, int curr_col) {
    while (curr_col >= 0 && curr_row < n) {
        answer[curr_row][curr_col] = cnt;
        curr_row++;
        curr_col--;
        cnt++;
    }
    return;
}

int main() {
    cin >> n >> m;


    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++)
            if (answer[row][col] == 0)
                FillDiagonal(row, col);
    }

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++)
            cout << answer[row][col] << " ";
        cout << endl;
    }

    return 0;
}