class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) 
    {
        int n = nums.size();
        int count = 0;

        if (n == 1) return 1;

        for (int i = 0; i < n; i++)
        {
            unordered_map<int, int> mp;

            for (int j = i; j < n; j++)
            {
                vector<int> temp;
                mp[j]++;
                bool helpme = false;

                for (int k = 0; k < n; k++) {
                    if (mp.find(k) == mp.end())
                    {
                        temp.push_back(nums[k]);
                    }
                }

                if (temp.size() == 1) count += 1;
                else if (temp.size() == 0) count += 1;
                else 
                {
                    for (int m = 0; m < temp.size() - 1; m++)
                    {
                        if (temp[m] >= temp[m + 1]) helpme = true;
                    }

                    if (helpme == false) count += 1;
                }
            }
        }

        return count;
        
    }
};
