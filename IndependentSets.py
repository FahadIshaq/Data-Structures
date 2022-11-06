def IndependentSets(array):
    arr = []
    for i in range(len(array)):
        for j in range(len(array)):
            if (i == j):
                continue
            elif (array[i][j] == 0):
                arr.append((i, j))
    return arr


# array = [[0, 1, 1, 0, 1, 0],
#          [1, 0, 1, 1, 0, 1],
#          [1, 1, 0, 1, 0, 1],
#          [0, 1, 1, 0, 1, 1],
#          [1, 0, 0, 1, 0, 0],
#          [0, 1, 1, 1, 0, 0]]


array = [[0, 1, 1, 0],
         [0, 1, 0, 1],
         [1, 0, 1, 0],
         [0, 1, 0, 1]
         ]


s = IndependentSets(array)

print(s)
# if (s == 0):
#     print("K is not the clique of the array")
# else:
#     print("K is the clique of the array")
