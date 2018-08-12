class Solution {
public:
    int majorityElement(vector<int> &num) {
        int length = num.size();
        //start ,end将整个数列不断的分段
        int start = 0;
        int end = length - 1;
        int index = IndexInArray(start, end, num);
        while(index != (length >> 1)){
            if (index < (length >> 1)){
                start = index + 1;                  //二分法 start
                index = IndexInArray(start, end, num);
            }else{
                end = index - 1;                    // 二分法 end
                index = IndexInArray(start, end, num);
            }
        }
        
        return num[index];
    }
    
    int IndexInArray(int head, int tail, vector<int> &num){
        int small = head - 1;
        int i;
        for (i = head; i < tail; i++){
            if (num[i] < num[tail]){ //小于不能有等于
                small++;
                swap(&num[small], &num[i]);
            }
        }
        
        small++;
        swap(&num[small], &num[tail]);
        return small;
    }
    
    void swap(int * a, int * b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    
};
