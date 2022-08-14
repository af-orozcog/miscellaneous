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
const int N = 1e5+20;
const ld eps = 1e-9;
const ll mod = 998244353;
const ll lel = 1e12;
int n;
ll st[2*N];

void build() {
    for(int i = n-1; i>0; --i) st[i] = min(st[i<<1],st[i<<1|1]);
}

void update(int p, ll val) {
    for(st[p+=n] = val; p > 1; p>>=1) st[p>>1] = min(st[p],st[p^1]);
}

ll query(int l, int r) {
    ll rta = INT_MAX;
    for(l+=n, r+=n; l<r; l>>=1, r>>= 1) {
        if(l&1) rta=min(rta,st[l++]);
        if(r&1) rta=min(st[--r],rta);
    }
    return rta;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> n >> k;
        ++n;
        for(int i = 0; i <= (2*n)+2;++i) st[i] = INT_MAX;
        char see[n-1];
        for(auto &va:see) cin >> va;
        update(0,-1);
        set<int> positions;
        for(int i = 1; i < n;++i){
            if(i != n-1 && see[i-1] == see[i]) positions.insert(-i);
            update(i,query(i-1,i)+1);
            auto closest = positions.upper_bound(-i);
            if(closest == positions.end()) continue;
            int good = -(*closest);
            int lower = max(0,i-k), up = good;
            if(good <= lower) continue;
            ll check = min(query(i,i+1),query(lower,up)+1);
            update(i,check);
        }
        cout << query(n-1,n) << "\n";
    }
    return 0;
}

