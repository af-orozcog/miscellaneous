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

struct node{
    node *left = nullptr, *right = nullptr;
    ll ans = 0;
    ll blocked = 0, free = 0;
    ll lazy = 0;
    node(){}
};

vector<ll> vals;
vector<ll> blocked;

void merge(node *v){
    v->blocked = v->left->blocked + v->right->blocked;
    v->free = v->left->free + v->right->free;
    v->ans = v->left->ans + v->right->ans;
}

void build(node *v,int low, int high){
    if(low == high){
        v->ans = vals[low];
        v->free = (blocked[low]);
        v->blocked = 1 - v->free;
        return;
    }
    v->left = new node(), v->right = new node();
    int mid = (low+high)>>1;
    build(v->left,low,mid);
    build(v->right,mid+1,high);
    merge(v);
}

void push(node *v){
    if(!v->lazy)return;
    v->left->lazy += v->lazy;
    v->left->ans += (v->left->free * v->lazy);

    v->right->lazy += v->lazy;
    v->right->ans += (v->right->free * v->lazy);

    v->lazy = 0;
}

void update(node *v, int low, int high, int l, int r, ll val){
    if(low >= l && high <= r){
        if(v->free){
            v->lazy += val;
            v->ans += (v->free * val);
        }
        return;
    }
    push(v);
    int mid = (low+high)>>1;
    if(l <= mid)
        update(v->left,low,mid,l,r,val);
    if(r > mid)
        update(v->right,mid+1,high,l,r,val);
    merge(v);
}

void update(node *v, int low, int high, int pos, int val){
    if(low == high){
        v->free = val;
        v->blocked = 1LL - (v->free);
        return;
    }
    push(v);
    int mid = (low+high) >> 1;
    if(pos <= mid)
        update(v->left,low,mid,pos,val);
    else
        update(v->right,mid+1,high,pos,val);
    merge(v);
}

ll query(node *v,int low, int high, int l, int r){
    if(r < low || l > high)
        return 0;
    if(low >= l && high <= r) return v->ans;
    push(v);
    int mid = (low+high)>>1;
    ll left = query(v->left,low,mid,l,r);
    ll right = query(v->right,mid+1,high,l,r);
    return left + right;
}

int main(){
    int n,q;
    cin >> n >> q;
    vals.resize(n);
    blocked.resize(n);
    for(auto &va:vals) cin >> va;

    for(auto &va:blocked) cin >> va;

    node *head = new node();
    build(head,0,n-1);

    while(q--){
        int type; cin >> type;
        if(type == 1){
            int val; cin >> val;
            update(head,0,n-1,val-1,0);
        }
        else if(type == 2){
            int val; cin >> val;
            update(head,0,n-1,val-1,1);
        }
        else if(type == 3){
            int l,r,val;
            cin >> l >> r >> val;
            update(head,0,n-1,l-1,r-1,val);
        }
        else{
            int l,r; cin >> l >> r;
            cout << query(head,0,n-1,l-1,r-1) << "\n";
        }
    }
    return 0;
}
