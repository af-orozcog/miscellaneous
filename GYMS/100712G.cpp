// Is love even real?
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int N = 32768;
const ld eps = 1e-9;
const ll mod = 998244353;
const ll lel = 1e12;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,s;
        cin >> n >> s;
        vector<int> coins(n);
        for(auto &va:coins) cin >> va;
        sort(coins.begin(),coins.end());
        reverse(coins.begin(),coins.end());
        vector<vector<int>> dp(n+1,vector<int>(s+1+200,INT_MIN));
        dp[0][0] = 0;
        int ans = 0;
        for(int i = 1; i <= n;++i){
            for(int j = 0; j < dp[i].size();++j){
                dp[i][j] = dp[i-1][j];
                if(j-coins[i-1] >= 0) dp[i][j] = max(dp[i][j],dp[i-1][j-coins[i-1]]+1);
                if(j-coins[i-1] < s && j >= s) ans = max(ans,dp[i][j]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

