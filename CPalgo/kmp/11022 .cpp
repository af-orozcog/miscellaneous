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

int dp[81][81];
string see;

vector<int> prefix_fun(int l, int r){
    vector<int> phi(r-l+1);
    phi[0] = 0;
    for(int i = 1, j = 0; i < phi.size();++i){
        while(j && see[i+l] != see[j+l]) j = phi[j-1];
        if(see[i+l] == see[j+l]) ++j;
        phi[i] = j;
    }
    return phi;
}

int go(int i, int j){
    if(i  > j) return 0;
    if(i == j) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    auto check = prefix_fun(i,j);
    int ans = 1+go(i+1,j);
    if(i == 2 && j == 12){
        int lel = 10;
    }
    for(int k = i+1; k <= j;++k){
        int imp = (k-i+1)-check[k-i];
        if((k-i+1) % imp == 0 && check[k-i])
            ans = min(ans,go(i,i+imp-1)+go(k+1,j));
    }
    return dp[i][j] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> see){
        if(see == "*") break;
        memset(dp,-1,sizeof(dp));
        cout << go(0,see.size()-1) << "\n";
    }
    return 0;
}
