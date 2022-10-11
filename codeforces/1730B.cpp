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
const int N = 1e6+1;
const ld eps = 1e-9;
const ll mod = 998244353;
const ll lel = 1e12;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pll> vals(n);
        for(auto &va:vals) cin >> va.ff;
        for(auto &va:vals) cin >> va.ss;
        sort(vals.begin(),vals.end());
        if(n == 1){
            cout << vals[0].ff << "\n";
            continue;
        }
        ld ma = vals[0].ss;
        ld ans = vals[0].ff;
        ll mi = vals[0].ff - vals[0].ss;
        for(int i = 1; i < n;++i) {
            if(vals[i].ss > ma){
                ans = vals[i].ff;
                ma = vals[i].ss;
            }
            ll xP = vals[i].ff + vals[i].ss;
            if (xP < mi) {
                if (vals[i].ss > ma) {
                    ma = vals[i].ss;
                    ans = vals[i].ff;
                }
                continue;
            } else {
                ld intersect = (xP + mi) / (ld) 2;
                ld yP = (ld) vals[i].ff - intersect + (ld) vals[i].ss;
                if (yP > ma) {
                    ma = yP;
                    ans = intersect;
                }
            }
            mi = min(mi,vals[i].ff - vals[i].ss);
        }

        cout << setprecision(9) << fixed << ans << "\n";
    }
    return 0;
}
