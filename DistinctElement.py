def UniqueElements(A):
    for i in range(len(A)):
        for j in range(i+1, len(A)):
            if A[i] == A[j]:
                return False
    return True

print("Unique Elements")
A=[1,2,3,4,5,6,7,2,9,10]
print("The Array is: ", A)
print("The Array has Unique Elements: ", UniqueElements(A))
