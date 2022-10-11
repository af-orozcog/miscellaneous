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
        string s;
        cin >> s;
        string ans = "";
        map<int,int> mp;
        for(auto va:s) ++mp[va-'0'];
        for(auto va:s){
            auto mi = mp.begin()->ff;
            if(mi + 1 + '0' < va){
                ans += (mi + 1 + '0');
                --mp[mi];
                if(mp[mi] == 0) mp.erase(mi);
            }
            else{
                --mp[va-'0'];
                if(mp[va-'0'] == 0) mp.erase(va-'0');
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
