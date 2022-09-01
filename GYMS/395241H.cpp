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

bool check(string temp, int l, int r){
    reverse(temp.begin()+l,temp.begin()+r+1);
    int i = 0,j = temp.size()-1;
    while(i < j && temp[i] == temp[j]) ++i,--j;
    return i >= j;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string see;
    cin >> see;

    int i = 0,j = see.size()-1;

    while(i < j && see[i] == see[j]) ++i,--j;

    if(i >= j){
        cout << 1 << " " << see.size() << "\n";
        return 0;
    }

    if(check(see,i+1,j))
        cout << (i+2) << " " << j+1 << "\n";
    else if(check(see,i,j-1))
        cout << (i+1) << " " << j << "\n";
    else if(check(see,i,i+(j-i+1)/2 - 1))
        cout << (i+1) << " " << i+(j-i+1)/2 << "\n";
    else if((j-i+1)%2 == 1){
        if(check(see,i,i+(j-i+1)/2))
            cout << (i+1) << " " << i+(j-i+1)/2 + 1 << "\n";
        if(check(see,i+(j-i+1)/2,j))
            cout << i+(j-i+1)/2 + 1 << " " << j+1 << "\n";
    }
    else cout << "-1 -1\n";
}
