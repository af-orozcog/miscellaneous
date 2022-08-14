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

bool comp(const pair<string,pii> &a, const pair<string,pii> &b){
    if(a.ss.ff > b.ss.ff) return 1;
    else if(a.ss.ff < b.ss.ff) return 0;
    return a.ss.ss < b.ss.ss;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<string,pii>> per(n);
        for(auto &va:per)
            cin >> va.ff >> va.ss.ff >> va.ss.ss;

        sort(per.begin(),per.end(),comp);
        cout << per[0].ff << "\n";
    }
    return 0;
}

