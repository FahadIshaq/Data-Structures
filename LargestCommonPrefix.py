
def commonprefix(s1,s2):
    common=""
    n1=len(s1)
    n2=len(s2)
    
    for i in range(0,min(n1,n2)): #min(n1,n2) is the length of the shortest string
        if s1[i]==s2[i]:
            common+=s1[i]
        else:
            break
    return common

def largestCommonPrefix(arr, low, high):
    if (low == high):
        return arr[low]
    if(high>low):
        mid=low+(high-low)//2
        s1=largestCommonPrefix(arr,low,mid)
        s2=largestCommonPrefix(arr,mid+1,high)
        ans=commonprefix(s1,s2)
        return ans
    
    
arr=["fahad","fahima","faheem"]
print(largestCommonPrefix(arr,0,len(arr)-1))
