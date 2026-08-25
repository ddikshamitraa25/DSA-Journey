class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        for(int i=1; i<=110; i++){
            int multiple=i*k;
            bool found=false;
            for(int j=0; j<nums.size(); j++){
                if(nums[j]==multiple){
                    found=true;
                    break;
                }
            }
            if(found==false){
                return multiple;
            }
        }
        return -1;
    }
};