#include <bits/stdc++.h>
using namespace std;
 
 
typedef long long ll;
typedef vector<char> vc;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<vector<ll>> vvl;
typedef pair<int, int> pi;        //inserting values: pi = make_pair(3,2); printing values: cout<<pi.first<<" "<<pi.second;
typedef vector<pair<ll,ll>> vp;
#define loop(i,x,n) for(ll i=x;i<=n;i++)
#define rloop(i,x,n) for(ll i=x;i>=n;i--)
 
string s;
string t;
ll dp[3005][3005];
 
ll lcs(ll i,ll j){
    if(i==-1 || j==-1){
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    ll ans = 0; 
    if(s[i]==t[j]){
        ans = lcs(i-1,j-1)+1;
    }
    if(s[i]!=t[j]){
        ans = max(lcs(i-1,j),lcs(i,j-1));
    }
    return dp[i][j] = ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    cin>>t;
    ll l1 = s.size()-1;
    ll l2 = t.size()-1;
    string ans="";
    memset(dp,-1,sizeof(dp));
    while(true){
        if(s[l1]==t[l2]){
            ans+=s[l1];
            l1--;
            l2--;
        }
        else{
            if(lcs(l1-1,l2) >= lcs(l1,l2-1)){
                l1--;
            }
            else{
                l2--;
            }
        }
        if(l1==-1 || l2==-1){
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
    return 0;
}