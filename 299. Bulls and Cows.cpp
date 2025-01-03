class Solution {
public:
    string getHint(string secret, string guess) {
        int countBull =0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                countBull++;
                secret[i]=guess[i]='*';
            }
        }
        int countCow=0;
        unordered_map<char,int>mp;
        for(char ch:secret){
            if(ch!='*'){
                mp[ch]++;
            }
        }
          for (char c : guess) {
            if (c != '*' && mp[c] > 0) {
                countCow++;
                mp[c]--;
            }
        }
        string ans =to_string(countBull)+'A'+to_string(countCow)+'B';
        return ans;
    }
};
