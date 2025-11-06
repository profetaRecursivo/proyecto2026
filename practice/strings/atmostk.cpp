#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26] = {nullptr};
};

int main() {
    string s; cin >> s;
    string goodStr; cin >> goodStr;
    int k; cin >> k;

    vector<bool> isGood(26);
    for(int i = 0; i < 26; i++) isGood[i] = goodStr[i] == '1';

    TrieNode* root = new TrieNode();
    int count = 0;

    for(int i = 0; i < s.size(); i++) {
        TrieNode* node = root;
        int badCount = 0;
        for(int j = i; j < s.size(); j++) {
            if(!isGood[s[j]-'a']) badCount++;
            if(badCount > k) break;
            if(!node->children[s[j]-'a']) {
                node->children[s[j]-'a'] = new TrieNode();
                count++;
            }
            node = node->children[s[j]-'a'];
        }
    }
    cout << count << "\n";
}