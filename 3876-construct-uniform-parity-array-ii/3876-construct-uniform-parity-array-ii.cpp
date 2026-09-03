class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int mini=nums1[0];
        for(int i=0; i<n; i++) {
            mini=min(mini, nums1[i]);
        }
        if(mini%2!=0) {
            return true;
        }
        for(int i=0; i<n; i++) {
            if(nums1[i]%2!=0) {
                return false;
            }
        }
        return true;
    }
};