
#데이타 받아오는 방법
n, m, k = map(int, input().split())
data = list(map(int, input().split()))

#큰 수를 위한 정렬
data.sort()

#가장 큰 수와 두 번째로 큰 수
big1 = data[-1]
big2 = data[-2]
print(big1)
print(big2)
sum = 0


for i in range(1,m+1) :
    #k번째이후는 두 번째로 큰 수를 더함
    if( i % k == 0) :
        sum += big2
    else : sum += big1

print(sum)