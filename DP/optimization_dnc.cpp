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
#define int long long

const int maxN = 8005;
const int mod = 1e9 + 7;
const int inf = (ll)1e16;


int n, k;
int cost[maxN], prefix_sum[maxN], dp[805][8005]; 
int pos;// luu vi tri k lon nhat sao cho dp co gia tri be nhat
int C(int l, int r){
    if(l > r) return 0;
    return (prefix_sum[r] - prefix_sum[l - 1]) * (r - l + 1);
}
void solve(int g, int l, int r, int optimal_l, int optimal_r){
    if(l > r) return;
    int mid = (l + r) >> 1;
    dp[g][mid] = inf;

    foru(j, optimal_l, optimal_r){
        ll new_value = dp[g - 1][j] + C(j + 1, mid);
        if(new_value < dp[g][mid]){
            pos = j;
            dp[g][mid] = new_value;
        } 
    }
    solve(g, l, mid - 1, optimal_l, pos);
    solve(g, mid + 1, r, pos, optimal_r);
}
signed main(){
    IOS
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    foru(j, 1, n){
        cin >> cost[j];
        prefix_sum[j] = prefix_sum[j - 1] + cost[j];
    }
    foru(j, 1, n){
        dp[1][j] =  C(1, j);
    }
    foru(j, 2, k)  solve(j, 1, n, 1, n);

    cout << dp[k][n];
}
// Link of problem: https://www.hackerrank.com/contests/ioi-2014-practice-contest-2/challenges/guardians-lunatics-ioi14/problem
