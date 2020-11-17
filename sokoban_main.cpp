#include "sokoban.h"
#include <iostream>
void Building_Maze(){
	//open a window
	initscr();
	start_color();
	curs_set(0);
	resize_term(30, 30);
	mvprintw(5,5,"******GAME START******");

	
	const int MAZE_SIZE = 11;	//maze size
	int map[11][11];		//maze
	int i=0, j=0;			//maze pointer
	
	int fd;
	char buf[256];	
	int read_size;	
	
	fd = open("./readtest2", O_RDONLY);
	
	if(fd == -1)
		printw("File Open Error\n");
	
	while(0 < (read_size = read(fd, buf, 1))){
		if(j==10)
		{
			j=0; 
			i++;
		}		
		map[i][j] = atoi(buf);
		j++;
	}
	for(int a=0;a<MAZE_SIZE-1;a++)
	{
		
		for(int b=0;b<MAZE_SIZE-1;b++)
			{
			Display(map[a][b], a, b);
			}
		
	}

	i = 0;
    j = 0;
	
	
	refresh();
	Move_Character(map);
    	fd = open("./readtest3", O_RDONLY);
	
	if(fd == -1)
		printw("File Open Error\n");
	
	while(0 < (read_size = read(fd, buf, 1))){
		if(j==10)
		{
			j=0; 
			i++;
		}		
		map[i][j] = atoi(buf);
		j++;
	}
	for(int a=0;a<MAZE_SIZE-1;a++)
	{
		
		for(int b=0;b<MAZE_SIZE-1;b++)
			{
			Display(map[a][b], a, b);
			}
		
	}

	i = 0;
    j = 0;
	

	refresh();
	Move_Character(map);
    fd = open("./readtest", O_RDONLY);
	
	if(fd == -1)
		printw("File Open Error\n");
	
	while(0 < (read_size = read(fd, buf, 1))){
		if(j==10)
		{
			j=0; 
			i++;
		}		
		map[i][j] = atoi(buf);
		j++;
	}
	for(int a=0;a<MAZE_SIZE-1;a++)
	{
		
		for(int b=0;b<MAZE_SIZE-1;b++)
			{
			Display(map[a][b], a, b);
			}
		
	}
    refresh();
    Move_Character(map);
	getch();
    close(fd);
	endwin();
}

