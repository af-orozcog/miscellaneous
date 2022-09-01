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

// adj[u] = adjacent nodes of u
// ap = AP = articulation points
// p = parent
// disc[u] = discovery time of u
// low[u] = 'low' node of u

const int N = 2*(1e5+8);
int low[N], disc[N], tiempo = 0;
bool ap[N];
vector<int> g[N];
set<pii> br;
int n; //Size of the graph

int dfs(int u, int p) {
  int children = 0;
  low[u] = disc[u] = ++tiempo;
  for (int& v : g[u]) {
    if (v == p) continue; // we don't want to go back through the same path.
                          // if we go back is because we found another way back
    if (!disc[v]) { // if V has not been discovered before
      children++;
      dfs(v, u); // recursive DFS call
      if (disc[u] <= low[v]) // condition #1
        ap[u] = 1;
      if(disc[u] < low[v]){
        br.insert({u,v});//we add the bridge
        br.insert({v,u});
      }
      low[u] = min(low[u], low[v]); // low[v] might be an ancestor of u
    } else // if v was already discovered means that we found an ancestor
      low[u] = min(low[u], disc[v]); // finds the ancestor with the least discovery time
  }
  return children;
}

void DFS() {
  tiempo = 0;
  for (int u = 0; u < n; u++)
    if (!disc[u])
      ap[u] = dfs(u, u) > 1; // condition #2
}

vector<int> colors(n);
vector<int> colors2(n);

void dfs2(int now, int color){
    colors[now] = color;
    for(auto adj:g[now]){
        if(br.count({now,adj}) || colors[adj] != -1) continue;
        dfs2(adj,color);
    }
}

void dfs3(int now, int color){
    colors2[now] = color;
    for(auto adj:g[now]){
        if(colors2[adj] != -1) continue;
        dfs3(adj,color);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    colors.resize(n,-1);
    colors2.resize(n,-1);
    for(int i = 0; i < n;++i){
        int a,b; cin >> a >> b;
        --a,--b;
        g[a].pb(b);
        g[b].pb(a);
    }
    DFS();
    for(int i = 0,color = 0;i < n;++i){
        if(colors[i] == -1)
            dfs2(i,color++);
    }
    int maC = 0;
    int whoC;
    map<int,int> mp;
    for(auto va:colors){
        ++mp[va];
        if(maC < mp[va]){
            maC = mp[va];
            whoC = va;
        }
    }

    for(int i = 0,color = 0; i < colors.size();++i){
        if(colors[i] == whoC){
            for(auto adj:g[i]){
                if(colors[adj] != whoC){
                    dfs3(adj,color++);
                }
            }
        }
    }

    int q;
    cin >> q;
    while(q--){
        int a,b; cin >> a >>b;
        --a,--b;
        if(colors[a] == whoC || colors[b] == whoC)
            cout << "No\n";
        else if(colors2[a] != colors2[b])
            cout << "No\n";
        else
            cout << "Yes\n";
    }

    return 0;
}
