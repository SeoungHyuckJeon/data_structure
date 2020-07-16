# -*- coding: utf-8 -*-
"""
Created on Thu Jul 16 21:38:30 2020

@author: Jeon Seung Hyuck
"""

N=8;
maze =  [[ 0, 0, 0, 0, 0, 0, 0, 1 ],
        [ 0, 1, 1, 0, 1, 1, 0, 1 ],
        [ 0, 0, 0, 1, 0, 0, 0, 1 ],
        [ 0, 1, 0, 0, 1, 1, 0, 0 ],
        [ 0, 1, 1, 1, 0, 0, 1, 1 ],
        [ 0, 1, 0, 0, 0, 1, 0, 1 ],
        [ 0, 0, 0, 1, 0, 0, 0, 1 ],
        [ 0, 1, 1, 1, 0, 1, 0, 0 ]]

PATHWAY_COLOUR = 0
WALL_COLOUR = 1
BLOCKED_COLOUR = 2
PATH_COLOUR = 3

def findMazePath(x, y):
    if x<0 or y<0 or x>=N or y>=N:
        return False
    elif maze[x][y]!=PATHWAY_COLOUR:
        return False
    elif x==N-1 and y==N-1:
        maze[x][y] = PATH_COLOUR
        return True
    else:
        maze[x][y] = PATH_COLOUR
        if findMazePath(x-1,y) or findMazePath(x,y-1) or findMazePath(x+1,y) or findMazePath(x,y+1):
            return True
        maze[x][y] = BLOCKED_COLOUR;
        return False
    
for i in range(0,N):
    for j in range(0,N):
        print(maze[i][j],end='')
    print('',end='\n')
    
print('',end='\n')    
findMazePath(0,0)

for i in range(0,N):
    for j in range(0,N):
        print(maze[i][j],end='')
    print('',end='\n')