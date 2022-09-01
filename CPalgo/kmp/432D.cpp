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

vector<int> prefix_fun(string &see){
    vector<int> phi(see.size());
    for(int i = 1,j = 0; i < see.size();++i){
        while(j && see[i] != see[j]) j = phi[j-1];
        if(see[i] == see[j]) ++j;
        phi[i] = j;
    }
    return phi;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string see;
    cin >> see;
    auto check = prefix_fun(see);
    vector<ll> ans(check.size()+1);
    for(int i = 0; i < check.size();++i)
        ++ans[check[i]];
    for(int i = check.size()-1; i > 0;--i)
        ans[check[i-1]] += ans[i];
    for(int i = 0; i <= check.size();++i)
        ans[i]++;

    int i = check.back();
    vector<pll> defAns;
    while(i){
        defAns.pb({i,ans[i]});
        i = check[i-1];
    }
    reverse(defAns.begin(),defAns.end());
    defAns.pb({see.size(),1});

    cout << defAns.size() << "\n";
    for(auto va:defAns)
        cout << va.ff << " " << va.ss << "\n";
    return 0;
}
