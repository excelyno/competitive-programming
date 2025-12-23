#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    if(n <= 0) return 0;
    
    int dataArray[n];
    int result = 0;
    
    for (int i = 0; i < n; i++){
        cin >> dataArray[i];
        result += dataArray[i];
    }
    
    double average = (double)result / n;
    cout << average;
    
    return 0;
}