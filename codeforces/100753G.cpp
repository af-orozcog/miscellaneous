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

struct state {
    int len, link;
    //Cuenta cuantas veces aparecen los strings que correponden a este nodo en el string
    ll cnt = 0;
    //Almacena cuantos strings (diferentes) corresponden a este nodo
    int tam;
    //Indica si este nodo corresponde a sufijos del string original
    bool terminal = false;
    map<char, int> next;
};

const int MAXLEN = 1e6;
state st[MAXLEN * 2];
int sz, last;


void sa_init() {
    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
}

void sa_extend(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

int contar(int v){
    if(st[v].cnt){
        return st[v].cnt;
    }
    if(v) {
        st[v].tam = st[v].len - st[st[v].link].len;
    }
    int rta = st[v].terminal;
    for (auto const& x : st[v].next){
        rta+=contar(x.second);
    }
    return st[v].cnt = rta;
}

void asignar_terminales() {
    int est = last;
    while(est>0){
        st[est].terminal = true;
        est = st[est].link;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    //Costruimos el automata
    sa_init();
    for(auto c: s){
        sa_extend(c);
    }
    asignar_terminales();
    int q;
    cin >> q;
    while(q--){
        string check; cin >> check;

        int now = 0;
        int i = 0;
        int ans = 1;
        while(i < check.size()){
            if(st[now].next.count(check[i]))
                now = st[now].next[check[i]];
            else{
                ++ans;
                if(now == 0)break;
                else now = 0;
            }
        }

        if(check.size() == i) cout << ans << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}


