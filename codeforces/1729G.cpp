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


vector<int> prefix(string &s){
    vector<int> ans(s.size(),0);
    for(int i = 1,j = 0; i < s.size();++i){
        while(j && s[i] != s[j]) j = ans[j-1];
        if(s[i] == s[j])++j;
        ans[i] = j;
    }

    return ans;
}

vector<int>toUse(vector<int> &see,string &fi, string &se){
    vector<int> ans(see.size()-se.size());
    for(int i = fi.size()+1,j = 0; i < see.size();++i,++j){
        if(see[i] == fi.size()){
            ans[j-fi.size()+1] = 1;
        }
    }

    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string fi,se;
        cin >> fi >> se;
        string temp = se;
        se += "@";
        temp += se;
        vector<int> imp = prefix(temp);
        imp = toUse(imp,fi,se);
        vector<vector<pll>> dp(2,vector<pll>(fi.size()+1,{0,0}));
        dp[0].back() = {0,1};
        for(int i = fi.size()-1;i > -1;--i){
            if(imp[i]){
                dp[1][i] = {1 + dp[0][i+se.size()].ff,dp[0][i+se.size()].ss};
                dp[0][i] = {INT_MAX,INT_MAX};
                for(int j = i+1; j < i+se.size();++j){
                    if(imp[j])
                        dp[0][i].ff = min(dp[1][j].ff,dp[0][i].ff);
                }
                for(int j = i+1; j < i+se.size();++j){
                    if(imp[j] && dp[1][j].ff == dp[0][i].ff){
                        dp[0][i].ss += dp[1][j].ss;
                        if(dp[0][i].ss >= mod) dp[0][i].ss -= mod;
                    }
                }
                if(dp[1][i].ff == dp[0][i].ff){
                    dp[0][i].ss += dp[1][i].ss;
                    if(dp[0][i].ss >= mod) dp[0][i].ss -= mod;
                }
            }
            else dp[0][i] = dp[0][i+1];
        }

        cout << dp[0][0].ss << "\n";
    }
    return 0;
}
