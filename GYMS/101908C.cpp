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

const int MAX = 1e6;
ll fenwick[MAX+1];

ll sum(int n){
    ll ans = 0;
    while(n){
        ans += fenwick[n];
        n -= (n&(-n));
    }
    return ans;
}

void add(int n){
    while(n <= MAX){
        ++fenwick[n];
        n += (n&(-n));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,y;
    cin >> x >> y;
    ll h,v;
    cin >> h >> v;
    vector<pii> ho(h),ve(v);
    vector<int> values = {-1};
    for(auto &see:ho) {
        cin >> see.ff >> see.ss;
        values.pb(see.ff);
        values.pb(see.ss);
    }

    for(auto &see:ve) {
        cin >> see.ff >> see.ss;
        values.pb(see.ff);
        values.pb(see.ss);
    }

    sort(values.begin(),values.end());
    sort(ho.begin(),ho.end());
    sort(ve.begin(),ve.end());

    ll ans = (h + 1) * (v + 1);

    memset(fenwick,0,sizeof(fenwick));

    for(auto &va:ho){
        int ind = lower_bound(values.begin(),values.end(),va.ss) - values.begin();
        ans += sum(MAX)-sum(ind);
        add(ind);
    }

    memset(fenwick,0,sizeof(fenwick));
    for(auto &va:ve){
        int ind = lower_bound(values.begin(),values.end(),va.ss) - values.begin();
        ans += sum(MAX)-sum(ind);
        add(ind);
    }

    cout << ans << "\n";
    return 0;
}
