public class TanyaJain_SquareRoot {
    long floorSqrt(long n) {
        // Your code here
        long ans = 1;
        long start = 1;
        long end = n;
        while(start <= end){
            long mid = start + (end - start)/2;
            if(mid * mid == n){
                ans = mid;
                break;
            }
            else if(mid * mid < n){
                ans = mid;
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return ans;
    }
}
