#include <iostream>
using namespace std;

const long long MOD = 1000000007;

int R, C, M, B;
int N;                       // jumlah petak
long long forbidMask[36];    // petak-petak yang tidak boleh dipakai bersama dengan petak tertentu
long long jawaban = 0;

int id(int r, int c) {
    return r * C + c;
}

void coba(int pos, int pakai, long long mask) {

    if (pakai == M) {
        jawaban = (jawaban + 1) % MOD;
        return;
    }

    if (pos == N) return;

    int sisa = N - pos;
    if (pakai + sisa < M) return;

    coba(pos + 1, pakai, mask);

    if (!(mask & (1LL << pos))) {
        long long maskBaru = mask | forbidMask[pos];
        coba(pos + 1, pakai + 1, maskBaru);
    }
}

int main() {
    cin >> R >> C >> M >> B; 
    N = R * C;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {

            int u = id(r, c);
            long long mask = 0;

            mask |= (1LL << u);

            int dr[4] = {-1, 1, 0, 0};
            int dc[4] = {0, 0, -1, 1};

            for (int d = 0; d < 4; d++) {
                for (int step = 1; step <= 2; step++) {
                    int nr = r + dr[d] * step;
                    int nc = c + dc[d] * step;

                    if (nr < 0 || nr >= R || nc < 0 || nc >= C) break;

                    int v = id(nr, nc);
                    mask |= (1LL << v);
                }
            }

            forbidMask[u] = mask;
        }
    }

    
    coba(0, 0, 0);

    cout << jawaban % MOD << endl;
    return 0;
}
