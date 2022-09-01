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
    vector<int> phi(see.size(),0);
    for(int i = 1, j = 0; i < see.size();++i){
        while(j && see[j] != see[i]) j = phi[j-1];
        if(see[i] == see[j]) ++j;
        phi[i] = j;
    }
    return phi;
}

bool good(string &needle, string &see){
    string send = needle + "#" + see;
    auto check = prefix_fun(send);
    int found = 0;

    for(int i = needle.size()+1; i < check.size();++i)
        found += (check[i] == needle.size());

    return found == 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string alpa, needle, see;
        cin >> alpa >> needle >> see;
        map<char,int> mp;
        for(int i = 0; i < alpa.size();++i){
            mp[alpa[i]] = i;
        }
        vector<int> sols;
        for(int i = 1; i <= alpa.size();++i){
            string toUse = "";
            for(auto va:needle)
                toUse += alpa[(mp[va]+i)%alpa.size()];
            if(good(toUse,see))
                sols.pb(i%alpa.size());
        }
        sort(sols.begin(),sols.end());
        if(!sols.size()) cout << "no solution\n";
        else if(sols.size() == 1) cout << "unique: " << sols.back() << "\n";
        else{
            cout << "ambiguous:";
            for(auto va:sols) cout << " " << va;
            cout << "\n";
        }
    }
    return 0;
}
