class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums,
                                       vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> ans;

        for (auto& query : queries) {
            int k = query[0], trimLen = query[1];
            vector<string> temp(n);

            for (int i = 0; i < n; i++) {
                temp[i] = nums[i].substr(nums[i].size() - trimLen, trimLen);
            }

            vector<int> idx(n);
            for (int i = 0; i < n; i++)
                idx[i] = i;

            sort(idx.begin(), idx.end(), [&](int i, int j) {
                if (temp[i] == temp[j])
                    return i < j;
                return temp[i] < temp[j];
            });

            ans.push_back(idx[k - 1]); // 1-based indexing for queries
        }

        return ans;
    }
};
