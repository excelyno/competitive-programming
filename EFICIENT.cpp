#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// SPECIFIC USING DECLARATIONS
using std::cout;
using std::cin;
using std::vector;
using std::sort;
using std::string;
using std::to_string;

int main() {
    // 1. Optimasi Jalur I/O (Wajib untuk efisiensi tinggi)
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Kita asumsikan input valid agar tidak memperlambat dengan pengecekan berlebih
    if (!(cin >> n)) return 0;

    // 2. INOVASI MEMORI: Reserve
    // vector::reserve() memesan kapasitas memori TANPA membuat objek default (0).
    // Ini lebih ringan daripada vector<int> arr(n) yang mengisi semua dengan 0 dulu.
    vector<int> arr;
    arr.reserve(n); 

    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        // push_back di sini sangat cepat karena memori sudah di-reserve
        arr.push_back(temp);
    }

    // 3. Sorting (Tetap diperlukan untuk efisiensi memori O(N))
    sort(arr.begin(), arr.end());

    // 4. INOVASI OUTPUT: String Buffer
    // Daripada melakukan 'cout' ratusan kali di dalam loop,
    // kita tampung hasilnya dalam satu string raksasa.
    string outputBuffer = "";
    // Estimasi ukuran buffer untuk mencegah realokasi string (opsional tapi bagus)
    outputBuffer.reserve(n * 10); 

    outputBuffer += "\nHasil Frekuensi:\n----------------\n";

    if (n > 0) {
        int currentCount = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i-1]) {
                currentCount++;
            } else {
                // Simpan ke buffer, JANGAN dicetak dulu
                outputBuffer += to_string(arr[i-1]) + " : " + to_string(currentCount) + " kali\n";
                currentCount = 1;
            }
        }
        // Masukkan elemen terakhir ke buffer
        outputBuffer += to_string(arr[n-1]) + " : " + to_string(currentCount) + " kali\n";
    }

    // 5. EKSEKUSI FINAL: Satu kali cetak untuk semua data
    cout << outputBuffer;

    return 0;
}