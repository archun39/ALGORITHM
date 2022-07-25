S = input()
result = 0
zero = 0
one = 0

tmp = S[0]
minlist = []
minlist.append(tmp)

#문자열 축소화
for i in range(len(S)) : 
    if tmp != S[i] : 
        minlist.append(S[i])
        tmp = S[i]


#문자열 축소화 완료
S = minlist

#문자열 0과 1 각각 카운팅
for i in range(len(S)) :
    if S[i] == '0' :
        zero += 1
    elif S[i] == '1' :
        one += 1

if zero > one :
    for i in range(len(S)-1) :
        if S[i] == '0' and S[i+1] == '1' :
            result += 1
        
        elif i == 0 and S[i] == '1' :
            result += 1

else : 
    for i in range(len(S)-1) :
        if S[i] == '1' and S[i+1] == '0' :
            result += 1
        
        elif i == 0 and S[i] == '0' :
            result += 1

print(result)