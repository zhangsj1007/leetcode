/*
    算法：N!进行质因数分解 N! = (2^x) * (3^y) * (5^z)......显然ret = min(x,z)，又z一定大于x，所以 ret = z;
    又z = [N/5] + [N/5^2] + [N/5^3] .....（一直到k，当[N/5^k] == 0）所以有下面的解。
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while(n / 5){
            count += n / 5;
            n /= 5; 
        }
        return count;
    }
};
