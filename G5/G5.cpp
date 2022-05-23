// Фаталиев Джавид Б05-125 задача G с 5 контеста
// https://codeforces.com/group/PVbQ8eK2T4/contest/368711/submission/147220766
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::cin;
using std::string;

int dp(int n, int m, vector<int> &a, vector<int> &b) {
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }
  for (int i = 0; i <= m; i++) {
    dp[0][i] = 0;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i - 1] != b[j - 1]) {
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      }
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
    }
  }
  return dp[n][m];
}

int main() {
  int n, m;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  cout << dp(n, m, a, b);
}
