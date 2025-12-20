#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n){
  // nums1 last index
  int last = m + n - 1;
  int size = last;

  // Merging in reverse order
  while(m>0 && n>0){
    if(nums1[m - 1] > nums2[n - 1]){
      nums1[last] = nums1[m - 1];
      m--;
    }
    else{
      nums1[last] = nums2[n - 1];
      n--;
    }
    last--;
  }

  // If we get a case like nums1 = [2,2,3,0,0,0] and nums2 = [1,5,6], then the first elemtnt of nums2 will be place at the first of nums1
  // For that we will have to take all left values of nums2 and fill them in nums1 
  // The condition of leftover elements is :-
  
  while(n>0){
    nums1[last] = nums2[n];
    n--;
    last = n-1;
    last--;
  }

  for (int i = 0; i <= size; i++)
    cout << nums1[i] << " ";
        
}

int main()
{
    vector<int> nums1 = {1,2,3,0,0,0}, nums2 = {2,5,6};
    int m = 3, n = 3;
    merge(nums1,m,nums2,n);
    return 0;
}