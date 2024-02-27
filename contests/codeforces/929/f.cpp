#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt,sse,sse2,sse3,sse4,mmx")

using namespace std;

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 0;
    cin >> t;
    for (int ti = 0; ti < t; ti++)
    {
        int r = 0;
        int c = 0;
        cin >> r >> c;
        vector<vector<int>> grid(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> grid[i][j];
            }
        }

        if (grid[0][0])
        {
            cout << "-1\n";
            continue;
        }

        vector<vector<int>> dp(r, vector<int>(c, -1));

        priority_queue<pair<int, pair<int, int>>, deque<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});

        while (!pq.empty())
        {
            pair<int, pair<int, int>> top = pq.top();
            pq.pop();
            int current_cost = top.first;
            int current_row = top.second.first;
            int current_col = top.second.second;

            // cout << "Current location: " << current_row << " " << current_col << " cost: " << current_cost << "\n";

            int bottom = (current_row + 1) % r;
            int bottom_2 = (current_row + 2) % r;
            int right = (current_col + 1) % c;

            if (dp[current_row][current_col] == -1 || dp[current_row][current_col] > current_cost)
            {
                dp[current_row][current_col] = current_cost;
                if (grid[bottom][current_col] == 0 && grid[bottom_2][current_col] == 0)
                {
                    pq.push({current_cost + 1, {bottom_2, current_col}});
                }
                if (grid[bottom][right] == 0)
                {
                    pq.push({current_cost + 1, {bottom, right}});
                }
            }
        }

        int min_cost = INT_MAX;

        for (int j = 0; j < r; j++)
        {
            if (dp[j][c - 1] == -1)
            {
                continue;
            }

            if (grid[j][c - 1] == 1)
            {
                continue;
            }

            int dp_cost = dp[j][c - 1];

            int wait_target = j + 1 % r;

            int dp_mod = dp_cost % r;

            int additional_cost = (wait_target - dp_mod + r) % r;

            min_cost = min(min_cost, dp_cost + additional_cost);
        }

        if (min_cost == INT_MAX)
        {
            cout << "-1\n";
        }
        else
        {
            cout << min_cost << "\n";
        }
    }
    return 0;
}