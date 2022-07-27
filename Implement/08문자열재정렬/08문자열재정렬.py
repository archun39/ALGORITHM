S = str(input())

num = ['0','1','2','3','4','5','6','7','8','9']

Stringlist = []
Intlist = []
for i in range(len(S)) :
    if (S[i] in num)  :
        Intlist.append(S[i])
    else : 
        Stringlist.append(S[i])

#숫자 더하기
add = 0
for i in range(len(Intlist)) :
    add = add + int(Intlist[i])

Stringlist.sort()

tmp = ""
for i in range(len(Stringlist)) :
    tmp = tmp + Stringlist[i]


#문자열에 숫자가 없는 경우
if (len(Intlist) != 0) : 
    print(tmp+ str(add))
else : print(tmp)
