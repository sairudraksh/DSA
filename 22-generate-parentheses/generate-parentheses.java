class Solution {
    void find(int n, ArrayList<String>ans,int close,int open,String s){
        if(s.length()==n*2){
            if(open==close){
                ans.add(s);
            }
            return;
        }
        if(open>close){
            find(n,ans,close+1,open,s+')');
            find(n,ans,close,open+1,s+'(');
        }
        else{
            find(n,ans,close,open+1,s+'(');
        }
    }
    public List<String> generateParenthesis(int n) {
        ArrayList<String>arr=new ArrayList<>();
        find(n,arr,0,0,"");
        return arr;
    }
}