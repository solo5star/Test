#include <stdio.h>

void printmaps(void);
void maptime(void);
void killnum(int ded,int cha);
void mapscan(void);
	
int maps[2000][2000][2]={0,};	
int size=1;
int start=1;
int main(void) {
	
	int i,y,count=0;
	int a,b;
	int wait=0;
	scanf("%d",&size);
	scanf("%d",&start);
	for(i=1;i<=start;i++){
		scanf("%d %d",&a,&b);
		maps[a][b][0]=i;
	}
	/*
	printmaps();10
	maptime();
	printf("\n");
	mapscan();
	printmaps();
	maptime();
	mapscan();
	printf("\n");
	printmaps();*/
	mapscan();
	for(;;){
		for(i=1;i<=size;i++){
			for(y=1;y<=size;y++){
				if(maps[i][y][0]!=0)
					if(maps[i][y][0]<start)wait=1;
			}
		}
		if(wait==0)break;
		maptime();
		mapscan();
		//printmaps();
		//printf("\n");
		count++;
		wait=0;
	}
	printf("%d",count);
	return 0;
}
	
void printmaps(void){
	int i,y;
	for(i=1;i<=size;i++){
		for(y=1;y<=size;y++){
			printf("%d ",maps[i][y][0]);
		}
		printf("띄우기\n");
	}
}

void maptime(void){
	int i,y;
	for(i=1;i<=size;i++){
		for(y=1;y<=size;y++){
			if(maps[i][y][0]>0){
				maps[i+1][y][1]=maps[i][y][0];
				maps[i][y+1][1]=maps[i][y][0];
				maps[i-1][y][1]=maps[i][y][0];
				maps[i][y-1][1]=maps[i][y][0];
			}
		}
	}
	
	for(i=1;i<=size;i++){
		for(y=1;y<=size;y++){
				if(maps[i][y][0]==0)maps[i][y][0]=maps[i][y][1];
			
		}
	}
}


void mapscan(void){
	int i,y;
	int deadnum,changnum;
	int ok=0;;
	for(i=1;i<=size;i++){
		for(y=1;y<=size;y++){
			if(maps[i][y][0]!=0){
				if(maps[i][y][0]<maps[i+1][y][0]){
					ok=1;
					deadnum=maps[i][y][0];
					changnum=maps[i+1][y][0];
				}
				//if(ok==0)	
					if(maps[i][y][0]<maps[i][y+1][0]){
						ok=1;
						deadnum=maps[i][y][0];
						changnum=maps[i][y+1][0];
					}
				//if(ok==0)	
					if(i>0)
						if(maps[i][y][0]<maps[i-1][y][0]){
						ok=1;
						deadnum=maps[i][y][0];
						changnum=maps[i-1][y][0];
					}
				//if(ok==0)	
					if(i>0)
						if(maps[i][y][0]<maps[i][y-1][0]){
						ok=1;
						deadnum=maps[i][y][0];
						changnum=maps[i][y-1][0];
					}
			
				if(ok==1){
					killnum(deadnum,changnum);
					ok=0;
				}
			}
		}
	}
}




void killnum(int ded,int cha){
	int i,y;
	for(i=1;i<=size;i++){
		for(y=1;y<=size;y++){
			if(maps[i][y][0]==ded){
				maps[i][y][0]=cha;
			}
		}
	}
}