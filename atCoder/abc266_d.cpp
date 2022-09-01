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
//const int N = 1e5+20;
const ld eps = 1e-9;
const ll mod = 998244353;
const ll lel = 1e12;
const int N = 100000;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<ll>> dp(N+1,vector<ll>(5,LLONG_MIN));
    dp[0][0] = 0;
    vector<pair<int,pii>> info(n);
    for(auto &va:info) cin >> va.ff >> va.ss.ff >> va.ss.ss;

    int next = 0;
    for(int i = 1; i <= N;++i){
       for(int j = 0; j < 5;++j){
            dp[i][j] = dp[i-1][j];
            if(j != 4) dp[i][j] = max(dp[i][j],dp[i-1][j+1]);
            if(j) dp[i][j] = max(dp[i][j],dp[i-1][j-1]);
            if(next < n && info[next].ff == i &&
               info[next].ss.ff == j)
               dp[i][j] += info[next].ss.ss;

       }
        if(next < n && info[next].ff == i) ++next;
    }

    ll ans = 0;
    for(auto va:dp.back()) ans = max(ans,va);

    cout << ans << "\n";
    return 0;
}
