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
const int N = 32768;
const ld eps = 1e-9;
const ll mod = 998244353;
const ll lel = 1e12;

ll fastSum(ll n){
    return (n*(n+1))>>1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums;
        for(int i = 1; i <= (1<<n);++i) nums.pb(i);
        while(nums.size() > 2){
            vector<int> temp;
            for(int i = 0; i < nums.size();i+=4){
                cout << "? "<< nums[i] << " " << nums[i+3] << "\n";
                cout.flush();
                int ans;
                cin >> ans;
                if(ans == 1){
                    cout << "? "<< nums[i] << " " << nums[i+2] << "\n";
                    cout.flush();
                    cin >> ans;
                    if(ans == 1)
                        temp.pb(nums[i]);
                    else if(ans == 2)
                        temp.pb(nums[i + 2]);
                    else temp.pb(nums[i]);
                } else if(ans == 2) {
                    cout << "? " << nums[i + 1] << " " << nums[i + 3] << "\n";
                    cout.flush();
                    cin >> ans;
                    if(ans == 1)
                        temp.pb(nums[i + 1]);
                    else if(ans == 2)
                        temp.pb(nums[i + 3]);
                    else temp.pb(nums[i + 1]);
                } else {
                    cout << "? " << nums[i + 1] << " " << nums[i + 2] << "\n";
                    cout.flush();
                    cin >> ans;
                    if(ans == 1)
                        temp.pb(nums[i + 1]);
                    else if(ans == 2)
                        temp.pb(nums[i + 2]);
                    else temp.pb(nums[i + 1]);
                }
            }
            nums = temp;
        }
        cout << "? " << nums[0] << " " << nums[1] << "\n";
        cout.flush();
        int ans;
        cin >> ans;
        if(ans == 1) cout << nums[0] << "\n";
        else cout << nums.back() << "\n";
        cout.flush();
    }
    return 0;
}

