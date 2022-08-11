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
const int tama = 'f'-'a'+1;

namespace fft {
    typedef long long ll;
    const double PI = acos(-1.0);
    vector<int> rev;
    struct pt {
        double r, i;
        pt(double r = 0.0, double i = 0.0) : r(r), i(i) {}
        pt operator + (const pt & b) { return pt(r + b.r, i + b.i); }
        pt operator - (const pt & b) { return pt(r - b.r, i - b.i); }
        pt operator * (const pt & b) { return pt(r * b.r - i * b.i, r * b.i + i * b.r); }
    };
    void fft(vector<pt> &y, int on) {
        int n = y.size();
        for(int i = 1; i < n; i++) if(i < rev[i]) swap(y[i], y[rev[i]]);
        for(int m = 2; m <= n; m <<= 1) {
            pt wm(cos(-on * 2 * PI / m), sin(-on * 2 * PI / m));
            for(int k = 0; k < n; k += m) {
                pt w(1, 0);
                for(int j = 0; j < m / 2; j++) {
                    pt u = y[k + j];
                    pt t = w * y[k + j + m / 2];
                    y[k + j] = u + t;
                    y[k + j + m / 2] = u - t;
                    w = w * wm;
                }
            }
        }
        if(on == -1)
            for(int i = 0; i < n; i++) y[i].r /= n;
    }
    vector<ll> mul(vector<ll> &a, vector<ll> &b) {
        int n = 1, la = a.size(), lb = b.size(), t;
        for(n = 1, t = 0; n <= (la+lb+1); n <<= 1, t++); t = 1<<(t-1);
        vector<pt> x1(n), x2(n);
        rev.assign(n, 0);
        for(int i = 0; i < n; i++) rev[i] = rev[i >> 1] >> 1 |(i & 1 ? t : 0);
        for(int i = 0; i < la; i++) x1[i] = pt(a[i], 0);
        for(int i = 0; i < lb; i++) x2[i] = pt(b[i], 0);
        fft(x1, 1); fft(x2, 1);
        for(int i = 0; i < n; i++) x1[i] = x1[i] * x2[i];
        fft(x1, -1);
        vector<ll> sol(n);
        for(int i = 0; i < n; i++) sol[i] = x1[i].r + 0.5;
        return sol;
    }
}

vector<int> painted(tama,0);

void dfs(int now, vector<vector<int>> &g){
    painted[now] = 1;
    for(auto adj:g[now]){
        if(!painted[adj])
            dfs(adj,g);
    }
}

vector<ll> generateVector(string &see, char comp){
    vector<ll> ans(see.size(),0);
    for(int i = 0; i < see.size();++i){
        ans[i] = (see[i] == comp);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string see1,see2;
    cin >> see1 >> see2;
    reverse(see2.begin(),see2.end());
    vector<vector<ll>> firstS(tama);
    vector<vector<ll>> secondS(tama);
    for(auto i = 'a'; i <= 'f';++i){
        firstS[i-'a'] = generateVector(see1,i);
        secondS[i-'a'] = generateVector(see2,i);
    }
    vector<vector<vector<ll>>> check(tama,vector<vector<ll>>(tama));

    for(int i = 0; i < tama;++i){
        for(int j = 0; j < tama;++j){
            check[i][j] = fft::mul(firstS[i],secondS[j]);
        }
    }

    for(int i = see2.size()-1, j = 0; j <= see1.size()-see2.size();++i,++j){
        int ans = 0;
        vector<vector<int>> g(tama);
        fill(painted.begin(),painted.end(),0);
        for(int let1 = 0;let1 < tama;++let1){
            for(int let2 = 0; let2 < tama;++let2){
                if(check[let1][let2][i]){
                    if(!g[let1].size()) ++ans;
                    if(!g[let2].size() && let1 != let2) ++ans;
                    g[let1].pb(let2);
                    g[let2].pb(let1);
                }
            }
        }
        for(int let = 0; let < tama;++let){
            if(g[let].size() && !painted[let]){
                --ans;
                dfs(let,g);
            }
        }
        cout << ans << " ";
    }

    cout << "\n";
    return 0;
}
