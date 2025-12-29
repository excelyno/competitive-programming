#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Konstanta Modulo sesuai soal
const int MOD = 1000000007;

// Variabel Global untuk menyimpan input
int R, C, M, B;
int grid[40]; // Menyimpan isi papan (dibuat 1D array agar mudah). 0=Kosong, 1=Mata-mata, 2=Bata
long long C_n_k[40][40]; // Tabel untuk menyimpan nilai kombinasi (Pascal Triangle)

// Fungsi untuk menghitung Kombinasi (nCr) sebelumnya (Precompute)
void precomputeCombinations() {
    for (int i = 0; i < 40; i++) {
        C_n_k[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C_n_k[i][j] = (C_n_k[i-1][j-1] + C_n_k[i-1][j]) % MOD;
        }
    }
}

// Fungsi Rekursif Utama (Backtracking)
// idx: indeks sel saat ini (0 s.d R*C-1)
// m_sisa: sisa mata-mata yang harus diletakkan
// b_sisa: sisa jatah batu bata yang BOLEH diletakkan
long long solve(int idx, int m_sisa, int b_sisa) {
    int total_sel = R * C;
    int cells_left = total_sel - idx;

    // Pruning 1: Jika sisa sel tidak cukup untuk menampung sisa mata-mata
    if (m_sisa > cells_left) return 0;

    // BASE CASE / OPTIMASI MATEMATIKA:
    // Jika semua mata-mata sudah diletakkan, kita tidak perlu rekursi lagi.
    // Sisa sel (cells_left) bisa diisi dengan batu bata (0 sampai b_sisa).
    // Ini menghitung: Kombinasi total cara mengisi sisa papan dengan sisa jatah bata.
    if (m_sisa == 0) {
        long long ways = 0;
        // Kita bisa meletakkan i batu bata, di mana 0 <= i <= b_sisa
        // Namun i juga tidak boleh melebihi jumlah sel yang tersisa
        int max_bata = min(cells_left, b_sisa);
        
        for (int i = 0; i <= max_bata; i++) {
            ways = (ways + C_n_k[cells_left][i]) % MOD;
        }
        return ways;
    }

    // Jika sudah sampai ujung tapi mata-mata belum habis (seharusnya kena pruning di atas, tapi untuk keamanan)
    if (idx == total_sel) return 0;

    long long total_ways = 0;
    int r = idx / C; // Baris saat ini
    int c = idx % C; // Kolom saat ini

    // --- OPSI 1: TARUH MATA-MATA (Isi 1) ---
    // Cek apakah aman menaruh mata-mata di sini (Lihat Kiri dan Atas)
    bool aman = true;
    
    // Cek Kiri (Jarak 1)
    if (c >= 1 && grid[idx-1] == 1) aman = false;
    // Cek Kiri (Jarak 2): Jika di idx-2 ada mata-mata DAN di idx-1 BUKAN bata
    if (c >= 2 && grid[idx-2] == 1 && grid[idx-1] != 2) aman = false;
    
    // Cek Atas (Jarak 1)
    if (r >= 1 && grid[idx-C] == 1) aman = false;
    // Cek Atas (Jarak 2): Jika di idx-2C ada mata-mata DAN di idx-C BUKAN bata
    if (r >= 2 && grid[idx-2*C] == 1 && grid[idx-C] != 2) aman = false;

    if (aman) {
        grid[idx] = 1; // Set jadi Mata-mata
        total_ways = (total_ways + solve(idx + 1, m_sisa - 1, b_sisa)) % MOD;
        grid[idx] = 0; // Backtrack (kembalikan jadi kosong)
    }

    // --- OPSI 2: TARUH BATU BATA (Isi 2) ---
    // Hanya bisa jika kita masih punya jatah batu bata
    if (b_sisa > 0) {
        grid[idx] = 2; // Set jadi Bata
        total_ways = (total_ways + solve(idx + 1, m_sisa, b_sisa - 1)) % MOD;
        grid[idx] = 0; // Backtrack
    }

    // --- OPSI 3: BIARKAN KOSONG (Isi 0) ---
    grid[idx] = 0; // Set Kosong
    total_ways = (total_ways + solve(idx + 1, m_sisa, b_sisa)) % MOD;
    // Tidak perlu backtrack karena nilai sudah 0

    return total_ways;
}

int main() {
    // Optimasi I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Persiapkan tabel kombinasi
    precomputeCombinations();

    // Baca Input
    if (cin >> R >> C >> M >> B) {
        // Reset grid (meski global sudah 0, untuk memastikan)
        for(int i=0; i<40; i++) grid[i] = 0;
        
        // Jalankan solusi mulai dari index 0
        cout << solve(0, M, B) << endl;
    }

    return 0;
}
