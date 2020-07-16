#include <stdio.h>
int ec(int a, int r){
	if(a%r==0){
		return r;
	}
	else{
		ec(r, a%r); 
	}
}
int main(){
	int a,b;
	scanf("%d %d", &a, &b);
	int c=ec(a,b);
	printf("%d\n%d",c ,(a*b)/c );
	
}

