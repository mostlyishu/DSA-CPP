class Solution {
public:
    double myPow(double x, int n) {
        long long power = n; // for safe INT_MIN coversion to INT_MAX when -ve ... without going overflow
        long double base = x; // to match leetcode precision
        if (power < 0){ // agar power negative h toh base ko reciprocate krdo and power ko positive krdo
            base = 1.0L/base; // // reciproc al of base
            power = -power; // now power become positive
        }

        long double ans = 1.0; // to store large ans 

        while (power>0){ // jab tk power 0  se bdi rehti h 
            if (power % 2 == 1){ //When the exponent is odd, we extract one factor of the current base and multiply it into ans.
                ans = ans * base; 
            }

            base=base*base; // base ko sqaure krte jao and power ko half krte jao
            power = power/2;
        }
      // basically it works like : (6)^10 = (6^2)^5 
        return (double)ans;
    }
};