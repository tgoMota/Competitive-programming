//https://codeforces.com/contest/1487/problem/D
//Codeforces | D. Pythagorean Triples
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
int n;
 
int getb(int a){
  int b = (a*a-1)/2;
  return b;
}
 
bool pit(int a, int b, int c){
  return (c*c) == (a*a) + (b*b);
}
 
int main(){
    fastio();
    int t;
    cin >> t;
    for(int ti = 1; ti <= t ; ++ti){
        cin >> n;
        int ans = 0;
        for(int a = 1; a <= n ; ++a){
          int b = getb(a);
          int c = b+1;
          if(b > n || c > n) break;
          if(b <= a || !pit(a,b,c)) continue;
          ans++;
        }
 
        cout << ans << '\n';
    }
 
    return 0;
}