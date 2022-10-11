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


vector<vector<int>> dp1;
vector<vector<int>> dp2;
string u,v;


int go1(int i, int j){
    if(i > j) return 1;
    if(j-i == 0) return 0;
    if(dp1[i][j] != -1) return dp1[i][j];
    bool ans = 0;
    if(u[i] == u[j])
        ans |= go1(i+1,j-1);
    if(u[i] == u[i+1])
        ans |= go1(i+2,j);
    if(j-i >= 3 && (u.substr(i,4) == "ABAB" || u.substr(i,4) == "BCBC"))
        ans |= go1(i+4,j);
    return dp1[i][j] = ans;
}

int go2(int i, int j){
    if(i > j) return 1;
    if(j-i == 0) return 0;
    if(dp2[i][j] != -1) return dp2[i][j];
    bool ans = 0;
    if(v[i] == v[j])
        ans |= go2(i+1,j-1);
    if(v[i] == v[i+1])
        ans |= go2(i+2,j);
    if(j-i >= 3 && (v.substr(i,4) == "ABAB" || v.substr(i,4) == "BCBC"))
        ans |= go2(i+4,j);
    return dp2[i][j] = ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> u >> v;

        dp1.resize(u.size(),vector<int>(u.size(),-1));
        dp2.resize(v.size(),vector<int>(v.size(),-1));

        for(int i = 0; i < u.size();++i){
            for(int j = i; j < u.size();++j)
                go1(i,j);
        }

        for(int i = 0; i < v.size();++i){
            for(int j = i; j < v.size();++j)
                go2(i,j);
        }

        vector<vector<bool>> dp(u.size()+1,vector<bool>(v.size()+1,false));



        dp[0][0] = 1;
        for(int i = 1; i <= v.size();++i)
            dp[0][i] = go2(0,i-1);

        for(int i = 1; i <= u.size();++i)
            dp[i][0] = go1(0,i-1);


        for(int i = 1;i <= u.size();++i){
            for(int j = 1; j <= v.size();++j){
                if(u[i-1] == v[i-1]){
                    dp[i][j] |= dp[i-1][j-1];
                }
                if(i >= 2 && (
                        u.substr(i-2,2) == "AA" ||
                        u.substr(i-2,2) == "BB" ||
                        u.substr(i-2,2) == "CC"))
                        dp[i][j] |= dp[i-2][j];
                if(j >= 2 && (
                        u.substr(j-2,2) == "AA" ||
                        u.substr(j-2,2) == "BB" ||
                        u.substr(j-2,2) == "CC"))
                        dp[i][j] |= dp[i][j-2];
                if(i >= 4 && (
                        u.substr(i-4,4) == "ABAB" ||
                        u.substr(i-4,4) == "BCBC"))
                        dp[i][j] |= dp[i-4][j];
                if(j >= 4 && (
                        u.substr(j-4,4) == "ABAB" ||
                        u.substr(j-4,4) == "BCBC"))
                        dp[i][j] |= dp[i][j-4];

            }
        }


        if(dp[u.size()][v.size()]) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
