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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n],b[n];
        for(auto &va:a) cin >> va;
        for(auto &va:b) cin >> va;
        int miss = 0;
        int seen[2];
        int needed[2];
        for(int i = 0;i < n;++i){
            ++seen[a[i]];
            ++needed[b[i]];
            miss += (a[i] != b[i]);
        }
        if(miss == 0)
            cout << 0 << "\n";
        else if(miss == 1)
            cout << 1 << "\n";
        else{
            if(needed[0] - seen[0] > 0)
                cout << (1 - (needed[0] - seen[0] == miss) + needed[0] - seen[0]) << "\n";
            else if(needed[1] - seen[1] > 0)
                cout << (1 - (needed[1] - seen[1] == miss) + needed[1] - seen[1]) << "\n";
            else
                cout << 1 << "\n";
        }
    }
    return 0;
}
