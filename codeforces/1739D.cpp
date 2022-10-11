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

vector<bool> marked;
vector<vector<int>> g;
vector<int> dad;
vector<pii> vals;

int goUp(int from, int depth){
    if(from == 1) return -1;
    int now = from;
    while(depth--)
        now = dad[now];
    if(depth) return -1;
    else return now;
}

void dfs(int s, int dad, int depth){
    if(depth == 0) return;
    marked[s] = 1;
    for(auto adj:g[s]){
        if(adj == dad) continue;
        if(marked[adj]) continue;
        dfs(adj,s,depth-1);
    }
}

void calc(int s, int dad, int depth = 0){
    vals[s] = {depth,s};
    for(auto adj:g[s]){
        if(adj == dad) continue;
        calc(adj,s,depth+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        marked.resize(n+1,0);
        dad.resize(n+1);
        vals.resize(n+1);
        g.resize(n+1);
        for(int i = 2; i < n;++i){
            int see; cin >> see;
            dad[i] = see;
            g[i].pb(see);
            g[see].pb(i);
        }
        calc(1,-1);
        sort(vals.begin(),vals.end());
        reverse(vals.begin(),vals.end());
        fill(marked.begin(),marked.end(),0);
        int ans;
        int lo = 0, hi = n+1;
        while(lo <= hi){
            int mid = (lo+hi)>>1;
            fill(marked.begin(),marked.end(),0);
            int taken = 0;
            for(int i = 0; i < vals.size();++i){
                if(!marked[vals[i].ss] && vals[i].ff > mid){
                    ++taken;
                    int see = goUp(vals[i].ss,mid-1);
                    dfs(see,(see == 1?-1:dad[see]),mid-1);
                }
            }

            if(taken <= k){
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }

        cout << ans << "\n";
    }
    return 0;
}
