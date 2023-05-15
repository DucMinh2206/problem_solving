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
int cost[30];
int LCS(string a, string b){
    int a_size = a.size(), b_size = b.size();

    int ans[a_size + 1][b_size + 1];
    memset(ans, 0, sizeof(ans));
    int sum = 0;
    foru(i, 1, a_size){
        foru(j, 1, b_size){
            if(a[i - 1] == b[j - 1]){
                ans[i][j] = ans[i - 1][j - 1] + cost[a[i - 1] - 'a'];
            }
            else ans[i][j] = max(ans[i - 1][j], ans[i][j - 1]);
            sum = max(ans[i][j], sum);
        }
    }
    return sum;
}

signed main(){
    IOS
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int x, y;
    cin >> x >> y;

    string s, ss;
    foru(j, 0, 25) cin >> cost[j];

    cin >> s >> ss;
    cout << LCS(s, ss);


}
//
// link problem: https://www.spoj.com/problems/ADASEQEN/
