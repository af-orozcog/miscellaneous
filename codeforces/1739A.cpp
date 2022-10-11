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

int movesX[] = {-1,1,-2,2,-1,1,-2,2};
int movesY[] = {-2,-2,-1,-1,2,2,1,1};


bool valid(int x, int y, int n, int m){
    bool ans = 0;
    for(int i = 0; i < 8 && !ans;++i){
        int neX = x + movesX[i], neY = y + movesY[i];
        if(neX < 0 || neX >= n || neY < 0 || neY >= m) continue;
        ans = 1;
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        int ans = 0;
        for(int i = 0; i < n && !ans;++i){
            for(int j = 0; j < m && !ans;++j){
                if(!valid(i,j,n,m)){
                    cout << i+1 << " " << j+1 << "\n";
                    ans = 1;
                }
            }
        }
        if(!ans) cout << 1 << " " << 1 << "\n";
    }
    return 0;
}
