class Solution {
public:
    string addBinary(string a, string b) {
        string sum;
        char temp = '0';
        char takeover = '0';
        
        //为方便起见，对于不同长度的字符串末尾补齐
        if (a.size() > b.size()){
            for (int i = b.size(); i < a.size(); i++){
                b.insert(b.begin(), temp);//对于此版c++，只支持迭代器，不支持位置pos
            }
        }
        if (b.size() > a.size()){
            for (int i = a.size(); i < b.size(); i++){
                a.insert(a.begin(), temp);
            }
        }
        
        
        //注意字符串计算要从尾部开始算起
        for (int i = a.size() - 1; i >= 0; i--){
            temp = a[i] + b[i] + takeover - 2 * '0';
            switch (temp){ //switch语句需要1.大括号。2.break。3.default
            case '0': 
               sum.insert(sum.begin(), '0');
               takeover = '0';
                break;
            
            case '1': 
               sum.insert(sum.begin(), '1');
               takeover = '0';
               break;
            
            case '2': 
                sum.insert(sum.begin(), '0');
                takeover = '1';
                break;
                
            case '3':
                sum.insert(sum.begin(), '1');
                takeover = '1';
                break;
            
            default:{
                exit(1);
            }
            
            }
        }
        
        //查看最后一位计算若有进位，则sum需要加一个‘1’
        if (takeover == '1'){
                sum.insert(sum.begin(), '1');
        }
        
        return sum;
    }
};
