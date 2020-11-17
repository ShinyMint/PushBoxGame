#ifndef SOKOBAN_H
#define SOKOBAN_H
//loading a txt file
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

//standard library
#include <iostream>
#include <string>
#include <stdlib.h>

//using ncurses.h
#include <ncurses.h>

void Building_Maze();
void Move_Character(int map[][11]);
void Display(int map_Position, int characterX, int characterY);
void Beep();
bool define_End( int map[][11]);
#endif
