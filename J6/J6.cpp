// Фаталиев Джавид Б05-125 задача J с 6 контеста
// https://codeforces.com/group/PVbQ8eK2T4/contest/371629/submission/150456794
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

unsigned long long dp(unsigned long long n, unsigned long long m) {
  unsigned long long power_n = (1 << n);
  if (n == 1 && m == 1) return 2;
  vector<vector<unsigned long long>> dp(m, vector<unsigned long long>(power_n, 0));
  vector<vector<bool>> dpi(power_n, vector<bool>(power_n, true));
  for (unsigned long long i = 0; i < power_n; i++) {
    for (unsigned long long j = 0; j < power_n; j++) {
      for (unsigned long long k = 0; k < n - 1; k++) {
        if ((i >> k) % 2 == ((i >> (k + 1)) % 2)) {
          if (((i >> k) % 2 == 1) && ((j >> k) % 2 == 1) && ((j >> (k + 1)) % 2 == 1)) dpi[i][j] = false;
          if (((i >> k) % 2 == 0) && ((j >> k) % 2 == 0) && ((j >> (k + 1)) % 2 == 0)) dpi[i][j] = false;
        }
      }
    }
  }
  for (unsigned long long &i: dp[0]) i = 1;
  unsigned long long ans = 0;
  for (unsigned long long i = 1; i < dp.size(); i++) {
    for (unsigned long long j = 0; j < power_n; j++) {
      for (unsigned long long k = 0; k < power_n; k++) {
        if (dpi[k][j]) dp[i][j] += dp[i - 1][k];
      }
    }
  }
  for (unsigned long long i = 0; i < power_n; i++) {
    ans += dp[m - 1][i];
  }
  return ans;
}

int main() {
  unsigned long long n, m;
  cin >> m >> n;
  if (n > m) std::swap(n, m);
  cout << dp(n, m);
}
