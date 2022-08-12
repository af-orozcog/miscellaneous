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

typedef long long D;
typedef vector<int> poly;
const int maxn=530003,mod=1009;
const double pi=acos(-1);
struct com{
    double r,i;
    com(){}
    com(double _r,double _i):r(_r),i(_i){}
    com operator+(const com &x)const{return com(r+x.r,i+x.i);}
    com operator-(const com &x)const{return com(r-x.r,i-x.i);}
    com operator*(const com &x)const{return com(r*x.r-i*x.i,r*x.i+i*x.r);}
}k1[maxn],k2[maxn];
int r[maxn];
void fft(com a[],int n,int sgn){
    for(int i=0;i<n;i++)if(r[i]>i)swap(a[i],a[r[i]]);
    for(int mid=1;mid<n;mid<<=1){
        com wn(cos(pi/mid),sgn*sin(pi/mid));
        for(int j=0;j<n;j+=(mid<<1)){
            com w(1,0);
            for(int k=0;k<mid;k++,w=w*wn){
                com tmp=w*a[j+k+mid];
                a[j+k+mid]=a[j+k]-tmp;
                a[j+k]=a[j+k]+tmp;
            }
        }
    }
}
poly operator*(const poly &a,const poly &b){
    int n1=a.size()-1,n2=b.size()-1,lg=0,n=1;
    while(n<=n1+n2)lg++,n<<=1;
    for(int i=0;i<n;i++)r[i]=(r[i>>1]>>1)|((i&1)<<(lg-1)),k1[i]=k2[i]=com(0,0);
    for(int i=0;i<=n1;i++)k1[i].r=a[i];
    for(int i=0;i<=n2;i++)k2[i].r=b[i];
    fft(k1,n,1);
    fft(k2,n,1);
    for(int i=0;i<n;i++)k1[i]=k1[i]*k2[i];
    fft(k1,n,-1);
    poly ret(n1+n2+1);
    for(int i=0;i<=n1+n2;i++)ret[i]=D(k1[i].r/n+0.5)%mod;
    return ret;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n,m,k;
    scanf(" %d %d %d",&n,&m,&k);
    vector<int> count(m+1,0);
    for(int i = 0; i < n;++i){
        int see; scanf(" %d",&see);
        ++count[see];
    }
    vector<vector<int>> toMul;
    for(int i = 1; i <= m;++i) {
        if(count[i])
            toMul.pb(poly(min(count[i],k)+1,1));
    }

    for(int i = 2; (i>>1) < toMul.size();i<<=1){
        for(int j = 0; j+(i>>1) < toMul.size();j+=i){
            toMul[j] = toMul[j]*toMul[j+(i>>1)];
            while(toMul[j].size() > k+1) toMul[j].pop_back();
        }
    }

    printf("%d\n",toMul[0][k]);
    return 0;
}
