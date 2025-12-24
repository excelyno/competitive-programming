#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int nilaiMaksimum = 0;
    vector<int> dataInput(n);
    for(int i = 0; i < n;i++){
        cin >> dataInput[i];
        if(dataInput[i] > nilaiMaksimum){
            nilaiMaksimum = dataInput[i];
        }
    }
    vector<int> frequensi(nilaiMaksimum + 1, 0);
    for(int i =0; i < n; i++){
        int angka = dataInput[i];
        frequensi[angka]++;
    }
    int angkaTerbanyak = 0;
    int jumlahMuncul = 0;

    for(int i = 0; i <= nilaiMaksimum; i++){
        if(frequensi[i] > jumlahMuncul){
            jumlahMuncul = frequensi[i];
            angkaTerbanyak = i;
        }
    }
    cout << "angka terbanyak adalah : " << angkaTerbanyak << endl;
    cout << "jumlah angka tersebut adalah : " << jumlahMuncul << endl;
}


int main(){
    solve();
    return 0;
}
