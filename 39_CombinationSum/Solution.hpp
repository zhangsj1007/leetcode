/*
算法：回溯算法
*/

class Solution {
private:
    vector<vector<int> > vV;
    vector<int> v;
    vector<int> _candidates;
    int _target;
    bool isContinue(int a) {
        int sum = 0;
        for(int i = 0; i < v.size(); i++)
            sum += v[i];
        return (sum + a > _target) ? false : true;
    }
    void calculate(){
        int sum = 0;
        for (int i = 0; i < v.size(); i++)
            sum += v[i];
        if (sum == _target){
            vV.push_back(v);
        }else{
            for (int i = 0; i < _candidates.size(); i++){
                //元素递增，防止重复
                if (!v.empty() && _candidates[i] < v.back()){
                    continue;
                }
                if (isContinue(_candidates[i])){
                    v.push_back(_candidates[i]);
                    calculate();
                    v.pop_back();
                }
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        _target = target;
        _candidates = candidates;
        calculate();
        return vV;
    }
};
