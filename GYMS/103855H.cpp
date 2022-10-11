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
const ll mod = 1e9 + 7;
const ll lel = 1e12;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> vals(n);
    ll ans = 0;

    for(auto &va:vals) cin >> va;
    int next = n;
    vector<int> seen(n,0);
    vector<int> positions;

    for(int i = n-1; i > -1;--i){
        seen[i] = 1;
        if(vals[i] == next){
            positions.pb(i);
            while(next && seen[next]) --next;
        }
    }
    positions.pb(-1);
    vector<ll> dp(positions.size());
    dp[0] = 1;
    reverse(positions.begin(),positions.end());

    for(int i = 1; i < positions.size();++i){
        ll temp = positions[i]-positions[i-1];
        temp *= dp[i-1];
        if(temp >= mod) temp %= mod;
        temp += dp[i-1];
        if(temp >= mod) temp %= mod;
        dp[i] = temp;
    }

    cout << dp.back() << "\n";

    return 0;
}
