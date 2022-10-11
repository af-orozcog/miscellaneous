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

ll binExp(ll x, ll y){
    ll ans = 1;
    while(y){
        if(y & 1){
            ans *= x;
            if(ans >= mod) ans %= mod;
        }
        x *= x;
        if(x >= mod) x %= mod;
        y >>= 1;
    }

    return ans;
}

ll modInv(ll x){
    return binExp(x,mod-2);
}

vector<ll> fact;

ll nCr(ll n, ll m){
    ll ans = fact[n];
    ans *= modInv(fact[m]);
    if(ans >= mod) ans %= mod;
    ans *= modInv(fact[n-m]);
    if(ans >= mod) ans %= mod;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fact.resize(61);
    fact[0] = 1;
    for(ll i = 1;i < fact.size();++i){
        fact[i] = fact[i-1]*i;
        if(fact[i] >= mod)
            fact[i] %= mod;
    }
    ll dp[61];
    dp[0] = dp[1] = 0;

    for(int i = 2; i < 61;i+=2){
        dp[i] = nCr(i-1,(i/2)-1) + dp[i-2];
    }

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll val1 = dp[n];
        ll total = nCr(n,n/2);
        ll val2 = total - val1 - 1;
        if(val2 < 0){
            val2 %= mod;
            val2 += mod;
        }
        cout << val1 << " " << val2 << " " << 1 << "\n";
    }
    return 0;
}
