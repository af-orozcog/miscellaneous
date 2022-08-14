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
const int MAX = 200000;

vector<int> topo;
vector<int> seen;
vector<vector<int>> g;

void topoSort(int now){
    topo[now] = 1;
    for(auto va:g[now]){
        if(!seen[va])
            topoSort(va);
    }

    topo.pb(now);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    g.resize(n);
    seen.resize(n,0);
    for(int i = 0; i < m;++i){
        int a,b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    topoSort(0);
    vector<int> dp(n,INT_MIN);
    fill(seen.begin(),seen.end(),0);
    dp[0] = 0;
    for(auto va:topo) {
        seen[va] = 1;
        for (auto adj: g[va]) {
            if(!seen[adj])
                dp[adj] = max(dp[adj], dp[va] + 1);
        }
    }

    bool ans = 0;
    for(int i = 1; i < n && !ans;++i){
        for(auto adj:g[i]){
            if(adj == 0 && dp[i] == n-1){
                ans = 1;
                break;
            }
        }
    }

    cout << (ans?"YES":"NO") << "\n";
    return 0;
}

