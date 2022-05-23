// Фаталиев Джавид Б05-125 задача E с 5 контеста
// https://codeforces.com/group/PVbQ8eK2T4/contest/368711/submission/147596261
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::cout;
using std::cin;
using std::string;

long long dp(long long n) {
  vector<vector<long long>> dp(2001, vector<long long>(2001));
  dp[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      if (j / 2 < 1) {
        dp[i][j] = 0;
      } else {
        if (i == j) {
          dp[i][j] = 1;
        } else {
          for (int k = 1; k <= std::min(j / 2, i - j); k++) {
            dp[i][j] += dp[i - j][k];
          }
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += dp[n][i];
  }
  return ans;
}

int main() {
  long long n;
  cin >> n;
  cout << dp(n);
}
