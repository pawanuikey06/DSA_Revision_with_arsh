class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {

        if (s.size() < a.size() || s.size() < b.size() || s.size() < k)
            return {};
        vector<int> st;
        for (int i = 0; i <= s.size() - a.size(); i++) {
            string str = s.substr(i, a.size());

            if (str == a) {
                st.push_back(i);
            }
        }
        vector<int> st1;
        for (int i = 0; i <= s.size() - b.size(); i++) {
            string str = s.substr(i, b.size());

            if (str == b) {
                st1.push_back(i);
            }
        }

        vector<int> ans;
        for (int i = 0; i < st.size(); i++) {
            for (int j = 0; j < st1.size(); j++) {
                if (abs(st[i] - st1[j]) <= k) {
                    ans.push_back(st[i]);
                    break;
                }
            }
        }
        
        return ans;
    }
};
