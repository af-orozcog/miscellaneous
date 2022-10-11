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
const ll mod = 1e9 + 7;
const ll lel = 1e12;

ll calc(map<pll,ll> &vals, map<int,ll> &col, map<int,ll> &row,
        map<int,set<int>> &colV, map<int,set<int>> &rowsV,
        set<pll> &colO, set<pll> &rowO){
    ll ans = 0;
    for(auto &va:colV){
        ll temp = 0;
        for(auto &rowV:va.ss){
            int now = row[rowV];
            rowO.erase({now,rowV});
            temp += vals[{rowV,va.ff}];
            now -= vals[{rowV,va.ff}];
            row[rowV] = now;
            rowO.insert({now,rowV});
        }

        vector<pii> imp;
        for(int i = 0;rowO.size() && i < 2;++i){
            auto see = *rowO.rbegin();
            imp.pb(see);
            temp += see.ff;
            rowO.erase(see);
        }

        ans = max(ans,temp);

        for(auto va:imp) rowO.insert(va);

        for(auto &rowV:va.ss){
            int now = row[rowV];
            rowO.erase({now,rowV});
            now += vals[{rowV,va.ff}];
            row[rowV] = now;
            rowO.insert({now,rowV});
        }

    }

    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<int,ll> col,rows,colI,rowsI;
    map<int,set<int>> colV,rowsV,colVI,rowsVI;
    map<pll,ll> vals,valsInv;


    int n; cin >> n;
    while(n--){
        int r,c,v; cin >> r >> c >> v;
        col[c] += v;
        colI[r] += v;

        rows[r] += v;
        rowsI[c] += v;

        colV[c].insert(r);
        colVI[r].insert(c);

        rowsV[r].insert(c);
        rowsVI[c].insert(r);

        vals[{r,c}] = v;
        valsInv[{c,r}] = v;
    }

    set<pll> colO,rowO,colOI,rowOI;
    for(auto &va:col){
        colO.insert({va.ss,va.ff});
        rowOI.insert({va.ss,va.ff});
    }

    for(auto &va:rows){
        colOI.insert({va.ss,va.ff});
        rowO.insert({va.ss,va.ff});
    }

    ll ans  = 0;

    vector<pii> imp;
    for(int i = 0;colO.size() && i < 3;++i){
        auto see = *colO.rbegin();
        imp.pb(see);
        ans += see.ff;
        colO.erase(see);
    }

    for(auto va:imp) colO.insert(va);

    ll temp = 0;

    imp.clear();

    for(int i = 0;rowO.size() && i < 3;++i){
        auto see = *rowO.rbegin();
        imp.pb(see);
        temp += see.ff;
        rowO.erase(see);
    }

    for(auto va:imp) rowO.insert(va);

    ans = max(ans,temp);

    ans = max(ans,calc(vals,col,rows,colV,rowsV,colO,rowO));

    ans = max(ans,calc(valsInv,colI,rowsI,colVI,rowsVI,colOI,rowOI));

    cout << ans << "\n";

    return 0;
}
