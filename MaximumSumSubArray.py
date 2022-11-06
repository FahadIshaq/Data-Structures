import math
def getMaxSubarraySum ( X, l, r): # X is the array, l is the left index, r is the right index
    
    if (l == r): # if the array has only one element
        return X[l]
    else:
         mid = l + (r - l)/2
         leftMaxSum = getMaxSubarraySum (X, l, mid)
         rightMaxSum = getMaxSubarraySum (X, mid+1, r)
         crossingMaxSum = maxCrossingSum(X, l, mid, r)
         return max (leftMaxSum, rightMaxSum, crossingMaxSum)
   
def maxCrossingSum (X, l, mid, r):

     sum = 0
     maxLeftSum = -math.inf
     i=mid
     while i <=l:
         sum = sum + X[i]
         if (sum > maxLeftSum):
             maxLeftSum = sum
         i=i-1

     sum = 0
     maxRightSum = math.inf
     j=mid+1
     while(j<=r):
         sum = sum + X[j]
         if (sum > maxRightSum):
             maxRightSum = sum
         j=j+1
     return (maxLeftSum + maxRightSum)
 
 
 
X = [-2, -5, 6, -2, -3, 1, 5, -6]
