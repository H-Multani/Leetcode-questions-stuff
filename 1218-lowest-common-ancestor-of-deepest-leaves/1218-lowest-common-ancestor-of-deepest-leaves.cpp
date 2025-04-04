/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> forp;
    vector<TreeNode*> forq;
    void traverse(TreeNode* root, TreeNode* p, TreeNode* q,
                  vector<TreeNode*> &curr) {
        if (root == nullptr)
            return;

        // current node agar p ya q ke barabar aa jaaye toh means p and q ka
        // path nikal gaya hai, update kar do bs
        if (root == p) {
            curr.push_back(root);
            vector<TreeNode*> ans=curr;
            forp = ans;
            curr.pop_back();
        }
        if (root == q) {
            curr.push_back(root);
            vector<TreeNode*> ans=curr;
            forq = ans;
            curr.pop_back();
        }

        // current node path me add karo
        curr.push_back(root);
        // aage badho
        // to left
        traverse(root->left, p, q, curr);
        // to right
        traverse(root->right, p, q, curr);
        // ab jo element add kiya tha usko remove kar do, so that ye current banda apne path me aage problem na kare
        curr.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        forq.resize(0);
        forp.resize(0);
        vector<TreeNode*> curr;
        traverse(root, p, q, curr);

        for (auto it : forp) {
            cout << it->val << " ";
        }
        cout << endl;
        for (auto it : forq) {
            cout << it->val << " ";
        }
        cout << endl;

        for (int i = 0; i < min(forp.size(), forq.size()); i++) {
            if (forp[i]->val != forq[i]->val) {
                // means yaha tak path common tha, i-1 th wala common ancestor
                // ho gaya p and q ka
                // return i-1 th node, since that is the last common ancestor
                return forp[i - 1];
            }
        }

        // yaha pahuche means, p and q ka common ancestor passes through p or q,
        // eg 2 dekh lo
        // in such case, return forp(or forq) ka last element(dono me se jo bhi
        // pehle khatam hoga )

        return forp[min(forp.size(),forq.size())-1];
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        // bfs chala kar saare levels nikal lo, store karlo levels

        // phir unn levels me se sabse lowest levels waale nodes nikalo,agar 1
        // node hi hai toh vahi return kardena, agar 2 hai toh LCA nikal kar bhj
        // dena dono ka

        // base case, agar root ke left and rt me kch nai h toh return root
        if(root==nullptr) return nullptr;
        if(root->left==nullptr && root->right==nullptr) return root; 

        queue<TreeNode*> q;

        q.push(root);
        
        // map me store karlo node and depth
        unordered_map<TreeNode*,int> mpp;

        int depth=0;

        while(!q.empty()){
            // current n bande at current depth
            int n=q.size();

            for(int i=0;i<n;i++){
                mpp[q.front()]=depth;

                auto curr=q.front();
                q.pop();

                // agar left and right me nodes hai toh explore karlo
                if(curr->left!=nullptr) q.push(curr->left);
                if(curr->right!=nullptr) q.push(curr->right);
            }

            depth++;
        }

        depth--;
        // iss depth par baithe bande count karne h

        int cnt=0;

        // set me daal do last level waale nodes
        unordered_set<TreeNode*> nds;
        // unordered so that O(1) search

        for(auto it:mpp){
            // cout<<it.first->val<<" "<<it.second<<endl;
            if(it.second==depth){
                nds.insert(it.first);
                cnt++;
            }
        }
        // cout<<depth<<endl;

        if(nds.size()==1){
            return *nds.begin();
        }

        // we here means last lvl par 2 se zyada nodes hai 
        // unka common ancestor bana do and return krdo

        q.push(root);

        TreeNode* ans=nullptr;

        // leaf nodes par iterate karo phir ab, har 2 nodes utha kar 
        
        // for(int i=0;i<nds.size();i++){
        //     for(int j=0;j<nds.size();j++){
        //         if(i!=j){
        //             // lca chalao and lagao
        //         }
        //     }
        // }

        for(auto it1:nds){
            for(auto it2:nds){
                if(it1!=it2){
                    TreeNode* lca=lowestCommonAncestor(root,it1,it2);

                    // ab agar current lca ka depth kam hai toh update kardo
                    if(mpp[lca]<mpp[ans] || ans==nullptr)
                        ans=lca;
                }
            }
        }



        return ans;
        
    }
};