N, M = map(int,input().split())

balls = list(map(int,input().split()))


result = 0
#공을 앞에서 부터 하나씩 A가 고르고 그 다음 것 부터 무게가 다른 것만 B가 고르면 된다.
#같은 무게의 공이 몇개 있든 무게가 다른 것만 고르면 된다. 또한 같은 무게의 공은 서로 다른 공이므로 색이 다르다고 생각하면 쉽다.

for A in range(N-1) : 
    for B in range(A+1,N) :
        if balls[A] != balls[B] :
            result += 1

print(result)


## 이코테 설명보다 더 쉽게 푼 것 같다.


