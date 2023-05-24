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

// five cards can be formed by two independent set.
// so we want to calculate the number of one satisfied set which we have in original set.
// O(n ^ 2) solutions: we iterate all pair cards and increase a count of other cards using map<vector<int>, int>.
// So ans = a sum of C 2 cnt[i]. 
// cnt[i] the number of appearence of cards in good set.
