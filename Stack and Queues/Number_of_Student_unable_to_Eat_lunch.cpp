class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int>st;
        queue<int>q;
        for (int i = 0 ; i < students.size() ; i++){
            q.push(students[i]);
        }
        for (int i =sandwiches.size()-1 ; i >=0 ; i-- ){
            st.push(sandwiches[i]);
        }
        int rotation =0;
        while(!st.empty()&&!q.empty()){
            if (st.top()==q.front()){
                st.pop();
                q.pop();
                rotation = 0;
            }
            else{
                int temp = q.front();
                q.pop();
                q.push(temp);
                rotation++;
            }
            if (rotation == q.size()){
                break;
            }
        }
        return q.size();
    }
};
