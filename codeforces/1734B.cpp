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
        int n;
        cin >> n;
        vector<vector<ll>> sums(n+1),ans(n+1);
        map<pii,ll>right;
        ans[1] = sums[1] = {0,1};
        right[{1,1}] = 1;
        for(int i = 2; i <= n;++i){
            ans[i].resize(i+1,0);
            sums[i].resize(i+1,0);
            ll ma = 0;
            for(int j = 1; j <= i;++j){
                sums[i][j] = sums[i-1][j-1] + right[{i-1,j+1}];
                ma = max(ma,sums[i][j]);
            }
            for(int j = 1; j <= i;++j){
                ll add = ma-sums[i][j];
                right[{i,j}] = right[{i-1,j+1}] + add;
                ans[i][j] += add;
            }
        }

        for(int i = 1; i <= n;++i){
            for(int j = 1; j <= i;++j)
                cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
    return 0;
}
