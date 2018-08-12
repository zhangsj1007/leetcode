/*
We are toggling the nth bulb that much number of times as much there are factors of it. Thus number i with even number of factors will be off and bulb at number j with odd number of factors will be on.
And only square numbers have odd number of factors. E.g 1(only 1), 4(1,2,4) ,  9(1,3,9), 16(1,2,4,8,16)...and so on...thus we have to find number of perfect squares within n which can be simply reduced to square root of n.自己的做法超时
*/
class Solution {
public:
    int bulbSwitch(int n) {
        /*bitset<n> bs;
        //auto bs = new bitset;
        bitset
        bs.set();
        for (int i = 1; i < n; i++){
            bulbSet(bs, i+1);
        }
        return bs.count();*/
        /*auto p = new vector<bool>(n, true);
        int count = 0;
        for (int i= 1; i < n; i++){
            bulbSet(p, n, i+1);
        }
        for (int i = 0; i < n; i++){
            if ((*p)[i])
                count++;
        }
        return count;*/
        int i;
        for(i=1; i*i<=n; i++);
        return i-1;
    }
   /* template<size_t n>
    void bulbSet(bitset<n>* bs, int count){
        for (int i = 1; i < n; i++){
            if ((i + 1) % count == 0){
                bs.flip(i);
            }
        }
    }*/
    void bulbSet(vector<bool> *p, int n, int count){
        for (int i = 1; i < n; i++){
            if ((i+1) % count == 0){
                (*p)[i] = (*p)[i] ? false : true;
            }
        }
    }
};
