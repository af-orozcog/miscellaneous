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
//const int N = 1e5+20;
const ld eps = 1e-9;
const ll mod = 998244353;
const ll lel = 1e12;

map<char,string> tr =
{
    {'A',".-"},
    {'B',"-..."},
    {'C',"-.-."},
    {'D',"-.."},
    {'E',"."},
    {'F',"..-."},
    {'G',"--."},
    {'H',"...."},
    {'I',".."},
    {'J',".---"},
    {'K',"-.-"},
    {'L',".-.."},
    {'M',"--"},
    {'N',"-."},
    {'O',"---"},
    {'P',".--."},
    {'Q',"--.-"},
    {'R',".-."},
    {'S',"..."},
    {'T',"-"},
    {'U',"..-"},
    {'V',"...-"},
    {'W',".--"},
    {'X',"-..-"},
    {'Y',"-.--"},
    {'Z',"--.."},
    {'0',"-----"},
    {'1',".----"},
    {'2',"..---"},
    {'3',"...--"},
    {'4',"....-"},
    {'5',"....."},
    {'6',"-...."},
    {'7',"--..."},
    {'8',"---.."},
    {'9',"----."}
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string see;
    getline(cin,see);
    stringstream ss(see);
    string temp;
    string traduction;


    while(ss >> temp){
        for(auto let:temp){
            if(isalpha(let))
                traduction += tr[toupper(let)];
            else if(isalnum(let))
                traduction += tr[let];
        }
    }

    int i = 0, j = traduction.size();
    while(i < j && traduction[i] == traduction[j]) ++i,--j;

    if(i >= j)
        cout << "YES\n";

    else cout << "NO\n";

    return 0;
 }
