//dem nhung so co so uoc tuyet doi la 4 trong doan l den r
#include <bits/stdc++.h>
using namespace std;
#define faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
#define int long long
const int N = 1e6 + 5;
vector<int> uoc(N);
vector<int> pf(N);
void cnt(){
    for(int i = 1; i <N; i++){
        for(int j = i; j < N; j += i){
            uoc[j]++;
        }
    }
    for(int i = 1; i < N; i++){
        pf[i] = pf[i-1] + (uoc[i] == 4);
    }
}
signed main()
{
    // freopen("div.inp", "r", stdin);
    // freopen("div.out", "w", stdout);
    faster;
    cnt();
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << pf[r] - pf[l-1] << "\n";
    }
}

//????????????????
