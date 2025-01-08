class Solution {
  public:
    static bool customComp(char a, char b) {
        // Define the custom order
        std::string order = "!,#$%&*?@^";
        std::unordered_map<char, int> orderMap;

        // Map each character to its priority
        for (int i = 0; i < order.size(); ++i) {
            orderMap[order[i]] = i;
        }

        // Compare the priority of characters
        return orderMap[a] < orderMap[b];
    }

    void matchPairs(int n, char nuts[], char bolts[]) {
        // Sort nuts and bolts using the static custom comparator
        std::sort(nuts, nuts + n, customComp);
        std::sort(bolts, bolts + n, customComp);
    }
};
