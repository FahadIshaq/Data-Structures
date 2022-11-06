

def insertionSort(arr):
 
    for i in range(1, len(arr)):
 
        key = arr[i]
        j = i-1
        while j >= 0 and key < arr[j] :
                arr[j + 1] = arr[j]
                j -= 1
        arr[j + 1] = key
    return arr


    
def merge(arr1, arr2):
    i = 0
    j = 0
    arr1=insertionSort(arr1)
    arr2=insertionSort(arr2)
    
    arr3 = []
    while i < len(arr1) and j < len(arr2):
        if arr1[i] < arr2[j]:
            arr3.append(arr1[i])
            i += 1
        else:
            arr3.append(arr2[j])
            j += 1
    if i < len(arr1):
        arr3 += arr1[i:]
    if j < len(arr2):
        arr3 += arr2[j:]
    return arr3


def mergeSort(arr):
    if len(arr) < 20:
        print("Insertion sort used")
        return insertionSort(arr)
    
    else:
        mid = len(arr) // 2
        left = mergeSort(arr[:mid])
        right = mergeSort(arr[mid:])
        return merge(left, right)
    


arr1=[11,5,13,14,16, 15,16,17,18,19, 15,16,17,18,19,15,16,17,18,19,15,16,17,18,19,15,16,17,18,19,15,16,17,18,19]
print(len(arr1))

print(mergeSort(arr1))



