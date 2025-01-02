// GREEDY METHOD FAILED
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        if (envelopes.size() == 1)
            return 1;
        int finalCount = 1;

        for (int i = 0; i < envelopes.size(); i++) {
            int CurS = envelopes[i][0];
            int CurE = envelopes[i][1];
            int count = 1;
            for (int j = i+1; j < envelopes.size(); j++) {
                if (envelopes[j][0] > CurS && envelopes[j][1] > CurE) {
                    count++;
                    finalCount = max(finalCount, count);
                    CurS = envelopes[j][0];
                    CurE = envelopes[j][1];
                }
            }
        }
        return finalCount;
    }
};
