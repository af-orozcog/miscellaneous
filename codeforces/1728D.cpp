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

string see;

vector<vector<int>> dp;

int go(int i, int j){
    if(i == j-1){
        if(see[i] == see[j]) return 2;
        return dp[i][j] = 1;
    }
    if(dp[i][j] != -1) return dp[i][j];
    int check1 = go(i+2,j);
    int check2 = go(i+1,j-1);
    int check3 = go(i+1,j-1);
    int check4 = go(i,j-2);
    if(check1 == 2 && see[i] < see[i+1]) check1 = 1;
    if(check2 == 2 && see[i] < see[j]) check2 = 1;
    if(check3 == 2 && see[j] < see[i]) check3 = 1;
    if(check4 == 2 && see[j] < see[j-1]) check4 = 1;
    if(check1 == 1 && check2 == 1)
        return dp[i][j] = 1;
    else if(check3 == 1 && check4 == 1)
        return dp[i][j] = 1;
    else if((check1 == 0 || check2 == 0) && (check3 == 0 || check4 == 0))
        return dp[i][j] = 0;
    else
        return dp[i][j] = 2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> see;
        dp.clear();
        dp.resize(see.size()+2, vector<int>(see.size()+2,-1));
        int check = go(0,see.size()-1);
        if(check == 1)
            cout << "Alice\n";
        else if(check == 0)
            cout << "Bob\n";
        else cout << "Draw\n";
    }
    return 0;
}
