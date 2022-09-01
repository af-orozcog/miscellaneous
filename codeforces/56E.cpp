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

const ll iden = LLONG_MIN;
struct node {
    node* left = nullptr, *right = nullptr;
    ll val = iden;
    node() {}
};

//Funcion auxiliar para obtener valores
ll get_val(node* v) {
    if(v == nullptr) return iden;
    return v -> val;
}

//low es el minimo del rango actual, high el maxi y estamos actualizando la posicion idx con el valor value
void update(node* v, ll low, ll high, ll idx, ll value) {
    if(idx > high || idx < low || low > high) return;
    if(low == high) {
        v-> val = max(value, v->val);
        return;
    }
    ll mid = (low + high) >>1;
    if(idx <= mid) {
        if(v->left == nullptr) v ->left = new node();
        update(v->left, low, mid, idx, value);
    } else {
        if(v->right == nullptr) v->right = new node();
        update(v->right, mid+1, high, idx, value);
    }
    v->val = max(get_val(v->left), get_val(v->right));
}

//low es el minimo del rango actual, high el maxi y estamos haciendo la query en el intervalo [l,r]
ll query_max(node* v, ll low, ll high, ll l, ll r) {
    if(v == nullptr) return iden;
    if(l>high || r<low || low > high) return iden;
    if(low >= l && high <= r) return v->val;
    ll mid = (low+high)>>1;
    ll v1 = query_max(v->left, low, mid, l, r);
    ll v2 = query_max(v->right, mid+1, high, l, r);
    return max(v1, v2);
}

struct domino {
    int id, x, h;
    domino(){}
    domino(int _id, int _x,int _h):id{_id},x{_x},h{_h}{}
};

bool comp(const domino &a, const domino &b){
    return a.x < b.x;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<domino> values(n);
    int id = 0;
    for(auto &va:values){
        cin >> va.x >> va.h;
        va.id = id++;
    }

    ll mi = -1e8-2, ma = 1e8+1;
    node *head = new node();

    sort(values.begin(),values.end(),comp);
    vector<int> dp(n);
    vector<int> ans(n);
    for(int i = n-1; i > -1;--i){
        int upTo = max(values[i].x + values[i].h, (int)query_max(head,mi,ma,values[i].x,values[i].x + values[i].h));
        int lo = i, hi = n;
        int last = i;
        while(lo <= hi){
            int mid = (lo+hi)>>1;
            if(values[mid].x <= upTo){
                last = mid;
                lo = mid + 1;
            }
            else lo = mid - 1;
        }
        ans[values[i].id] = (last-i)+1;
        update(head,mi,ma,values[i].x,upTo);
    }

    for(auto va:ans)
        cout << va << " ";
    cout << "\n";

    return 0;
}
