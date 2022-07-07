from tokenize import String

N = int(input())
move = input().split()

#(row,col)
row = 1
col = 1
print(move)
for i in range(len(move)) :
    if (move[i] == 'L' and col > 1) :
        col -= 1
    elif (move[i] == 'R' and col < N) :
        col += 1
    elif (move[i] == 'U' and row > 1) :
        row -= 1
    elif (move[i] == 'D' and row < N) :
        row += 1
    
print(str(row) + " " + str(col))
