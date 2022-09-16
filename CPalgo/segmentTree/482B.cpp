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

const int iden = (1<<30)-1;
struct node {
    node* left = NULL, *right = NULL;
    int val = iden, lazy = 0;
    node() {}
};
//Funcion auxiliar para obtener valores
int get_val(node* v) {
    if(v == NULL) return iden;
    return v -> val;
}
//Propago los valores lazy
void push(node* v) {
    if(v->lazy == 0) return;

    if(v->right == NULL) v->right = new node();
    v->right->lazy |= v->lazy;
    v->right->val |= v->lazy;

    if(v->left == NULL) v->left = new node();
    v->left->lazy |= v->lazy;
    v->left->val |= v->lazy;

    v->lazy = 0;
}
//low es el minimo del rango actual, high el maxi y estamos actualizando la posicion idx con el valor value
void update(node* v, ll low, ll high, ll l, ll r, int value) {
    if(l > high || r < low || low > high) return;
    if(low >= l && high<= r) {
        v-> val |= value;
        v->lazy |= value;
        return;
    }

    ll mid = (low + high) >>1;
    push(v);
    if(l <= mid) {
        if(v->left == NULL) v ->left = new node();
        update(v->left, low, mid, l, r, value);
    }
    if(r > mid ) {
        if(v->right == NULL) v->right = new node();
        update(v->right, mid+1, high, l, r, value);
    }
    v->val = get_val(v->left) & get_val(v->right);
}

//low es el minimo del rango actual, high el maxi y estamos haciendo la query en el intervalo [l,r]
int query_max(node* v, ll low, ll high, ll l, ll r) {
    if(v == NULL) return iden;
    if(l>high || r<low || low > high) return iden;
    if(low >= l && high <= r) return v->val;
    ll mid = (low+high)>>1;
    push(v);
    int v1 = query_max(v->left, low, mid, l, r);
    int v2 = query_max(v->right, mid+1, high, l, r);
    return v1 & v2;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    node *head = new node();
    vector<pair<int,pii>> queries(m);
    for(auto &va:queries){
        cin >> va.ff >> va.ss.ff >> va.ss.ss;
        update(head,1,n,va.ff,va.ss.ff,va.ss.ss);
    }
    bool good = 1;
    for(auto &va:queries)
        good &= (query_max(head,1,n,va.ff,va.ss.ff) == va.ss.ss);

    if(good) cout << "YES\n";
    for(int i = 1; i <= n && good;++i)
        cout << query_max(head,1,n,1,1) << " ";
    if(!good) cout << "NO";
    cout << "\n";
    return 0;
}
