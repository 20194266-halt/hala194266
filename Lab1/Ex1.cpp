#include<iostream>
#include<vector>
using namespace std;
int find(vector<int>&arr, int x, int low, int high)
{   if (high >= low) {
    int mid = low + (high - low) / 2; // Tuong duong (l+r)/2 nhung uu di?m tránh tràn s? khi l,r l?n
 
    // N?u arr[mid] = x, tr? v? ch? s? và k?t thúc.
    if (arr.at(mid)<= x&&arr.at(mid+1)>x)
      return mid;
 
    // N?u arr[mid] > x, th?c hi?n tìm ki?m n?a trái c?a m?ng
    if (arr.at(mid)> x)
      return find(arr, x, low, mid - 1);
 
    // N?u arr[mid] < x, th?c hi?n tìm ki?m n?a ph?i c?a m?ng
    return find(arr, x, mid + 1, high);
  }
 
  // N?u không tìm th?y
  return -1;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int a = nums1.size();
        int b = nums2.size();// [1,3] [2,4,5,6,7] h =4 
        int l = (a+b)%2;double x; int h = (a+b)/2+1,flag = 1;
        int first1 = 0, first2 = 0, med1 = (a-1)/2, med2 = (b-1)/2, last1 = a-1, last2 = b-1;
        while(true)
        	{ 	//[3,4] [1,2]
						if(nums1.at(med1)>nums2.at(med2))
        					{
								int k = find(nums1, nums2.at(med2), first1, med1);
								k!=-1?h = h-(med2-first2+1)-(k-first1+1):h = h-(med2-first2+1);
								if (h<0)
									{
									med2 = (med2+first2)/2;med1 = (med1+first1)/2;	}
								 if(h>0)
								{   if(med1==last1)
									{   flag =0;
										if(nums1.at(last1)>nums2.at(med2+h))
										{
											x = ((double) (nums2.at(med2+h)+nums2.at(med2+h-!l)))/2.0; break;
										}
										else
										{   
											x = ((double) (max(nums2.at(med2+h-1),nums1.at(last1))+max(nums2.at(med2+h-1),nums1.at(last1))))/2.0;break;
										}
										break;
									}
									else if(med2 == last2)//[1,2,3,4,5][6.7.8]
									{   flag = 0;
									if(h==1)
									{
										if(k!=-1)
										{
										l==1? x = ((double)nums1.at(k+1)): x = ((double)(nums1.at(k+1)+nums2.at(last2))/2.0);break;}
										else
										{
										l==1? x = ((double) nums1.at(first1)): x = ((double) (nums1.at(first1)+nums2.at(last2))/2.0);break;
										}
									}
									else{
										if(k!=-1)
										{
										l==1? x = ((double)nums1.at(k+h)): x = ((double)(nums1.at(k+h)+nums1.at(k+h-1))/2.0);break;}
										else
										{
										l==1? x = ((double) nums1.at(first1+h-1)): x = ((double) (nums1.at(first1+h-1)+nums1.at(first1+h-2))/2.0);break;
										}
										
									}}
									else
									{
									first2 = med2+1; med2= (last2+first2)/2;
									k!=-1?first1 = k+1:first1 = first1; med1 = (first1+last1)/2;
								    }
								}
								else{
								break;
								}	
										
									}
									
								
								
							
						else
							{
								int k = find(nums2, nums1.at(med1), first2, med2);
								k!=-1?h = h-(med1-first1+1)-(k-first2+1):h = h-(med1-first1+1);
								if (h<0)
									{med2 = (med2+first2)/2;med1 = (med1+first1)/2;}
								if(h>0)
								{	if(med1==last1)
									{   flag =0;
										if(nums1.at(last1)>nums2.at(med2+h))
										{
											x = ((double) (nums2.at(med2+h)+nums1.at(med2+h-!l)))/2.0; break;
										}
										else
										{
											x = ((double) (max(nums2.at(med2+h-1),nums1.at(last1))+max(nums2.at(med2+h-1-!l),nums1.at(last1))))/2.0;break;
										}
										break;
									}
									else if(med2 == last2)
									{    flag = 0;
									if(nums2.at(last2)>nums1.at(med1+h))
									{
										x = ((double) (nums1.at(med1+h)+nums1.at(med1+h-!l)))/2.0; break;
									}
									else{
										x = ((double) (max(nums1.at(med1+h-1),nums2.at(last2))+max(nums1.at(med1+h-1-!l),nums2.at(last2))))/2.0;break;
									}
									}
									else
									{
									first1 = med1+1; med1 = (first1 + last1)/2;
									k!= -1? first2 = k+1: first2 = first2; med2 = (first2+last2)/2;
								    }
								}
								else{
								break;
								}
							}
		 			}
					
			
		if(flag)	
			{
			if(l) 
				{x = (double) min(nums1.at(med1), nums2.at(med2));}
			else
				{x = (double)min(nums1.at(med1), nums2.at(med2));
			 	 if(x ==nums1.at(med1))
			 	 {  int y = find(nums2,nums1.at(med1),first2,med2);
			 	 	y==-1? x = (x +nums1.at(med1-1))/2.0:x=x+max(nums1.at(med1-1),nums2.at(y));
				  }
			 	else
			 	 {int y = find(nums1,nums2.at(med2),first1,med1);
			 	 	y==-1? x = (x +nums2.at(med2-1))/2.0:x=x+max(nums2.at(med2-1),nums1.at(y));
			 	 	
				  }
				}
			}		
		return x;
}
				
		
    int main()
    {   
		int a[2] = {1,2};//1,1,2,2,5,6    1,3    2
		int b[2] = {3,4};
		std::vector<int> arr1( a, a + 2);	
		std::vector<int> arr2( b, b + 2);	
		
		
		cout<<findMedianSortedArrays(arr1, arr2);
	
		
        
	}
