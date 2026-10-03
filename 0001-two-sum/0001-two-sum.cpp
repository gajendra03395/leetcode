class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int diff = target - nums[i];
            if (numMap.count(diff)) {
                return {numMap[diff], i};
            }
            numMap[nums[i]] = i;
        }

        return {}; 
    }
};