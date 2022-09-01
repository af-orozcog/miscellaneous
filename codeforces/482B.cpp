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

vector<int> values;

struct node {
    node *left = nullptr, *right = nullptr;
    int val;
};

void build(node *head, int l, int r){
    if(l == r){
        head->val = values[l];
        return;
    }
    head->left = new node(), head->right = new node();
    build(head->left,l,(l+r)>>1);
    build(head->right,((l+r)>>1)+1,r);
    head->val = head->left->val|head->right->val;
}

void build(node *head){
    build(head,0,values.size()-1);
}

int query(node *head, int l, int r, int lq,int rq){
    if(l >= lq && r < rq) return head->val;
    if(rq <= l || lq > r) return 0;
    return query(head->left,l,(l+r)>>1,lq,rq)|query(head->right,((l+r)>>1)+1,r,lq,rq);
}

int query(node *head, int lq, int rq){
    return query(head,0,values.size()-1,lq,rq);
}

void update(node *head,int pos, int val, int l, int r){
    if(l == r){
        head->val = val;
        return;
    }
    int mid = (l+r)>>1;
    if(pos <= mid)
        update(head->left,pos,val,l,mid);
    else
        update(head->right,pos,val,mid+1,r);
    head->val = head->left->val|head->right->val;
}

void update(node *head, int pos, int val){
    return update(head,pos, val, 0, values.size()-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int temp,m;
    cin >> temp >> m;
    int n = (1<<temp);
    values.resize(n);
    for(auto &va:values) cin >> va;
    node *head = new node();
    build(head);
    while(m--){
        int p, val;
        cin >> p >> val;
        --p;
        update(head,p,val);
        cout << query(head,0,n) << "\n";
    }
    return 0;
}
