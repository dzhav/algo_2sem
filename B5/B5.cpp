// Фаталиев Джавид Б05-125 задача B с 5 контеста
// https://codeforces.com/group/PVbQ8eK2T4/contest/368711/submission/147602572
#include <iostream>
#include <vector>
#define INF 1e12

using std::vector;
using std::cout;
using std::cin;
using std::string;

vector <long long> dp(vector<long long> & dp, vector<long long> & pos, vector<long long> & prev, vector <long long> &a, int n){
  long long length = 0;
  pos[0] = -1;
  dp[0] = -INF;
  for (long long i = 0; i < n; i++){
    long long j = (int) (std::upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin());
    if (dp[j-1] <= a[i] and a[i] < dp[j]){
      dp[j] = a[i];
      pos[j] = i;
      prev[i] = pos[ j - 1];
      length = std::max(length, j);
    }
  }

  vector <long long> answer(length);
  long long p = pos[length];
  int num = 0;
  while (p != -1){
    answer[num] = p; num++;
    p = prev[p];
  }
  return answer;
}

int main() {
  long long n;
  cin >> n;
  vector <long long> a(n);
  for (long long i = 0; i < n; i++){
    cin >> a[i];
  }
  std::reverse(a.begin(), a.end());
  vector <long long> dp_array(n + 1, INF);
  vector <long long> pos(n + 1);
  vector <long long> prev(n);
  vector <long long> ans = dp(dp_array, pos, prev, a, n);
  cout << ans.size() << "\n";
  for (long long an : ans){
    cout<<n - an << " ";
  }
}
