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

ll binExp(ll x, ll y){
    ll ans = 1;
    while(y){
        if(y&1){
            ans *= x;
            if(ans >= mod) ans %= mod;
        }
        x *= x;
        if(x >= mod) x %= mod;
        y >>= 1;
    }

    return ans;
}

ll invMod(ll x){
    return binExp(x,mod-2);
}

vector<ll> fact;

ll calc(ll n,ll m){
    ll numerator = fact[n];
    ll denominator = fact[m];
    denominator *= fact[n-m];
    if(denominator >= mod)denominator %= mod;
    denominator = invMod(denominator);
    numerator *= denominator;
    if(numerator >= mod) numerator %= mod;
    return numerator;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin >> n >> k;
    fact.resize(n+1);
    fact[0] = 1;
    for(ll i = 1; i < fact.size();++i){
        fact[i] = fact[i-1]*i;
        if(fact[i] >= mod) fact[i] %= mod;
    }
    ll ans = 0;
    for(ll i = 0; i <= min(n,k);++i){
        ans += calc(n,i);
        if(ans >= mod) ans -= mod;
    }

    cout << ans << "\n";
    return 0;
}
