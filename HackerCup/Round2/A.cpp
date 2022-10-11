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
const int N = 1e6+1;
const ld eps = 1e-9;
const ll mod = 998244353;
const ll lel = 1e12;

#define bint __int128
bint MOD=212345678987654321LL,P=1777771;

vector<bint> potencias;
set<bint> seen;
vector<int> original;

struct node{
    node *left = nullptr,*right = nullptr;
    bint val = 0;
    map<int, int> seen;
};


void build(node *v, int low, int high){
    if(low == high){
        ++v->seen[original[low]];
        v->val = potencias[original[low]-1];
        return;
    }
    int mid = (low+high)>>1;
    v->left = new node(), v->right = new node();
    build(v->left,low,mid);
    build(v->right,mid+1,high);
    for(auto &va:v->left->seen)
        v->seen[va.ff] += va.ss;
    for(auto &va:v->right->seen)
        v->seen[va.ff] += va.ss;
    v->val = v->left->val + v->right->val;
    if(v->val >= MOD) v->val -= MOD;
}

void update(node *v, int low, int high, int pos, int val){
    if(!v) return;
    if(low == pos && high == pos){
        v->val -= potencias[original[pos]-1];
        if(v->val < 0LL) v->val += MOD;
        --v->seen[original[pos]];
        v->val += potencias[val-1];
        if(v->val >= MOD) v->val -= MOD;
        original[pos] = val;
        ++v->seen[val];
        return;
    }
    else if(low <= pos && high >= pos){
        v->val -= potencias[original[pos]-1];
        if(v->val < 0LL) v->val += MOD;
        --v->seen[original[pos]];
        v->val += potencias[val-1];
        if(v->val >= MOD) v->val -= MOD;
    }
    else if(low > pos || high < pos) return;
    int mid = (low + high)>>1;
    update(v->left,low,mid,pos,val);
    update(v->right,mid+1,high,pos,val);
}


bint query(node *v,int low, int high, int l, int r){
    if(l <= low && high <= r)
        return v->val;

    if(high < l || low > r) return 0;

    int mid = (low+high) >> 1;
    bint left = query(v->left,low,mid,l,r);
    bint right = query(v->right,mid+1,high,l,r);
    bint answer = left+right;
    if(answer >= MOD) answer %= MOD;
    return answer;
}

void deleteTree(node *v){
    if(!v) return;
    deleteTree(v->right);
    deleteTree(v->left);
    delete v->left;
    delete v->right;
}

bool check(bint a, bint b){
    if(a > b) b += MOD;
    bint see = b - a;
    return seen.count(see);
}

int main(){
    potencias.resize(N);
    potencias[0] = 1;
    seen.insert(1);
    for(int i = 1; i < potencias.size();++i){
        potencias[i] = potencias[i-1]*P;
        if(potencias[i] >= MOD)
            potencias[i] %= MOD;
        seen.insert(potencias[i]);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int cas = 1;
    node *tree = nullptr;
    while(t--){
        cout << "Case #" << cas++ << ": ";
        int ans = 0;
        string s; cin >> s;
        int n = s.size();
        original.resize(s.size());
        for(int i = 0; i < s.size();++i){
            original[i] = s[i];
        }
        tree = new node();
        build(tree,0,n-1);
        int q; cin >> q;

        while(q--){
            int x1,x2; cin >> x1 >> x2;
            --x1,--x2;
            if((x2-x1) %2 != 0) continue;
            int mid = (x1+x2)>>1;
            bint b = query(tree,0,n-1,x1,mid);
            bint a = query(tree,0,n-1,mid+1,x2);
            if(check(a,b)){
                ++ans; continue;
            }
            a = query(tree,0,n-1,x1,mid-1);
            b = query(tree,0,n-1,mid,x2);
            if(check(a,b)) ++ans;
        }

        cout << ans << "\n";
        original.clear();
        deleteTree(tree);
        delete tree;
    }
    return 0;
}
