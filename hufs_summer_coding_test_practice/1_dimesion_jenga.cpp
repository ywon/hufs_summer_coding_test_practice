#include <iostream>

#define MAX_N 100

using namespace std;

int n;
int numbers[MAX_N];

int end_of_array;

void CutArray(int start_idx, int end_idx) {
    int temp_arr[MAX_N];
    int end_of_temp_array = 0;

    for (int i = 0; i < end_of_array; i++)
        if (i < start_idx || i > end_idx)
            temp_arr[end_of_temp_array++] = numbers[i];

    for (int i = 0; i < end_of_temp_array; i++)
        numbers[i] = temp_arr[i];

    end_of_array = end_of_temp_array;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    end_of_array = n;

    for (int k = 0; k < 2; k++) {
        int s, e;
        cin >> s >> e; s--; e--;
        CutArray(s, e);
    }

    cout << end_of_array << endl;
    for (int i = 0; i < end_of_array; i++)
        cout << numbers[i] << endl;

    return 0;
}