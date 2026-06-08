class Solution {
public:
    int n;
    TreeNode* find(unordered_map<int,pair<int,int>>&map,int currRoot){
        TreeNode* t=new TreeNode(currRoot);
        if(map.find(currRoot)==map.end()) return t;


        t->left=NULL;
        t->right=NULL;

        int leftt=map[currRoot].first;
        int rightt=map[currRoot].second;

        if(leftt!=-1){
            t->left=find(map,leftt);
        } 
        if(rightt!=-1){
            t->right=find(map,rightt);
        }

        return t;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& nums) {
        n=nums.size();
        unordered_map<int,int>map1;
        unordered_map<int,int>map3;
        unordered_map<int,pair<int,int>>map2;

        for(int i=0;i<n;i++){
            map1[nums[i][1]]++;
            
            if(nums[i][2]==0){
                map2[nums[i][0]].second=nums[i][1];
                if(map3.find(nums[i][0])==map3.end()) map2[nums[i][0]].first=-1;
            }
            else{
                map2[nums[i][0]].first=nums[i][1];
               if(map3.find(nums[i][0])==map3.end()) map2[nums[i][0]].second=-1;
            }
            map3[nums[i][0]]++;
        }
        int ans=-1;

        for(int i=0;i<n;i++){
            if(map1.find(nums[i][0])==map1.end()){
                ans=nums[i][0];
                break;
            }
        }

        return find(map2,ans);

    }
};