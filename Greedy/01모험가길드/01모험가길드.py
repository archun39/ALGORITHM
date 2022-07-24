N = int(input())
adv = list(map(int,input().split()))

adv.sort()

result = 0
tmp = 0
while True :
    target = adv[tmp]
    cnt = 0
    group = 0
    #가장 작은 공포심을 가진 모험가가 전체 모험가의 수보다 큰 경우
    if adv[0] > len(adv) :
        break

    # 그룹 생성 가능한지 탐색
    for i in range(len(adv)) :

        if cnt == target :
            group  = 1
            break

        if adv[i] <= target :
            cnt += 1
        
    # 그룹이 만들어질 수 있으면 그룹을 만들어 주고 모험가들은 대기 리스트에서 삭제      
    if group == 1:
        adv = adv[cnt:]
        result += 1
        tmp = 0

    else : 
        tmp += 1

        # 모험가들을 끝까지 탐색하면서 더이상 탐색할 모험가가 없는 경우
        if tmp >= len(adv) :
            break
    
print(result)
