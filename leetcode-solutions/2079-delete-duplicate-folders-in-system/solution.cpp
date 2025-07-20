class Solution {
public:
    struct Node {
        unordered_map<string, Node*> children;
        bool toDelete = false;
    };
     unordered_map<string, vector<Node*>> serialMap;

    // Step 1: Serialize subtree structure
    string serialize(Node* node) {
        if (node->children.empty()) return "";
        vector<pair<string, string>> serializedChildren;
        for (auto& [name, child] : node->children) {
            serializedChildren.emplace_back(name, serialize(child));
        }
        sort(serializedChildren.begin(), serializedChildren.end());

        string serial;
        for (auto& [name, sub] : serializedChildren) {
            serial += name + "(" + sub + ")";
        }

        serialMap[serial].push_back(node);
        return serial;
    }

    // Step 2: Collect remaining paths after deletion
    void collect(Node* node, vector<string>& path, vector<vector<string>>& result) {
        for (auto& [name, child] : node->children) {
            if (child->toDelete) continue;
            path.push_back(name);
            result.push_back(path);
            collect(child, path, result);
            path.pop_back();
        }
    }
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = new Node();

        // Step 0: Build the Trie
        for (auto& path : paths) {
            Node* curr = root;
            for (string& folder : path) {
                if (!curr->children.count(folder)) {
                    curr->children[folder] = new Node();
                }
                curr = curr->children[folder];
            }
        }

        // Step 1: Serialize
        serialize(root);

        // Step 2: Mark duplicates
        for (auto& [_, nodes] : serialMap) {
            if (nodes.size() > 1) {
                for (auto node : nodes) node->toDelete = true;
            }
        }

        // Step 3: Collect valid paths
        vector<vector<string>> result;
        vector<string> currPath;
        collect(root, currPath, result);
        return result;
    }
};
