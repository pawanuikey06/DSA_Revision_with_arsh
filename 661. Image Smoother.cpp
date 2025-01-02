class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                {0, 1},   {1, -1}, {1, 0},  {1, 1}};
        vector<vector<int>> ans(img.size(), vector<int>(img[0].size(), 0));
        int m = img.size();
        int n = img[0].size();
        for (int i = 0; i < img.size(); i++) {
            for (int j = 0; j < img[0].size(); j++) {
                int sum = img[i][j];
                int count = 1;
                for (int k = 0; k < 8; k++) {
                    int ni = i + directions[k][0]; // New row index
                    int nj = j + directions[k][1]; // New column index
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        sum += img[ni][nj];
                        count++;
                    }
                }
                ans[i][j] = floor(sum / count);
            }
        }
        return ans;
    }
};
