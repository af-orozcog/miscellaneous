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

vector<vector<int>> g;
vector<ll> ways,starting,rooting;
ll ans = 0;

void dfs(int p, int dad = -1){
    ll way = 0, s = 0;

    for(auto adj:g[p]){
        if(adj == dad) continue;
        dfs(adj,p);
        way += ways[adj];
        s += starting[adj];
    }

    ways[p] = way + s;
    starting[p] = s;
}


void rerouting(int p, int dad){
    ll check1 = ways[dad] - starting[p];
    ll check2 = starting[dad] - starting[p];

    rooting[p] = ways[p] + check1 + starting[p] + check2;
    ans = max(ans,rooting[p]);

    for(auto adj:g[p]){
        if(adj == dad) continue;
        rerouting(adj,p);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    g.resize(n);
    ways.resize(n);
    starting.resize(n);
    rooting.resize(n);
    for(int i = 0; i < n-1;++i){
        int see; cin >> see;
        --see;
        g[see].pb(i);
        g[i].pb(see);
    }


    dfs(0);

    rooting[0] = ways[0];

    for(auto adj:g[0])
        rerouting(adj,0);

    cout << ans << "\n";

    return 0;
}
