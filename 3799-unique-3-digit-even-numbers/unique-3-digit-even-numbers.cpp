class Solution {
public:
    vector<int>visited;
    int find(vector<int>& digits,int sum,unordered_map<int,int>&map,int num){
        if(num==3){
            if(map.find(sum)==map.end() && sum%2==0){
                map[sum]++;
                return 1;
            }
            return 0;
        }
        int count=0;
        for(int i=0;i<digits.size();i++){
            if(visited[i]==0){
                if(sum==0 && digits[i]==0) continue;
                int newsum=sum*10+digits[i];
                visited[i]=1;
                count+=find(digits,newsum,map,num+1);
                visited[i]=0;
            }
        }
        return count;
    }
    int totalNumbers(vector<int>& digits) {
        unordered_map<int,int>map;
        int n=digits.size();
        visited.resize(n+1,0);
        return find(digits,0,map,0);
    }
};