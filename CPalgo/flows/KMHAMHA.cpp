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

const ll INF  = (1LL<<62);

struct MaxFlow{
    int nodes,src,dst;
    vector<int> dist,q,work;
    struct edge {int to,rev;ll f,cap;};
    vector<vector<edge>> g;
    MaxFlow(int x):nodes(x),g(x),dist(x),q(x),work(x){}
    void add_edge(int s, int t, ll cap){
        g[s].pb((edge){t,(int) g[t].size(),0,cap});
        g[t].pb((edge){s,(int)g[s].size()-1,0,0});
    }
    bool dinic_bfs(){
        fill(dist.begin(), dist.end(),-1);dist[src]=0;
        int qt=0;q[qt++]=src;
        for(int qh=0;qh<qt;qh++){
            int u=q[qh];
            for(int i = 0; i<g[u].size(); ++i){
                edge &e=g[u][i];int v=g[u][i].to;
                if(dist[v]<0&&e.f<e.cap)dist[v]=dist[u]+1,q[qt++]=v;
            }
        }
        return dist[dst]>=0;
    }
    ll dinic_dfs(int u, ll f){
        if(u==dst)return f;
        for(int &i=work[u];i<g[u].size();i++){
            edge &e=g[u][i];
            if(e.cap<=e.f)continue;
            int v=e.to;
            if(dist[v]==dist[u]+1){
                ll df=dinic_dfs(v,min(f,e.cap-e.f));
                if(df>0){e.f+=df;g[v][e.rev].f-=df;return df;}
            }
        }
        return 0;
    }
    /*
     * Aqui es super importante resaltar que cuando se llama el método varias veces lo que retorna es la mejora en el
     * flujo respecto a la vez pasada que se llamó, no el flujo total actual.
     */
    ll max_flow(int _src, int _dst){
        src=_src;dst=_dst;
        ll result=0;
        while(dinic_bfs()){
            fill(work.begin(), work.end(),0);
            while(ll delta=dinic_dfs(src,INF))result+=delta;
        }
        return result;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pii> ele(n);
        set<int> row,col;
        for(auto &va:ele){
            cin >> va.ff >> va.ss;
            row.insert(va.ff); col.insert(va.ss);
        }

        map<int,int> idC,idR;
        for(auto va:row)
            idR[va] = idR.size()+1;
        for(auto va:col)
            idC[va] = idR.size()+idC.size() + 1;

        auto graph = MaxFlow(idC.size()+idR.size()+2);

        for(auto &va:ele){
            int r = va.ff,c = va.ss;
            graph.add_edge(idR[r],idC[c],1);
        }

        for(auto va:idR)
            graph.add_edge(0,va.ss,1);

        for(auto va:idC)
            graph.add_edge(va.ss,idC.size()+idR.size()+1,1);

        cout << graph.max_flow(0,idC.size()+idR.size()+1) << "\n";

    }
    return 0;
}
