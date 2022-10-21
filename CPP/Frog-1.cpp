#include <bits/stdc++.h>
using namespace std;
 
 
typedef long long ll;
typedef vector<char> vc;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<vector<ll>> vvl;
typedef pair<int, int> pi;        //inserting values: pi = make_pair(3,2); printing values: cout<<pi.first<<" "<<pi.second;
typedef vector<pair<ll,ll>> vp;
const int N = 1e5 + 10;
 
int a[N];
int dp[N];
 
int mincost(int n){
    if(dp[n]!=-1)return dp[n];
    if(n==1)return dp[n] = 0;
    if(n==2)return dp[n] = abs(a[1]-a[2]);
    return dp[n] = min(mincost(n-1)+abs(a[n]-a[n-1]),mincost(n-2)+abs(a[n]-a[n-2])); 
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<mincost(n)<<endl;
    return 0;
}