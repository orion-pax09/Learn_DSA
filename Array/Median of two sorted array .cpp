class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>merge;
        int low = 0;
        int high = 0;
        int size = nums1.size() + nums2.size();
        while (low < nums1.size() && high < nums2.size()){
            if (nums1[low] > nums2[high]){
                merge.push_back(nums2[high]);high++;
            }
            else if (nums1[low] < nums2[high]){
                merge.push_back(nums1[low]);
                low++;
            }
            else{
                merge.push_back(nums1[low]);
                merge.push_back(nums2[high]);
                high++;
                low++;
            }
        }
        while (low < nums1.size()){
            merge.push_back(nums1[low]);
            low++;
        }
        while(high < nums2.size()){
            merge.push_back(nums2[high]);
            high++;
        }
        double middle;
        if (merge.size()%2==0){
            middle = (merge[merge.size() / 2 - 1] + merge[merge.size()/2]) / 2.0;
        }
        else{
            middle = merge[merge.size() / 2];
        }
        return middle;
    }
};
