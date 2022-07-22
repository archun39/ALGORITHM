from stringprep import c6_set
from sys import intern


point = input()

x = point[0]
y = point[1]

cng = ['a','b','c','d','e','f','g','h']


# 소문자를 1로 바꿀 때 ord()를 사용하면 편하다.
# -> x = int(ord(point[0])) - int(ord('a')) + 1


tmp = 1
for i in cng :
    if i == x :
        x = tmp
    tmp += 1


# 갈 수 있는 방향 8 가지를 하나씩 더하고 빼는 것이 아니라 미리 가중치를 리스트에 담아두어 쉽게 반복문을 통해 사용할 수 있다.
move = [(-2,-1),(-2,1),(2,-1),(2,1),(-1,2),(1,2),(-1,-2),(1,-2)]

result = 0

#리스트 안의 괄호 '()'를 통해서 인덱스로 쉽게 가져올 수 있다.
for m in move :
    dx = int(x) + int(m[0])
    dy = int(y) + int(m[1])
    if (dx >= 1 and dx <=8 and dy >= 1 and dy <= 8) :
        result += 1

print(result)