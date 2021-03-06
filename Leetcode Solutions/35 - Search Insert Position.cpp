//https://leetcode.com/problems/search-insert-position/
//35. Search Insert Position
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1, mid;
        while(lo < hi){
            mid = (lo+hi)>>1;
            if(nums[mid] == target) return mid;
            if(nums[mid] < target) lo = mid+1;
            else hi = mid;
        }
        if(nums[lo] < target) lo++;
        return lo;
    }
};

int main(){
    int k, t, e;
    vector<int> ans;
    cin >> k >> t;
    for(int i = 0; i < k ; ++i){
        cin >> e;
        ans.push_back(e);
    }
    Solution a;
    printf("%d\n",a.searchInsert(ans,t));

    return 0;
}