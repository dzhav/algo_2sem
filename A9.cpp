//  Фаталиев Джавид Б05-125 9 контест задача A
// https://codeforces.com/group/PVbQ8eK2T4/contest/379712/submission/157929546


#include <iostream>
#include <vector>
#define INFI 1000000

using std::cin;
using std::vector;
using std::cout;
long long Prim(vector<vector<int>> &ways) {
  long long int summa = 0;
  int len = ways.size();
  vector<bool> used(len);
  vector<int> mini(len, INFI);
  mini[1] = 0;
  for (int i = 1; i < len; i++) {
    int counter = 1;
    for (int j = 1; j < len; j++) if (mini[j] < mini[counter] && !used[j]) counter = j;
    used[counter] = true;
    summa += mini[counter];
    mini[counter] = INFI;
    for (int k = 1; k < len; k++) if (ways[counter][k] < mini[k] && !used[k]) mini[k] = ways[counter][k];
  }
  return summa;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> ways(n + 1, vector<int>(n + 1, INFI));
  int b, e, f;
  for (int i = 0; i < m; i++) {
    cin >> b >> e >> f;
    ways[b][e] = f;
    ways[e][b] = f;
  }
  cout << Prim(ways);
}
