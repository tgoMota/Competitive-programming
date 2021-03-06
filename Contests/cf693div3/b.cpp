#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
#define LOCAL
#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...) 42
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}
const int mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
vector<int> v;
vector<vector<int>> memo;

int solve(int idx, int sum, const int totalSum, const int n){
  if(idx == n || sum*2 >= totalSum) return sum*2 == totalSum;
  int& ans = memo[idx][sum];
  if(ans != -1) return ans;
  return ans = solve(idx+1, sum+v[idx], totalSum, n) || solve(idx+1, sum, totalSum, n);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n;
        scanf("%d", &n);
        v.assign(n, 0);
        int totalW = 0;
        for(int i = 0; i < n ; ++i) {
          scanf("%d", &v[i]);
          totalW += v[i];
        }

        memo.assign(n+1, vector<int>(totalW+1, -1));
        int ans = totalW % 2 == 0 ? solve(0,0, totalW, n) : 0;
        printf("%s\n", ans ? "YES" : "NO");
    }
    return 0;
}