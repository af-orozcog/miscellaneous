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


vector<vector<pll>> g;
vector<ll> dist;
vector<vector<int>> parents;
vector<int> seen;

void dijsktra(){
    priority_queue<pll> q;
    dist[0] = 0;
    q.push({0,0});

    while(q.size()){
        pll now = q.top();
        q.pop();
        now.ff *= -1;
        if(dist[now.ss] < now.ff) continue;
        for(auto va:g[now.ss]){
            if(va.ss + now.ff < dist[va.ff]){
                dist[va.ff] = va.ss + now.ff;
                parents[va.ff].clear();
                parents[va.ff].pb(now.ss);
                q.push({-dist[va.ff],va.ff});
            }
            else if(va.ss + now.ff == dist[va.ff])
                parents[va.ff].pb(now.ss);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p,t;
    cin >> p >> t;
    g.resize(p);
    dist.resize(p,LLONG_MAX);
    parents.resize(p);
    seen.resize(p,0);
    for(int i = 0; i < t;++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        g[a].pb({b,c});
        g[b].pb({a,c});
    }

    dijsktra();

    queue<int> q;
    q.push(p-1);
    ll ans = 0;
    while(q.size()){
        int now = q.front();
        q.pop();
        for(auto va:g[now]){
            if(dist[now] == va.ss + dist[va.ff]){
                ans += (va.ss<<1);
                if(!seen[va.ff]){
                    q.push(va.ff);
                    seen[va.ff] = 1;
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}

