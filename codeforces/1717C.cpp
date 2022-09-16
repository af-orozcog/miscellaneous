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

vector<int> toUse;
vector<vector<int>> stMin;
vector<vector<int>> stMax;

void build(){
    stMin.clear();
    stMax.clear();
    int imp = log2(toUse.size());
    int n = toUse.size();
    stMin.resize(imp+1,vector<int>(n));
    stMax.resize(imp+1,vector<int>(n));

    stMin[0] = stMax[0] = toUse;

    for(int j = 1; j <= imp;++j){
        for(int i = 0; (i+(1<<j)) <= n;++i){
            stMin[j][i] = min(stMin[j-1][i],stMin[j-1][i+(1<<(j-1))]);
            stMax[j][i] = max(stMax[j-1][i],stMax[j-1][i+(1<<(j-1))]);
        }
    }
}

int queryMin(int l, int r){
    if(l >= stMin[0].size()) return INT_MAX;
    int imp = log(r-l+1);
    return min(stMin[imp][l],stMin[imp][r-(1<<imp)+1]);
}

int queryMax(int l, int r){
    int imp = log(r-l+1);
    return max(stMax[imp][l],stMax[imp][r-(1<<imp)+1]);
}

int firstBiggest(int l, int r, int val){
    int lo = l, hi = r;
    int ans = -1;
    while(lo <= hi){
        int mid = (lo+hi)>>1;
        if(queryMax(l,mid) >= val){
            ans = mid;
            hi = mid -1;
        }
        else lo = mid + 1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n),b(n);
        for(auto &va:a) cin >> va;
        for(auto &va:b) cin >> va;
        bool posi = 1;
        toUse = b;
        build();
        for(int i = n-1; i > -1 && posi;--i){
            if(a[i] == b[i]) continue;
            if(a[i] > b[i]){
                posi = 0;
                continue;
            }
            int nextBiggest = firstBiggest(i+1,n-1,b[i]-1);
            if(nextBiggest == -1)
                nextBiggest = firstBiggest(0,n-1,b[i]-1);
            if(nextBiggest <= i){
                int small1 = queryMin(i+1,n-1);
                int small2 = queryMin(0,nextBiggest);
                if(min(small1,small2) < b[i]-1) posi = 0;
            }
            else{
                int small1 = queryMin(i+1,nextBiggest);
                if(small1 < b[i]-1) posi = 0;
            }
        }
        if(posi) cout << "YES";
        else cout << "NO";
        cout << "\n";
    }
    return 0;
}
