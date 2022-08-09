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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> initial(m,0);
    int l;
    cin >> l;
    for(int i = 0; i < l;++i){
        int see; cin >> see;
        --see;
        initial[see] = 1;
    }
    vector<vector<int>> sw(m);
    for(int i = 0;i < n;++i) {
        int sz;
        cin >> sz;
        while (sz--) {
            int val;
            cin >> val;
            --val;
            sw[val].pb(i);
        }
    }
    bool skip = 1;
    for(auto va:initial){
        if(va == 1){
            skip = 0; break;
        }
    }
    if(skip){
        cout << 0 << "\n"; return 0;
    }

    int ans = INT_MAX;
    for(int i = 0; i < n;++i){
        vector<int> two(2,0);
        int bad = 0;
        for(int j = 0; j < m;++j){
            vector<int> s = sw[j];
            if(!s.size()){
                if(initial[i]) bad = 1;
                continue;
            }
            int ind = lower_bound(s.begin(),s.end(),i)-s.begin();
            if(ind == s.size() || s[ind] > i) --ind;
            ++ind;
            if(ind&1){
                if(initial[j]){
                    if(s.size()&1) ++two[0];
                }
                else{
                    if(s.size()&1) ++two[1];
                    else ++bad;
                }
            }
            else{
                if(initial[j]){
                    if(s.size()&1) ++two[1];
                    else ++bad;
                }
                else{
                    if(s.size()&1) ++two[0];
                }
            }
        }
        if((two[0] && two[1]) || bad) continue;
        if(two[0]) ans = min(ans,i+1);
        else ans = min(n+i+1,ans);
    }

    cout << (ans == INT_MAX?-1:ans) << "\n";
    return 0;
}