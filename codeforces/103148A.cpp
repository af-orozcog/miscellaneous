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
#define bint __int128

ll lcm(ll a, ll b){
    return (a/__gcd(a,b))*b;
}

ll comp1(int from, int upTo){
    ll ans = 1;
    for(int i = from;i <= upTo;++i)
        ans = lcm(ans,i);

    ll defAns = 0;
    while(ans && ans % 10 == 0) ++defAns, ans /= 10;
    return defAns;
}

int comp2(ll a, ll b){
    int biggest5 = 0,biggest2 = 0;
    ll now = 1;
    int temp = 0;
    while(now <= b){
        ll imp = a/now;
        if(imp * now < a) ++imp;
        if(imp * now <= b) biggest5 = temp;
        if(LLONG_MAX / now < 5)break;
        now *= 5;
        ++temp;
    }
    now = 1;
    temp = 0;
    while(now <= b){
        ll imp = a/now;
        if(imp * now < a) ++imp;
        if(imp * now <= b) biggest2 = temp;
        if(LLONG_MAX / now < 2)break;
        now *= 2;
        ++temp;
    }
    return min(biggest2,biggest5);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b;
    cin >> a >> b;
    cout << comp2(a,b) << "\n";
    /*for(int i = 1; i <= 40;++i){
        for(int j = 1; j <= 40;++j){
            ll a = comp1(i,j);
            ll b = comp2(i,j);
            if(a != b){
                cout << i << " " << j << " comp1 " << a << " comp2 " << b << "\n";
            }
        }
    }*/
    return 0;
}
