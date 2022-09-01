
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

vector<int> prefix_fun(string &see){
    vector<int> phi(see.size());
    for(int i = 1,j = 0; i < see.size();++i){
        while(j && see[i] != see[j]) j = phi[j-1];
        if(see[i] == see[j])++j;
        phi[i] = j;
    }
    return phi;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        string send = b + "#" + a;
        auto check = prefix_fun(send);
        vector<int> ans;
        for(int i = b.size()+1; i < check.size();++i){
            if(check[i] == b.size())
                ans.pb(i-b.size()+1-b.size());
        }
        if(!ans.size()) cout << "Not Found\n";
        else{
            cout << ans.size() << "\n";
            for(auto va:ans) cout << va << " ";
            cout << "\n";
        }
        if(t) cout << "\n";
    }
    return 0;
}
