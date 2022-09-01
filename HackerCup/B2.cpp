// Is love even real?
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
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

const int N = 1e7;
vector<int> low,disc;
vector<bool> ap;
int tiempo = 0;
vector<int> color1,color2;
vector<vector<int>> g;
set<pii> br;
int n; //Size of the graph
int r,c;
vector<vector<char>> mat;

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

int id(int x, int y){
    return x*c + y;
}

pii idInverse(int x){
    return {x/c,x%c};
}

void dfs2(int now, int color){
    color1[now] = color;
    for(auto adj:g[now]){
        if(br.count({now,adj}) || color1[adj] != -1) continue;
        dfs2(adj,color);
    }
}

void dfs3(int now){
    color2[now] = 1;
    pii see = idInverse(now);
    mat[see.ff][see.ss] = '^';
    for(auto adj:g[now]){
        if(br.count({now,adj}) || color2[adj] != -1) continue;
        dfs3(adj);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int cas = 1;
    while(t--){
        cout << "Case #" << cas++ << ": ";
        cin >> r >> c;
        n = r*c;
        color1.resize(n,-1);
        color2.resize(n,-1);
        mat.resize(r,vector<char>(c));
        g.resize(n);
        low.resize(n,0);
        disc.resize(n,0);
        ap.resize(n,0);
        for(auto &row:mat){
            for(auto &col:row) cin >> col;
        }
        vector<pii> trees;
        for(int i = 0; i < r;++i){
            for(int j = 0; j < c;++j){
                if(mat[i][j] != '#'){
                    if(i && mat[i-1][j] != '#')
                        g[id(i,j)].pb(id(i-1,j));
                    if(j && mat[i][j-1] != '#')
                        g[id(i,j)].pb(id(i,j-1));
                    if(i != r-1 && mat[i+1][j] != '#')
                        g[id(i,j)].pb(id(i+1,j));
                    if(j != c-1 && mat[i][j+1] != '#')
                        g[id(i,j)].pb(id(i,j+1));
                }
                if(mat[i][j] == '^')
                    trees.pb({i,j});
            }
        }

        DFS();
        map<int,int> mp;
        for(int i = 0,color = 0; i < n;++i){
            if(color1[i] == -1)
                dfs2(i,color++);
            ++mp[color1[i]];
        }

        bool posi = 1;
        for(auto va:trees){
            if(mp[color1[id(va.ff,va.ss)]] < 3){
                posi = 0;
                break;
            }
            else if(color2[id(va.ff,va.ss)] == -1)
                dfs3(id(va.ff,va.ss));
        }

        if(!posi) cout << "Impossible\n";
        else {
            cout << "Possible\n";
            for(auto &row:mat){
                for(auto &c:row)
                    cout << c;
                cout << "\n";
            }
        }

        tiempo = 0;
        mat.clear();
        color1.clear();
        color2.clear();
        br.clear();
        g.clear();
        low.clear();
        disc.clear();
        ap.clear();
    }
    return 0;
}
