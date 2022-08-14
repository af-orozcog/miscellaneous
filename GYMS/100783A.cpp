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
const int N = 32768;
const ld eps = 1e-9;
const ll mod = 998244353;
const ll lel = 1e12;

vector<string> words;
vector<char> toUse;

int getAns(int word,int pos, int acum, int now,map<char,int> &tr,vector<int> &ava){
    int ans = 0;
    if(word == words.size()-1 && pos == words.back().size())
        return acum == now;
    if(pos == words[word].size())
        return getAns(word+1,0,acum+now,0,tr,ava);
    if(tr.count(words[word][pos])) {
        if(tr[words[word][pos]] == 0 && pos == 0) return 0;
        return getAns(word, pos + 1, acum, now * 10 + tr[words[word][pos]], ava);
    }
    for(int i = (pos == 0); i < ava.size();++i){
        if(ava[i]){
            ava[i] = 0;
            tr[words[word][pos]] = i;
            ans += getAns(word, pos + 1, acum, now * 10 + tr[words[word][pos]], ava);
            tr.erase(words[word][pos]);
            ava[i] = 1;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    words.resize(n);
    for(auto &va:words){
        cin >> va;
    }

    cout << getAns() << "\n";
    return 0;
}

