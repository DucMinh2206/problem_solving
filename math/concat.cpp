#include "bits/stdc++.h"
//#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define foru(j, a, b) for(int j = a; j <= b; ++j)
#define mp make_pair
#define endl '\n'
#define int long long
const int maxN = 1e5 + 5;
const int can = 2000;
int cnt[3], arr[maxN], ans[maxN];
stack<int> zero, one;
signed main(){
    IOS
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    foru(j, 1, n){
        cin >> arr[j];
        arr[j] = arr[j] % 3;
        arr[j] = (arr[j] * arr[j]) % 3;
        if(arr[j] == 1) {
            one.push(j);
            ans[j] = 1;
        }
        else{
             zero.push(j);
             ans[j] = 0;
        }
    }
    int val, diff;
    if(one.size() == zero.size()){
        cout << "2" << endl;
        foru(j, 1, n){
            cout << ans[j];
        }
    }
    else if(one.size() > zero.size()){
        diff = one.size() - zero.size();
        diff /= 2;
        foru(j, 1, diff){
            ans[one.top()] = 0;
            one.pop();
        }
        cout << "0" << endl;
        foru(j, 1, n){
            cout << ans[j];
        }
    }
    else if(zero.size() > one.size()){
        diff = zero.size() - one.size();
        diff /= 2;
        foru(j, 1, diff){
            ans[zero.top()] = 1;
            zero.pop();
        }
        cout << "2" << endl;
        foru(j, 1, n){
            cout << ans[j];
        }
    }

    return 0;
}
    
// concat(i, j) * concat(j, i) + a[i] * a[j] = a[i] * a[i] + a[j] * a[j] (modulo 3)
// a[i] ^ 2 = 0, 1 (modulo 3)
// so we divide into some ways.
// if we divide both parts having one and zero -> -1

// so we want to divide one part full 0 or full 1.
// if the number of elements of first part is bigger than second part, we can move some elements from one to other parts.
// -> so there is no condition that both parts having one and zero elements.
