class Solution {
public:
    int rev =0;
    int reverse(int x) {
        while(x!=0){
            int ld = x%10;
            x=x/10;
        if(rev>INT_MAX/10||rev<INT_MIN/10)
            return 0;
        
        if(rev == INT_MAX && ld > 7)
            return 0;
        
        if(rev == INT_MIN && ld < -8)
            return 0;
        
        rev =(rev*10) + ld;
    }
  return rev;  
}
   
};