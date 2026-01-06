// Last updated: 1/6/2026, 10:01:36 PM
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {

        int n = garbage.size(); 
        int time = 0;

        int g_loc = 0;
        int p_loc = 0;
        int m_loc = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0;j<garbage[i].size(); j++){
                if(garbage[i][j] == 'G'){
                    if(i == 0) time += 1;
                    else{
                        time+=1;
                        for(int k = g_loc; k<i; k++){
                            time += (travel[k]);
                        }
                    }
                    g_loc = i; 
                }
                if(garbage[i][j] == 'M'){
                    if(i == 0) time += 1;
                    else{
                        time+=1;
                        for(int k = m_loc; k<i; k++){
                            time += (travel[k]);
                        }
                    }
                    m_loc = i; 
                }
                if(garbage[i][j] == 'P'){
                    if(i == 0) time += 1;
                    else{
                        time+=1;
                        for(int k = p_loc; k<i; k++){
                            time += (travel[k]);
                        }
                    }
                    p_loc = i; 
                }
            }
        }
        return time;
        
    }
};