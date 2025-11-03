class Solution {
public:
    class Node {
        public:
        Node* left; // 0
        Node* right; //1
    };

    void insert(Node* root, int num) {
        Node* crawl = root;
        for(int i= 31; i>= 0; i--) {
            int ithBit = (num>>i) & 1;

            if(ithBit == 1) {
                if(crawl->right== nullptr) crawl->right = new Node();
                crawl = crawl->right;
            }
            else{
                if(crawl->left== nullptr) crawl->left = new Node();
                crawl = crawl->left;
            }
        }
    }

    int maxXor(Node* root, int num) {
        Node* crawl = root;
        int ans = 0;
        for(int i= 31; i>= 0; i--) {
            int ithbit = (num>>i) & 1;

            if(ithbit == 1) {
                if(crawl->left) {
                    ans += pow(2,i);
                    crawl = crawl->left;
                }
                else {
                    crawl = crawl -> right;
                }
            }
            else {
                if(crawl->right) {
                    ans += pow(2,i);
                    crawl = crawl->right;
                }
                else {
                    crawl = crawl -> left;
                }
            }
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        Node* root = new Node();
        for(int i:  nums) {
            insert(root,i);
        }
        int ans = 0;
        for(int i: nums) {
            int mx = maxXor(root,i);
            ans = max(ans,mx);
        }
        return ans;
    }
};
