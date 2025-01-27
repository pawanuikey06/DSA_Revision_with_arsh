class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; // Handle empty input case

        unordered_map<char, string> mp;
        vector<string> ans = {""}; // Start with an empty combination

        // Mapping digits to their respective letters
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        // Use iterative approach to generate combinations
        for (char digit : digits) { 
            vector<string> temp;
            for (const string& combination : ans) { 
                for (char letter : mp[digit]) {
                    temp.push_back(combination + letter);
                }
            }
            ans = temp; // Update ans with the new combinations
        }

        return ans;
    }
};
