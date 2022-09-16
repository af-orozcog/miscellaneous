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

struct node {
    node *left = nullptr, *right = nullptr;
    ll val = INT_MIN,pre = INT_MIN, suff = INT_MIN,sum = 0;
    node() {}
};

vector<int> vals;

void merge(node *v){
    v->sum = v->left->sum + v->right->sum;
    v->pre = max(v->left->pre, v->left->sum + v->right->pre);
    v->suff = max(v->right->suff, v->right->sum + v->left->suff);
    v->val = max(max(v->left->val,v->right->val), v->left->suff + v->right->pre);
}


void build(node *v, int low, int high){
    if(low == high) {
        v->val = v->pre = v->suff = v->sum = vals[low];
        return;
    }
    int mid = (low+high)>>1;
    v->left = new node(), v->right = new node();
    build(v->left,low,mid);
    build(v->right,mid+1,high);
    merge(v);
}

void update(node *v,int low, int high, int pos, int value){
    if(low == pos && high == pos){
        v->val = v->pre = v->suff = v->sum = value;
        return;
    }
    int mid = (low+high)>>1;
    if(pos <= mid)
        update(v->left,low,mid,pos,value);
    else
        update(v->right,mid+1,high,pos,value);
    merge(v);
}

node query(node *v,int low,int high, int l,int r){
    if(l > high || r < low || low > high){
        node val;
        return val;
    }
    if(low >= l && high <= r)
        return *v;
    int mid = (low+high)>>1;
    node left = query(v->left,low,mid,l,r);
    node right = query(v->right,mid+1,high,l,r);
    node temp = node();
    temp.left = &left;
    temp.right = &right;
    merge(&temp);
    return temp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    node *head = new node();
    int n;
    cin >> n;
    vals.resize(n);
    for(auto &va:vals) cin >> va;
    build(head,0,n-1);
    int q;
    cin >> q;
    while(q--){
        int t, x,y;
        cin >> t >> x >> y;
        if(!t)
            update(head,0,n-1,x-1,y);
        else
            cout << query(head,0,n-1,x-1,y-1).val << "\n";
    }
    return 0;
}
