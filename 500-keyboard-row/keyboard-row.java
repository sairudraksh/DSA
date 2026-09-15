class Solution {
    public String[] findWords(String[] words) {
        HashMap<Character,Integer>map=new HashMap<>();

        map.put('q',1);
        map.put('Q',1);
        map.put('w',1);
        map.put('e',1);
        map.put('r',1);
        map.put('t',1);
        map.put('y',1);
        map.put('u',1);
        map.put('i',1);
        map.put('o',1);
        map.put('p',1);
    
        map.put('W',1);
        map.put('E',1);
        map.put('R',1);
        map.put('T',1);
        map.put('Y',1);
        map.put('U',1);
        map.put('I',1);
        map.put('O',1);
        map.put('P',1);

        map.put('A',2);
        map.put('S',2);
        map.put('D',2);
        map.put('F',2);
        map.put('G',2);
        map.put('H',2);
        map.put('J',2);
        map.put('K',2);
        map.put('L',2);
    
        map.put('a',2);
        map.put('s',2);
        map.put('d',2);
        map.put('f',2);
        map.put('g',2);
        map.put('h',2);
        map.put('j',2);
        map.put('k',2);
        map.put('l',2);

        map.put('Z',3);
        map.put('X',3);
        map.put('C',3);
        map.put('V',3);
        map.put('B',3);
        map.put('N',3);
        map.put('M',3);
    
        map.put('z',3);
        map.put('x',3);
        map.put('c',3);
        map.put('v',3);
        map.put('b',3);
        map.put('n',3);
        map.put('m',3);

        ArrayList<String>list=new ArrayList<>();

        for(int i=0;i<words.length;i++){
            String s=words[i];

            int curr=-1;
            boolean found=false;
            for(int j=0;j<s.length();j++){
                int num=map.get(s.charAt(j));

                if(curr==-1 || num==curr){
                    curr=num;
                }
                else{
                    found=true;
                    break;
                }
            }

            if(found==false) list.add(s);
            
        }
        int n=list.size();
        String[] ans=new String[n];

        for(int i=0;i<n;i++){
            ans[i]=list.get(i);
        }
        return ans;
    }
}