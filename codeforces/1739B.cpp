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
const ll mod = 1e9 + 7;
const ll lel = 1e12;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> vals(n);
        for(auto &va:vals) cin >> va;
        vector<int> ans;
        ans.pb(vals[0]);

        for(int i = 1; i < n;++i){
            int check1 = vals[i] - ans[i-1];
            int check2 = ans[i-1] - vals[i];
            if(check1 != check2) break;
            ans.pb(check1);
        }

        if(ans.size() == n){
            for(auto va:ans)
                cout << va << " ";
            cout << "\n";
        }
        else cout << "-1\n";

    }
    return 0;
}
