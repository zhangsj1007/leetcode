class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        int a[] = {1, 2, 4, 8};
        int b_[] = {1, 2, 4, 8, 16, 32};
        vector<int> t(a, a+4);
        vector<int> b(b_, b_+6);
        vector<string> ret;
        if (num == 0){
            ret.push_back("0:00");
            return ret;
        }
        int top = 0;
        if (num >= 4)
            top = 4;
        else
            top = num;
        for (int s = 0; s <= top; s++){
            if (num - s > 6)
                continue;
            if (s == 0){
                vector<vector<int> >bottomComb = computeComb(b, num);
                for (int i = 0; i < bottomComb.size(); i++){
                    int sum = accumulate(bottomComb[i].begin(), bottomComb[i].end(), 0);
                    if (sum > 59)
                        continue;
                    stringstream ss;
                    if (sum < 10){
                        ss << "0";
                        ss << sum;
                    }else{
                        ss << sum;
                    }
                    string s = "0:";
                    s += ss.str();
                    ret.push_back(s);
                }
            } else if(num - s == 0){
                vector<vector<int> >topComb = computeComb(t, num);
                for (int i = 0; i < topComb.size(); i++){
                    int sum = accumulate(topComb[i].begin(), topComb[i].end(), 0);
                    if (sum > 11)
                        continue;
                    stringstream ss;
                    ss << sum;
                    string s = ":00";
                    s = ss.str() + s;
                    ret.push_back(s);
                }
            } else{
                vector<vector<int> >topComb = computeComb(t, s);
                vector<vector<int> >bottomComb = computeComb(b, num-s);
                for (int i = 0; i < topComb.size(); i++){
                    for (int j = 0; j < bottomComb.size(); j++){
                        int sumTop = accumulate(topComb[i].begin(), topComb[i].end(), 0);
                        int sumBottom = accumulate(bottomComb[j].begin(), bottomComb[j].end(), 0);
                        if (sumTop > 11) continue;
                        if (sumBottom > 59) continue;
                        stringstream ss1;
                        stringstream ss2;
                        if (sumBottom < 10){
                            ss1 << "0";
                            ss1 << sumBottom;
                        }else{
                            ss1 << sumBottom;
                        }
                        ss2 << sumTop;
                        string s;
                        s = ss2.str() + ":" + ss1.str();
                        ret.push_back(s);
                    }
                }
            }
        }
        return ret;
    }
private:
    vector<vector<int> >computeComb(vector<int> input, int n){
        vector<int> v;
        vector<vector<int> > ret;
        for (int i = 0; i < input.size(); i++){
            v.push_back(input[i]);
            helper(1, i+1, n, input, v, ret);
            v.pop_back();
        }
        return ret;
    }
    void helper(int m, int s, int n , vector<int>& input, vector<int>& v, vector<vector<int> >& ret){
        if (m == n){
            ret.push_back(v);
            return;
        }
        for (int i = s; i < input.size(); i++){
            v.push_back(input[i]);
            helper(m+1, i+1, n, input, v, ret);
            v.pop_back();
        }
    }
};
