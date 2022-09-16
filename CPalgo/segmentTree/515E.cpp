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


struct segTree{
    vector<ll> height;
    vector<ll> position;

    struct node{
        node *left = nullptr, *right = nullptr;
        ll biggestLeft = 0, biggestRight = 0;
        int leftIndex = -1, rightIndex = -1;
        ll ans = 0;
        node(){}
    };

    node *head;


    void merge(node *v){
        v->biggestLeft = max(v->left->biggestLeft + position[v->right->rightIndex] - position[v->left->rightIndex]
                             , v->right->biggestLeft);
        v->biggestRight = max(v->right->biggestRight + position[v->right->leftIndex] - position[v->left->leftIndex],
                              v->left->biggestRight);
        v->leftIndex = v->left->leftIndex;
        v->rightIndex = v->right->rightIndex;
        v->ans = max(v->left->ans,v->right->ans);
        v->ans = max(v->left->biggestLeft + v->right->biggestRight + position[v->right->leftIndex] -
                     position[v->left->rightIndex], v->ans);
    }

    void build(node *v, int low, int high){
        if(low == high){
            v->leftIndex = v->rightIndex = low;
            v->biggestLeft = v->biggestRight =(height[low]<<1);
            return;
        }

        v->left = new node(), v->right = new node();
        int mid = (low+high)>>1;
        build(v->left,low,mid);
        build(v->right,mid+1,high);
        segTree::merge(v);
    }

    void build(vector<ll> &heightTemp, vector<ll> &positionTemp) {
        height = heightTemp;
        position = positionTemp;
        head = new node();
        build(head,0,height.size()-1);
    }

    node query(node *v,int low, int high, int l, int r){
        if(low >= l && r >= high) return *v;
        if(l > high || r < low){
            node ans;
            return ans;
        }
        ll mid = (low+high)>>1;
        node left = query(v->left,low,mid,l,r);
        node right = query(v->right,mid+1,high,l,r);
        node ans;
        if(left.leftIndex == -1) ans = right;
        else if(right.rightIndex == -1) ans = left;
        else{
            ans.left = &left;
            ans.right = &right;
            segTree::merge(&ans);
        }
        return ans;
    }

    node query(int l, int r){
        return query(head,0,position.size()-1,l,r);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<ll> distance(n), position, height(n);
    for(auto &va: distance) cin >> va;
    for(auto &va: height) cin >> va;
    position.pb(0);
    for(int i = 0,j = 0; j < 2*n;++i,++j){
        if(i == n) i = 0;
        position.pb(position.back() + distance[i]);
    }
    for(int i = 0; i < n;++i)
        height.pb(height[i]);

    segTree toUse;
    toUse.build(height,position);

    while(m--){
        int a,b;
        cin >> a >> b;
        --a,--b;
        if(a <= b)
            cout << toUse.query(b+1,n+a-1).ans << "\n";
        else
            cout << toUse.query(b+1,a-1).ans << "\n";
     }

    return 0;
}
