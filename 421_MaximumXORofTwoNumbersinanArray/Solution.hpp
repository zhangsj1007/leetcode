class Solution {
public:

    struct TreeNode{
        TreeNode* c[2];
        TreeNode(){
            c[0] = c[1] = NULL;
        }
    };
    
    TreeNode * root;

    void insert(TreeNode* &root, int num){
        if (!root)
            root = new TreeNode();
        TreeNode* p = root;
        for (int i = 31; i >= 0; i--){
            int d = ((num & (1 << i)) > 0);
            if (p->c[d] == NULL)
                p->c[d] = new TreeNode();
            p = p->c[d];
        }
    }

    int findMaximumXOR(vector<int>& nums) {
        root = NULL;
        for (auto n : nums)
            insert(root, n);
        int max_res = 0;
        for (auto n : nums){
            int value = 0;
            TreeNode* p = root;
            for(int i = 31; i >= 0; i--){
                int d = ((n & (1 << i)) > 0);
                if (p->c[1-d]){
                    p = p->c[1-d];
                    value |= (1 << i);
                }else{
                    p = p->c[d];
                }
            }
            max_res = max(max_res, value);
        }
        return max_res;
    }
};
