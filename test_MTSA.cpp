#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int median = 2;
        int n1 = 0;
        int n2 = 0;
        vector<int> MainVec {};
        while (MainVec.size() != median)
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
        return double(MainVec.back());
    }
};

int main()
{
    Solution s;
    vector<int> tv1 {1,3,5};
    vector<int> tv2 {2,4};
    vector<int> tv3 {1,2,10};
    vector<int> tv4 {4,6};

    cout<<s.findMedianSortedArrays(tv1, tv2)<<endl;
    
    return 0;
}
