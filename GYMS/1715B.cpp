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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll n,k,b,s;
        cin >> n >> k >> b >> s;
        ll prom = b/n;
        ll left = b%n;
        ll ma = (prom+1)*k-1;
        ll mi = prom*k;
        if(ma*n + (left*k) >= s && mi*n <= s){
            vector<ll> ans(n,mi);
            s -= mi*n;
            for(int i = 0; i < left && s >= 0;++i){
                s += mi;
                s -= ma+1;
                ans[i] = ma+1;
            }
            for(auto &va:ans){
                ll add = max(0LL,min(s-k-1,ma-mi));
                va += add;
                s -= add;
            }
            if(s != 0){
                cout << "-1\n";
                continue;
            }
            for(auto &va:ans) cout << va << " ";
        }
        else
            cout << -1 << "\n";
    }
    return 0;
}