void Move_Character(int map[][11]){
	keypad(stdscr, TRUE);
	noecho();
	int input;
	int characterX, characterY; // index of characterX
	bool bool_end = false;
    int move_box = 0;
    int walk = 0;
    mvprintw(7, 15,"Box : *******");
    mvprintw(8, 15,"Walk : *******");
    refresh();
	bool_end = define_End(map);
	for(int a=0;a<11;a++)
	{
		for(int b=0;b<11;b++)
			{
				if(map[a][b] == 5){
					characterX = a;
					characterY = b;
				}
			}
		
	}
	while((input = getch()) != KEY_F(1) && bool_end == false){
		Beep(); // while typing, it creates beep sound!
		switch(input){
			case KEY_LEFT:
				if(characterY == 1){
				
				}
				else if (map[characterX][characterY-1] == 1){

				}
				else if (map[characterX][characterY-1] == 4){
					if(map[characterX][characterY] == 8){
						map[characterX][characterY] = 3;
						Display(map[characterX][characterY], characterX, characterY);
						characterY = characterY-1;
						map[characterX][characterY] = 5;
						Display(map[characterX][characterY], characterX, characterY);
						mvprintw(8, 15,"Walk : %d",++walk);
						refresh();
					}
					else{
						map[characterX][characterY] = 4;
						Display(map[characterX][characterY], characterX, characterY);
						characterY = characterY-1;
						
						mvprintw(8, 15,"Walk : %d",++walk);
						map[characterX][characterY] = 5;
						Display(map[characterX][characterY], characterX, characterY);
						refresh();
					}
				}
				else if (map[characterX][characterY-1] == 3){
						if(map[characterX][characterY] == 8){
						map[characterX][characterY] = 3;
						Display(map[characterX][characterY], characterX, characterY);
						characterY = characterY-1;
						
						mvprintw(8, 15,"Walk : %d",++walk);
						map[characterX][characterY] = 8;
						Display(map[characterX][characterY], characterX, characterY);
						refresh();
					}
					else{
						map[characterX][characterY] = 4;
						Display(map[characterX][characterY], characterX, characterY);
						characterY = characterY-1;
						mvprintw(8, 15,"Walk : %d",++walk);
						map[characterX][characterY] = 8;
						Display(map[characterX][characterY], characterX, characterY);
						refresh();
					}
				}
				else if (map[characterX][characterY-1] == 2){
					if(characterY <= 2){

					}
					else if(map[characterX][characterY-2] == 1){

					}
					else if(map[characterX][characterY-2] == 2){

					}
					else if(map[characterX][characterY-2] == 3){
						if(map[characterX][characterY] == 8){
							map[characterX][characterY] = 3;
							Display(map[characterX][characterY], characterX, characterY);
							characterY = characterY-1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 5;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
							map[characterX][characterY-1] = 7;
							Display(map[characterX][characterY-1], characterX, characterY-1);
							refresh();
							bool_end = define_End(map);
						}
						else{
							map[characterX][characterY] = 4;
							Display(map[characterX][characterY], characterX, characterY);
							characterY = characterY-1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 5;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
							
							map[characterX][characterY-1] = 7;
							Display(map[characterX][characterY-1], characterX, characterY-1);
							refresh();
							bool_end = define_End(map);
						}
					}
					else if(map[characterX][characterY-2] == 4){
						if(map[characterX][characterY] == 8){
							map[characterX][characterY] = 3;
							Display(map[characterX][characterY], characterX, characterY);
							characterY = characterY-1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 5;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
							
							map[characterX][characterY-1] = 2;
							Display(map[characterX][characterY-1], characterX, characterY-1);
							refresh();
							bool_end = define_End(map);
						}
						else{
							map[characterX][characterY] = 4;
							Display(map[characterX][characterY], characterX, characterY);
							characterY = characterY-1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 5;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
							
							map[characterX][characterY-1] = 2;
							Display(map[characterX][characterY-1], characterX, characterY-1);
							refresh();
							bool_end = define_End(map);
						
						}
					}
				}

				else if (map[characterX][characterY-1] == 7){
					if(characterY <= 2){

					}
					else if(map[characterX][characterY-2] == 1){

					}
					else if(map[characterX][characterY-2] == 2){

					}
					else if(map[characterX][characterY-2] == 3){
						if(map[characterX][characterY] == 8){
							map[characterX][characterY] = 3;
							Display(map[characterX][characterY], characterX, characterY);
							characterY = characterY-1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 8;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
							
							map[characterX][characterY-1] = 7;
							Display(map[characterX][characterY-1], characterX, characterY-1);
							refresh();
							bool_end = define_End(map);
						}
						else{
							map[characterX][characterY] = 4;
							Display(map[characterX][characterY], characterX, characterY);
							characterY = characterY-1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 8;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
							
							map[characterX][characterY-1] = 7;
							Display(map[characterX][characterY-1], characterX, characterY-1);
							refresh();
							bool_end = define_End(map);
						}
					}
					else if(map[characterX][characterY-2] == 4){
						if(map[characterX][characterY] == 8){
							map[characterX][characterY] = 3;
							Display(map[characterX][characterY], characterX, characterY);
							characterY = characterY-1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 8;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
							
							map[characterX][characterY-1] = 2;
							Display(map[characterX][characterY-1], characterX, characterY-1);
							refresh();
							bool_end = define_End(map);
						}
						else{
						
							map[characterX][characterY] = 4;
							Display(map[characterX][characterY], characterX, characterY);
							characterY = characterY-1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 8;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
							map[characterX][characterY-1] = 2;
							
							Display(map[characterX][characterY-1], characterX, characterY-1);
							refresh();
							bool_end = define_End(map);
						
						}
					}
				}
				
				/*map[characterX][characterY] = 0;
				mvprintw(characterX+10,characterY+10,"%d",map[characterX][characterY]);
				refresh();*/
				break;
			case KEY_RIGHT:
				if(characterY == 8){
				
				}
				else if (map[characterX][characterY+1] == 1){

				}
				else if (map[characterX][characterY+1] == 4){
					if(map[characterX][characterY] == 8){
						map[characterX][characterY] = 3;
						Display(map[characterX][characterY], characterX, characterY);
						characterY = characterY+1;
						mvprintw(8, 15,"Walk : %d",++walk);
						map[characterX][characterY] = 5;
						Display(map[characterX][characterY], characterX, characterY);
						refresh();
					}
					else{
						map[characterX][characterY] = 4;
						Display(map[characterX][characterY], characterX, characterY);
						characterY = characterY+1;
						mvprintw(8, 15,"Walk : %d",++walk);
						map[characterX][characterY] = 5;
						Display(map[characterX][characterY], characterX, characterY);
						refresh();
					}
				}
				else if (map[characterX][characterY+1] == 3){
						if(map[characterX][characterY] == 8){
						map[characterX][characterY] = 3;
						Display(map[characterX][characterY], characterX, characterY);
						characterY = characterY+1;
						mvprintw(8, 15,"Walk : %d",++walk);
						map[characterX][characterY] = 8;
						Display(map[characterX][characterY], characterX, characterY);
						refresh();
					}
					else{
						map[characterX][characterY] = 4;
						Display(map[characterX][characterY], characterX, characterY);
						characterY = characterY+1;
						mvprintw(8, 15,"Walk : %d",++walk);
						map[characterX][characterY] = 8;
						Display(map[characterX][characterY], characterX, characterY);
						refresh();
					}
				}
				else if (map[characterX][characterY+1] == 2){
					if(characterY >= 7){

					}
					else if(map[characterX][characterY+2] == 1){

					}
					else if(map[characterX][characterY+2] == 2){

					}
					else if(map[characterX][characterY+2] == 3){
						if(map[characterX][characterY] == 8){
							map[characterX][characterY] = 3;
							Display(map[characterX][characterY], characterX, characterY);
							characterY = characterY+1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 5;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
							
							map[characterX][characterY+1] = 7;
							Display(map[characterX][characterY+1], characterX, characterY+1);
							refresh();
							bool_end = define_End(map);
						}
						else{
							map[characterX][characterY] = 4;
							Display(map[characterX][characterY], characterX, characterY);
							characterY = characterY+1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 5;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
							
							map[characterX][characterY+1] = 7;
							Display(map[characterX][characterY+1], characterX, characterY+1);
							refresh();
							bool_end = define_End(map);
						}
					}
					else if(map[characterX][characterY+2] == 4){
						if(map[characterX][characterY] == 8){
							map[characterX][characterY] = 3;
							Display(map[characterX][characterY], characterX, characterY);
							characterY = characterY+1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 5;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
							
							map[characterX][characterY+1] = 2;
							Display(map[characterX][characterY+1], characterX, characterY+1);
							refresh();
							bool_end = define_End(map);
						}
						else{
							map[characterX][characterY] = 4;
							Display(map[characterX][characterY], characterX, characterY);
							characterY = characterY+1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 5;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
							
							map[characterX][characterY+1] = 2;
							Display(map[characterX][characterY+1], characterX, characterY+1);
							refresh();
							bool_end = define_End(map);
						
						}
					}
				}

				else if (map[characterX][characterY+1] == 7){
					if(characterY >= 7){

					}
					else if(map[characterX][characterY+2] == 1){

					}
					else if(map[characterX][characterY+2] == 2){

					}
					else if(map[characterX][characterY+2] == 3){
						if(map[characterX][characterY] == 8){
							map[characterX][characterY] = 3;
							Display(map[characterX][characterY], characterX, characterY);
							characterY = characterY+1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 8;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
							
							map[characterX][characterY+1] = 7;
							Display(map[characterX][characterY+1], characterX, characterY+1);
							refresh();
							bool_end = define_End(map);
						}
						else{
							map[characterX][characterY] = 4;
							Display(map[characterX][characterY], characterX, characterY);
							characterY = characterY+1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 8;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
							map[characterX][characterY+1] = 7;
 							Display(map[characterX][characterY+1], characterX, characterY+1);
							refresh();
							bool_end = define_End(map);
						}
					}
					else if(map[characterX][characterY+2] == 4){
						if(map[characterX][characterY] == 8){
							map[characterX][characterY] = 3;
							Display(map[characterX][characterY], characterX, characterY);
							characterY = characterY+1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 8;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
							map[characterX][characterY+1] = 2;
 							Display(map[characterX][characterY+1], characterX, characterY+1);
							refresh();
							bool_end = define_End(map);
						}
						else{
						
							map[characterX][characterY] = 4;
							Display(map[characterX][characterY], characterX, characterY);
							characterY = characterY+1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 8;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
							map[characterX][characterY+1] = 2;
 							Display(map[characterX][characterY+1], characterX, characterY+1);
							refresh();
							bool_end = define_End(map);
						
						}
					}
				}
				break;
			case KEY_UP:
				if(characterX == 1){
				
				}
				else if (map[characterX-1][characterY] == 1){

				}
				else if (map[characterX-1][characterY] == 4){
					if(map[characterX][characterY] == 8){
						map[characterX][characterY] = 3;
						Display(map[characterX][characterY], characterX, characterY);
						characterX = characterX-1;
						mvprintw(8, 15,"Walk : %d",++walk);
						map[characterX][characterY] = 5;
						Display(map[characterX][characterY], characterX, characterY);
						refresh();
					}
					else{
						map[characterX][characterY] = 4;
						Display(map[characterX][characterY], characterX, characterY);
						characterX = characterX-1;
						mvprintw(8, 15,"Walk : %d",++walk);
						map[characterX][characterY] = 5;
						Display(map[characterX][characterY], characterX, characterY);
						refresh();
					}
				}
				else if (map[characterX-1][characterY] == 3){
						if(map[characterX][characterY] == 8){
						map[characterX][characterY] = 3;
						Display(map[characterX][characterY], characterX, characterY);
						characterX = characterX-1;
						mvprintw(8, 15,"Walk : %d",++walk);
						map[characterX][characterY] = 8;
						Display(map[characterX][characterY], characterX, characterY);
						refresh();
					}
					else{
						map[characterX][characterY] = 4;
						Display(map[characterX][characterY], characterX, characterY);
						characterX = characterX-1;
						mvprintw(8, 15,"Walk : %d",++walk);
						map[characterX][characterY] = 8;
						Display(map[characterX][characterY], characterX, characterY);
						refresh();
					}
				}
				else if (map[characterX-1][characterY] == 2){
					if(characterX <= 2){

					}
					else if(map[characterX-2][characterY] == 1){

					}
					else if(map[characterX-2][characterY] == 2){

					}
					else if(map[characterX-2][characterY] == 3){
						if(map[characterX][characterY] == 8){
							map[characterX][characterY] = 3;
							Display(map[characterX][characterY], characterX, characterY);
							characterX = characterX-1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 5;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
 							map[characterX-1][characterY] = 7;
							Display(map[characterX-1][characterY], characterX-1, characterY);
							refresh();
							bool_end = define_End(map);
						}
						else{
							map[characterX][characterY] = 4;
							Display(map[characterX][characterY], characterX, characterY);
							characterX = characterX-1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 5;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
 							map[characterX-1][characterY] = 7;
							Display(map[characterX-1][characterY], characterX-1, characterY);
							refresh();
							bool_end = define_End(map);
						}
					}
					else if(map[characterX-2][characterY] == 4){
						if(map[characterX][characterY] == 8){
							map[characterX][characterY] = 3;
							Display(map[characterX][characterY], characterX, characterY);
							characterX = characterX-1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 5;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
 							map[characterX-1][characterY] = 2;
							Display(map[characterX-1][characterY], characterX-1, characterY);
							refresh();
							bool_end = define_End(map);
						}
						else{
							map[characterX][characterY] = 4;
							Display(map[characterX][characterY], characterX, characterY);
							characterX = characterX-1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 5;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
 							map[characterX-1][characterY] = 2;
							Display(map[characterX-1][characterY], characterX-1, characterY);
							refresh();
							bool_end = define_End(map);
						
						}
					}
				}

				else if (map[characterX-1][characterY] == 7){
					if(characterX <= 2){

					}
					else if(map[characterX-2][characterY] == 1){

					}
					else if(map[characterX-2][characterY] == 2){

					}
					else if(map[characterX-2][characterY] == 3){
						if(map[characterX][characterY] == 8){
							map[characterX][characterY] = 3;
							Display(map[characterX][characterY], characterX, characterY);
							characterX = characterX-1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 8;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
 							map[characterX-1][characterY] = 7;
							Display(map[characterX-1][characterY], characterX-1, characterY);
							refresh();
							bool_end = define_End(map);
						}
						else{
							map[characterX][characterY] = 4;
							Display(map[characterX][characterY], characterX, characterY);
							characterX = characterX-1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 8;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
 							map[characterX-1][characterY] = 7;
							Display(map[characterX-1][characterY], characterX-1, characterY);
							refresh();
							bool_end = define_End(map);
						}
					}
					else if(map[characterX-2][characterY] == 4){
						if(map[characterX][characterY] == 8){
							map[characterX][characterY] = 3;
							Display(map[characterX][characterY], characterX, characterY);
							characterX = characterX-1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 8;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
							map[characterX-1][characterY] = 2;
 							Display(map[characterX-1][characterY], characterX-1, characterY);
							refresh();
							bool_end = define_End(map);
						}
						else{
						
							map[characterX][characterY] = 4;
							Display(map[characterX][characterY], characterX, characterY);
							characterX = characterX-1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 8;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
							map[characterX-1][characterY] = 2;
 							Display(map[characterX-1][characterY], characterX-1, characterY);
							refresh();
							bool_end = define_End(map);
						
						}
					}
				}
				break;
			case KEY_DOWN:
				if(characterX == 7){
				
				}
				else if (map[characterX+1][characterY] == 1){

				}
				else if (map[characterX+1][characterY] == 4){
					if(map[characterX][characterY] == 8){
						map[characterX][characterY] = 3;
						Display(map[characterX][characterY], characterX, characterY);
						characterX = characterX+1;
						mvprintw(8, 15,"Walk : %d",++walk);
						map[characterX][characterY] = 5;
						Display(map[characterX][characterY], characterX, characterY);
						refresh();
					}
					else{
						map[characterX][characterY] = 4;
						Display(map[characterX][characterY], characterX, characterY);
						characterX = characterX+1;
						mvprintw(8, 15,"Walk : %d",++walk);
						map[characterX][characterY] = 5;
						Display(map[characterX][characterY], characterX, characterY);
						refresh();
					}
				}
				else if (map[characterX+1][characterY] == 3){
						if(map[characterX][characterY] == 8){
						map[characterX][characterY] = 3;
						Display(map[characterX][characterY], characterX, characterY);
						characterX = characterX+1;
						mvprintw(8, 15,"Walk : %d",++walk);
						map[characterX][characterY] = 8;
						Display(map[characterX][characterY], characterX, characterY);
						refresh();
					}
					else{
						map[characterX][characterY] = 4;
						Display(map[characterX][characterY], characterX, characterY);
						characterX = characterX+1;
						mvprintw(8, 15,"Walk : %d",++walk);
						map[characterX][characterY] = 8;
						Display(map[characterX][characterY], characterX, characterY);
						refresh();
					}
				}
				else if (map[characterX+1][characterY] == 2){
					if(characterX >= 7){

					}
					else if(map[characterX+2][characterY] == 1){

					}
					else if(map[characterX+2][characterY] == 2){

					}
					else if(map[characterX+2][characterY] == 3){
						if(map[characterX][characterY] == 8){
							map[characterX][characterY] = 3;
							Display(map[characterX][characterY], characterX, characterY);
							characterX = characterX+1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 5;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
 							map[characterX+1][characterY] = 7;
							Display(map[characterX+1][characterY], characterX+1, characterY);
							refresh();
							bool_end = define_End(map);
						}
						else{
							map[characterX][characterY] = 4;
							Display(map[characterX][characterY], characterX, characterY);
							characterX = characterX+1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 5;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
 							map[characterX+1][characterY] = 7;
							Display(map[characterX+1][characterY], characterX+1, characterY);
							refresh();
							bool_end = define_End(map);
						}
					}
					else if(map[characterX+2][characterY] == 4){
						if(map[characterX][characterY] == 8){
							map[characterX][characterY] = 3;
							Display(map[characterX][characterY], characterX, characterY);
							characterX = characterX+1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 5;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
 							map[characterX+1][characterY] = 2;
							Display(map[characterX+1][characterY], characterX+1, characterY);
							refresh();
							bool_end = define_End(map);
						}
						else{
							map[characterX][characterY] = 4;
							Display(map[characterX][characterY], characterX, characterY);
							characterX = characterX+1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 5;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
 							map[characterX+1][characterY] = 2;
							Display(map[characterX+1][characterY], characterX+1, characterY);
							refresh();
							bool_end = define_End(map);
						
						}
					}
				}

				else if (map[characterX+1][characterY] == 7){
					if(characterX >= 7){

					}
					else if(map[characterX+2][characterY] == 1){

					}
					else if(map[characterX+2][characterY] == 2){

					}
					else if(map[characterX+2][characterY] == 3){
						if(map[characterX][characterY] == 8){
							map[characterX][characterY] = 3;
							Display(map[characterX][characterY], characterX, characterY);
							characterX = characterX+1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 8;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
							map[characterX+1][characterY] = 7;
 							Display(map[characterX+1][characterY], characterX+1, characterY);
							refresh();
							bool_end = define_End(map);
						}
						else{
							map[characterX][characterY] = 4;
							Display(map[characterX][characterY], characterX, characterY);
							characterX = characterX+1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 8;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
							map[characterX+1][characterY] = 7;
 							Display(map[characterX+1][characterY], characterX+1, characterY);
							refresh();
							bool_end = define_End(map);
						}
					}
					else if(map[characterX+2][characterY] == 4){
						if(map[characterX][characterY] == 8){
							map[characterX][characterY] = 3;
							Display(map[characterX][characterY], characterX, characterY);
							characterX = characterX+1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 8;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
							map[characterX+1][characterY] = 2;
 							Display(map[characterX+1][characterY], characterX+1, characterY);
							refresh();
							bool_end = define_End(map);
						}
						else{
						
							map[characterX][characterY] = 4;
							Display(map[characterX][characterY], characterX, characterY);
							characterX = characterX+1;
							mvprintw(8, 15,"Walk : %d",++walk);
							map[characterX][characterY] = 8;
							Display(map[characterX][characterY], characterX, characterY);
							mvprintw(7, 15,"Box : %d",++move_box);
							map[characterX+1][characterY] = 2;
 							Display(map[characterX+1][characterY], characterX+1, characterY);
							refresh();
							bool_end = define_End(map);
						}
					}
				}
				break;
		}
	}
    move_box = 0;
    walk = 0;
    
}
void Display(int map_Position, int characterX, int characterY)
{
	//color setting

	init_pair(0,COLOR_BLACK,COLOR_BLACK);
	init_pair(1,COLOR_WHITE,COLOR_WHITE);
	init_pair(2,COLOR_CYAN,COLOR_CYAN);
	init_pair(3,COLOR_GREEN,COLOR_BLACK);
	init_pair(4,COLOR_BLACK,COLOR_BLACK);
	init_pair(5,COLOR_YELLOW,COLOR_BLACK);
	
	switch(map_Position)
	{
		case 1://wall
			attron(COLOR_PAIR(1));
			mvprintw(characterX+10,characterY+10," ");
			attron(COLOR_PAIR(5));
			break;
		case 2:
			attron(COLOR_PAIR(2));
			mvprintw(characterX+10,characterY+10," ");
			attron(COLOR_PAIR(5));
			break;
		case 7://box on goal
			attron(COLOR_PAIR(2));
			mvprintw(characterX+10,characterY+10," ");
			attron(COLOR_PAIR(5));
			break;
		case 3://goal
			attron(COLOR_PAIR(3));
			mvprintw(characterX+10,characterY+10,"X");
			attron(COLOR_PAIR(5));
			break;
		case 4://background
			attron(COLOR_PAIR(4));
			mvprintw(characterX+10,characterY+10," ");
			attron(COLOR_PAIR(5));
			break;
		case 5:
			attron(COLOR_PAIR(5));
			mvprintw(characterX+10,characterY+10,"O");
			attron(COLOR_PAIR(5));
			break;
		case 8://character on goal
			attron(COLOR_PAIR(5));
			mvprintw(characterX+10,characterY+10,"O");
			attron(COLOR_PAIR(5));
			break;
	}	
}

