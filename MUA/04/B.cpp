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
        vector<int> nums(n);
        for(auto &va:nums) cin >> va;
        map<int,int> seen;
        bool ans = 0;
        for(int i = 0; i < n && !ans;++i){
            if(seen.count(nums[i])){
                if(seen[nums[i]] != i-1) ans = 1;
            }
            else
                seen[nums[i]] = i;
        }
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
