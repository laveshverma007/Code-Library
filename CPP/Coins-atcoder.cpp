#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<char> vc;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<vector<ll>> vvl;
typedef pair<int, int> pi; // inserting values: pi = make_pair(3,2); printing values: cout<<pi.first<<" "<<pi.second;
typedef vector<pair<ll, ll>> vp;
#define loop(i, x, n) for (ll i = x; i <= n; i++)
#define rloop(i, x, n) for (ll i = x; i >= n; i--)
 
ll n;
long double phead[3005];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // ll t;
    // cin >> t;
    // while (t--)
    // {
    cin >> n;
    loop(i, 1, n)
    {
        cin >> phead[i];
    }
    cout<<setprecision(10);
    long double dp[n+5][n+5];
    dp[0][0] = 0;
    dp[1][1] = phead[1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j <= i)
            {
                if (j == 0)
                {
                    if (dp[i - 1][j] == 0)
                    {
                        dp[i][j] = 1 - phead[i];
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j] * (1 - phead[i]);
                    }
                }
                else if (i == j)
                {
                    if (i != 1)
                        dp[i][j] = dp[i - 1][j - 1] * phead[i];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] * (1 - phead[i]) + (dp[i - 1][j - 1]) * (phead[i]);
                }
            }
        }
    }
    long double ans = 0;
    loop(i, n / 2 + 1, n)
    {
        ans += dp[n][i];
    }
    cout << ans << endl;
    return 0;
}