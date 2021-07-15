#include <bits/stdc++.h>
using namespace std;
int n, A;
int sum = 0;
int a[110];
bool dp[110][10010];

int main() {
    cin >> n >> A;
    for(int i = 0; i < n; i++) cin >> a[i];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= A; j++) {
            dp[i+1][j] |= dp[i][j];
            if(j >= a[i]) dp[i+1][j] |= dp[i][j-a[i]];
            if(dp[i+1][j] && j == A) {
                cout << i << " " << j << endl;
            }
        }
    }

    cout << sum << endl;

    return 0;
}
