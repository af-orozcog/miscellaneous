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
    int t; cin >> t;
    while(t--){
        int n,x,y;
        cin >> n >> x >> y;
        if(x > y) swap(x,y);
        if(x == 0)
            cout << -1 << "\n";
        else if(y != 0)
            cout << -1 << "\n";
        else if(n % (x+1) != 0)
            cout << -1 << "\n";
        else{
            for(int i = 0, now = 1; i < n-1;++i){
                if(i == x) now += (x+1);
                cout << now << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
