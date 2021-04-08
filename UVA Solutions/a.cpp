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
struct suffixArray{
  string s;
  int N;
  vector<int> SA, tempSA, RA, tempRA, c;
  vector<int> LCP, PLCP, Phi;
  suffixArray(){}
  suffixArray(string _s){
    s = _s;
    N = (int)s.size();
    SA.assign(N, 0);
    tempSA.assign(N, 0);
    RA.assign(N, 0);
    tempRA.assign(N, 0);
    LCP.assign(N, 0);
    PLCP.assign(N, 0);
    Phi.assign(N, 0);
    buildSA();
    buildLCP();
    SA.erase(SA.begin());
    LCP.erase(LCP.begin());
  }

  void countingSort(int k){
    int maxi = max(N, 256);
    c.assign(maxi, 0);
    for(int i = 0; i < N ; ++i) ++c[RA[(i+k)%N]];
    for(int i = 1; i < maxi ; ++i) c[i]+=c[i-1];
    for(int i = 0; i < maxi ; ++i) tempSA[--c[RA[(SA[i]+k)%N]]] = SA[i];
    SA.swap(tempSA);
  }

  void buildSA(){
    for(int i = 0; i < N ; ++i){
      RA[i] = s[i];
      SA[i] = i;
    }

    for(int k = 1; k < N ; k<<=1){
      countingSort(k);
      countingSort(0);

      int r = tempRA[SA[0]] = 0;
      for(int i = 1; i < N ; ++i){
        tempRA[SA[i]] = (ii(RA[SA[i]], RA[(SA[i]+k)%N]) == ii(RA[SA[i-1]], RA[(SA[i-1]+k)%N]) ? r : ++r);
      }
      RA.swap(tempRA);
      if(RA[SA[N-1]] == N-1) break;
    }
  }

  void buildLCP(){
    
  }

};
int main(){
    fastio();
    int n;
    while(cin >> n && n){
      vector<string> v(n);
      for(int i = 0; i < n ; ++i){
        cin >> v[i];
      }

    }
    return 0;
}

