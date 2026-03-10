# def sito(n):
#     res = [True] * (n + 1)
#     res[0] = res [1] = False
#     for i in range(2, n +1):
#         if res[i]:
#             for j in range(i*2, len(res), i):
#                 res[j] = False
#     return res
#
# n = int(input())
# b = sito(n)
#
# for q in range(len(b)):
#     if b[q] == True:
#         print(q)


# def col(a, b, c):
#     x1, y1 = a
#     x2, y2 = b
#     x3, y3 = c
#     return (x2 - x1)*(y3 - y1) == (y2 - y1)*(x3 - x1)
#
# a = tuple(map(int, input().split()))
# b = tuple(map(int, input().split()))
# c = tuple(map(int, input().split()))
#
# print(col(a, b, c))

# vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U', 'Y', 'y']
#
# sentense = input()
#
# mes = list(sentense)
# result = mes[:]
# print(mes)
#
# for i in mes[:]:
#     if i in vowels:
#         result.remove(i)
#
# print("".join(result))
# for b in result[:]:
#     print(b)

n = int(input())

def a(e):
    if e == 1:
        return 1

    an_1 = 1 + a(e - a(n+1  - a(a(n))))
    return an_1

print(a(n))