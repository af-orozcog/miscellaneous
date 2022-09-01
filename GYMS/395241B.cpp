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
const int N = 1e6+3;

const ll iden = -1e16;

int n;
ll st[2*N];

void build() {
    for(int i = n-1; i>0; --i) st[i] = max(st[i<<1],st[i<<1|1]);
}

void update(int p, ll val) {
    for(st[p+=n] = val; p > 1; p>>=1) st[p>>1] = max(st[p],st[p^1]);
}

ll query(int l, int r) {
    ll rta = iden;
    for(l+=n, r+=n; l<r; l>>=1, r>>= 1) {
        if(l&1) rta = max(rta,st[l++]);
        if(r&1) rta = max(rta,st[--r]);
    }
    return rta;
}

vector<ll> nums;


int main(){
    int tama,q,p;
    scanf(" %d %d %d",&tama,&q,&p);
    n = tama+1;
    nums.resize(tama+1);
    for(int i = 0; i < n;++i) st[i+n] = iden;
    build();
    for(int i = 1; i <= tama;++i) scanf(" %lld",&nums[i]);
    unordered_map<int,ll> mp;
    while(q--){
        int x; cin >> x;
        if(mp.count(x)){
            ll val = mp[x];
            if(val <= iden) printf("Noob\n");
            else printf("%lld\n",val);
            continue;
        }
        for(int i = (tama/x)*x; i > -1; i -= x){
            ll see = query(i,min(i+p+1,n));
            ll use = max((i+p > tama?0LL:iden),see);
            if(use != iden) use += nums[i];
            update(i,use);
        }
        ll val = query(0,1);
        mp[x] = val;
        if(val <= iden) printf("Noob\n");
        else printf("%lld\n",val);
        for(int i = (tama/x)*x; i > -1; i -= x)
            update(i,iden);
    }
    return 0;
}
