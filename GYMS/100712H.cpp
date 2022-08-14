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

const int N = 1e5+8;
int low[N], disc[N], tiempo = 0;
bool ap[N];
vector<int> g[N];
set<pii> br;
int numBr = 0;
int n; //Size of the graph
vector<vector<int>> fakeG;

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
                br.insert({u, v});//we add the bridge
                br.insert({v, u});//we add the bridge
                ++numBr;
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

void dfs(int from, vector<int> &visited){
    visited[from] = tiempo;
    for(auto adj:g[from]){
        if(visited[adj] == -1){
            if(br.count({from,adj}))
                continue;
            dfs(adj,visited);
        }
    }
}

void createFakeGraph(){
    vector<int> visited(n,-1);
    fakeG.resize(n);
    tiempo = -1;
    for(int i = 0; i < n;++i){
        if(visited[i] == -1){
            ++tiempo;
            dfs(i,visited);
        }
    }
    for(auto &va:br){
        fakeG[visited[va.ff]].pb(visited[va.ss]);
    }
}

pii bfs(int now,vector<bool> &visited){
    pii ans = {now,0};
    vector<int> dist(tiempo+1,-1);
    dist[now] = 0;
    queue<int> q;
    q.push(now);
    visited[now] = 1;
    while(q.size()){
        int dad = q.front();
        q.pop();
        for(auto adj:fakeG[dad]){
            if(dist[adj] == -1){
                visited[adj] = 1;
                dist[adj] = dist[dad]+1;
                if(dist[adj] > ans.ss) ans = {adj,dist[adj]};
                q.push(adj);
            }
        }
    }

    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int m;
        cin >> n >> m;
        for(int i = 0; i < m;++i){
            int a,b; cin >> a >> b;
            --b,--a;
            g[a].pb(b);
            g[b].pb(a);
        }

        DFS();
        createFakeGraph();

        int ans = 0;
        vector<bool> visited(tiempo+1,0);
        for(int i = 0; i <= tiempo;++i){
            if(!visited[i]){
                auto see = bfs(i,visited);
                see = bfs(see.ff,visited);
                ans = max(ans,see.ss);
            }
        }

        cout << numBr - ans << "\n";
        // Clean the graph
        for(int i = 0; i < n;++i){
            low[i] = disc[i] = ap[i] = 0;
            g[i].clear();
        }
        tiempo = 0;
        numBr = 0;
        br.clear();
        fakeG.clear();
    }
    return 0;
}

