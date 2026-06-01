#include <bits/stdc++.h>
using namespace std;

#define faster                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
#define int long long

const int N = 1e6 + 5;
vector<bool> nt(N, true);

void snt() {
    nt[0] = nt[1] = false;
    for (int i = 2; i * i < N; i++) {
        if (nt[i]) {
            for (int j = i * i; j < N; j += i) {
                nt[j] = false;
            }
        }
    }
}

bool cklon(int n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

bool ck2(int n) {
    if (n == 0) return false;
    while (n > 0) {
        int chu_so = n % 10;
        if (chu_so != 2 && chu_so != 3 && chu_so != 5 && chu_so != 7) 
            return false;
        n /= 10;
    }
    return true;
}

bool ck(int n) {
    int tong = 0;
    while (n > 0) {
        tong += n % 10;
        n /= 10;
    }
    if (tong < N) return nt[tong];
    return cklon(tong);
}

signed main() {
    freopen("bai2.inp", "r", stdin);
    freopen("bai2.out", "w", stdout);
    faster;
    
    snt();
    
    int a, b;
    if (!(cin >> a >> b)) return 0;
    
    bool found = false;

    for (int i = a; i <= b; i++) {
        if (ck2(i) && ck(i)) { 
            if (i >= N) {
                if (cklon(i)) {
                    cout << i << " ";
                    found = true;
                }
            } else {
                if (nt[i]) {
                    cout << i << " ";
                    found = true;
                }
            }
        }
    }

    if (!found) cout << 0;
    return 0;
}
