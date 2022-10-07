//https://codeforces.com/contest/1521/problem/B
//B. Nastia and a Good Array
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
        int n;
        cin >> n;
        vector<int> v(n);
        int mx = oo, p = 1;
        for(int i = 0; i < n ; ++i){
          cin >> v[i];
          if(v[i] < mx){
            mx = v[i];
            p = i+1;
          }
        }
        if(n == 1){
          cout << 0 << '\n';
          continue;
        }
        cout << n-1 << '\n';
        for(int i = 0; i < n ; ++i){
          if(i == p-1) continue;
          cout << p << " " << i+1 << " " << mx << " " << mx+abs(p-i-1) << '\n';
        }
    }
    return 0;
}