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

        map<int,int> mp;
        for(int i = 0; i < n;++i)
            mp[b[i]] = i;

        set<int> dif;
        for(int i = 0; i < n;++i){
            int imp = mp[a[i]] - i;
            if(imp < 0) imp += n;
            dif.insert(imp);
        }

        if(dif.size() != 1){
            cout << "NO\n";
            continue;
        }

        int imp = *(dif.begin());

        if(k == 0 && imp){
            cout << "NO\n";
            continue;
        }

        if(k&1){
            if(imp == 0){
                if(k > 1 && n > 2)
                    cout << "YES\n";
                else cout << "NO\n";
            }
            else
                cout << "YES\n";
        }
        else{
            if(imp == 1){
                if(n > 2) cout << "YES\n";
                else cout << "NO\n";
            }
            else cout << "YES\n";
        }
    }
    return 0;
}
