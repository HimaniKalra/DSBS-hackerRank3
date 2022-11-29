#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory>
#include <unordered_map>

using namespace std;

class Trie
{
    public:
        bool insert(const string& s)
        {
            bool prefixFound = false;
            Node* node = &root;
            for (char c : s)
            {
                auto found = node->children.find(c);
                if (found == node->children.end())
                {
                    if (node->isWord) {
                        prefixFound = true;
                    }
                    Node* newNode = new Node();

                    node->children[c] = unique_ptr<Node>(newNode);
                    node = newNode;
                }
                else
                {
                    node = found->second.get();
                }
            }
            if (node->isWord) {
                prefixFound = true;
            }
            node->isWord = true;
            return prefixFound || node->children.size() > 0;
        }

    private:
        struct Node
        {
            bool isWord = false;
            unordered_map<char, unique_ptr<Node> > children;
        };

        Node root;
};



int main() {
    int n;
    cin >> n;
    
    Trie trie;
    string s;
    while (n--) {
        cin >> s;
        if (trie.insert(s)) {
            cout << "BAD SET" << endl;
            cout << s << endl;
            return 0;
        }
    }
    cout << "GOOD SET" << endl;
    return 0;
}
