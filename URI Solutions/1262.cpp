//https://www.urionlinejudge.com.br/judge/pt/problems/view/1262
//URI 1262 - Leitura Múltipla
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
    string s;
    while(cin >> s){
      int p;
      cin >> p;
      const int N = (int)s.size();
      int ans = 0;
      for(int i = 0, cic = 0; i < N ; ++i){
        if(s[i] == 'W' || cic == p) cic = 0;
        if(cic == 0) ans++;
        if(s[i] != 'W') cic++;
      }

      cout << ans << '\n';
    }
    return 0;
}

