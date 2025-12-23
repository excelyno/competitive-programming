#include <iostream>
using namespace std;

const int n = 3;
int atu[n];

int main() {
    for (int i = 0; i < n; i++) {
        cin >> atu[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (atu[j] < atu[j + 1]) {
                int temp = atu[j];
                atu[j] = atu[j + 1];
                atu[j + 1] = temp;
            }
        }
    }
    for (int k = 0; k < n; k++) {
        cout << atu[k] << endl;
    }

    return 0;
}