#3 way merge sort
def mergeSort3way(arr):
    if len(arr) < 3:
        return    
    else:
        mid = len(arr) // 3
        left = mergeSort3way(arr[:mid])
        mid2 = mid + len(arr) // 3
        mid1 = mid
        mid = mid2
        mid2 = mid2 + len(arr) // 3
        middle = mergeSort3way(arr[mid1:mid])
        right = mergeSort3way(arr[mid2:])
        return merge3way(left, middle, right)

#merge 3 sorted arrays into one sorted array
def merge3way(arr1, arr2, arr3):    
    i = 0
    j = 0
    k = 0
    arr3 = []
    while i < len(arr1) and j < len(arr2) and k < len(arr3):
        if arr1[i] < arr2[j] and arr1[i] < arr3[k]:
            arr3.append(arr1[i])
            i += 1
        elif arr2[j] < arr1[i] and arr2[j] < arr3[k]:
            arr3.append(arr2[j])
            j += 1
        else:
            arr3.append(arr3[k])
            k += 1
    if i < len(arr1):
        arr3 += arr1[i:]
    if j < len(arr2):
        arr3 += arr2[j:]
    if k < len(arr3):
        arr3 += arr3[k:]
    return arr3

    
arr=[1,2,3,4,5]
arr1=[6,7,8,9,10]
arr2=[11,2]

print(merge3way(arr, arr1, arr2))





def merge(A, start, mid1, mid2, end):
    left_A = A[start - 1: mid1]
    mid_A = A[mid1: mid2 + 1]
    right_A = A[mid2 + 1: end]

    # lists might be empty so add a dummy infinite val
    left_A.append(float('inf'))
    mid_A.append(float('inf'))
    right_A.append(float('inf'))

    left_indx = 0
    mid_indx = 0
    right_indx = 0

    for i in range(start - 1, end):
        minimum = min([left_A[left_indx], mid_A[mid_indx], right_A[right_indx]])
        if minimum == left_A[left_indx]:
            left_indx += 1
        elif minimum == mid_A[mid_indx]:
            mid_indx += 1
        else:
            right_indx += 1
        A[i] = minimum

def merge_sort_helper(A, start, end):
    if len(A[start - 1: end]) < 2:
        return A
    
    mid1 = start + ((end - start) // 3)
    mid2 = start + 2 * ((end - start) // 3)

    merge_sort_helper(A, start, mid1)
    merge_sort_helper(A, mid1 + 1, mid2 + 1)
    merge_sort_helper(A, mid2 + 2, end)
    merge(A, start, mid1, mid2, end)
    return A


def merge_sort(A):
    return merge_sort_helper(A, 1, len(A))