/******************************************************************************

My Naive approch for this qustion problem will be like start iterating on the array from left side and
when we will find the -1 we just break the loop and  return that index
Time Complexity =  O(n)
Space Complexity = O(1)


Optimised Approach:
As we know we can divide out array in a range because if we find the negative element then after that we have all negativ element so what i will do 
i will apply binary search on answer
if current element is -1 then this can be our potention answer we will move towards left by  storing it in our answer and high =  mid-1

if current element is  positive or zero the we have to make low = mid+1

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;


int findIndex(vector<int>&vec,int n)
{
    int low =0;
    int high = n-1;
    int ans = -1;
    while(low<=high)
    {
        int mid = low+(high-low)/2;
        if(vec[mid]>=0)
        {
            low =mid+1;
        }
        else
        {
            ans =mid;
            high =mid-1;
        }
     
    }
    return ans;
}

int main()
{
   vector<int>vec;
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
       int ele;
       cin>>ele;
       vec.push_back(ele);
   }
   
   
   cout<<findIndex(vec,n);
   return 0;
   
}



