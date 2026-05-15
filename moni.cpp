/*
Bài 2. Đổi tiền. (7 điểm)
Một ngân hàng có N loại tiền mệnh giá A[1], A[2], ..., A[N] với số lượng tiền mỗi loại không
giới hạn. Cần chi trả cho khách hàng một số tiền M đồng.
Yêu cầu: Hãy cho biết cần bao nhiêu tờ cho mỗi loại tiền để tổng số tờ là ít nhất.
Dữ liệu vào: file text, tên file là MONEY.INP gồm 2 dòng
- Dòng đầu tiên ghi 2 số N, M (0 < N ≤ 100; 0 < M ≤ 10000).
- Dòng thứ hai ghi N số: A[1], A[2], ..., A[N] các số cách nhau bởi dấu cách.
Dữ liệu ra: file text, tên file là MONEY.OUT gồm 2 dòng
- Dòng đầu tiên ghi số tờ cần dùng, nếu không thể đổi được thì ghi số -1 và không cần thực
hiện tiếp.
- Dòng tiếp theo ghi n số ( mỗi số biểu hiện cho số tờ cần dùng cho mỗi loại).
*/
#include <bits/stdc++.h>
using namespace std;
#define faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
#define int long long
const int INF = 1e18;
signed main()
{
    // freopen("NTCN.inp", "r", stdin);
    // freopen("NTCN.out", "w", stdout);
    faster;
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), dp(m+1, INF), trace(m+1, -1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int s = a[i]; s <= m; s++){
            if(dp[s - a[i]] + 1 < dp[s]){
                dp[s] = dp[s - a[i]] + 1;
                trace[s] = i;
            }
        }
    }
    if(dp[m] == INF){
        cout << -1;
        return 0;
    }
    cout << dp[m] << "\n";
    vector<int> cnt(n+1, 0);
    int i = m;
    while(i > 0){
        cnt[trace[i]]++;
        i -= a[trace[i]];
    }
    for(int i = 1; i <= n; i++){
        cout << cnt[i] << " ";
    }
}

//?????????????????
