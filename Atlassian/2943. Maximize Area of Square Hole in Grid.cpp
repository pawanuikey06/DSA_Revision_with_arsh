class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        

        int count=1;
        int maxH=1;
        for(int i=1;i<hBars.size();i++){
            if(hBars[i-1]+1==hBars[i]){
                count++;
            }else{
                count=1;
            }
            maxH=max(maxH,count);

        }
        //if only single bar
        maxH=max(maxH,count);
        count=1;
        int maxV=1;
        for(int i=1;i<vBars.size();i++){
            if(vBars[i-1]+1==vBars[i]){
                count++;
            }else{
                count=1;
            }
            maxV=max(maxV,count);

        }
        //if only single bar
        maxV=max(maxV,count);

        int ax =min(maxH,maxV)+1;
        
        return ax*ax;
        


    }
};
