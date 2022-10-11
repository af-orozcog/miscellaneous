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

int n,k,m;
vector<vector<int>> values;
vector<int> expected;

map<pii,int> states;

int freePosition(int mask, int val){
    return (mask>>val)&1;
}

int paint(int mask1, int mask2, int color){
    set<int> covered;
    for(int i = 0; i < m;++i){
        if(!freePosition(mask2,i)) continue;
        for(auto va:values[i])
            covered.insert(va);
    }
    for(int i = 0; i < n;++i){
        if(covered.count(i)) continue;
        if(color != expected[i] && (mask1>>i)%2 == 1)
            mask1 -= (1<<(i));
        else if(color == expected[i])
            mask1 |= (1<<i);
    }
    return mask1;
}

int addCover(int mask2,int val){
    return mask2 | (1<<val);
}

int deleteCover(int mask2,int val){
    return mask2 - (1<<val);
}

void bfs(int mask1, int mask2){
    states[{mask1,mask2}] = 0;
    queue<pii> q;
    q.push({mask1,mask2});
    while(q.size()){
        pii dad = q.front();
        q.pop();
        for(int i = 1; i <= k;++i){
            int check = paint(dad.ff,dad.ss,i);
            pii toAdd = {check,dad.ss};
            if(!states.count(toAdd)){
                q.push(toAdd);
                states[toAdd] = states[dad] + 1;
            }
        }
        for(int i = 0; i < m;++i){
            int check = addCover(dad.ss,i);
            pii toAdd = {dad.ff,check};
            if(!states.count(toAdd)){
                q.push(toAdd);
                states[toAdd] = states[dad] + 1;
            }
            check = deleteCover(dad.ss,i);
            toAdd = {dad.ff,check};
            if(!states.count(toAdd)){
                q.push(toAdd);
                states[toAdd] = states[dad] + 1;
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> m;
    expected.resize(n);
    values.resize(m);

    for(auto &va:expected) cin >> va;
    for(int i = 0; i < m;++i){
        int amount; cin >> amount;
        values[i].resize(amount);
        for(auto &va:values[i]) {
            cin >> va;
            --va;
        }
    }

    int initialMask = 0;
    for(int i = 0; i < n;++i){
        if(expected[i] == 1)
            initialMask |= (1<<i);
    }

    bfs(initialMask,0);

    int ans = INT_MAX;

    for(int i = 0; i < (1<<m);++i){
        int first = (1<<n)-1;
        if(states.count({first,i}))
            ans = min(ans,states[{first,i}]);

    }

    cout << (ans == INT_MAX? -1:ans) << "\n";

    return 0;
}
