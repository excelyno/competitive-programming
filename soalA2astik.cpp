#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const long long MOD = 1'000'000'007;
vector<long long> f, inv;

long long modpow(long long a,long long b){
    long long r=1;
    while(b){ if(b&1) r=r*a%MOD; a=a*a%MOD; b>>=1; }
    return r;
}

long long C(long long n,long long k){
    if(k<0||k>n) return 0;
    return f[n]*inv[k]%MOD*inv[n-k]%MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int MAX = 1<<20;
    f.resize(MAX+1);
    inv.resize(MAX+1);

    f[0]=1;
    for(int i=1;i<=MAX;i++) f[i]=f[i-1]*i%MOD;
    inv[MAX]=modpow(f[MAX],MOD-2);
    for(int i=MAX;i;i--) inv[i-1]=inv[i]*i%MOD;

    int T; cin>>T;
    while(T--){
        long long N,K; cin>>N>>K;
        long long M = 1LL<<N;

        long long R = min<long long>(N, floor(log2((long double)K))+1);
        long long S = 1LL<<(R-1);
        long long blocks = M/S;

        long long TOTAL =
            (blocks%MOD) * C(K-1,S-1)%MOD * f[S]%MOD * f[M-S]%MOD;

        if(R==N){ cout<<R<<" "<<TOTAL%MOD<<"\n"; continue; }

        long long BAD = 0;
        if(K-S>=S){
            BAD =
                (blocks%MOD) *
                C(K-1,S-1)%MOD * f[S]%MOD *
                C(K-S,S)%MOD * f[S]%MOD *
                f[M-2*S]%MOD;
        }

        long long ans = (TOTAL-BAD)%MOD;
        if(ans<0) ans+=MOD;

        cout<<R<<" "<<ans<<"\n";
    }
}
