import math

def abs(list):
    for i in range(0, list.len()):
        list[i] = abs(list[i])

    return list


def gcd(list):
    list = abs(list)
    if list.len() == 1:
        return list[0]
    if list.len() == 2:
        return math.gcd(list[0], list[1])
    for result in range(int(min(list)), 0, -1):
        if sum(list%result) == 0:
            return result




def solve(matrix, count):
    lvl = 0
    while lvl < count-1:
        for i in range(lvl+1, count):
            matrix[i] = matrix[i]*matrix[lvl][lvl] - matrix[lvl]*matrix[i][lvl]
            matrix[i] /= gcd(matrix[i])

        lvl += 1

    return [matrix[count-1][count-1], matrix[count-1][count]]


print("Count of unknowns: ")
count = int(input())
print("Matrix:")
matrix = [[]]
for i in range(count):
    for j in range(count+1):
        matrix[i] += [int(input())]

    matrix += [[]]

print(solve(matrix, count))
