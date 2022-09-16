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

int smallest(priority_queue<int> &vals){
    while(vals.size() > 1){
        int fi = vals.top();
        vals.pop();
        int se = vals.top();
        vals.pop();
        fi -= se;
        if(fi) vals.push(fi);
    }
    return vals.top();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> vals(n);
        for(auto &va:vals) cin >> va;
        int ans = 0;
        for(int i = 0; i < n;++i){
            priority_queue<int> q;
            for(int j = 0; j < n;++j){
                if(j == i) continue;
                q.push(vals[j]);
            }
            int see = smallest(q);
            if(see < vals[i]) ++ans;
        }
        cout << ans << "\n";
    }
    return 0;
}
