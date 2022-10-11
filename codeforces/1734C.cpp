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
        string see; cin >> see;
        map<int,int> next;
        ll ans = 0;
        for(int i = 1; i <= see.size();++i){
            if(see[i-1] == 0){
                int smallest = INT_MAX;
                for(int j = 1; j*j <= i;++j){
                    if(i % j == 0){
                        int ot = i / j;
                        if(!next.count(j)) next[j] = j;
                        if(!next.count(ot)) next[ot] = ot;
                        while(next[j] <= see.size() && see[next[j]-1] == '0') next[j] += j;
                        while(next[ot] <= see.size() && see[next[ot]-1] == '0') next[ot] += ot;
                        if(i == next[j])
                            smallest = min(j,smallest);
                        if(i == next[ot])
                            smallest = min(ot,smallest);
                    }
                }
                ans += smallest;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
