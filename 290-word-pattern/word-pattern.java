class Solution {
    public boolean wordPattern(String pattern, String s) {
        HashMap<String,ArrayList<Integer>>map1=new HashMap<>();
        HashMap<Character,ArrayList<Integer>>map2=new HashMap<>();
        int n=pattern.length();
        int m=s.length();
        for(int i=0;i<n;i++){
            map2.computeIfAbsent(pattern.charAt(i),k->new ArrayList<>()).add(i);
        }
        int j=0;
        int count=0;
        ArrayList<String>list=new ArrayList<>();
        while(j<m){
            String str="";
            count++;
            while(j<m && s.charAt(j)!=' '){
                str+=s.charAt(j);
                j++;
            }
            j++;
            list.add(str);
            int num=count-1;
            map1.computeIfAbsent(str,k->new ArrayList<>()).add(num);
        }

        if(pattern.length()!=count) return false;

        for(int l=0;l<count;l++){
            ArrayList<Integer>list1=map2.get(pattern.charAt(l));
            ArrayList<Integer>list2=map1.get(list.get(l));

            if(list1.equals(list2)){
                continue;
            }
            else return false;
        }
        return true;
    }
}