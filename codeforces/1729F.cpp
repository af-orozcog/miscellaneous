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
const int MAX = 2* (1e5) + 3;

string s;

vector<int> powers;

struct node{
    node *left = nullptr, *right = nullptr;
    int size;
    int val;
    node(){}
};

void combine(node *v){
    int tamL = v->left->size, tamR = v->right->size;
    v->val = v->left->val * powers[tamR] + v->right->val;
    if(v->val >= 9) v->val %= 9;
    v->size = v->left->size + v->right->size;
}


void build(node *v, int low, int high){
    if(low == high){
        v->size = 1;
        v->val = (s[low] - '0') % 9;
        return;
    }
    v->left = new node(), v->right = new node();
    int mid = (low+high)>>1;
    build(v->left,low,mid);
    build(v->right,mid+1,high);
    combine(v);
}


node query(node *v,int low, int high, int l, int r){
    if(low > r || high < l) {
        node ans;
        ans.size = ans.val = 0;
        return ans;
    }
    if(low >= l && high <= r) return *v;
    node ans;
    int mid = (low+high)>>1;
    node left = query(v->left,low,mid,l,r), right = query(v->right,mid+1,high,l,r);
    ans.left = &left;
    ans.right = &right;
    combine(&ans);
    return ans;
}


void deleteTree(node *v){
    if(!v) return;
    deleteTree(v->left);
    deleteTree(v->right);
    delete v;
}


map<int,vector<int>> calc(node *v, int w){
    map<int,vector<int>> mp;
    for(int i = 0,j = w-1; j < s.size();++i,++j){
        auto see = query(v,0,s.size()-1,i,j);
        mp[see.val].pb(i);
    }

    return mp;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    powers.resize(MAX);
    powers[0] = 1;
    for(int i = 1;i < MAX;++i){
        powers[i] = powers[i-1]*10;
        if(powers[i] >= 9) powers[i] %= 9;
    }


    node *tree = nullptr;

    int t;
    cin >> t;


    while(t--){
        cin >> s;

        tree = new node();
        build(tree,0,s.size()-1);

        int w,m;

        cin >> w >> m;

        auto imp = calc(tree,w);

        while(m--){
            int l,r,k; cin >> l >> r >> k;
            pii ans = {INT_MAX,INT_MAX};

            int ini = query(tree,0,s.size()-1,l-1,r-1).val;

            for(int i = 0; i < 9; ++i){
                int check = k - ((i*ini)%9);
                if(check < 0) check += 9;
                if(imp.count(i) && imp.count(check)){
                    pii comp;
                    if(check == i){
                        if(imp[i].size() > 1) comp = {imp[i][0],imp[i][1]};
                        else continue;
                    }
                    else comp = {imp[i][0],imp[check][0]};
                    ans = min(ans,comp);
                }
            }

            if(ans.ff == INT_MAX) ans = {-1,-1};

            cout << ans.ff << " " << ans.ss << "\n";
        }


        deleteTree(tree);
        delete tree;
    }
    return 0;
}
