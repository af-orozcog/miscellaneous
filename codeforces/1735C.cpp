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

vector<int> dad;

int find(int x){
    if(dad[x] == x) return x;
    return find(dad[x]);
}

bool sameComponent(int x, int y){
    return find(x) == find(y);
}

void merge(int x, int y){
    int dadX = find(x),dadY = find(y);
    if(dadX != dadY)
        dad[dadX] = dadY;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string see; cin >> see;
        string ans;
        vector<bool> out(26,0);
        dad.resize(26);
        for(int i = 0; i < 26;++i) dad[i] = i;
        map<char,char> whoIn;
        int connected = 0;
        for(auto va: see){
            if(whoIn.count(va))
                ans += whoIn[va];
            else{
                int toUse = -1;
                for(int i = 0; i < 26 && toUse == -1;++i){
                    if(!out[i]){
                        if(connected == 25)
                            toUse = i;
                        else if(!sameComponent((int)(va-'a'),i))
                            toUse = i;
                    }
                }
                //cout << "whaaat " << see << "\n";
                assert(toUse != -1);
                whoIn[va] = toUse+'a';
                ans += whoIn[va];
                out[toUse] = 1;
                merge(va-'a',toUse);
                ++connected;
            }
        }

        cout << ans << "\n";
        dad.clear();
    }
    return 0;
}
