class Solution {
public:
    typedef long long ll;
    vector<ll> power;
    unordered_map<string, int> mp;
    int solve(int &k ,int i,bool goback,int jump){
        if(i>k+1 || i<0) return 0;
        string key = to_string(i) + "_" + to_string(jump) + "_" + to_string(goback);
        if (mp.find(key) != mp.end())
            return mp[key];
        int count =0;
        if(i==k) count++;
        if(goback){
            count+=solve(k,i-1,false,jump);

        }
        count+=solve(k,i+power[jump],true,jump+1);

        return mp[key]= count;
    }
    int waysToReachStair(int k) {
       power.resize(33);
       for(int i = 0; i < 33; ++i) {
            power[i] = pow(2, i);
        }
       return solve(k,1,true,0);
    }
};
