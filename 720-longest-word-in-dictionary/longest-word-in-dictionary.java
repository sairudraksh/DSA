class Solution {
    public String longestWord(String[] words) {
        int n=words.length;

        HashSet<String>st=new HashSet<>();

        Arrays.sort(words);
        String ans="";
        for(int i=0;i<n;i++){
            String s=words[i];

            s=s.substring(0,words[i].length()-1);

            if(words[i].length()==1 || st.contains(s)){
                st.add(words[i]);

                if(s.length()+1>ans.length()){
                    ans=words[i];
                }
            }
        }
        return ans;
    }
}