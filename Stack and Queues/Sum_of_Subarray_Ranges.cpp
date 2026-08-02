class Solution {
public:
vector<int>PLE(vector<int>&arr){
    stack<int>st;
    vector<int>ans(arr.size(),-1);
    for(int i = 0 ; i < arr.size() ; i++){
        while(!st.empty()&&arr[st.top()] > arr[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}
vector<int>NLE(vector<int>&arr){
    stack<int>st;
    vector<int>ans(arr.size(),-1);
    for(int i = arr.size()-1 ; i >= 0 ; i--){
        while(!st.empty()&&arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}vector<int>NGE(vector<int>arr){
    stack<int>st;
    vector<int>ans(arr.size() , -1);
    for(int i = arr.size()-1 ; i>=0 ; i--){
        while(!st.empty()&&arr[st.top()] < arr[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}
vector<int>PGE(vector<int>&arr){
    stack<int>st;
    vector<int>ans(arr.size() , -1);
    for(int i = 0 ; i < arr.size() ; i++){
        while(!st.empty()&&arr[i] >= arr[st.top()]){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}
long long Sunofminimumsubarray(vector<int>&arr){
    long long total = 0;
    vector<int>ple = PLE(arr);
    vector<int>nle = NLE(arr);
    for(int i = 0 ; i < arr.size() ; i++){
        int right;
        if(nle[i]==-1){
            right = arr.size()-i;
        }
        else{
            right = nle[i] - i;
        }
        int left = i - ple[i];
        total = total + (1LL*left*right*arr[i]);
    }
    return total;
}
long long SumofMaximumsubarray(vector<int>&arr){
    const int mod = 1e9+7;
    long long total = 0;
    vector<int>pge = PGE(arr);
    vector<int>nge = NGE(arr);
    for(int i = 0 ; i < arr.size() ; i++){
        int right;
        if(nge[i]==-1){
            right = arr.size()-i;
        }
        else{
            right = nge[i] - i;
        }
        int left = i - pge[i];
        total = total + (1LL*left*right*arr[i]);
    }
    return total;
}
    long long subArrayRanges(vector<int>& nums) {
        return SumofMaximumsubarray(nums) - Sunofminimumsubarray(nums);   
    }
};
