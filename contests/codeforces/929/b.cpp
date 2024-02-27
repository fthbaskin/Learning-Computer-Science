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

        int mod_0 = 0;
        int mod_1 = 0;
        int mod_2 = 0;

        for (int i = 0; i < n; i++)
        {
            int x = 0;
            cin >> x;
            if (x % 3 == 0)
            {
                mod_0++;
            }
            else if (x % 3 == 1)
            {
                mod_1++;
            }
            else
            {
                mod_2++;
            }
        }

        int total = (mod_1 + 2 * mod_2) % 3;

        int ans = 0;
        if (total == 0)
        {
            ans = 0;
        }
        else if (total == 1)
        {
            if (mod_1 > 0)
            {
                ans = 1;
            }
            else
            {
                ans = 2;
            }
        }
        else
        {
            ans = 1;
        }

        cout << ans << "\n";
    }

    return 0;
}