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
        vector<int> nums1(n),nums2(n);
        for(auto &va:nums1) cin >> va;
        for(auto &va:nums2) cin >> va;
        int ans = 0;
        for(int i = 29; i > -1;--i){
            int see = ans | (1<<i);
            map<int,int> mp1,mp2;
            for(auto va:nums1){
                ++mp1[va&see];
            }
            for(auto va:nums2){
                ++mp2[va&see];
            }
            bool posi = 1;
            for(auto va:mp1){
                if(!mp2.count(see ^ va.ff) || mp2[see ^ va.ff] != va.ss){
                    posi = 0;
                    break;
                }
            }
            for(auto va:mp2){
                if(!mp1.count(see ^ va.ff) || mp1[see ^ va.ff] != va.ss){
                    posi = 0;
                    break;
                }
            }
            if(posi) ans = see;
        }
        cout << ans << "\n";
    }
    return 0;
}
