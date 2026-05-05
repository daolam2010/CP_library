#include <bits/stdc++.h>
using namespace std;
#define faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
#define int long long
signed main()
{
    // freopen("bai1.inp", "r", stdin);
    // freopen("bai1.out", "w", stdout);
    faster;
    int n;
    cin >> n;
    int h = n / 3600;
    int m = (n % 3600) / 60;
    int s = n % 60;
    cout << setfill('0') << setw(2) << h << ":"
         << setfill('0') << setw(2) << m << ":"
         << setfill('0') << setw(2) << s << "\n";
}

//?????????????????
