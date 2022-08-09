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
const ll mod = 1e9+7;
const ll lel = 1e12;

int dp[10001][1<<10];

bool comp(const pair<pii,pii> &a, const pair<pii,pii> &b){
    if(a.ss.ff < b.ss.ff) return 1;
    else if(a.ss.ff > b.ss.ff) return 0;
    return a.ss.ss < b.ss.ss;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<pii,pii>> nums;
    for(int i = 0; i < n;++i){
        int m; cin >> m;
        while(m--){
            int from,to,val;
            cin >> from >> to >> val;
            nums.pb({{val,i},{from,to}});
        }
    }
    sort(nums.begin(),nums.end(),comp);
    for(int i = 0; i < 10001;++i){
        for(int j = 0; j < (1<<10);++j) dp[i][j] = INT_MIN;
    }
    dp[nums.size()][0] = 0;
    for(int i = nums.size()-1; i > -1;--i){
        int next = nums.size();
        int lo = i+1,hi = nums.size()-1;
        while(lo <= hi){
            int mid = (lo+hi)>>1;
            if(nums[mid].ss.ff >= nums[i].ss.ss){
                next = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        for(int j = 0; j < (1<<10);++j){
            dp[i][j] = max(dp[i][j],dp[i+1][j]);
            int add = (1<<nums[i].ff.ss) | j;
            dp[i][add] = max(dp[i][add],dp[next][j]+nums[i].ff.ff);
        }
    }

    cout << (dp[0][(1<<(n))-1] < 0?-1:dp[0][(1<<(n))-1]) << "\n";

    return 0;
}