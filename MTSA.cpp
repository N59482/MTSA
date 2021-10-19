class Solution {
public:
    double DifSize(vector<int> nums1, vector<int> nums2, int iM)
        {
            int res = 0;
            while(!nums2.empty() && (iM + 1))
                {
                    if(nums1.at(0) < nums2.at(0))
                        {
                            res = nums1.at(0);
                            nums1.erase(nums1.begin());
                        }
                        else 
                            {
                                res = nums2.at(0);
                                nums2.erase(nums2.begin());
                            }
                    iM--; 
                }
                if(iM + 1) res = nums1.at(iM);
            return double(res);
        }
    double OneSize(vector<int> nums1, vector<int> nums2, int iM)
        {
            int res = 0;
            while(!nums1.empty() && !nums2.empty() && (iM + 1))
                {
                    if(nums1.at(0) < nums2.at(0))
                        {
                            res = nums1.at(0);
                            nums1.erase(nums1.begin());
                        }
                        else 
                            {
                                res = nums2.at(0);
                                nums2.erase(nums2.begin());
                            }
                    iM--; 
                }
                if(iM + 1) 
                    {
                        if (nums1.empty()) res = nums2.at(iM);
                        else res = nums1.at(iM);
                    };
            return double(res);
        }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int totalnumsize =  nums1.size() + nums2.size(); // ОПТИМИЗАЦИЯ убрать
        int iMedian = ( (nums1.size() + nums2.size()) / 2);
        if((nums1.size() + nums2.size()) % 2 != 0) // Если общее количество элементов нечётное 
            {   // Один ответ
                if(nums1.size() < nums2.size()) return findMedianSortedArrays(nums2, nums1); // сортируем очерёдность списков если они разных размеров.
                if(nums2.size() == 0) return double(nums1.at(iMedian)); // решение если один из списков пуст.
                else return DifSize(nums1,nums2,(iMedian)); // решение на все остальные случаи
            }
            else // два ответа
                {
                    if (nums1.size() != nums2.size()) // если списки разных размеров
                        {
                            if(nums1.size() < nums2.size()) {cout<<"reverse"<<endl; return findMedianSortedArrays(nums2, nums1);} // сортируем списки.
                            if(nums2.size() == 0) return double(nums1.at(iMedian - 1) + nums1.at(iMedian)) / 2.0; // решение если один из списков пуст.
                            else return ((DifSize(nums1,nums2,(iMedian)) + DifSize(nums1,nums2,(iMedian - 1)))/2.0); // решение на все остальные случаи
                        }
                        else return ((OneSize(nums1,nums2,(iMedian)) + OneSize(nums1,nums2,(iMedian-1)))/2.0); // решение если списки одинаковых размеров.
                };
    };
};