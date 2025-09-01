/**
 * @param {string} s
 * @return {string}
 */
var reverseVowels = function(s) {
    let ans="";
    let n=s.length;
    for(let i=0;i<n;i++){
        if(s[i]=="a" ||s[i]=="e" ||s[i]=="i" ||s[i]=="o" ||s[i]=="u" || s[i]=="A" ||s[i]=="E" ||s[i]=="I" ||s[i]=="O" ||s[i]=="U"){
            ans+=s[i];
        }
    }
    let ans2="";
    let k=ans.length-1;
    for(let i=0;i<n;i++){
        if(s[i]=="a" ||s[i]=="e" ||s[i]=="i" ||s[i]=="o" ||s[i]=="u" || s[i]=="A" ||s[i]=="E" ||s[i]=="I" ||s[i]=="O" ||s[i]=="U"){
            ans2+=ans[k];
            k--;
        }
        else ans2+=s[i];
    }
    return ans2;
};