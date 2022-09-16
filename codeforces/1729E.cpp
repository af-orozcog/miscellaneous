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

bool valid(vector<ll> vals, ll posi){
    set<ll> dif;

    return (dif.size() == 1)
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ll> vals;
    for(int i = 0; i < 46;++i){
        cout << "? " << 1 << i+2 << "\n";
        ll dist;
        cin >> dist;
        if(dist > 0) vals.pb(dist);
    }
    ll possible1

    cout << "! " << n << "\n";

    return 0;
}
