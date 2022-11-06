# # # # def is_Palindrome(n):
# # # #     for i in range(len(n)):
# # # #         if n[i] != n[len(n)-i-1]:
# # # #             return False
# # # #     return True

# # # import math
# # # # def main():
# # # #     n = input("Enter a word: ")
# # # #     if(is_Palindrome(n)==True):

# # # #         print(n + " is palindrome")
# # # #     else:
# # # #         # print(n + " is not a palindrome")
# # # # main()


# # # # ACTIVITY 4 (A closed polygon with N sdes can be represented as a list of touples of N connected coordinates. )
# # # # Write a python function that takes a list of N tuples as input and returns the perimeter of the polygon. Remember that your code should work for any value of N.

# # # def perimeterOfPolygon(number):
# # #     perimeter = 0
# # #     # length = len(number)
# # #     for i in range(0, length-1):
# # #         distance = math.sqrt(
# # #             (number[i+1][0]-number[i][0])**2+(number[i+1][1]-number[i][1])**2)
# # #         perimeter = perimeter+distance
# # #     perimeter = perimeter+math.sqrt((number[0][0]-number[length-1][0])**2)
# # #     return perimeter
# # # def main():
# # #     l = [(0, 0), (0, 5), (3, 5), (3, 0)]
# # #     print(perimeterOfPolygon(l))


# # # main()


# # # def product(a, b):
# # #     c = [[]]
# # #     # a = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
# # #     # b = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

# # #     for i in range(3):
# # #         c.append([])
# # #         for j in range(3):
# # #             c[i].append(0)
# # #             for k in range(3):
# # #                 c[i][j] += a[i][k]*b[j][i]

# # #     print(c)
# # # def main():
# # #     a = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
# # #     b = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
# # #     product(a, b)

# # # list1 = []
# # # list2 = []

# # # print("Enter elements for list 1")
# # # for i in range(3):
# # #     n = input("Enter number " + str(i+1) + ": ")
# # #     list1.append(n)

# # # print("Enter elements for list 2")

# # # for j in range(3):
# # #     n = input("Enter number " + str(j+1) + ": ")
# # #     list2.append(n)


# # # list3 = list1+list2
# # # list3.sort()
# # # print("The sorted list is: ", list3)
# # list1 = []
# # list2 = []

# # print("Enter elements for list 1")
# # for i in range(3):
# #     n = input("Enter number " + str(i+1) + ": ")
# #     list1.append(n)

# # print("Enter elements for list 2")

# # for j in range(3):
# #     n = input("Enter number " + str(j+1) + ": ")
# #     list2.append(n)


# # list3 = list1+list2
# # list3.sort()
# # print("The Smallest Integer: ", list3[0])
# # print("The Largest Integer: ", list3[len(list3)-1])

# dictionary = {
#     "Fahad": "21/08/2001",
#     "Kumail": "9/09/2000",
#     "Ali": "7/10/2001",
#     "Zain": "7/10/2001",
#     "Idrees": "6/1/2008",

# }

# print("We know the birthdays of: ")
# for key in dictionary.keys():
#     print(key)

# birthday = input("Whose birthday do you want to look up? ")
# if (birthday not in dictionary):
#     print("Birthday Does Not Exists")
# else:
#     print(birthday + "'s birthday is " + dictionary[birthday.lower()])


sample_dict = {
    "name": "Kelly",
    "age": 25,
    "salary": 8000,
    "city": "New york"}

keys = ["name", "salary"]

new_dictioinary = {}

for i in range(len(keys)):
    new_dictioinary[keys[i]] = sample_dict[keys[i]]

print(new_dictioinary)
