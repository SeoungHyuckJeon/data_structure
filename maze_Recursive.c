#include <stdio.h>
#define PATHWAY 0
#define WALL 1
#define BLOCKED 2
#define PATH 3
int N=8; 
int maze[8][8]={
	{ 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 0, 1, 1, 0, 1, 1, 0, 1 },
	{ 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 0, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 1, 1, 1, 0, 0, 1, 1 },
	{ 0, 1, 0, 0, 0, 1, 0, 1 },
	{ 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 0, 1, 1, 1, 0, 1, 0, 0 }
};
bool findMazePath(int x, int y){
	if( x<0 || y<0 || x>=N || y>=N){
		return false;
	}
	else if( maze[x][y] != PATHWAY){
		return false;
	}
	else if( x == N-1 && y == N-1){
		maze[x][y] = PATH; 
		return true;
	}
	else{
		maze[x][y] = PATH;
		if(findMazePath(x-1,y) || findMazePath(x,y+1) || findMazePath(x+1,y) || findMazePath(x,y-1)){
			return true;
		}
		maze[x][y] = BLOCKED;
		return false;
	}
}
int main(){
	findMazePath(0, 0);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
}

