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


vector<ll> vals;

struct node{
    node *left = nullptr, *right = nullptr;
    ll sum = 0;
    ll lazy = 0;
};


void push(node *v){
    if(!v->lazy) return;
    v->left->lazy += v->lazy;
    v->right->lazy += v->lazy;
    v->left->sum += v->lazy;
    v->right->sum += v->lazy;

    v->lazy = 0;
}

void build(node *v, int low, int high){
    if(low == high){
        v->sum = vals[low];
        return;
    }

    v->left = new node(), v->right = new node();
    int mid = (low+high)>>1;
    build(v->left,low,mid);
    build(v->right,mid+1,high);
    v->sum = min(v->left->sum,v->right->sum);
}

void update(node *v, int low, int high, int l, int r, ll val){
    if(l > r) return;
    if(low >= l && high <= r){
        v->lazy += val;
        v->sum += val;
        return;
    }
    push(v);
    int mid = (low+high)>>1;
    if(l <= mid)
        update(v->left,low,mid,l,r,val);
    if(r > mid)
        update(v->right,mid+1,high,l,r,val);

    v->sum = min(v->left->sum,v->right->sum);
}

int query(node *v, int low, int high, int l, int r){
    if(low > r || high < l) return INT_MAX;
    if(low >= l && high <= r) return v->sum;
    push(v);
    int mid = (low+high)>>1;
    int left = query(v->left,low,mid,l,r);
    int right = query(v->right,mid+1,high,l,r);
    return min(left,right);
}

void deleteTree(node *v){
    if(v->left)
        deleteTree(v->left);
    if(v->right) deleteTree(v->right);
    delete v;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    node *tree = nullptr;
    int n; cin >> n;
    vals.resize(n);
    for(auto &va:vals) cin >> va;
    ll ans = 0;
    tree = new node();
    build(tree,0,n-1);
    vector<int> bad(n);
    vector<int> sBad(n);
    vector<vector<int>> who(n+1);
    vector<ll> precal(n+1,0);
    for(int i = n-1; i > -1;--i){
        update(tree,0,n-1,i+1,n-1,-1);
        int lo = i, hi = n-1;
        int rightM = i;
        while(lo <= hi){
            int mid = (lo+hi)>>1;
            if(query(tree,0,n-1,i+1,mid) > 0){
                rightM = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        ans += (rightM-i+1);
        bad[i] = rightM + 1;
        who[rightM+1].pb(i);
        ++rightM;
        lo = rightM, hi = n - 1;
        while(lo <= hi){
            int mid = (lo+hi)>>1;
            if(query(tree,0,n-1,i+1,mid) > 0){
                rightM = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        sBad[i] = min(rightM,n-1);
        precal[i] = sBad[i] - bad[i] + 1LL;
    }

    for(int i = 1; i < precal.size();++i)
        precal[i] += precal[i-1];

    for(auto &va: who)
        sort(va.begin(),va.end());

    int q; cin >> q;
    while(q--){
        int p,x;
        cin >> p >> x;
        --x;
        int mi = x - p + 1;
        int check = lower_bound(who[x].begin(),who[x].end(),mi) - who[x].begin();
        ll add = 0;
        if(check < who[x].size()){
            add = precal[who[x].back()];
            if(who[x][check] > 0) add -= precal[who[x][check]-1];
        }

        cout << ans + add << "\n";
    }
    return 0;
}

