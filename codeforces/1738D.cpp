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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> b(n);
        for(auto &va:b) cin >> va;
        int leq = 0,big = 0;
        int lastLes = -1,lastBig = -1;
        vector<int> bigP,les;
        vector<int> ans(n,-1);
        for(int i = 0;i < n;++i){
            if(b[i] == n+1){
                ++leq;
                les.pb(i);
            }
            else if(b[i] == 0){
                ++big;
                bigP.pb(i);
            }
            else{
                if(b[i] == lastBig)
                    les.pb(i);
                else if(b[i] == lastLes)
                    bigP.pb(i);
                else{
                    if(!bigP.size()){
                        ans[les.back()] = b[i];
                        lastLes = b[i];
                    }
                    else if(!les.size()){
                        ans[bigP.back()] = b[i];
                        lastBig = b[i];
                    }
                    else if(les.back() > bigP.back()){
                        ans[les.back()] = b[i];
                        lastLes = b[i];
                    }
                    else{
                        ans[bigP.back()] = b[i];
                        lastBig = b[i];
                    }
                }
            }
        }

        set<int> check1,check2;
        for(auto va:les){
            if(ans[va] != -1) check1.insert(ans[va]);
        }

        for(auto va:bigP){
            if(ans[va] != -1) check2.insert(ans[va]);
        }

        for(int i = 0, j = 1; i < les.size();++i){
            while(check1.count(j)) ++j;
            if(ans[les[i]] != -1) continue;
            ans[les[i]] = j;
            check1.insert(j);
        }

        for(int i = 0, j = leq+1; i < bigP.size();++i){
            while(check1.count(j)) ++j;
            if(ans[bigP[i]] != -1) continue;
            ans[bigP[i]] = j;
            check1.insert(j);
        }

        cout << leq << "\n";
        for(auto va:ans)
            cout << va << " ";

        cout << "\n";
    }
    return 0;
}
