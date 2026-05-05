#include <bits/stdc++.h>
using namespace std;
#define faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
#define int long long
const int N = 1e6 + 5;
vector<int> nt;
vector<bool> ntnho(N, true);
void sangnho(){
    ntnho[0] = ntnho[1] = false;
    for(int p = 2; p * p < N; p++){
        if(ntnho[p]){
            for(int i = p * p; i < N; i += p){
                ntnho[i] = false;
            }
        }
    }
    for(int p = 2; p <  N; p++){
        if(ntnho[p]) nt.push_back(p);
    }
}
void sntdoan(int l, int r)
{
    vector<bool> ntdoan(r - l + 1, true);
    if(l == 1) ntdoan[0] = false;
    for(int p : nt){
        if(p * p > r) break;
        for(int j = max(p * p, (l+p-1)/p*p); j <= r; j += p){
            ntdoan[j - l] = false;
        }
    }
    int cnt = 0;
    for(int i = 0; i < r - l + 1; i++){
        if(ntdoan[i]) cnt++;
    }
    cout << cnt << "\n";
}
signed main()
{
    // freopen("bai1.inp", "r", stdin);
    // freopen("bai1.out", "w", stdout);
    faster;
    sangnho();
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        sntdoan(l, r);
    }
}

//?????????????????
