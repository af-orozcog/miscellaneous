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
    vector<int> ans(see.size());
    ans[0] = 0;
    for(int i = 1,j = 0; i < see.size();++i){
        while(j && see[j] != see[i]) j = ans[j-1];
        if(see[j] == see[i]) ++j;
        ans[i] = j;
    }
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    bool fi = 1;
    while(t--){
        if(!fi) cout << "\n";
        fi = 0;
        string see;
        cin >> see;
        auto check = prefix_fun(see);
        int imp = see.size() - check.back();
        if(see.size() % imp == 0)
            cout << imp << "\n";
        else cout << see.size() << "\n";
    }
    return 0;
}
