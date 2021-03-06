//https://leetcode.com/problems/range-sum-query-immutable/
//303. Range Sum Query - Immutable
class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int>& nums) {
        sum.push_back(0);
        for(int i = 0; i < nums.size() ; ++i) {
            sum.push_back(nums[i]);
            sum[i+1]+=sum[i];
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j+1]-sum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */