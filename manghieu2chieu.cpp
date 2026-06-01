#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
signed main()
{
    // freopen("bai2.inp", "r", stdin);
    // freopen("bai2.out", "w", stdout);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> diff(1005, vector<int>(1005, 0));
    vector<vector<int>> mang(1005, vector<int>(1005, 0));
    while (q--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        diff[a][b] += 1;
        diff[c + 1][b] -= 1;
        diff[a][d + 1] -= 1;
        diff[c + 1][d + 1] += 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            mang[i][j] = mang[i - 1][j] + mang[i][j - 1] - mang[i - 1][j - 1] + diff[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << mang[i][j] << " ";
        }
        cout << "\n";
    }
}
