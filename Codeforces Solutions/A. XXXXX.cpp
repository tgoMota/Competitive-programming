//https://codeforces.com/problemset/problem/1364/A
//A. XXXXX
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
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
//CHECK THE CONSTRAINTS, PLEASE
int main(){
    fastio();
    int t;
    cin >> t;
    for(int ti = 1; ti <= t ; ++ti){
        int n, m;
        cin >> n >> m;
        vector<int> v(n);
        int subMax = -1, sum = 0;
        for(int i = 0; i < n ; ++i) {
          cin >> v[i];
          sum+=v[i];
          if(sum%m) subMax = i+1;
        }
        sum = 0;
        for(int i = n-1 ; i >= 0 ; --i){
          sum+=v[i];
          if(sum%m) subMax = max(subMax, n-i);
        }

        cout << subMax << '\n';
    }
    return 0;
}
