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
    int marked = -1;
    node(){}
};

void build(node *v, int low, int high){
    if(low == high) return;

    v->left = new node(), v->right = new node();
    int mid = (low+high)>>1;
    build(v->left,low,mid);
    build(v->right,mid+1,high);
}

void push(node *v){
    if(v->left->marked == -1)
        v->left->marked = v->marked;
    if(v->right->marked == -1)
        v->right->marked = v->marked;
}

void update(node *v, int low, int high,int l, int r, int val){
    if(l > r) return;
    if(low >= l && high <= r){
        if(v->marked == -1)
            v->marked = val;
        return;
    }
    push(v);
    int mid = (low+high)>>1;
    if(l <= mid)
        update(v->left,low,mid,l,r,val);
    if(r > mid)
        update(v->right,mid+1,high,l,r,val);
}


int query(node *v, int low, int high, int pos){
    if(low == pos && high == pos)
        return v->marked;
    push(v);
    int mid = (low+high)>>1;
    if(pos <= mid)
        return query(v->left,low,mid,pos);
    else
        return query(v->right,mid+1,high,pos);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin >> n >> q;
    node *head = new node();
    build(head,1,n);
    while(q--){
        int l,r,x;
        cin >> l >> r >> x;
        update(head,1,n,l,x-1,x);
        update(head,1,n,x+1,r,x);
    }
    for(int i = 1; i <= n;++i){
        int check = query(head,1,n,i);
        cout << (check != -1? check: 0) << " ";
    }
    cout << "\n";
    return 0;
}
