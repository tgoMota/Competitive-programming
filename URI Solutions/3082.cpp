//https://www.urionlinejudge.com.br/judge/pt/problems/view/3082
//URI 3082 - Matador De Onça Mutante
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
int N, K;
vector<int> ans;
struct CentroidDec{
  int N;
  vector<int> lv, size, sub_tree, dist_cent, dist_sub;
  vector<bool> isCentroid;
  vector<vector<int>> tree;
  CentroidDec(){}
  CentroidDec(const int n){
    N = n;
    size.assign(n+1, 0);
    isCentroid.assign(n+1, false);
    tree.assign(n+1, vector<int>());
    lv.assign(n+1, 0);
  }

  void add_edge(int u, int v){
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  void dfs(int v, int p){
    size[v] = 1;
    for(int x : tree[v]){
      if(x != p && !isCentroid[x]){
        dfs(x, v);
        size[v] += size[x];
      }
    }
  }

  void dfs1(int v, int p){
    size[v] = 1;
    dist_cent.push_back(lv[v]);
    for(int x : tree[v]){
      if(x != p && !isCentroid[x]){
        lv[x] = lv[v] + 1;
        dfs1(x,v);
        size[v] += size[x];
      }
    }
  }

  void dfs2(int v, int p){
    sub_tree.push_back(v);
    size[v] = 1;
    dist_sub.push_back(lv[v]);
    for(int x : tree[v]){
      if(x != p && !isCentroid[x]){
        lv[x] = lv[v] + 1;
        dfs2(x,v);
        size[v] += size[x];
      }
    }
  }

  int getCentroid(int v, int p, const int n){
    bool is_centroid = true;
    int heaviest_child = 0;
    for(int x : tree[v]){
      if(x != p && !isCentroid[x]){
        if(2*size[x] > n) is_centroid = false;
        if(heaviest_child == 0 || size[heaviest_child] < size[x]) heaviest_child = x;
      }
    }

    if(is_centroid && 2*size[v] >= n) return v;
    return getCentroid(heaviest_child, v, n);
  }

  int getCentroid(int v){
    dfs(v, -1);
    int centroid = getCentroid(v, -1, size[v]);
    isCentroid[centroid] = true;
    return centroid;
  }

  void decompose(int v){
    int cent_root = getCentroid(v);
    dist_cent.clear();
    lv[cent_root] = 0;
    dfs1(cent_root, -1);
    sort(dist_cent.begin(), dist_cent.end());
    int d = upper_bound(dist_cent.begin(), dist_cent.end(), K) -  dist_cent.begin();
    ans[cent_root] += d;
    for(int x : tree[cent_root]){
      if(!isCentroid[x]){
        sub_tree.clear();
        dist_sub.clear();
        lv[x] = 1;
        dfs2(x, cent_root);
        sort(dist_sub.begin(), dist_sub.end());

        for(int node : sub_tree){
          int add = upper_bound(dist_cent.begin(), dist_cent.end(), K-lv[node])-dist_cent.begin();
          int repeated = upper_bound(dist_sub.begin(), dist_sub.end(), K-lv[node])-dist_sub.begin();
          ans[node] += add - repeated;
        }
      }
    }

    for(int x : tree[cent_root]){
      if(!isCentroid[x]) decompose(x);
    }
  }
};
int main(){
    fastio();
    cin >> N >> K;
    CentroidDec cd(N);
    for(int i = 0; i < N-1 ; ++i){
      int a, b;
      cin >> a >> b;
      cd.add_edge(a,b);
    }
    ans.assign(N+1, 0);
    cd.decompose(1);
    for(int i = 1; i <= N ; ++i) cout << ans[i] << '\n';
    return 0;
}

