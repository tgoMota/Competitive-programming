#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define mod 1e9+7
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
typedef long long ll;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> pii;

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n, k;
        scanf("%d%d", &n, &k);
        vector<int> v(n);
       // map<int,int> cnt;
        for(int i = 0; i < n ; ++i) scanf("%d", &v[i]);
        int ans = 0;
        // for(int i = 0, j = n-1 ; i < j ; ++i, --j){
        //     cnt[v[i]+v[j]]++;
        // }
        int ansmin = oo;
        //int S = (*cnt.begin()).first;
        for(int S = 2; S <= 2*k ; ++S){
            ans = 0;
            for(int i = 0, j = n-1 ; i < j ; ++i, --j){
                if(v[i] + v[j] != S){
                    if(S-v[i] > k || S-v[j] > k){
                        ans = oo;
                        break;
                    } 
                    if(v[i] < 1 || v[i] >= k || v[j] < 1 || v[j] >= k || v[i] > S || v[j] >= S){
                        if(v[i] < 1 || v[i] >= k || v[i] >= S) ans++;
                        if(v[j] < 1 || v[j] >= k || v[j] >= S) ans++;
                    }else {
                        ans++;
                    }
                }
            }
            ansmin = min(ansmin, ans);
        }
        printf("%d\n", ansmin);
    }
    return 0;
}