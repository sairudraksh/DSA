class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long volume=1LL*length*width*height;
        bool bulky=false;
        string category="";
        if(volume>=1000000000 || length>=10000 || width>=10000 || height>=10000 || mass>=10000){
            bulky=true;
            category="Bulky";
        }

        bool heavy=false;

        if(mass>=100){
            heavy=true;
            category="Heavy";
        }

        if(bulky==true &&  heavy==true){
            category="Both";
        }

        if(bulky==false && heavy==false){
            category="Neither";
        }
        if(bulky==true && heavy==false){
            category="Bulky";
        }
        if(bulky==false && heavy==true){
            category="Heavy";
        }

        return category;
        
    }
};