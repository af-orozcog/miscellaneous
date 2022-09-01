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

vector<vector<int>> automaton;

void buildAutomaton(string &see){
    automaton.resize(see.size()+1,vector<int>(26));
    vector<int> phi = {0};
    for(int i = 0; i < see.size();++i){
        for(int j = 0; j < 26;++j){
            if(i && see[i] != j+'a')
                automaton[i][j] = automaton[phi[i-1]][j];
            else
                automaton[i][j] = i + (see[i] == 'a'+j);
        }
        if(i)
            phi.pb(automaton[phi.back()][see[i]-'a']);
    }
    for(int j = 0; j < 26;++j)
        automaton[see.size()][j] = automaton[phi.back()][j];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    cin >> s >> t;
    buildAutomaton(t);
    vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,INT_MIN));
    dp[0][0] = 0;
    for(int i = 1; i <= s.size();++i){
        for(int j = 0;j <= t.size();++j){
            if(s[i-1] == '?'){
                for(int let = 0; let < 26;++let)
                    dp[i][automaton[j][let]] = max(dp[i-1][j]+ (automaton[j][let] == t.size()),dp[i][automaton[j][let]]);
            }
            else
                dp[i][automaton[j][s[i-1]-'a']] = max(dp[i-1][j] + (automaton[j][s[i-1]-'a'] == t.size()),dp[i][automaton[j][s[i-1]-'a']]);
        }
    }
    int ans = 0;
    for(auto va:dp.back()) ans = max(ans,va);

    cout << ans << "\n";
    return 0;
}
