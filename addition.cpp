#include <iostream>
using namespace std;


int result;
int a;
int b;
int Addition(int a, int b){
    result = a + b;
    return result;
}

int main(){
    cin >> a >> b;
    Addition(a,b);
    cout << result;
}