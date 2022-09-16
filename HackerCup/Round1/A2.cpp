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

bool valid(int imp, int n, int k){
    if(k == 0 && imp) return false;

    if(k&1){
        if(imp == 0){
            if(k > 1 && n > 2) return true;
            else return false;
        }
        else
            return true;
    }
    else{
        if(imp == 1){
            if(n > 2) return true;
            else return false;
        }
        else return true;
    }
}

vector<int> kmp(vector<int> &see){
    vector<int> ans(see.size(),0);
    for(int i = 1, j = 0; i < see.size();++i){
        while(j && see[i] != see[j]) j = ans[j-1];
        if(see[i] == see[j]) ++j;
        ans[i] = j;
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int cas = 1;
    while(t--){
        cout << "Case #" << cas++ << ": ";
        int n,k;
        cin >> n >> k;
        vector<int> a(n),b(n);
        for(auto &va:a) cin >> va;
        for(auto &va:b) cin >> va;
        for(int i = 0; i < n;++i)
            a.pb(a[i]);
        a.pop_back();
        vector<int> send;
        for(auto va:b) send.pb(va);
        send.pb(-1);
        for(auto va:a) send.pb(va);

        vector<int> see = kmp(send);

        bool ans = false;
        for(int i = n+n, j = 0; i < see.size() && !ans;++i,++j){
            if(see[i] == n)
                ans = valid(j,n,k);
        }

        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
