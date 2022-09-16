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

vector<int> imp;

void generateNums(int now, int index, int maximum){
    if(index == maximum){
        imp.pb(now);
        return;
    }
    generateNums(now*10 + 4, index+1, maximum);
    generateNums(now*10 + 7, index+1, maximum);
}

struct node{
    node *left = nullptr, *right = nullptr;
    int lazy = 0, amount = 0, ans = 0;
    node(){}
};

vector<int> values;
vector<int> actual;

void merge(node *v){
    v->ans = min(v->left->ans,v->right->ans);
    if(v->left->ans == v->ans) v->amount += v->left->amount;
    if(v->right->ans == v->ans) v->amount += v->right->amount;
}

void build(node *v, int low, int high){
    if(low == high){
        v->ans = values[low];
        while(imp[actual[low]] - v->ans < 0){
            v->ans -= imp[actual[low]++];
        }
        v->ans = imp[actual[low]] - v->ans;
        v->amount = 1;
        ++actual[low];
        return;
    }
    v->left = new node(), v->right = new node();
    int mid = (low+high)>>1;
    build(v->left,low, mid);
    build(v->right,mid+1,high);
    merge(v);
}

void push(node *v){
    if(!v->lazy) return;
    v->left->ans += v->lazy;
    v->left->lazy += v->lazy;

    v->right->ans += v->lazy;
    v->right->lazy += v->lazy;

    v->lazy = 0;
}

void update(node *v, int low, int high, int l, int r, int add){
    if(low >= l && r >= high){
        v->lazy += add;
        v->ans += add;
        return;
    }
    push(v);
    int mid = (low+high)>>1;
    if(l <= mid)
        update(v->left,low,mid,l, r, add);
    if(r > mid)
        update(v->right,mid+1,high,l,r,add);

    merge(v);
}

void clean(node *v,int low, int high, int l, int r){
    if(l > high || r < low) return;
    if(low == high){
        while(imp[actual[low]] - v->ans < 0){
            v->ans -= imp[actual[low]++];
        }
        v->ans = imp[actual[low]] - v->ans;
        v->amount = 1;
        ++actual[low];
    }
    if(low >= l && r >= high){
        if(v->ans >= 0) return;
        int mid = mid + 1;

        clean(v->left,low,mid,l,r);
        clean(v->right,mid+1,high,l,r);

        merge(v);
    }
}

node query(node *v, int low, int high, int l, int r){
    if(l > high || r < low){
        node ans;
        return ans;
    }
    if(low >= l && r >= high) return *v;

    push(v);
    int mid = (low+high) >> 1;
    node left = query(v->left, low, mid, l, r);
    node right = query(v->right, mid+1,high,l,r);
    node temp;
    if(left.amount == 0) temp = right;
    else if(right.amount == 0) temp = left;
    else{
        temp.left = &left;
        temp.right = &right;
        merge(&temp);
    }
    return temp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    actual.resize(n,0);
    imp.pb(0);
    for(int i = 1; i <= 4;++i)
        generateNums(0,0,i);
    imp.pb(1e9);
    vector<int> temp;
    for(int i = 1; i < imp.size();++i)
        temp.pb(imp[i]-imp[i-1]);

    imp = temp;

    values.resize(n);
    for(auto &va:values) cin >> va;

    node *head = new node();
    build(head,0,n-1);

    while(m--){
        string op; int a,b;
        cin >> op;
        if(op[0] == 'c'){
            cin >> a >> b;
            node see = query(head,0,n-1,a-1,b-1);
            int ans = (see.ans == 0? see.amount:0);
            cout << ans << "\n";
        }
        else{
            int add;
            cin >> a >> b >> add;
            update(head,0,n-1,a-1,b-1,-add);
            clean(head,0,n-1,a-1,b-1);
        }
    }

    return 0;
}

