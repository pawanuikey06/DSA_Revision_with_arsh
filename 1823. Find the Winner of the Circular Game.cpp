class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner =0;
        for(int i=1;i<=n;i++){
            winner =(winner+k)%i;
        }
        return  winner+1;
    }
};

// Using Queues


class Solution {
public:
    int findTheWinner(int n, int k) {
      if(k==1) return n;
        
      queue<int> que;
      for(int i=1;i<=n;i++) que.push(i);
        
      while(que.size()!=1)
      {
          int repeat=k-1;
          while(repeat)
          {
              que.push(que.front());
              que.pop();
              repeat--;
          }
          que.pop();
      }
        
        return que.front();
    }
};
