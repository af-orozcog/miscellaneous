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

ll fastSum(ll n){
    return (n*(n+1))>>1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<vector<int>> nums(4);
        for(int i = 1, j = 1; i <= n;++i,++j){
            if(j == 4) j = 0;
            nums[j].pb(i);
        }
        k = k % 4;
        if(k == 1){
            cout << "YES\n";
            for(int i = 1; i <= n;i+=2)
                cout << i << " " << i+1 << "\n";
        }
        else {
            vector<pii> ans;
            for(int i = 1; i < 4;++i){
                if(i + k == 0) continue;
                while(nums[0].size() && nums[i].size()){
                    ans.pb({nums[i].back(),nums[0].back()});
                    nums[0].pop_back();
                    nums[i].pop_back();
                }
            }
            for(int i = 1; i < 4;++i){
                if(i + k == 0) continue;
                while(nums[4-k].size() && nums[i].size()){
                    ans.pb({nums[4-k].back(),nums[i].back()});
                    nums[4-k].pop_back();
                    nums[i].pop_back();
                }
            }
            if(ans.size() == n/2){
                cout << "YES\n";
                for(auto va:ans)
                    cout << va.ff << " " << va.ss << "\n";
            }
            else cout << "NO\n";
        }
    }
    return 0;
}

