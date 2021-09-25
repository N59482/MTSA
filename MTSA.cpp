class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int imedian = nums1.size() + nums2.size() / 2;
        if (((nums1.size() + nums2.size()) % 2) != 0)
            {
                int n1 = 0;
                int n2 = 0;
                int median = 0;
                while (MainVec.size() != imedian)
                {
                    if (nums1.at(n1) < nums2.at(n2)) 
                    {
                        MainVec.push_back(nums1.at(n1));
                        n1++;
                    } else 
                        {
                            MainVec.push_back(nums2.at(n2));
                            n2++;
                        };
                }
            }
        else
            {
                imedian++;
            };
        
    }
};