#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt,sse,sse2,sse3,sse4,mmx")

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vpii vector<pii>
#define vvpii vector<vpii>

#define MOD 1000000007

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 0;
    cin >> t;

    for (int ti = 0; ti < t; ti++)
    {
        int n = 0;
        cin >> n;

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int x = 0;
            cin >> x;
            ans += abs(x);
        }
        cout << ans << "\n";
    }

    return 0;
}