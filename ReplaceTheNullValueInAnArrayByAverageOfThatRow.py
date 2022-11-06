from asyncio.windows_events import NULL


def fill(mat):
    rowtotal = 0
    average = 0
    count = 0
    for i in range(len(mat)):
        for j in range(len(mat[i])):
            rowtotal += mat[i][j]
        for l in range(len(mat[i])):

            if (mat[i][l] == NULL):
                count += 1
            r = len(mat[i])-count

        for k in range(len(mat)):
            if (mat[i][k] == NULL):
                average = rowtotal/r
                mat[i][k] = average
        rowtotal = 0
        average = 0
        count = 0

    print(mat)


T = [[11, 12, NULL, 2],
     [15, 6, 10, 11],
     [10, 8, 12, 5],
     [12, 15, NULL, 6]]

fill(T)
