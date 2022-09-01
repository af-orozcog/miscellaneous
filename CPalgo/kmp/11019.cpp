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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<vector<char>> mat1(n,vector<char>(m));
        for(auto &row:mat1){
            for(auto &val:row) cin >> val;
        }
        int x,y;
        cin >> x >> y;
        string check = "";
        for(int i = 0; i < x*y;++i){
            char temp; cin >> temp;
            check += temp;
        }
        check += "#";
        buildAutomaton(check);
        int ans = 0;
        for(int c = 0; c <= m-y;++c){
            int state = 0;
            for(int r = 0; r < n;++r){
                for(int c2 = 0; c2 < y;++c2)
                    state = automaton[state][mat1[r][c+c2]-'a'];
                if(state == check.size()-1 && r >= x-1) ++ans;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
