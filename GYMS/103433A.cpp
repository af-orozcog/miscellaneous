// Is love even real?
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    map<int,vector<int>> vals;
    for(int i = 0; i < n;++i){
        int m; cin >> m;
        int temp = m;
        int ma = 0;
        while(temp--){
            int see; cin >> see;
            ma = max(see,ma);
        }
        vals[ma].pb(m);
    }

    ll biggest = vals.rbegin()->first;
    ll ans = 0;

    for(auto &va:vals){
        ll dif = biggest - va.first;
        for(auto &see:va.second)
            ans += see*dif;
    }

    cout << ans << "\n";

    return 0;
}
