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

bool isPalindrome(vector<int> &see){
    int i = 0,j = see.size()-1;
    while(i < j && see[i] == see[j]) ++i,--j;
    return i >= j;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string see;
    string check = "hello";
    cin >> see;
    int j = 0;
    for(int i = 0; i < see.size() && j < check.size();++i){
        if(check[j] == see[i]) ++j;
    }

    if(j == check.size()) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
