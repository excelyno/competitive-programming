#include <iostream>
using namespace std;

int main() {
    string inputUser;
    cin >> inputUser;

    int countVokal = 0;

    for (int i = 0; i < inputUser.length(); i++) {
        char c = inputUser[i];

        if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o' ||
            c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O') {
            countVokal++;
        }
    }

    cout << countVokal << endl;
    return 0;
}
