class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        vector<string>ans;
        map<string,int>mp;
        for(auto str:words){
            mp[str]++;
        }
        vector<pair<string,int>>vec(mp.begin(),mp.end());

        sort(vec.begin(),vec.end(),[](const auto&a ,const auto &b){
            if(a.second==b.second) return a.first<b.first;  
            return a.second>b.second;
        });

        for(int i=0;i<k;i++){
            ans.push_back(vec[i].first);
        }
        vec.clear();
        return ans;
    }
};
