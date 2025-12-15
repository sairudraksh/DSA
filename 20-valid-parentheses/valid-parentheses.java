class Solution {
    public boolean isValid(String s) {
        int n=s.length();
        Stack<Character>st=new Stack<>();
        for(int i=0;i<n;i++){
            char ch=s.charAt(i);
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }
            else{
                if(st.isEmpty()) return false;
                char ch1=st.pop();
                if(ch1=='(' && ch!=')') return false;
                else if(ch1=='{' && ch!='}') return false;
                else if(ch1=='[' && ch!=']') return false;
            }
        }
        if(st.size()==0) return true;
        return false;
    }
}