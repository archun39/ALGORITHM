n, k = map(int, input().split())

# k로 더이상 나눌 수 없을 때까지 나눈 후 1씩 빼는 것이 가장 최적의 알고리즘이다.

process1 = 0
process2 = 0

# 2번 과정 구하기

while True :
    #k로 나눌 수 있을 때
    if (n%k == 0) :
        n = n//k
        process2 += 1
    
    #k로 나눌 수 없을 때
    else :

        #n이 k보다 작아 더이상 나눌 수 없을 때
        if (n < k) : 
            break

        #단순하게 나누어 떨어지지 못해 나눌 수 없을 때
        else : 
            while n%k != 0 :
                n -= 1
                process1 += 1

#남은 n을 1로 만드는 경우
while n!= 1:
    n -= 1
    process1 +=1
result = process1 + process2


print(result)
