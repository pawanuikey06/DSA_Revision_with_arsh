
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        
        vector<int>freq(arr.size()+1,0);
        for(int num:arr){
            freq[num]++;
        }
        int rep=0;
        int mis=0;
        for(int i=1;i<=arr.size();i++){
            
            if(freq[i]==0){
                mis=i;
            }
            if(freq[i]>1){
                rep=i;
            }
            
        }
        return {rep,mis};
    }
};
