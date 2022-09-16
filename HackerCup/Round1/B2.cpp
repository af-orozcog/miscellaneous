// Is love even real?
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

const ll mod = 1e9 + 7;

pair<vector<ll>,vector<ll>> ascending(vector<ll> &nums){
    vector<ll> ans(nums.size());

    int n = nums.size();


    for(ll i = 0; i < n;++i){
        ll difX = 0;
        if(i){
            difX = xAscending[i] - xAscending[i-1];
            if(difX >= mod) difX %= mod;
            difX *= i;
            if(difX >= mod) difX %= mod;
            difY = yAscending[i] - yAscending[i-1];
            if(difY >= mod) difY %= mod;
            difY *= i;
            if(difY >= mod) difY %= mod;
            acumxAscending[i] = acumxAscending[i-1] + difX;
            acumyAscending[i] = acumyAscending[i-1] + difY;
            if(acumxAscending[i] >= mod) acumxAscending[i] %= mod;
            if(acumyAscending[i] >= mod) acumyAscending[i] %= mod;
        }
    }
}

vector<ll> descending(vector<ll> &nums){

}

ll queries(int x, vector<ll> &preComputed, vector<ll> &nums){

}


int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    cin >> t;
    int cas = 1;
    while(t--){
        cout << "Case #" << cas++ << ": ";
        int n;
        cin >> n;
        vector<ll> xAscending,yAscending;
        for(int i = 0; i < n;++i){
            ll x,y;
            cin >> x >> y;
            xAscending.pb(x), yAscending.pb(y);
        }
        sort(xAscending.begin(),xAscending.end());
        sort(yAscending.begin(),yAscending.end());
        vector<ll> acumxAscending(n,0),acumxDescendidng(n,0),acumyAscending(n,0),acumyDescending(n,0);

        for(ll i = 0; i < n;++i){
            ll difX = 0;
            ll difY = 0;
            if(i){
                difX = xAscending[i] - xAscending[i-1];
                if(difX >= mod) difX %= mod;
                difX *= i;
                if(difX >= mod) difX %= mod;
                difY = yAscending[i] - yAscending[i-1];
                if(difY >= mod) difY %= mod;
                difY *= i;
                if(difY >= mod) difY %= mod;
                acumxAscending[i] = acumxAscending[i-1] + difX;
                acumyAscending[i] = acumyAscending[i-1] + difY;
                if(acumxAscending[i] >= mod) acumxAscending[i] %= mod;
                if(acumyAscending[i] >= mod) acumyAscending[i] %= mod;
            }
        }

        for(ll i = n-1,j = 0; i > -1;--i,++j){
            ll difX = 0;
            ll difY = 0;
            if(i != n-1){
                difX = xAscending[i+1] - xAscending[i];
                if(difX >= mod) difX %= mod;
                difX *= j;
                if(difX >= mod) difX %= mod;
                difY = yAscending[i+1] - yAscending[i];
                if(difY >= mod) difY %= mod;
                difY *= j;
                if(difY >= mod) difY %= mod;
                acumxDescendidng[i] = acumxDescendidng[i+1] + difX;
                acumyDescending[i] = acumyDescending[i+1] + difY;
                if(acumxDescendidng[i] >= mod) acumxDescendidng[i] %= mod;
                if(acumyDescending[i] >= mod) acumyDescending[i] %= mod;
            }
        }

        ll ans = 0;

        int q;
        cin >> q;

        while(q--){
            ll x,y;
            cin >> x >> y;
            ll sumLeft = 0, sumRight = 0, sumUp = 0, sumDown = 0;

            ll left = upper_bound(xAscending.begin(),xAscending.end(),x) - xAscending.begin();
            --left;
            if(left > -1){
                ll dif = x - xAscending[left];
                if(dif >= mod) dif %= mod;
                dif *= (left+1);
                sumLeft = acumxAscending[left] + dif;
                if(sumLeft >= mod) sumLeft %= mod;
                sumLeft *= sumLeft;
                if(sumLeft >= mod) sumLeft %= mod;
            }
            ++left;
            if(left < n){
                ll dif = xAscending[left] - x;
                if(dif >= mod) dif %= mod;
                dif *= (n-left);
                sumRight = acumxDescendidng[left] + dif;
                if(sumRight >= mod) sumRight %= mod;
                sumRight *= sumRight;
                if(sumRight >= mod) sumRight %= mod;
            }

            ll up = upper_bound(yAscending.begin(),yAscending.end(),y) - yAscending.begin();

            --up;
            if(up > -1){
                ll dif = y - yAscending[up];
                if(dif >= mod) dif %= mod;
                dif *= (up+1);
                sumUp = acumyAscending[up] + dif;
                if(sumUp >= mod) sumUp %= mod;
                sumUp *= sumUp;
                if(sumUp >= mod) sumUp %= mod;
            }
            ++up;
            if(up < n){
                ll dif = yAscending[up] - y;
                if(dif >= mod) dif %= mod;
                dif *= (n-up);
                sumDown = acumyDescending[up] + dif;
                if(sumDown >= mod) sumDown %= mod;
                sumDown *= sumDown;
                if(sumDown >= mod) sumDown %= mod;
            }

            ans += sumLeft;
            if(ans >= mod) ans -= mod;
            ans += sumRight;
            if(ans >= mod) ans -= mod;
            ans += sumDown;
            if(ans >= mod) ans -= mod;
            ans += sumUp;
            if(ans >= mod) ans -= mod;
        }

        cout << ans << "\n";
    }
    return 0;
}
