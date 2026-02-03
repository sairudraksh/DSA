/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findSwaps(vector<int>&nums){
        int swaps=0;
        for(int i=0;i<nums.size();i++){ 
            int minidx=i; 
            for(int j=i+1;j<nums.size();j++){ 
                if(nums[j]<nums[minidx]){ 
                    minidx=j; 
                } 
            } 
            if(minidx!=i){ 
                int temp=nums[minidx]; 
                nums[minidx]=nums[i]; 
                nums[i]=temp; 
                swaps++; 
            }
        }
        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;

        q.push(root);

        int total=0;

        while(q.size()>0){
            
            int size=q.size();
            vector<int>v;
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                v.push_back(temp->val);


                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            total+=findSwaps(v);
        }
        return total;
    }
};