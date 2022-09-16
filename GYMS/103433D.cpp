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
vector<int> dp;
vector<int> marked;

void dfs(int now){
    marked[now] = 1;
    int ans = 0;
    for(auto adj:g[now]){
        if(marked[adj] == 1) continue;
        else if(marked[adj] == 2)
            ans += dp[adj] + 1;
        else{
            dfs(adj);
            ans += dp[adj] + 1;
        }
    }
    marked[now] = 2;
    dp[now] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    g.resize(n);
    marked.resize(n,0);
    dp.resize(n,0);
    for(int i = 0; i < k;++i){
        int a,b;
        cin >> a >>b;
        --a, --b;
        g[a].pb(b);
        g[b].pb(a);
    }

    for(int i = 0; i < n;++i){
        if(!marked[i] && (g[i].size() == 0 || g[i].size() > 1))
            dfs(i);
    }

    for(int i = 0; i < n;++i){
        if(!marked[i])
            dfs(i);
    }

    for(auto va:dp)
        cout << va << " ";

    cout << "\n";


    vector<pii> toUse;
    for(int i = 0; i < n;++i)
        toUse.pb({dp[i],i});

    sort(toUse.begin(),toUse.end());

    bool possible = false;

    for(int i = 0; i < n-1 && !possible;++i){
        if(toUse[i].ff == toUse[i+1].ff)
            possible = true;
    }

    if(!possible){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    vector<int> ans(n);
    for(int i = 0,j = 1; i < n;++i,++j)
        ans[toUse[i].ss] = j;

    for(auto va: ans)
        cout << va << " ";
    cout << "\n";

    for(int i = 0; i < n-1;++i){
        if(toUse[i].ff == toUse[i+1].ff)
            ans[i] = ans[i+1];
    }

    for(auto va: ans)
        cout << va << " ";
    cout << "\n";

    return 0;
}
