class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0 , max1 = INT_MIN;
        for(int val : nums)
        {
            curr += val;
            max1 = max(curr , max1);
            if(curr < 0)
            {
                curr = 0;
            }
        }
        return max1;
    }
};