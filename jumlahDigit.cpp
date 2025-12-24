#include <iostream>

using namespace std;

int main(){
    string inputUser;
    cin >> inputUser;
    double result = 0;
    for(int i = 0; i < inputUser.length(); i++){
        char c = inputUser[i];
        result += (c - '0');
    }
    cout << result;
}