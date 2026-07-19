#pragma once                            //tells the compiler to compile this file only once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef int8 bitmap;

bitmap *mkbmp(int16);
void zero(int8*,int16);
void setbit(bitmap*,int16,bool);
bool getbit(bitmap*,int16);

#define $c (char *)
#define $i (int)
#define $1 (int8 *)
#define $2 (int16)
#define $4 (int32)


