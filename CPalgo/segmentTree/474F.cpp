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

vector<int> vals;

struct node{
    node *left = nullptr, *right = nullptr;
    int gcd = -1,minVal = INT_MAX, times = 0;
    node(){}
};


void merge(node *v){
    v->gcd = __gcd(v->left->gcd, v->right->gcd);
    int mi = min(v->left->minVal,v->right->minVal);
    v->minVal = mi;
    if(v->left->minVal == mi) v->times += v->left->times;
    if(v->right->minVal == mi) v->times += v->right->times;
}

void build(node *v, int low, int high){
    if(low == high){
        v->gcd = v->minVal = vals[low];
        v->times = 1;
        return;
    }

    v->left = new node(),v->right = new node();
    int mid = (low+high)>>1;
    build(v->left,low,mid);
    build(v->right,mid+1,high);
    merge(v);
}

node query(node *v, int low, int high, int l, int r){
    if(r < low || l > high){
        node ans;
        return ans;
    }
    if(low >= l && r >= high)
        return *v;
    int mid = (low+high)>>1;
    node left = query(v->left,low,mid,l,r);
    node right = query(v->right,mid+1,high,l,r);
    if(left.gcd == -1) left = right;
    else if(right.gcd == -1) right = left;
    node temp;
    temp.left = &left, temp.right = &right;
    merge(&temp);
    return temp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vals.resize(n);
    for(auto &va:vals) cin >> va;
    int q; cin >> q;
    node *head = new node();
    build(head,0,n-1);
    while(q--){
        int l,r;
        cin >> l >> r;
        node check = query(head,0,n-1,l-1,r-1);
        if(check.gcd % check.minVal == 0)
            cout << check.times << "\n";
        else cout << 0 << "\n";
    }

    return 0;
}
