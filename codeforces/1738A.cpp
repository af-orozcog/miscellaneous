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

ll calc(vector<ll> see1,vector<ll> see2){
    ll ans = 0;
    bool add = 0;
    if(see1.size()){
        ans += see1[0];
        see1.erase(see1.begin());
        add = 1;
    }
    while(see1.size() && see2.size()){
        ans += (see1.back()<<1);
        ans += (see2.back()<<1);
        see1.pop_back();
        see2.pop_back();
    }
    if(add && see2.size()){
        ans += (see2.back()<<1);
        see2.pop_back();
    }
    while(see1.size()){
        ans += (see1.back());
        see1.pop_back();
    }
    while(see2.size()){
        ans += (see2.back());
        see2.pop_back();
    }
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> types(n);
        for(auto &va:types) cin >> va;
        vector<vector<ll>> vals(2,vector<ll>());
        for(int i = 0; i < n;++i){
            ll temp; cin >> temp;
            vals[types[i]].pb(temp);
        }
        sort(vals[0].begin(),vals[0].end());
        sort(vals[1].begin(),vals[1].end());

        ll ans = calc(vals[0],vals[1]);
        ans = max(calc(vals[1],vals[0]),ans);

        cout << ans << "\n";
    }
    return 0;
}
