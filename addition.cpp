#include <iostream>
using namespace std;


int result;

int Addition(int a, int b){
    result = a + b;
    return result;
}

int main(){
    Addition(5,10);
    cout << result;
}