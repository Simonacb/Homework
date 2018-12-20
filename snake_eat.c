#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SNAKE_MAX_LENGTH 20
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'

//蛇的走向 : y = 1(down), y = -1(up), x = -1(left), x = 1(right), x = 0 or y = 0 (no move)
void snakeMove(int x,int y);
//放置食物 
void put_money(int []);
int XY[2];//存放食物的位置 

void output(void);
//游戲結束 
int gameover(void);
//打印地圖 
void print_map(void);
//吃食物 
int eat(void);

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
		switch(ch){//判斷行走方向 
			case 'A'://向左走 
				snakeMove(-1,0);
				break;
			case 'S'://向下走 
				snakeMove(0,1);
				break;
			case 'D'://向右走 
				snakeMove(1,0);
				break;
			case 'W'://向上走 
				snakeMove(0,-1);
				break;
		}
		print_map();
	}
	printf("Game Over");
}

//打印地圖  根據蛇位置打印蛇,並且記錄蛇的位置而在其餘位置補上空格或邊界 
void print_map(void){
	int i = 0, j = 0, k = 0, g = 0, h = 0, z = 0;
	for(i=0;i<12;i++){
		for(j=0;j<12;j++){
			for(k=0;k<snakeLength;k++){//判斷蛇在不在這個位置而打印 
				if(k==snakeLength-1 && j==snakeX[k] && i==snakeY[k]){
					for(h=0;h<snakeLength-1;h++){//判斷蛇是否撞到身體 是的話標記Z通知蛇頭已打印 
						if(snakeX[h]==snakeX[snakeLength-1] && snakeY[h]==snakeY[snakeLength-1]){
							z=1;
						}
					}
					if(z==0 && (snakeX[k]==0 || snakeX[k]==11 || snakeY[k]==0 || snakeY[k]==11)){//根據蛇頭還沒打印 若蛇頭撞到障礙標記已經打印蛇頭 
						g=0;
					}
				
					else if(z==0){//到目前為止 蛇頭還沒打印 所以打印蛇頭位置 
						printf("%c",SNAKE_HEAD);
						g=1; //標誌打印了蛇 
					}
				}
				else if(j==snakeX[k] && i==snakeY[k]){
					printf("%c",SNAKE_BODY); 
					g=1;//標誌打印了蛇 
				}
			}
			if(j==(XY[0]) && i==(XY[1])){//判斷食物位置後打印 
				printf("%c",SNAKE_FOOD);
				g=1;
			}
			if(g==0 && (i==0 || i==11)  || g==0 && (j==0 || j==11)){//沒有打印蛇的話補上地圖  障礙  map版: if(g==0){ 
				printf("%c",WALL_CELL);								//											printf("%c",map[i][j]);
			}														//											}
			else if(g==0 && (i>0 && i<12) || g==0 && (j>0 && j<12)){//沒有打印蛇的話補上地圖 空格 				
				printf("%c",BLANK_CELL);
			}
			g=0;
		}
		printf("\n");
	}
	
}

//控制蛇的走動 蛇的身體會根據前面的身體來判斷走向,蛇頭自己會單獨的按輸入的指令而走 
void snakeMove(int x,int y){
	int i = 0, midX = 0, midY = 0;//midX和midY 記錄蛇尾位置 方便了吃到食物後的增尾操作
	midX = snakeX[0];
	midY = snakeY[0]; 
	for(i=0;i<snakeLength-1;i++){
		if((snakeX[i]+1)==snakeX[i+1]){//蛇身操作
			snakeX[i]+=1;
		}
		if((snakeX[i]-1)==snakeX[i+1]){//蛇身操作 
			snakeX[i]-=1;
		}
		if((snakeY[i]+1)==snakeY[i+1]){//蛇身操作 
			snakeY[i]+=1;
		}
		if((snakeY[i]-1)==snakeY[i+1]){//蛇身操作 
			snakeY[i]-=1;
		}
	}
	if(x==1){//蛇頭操作 
		snakeX[snakeLength-1]+=1;	
	}
	else if(x==-1){//蛇頭操作 
		snakeX[snakeLength-1]-=1;
	}
	else{//X=0 不移動的情況 
	}
	if(y==1){//蛇頭操作 
		snakeY[snakeLength-1]+=1;
	}
	else if(y==-1){//蛇頭操作 
		snakeY[snakeLength-1]-=1;
	}
	else{//Y=0 不移動的情況 
	}
	if(eat()){//如果吃到食物 加長蛇的物理長度 
		for(i=snakeLength-2;i>=0;i--){
			snakeX[i+1] = snakeX[i];
			snakeY[i+1] = snakeY[i]; 
		}
		snakeX[0] = midX;
		snakeY[0] = midY;
	} 
}

//遊戲結束的判斷 (撞到牆或是蛇頭撞到身體) 
int gameover(void){
	int i = 0;
	if(snakeX[snakeLength-1]==0 || snakeX[snakeLength-1]==11){//邊界判斷 
		return 1; 
	}
	else if(snakeY[snakeLength-1]==0 || snakeY[snakeLength-1]==11){//邊界判斷 
		return 1;
	}
	else {//蛇頭撞身體判斷 
		for(i=0;i<snakeLength-1;i++){
			if(snakeX[i] == snakeX[snakeLength-1] && snakeY[i] == snakeY[snakeLength-1]){
				return 1;
			}
		}
	}
	return 0;
}

//放置食物
void put_money(int XY[]){
	int i = 0;
	srand(time(0));//隨機食物位置 使用指針儲存位置 [0]代表X [1]代表Y
	XY[0] = rand() % 10 +1;//在邊界裡分配食物 
	XY[1] = rand() % 10 +1;//在邊界裡 
	for(i=0;i<snakeLength;i++){//判斷食物會不會與蛇同位 會的話重新分食物位置 直到不會 
		while(1){
			if(XY[0]==snakeX[i] || XY[1]==snakeY[i]){
				XY[0] = rand() %10 +1; //X軸能放置長度為1到10 
				XY[1] = rand() %10 +1;  //Y軸能放置長度為1到10 
			}
			else if(XY[0]!=snakeX[i] && XY[1]!=snakeY[i]){
				break;
			}
		}
	}
}

//蛇吃到食物
int eat(void){
	if(snakeX[snakeLength-1]==XY[0] && snakeY[snakeLength-1]==XY[1]){//判斷有沒有吃到食物 
		put_money(XY); //重新分配食物
		snakeLength +=1;//加長蛇的邏輯長度 
		return 1; 
	}
	else{
		return 0;
	}
} 