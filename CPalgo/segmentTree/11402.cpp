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

const char iden = 'N';
struct node {
    node *left = nullptr, *right = nullptr;
    int val = iden;
    char lazy = iden;
    int len = 0;
    node() {}
};

vector<int> vals;

void build(node *v, int low, int high){
    if(low == high) {
        v->val = vals[low];
        v->len = 1;
        return;
    }
    int mid = (low+high)>>1;
    v->left = new node(), v->right = new node();
    build(v->left,low,mid);
    build(v->right,mid+1,high);
    v->val = v->left->val + v->right->val;
    v->len = (high-low)+1;
}

void set_utype(node *v, char type){
    if(!v) return;
    if(type == 'I'){
        switch(v->lazy){
             case 'F': v->lazy = 'E'; break;
             case 'E': v->lazy = 'F'; break;
             case 'I': v->lazy = iden; break;
             case iden: v->lazy = 'I'; break;
        }
    }
    else
        v->lazy = type;
}

void change(node *v){
    switch(v->lazy){
        case 'F': v->val = v->len; break;
        case 'E': v->val = 0; break;
        case 'I': v->val = v->len - v->val; break;
        default: return;
    }
    set_utype(v->left,v->lazy);
    set_utype(v->right,v->lazy);
    v->lazy = iden;
}

void update(node *v,int low, int high, int l, int r, char value){
    if(l > high || r < low || low > high) return;
    if(low >= l && high <= r)
        set_utype(v,value);
    int mid = (low+high)>>1;
    change(v);
    if(low >= l && high <= r) return;
    if(l <= mid)
        update(v->left,low,mid,l,r,value);
    if(r > mid)
        update(v->right,mid+1,high,l,r,value);
    v->val = v->left->val + v->right->val;
}

int query(node *v,int low, int high,int l, int r){
    change(v);
    if(l>high || r < low || low > high) return 0;
    if(low >= l && high <= r) return v->val;
    int mid = (low+high)>>1;
    return query(v->left,low,mid,l,r) + query(v->right,mid+1,high,l,r);
}


void deleteTree(node *v){
    if(v->left)
        deleteTree(v->left);
    if(v->right)
        deleteTree(v->right);
    delete v->left;
    delete v->right;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int cas = 1;
    node *head = new node();
    while(t--){
        cout << "Case " << cas++ << ":\n";
        int m;
        cin >> m;
        while(m--){
            int times; cin >> times;
            string see;
            getline(cin,see);
            getline(cin,see);
            while(times--){
                for(auto va:see)
                    vals.pb(va-'0');
            }
        }
        build(head,0,vals.size()-1);
        int q; cin >> q;
        int qu = 1;
        while(q--){
            char op;
            int lo,hi;
            cin >> op >> lo >> hi;
            if(op == 'S')
                cout << "Q" << qu++ << ": "<<query(head,0,vals.size()-1,lo,hi) << "\n";
            else
                update(head,0,vals.size()-1,lo,hi,op);
        }
        deleteTree(head);
        vals.clear();
    }
    return 0;
}
