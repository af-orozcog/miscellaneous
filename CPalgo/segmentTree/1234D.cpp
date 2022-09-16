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

struct node {
    node *left = nullptr,*right = nullptr;
    bitset<26> letters;
    node(){}
};

string vals;

void build(node *v,int low, int high){
    if(low == high){
        v->letters[vals[low]-'a'] = 1;
        return;
    }
    v->left = new node(), v->right = new node();
    int mid = (low+high)>>1;
    build(v->left,low,mid);
    build(v->right,mid+1,high);
    v->letters = v->right->letters | v->left->letters;
}

void update(node *v, int low, int high,int pos, char val){
    if(low == high && low == pos){
        v->letters[vals[pos]-'a'] = 0;
        vals[pos] = val;
         v->letters[vals[pos]-'a'] = 1;
        return;
    }
    int mid = (low+high)>>1;
    if(pos <= mid)
        update(v->left,low,mid,pos,val);
    else
        update(v->right,mid+1,high,pos,val);
    v->letters = v->left->letters | v->right->letters;
}

bitset<26> query(node *v, int low, int high, int l, int r){
    if(low >= l && r >= high) return v->letters;
    if(l > high || r < low) {
        bitset<26> ans;
        return ans;
    }
    int mid = (low+high)>>1;
    bitset<26> left = query(v->left,low,mid,l,r);
    bitset<26> right = query(v->right,mid+1,high,l,r);
    return left | right;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> vals;
    int q;
    cin >> q;
    node *head = new node();
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int pos; char val;
            cin >> pos >> val;
            --pos;
            update(head,0,vals.size()-1,pos,val);
        }
        else{
            int lo,high; cin >> lo >> high;
            --lo,--high;
            cout << query(head,0,vals.size()-1,lo,high).count() << "\n";
        }
    }
    return 0;
}
