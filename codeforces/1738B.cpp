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
        int n,k; cin >> n >> k;
        vector<ll> vals(k);
        for(auto &va:vals) cin >> va;
        set<ll> seen;
        reverse(vals.begin(),vals.end());
        bool ans = 1;
        vector<ll> nums;
        for(int i = 0; i < k-1 && ans;++i){
            ll here = vals[i]-vals[i+1];
            nums.pb(here);
            if(!seen.size())
                seen.insert(here);
            else{
                ll check = *(seen.begin());
                if(check < here) ans = 0;
            }
        }
        if(ans){
            ll amount = n - k + 1;
            ll base = (vals.back()/amount);
            while(nums.size() < n) nums.pb(base);
            for(int i = 0; i < abs(vals.back()%amount);++i){
                if(vals.back() < 0)
                    nums[nums.size()-i-1] -= 1;
                else
                    nums[k+i-1] += 1;
            }
        }
        if(ans){
            reverse(vals.begin(),vals.end());
            reverse(nums.begin(),nums.end());
            ll sum = 0;
            for(int i = 0, j = n-k, lel = 0; i < n && ans;++i){
                sum += nums[i];
                if(i == j){
                    ans &= (vals[lel] == sum);
                    ++j;
                    ++lel;
                }
                if(i)
                    ans &= (nums[i] >= nums[i-1]);
            }
        }

        cout << (ans?"YES":"NO") << "\n";
    }
    return 0;
}
