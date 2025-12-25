#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::cin;
using std::vector;
using std::endl;
using std::sort;

void solver(){
    int n;
    if(!(cin >> n))return;

    vector<int> koordinat;
    koordinat.reserve(n);
    
    int temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        koordinat.push_back(temp); 
    }
    sort(koordinat.begin(), koordinat.end());
    int jarakMinimum = koordinat[1] - koordinat[0];
    for(int i = 1; i < n; i++){
        if (koordinat[i] - koordinat[i - 1] < jarakMinimum){
            jarakMinimum = koordinat[i] - koordinat[i -1];
        }
    }
    cout << jarakMinimum;
}


int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solver();
}
