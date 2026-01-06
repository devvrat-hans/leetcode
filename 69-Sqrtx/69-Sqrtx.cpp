// Last updated: 1/6/2026, 10:03:11 PM
// class Solution {
// public:
//     int mySqrt(int x) {
//         int res;

//         for(long i = 1; i<=x/2+1; i++){
//             if (i*i == x){
//                 res = i;
//                 break;
//             }
//             if (i*i>x){
//                res = i-1; 
//                break;
//             }
//         }
//         return res;    
//     }
// };

class Solution {
public:
    int mySqrt(int x) {
        int res =0  ;
        int l = 1 , r = x/2 ;
        if(x<2)return x ;
        while(l<=r){
            int mid = l + (r-l)/2 ;
            long long sqr =(long long) mid*mid ;
            if(sqr == x){
                return mid ;
            }else if(sqr>x){
                r = mid-1;
            }else{
                l = mid+1;
                res = mid ;
            }
        }
        
        return res;
    }
};