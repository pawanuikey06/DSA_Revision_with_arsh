class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n =arr.size();
        vector<int>ans;
        deque<int>dq;
        for(int i=0;i<k;i++){
            while(!dq.empty() && arr[i]>arr[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for(int i=k ;i<n ;i++){
            ans.push_back(arr[dq.front()]);
            if(!dq.empty() && i-dq.front()>=k) dq.pop_front();
            
            while(!dq.empty() && arr[i]>arr[dq.back()]){
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        ans.push_back(arr[dq.front()]);
        return ans;
        
    }
};
