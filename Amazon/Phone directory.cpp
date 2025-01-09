class Solution {
public:
    struct TrieNode {
        bool isEnd;
        TrieNode* children[26];

        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; ++i) {
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root;

    Solution() {
        root = getNode(); // Initialize the root node
    }

    TrieNode* getNode() {
        return new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* crawler = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (crawler->children[index] == nullptr) {
                crawler->children[index] = getNode();
            }
            crawler = crawler->children[index];
        }
        crawler->isEnd = true;
    }

    TrieNode* prefixstr(string s){
        int n=s.size();
        TrieNode* curr=root;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(curr->children[ch-'a']==NULL){
                return NULL;
            }
            curr=curr->children[ch-'a'];
        }
        
        return curr;
    }
    void findWordsWithPrefix(TrieNode* node, string& prefix, vector<string>& result) {
        if (node == nullptr) return;

        if (node->isEnd) {
            result.push_back(prefix);
        }

        // Iterate over all children of the current node
        for (int i = 0; i < 26; ++i) {
            if (node->children[i] != nullptr) {
                prefix.push_back('a' + i);  // Add character corresponding to the child
                findWordsWithPrefix(node->children[i], prefix, result);
                prefix.pop_back();  // Backtrack
            }
        }
    }

    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        // Insert all contacts into the Trie
        for (int i = 0; i < n; ++i) {
            insert(contact[i]);
        }

        vector<vector<string>> result;
        string prefix = "";

        // For each character in the input string s
        for (int i = 0; i < s.size(); ++i) {
            prefix += s[i];  // Build the prefix one character at a time
            vector<string> words;

            // If there are contacts starting with the prefix, find them
            TrieNode* curr=prefixstr(prefix);
            if (curr) {
                findWordsWithPrefix(curr, prefix, words);  // Custom function to find contacts with this prefix
            }

            // If no words are found for the current prefix, add "0"
            if (words.empty()) {
                result.push_back({"0"});
            } else {
                result.push_back(words);
            }
        }

        return result;
    }
};
