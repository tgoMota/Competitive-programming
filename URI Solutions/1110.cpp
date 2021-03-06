//https://www.urionlinejudge.com.br/judge/pt/problems/view/1110
//URI 1110 - Jogando Cartas Fora
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
    int n;
    while(cin  >> n && n){
      deque<int> d;
      for(int i = 1; i <= n ; ++i){
        d.push_front(i);
      }
      vector<int> dis, rem;
      while((int)d.size() >= 2){
        dis.push_back(d.back());
        d.pop_back();
        d.push_front(d.back());
        d.pop_back();
      }
      cout << "Discarded cards: ";
      for(int i = 0 ; i < (int)dis.size() ; ++i){
        if(i) cout << ", ";
        cout << dis[i];
      }
      if(!d.empty()) cout << "\nRemaining card: " << d.back()  << '\n';
      else cout <<  "\nRemaining card: " << '\n';
    }
    return 0;
}
