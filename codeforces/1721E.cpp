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
string s;
vector<vector<int>> automaton;
vector<int> pi;

void prefix_fun(){
    vector<int> ans(s.size());
    ans[0] = 0;
    for(int i = 1,j = 0; i < s.size();++i){
        while(j && s[i] != s[j])
            j = ans[j-1];
        if(s[i] == s[j]) ++j;
        ans[i] = j;
    }
    pi = ans;
}

void buildAutomaton(){
    automaton.resize(s.size(),vector<int>(26,0));
    for(int i = 0; i < s.size();++i){
        for(int j = 0; j < 26;++j){
            if(i && s[i] != ('a' + j))
                automaton[i][j] = automaton[pi[i-1]][j];
            else
                automaton[i][j] = i + ('a' + j == s[i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    int q;
    cin >> q;
    prefix_fun();
    buildAutomaton();
    while(q--){
        string t;
        cin >> t;
        for(int i = s.size(); i < s.size() + t.size();++i){
            automaton.pb(vector<int>(26,0));
            for(int j = 0; j < 26;++j){
                if(i && t[i-s.size()] != ('a' + j))
                    automaton[i][j] = automaton[pi[i-1]][j];
                else{
                    automaton[i][j] = i + ('a' + j == t[i-s.size()]);
                }
            }
            pi.pb(automaton[pi[i-1]][t[i-s.size()]-'a']);
            cout << pi.back() << " ";
        }
        for(int i = 0; i < t.size();++i){
            pi.pop_back(); automaton.pop_back();
        }
        cout << "\n";
    }

    return 0;
}
