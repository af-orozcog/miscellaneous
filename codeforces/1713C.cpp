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

ll fastSum(ll n){
    return (n*(n+1))>>1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    vector<int> imp;
    for(int i = 0; i*i <= 1000000;++i)
        imp.pb(i*i);
    while(t--){
        int n;
        cin >> n;
        vector<int> ans(n,-1);
        bool posi = 1;
        for(int i = n-1; i > -1 && posi;--i){
            if(ans[i] != -1) continue;
            int ind = lower_bound(imp.begin(),imp.end(),i+i)-imp.begin();
            while(ind > -1 && imp[ind] >= i){
                if(imp[ind]-i <= i && ans[imp[ind]-i] == -1){
                    ans[i] = imp[ind]-i;
                    ans[imp[ind]-i] = i;
                    break;
                }
                --ind;
            }
            if(ind == -1) posi = 0;
        }
        if(!posi){
            cout << -1 << "\n";
            continue;
        }
        for(auto va:ans) cout << va << " ";
        cout << "\n";
    }
    return 0;
}

