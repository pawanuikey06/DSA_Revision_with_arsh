class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;

        int longest = 0;
        int i = 1;

        while (i < n - 1) {
            // Check if it's a peak
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                int left = i - 1;
                int right = i + 1;

                // Expand to the left
                while (left > 0 && arr[left] > arr[left - 1]) {
                    left--;
                }

                // Expand to the right
                while (right < n - 1 && arr[right] > arr[right + 1]) {
                    right++;
                }

                // Calculate mountain length
                int mountainLength = right - left + 1;
                longest = max(longest, mountainLength);

                // Move `i` to the end of the current mountain
                i = right;
            } else {
                i++;
            }
        }

        return longest;
    }
};
