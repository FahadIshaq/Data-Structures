def is_square(mat):
    i = 0
    while (i < len(mat)):
        if (len(mat[i]) != len(mat)):
            return False
        i += 1
    return True


def swapp(x, y):
    z = x
    x = y
    y = z
    return x, y


def transpose(mat):
    for i in range(len(mat)):
        for j in range(i):
            swapp(mat[i][j], mat[j][i])
    print(mat)


T = [[11, 12, 5, 2],
     [15, 6, 10, 11],
     [10, 8, 12, 5],
     [12, 15, 8, 6]]


print(len(T))
