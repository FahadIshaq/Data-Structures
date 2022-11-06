def findKey(arr, key, first, last):
    

        
    if (first==last and arr[first]==key): 
        print(first==last and arr[first]==key)
        return first 
    elif (first==last and arr[first]!=key): 
        return -1 
    mid1=first+((last-first)//3) 
    
    mid2=mid1+((last-mid1)//3) 

    if (key <= arr[mid1]):
    
        return findKey(arr,key,first,mid1) 
    elif(key>arr[mid1] and key<=arr[mid2]): 
        
        return findKey(arr,key,mid1+1, mid2) 
    else: 
    
        return findKey(arr,key,mid2+1, last)  



arr=[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]

length =len(arr)
key=99
index = findKey(arr,key,0,length-1)
if(index==-1):
    print("Key not found")
else:
    print("Key found at index",index)