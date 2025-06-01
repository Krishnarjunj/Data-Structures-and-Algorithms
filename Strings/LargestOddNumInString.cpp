class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int index = -1;
        for(int i = n-1 ; i >= 0 ; i --){
            if((num[i]-'0')%2 != 0 ){
                index = i;
                break;
            }
        }
        if(index!= -1) return num.substr(0,index+1);
        return "";
    }
};
