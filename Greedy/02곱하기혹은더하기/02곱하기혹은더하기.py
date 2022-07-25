A = input()

result = int(A[0])
jump = 0
for i in range(len(A)-1) :
    
    #점프 확인
    if jump == 1 :
        jump = 0
        continue
    
    #다음 숫자가 0 또는 1일 경우
    #0 또는 1이 나오는 경우에 0과 1 앞뒤로 +를 해주어야 한다
    if A[i+1] == '0' or A[i+1] == '1' :
        result = result + int(A[i+1])
        if (i+1) < len(A)-1 :
            result = result + int(A[i+2])
            # 이 과정에서 포문의 인덱스를 한 개 건너뛰어야 하므로 점프를 통해 건너뛰어준다.
            jump = 1
            continue
            
    elif A[i] == '0' or A[i] == '1' : 
        result = result + int(A[i+1])
    
    else : 
        result = result * int(A[i+1])
    
print(result)
