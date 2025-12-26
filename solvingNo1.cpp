#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void solve(){
    long long N, K;
    cin >> N >> K;
    long long max_round_by_power = (long long)log2(K) + 1;
    long long ans = min(N, max_round_by_power);

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
