#include "sokoban.h"
bool define_End(int map[][11]){
	for(int a=0;a<11;a++)
		{
			for(int b=0;b<11;b++)
				{
					if(map[a][b] == 2 || map[a][b] == 8){
						return false;
					}
				}
			}
	return true;
}
void Beep(){
	std::cout << "\a" <<std::flush;//this method creates beep sound
}
