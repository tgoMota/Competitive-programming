//https://www.urionlinejudge.com.br/judge/pt/problems/view/2049
//URI 2049 - Números de Ahmoc
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
    string a, b;
    int t = 1;
    while(cin >> a && a != "0"){
      cin >> b;
      if(t > 1) cout << '\n';
      const int N = (int)a.size();
      const int M = (int)b.size();
      bool ok = false;
      for(int i = 0; i < M && !ok ; ++i){
        if(b.substr(i, N) == a) ok = true;
      }
      cout << "Instancia " << t++ << '\n';
      cout << (ok ? "verdadeira" : "falsa") << '\n';
    }
    return 0;
}

