// Is love even real?
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
typedef long long ll;

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
typedef long long ll;
/// Complexity: O(|N|*log(|N|))
/// Tested: https://tinyurl.com/y8g2q66b
namespace fft {
    const double PI = acos(-1.0);
    vector<int> rev;
    struct pt {
        double r, i;
        pt(double r = 0.0, double i = 0.0) : r(r), i(i) {}
        pt operator + (const pt & b) { return pt(r + b.r, i + b.i); }
        pt operator - (const pt & b) { return pt(r - b.r, i - b.i); }
        pt operator * (const pt & b) { return pt(r * b.r - i * b.i, r * b.i + i * b.r); }
    };
    void fft(vector<pt> &y, int on) {
        int n = y.size();
        for(int i = 1; i < n; i++) if(i < rev[i]) swap(y[i], y[rev[i]]);
        for(int m = 2; m <= n; m <<= 1) {
            pt wm(cos(-on * 2 * PI / m), sin(-on * 2 * PI / m));
            for(int k = 0; k < n; k += m) {
                pt w(1, 0);
                for(int j = 0; j < m / 2; j++) {
                    pt u = y[k + j];
                    pt t = w * y[k + j + m / 2];
                    y[k + j] = u + t;
                    y[k + j + m / 2] = u - t;
                    w = w * wm;
                }
            }
        }
        if(on == -1)
            for(int i = 0; i < n; i++) y[i].r /= n;
    }
    vector<ll> mul(vector<ll> &a, vector<ll> &b) {
        int n = 1, la = a.size(), lb = b.size(), t;
        for(n = 1, t = 0; n <= (la+lb+1); n <<= 1, t++); t = 1<<(t-1);
        vector<pt> x1(n), x2(n);
        rev.assign(n, 0);
        for(int i = 0; i < n; i++) rev[i] = rev[i >> 1] >> 1 |(i & 1 ? t : 0);
        for(int i = 0; i < la; i++) x1[i] = pt(a[i], 0);
        for(int i = 0; i < lb; i++) x2[i] = pt(b[i], 0);
        fft(x1, 1); fft(x2, 1);
        for(int i = 0; i < n; i++) x1[i] = x1[i] * x2[i];
        fft(x1, -1);
        vector<ll> sol(n);
        for(int i = 0; i < n; i++) sol[i] = x1[i].r + 0.5;
        return sol;
    }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    vector<ll> fi,se;
    char temp;
    while(1){
        scanf("%c",&temp);
        if(temp == '\n')break;
        fi.pb((temp == '1'?1:-1));
    }
    while(1){
        scanf("%c",&temp);
        if(temp == '\n')break;
        se.pb((temp == '1'?1:-1));
    }

    reverse(se.begin(),se.end());
    vector<ll> use = fft::mul(fi,se);

    int ans = 0;
    for(int i = se.size()-1,j = 0; j <= fi.size()-se.size();++i,++j){
        int see = se.size()-((se.size()+use[i])>>1);
        ans += !(see&1);
    }

    printf("%d/n",ans);

    return 0;
}
