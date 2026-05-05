#include <bits/stdc++.h>
using namespace std;
#define faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
#define int long long
void sntdoan(int l, int r)
{
    int N = sqrt(r);
    vector<bool> ntnho(N + 1, true);
    vector<int> nt;
    ntnho[0] = ntnho[1] = false;
    for (int p = 2; p <= N; p++)
    {
        if (ntnho[p])
        {
            nt.push_back(p);
            for (int i = p * p; i <= N; i += p)
            {
                ntnho[i] = false;
            }
        }
    }
    vector<bool> kqtd(r - l + 1, true);
    if (l == 1)
        kqtd[0] = false;
    for (int p : nt)
    {
        int bd = max(p * p, (l + p - 1) / p * p);
        for (int j = bd; j <= r; j += p)
        {
            kqtd[j - l] = false;
        }
    }
    int cnt = 0;
    for (int i = 0; i <= r - l; i++)
    {
        if (kqtd[i])
            cnt++;
    }
    cout << cnt;
}
signed main()
{
    // freopen("bai1.inp", "r", stdin);
    // freopen("bai1.out", "w", stdout);
    faster;
    snt();
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        int cnt = 0;
        for (int i = a; i <= b; i++)
        {
            if (i > N)
            {
                if (ktnt(i))
                    cnt++;
            }
            else
            {
                if (nt[i])
                    cnt++;
            }
        }
        cout << cnt << "\n";
    }
}

//?????????????????
