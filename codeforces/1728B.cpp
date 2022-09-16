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
    while(t--){
        int n;
        cin >> n;
        vector<int> ans(n);
        if(n&1){
            ans[n-1] = n, ans[n-2] = (n/2)+1, ans[n-3] = (n/2)-1;
            for(int i = n-4, j = 1; i > -1;--i,++j){
                while(j == (n/2)+1 || j == (n/2)-1) ++j;
                ans[i] = j;
            }
        }
        else{
            ans[n-1] = n, ans[n-2] = n-1;
            for(int i = n-3,j = 1; i > -1;--i,++j)
                ans[i] = j;
        }
        for(auto va:ans)
            cout << va << " ";
        cout << "\n";
    }
    return 0;
}
