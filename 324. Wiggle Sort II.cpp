class Solution {
public:
    void wiggleSort(vector<int>& nums) {

        vector<int> temp(nums.begin(), nums.end());
        sort(temp.begin(),temp.end());
        int i=nums.size()-1;
        for(int j=1;j<nums.size();j+=2){
            nums[j]=temp[i--];
        }
        for(int j=0;j<nums.size();j+=2){
            nums[j]=temp[i--];
        }
    }
};
