from ast import main
from ctypes.util import find_library
from typing import final


def findarr(subArray, mainArray):
    rows = len(subArray)
    cols = len(subArray[0])
    finalArray = []

    for i in range(len(mainArray)):
        for j in range(len(mainArray[0])):
            if (i > (len(mainArray)-rows) or j > (len(mainArray[0])-cols)):
                continue

            v = True

            for k in range(rows):
                for l in range(cols):
                    if (mainArray[i+k][j+l] != subArray[k][l]):
                        v = False
            if v == True:
                finalArray.append((i, j))
    print(finalArray)


P = [['a', 'a', 'a'],
     ['b', 'b', 'a'],
     ['a', 'a', 'b']]

I = [['a', 'b', 'a', 'b', 'a', 'b', 'b'],
     ['a', 'a', 'a', 'a', 'b', 'b', 'b'],
     ['b', 'b', 'b', 'a', 'a', 'a', 'b'],
     ['a', 'a', 'a', 'b', 'b', 'a', 'a'],
     ['b', 'b', 'a', 'a', 'a', 'b', 'b'],
     ['a', 'a', 'b', 'a', 'b', 'a', 'a'],
     ]
findarr(P, I)
