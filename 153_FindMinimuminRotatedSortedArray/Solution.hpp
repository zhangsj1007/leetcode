class Solution {
public:
    int findMin(vector<int> &num) {
        int index1 = 0;
        int index2 = num.size() - 1;
        int index;
        
        if (num[index1] < num[index2]){
            return num[index1];
        }
        
        while (index2 - index1 > 1){
            index = index1 + ((index2 - index1) >> 1); //寻找中间值
            if (num[index] > num[index1]){
                index1 = index;
            }else if (num[index] < num[index2]){
                index2 = index;
            }
        } 
        return num[index2];
    }
};
