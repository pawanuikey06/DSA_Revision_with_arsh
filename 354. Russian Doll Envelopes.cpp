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

// Dynamic Programming TLE
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        if (envelopes.size() == 1)
            return 1;
        vector<int>dp(envelopes.size(),1);
        int count=1;
        for(int i=0;i<envelopes.size();i++){

            for(int j=0;j<i;j++){
                 if(envelopes[i][0]>envelopes[j][0] && envelopes[i][1]>envelopes[j][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                    count =max(count,dp[i]);

                 }
            }
        }
        return count;
    }
};

//  Dynamic Programming + Lower_bound
class Solution {
public:
   
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),[](vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    });
       vector<int>lis;
       for(auto &vec :envelopes){
            auto it =lower_bound(begin(lis),end(lis),vec[1]);

            if(it==lis.end()){
                lis.push_back(vec[1]);
            }else{
                *it=vec[1];
            }
       }
       return lis.size();
    }
};
