#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SNAKE_MAX_LENGTH 20
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'

//矰ǐ : y = 1(down), y = -1(up), x = -1(left), x = 1(right), x = 0 or y = 0 (no move)
void snakeMove(int x,int y);
//竚 
void put_money(int []);
int XY[2];//竚 

void output(void);
//村栏挡 
int gameover(void);
//ゴ瓜 
void print_map(void);

void eat(void);

char map[12][12] = 
	{"************",//1
	 "*          *",//2
	 "*          *",//3
	 "*          *",//4
	 "*          *",//5
	 "*          *",//6
	 "*          *",//7
	 "*          *",//8
	 "*          *",//9
	 "*          *",//10
	 "*          *",//11
	 "************"};//12
	 
int snakeX[SNAKE_MAX_LENGTH] = {1,2,3,4,5};
int snakeY[SNAKE_MAX_LENGTH] = {1,1,1,1,1};
int snakeLength = 5;

int main(){
	char ch;
	put_money(XY);
	print_map();
	while(!gameover()){
		scanf("%s",&ch);
		switch(ch){//耞︽ǐよ 
			case 'A'://オǐ 
				snakeMove(-1,0);
				break;
			case 'S'://ǐ 
				snakeMove(0,1);
				break;
			case 'D'://ǐ 
				snakeMove(1,0);
				break;
			case 'W'://ǐ 
				snakeMove(0,-1);
				break;
		}
		eat();
		print_map();
	}
	printf("Game Over");
}

//ゴ瓜  沮矰竚ゴ矰,癘魁矰竚τㄤ緇竚干┪娩 
void print_map(void){
	int i = 0, j = 0, k = 0, g = 0, h = 0, z = 0;
	for(i=0;i<12;i++){
		for(j=0;j<12;j++){
			for(k=0;k<snakeLength;k++){//耞矰ぃ硂竚τゴ 
				if(k==snakeLength-1 && j==snakeX[k] && i==snakeY[k]){
					for(h=0;h<snakeLength-1;h++){//耞矰琌疾ō砰 琌杠夹癘Z硄矰繷ゴ 
						if(snakeX[h]==snakeX[snakeLength-1] && snakeY[h]==snakeY[snakeLength-1]){
							z=1;
						}
					}
					if(z==0 && (snakeX[k]==0 || snakeX[k]==11 || snakeY[k]==0 || snakeY[k]==11)){//沮矰繷临⊿ゴ 璝矰繷疾毁锚夹癘竒ゴ矰繷 
						g=0;
					}
				
					else if(z==0){//ヘ玡ゎ 矰繷临⊿ゴ ┮ゴ矰繷竚 
						printf("%c",SNAKE_HEAD);
						g=1; //夹粁ゴ矰 
					}
				}
				else if(j==snakeX[k] && i==snakeY[k]){
					printf("%c",SNAKE_BODY); 
					g=1;//夹粁ゴ矰 
				}
			}
			if(j==(XY[0]) && i==(XY[1])){//耞竚ゴ 
				printf("%c",SNAKE_FOOD);
				g=1;
			}
			if(g==0 && (i==0 || i==11)  || g==0 && (j==0 || j==11)){//⊿Τゴ矰杠干瓜  毁锚  map: if(g==0){ 
				printf("%c",WALL_CELL);								//											printf("%c",map[i][j]);
			}														//											}
			else if(g==0 && (i>0 && i<12) || g==0 && (j>0 && j<12)){//⊿Τゴ矰杠干瓜  				
				printf("%c",BLANK_CELL);
			}
			g=0;
		}
		printf("\n");
	}
	
}

//北矰ǐ笆 矰ō砰穦沮玡ō砰ㄓ耞ǐ,矰繷穦虫縒块τǐ 
void snakeMove(int x,int y){
	int i = 0;
	for(i=0;i<snakeLength-1;i++){
		if((snakeX[i]+1)==snakeX[i+1]){//矰ō巨
			snakeX[i]+=1;
		}
		if((snakeX[i]-1)==snakeX[i+1]){//矰ō巨 
			snakeX[i]-=1;
		}
		if((snakeY[i]+1)==snakeY[i+1]){//矰ō巨 
			snakeY[i]+=1;
		}
		if((snakeY[i]-1)==snakeY[i+1]){//矰ō巨 
			snakeY[i]-=1;
		}
	}
	if(x==1){//矰繷巨 
		snakeX[snakeLength-1]+=1;	
	}
	else if(x==-1){//矰繷巨 
		snakeX[snakeLength-1]-=1;
	}
	else{//X=0 ぃ簿笆薄猵 
	}
	if(y==1){//矰繷巨 
		snakeY[snakeLength-1]+=1;
	}
	else if(y==-1){//矰繷巨 
		snakeY[snakeLength-1]-=1;
	}
	else{//Y=0 ぃ簿笆薄猵 
	}
}

//笴栏挡耞 (疾鲤┪琌矰繷疾ō砰) 
int gameover(void){
	int i = 0;
	if(snakeX[snakeLength-1]==0 || snakeX[snakeLength-1]==11){//娩耞 
		return 1; 
	}
	else if(snakeY[snakeLength-1]==0 || snakeY[snakeLength-1]==11){//娩耞 
		return 1;
	}
	else {//矰繷疾ō砰耞 
		for(i=0;i<snakeLength-1;i++){
			if(snakeX[i] == snakeX[snakeLength-1] && snakeY[i] == snakeY[snakeLength-1]){
				return 1;
			}
		}
	}
	return 0;
}

//竚
void put_money(int XY[]){
	int i = 0;
	srand(time(0));//繦诀竚 ㄏノ皐纗竚 [0]X [1]Y
	XY[0] = rand() % 10 +1;//娩柑だ皌 
	XY[1] = rand() % 10 +1;//娩柑 
	for(i=0;i<snakeLength;i++){//耞穦ぃ穦籔矰 穦杠穝だ竚 ぃ穦 
		while(1){
			if(XY[0]==snakeX[i] || XY[1]==snakeY[i]){
				XY[0] = rand() %10 +1; //X禸竚110 
				XY[1] = rand() %10 +1;  //Y禸竚110 
			}
			else if(XY[0]!=snakeX[i] && XY[1]!=snakeY[i]){
				break;
			}
		}
	}
}

//矰
void eat(void){
	if(snakeX[snakeLength-1]==XY[0] && snakeY[snakeLength-1]==XY[1]){//狦  
		put_money(XY); //穝だ皌
		//snakeLength+=1; //矰+1 
	}
	else{//⊿┮ぃ巨 
		
	}
} 