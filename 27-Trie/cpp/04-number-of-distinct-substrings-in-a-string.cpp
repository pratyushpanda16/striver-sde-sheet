#include <string>

using namespace std;

class Solution {
private:
    struct Node {
        Node* children[26] = {nullptr};
    };

public:
    int countDistinctSubstring(string s) {
        Node* root = new Node();
        int count = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            Node* curr = root;
            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                if (!curr->children[idx]) {
                    curr->children[idx] = new Node();
                    count++;
                }
                curr = curr->children[idx];
            }
        }

        return count + 1;
    }
};
