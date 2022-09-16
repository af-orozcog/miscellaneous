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

int digits(int val){
    int ans = 0;
    while(val){
        ++ans;
        val /= 10;
    }
    return ans;
}

void cleanMap(map<int,int> &mp){
    vector<int> toDelete;
    for(auto va:mp){
        if(!va.ss) toDelete.pb(va.ff);
    }
    for(auto va:toDelete)
        mp.erase(va);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n),b(n);
        for(auto &va:a) cin >> va;
        for(auto &va:b) cin >> va;
        map<int,int> digA,digB;;
        for(auto va:a)
            ++digA[va];
        for(auto va:b)
            ++digB[va];
        int ans = 0;

        for(auto &va:digA){
            int mi = min(va.ss,digB[va.ff]);
            va.ss -= mi;
            digB[va.ff] -= mi;
        }
        for(auto &va:digB){
            int mi = min(va.ss,digA[va.ff]);
            va.ss -= mi;
            digA[va.ff] -= mi;
        }
        cleanMap(digA); cleanMap(digB);

        while(digA.size()){
            auto biggestA = (*digA.rbegin());
            auto biggestB = (*digB.rbegin());

            if(biggestA.ff > biggestB.ff){
                ans += biggestA.ss;
                digA.erase(biggestA.ff);
                int toAdd = digits(biggestA.ff);
                int mi = min(biggestA.ss,digB[toAdd]);
                biggestA.ss -= mi;
                digB[toAdd] -= mi;
                if(biggestA.ss)
                    digA[toAdd] += biggestA.ss;
                if(digB[toAdd] == 0)
                    digB.erase(toAdd);
            }
            else{
                ans += biggestB.ss;
                digB.erase(biggestB.ff);
                int toAdd = digits(biggestB.ff);
                int mi = min(biggestB.ss,digA[toAdd]);
                biggestB.ss -= mi;
                digA[toAdd] -= mi;
                if(biggestB.ss)
                    digB[toAdd] += biggestB.ss;
                if(digA[toAdd] == 0)
                    digA.erase(toAdd);
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
