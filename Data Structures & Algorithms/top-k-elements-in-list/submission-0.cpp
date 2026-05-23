class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        vector<vector<int>> bucket(nums.size() + 1);
        for(int n : nums){
            freq[n]++;
        }
        for(const auto& entry : freq){
            bucket[entry.second].push_back(entry.first);
        }
        vector<int> res;
        for(int i = bucket.size() - 1; i >0;--i){
            for(int n : bucket[i]){
                res.push_back(n);
                if(res.size() == k){
                    return res;
                }
            }
        }
        return res;
    }
};
