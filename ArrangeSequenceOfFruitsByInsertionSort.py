# Python program for implementation of Insertion Sort

# Function to do insertion sort
from dataclasses import replace


def insertionSort(a):

    arr = []

    for i in range(len(a)):
        if a[i] == 'red':
            arr.append(0)
        elif a[i] == 'white':
            arr.append(1)
        elif a[i] == 'blue':
            arr.append(2)

    # Traverse through 1 to len(arr)
    for i in range(1, len(arr)):

        key = arr[i]

        # Move elements of arr[0..i-1], that are
        # greater than key, to one position ahead
        # of their current position
        j = i-1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    print(arr)
    for i in range(len(arr)):
        if arr[i] == 0:
            arr[i] = 'red'
        elif arr[i] == 1:
            arr[i] = 'white'
        elif arr[i] == 2:
            arr[i] = 'blue'

    return arr


# Driver code to test above
arr = ['red', 'blue', 'red', 'white', 'blue']

print(insertionSort(arr))
