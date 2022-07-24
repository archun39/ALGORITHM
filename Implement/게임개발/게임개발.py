# map size
from re import X


N, M = map(int,input().split())

# first-point
x, y, d = map(int,input().split())

# 방향 단순화
# 북 서 남 동
dy = [0,-1,0,1]
dx = [-1,0,1,0]
# map
array = []
for i in range (N) :
    array.append(list(map(int, input().split())))


result = 1
end = 0

while True :     
    
    if array[x + dx[d]][y + dy[d]] == 0 :
        #갈 곳이 있으며로 자신이 왔던 곳은 표시를 해주어야 한다.
        array[x][y] = 2
        x = x + dx[d]
        y = y + dy[d]
        result += 1
        end = 0
        

        
    else : 
        d = (d+1)%4
        end += 1
        
        if end == 4 :
            
            # 왔던 길이 있는 경우
            if array[x - dx[d]][y - dy[d]] == 2:
                array[x][y] = 1
                x = x - dx[d]
                y = y - dy[d]
                end = 0
                
            else : 
                break

print(result)

