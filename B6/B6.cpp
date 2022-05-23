// Фаталиев Джавид Б05-125 задача B с 6 контеста
// https://codeforces.com/group/PVbQ8eK2T4/contest/371629/submission/150562671
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

long long power(long long ord, long long power_) {
  if (power_ == 1) return ord % 1000000007;
  while (power_) {
    if (power_ % 2 == 1) return (ord * power(ord, power_ - 1)) % (1000000000 + 7);
    else return (power(ord, power_ / 2) * power(ord, power_ / 2)) % (1000000007);
  }
}

std::pair<long, long> remainders_of_the_division(int k) {
  long long mod = 1e9 + 7;
  long long ans = 2;
  bool sign = false;
  vector<long long> a(k);
  for (int i = 0; i < k; i++) cin >> a[i];
  for (int i = 0; i < k; i++) {
    if (!sign) {
      if (a[i] % 2) sign = false;
      else sign = true;
    }
    ans = power(ans, a[i]);
  }
  ans = (ans * 500000004) % mod;
  if (sign) {
    cout << ((ans + 1) * 333333336) % mod << "/" << ans;
    return {((ans + 1) * 333333336) % mod, ans};
  } else {
    cout << ((ans - 1) * 333333336) % mod << "/" << ans;
    return {((ans - 1) * 333333336) % mod, ans};
  }
}

int main() {

  int k;
  cin >> k;
  std::pair<long, long> ans = remainders_of_the_division(k);
  cout << ans.first << "/" << ans.second;
};
