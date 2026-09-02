class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int>count(n, 0);
        for(int i=0; i<n; i++){
            count[nums[i]]++;
            if(count[nums[i]]>1)return nums[i];
        }
        return -1;
    }
};