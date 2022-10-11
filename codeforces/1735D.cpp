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


ll getValue(vector<int> &see){
    ll ans = 0;
    for(auto va:see){
        ans *= 3;
        ans += va;
    }

    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    vector<vector<int>> values(n, vector<int>(k));
    for(auto &row:values){
        for(auto &va:row) cin >> va;
    }

    map<ll,ll> imp;

    for(int i = 0; i < n;++i){
        for(int j = i+1; j < n;++j){
            vector<int> needed(k);
            for(int temp = 0; temp < k;++temp){
                if(values[i][temp] == values[j][temp])
                    needed[temp] = values[i][temp];
                else
                    needed[temp] = 3 - values[i][temp] - values[j][temp];
            }
            ++imp[getValue(needed)];
        }
    }

    ll ans = 0;

    for(int i = 0; i < n;++i){
        ll toSee = getValue(values[i]);
        if(imp.count(toSee))
            ans += (imp[toSee]*(imp[toSee]-1)) >> 1;
    }

    cout << ans << "\n";

    return 0;
}
