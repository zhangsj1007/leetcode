/*class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        string::size_type pos1;
        string::size_type pos2;
        pos1 = version1.find(".");
        pos2 = version2.find(".");
        string head1;
        string tail1;
        string head2;
        string tail2;
        
        
        if (pos1 != string::npos){
			head1.assign(version1, 0, pos1);
			tail1.assign(version1, pos1 + 1, version1.length() - pos1 - 1);
        }
        
        if (pos2 != string::npos){
			head2.assign(version2, 0, pos2);
			tail2.assign(version2, pos2 + 1, version2.length() - pos2 - 1);
        }
        
        
        if (pos1 == string::npos && pos2 == string::npos){
            if (atoi(version1) > atoi(version2)){
                return 1;
            }else if (atoi(version1) < atoi(version2)){
                return -1;
            }else{
                return 0;
            }
        }
        
        if (pos1 == string::npos && pos2 != string::npos){
            if (atoi(version1) > atoi(head2)){
                return 1;
            }else{
                if (atoi(tail2) == 0){
                    return 0;
                }
                return -1;
            }
        }
        
        if (pos1 != string::npos && pos2 == string::npos){
            if (atoi(version2) > atoi(head1)){
                return -1;
            }else{
                if (atoi(tail1) == 0){
                    return 0;
                }
                return 1;
            }
        }
        
        if (atoi(head1) > atoi(head2)){
            return 1;
        }else if (atoi(head1) < atoi(head2)){
            return -1;
        }else{
            if (atoi(tail1) > atoi(tail2)){
                return 1;
            }else if(atoi(tail1) < atoi(tail2)){
                return -1;
            }else{
                return 0;
            }
        }
    }
    
    int atoi(string s){
	    int result = 0;
    	for (int i = 0; i < s.length(); i++){
	    	result *= 10;
	    	result += s[i] - '0';
    	}
    	return result;
    }
}*/
class Solution {
public:
    int compareVersion(string version1, string version2){
        vector<int> v1;
        vector<int> v2;
        int temp = 0;
        
        for(int i = 0; i < version1.length(); i++){
            if (version1[i] == '.'){
                v1.push_back(temp);
                temp = 0;
                continue;
            }
            temp *= 10;
            temp += version1[i] - '0';
        }
        v1.push_back(temp);
        
        temp = 0;
        
        for(int i = 0; i < version2.length(); i++){
            if (version2[i] == '.'){
                v2.push_back(temp);
                temp = 0;
                continue;
            }
            temp *= 10;
            temp += version2[i] - '0';
        }
        v2.push_back(temp);
        
        if (v1.size() < v2.size()){
            for (int i = 0; i < v2.size() - v1.size(); i++){
                v1.push_back(0);
            }
        }
        
        if (v1.size() > v2.size()){
            for (int i = 0; i < v1.size() - v2.size(); i++){
                v2.push_back(0);
            }
        }
        
        for (int i = 0; i < v1.size(); i++){
            if (v1[i] > v2[i]){
                return 1;
            }else if (v1[i] < v2[i]){
                return -1;
            }
        }
        return 0;
    }
    
};
