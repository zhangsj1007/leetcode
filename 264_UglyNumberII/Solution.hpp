class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v;
        v.reserve(2000);
        int t = 1;
        int index[3] = {0, 0 ,0};
        int uglyPro[3] = {2, 3, 5};
        int pro[3] = {2, 3, 5};
        v.push_back(1);
        int i = 1;
        int j;
        while(i < n){
            for (j = 0; j < 3; j++){
                while(t >= uglyPro[j])
                    uglyPro[j] = v[++index[j]] * pro[j]; 
            }
            t = min(uglyPro, sizeof(uglyPro) / sizeof(*uglyPro));
            /*t = uglyPro[0];
            for (j = 1; j < 3; j++)
                if(t > uglyPro[j])
                    t = uglyPro[j];*/
            v.push_back(t);
            i++;
        }
        return v.back();
    }
    
    int min(int * a, int n){
        int min = a[0];
        for(int i = 1; i < n ; i++)
            if(a[i] < min)
                min = a[i];
        return min;          
    }
};
