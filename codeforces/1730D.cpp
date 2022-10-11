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
        string s1,s2;
        cin >> s1 >> s2;
        map<pair<char,char>,int> mp;
        for(int i = 0, j = n-1; i < n;++i,--j) {
            if(s1[i] > s2[j]) swap(s1[i],s2[j]);
            ++mp[{s1[i], s2[j]}];
        }
        int bad = 0;
        int good = 0;
        for(auto &va:mp){
            if((va.ss&1) && va.ff.ff != va.ff.ss){
                ++imp;
            }
            if(va.ff.ff == va.ff.ss) good += (va.ss&1);
        }
        bool ans = 0;
        if(n % 2 == 1) ans = (bad == 0 && good == 1);
        else if(n % 2 == 0) ans = (bad == 0 && good == 0);
        cout << (ans ? "YES":"NO") << "\n";
    }
    return 0;
}
