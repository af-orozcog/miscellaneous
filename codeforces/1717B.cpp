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

void modify(vector<vector<char>> &mat,int k, int r, int c){
    int n = mat.size();
    queue<pii> q;
    q.push({r,c});
    while(q.size()){
        auto dad = q.front();
        mat[dad.ff][dad.ss] = 'X';
        q.pop();
        if(dad.ff + k < n && mat[dad.ff+k][dad.ss] != 'X'){
            q.push({dad.ff+k,dad.ss});
            mat[dad.ff+k][dad.ss] = 'X';
        }
        if(dad.ff - k > -1 && mat[dad.ff-k][dad.ss] != 'X'){
            q.push({dad.ff-k,dad.ss});
            mat[dad.ff-k][dad.ss] = 'X';
        }
        if(dad.ss + k < n && mat[dad.ff][dad.ss+k] != 'X'){
            q.push({dad.ff,dad.ss+k});
            mat[dad.ff][dad.ss+k] = 'X';
        }
        if(dad.ss - k < n && mat[dad.ff][dad.ss-k] != 'X'){
            q.push({dad.ff,dad.ss-k});
            mat[dad.ff][dad.ss-k] = 'X';
        }
    }
}


void solve(vector<vector<char>> &mat, int k, int i, int j){
    set<int> freeRow;
    set<int> freeCol;
    for(int r = 0; r < k;++r) freeCol.insert(r), freeRow.insert(r);

    for(int r = 0; r < k;++r){
        for(int c = 0; c < k;++c){
            if(mat[i+r][c+j] == 'X'){
                freeCol.erase(c);
                freeRow.erase(r);
            }
        }
    }
    while(freeRow.size() && freeCol.size()){
        auto see1 = freeRow.begin();
        auto see2 = freeCol.begin();
        mat[i+(*see1)][j+(*see2)] = 'X';
        modify(mat,k,i+(*see1),j+(*see2));
        freeRow.erase(see1);
        freeCol.erase(see2);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,k,r,c;
        cin >> n >> k >> r >> c;
        vector<vector<char>> mat(n,vector<char>(n,'.'));
        mat[r-1][c-1] = 'X';
        modify(mat,k,r-1,c-1);
        for(int i = 0; i < n;i+=k){
            for(int j = 0; j < n; j+=k)
                solve(mat,k,i,j);
        }
        for(auto &row:mat){
            for(auto &col:row){
                cout << col;
            }
            cout << "\n";
        }
    }
    return 0;
}
