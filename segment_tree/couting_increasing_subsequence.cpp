#include "bits/stdc++.h"
//#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define IOS ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define foru(j, a, b) for(int j = a; j <= b; ++j)
#define ford(j ,a, b) for(int j= a; j >= b; --j)
#define forp(j, a, b) for(int j = a; j + 1 <= b; ++j)
#define endl '\n'

const int maxN = 2e5 + 5;
const int mod = 1e9 + 7;
const int inf = 1e9;
#define int ll
struct Node{
    int prefix, suffix, range, left, right;
}st[4 * maxN];

int arr[maxN];
Node operator +(Node &a, Node &b){
    Node ans;
    if(arr[a.right] <= arr[b.left]){
        ans.range = a.range + b.range + a.suffix * b.prefix;
        
        ans.prefix = (a.prefix == a.right - a.left + 1) ? a.prefix + b.prefix : a.prefix;
        ans.suffix = (b.suffix == b.right - b.left + 1)  ?  a.suffix + b.suffix : b.suffix;
    }
    else{
        ans.range = a.range + b.range;
        ans.prefix = a.prefix;
        ans.suffix = b.suffix;
    }

    ans.left = a.left;
    ans.right = b.right;

    return ans;    
}
void build(int id, int l, int r){
    if(l == r){
        st[id].prefix = st[id].suffix = st[id].range = 1;
        st[id].left = st[id].right = l;        
        return;
    }
    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    st[id] = st[id * 2] + st[id * 2 + 1];
    //cout << st[id].range << " " << st[id].left << " " << st[id].right << endl;
}

void update(int id, int l, int r, int i, int val){
    if(l > i || i > r) return;

    if(l == r){
        return;
    }
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, i, val);
    update(id * 2 + 1, mid + 1, r, i, val);

    st[id] = st[id * 2] + st[id * 2 + 1];
}

Node get(int id, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return st[id];
    }
    int mid = (l + r) >> 1;
    if(qr <= mid){
        return get(id * 2, l, mid, ql, qr);
    }
    else if(ql > mid){
        return get(id * 2 + 1, mid + 1, r, ql, qr);
    }
    else{
        Node a = get(id * 2, l, mid, ql, qr);
        Node b = get(id * 2 + 1, mid + 1, r, ql, qr);

        Node c = a + b;
        return c;
    }
}
signed main(){
    IOS
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    
    foru(j, 1, n) cin >> arr[j];
    build(1, 1, n);
    
    while(m--){
        int type, l, r, x, val;
        cin >> type;
        
        if(type == 1){
            cin >> x >> val;
            arr[x] = val;
            update(1, 1, n, x, val);
        }
        else{
            cin >> l >> r;
            Node ans = get(1, 1, n, l, r);
            cout << ans.range << endl;
        } 

    }

}

// Algorithm:
// Merging information from two nodes:

// If the combination (a[r] < b[l]) exists:

// Calculate the sum of pairs i,j in the parent node (cnt)=  pairs in child one +  in child two + the combination of the two nodes.
// The number of combinations can be calculated by multiplying the child one prefixes and child two suffixes of the two parts.

// If the combination doesn't exist:

// No need to calculate the combination.

//LINK TO PROBLEM: https://codeforces.com/contest/1567/problem/E
     
