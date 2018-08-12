/*
* Algorithm ： Using list is for the fast inserting operation.
*/


class Solution {
public:
    string addStrings(string num1, string num2) {
        carry = false;
        int len1 = num1.length();
        int len2 = num2.length();
        list<char> result;
        int i, j;
        
        for (i = len1-1, j = len2-1; (i>=0) && (j>=0); i--,j--){
            result.push_front(addChar(num1[i], num2[j]));
        }
        
         if (i < 0){
            //why do this? for the case of 9999999....., the carry is true all the time.
            while (j >= 0){
                result.push_front(addChar(num2[j--], '0'));
            }
        }else if (j < 0){
            while (i >= 0){
                result.push_front(addChar(num1[i--], '0'));
            }
        }
        
        if (carry) result.push_front('1');
        return string(result.begin(), result.end());
    }
    
private:
    char addChar(char c1, char c2){
        int i1 = c1 - '0';
        int i2 = c2 - '0';
        int i = i1 + i2 + (int)carry;
        if (i >= 10){
            carry = true;
            return (char)(i - 10) + '0';
        }else{
            carry = false;
            return (char)(i) + '0';
        }
    }

    bool carry;
};
