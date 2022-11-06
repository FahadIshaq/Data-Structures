def split(sentence):
    split_value = []
    tmp = ''
    for c in sentence:
        if c == ' ':
            split_value.append(tmp.lower())
            tmp = ''
        else:
            tmp += c
    if tmp:
        split_value.append(tmp.lower())

    return split_value


def samee(s1, s2):

    arr = split(s1)
    arr1 = split(s2)

    count = 0
    for i in range(len(arr)):
        for j in range(len(arr1)):

            if (arr[i] == arr1[j]):
                count += 1

    return count


def uncommon(s1, s2):
    arr = split(s1)
    arr1 = split(s2)

    count = 0
    for i in range(len(arr)):
        for j in range(len(arr1)):

            if (arr[i] != arr1[j]):
                count += 1

    return count


def percentage(S1, S2):
    count = samee(S1, S2)

    s = (len(split(S1)) + len(split(S2))) - count
    print(s)
    return ((count/s)*100)


print(percentage("This is a boy", "This is a girl"))
