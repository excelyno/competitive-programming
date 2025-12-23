#include <iostream>
using namespace std;

int inputUser;

int main(){
    cin >> inputUser;
    if (inputUser % 2 == 0){
        cout << "bilangan genap";
    } else {
        cout << "bilangan ganjil";
    }
}