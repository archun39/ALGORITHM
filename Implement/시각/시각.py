N = int(input())

#시간
hr = 00
min = 00
sec = 00

#결과값
cnt = 0

while True :
    #초가 60초 되면 1분 증가
    if(sec == 60) :
        sec = 0
        min += 1

    #60분이 되면 1시간 증가
    if (min == 60) :
        min = 0
        hr+=1
    
    #주어진 시각이 넘어가는 것을 방지
    if(hr>N) :
        break
    
    #3이 들어가는 모든 경우의 수
    #시간 / 분 / 초
    if(hr == 3 or min%10 == 3 or min//10 == 3 or sec%10 == 3 or sec//10 == 3 ):
        cnt+=1

    sec += 1

print(cnt)