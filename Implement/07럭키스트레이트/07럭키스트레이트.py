N = str(int(input()))

k = len(N) #길이

left = 0
right = 0
for i in range(k//2) : 
    left = left + int(N[i])

for i in range(k//2,k) : 
    right = right + int(N[i])


if (left == right ) :
    answer = "LUCKY"
else : answer = "READY"

print(answer)