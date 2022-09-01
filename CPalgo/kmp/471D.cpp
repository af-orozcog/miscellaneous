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

vector<int> prefix_fun(vector<int> &see){
    vector<int> phi(see.size(),0);
    for(int i = 1, j = 0; i < see.size();++i){
        while(j && see[i] != see[j]) j = phi[j-1];
        if(see[i] == see[j]) ++j;
        phi[i] = j;
    }
    return phi;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> nums1(n),nums2(m);
    for(auto &va:nums1) cin >> va;
    for(auto &va:nums2) cin >> va;
    vector<int> imp1, imp2;
    for(int i = 1; i < n;++i)
        imp1.pb(nums1[i]-nums1[i-1]);
    for(int i = 1; i < m;++i)
        imp2.pb(nums2[i]-nums2[i-1]);
    if(m == 1)
        cout << n << "\n";
    else{
        vector<int> send;
        for(auto va:imp2) send.pb(va);
        send.pb(INT_MAX);
        for(auto va:imp1) send.pb(va);
        auto check = prefix_fun(send);
        int ans = 0;
        for(int i = imp2.size()+1; i < check.size();++i){
            ans += (check[i] == imp2.size());
        }
        cout << ans << "\n";
    }
    return 0;
}
