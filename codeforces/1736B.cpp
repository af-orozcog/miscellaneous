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

ll lcm(ll a, ll b){
    return a * (b/__gcd(a,b));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        ll nums[n];
        for(auto &va:nums) cin >> va;
        vector<ll> vals(n+1,1);
        for(int i = 0;i < n;++i){
            vals[i] = lcm(vals[i],nums[i]);
            vals[i+1] = lcm(vals[i+1],nums[i]);
        }

        bool good = 1;

        for(int i = 0; i < vals.size()-1 && good;++i){
            if(__gcd(vals[i],vals[i+1]) != nums[i]) good = 0;
        }

        if(!good) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
