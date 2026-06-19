class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> combination;
        backtrack(nums,0,res,combination,target);
        return res;
    }

    void backtrack(const vector<int> &nums, int i, vector<vector<int>> &res, vector<int> &combination, int target){
        if(target == 0){
            res.push_back(combination);
            return;
        }
        if(target < 0 || i >= nums.size()){
            return;
        }
        combination.push_back(nums[i]);
        backtrack(nums,i,res,combination,target-nums[i]);
        combination.pop_back();
        backtrack(nums,i+1,res,combination,target);
    }
};
