class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {

        unordered_map<string,vector<int>>mp;
        for(auto vec:access_times){
            int time =stoi(vec[1]);
            mp[vec[0]].push_back(time);
        }
        vector<string>res;
        for(auto it :mp){
            sort(it.second.begin(),it.second.end());

            for(int i=2;i<it.second.size();i++){
                if(it.second[i]-it.second[i-2]<100){
                    res.push_back(it.first);
                    break;
                }
            }
        }
        return res;

       
        
        
    }
};
