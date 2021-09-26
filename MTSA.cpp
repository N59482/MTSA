class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int imedian = nums1.size() + nums2.size();//будет ли медиана числом одного из массивов (если конечный массив будет содержать нечетное кол-во элементов) или же нужно будет высчитывать его?(если конечный массив будет содержать ЧЕТНОЕ кол-во элементов) 
        int n1 = 0;
        int n2 = 0;
        int res = 0;

        if ((imedian % 2) != 0)// проверка на чётность
            {// если это конечный массив будет содержать нечетное кол-во элементов
                ++imedian /= 2;
                for(int i = 0; i != imedian; i++)
                {
                    if (nums1.at(n1) < nums2.at(n2)) 
                    {
                        res = nums1.at(n1);
                        n1++;
                    } else 
                        {
                            res = nums2.at(n2);
                            n2++;
                        };
                }
            }
        else
            {//если конечный массив будет содержать ЧЕТНОЕ кол-во элементов
                vector<int> MainVec {};
                ++imedian /= 2;
                while (MainVec.size() != imedian) // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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
                res = double((MainVec.back() + MainVec.at(imedian - 1)) / 2); // не считает в double
            };
        return double(res);
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int median = ( ( nums1.size() + nums2.size() ) / 2) + 1; 
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