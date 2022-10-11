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

int dp[2][101][101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp[0][0][0] = 1;

    for(int i = 0; i < 101;++i){
        for(int j = 0; j < 101;++j){
            if(i == 0 && j == 0) continue;
            for(int want = 0; want < 2;++want){
                bool ans1 = 0,ans2 = 0;
                if(i){
                    ans1 = 1;
                    if(i > 1)
                        ans1 &= dp[(want+1)&1][i-2][j];
                    if(j)
                        ans1 &= dp[(want+1)&1][i-1][j-1];
                    if(i == 1 && j == 0)
                        ans1 &= (want == 1);
                }
                if(j){
                    ans2 = 1;
                    if(j > 1)
                        ans2 &= dp[want][i][j-2];
                    if(i)
                        ans2 &= dp[want][i-1][j-1];
                    if(j == 1 && i == 0)
                        ans2 &= (want == 0);
                }
                dp[want][i][j] = (ans1 | ans2);
            }
        }
    }

    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        int see[2] = {0,0};
        for(int i = 0;i < n;++i){
            int check; cin >> check;
            ++see[check&1];
        }
        cout << (dp[0][see[1]][see[0]] ? "Alice":"Bob") << "\n";
    }

    return 0;
}
