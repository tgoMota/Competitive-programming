#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
      int n;
      scanf("%d", &n);
      vector<int> v(n);
      set<int> s;
      for(int& x : v) scanf("%d", &x);

      for(int i = 0; i < n ; ++i){
          s.insert(((i+v[i])%n + n)%n);
      }

      printf("%s\n", (int)s.size() == n ? "YES" : "NO");
    }
    return 0;
}