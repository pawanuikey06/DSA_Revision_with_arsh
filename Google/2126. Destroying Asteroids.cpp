class Solution {
public:
     int mod=1e5;
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        if(mass<asteroids[0]) return false;
        long long masss=mass;
        for(int i=0;i<asteroids.size();i++){
            if(masss>=asteroids[i]){
                masss+=asteroids[i];
                ;
            }
            if(masss<asteroids[i] ) return false;
        }
        return true;

    }
};
// 2nd Approach

class Solution {
public:
     
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        priority_queue<int,vector<int>,greater<int>>pq(asteroids.begin(),asteroids.end());
        long long masss=mass;
        while(!pq.empty()){
            int ast =pq.top();pq.pop();
            if(ast>masss) return false;
            masss+=ast;
        }

        return true;

    }
};
