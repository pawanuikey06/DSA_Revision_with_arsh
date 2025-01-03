// Brute Force Solution 
class Solution {
public: 
    
     int minMoves2(vector<int>& nums) {
        
       long long ans = LLONG_MAX;
        
        for (int i = 0; i < nums.size(); i++) {
            long long curr = 0; // Use long long to prevent overflow
            for (int j = 0; j < nums.size(); j++) {
                if (i != j) {
                    curr += abs(nums[i] - nums[j]);
                    
                }
            }
            ans = min(curr, ans); 
        }
        return (int)ans;
    }
};

// O(n) Solution
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), steps = 0;
        nth_element(nums.begin(), nums.begin()+(n/2), nums.end()); //Fixing ths median element
        int median = nums[n/2];
        for(int i=0; i<n; i++){
            steps += abs(nums[i] - median);
        }
        return steps;
    }
};
