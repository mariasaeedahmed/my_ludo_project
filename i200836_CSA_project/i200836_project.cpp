//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
//#include "Board.h"
#include "util.h"
#include <iostream>
#include<string>
#include<cstdlib>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
 int number_of_players;
 //ALL THE PLACES WHERE THE TOKENS CAN MOVE
 //X AXIS
int r1_x[]={120,415+30,415+30,415+30,415+30,415+30,/*FIRST BLUE*/325+30,260+30,195+30,130+30,65+30,30,/*CLIMB UP*/30,/*SECOND BLUE*/30,30+65,30+65*2,30+65*3,30+65*4,30+65*5,/*FIRST YELLOW*/447,447,447,447,447,447,/*CLIMB UP*/480+30,/*SECOND YELLOW*/480+65+30,480+65+30,480+65+30,480+65+30,480+65+30,480+65+30,/*FIRST GREEN*/1020-(65*6)+31,1020-(65*5)+31,1020-(65*4)+31,1020-(65*3)+31,1020-(65*2)+31,1020-(65*1)+31,1020-(65*1)+31,/*CLIMB UP*/1020-(65*1)+/*SECOND GREEN*/31,1020-(65*2)+31,1020-(65*3)+31,1020-(65*4)+31,1020-(65*5)+31,1020-(65*6)+31,/*back home*/415+30+65+65,575,575,575,575,575,575-65,510,510,510,510,510,510};
//Y-AXIS
int r1_y[]{100,/*FIRST RED*/65+25,65*2+25,65*3+25,65*4+25,65*5+25,/*FIRST BLUE*/427,427,427,427,427,427,/*CLIMB UP*/425+65,/*SECOND BLUE*/427+65*2,427+65*2,427+65*2,427+65*2,427+65*2,427+65*2,/* FIRST YELLOW*/935-65*5+25,935-65*4+25,935-65*3+25,935-65*2+25,935-65+25,935+25,/*CLIMB UP*/935+25,/*SECOND YELLOW*/935+25,935-65+30,935-65*2+30,935-65*3+30,935-65*4+30,935-65*5+30,/*FIRST GREEN*/530+27,530+27,530+27,530+27,530+27,530+27,530+27-65,/*SECOND GREEN*/530+27-65-65,427,427,427,427,427/*back home*/,65*5+25,65*4+25,65*3+25,65*2+25,65+25,25,/*GOING INTO HOME*/25,65+25,65*2+25,65*3+25,65*4+25,65*5+25,65*6+25};
//X AXIS

int b1_x[]={120,30+65,30+65*2,30+65*3,30+65*4,30+65*5,/*FIRST YELLOW*/447,447,447,447,447,447,/*CLIMB UP*/480+30,/*SECOND YELLOW*/480+65+30,480+65+30,480+65+30,480+65+30,480+65+30,480+65+30,/*FIRST GREEN*/1020-(65*6)+31,1020-(65*5)+31,1020-(65*4)+31,1020-(65*3)+31,1020-(65*2)+31,1020-(65*1)+31,1020-(65*1)+31,/*CLIMB UP*/1020-(65*1)+/*SECOND GREEN*/31,1020-(65*2)+31,1020-(65*3)+31,1020-(65*4)+31,1020-(65*5)+31,1020-(65*6)+31,/*RED*/415+30+65+65,575,575,575,575,575,575-65,575-65-65,415+30,415+30,415+30,415+30,415+30,/*FIRST BLUE*/325+30,260+30,195+30,130+30,65+30,30,/*CLIMB UP*/30,/*intohome*/30+65,30+65*2,30+65*3,30+65*4,30+65*5,30+65*6};
int b1_y[]={700,427+65*2,427+65*2,427+65*2,427+65*2,427+65*2,/* FIRST YELLOW*/935-65*5+25,935-65*4+25,935-65*3+25,935-65*2+25,935-65+25,935+25,/*CLIMB UP*/935+25,/*SECOND YELLOW*/935+25,935-65+30,935-65*2+30,935-65*3+30,935-65*4+30,935-65*5+30,/*FIRST GREEN*/530+27,530+27,530+27,530+27,530+27,530+27,530+27-65,/*SECOND GREEN*/530+27-65-65,427,427,427,427,427/*RED*/,65*5+25,65*4+25,65*3+25,65*2+25,65+25,25,25,25,/*FIRST RED*/65+25,65*2+25,65*3+25,65*4+25,65*5+25,/*FIRST BLUE*/427,427,427,427,427,427,/*CLIMB UP*/425+65,/*INTOHOME*/427+65,427+65,427+65,427+65,427+65,427+65};


int g1_x[]={700,1020-(65*2)+31,1020-(65*3)+31,1020-(65*4)+31,1020-(65*5)+31,1020-(65*6)+31/*RED SIDE*/,415+30+65+65,575,575,575,575,575,575-65,575-65-65,415+30,415+30,415+30,415+30,415+30,/*FIRST BLUE*/325+30,260+30,195+30,130+30,65+30,30,/*CLIMB UP*/30,/*SECOND BLUE*/30,30+65,30+65*2,30+65*3,30+65*4,30+65*5,/*FIRST YELLOW*/447,447,447,447,447,447,/*CLIMB UP*/480+30,/*SECOND YELLOW*/480+65+30,480+65+30,480+65+30,480+65+30,480+65+30,480+65+30,/*FIRST GREEN*/1020-(65*6)+31,1020-(65*5)+31,1020-(65*4)+31,1020-(65*3)+31,1020-(65*2)+31,1020-(65*1)+31,1020-(65*1)+31,/*CLIMB DOWN*/1020-(65*1)+31,/*INTO HOME*/1020-(65*2)+31,1020-(65*3)+31,1020-(65*4)+31,1020-(65*5)+31,1020-(65*6)+31};
int g1_y[]={100,427,427,427,427,427,/*RED LAST*/65*5+25,65*4+25,65*3+25,65*2+25,65+25,25,25,25,/*FIRST RED*/65+25,65*2+25,65*3+25,65*4+25,65*5+25,/*FIRST BLUE*/427,427,427,427,427,427,/*CLIMB UP*/425+65/*SEOND BLUE*/,427+65*2,427+65*2,427+65*2,427+65*2,427+65*2,427+65*2,/* FIRST YELLOW*/935-65*5+25,935-65*4+25,935-65*3+25,935-65*2+25,935-65+25,935+25,/*CLIMB UP*/935+25,/*SECOND YELLOW*/935+25,935-65+30,935-65*2+30,935-65*3+30,935-65*4+30,935-65*5+30,/*FIRST GREEN*/530+27,530+27,530+27,530+27,530+27,530+27,530+27-65/*INTO HOME*/,530+27-65,510,510,510,510,510};


int y1_x[]={730,480+65+30,480+65+30,480+65+30,480+65+30,480+65+30,/*FIRST GREEN*/1020-(65*6)+31,1020-(65*5)+31,1020-(65*4)+31,1020-(65*3)+31,1020-(65*2)+31,1020-(65*1)+31,1020-(65*1)+31,/*CLIMB DOWN*/1020-(65*1)+31,/*SECOND GREEN*/ 1020-(65*2)+31,1020-(65*3)+31,1020-(65*4)+31,1020-(65*5)+31,1020-(65*6)+31/*RED SIDE*/,415+30+65+65,575,575,575,575,575,575-65,575-65-65,415+30,415+30,415+30,415+30,415+30,/*FIRST BLUE*/325+30,260+30,195+30,130+30,65+30,30,/*CLIMB UP*/30,/*SECOND BLUE*/30,30+65,30+65*2,30+65*3,30+65*4,30+65*5,/*FIRST YELLOW*/447,447,447,447,447,447,/*CLIMB UP*/480+30,/*INTO HOME*/480+30,480+30,480+30,480+30,480+30,480+30};
int y1_y[]={900,935-65+30,935-65*2+30,935-65*3+30,935-65*4+30,935-65*5+30,/*FIRST GREEN*/530+27,530+27,530+27,530+27,530+27,530+27,530+27-65,/*SECOND GREEN*/427,427,427,427,427,427,/*RED LAST*/65*5+25,65*4+25,65*3+25,65*2+25,65+25,25,25,25,/*FIRST RED*/65+25,65*2+25,65*3+25,65*4+25,65*5+25,/*FIRST BLUE*/427,427,427,427,427,427,/*CLIMB UP*/425+65/*SEOND BLUE*/,427+65*2,427+65*2,427+65*2,427+65*2,427+65*2,427+65*2,/* FIRST YELLOW*/935-65*5+25,935-65*4+25,935-65*3+25,935-65*2+25,935-65+25,935+25,/*CLIMB UP*/935+25/*INTO HOME*/,935-65+30,935-65*2+30,935-65*3+30,935-65*4+30,935-65*5+30,935-65*6+30};


int r2_x[]={275,415+30,415+30,415+30,415+30,415+30,/*FIRST BLUE*/325+30,260+30,195+30,130+30,65+30,30,/*CLIMB UP*/30,/*SECOND BLUE*/30,30+65,30+65*2,30+65*3,30+65*4,30+65*5,/*FIRST YELLOW*/447,447,447,447,447,447,/*CLIMB UP*/480+30,/*SECOND YELLOW*/480+65+30,480+65+30,480+65+30,480+65+30,480+65+30,480+65+30,/*FIRST GREEN*/1020-(65*6)+31,1020-(65*5)+31,1020-(65*4)+31,1020-(65*3)+31,1020-(65*2)+31,1020-(65*1)+31,1020-(65*1)+31,/*CLIMB UP*/1020-(65*1)+/*SECOND GREEN*/31,1020-(65*2)+31,1020-(65*3)+31,1020-(65*4)+31,1020-(65*5)+31,1020-(65*6)+31,/*back home*/415+30+65+65,575,575,575,575,575,575-65,510,510,510,510,510,510};
//Y-AXIS
int r2_y[]{100,/*FIRST RED*/65+25,65*2+25,65*3+25,65*4+25,65*5+25,/*FIRST BLUE*/427,427,427,427,427,427,/*CLIMB UP*/425+65,/*SECOND BLUE*/427+65*2,427+65*2,427+65*2,427+65*2,427+65*2,427+65*2,/* FIRST YELLOW*/935-65*5+25,935-65*4+25,935-65*3+25,935-65*2+25,935-65+25,935+25,/*CLIMB UP*/935+25,/*SECOND YELLOW*/935+25,935-65+30,935-65*2+30,935-65*3+30,935-65*4+30,935-65*5+30,/*FIRST GREEN*/530+27,530+27,530+27,530+27,530+27,530+27,530+27-65,/*SECOND GREEN*/530+27-65-65,427,427,427,427,427/*back home*/,65*5+25,65*4+25,65*3+25,65*2+25,65+25,25,/*GOING INTO HOME*/25,65+25,65*2+25,65*3+25,65*4+25,65*5+25,65*6+25};
//X AXIS
int r3_x[]={275,415+30,415+30,415+30,415+30,415+30,/*FIRST BLUE*/325+30,260+30,195+30,130+30,65+30,30,/*CLIMB UP*/30,/*SECOND BLUE*/30,30+65,30+65*2,30+65*3,30+65*4,30+65*5,/*FIRST YELLOW*/447,447,447,447,447,447,/*CLIMB UP*/480+30,/*SECOND YELLOW*/480+65+30,480+65+30,480+65+30,480+65+30,480+65+30,480+65+30,/*FIRST GREEN*/1020-(65*6)+31,1020-(65*5)+31,1020-(65*4)+31,1020-(65*3)+31,1020-(65*2)+31,1020-(65*1)+31,1020-(65*1)+31,/*CLIMB UP*/1020-(65*1)+/*SECOND GREEN*/31,1020-(65*2)+31,1020-(65*3)+31,1020-(65*4)+31,1020-(65*5)+31,1020-(65*6)+31,/*back home*/415+30+65+65,575,575,575,575,575,575-65,510,510,510,510,510,510};
//Y-AXIS
int r3_y[]{270,/*FIRST RED*/65+25,65*2+25,65*3+25,65*4+25,65*5+25,/*FIRST BLUE*/427,427,427,427,427,427,/*CLIMB UP*/425+65,/*SECOND BLUE*/427+65*2,427+65*2,427+65*2,427+65*2,427+65*2,427+65*2,/* FIRST YELLOW*/935-65*5+25,935-65*4+25,935-65*3+25,935-65*2+25,935-65+25,935+25,/*CLIMB UP*/935+25,/*SECOND YELLOW*/935+25,935-65+30,935-65*2+30,935-65*3+30,935-65*4+30,935-65*5+30,/*FIRST GREEN*/530+27,530+27,530+27,530+27,530+27,530+27,530+27-65,/*SECOND GREEN*/530+27-65-65,427,427,427,427,427/*back home*/,65*5+25,65*4+25,65*3+25,65*2+25,65+25,25,/*GOING INTO HOME*/25,65+25,65*2+25,65*3+25,65*4+25,65*5+25,65*6+25};
//X AXIS
int r4_x[]={120,415+30,415+30,415+30,415+30,415+30,/*FIRST BLUE*/325+30,260+30,195+30,130+30,65+30,30,/*CLIMB UP*/30,/*SECOND BLUE*/30,30+65,30+65*2,30+65*3,30+65*4,30+65*5,/*FIRST YELLOW*/447,447,447,447,447,447,/*CLIMB UP*/480+30,/*SECOND YELLOW*/480+65+30,480+65+30,480+65+30,480+65+30,480+65+30,480+65+30,/*FIRST GREEN*/1020-(65*6)+31,1020-(65*5)+31,1020-(65*4)+31,1020-(65*3)+31,1020-(65*2)+31,1020-(65*1)+31,1020-(65*1)+31,/*CLIMB UP*/1020-(65*1)+/*SECOND GREEN*/31,1020-(65*2)+31,1020-(65*3)+31,1020-(65*4)+31,1020-(65*5)+31,1020-(65*6)+31,/*back home*/415+30+65+65,575,575,575,575,575,575-65,510,510,510,510,510,510};
//Y-AXIS
int r4_y[]{270,/*FIRST RED*/65+25,65*2+25,65*3+25,65*4+25,65*5+25,/*FIRST BLUE*/427,427,427,427,427,427,/*CLIMB UP*/425+65,/*SECOND BLUE*/427+65*2,427+65*2,427+65*2,427+65*2,427+65*2,427+65*2,/* FIRST YELLOW*/935-65*5+25,935-65*4+25,935-65*3+25,935-65*2+25,935-65+25,935+25,/*CLIMB UP*/935+25,/*SECOND YELLOW*/935+25,935-65+30,935-65*2+30,935-65*3+30,935-65*4+30,935-65*5+30,/*FIRST GREEN*/530+27,530+27,530+27,530+27,530+27,530+27,530+27-65,/*SECOND GREEN*/530+27-65-65,427,427,427,427,427/*back home*/,65*5+25,65*4+25,65*3+25,65*2+25,65+25,25,/*GOING INTO HOME*/25,65+25,65*2+25,65*3+25,65*4+25,65*5+25,65*6+25};

int b2_x[]={300,30+65,30+65*2,30+65*3,30+65*4,30+65*5,/*FIRST YELLOW*/447,447,447,447,447,447,/*CLIMB UP*/480+30,/*SECOND YELLOW*/480+65+30,480+65+30,480+65+30,480+65+30,480+65+30,480+65+30,/*FIRST GREEN*/1020-(65*6)+31,1020-(65*5)+31,1020-(65*4)+31,1020-(65*3)+31,1020-(65*2)+31,1020-(65*1)+31,1020-(65*1)+31,/*CLIMB UP*/1020-(65*1)+/*SECOND GREEN*/31,1020-(65*2)+31,1020-(65*3)+31,1020-(65*4)+31,1020-(65*5)+31,1020-(65*6)+31,/*RED*/415+30+65+65,575,575,575,575,575,575-65,575-65-65,415+30,415+30,415+30,415+30,415+30,/*FIRST BLUE*/325+30,260+30,195+30,130+30,65+30,30,/*CLIMB UP*/30,/*intohome*/30+65,30+65*2,30+65*3,30+65*4,30+65*5,30+65*6};
int b2_y[]={700,427+65*2,427+65*2,427+65*2,427+65*2,427+65*2,/* FIRST YELLOW*/935-65*5+25,935-65*4+25,935-65*3+25,935-65*2+25,935-65+25,935+25,/*CLIMB UP*/935+25,/*SECOND YELLOW*/935+25,935-65+30,935-65*2+30,935-65*3+30,935-65*4+30,935-65*5+30,/*FIRST GREEN*/530+27,530+27,530+27,530+27,530+27,530+27,530+27-65,/*SECOND GREEN*/530+27-65-65,427,427,427,427,427/*RED*/,65*5+25,65*4+25,65*3+25,65*2+25,65+25,25,25,25,/*FIRST RED*/65+25,65*2+25,65*3+25,65*4+25,65*5+25,/*FIRST BLUE*/427,427,427,427,427,427,/*CLIMB UP*/425+65,/*INTOHOME*/427+65,427+65,427+65,427+65,427+65,427+65};
int b3_x[]={125,30+65,30+65*2,30+65*3,30+65*4,30+65*5,/*FIRST YELLOW*/447,447,447,447,447,447,/*CLIMB UP*/480+30,/*SECOND YELLOW*/480+65+30,480+65+30,480+65+30,480+65+30,480+65+30,480+65+30,/*FIRST GREEN*/1020-(65*6)+31,1020-(65*5)+31,1020-(65*4)+31,1020-(65*3)+31,1020-(65*2)+31,1020-(65*1)+31,1020-(65*1)+31,/*CLIMB UP*/1020-(65*1)+/*SECOND GREEN*/31,1020-(65*2)+31,1020-(65*3)+31,1020-(65*4)+31,1020-(65*5)+31,1020-(65*6)+31,/*RED*/415+30+65+65,575,575,575,575,575,575-65,575-65-65,415+30,415+30,415+30,415+30,415+30,/*FIRST BLUE*/325+30,260+30,195+30,130+30,65+30,30,/*CLIMB UP*/30,/*intohome*/30+65,30+65*2,30+65*3,30+65*4,30+65*5,30+65*6};
int b3_y[]={900,427+65*2,427+65*2,427+65*2,427+65*2,427+65*2,/* FIRST YELLOW*/935-65*5+25,935-65*4+25,935-65*3+25,935-65*2+25,935-65+25,935+25,/*CLIMB UP*/935+25,/*SECOND YELLOW*/935+25,935-65+30,935-65*2+30,935-65*3+30,935-65*4+30,935-65*5+30,/*FIRST GREEN*/530+27,530+27,530+27,530+27,530+27,530+27,530+27-65,/*SECOND GREEN*/530+27-65-65,427,427,427,427,427/*RED*/,65*5+25,65*4+25,65*3+25,65*2+25,65+25,25,25,25,/*FIRST RED*/65+25,65*2+25,65*3+25,65*4+25,65*5+25,/*FIRST BLUE*/427,427,427,427,427,427,/*CLIMB UP*/425+65,/*INTOHOME*/427+65,427+65,427+65,427+65,427+65,427+65};
int b4_x[]={300,30+65,30+65*2,30+65*3,30+65*4,30+65*5,/*FIRST YELLOW*/447,447,447,447,447,447,/*CLIMB UP*/480+30,/*SECOND YELLOW*/480+65+30,480+65+30,480+65+30,480+65+30,480+65+30,480+65+30,/*FIRST GREEN*/1020-(65*6)+31,1020-(65*5)+31,1020-(65*4)+31,1020-(65*3)+31,1020-(65*2)+31,1020-(65*1)+31,1020-(65*1)+31,/*CLIMB UP*/1020-(65*1)+/*SECOND GREEN*/31,1020-(65*2)+31,1020-(65*3)+31,1020-(65*4)+31,1020-(65*5)+31,1020-(65*6)+31,/*RED*/415+30+65+65,575,575,575,575,575,575-65,575-65-65,415+30,415+30,415+30,415+30,415+30,/*FIRST BLUE*/325+30,260+30,195+30,130+30,65+30,30,/*CLIMB UP*/30,/*intohome*/30+65,30+65*2,30+65*3,30+65*4,30+65*5,30+65*6};
int b4_y[]={900,427+65*2,427+65*2,427+65*2,427+65*2,427+65*2,/* FIRST YELLOW*/935-65*5+25,935-65*4+25,935-65*3+25,935-65*2+25,935-65+25,935+25,/*CLIMB UP*/935+25,/*SECOND YELLOW*/935+25,935-65+30,935-65*2+30,935-65*3+30,935-65*4+30,935-65*5+30,/*FIRST GREEN*/530+27,530+27,530+27,530+27,530+27,530+27,530+27-65,/*SECOND GREEN*/530+27-65-65,427,427,427,427,427/*RED*/,65*5+25,65*4+25,65*3+25,65*2+25,65+25,25,25,25,/*FIRST RED*/65+25,65*2+25,65*3+25,65*4+25,65*5+25,/*FIRST BLUE*/427,427,427,427,427,427,/*CLIMB UP*/425+65,/*INTOHOME*/427+65,427+65,427+65,427+65,427+65,427+65};




int y2_x[]={730,480+65+30,480+65+30,480+65+30,480+65+30,480+65+30,/*FIRST GREEN*/1020-(65*6)+31,1020-(65*5)+31,1020-(65*4)+31,1020-(65*3)+31,1020-(65*2)+31,1020-(65*1)+31,1020-(65*1)+31,/*CLIMB DOWN*/1020-(65*1)+31,/*SECOND GREEN*/ 1020-(65*2)+31,1020-(65*3)+31,1020-(65*4)+31,1020-(65*5)+31,1020-(65*6)+31/*RED SIDE*/,415+30+65+65,575,575,575,575,575,575-65,575-65-65,415+30,415+30,415+30,415+30,415+30,/*FIRST BLUE*/325+30,260+30,195+30,130+30,65+30,30,/*CLIMB UP*/30,/*SECOND BLUE*/30,30+65,30+65*2,30+65*3,30+65*4,30+65*5,/*FIRST YELLOW*/447,447,447,447,447,447,/*CLIMB UP*/480+30,/*INTO HOME*/480+30,480+30,480+30,480+30,480+30,480+30};
int y2_y[]={700,935-65+30,935-65*2+30,935-65*3+30,935-65*4+30,935-65*5+30,/*FIRST GREEN*/530+27,530+27,530+27,530+27,530+27,530+27,530+27-65,/*SECOND GREEN*/427,427,427,427,427,427,/*RED LAST*/65*5+25,65*4+25,65*3+25,65*2+25,65+25,25,25,25,/*FIRST RED*/65+25,65*2+25,65*3+25,65*4+25,65*5+25,/*FIRST BLUE*/427,427,427,427,427,427,/*CLIMB UP*/425+65/*SEOND BLUE*/,427+65*2,427+65*2,427+65*2,427+65*2,427+65*2,427+65*2,/* FIRST YELLOW*/935-65*5+25,935-65*4+25,935-65*3+25,935-65*2+25,935-65+25,935+25,/*CLIMB UP*/935+25/*INTO HOME*/,935-65+30,935-65*2+30,935-65*3+30,935-65*4+30,935-65*5+30,935-65*6+30};
int y3_x[]={900,480+65+30,480+65+30,480+65+30,480+65+30,480+65+30,/*FIRST GREEN*/1020-(65*6)+31,1020-(65*5)+31,1020-(65*4)+31,1020-(65*3)+31,1020-(65*2)+31,1020-(65*1)+31,1020-(65*1)+31,/*CLIMB DOWN*/1020-(65*1)+31,/*SECOND GREEN*/ 1020-(65*2)+31,1020-(65*3)+31,1020-(65*4)+31,1020-(65*5)+31,1020-(65*6)+31/*RED SIDE*/,415+30+65+65,575,575,575,575,575,575-65,575-65-65,415+30,415+30,415+30,415+30,415+30,/*FIRST BLUE*/325+30,260+30,195+30,130+30,65+30,30,/*CLIMB UP*/30,/*SECOND BLUE*/30,30+65,30+65*2,30+65*3,30+65*4,30+65*5,/*FIRST YELLOW*/447,447,447,447,447,447,/*CLIMB UP*/480+30,/*INTO HOME*/480+30,480+30,480+30,480+30,480+30,480+30};
int y3_y[]={700,935-65+30,935-65*2+30,935-65*3+30,935-65*4+30,935-65*5+30,/*FIRST GREEN*/530+27,530+27,530+27,530+27,530+27,530+27,530+27-65,/*SECOND GREEN*/427,427,427,427,427,427,/*RED LAST*/65*5+25,65*4+25,65*3+25,65*2+25,65+25,25,25,25,/*FIRST RED*/65+25,65*2+25,65*3+25,65*4+25,65*5+25,/*FIRST BLUE*/427,427,427,427,427,427,/*CLIMB UP*/425+65/*SEOND BLUE*/,427+65*2,427+65*2,427+65*2,427+65*2,427+65*2,427+65*2,/* FIRST YELLOW*/935-65*5+25,935-65*4+25,935-65*3+25,935-65*2+25,935-65+25,935+25,/*CLIMB UP*/935+25/*INTO HOME*/,935-65+30,935-65*2+30,935-65*3+30,935-65*4+30,935-65*5+30,935-65*6+30};
int y4_x[]={900,480+65+30,480+65+30,480+65+30,480+65+30,480+65+30,/*FIRST GREEN*/1020-(65*6)+31,1020-(65*5)+31,1020-(65*4)+31,1020-(65*3)+31,1020-(65*2)+31,1020-(65*1)+31,1020-(65*1)+31,/*CLIMB DOWN*/1020-(65*1)+31,/*SECOND GREEN*/ 1020-(65*2)+31,1020-(65*3)+31,1020-(65*4)+31,1020-(65*5)+31,1020-(65*6)+31/*RED SIDE*/,415+30+65+65,575,575,575,575,575,575-65,575-65-65,415+30,415+30,415+30,415+30,415+30,/*FIRST BLUE*/325+30,260+30,195+30,130+30,65+30,30,/*CLIMB UP*/30,/*SECOND BLUE*/30,30+65,30+65*2,30+65*3,30+65*4,30+65*5,/*FIRST YELLOW*/447,447,447,447,447,447,/*CLIMB UP*/480+30,/*INTO HOME*/480+30,480+30,480+30,480+30,480+30,480+30};
int y4_y[]={900,935-65+30,935-65*2+30,935-65*3+30,935-65*4+30,935-65*5+30,/*FIRST GREEN*/530+27,530+27,530+27,530+27,530+27,530+27,530+27-65,/*SECOND GREEN*/427,427,427,427,427,427,/*RED LAST*/65*5+25,65*4+25,65*3+25,65*2+25,65+25,25,25,25,/*FIRST RED*/65+25,65*2+25,65*3+25,65*4+25,65*5+25,/*FIRST BLUE*/427,427,427,427,427,427,/*CLIMB UP*/425+65/*SEOND BLUE*/,427+65*2,427+65*2,427+65*2,427+65*2,427+65*2,427+65*2,/* FIRST YELLOW*/935-65*5+25,935-65*4+25,935-65*3+25,935-65*2+25,935-65+25,935+25,/*CLIMB UP*/935+25/*INTO HOME*/,935-65+30,935-65*2+30,935-65*3+30,935-65*4+30,935-65*5+30,935-65*6+30};
int g2_x[]={900,1020-(65*2)+31,1020-(65*3)+31,1020-(65*4)+31,1020-(65*5)+31,1020-(65*6)+31/*RED SIDE*/,415+30+65+65,575,575,575,575,575,575-65,575-65-65,415+30,415+30,415+30,415+30,415+30,/*FIRST BLUE*/325+30,260+30,195+30,130+30,65+30,30,/*CLIMB UP*/30,/*SECOND BLUE*/30,30+65,30+65*2,30+65*3,30+65*4,30+65*5,/*FIRST YELLOW*/447,447,447,447,447,447,/*CLIMB UP*/480+30,/*SECOND YELLOW*/480+65+30,480+65+30,480+65+30,480+65+30,480+65+30,480+65+30,/*FIRST GREEN*/1020-(65*6)+31,1020-(65*5)+31,1020-(65*4)+31,1020-(65*3)+31,1020-(65*2)+31,1020-(65*1)+31,1020-(65*1)+31,/*CLIMB DOWN*/1020-(65*1)+31,/*INTO HOME*/1020-(65*2)+31,1020-(65*3)+31,1020-(65*4)+31,1020-(65*5)+31,1020-(65*6)+31};
int g2_y[]={270,427,427,427,427,427,/*RED LAST*/65*5+25,65*4+25,65*3+25,65*2+25,65+25,25,25,25,/*FIRST RED*/65+25,65*2+25,65*3+25,65*4+25,65*5+25,/*FIRST BLUE*/427,427,427,427,427,427,/*CLIMB UP*/425+65/*SEOND BLUE*/,427+65*2,427+65*2,427+65*2,427+65*2,427+65*2,427+65*2,/* FIRST YELLOW*/935-65*5+25,935-65*4+25,935-65*3+25,935-65*2+25,935-65+25,935+25,/*CLIMB UP*/935+25,/*SECOND YELLOW*/935+25,935-65+30,935-65*2+30,935-65*3+30,935-65*4+30,935-65*5+30,/*FIRST GREEN*/530+27,530+27,530+27,530+27,530+27,530+27,530+27-65/*INTO HOME*/,530+27-65,510,510,510,510,510};
int g3_x[]={900,1020-(65*2)+31,1020-(65*3)+31,1020-(65*4)+31,1020-(65*5)+31,1020-(65*6)+31/*RED SIDE*/,415+30+65+65,575,575,575,575,575,575-65,575-65-65,415+30,415+30,415+30,415+30,415+30,/*FIRST BLUE*/325+30,260+30,195+30,130+30,65+30,30,/*CLIMB UP*/30,/*SECOND BLUE*/30,30+65,30+65*2,30+65*3,30+65*4,30+65*5,/*FIRST YELLOW*/447,447,447,447,447,447,/*CLIMB UP*/480+30,/*SECOND YELLOW*/480+65+30,480+65+30,480+65+30,480+65+30,480+65+30,480+65+30,/*FIRST GREEN*/1020-(65*6)+31,1020-(65*5)+31,1020-(65*4)+31,1020-(65*3)+31,1020-(65*2)+31,1020-(65*1)+31,1020-(65*1)+31,/*CLIMB DOWN*/1020-(65*1)+31,/*INTO HOME*/1020-(65*2)+31,1020-(65*3)+31,1020-(65*4)+31,1020-(65*5)+31,1020-(65*6)+31};
int g3_y[]={100,427,427,427,427,427,/*RED LAST*/65*5+25,65*4+25,65*3+25,65*2+25,65+25,25,25,25,/*FIRST RED*/65+25,65*2+25,65*3+25,65*4+25,65*5+25,/*FIRST BLUE*/427,427,427,427,427,427,/*CLIMB UP*/425+65/*SEOND BLUE*/,427+65*2,427+65*2,427+65*2,427+65*2,427+65*2,427+65*2,/* FIRST YELLOW*/935-65*5+25,935-65*4+25,935-65*3+25,935-65*2+25,935-65+25,935+25,/*CLIMB UP*/935+25,/*SECOND YELLOW*/935+25,935-65+30,935-65*2+30,935-65*3+30,935-65*4+30,935-65*5+30,/*FIRST GREEN*/530+27,530+27,530+27,530+27,530+27,530+27,530+27-65/*INTO HOME*/,530+27-65,510,510,510,510,510};
int g4_x[]={700,1020-(65*2)+31,1020-(65*3)+31,1020-(65*4)+31,1020-(65*5)+31,1020-(65*6)+31/*RED SIDE*/,415+30+65+65,575,575,575,575,575,575-65,575-65-65,415+30,415+30,415+30,415+30,415+30,/*FIRST BLUE*/325+30,260+30,195+30,130+30,65+30,30,/*CLIMB UP*/30,/*SECOND BLUE*/30,30+65,30+65*2,30+65*3,30+65*4,30+65*5,/*FIRST YELLOW*/447,447,447,447,447,447,/*CLIMB UP*/480+30,/*SECOND YELLOW*/480+65+30,480+65+30,480+65+30,480+65+30,480+65+30,480+65+30,/*FIRST GREEN*/1020-(65*6)+31,1020-(65*5)+31,1020-(65*4)+31,1020-(65*3)+31,1020-(65*2)+31,1020-(65*1)+31,1020-(65*1)+31,/*CLIMB DOWN*/1020-(65*1)+31,/*INTO HOME*/1020-(65*2)+31,1020-(65*3)+31,1020-(65*4)+31,1020-(65*5)+31,1020-(65*6)+31};
int g4_y[]={270,427,427,427,427,427,/*RED LAST*/65*5+25,65*4+25,65*3+25,65*2+25,65+25,25,25,25,/*FIRST RED*/65+25,65*2+25,65*3+25,65*4+25,65*5+25,/*FIRST BLUE*/427,427,427,427,427,427,/*CLIMB UP*/425+65/*SEOND BLUE*/,427+65*2,427+65*2,427+65*2,427+65*2,427+65*2,427+65*2,/* FIRST YELLOW*/935-65*5+25,935-65*4+25,935-65*3+25,935-65*2+25,935-65+25,935+25,/*CLIMB UP*/935+25,/*SECOND YELLOW*/935+25,935-65+30,935-65*2+30,935-65*3+30,935-65*4+30,935-65*5+30,/*FIRST GREEN*/530+27,530+27,530+27,530+27,530+27,530+27,530+27-65/*INTO HOME*/,530+27-65,510,510,510,510,510};
// this is to keep track of the tokens
int i=0;
int mover_r1=0;
int dice_number;
int mover_g1=0;
int mover_g2=0;
int mover_g3=0;
int mover_g4=0;
int mover_b1=0;
int mover_b2=0;
int mover_b3=0;
int mover_b4=0;
int mover_y1=0;
int mover_y2=0;
int mover_r2=0;
int mover_r3=0;
int mover_r4=0;
int mover_y3=0;
int mover_y4=0;
int blue_score=0;
int red_score=0;
int yellow_score=0;
int green_score=0;
int turn=0;
 char player[4];
 void Display_Random();
 void SetCanvasSize(int,int);
 void GameDisplay();
void highest_check();
void draw_dice( int );
void Set_display_choice_Size(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

void ThirdScreen(){
Set_display_choice_Size(1000,  1000);
Display_Random();
highest_check();

SetCanvasSize(1000, 1000);
glutDisplayFunc(GameDisplay);


glutSwapBuffers();
}
void SetFirstCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	
	glLoadIdentity();
}
void SetNameCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	
	glLoadIdentity();
}

void SecondScreen(){
DrawString( 200, 700, "Do you want random selection of colours (R) or choose (C) yourself? ", colors[PINK]);
/*DrawString( 200, 800, "choose color \n Red \nBlue \nGreen \nYellow", colors[PINK]);
draw_dice(dice_number);*/
Set_display_choice_Size(1000, 1000);
glutDisplayFunc(ThirdScreen);



 glutSwapBuffers();
}
//display the colour chosen when colour is supposed to be chosen randomly
void Display_Random()
{


if(player[0]=='r')
 DrawString( 500, 500, "PLAYER 1 HAS RED", colors[PINK]);
if(player[0]=='b')
 DrawString( 500, 500, "PLAYER 1 HAS BLUE", colors[PINK]);
 if(player[0]=='g')
 DrawString( 500, 500, "PLAYER 1 HAS GREEN", colors[PINK]);
 if(player[0]=='y')
 DrawString( 500, 500, "PLAYER 1 HAS YELLOW", colors[PINK]);
 if(player[1]=='r')
 DrawString( 500, 400, "PLAYER 2 HAS RED", colors[PINK]);
if(player[1]=='b')
 DrawString( 500, 400, "PLAYER 2 HAS BLUE", colors[PINK]);
 if(player[1]=='g')
 DrawString( 500, 400, "PLAYER 2 HAS GREEN", colors[PINK]);
 if(player[1]=='y')
 DrawString( 500, 400, "PLAYER 2 HAS YELLOW", colors[PINK]);
 if(number_of_players==2)
 return;
 if(player[2]=='r')
 DrawString( 500, 300, "PLAYER 3 HAS RED", colors[PINK]);
if(player[2]=='b')
 DrawString( 500, 300, "PLAYER 3 HAS BLUE", colors[PINK]);
 if(player[2]=='g')
 DrawString( 500, 300, "PLAYER 3 HAS GREEN", colors[PINK]);
 if(player[2]=='y')
 DrawString( 500, 300, "PLAYER 3 HAS YELLOW", colors[PINK]);
 if(number_of_players==3)
 return;
 if(player[3]=='r')
 DrawString( 500, 200, "PLAYER 4 HAS RED", colors[PINK]);
if(player[3]=='b')
 DrawString( 500, 200, "PLAYER 4 HAS BLUE", colors[PINK]);
 if(player[3]=='g')
 DrawString( 500, 200, "PLAYER 4 HAS GREEN", colors[PINK]);
 if(player[3]=='y')
 DrawString( 500, 200, "PLAYER 4 HAS YELLOW", colors[PINK]);
 
}


 int x_axis=120,y_axis=100;
 void FirstScreen(){

 DrawString( 300, 800, "please enter the number of people playing (2-4)", colors[PINK]);
 //DrawString( 500, 600, "enter name", colors[PINK]);
 
 glutSwapBuffers();
}
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
void highest_check(){
	int i=0;
	int max=0;
	int check[number_of_players];
	while(i<number_of_players){
		DrawString( 100, 100, "to check the highest value each player please press space bar to check if you have the highesT number ", colors[PINK]);
		draw_dice(dice_number);
check[i]=dice_number;
i++;
}
max=check[0];

int greatest=0;
while(i<number_of_players){
if(check[i]>max){
greatest=i;}
i++;
}


if(player[greatest]=='r')
turn=0;
else if(player[greatest]=='b')
turn=1;
else if(player[greatest]=='g')
turn=2;
else if(player[greatest]=='y')
turn=3;

}

/*
 * Main Canvas drawing function.
 * */
//Board *b;
//drawing the dice. i made another function  to make the code neater
void draw_dice(int dice_number){
if(dice_number==1)
	{
	int x_dice=500, y_dice=500;
	DrawSquare(x_dice, y_dice,70,colors[MISTY_ROSE]);
	DrawCircle(x_dice+35, y_dice+40,10,colors[BLACK]);
	}
	if(dice_number==2)
	{
	int x_dice=500, y_dice=500;
	DrawSquare(x_dice, y_dice,70,colors[MISTY_ROSE]);
	DrawCircle(x_dice+20, y_dice+40,7,colors[BLACK]);
	DrawCircle(x_dice+40, y_dice+40,7,colors[BLACK]);
	}
	if(dice_number==3)
	{
	int x_dice=500, y_dice=500;
	DrawSquare(x_dice, y_dice,70,colors[MISTY_ROSE]);
	DrawCircle(x_dice+20, y_dice+40,7,colors[BLACK]);
	DrawCircle(x_dice+40, y_dice+40,7,colors[BLACK]);
	DrawCircle(x_dice+35, y_dice+20,7,colors[BLACK]);
	}
	if(dice_number==4)
	{
	int x_dice=500, y_dice=500;
	DrawSquare(x_dice, y_dice,70,colors[MISTY_ROSE]);
	DrawCircle(x_dice+20, y_dice+40,7,colors[BLACK]);
	DrawCircle(x_dice+40, y_dice+40,7,colors[BLACK]);
	DrawCircle(x_dice+40, y_dice+20,7,colors[BLACK]);
	DrawCircle(x_dice+20, y_dice+20,7,colors[BLACK]);
	}
	if(dice_number==5)
	{
	int x_dice=500, y_dice=500;
	DrawSquare(x_dice, y_dice,70,colors[MISTY_ROSE]);
	DrawCircle(x_dice+20, y_dice+50,7,colors[BLACK]);
	DrawCircle(x_dice+55, y_dice+50,7,colors[BLACK]);
	DrawCircle(x_dice+55, y_dice+15,7,colors[BLACK]);
	DrawCircle(x_dice+20, y_dice+15,7,colors[BLACK]);
	DrawCircle(x_dice+35, y_dice+35,7,colors[BLACK]);
	}
	
	if(dice_number==6)
	{
	int x_dice=500, y_dice=500;
	DrawSquare(x_dice, y_dice,70,colors[MISTY_ROSE]);
	DrawCircle(x_dice+20, y_dice+50,7,colors[BLACK]);
	DrawCircle(x_dice+20, y_dice+30,7,colors[BLACK]);
	DrawCircle(x_dice+20, y_dice+15,7,colors[BLACK]);
	DrawCircle(x_dice+55, y_dice+50,7,colors[BLACK]);
	DrawCircle(x_dice+55, y_dice+30,7,colors[BLACK]);
	DrawCircle(x_dice+55, y_dice+15,7,colors[BLACK]);
	}



}
 
void GameDisplay()/**/{

	// set the background color using function glClearColor
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	//Fire Gun
	
	
	
	
	DrawSquare( 0, -25,410,colors[RED]); 
	DrawSquare( 50, -25+50,310,colors[ANTIQUE_WHITE]);
	DrawSquare( 0 , 600 ,410,colors[BLUE]); 
	DrawSquare( 50 , 650 ,310,colors[ANTIQUE_WHITE]);
	DrawSquare( 610 , 600 ,410,colors[YELLOW]);
	DrawSquare( 660 , 650 ,310,colors[ANTIQUE_WHITE]);	 
	DrawSquare( 610, -25,410,colors[GREEN]);
	DrawSquare( 660, -25+50,310,colors[ANTIQUE_WHITE]);
	DrawSquare( 0, 400,60,colors[ANTIQUE_WHITE]);
	
	//DRAWING THE BOARD
	
	int i=0;
	while(i<340){
	if(i==0)
	{
	DrawSquare( i, 400+65,60,colors[ANTIQUE_WHITE]);
	i=i+65;
	continue;
	}
	DrawSquare( i, 400+65,60,colors[BLUE]);
	i=i+65;
	
	}
	i=0;
	while(i<340){
	if(i==65){
	DrawSquare( i, 400+65+65,60,colors[BLUE]);
	i=i+65;
	continue;
	}
	
	DrawSquare( i, 400+65+65,60,colors[ANTIQUE_WHITE]);
	i=i+65;
	}
	i=0;
	while(i<340){
	if(i==65+65){
	DrawSquare( i, 400,60,colors[GRAY]);
	i=i+65;
	continue;
	}
	
	DrawSquare( i, 400,60,colors[ANTIQUE_WHITE]);
	i=i+65;
	}
	//for the first vertical column at the bottom
	i=0;
	while(i<340){
	if(i==65){
	DrawSquare( 415, i,60,colors[RED]);
	i=i+65;
	continue;
	}
	DrawSquare( 415, i,60,colors[ANTIQUE_WHITE]);
	i=i+65;
	}
	//for the second vertical column at the bottom
	i=0;
	while(i<340){
	if(i==0){
	DrawSquare( 415+65, i,60,colors[ANTIQUE_WHITE]);
	i=i+65;
	continue;
	}
	DrawSquare( 415+65, i,60,colors[RED]);
	i=i+65;
	}
	//for 3rd vertical column at thew bottom
	i=0;
	while(i<340){
	if(i==65+65){
	DrawSquare( 415+65+65, i,60,colors[GRAY]);
	i=i+65;
	continue;
	}
	DrawSquare( 415+65+65, i,60,colors[WHITE]);
	i=i+65;
	}
	//for the first vertical top row
	i=935;
	
	while(i>(600)){
	if(i==935-65-65){
	DrawSquare( 415, i,60,colors[GRAY]);
	i=i-65;
	continue;
	}
	DrawSquare( 415, i,60,colors[ANTIQUE_WHITE]);
	i=i-65;
	
	}
	//second vertical row on top
	DrawSquare( 480, 935,60,colors[ANTIQUE_WHITE]);
	i=(935-65);
	while(i>(600)){
	
	DrawSquare( 480, i,60,colors[YELLOW]);
	i=i-65;
	
	}
	//third vertical row on top
	i=935;
	while(i>(600)){
	if(i==935-65){
	DrawSquare( 480+65, i,60,colors[YELLOW]);
	i=i-65;
	continue;
	}
	DrawSquare( 480+65, i,60,colors[ANTIQUE_WHITE]);
	i=i-65;
	
	}
	
	i=1020-65;
	while(i>600){
	if(i==(1020-(65+65))){
	DrawSquare( i, 400,60,colors[GREEN]);
	i=i-65;
	continue;
	}
	DrawSquare(i, 400,60,colors[ANTIQUE_WHITE]);
	i=i-65;
	}
	
	i=1020-65;
	while(i>600){
	if(i==1020-(65+65+65)){
	
	DrawSquare( i, 400+65+65,60,colors[GRAY]);
	i=i-65;
	continue;
	}
	DrawSquare( i, 400+65+65,60,colors[ANTIQUE_WHITE]);
	i=i-65;
	}
	i=1020-65;
	while(i>600){
	if(i==1020-65){
	DrawSquare( i, 400+65,60,colors[ANTIQUE_WHITE]);
	i=i-65;
	continue;
	}
	DrawSquare( i, 400+65,60,colors[GREEN]);
	i=i-65;
	}
	//Display Score
	DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	
	DrawTriangle( 500, 500 , 400, 400 , 610, 400, colors[RED] ); 
	DrawTriangle( 500, 500 , 400, 400 , 400, 600, colors[BLUE] ); 
	DrawTriangle( 500, 500 , 610, 600 , 400, 600, colors[YELLOW] ); 
	DrawTriangle( 500, 500 , 610, 400 , 610, 600, colors[GREEN] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
		

	
	DrawLine( 0 , 390 ,  410 , 390 , 5 , colors[RED] );	
	DrawLine( 610 , 390 ,  1020 , 390 , 5 , colors[GREEN] );
	DrawLine( 610 , 390 ,  1020 , 390 , 5 , colors[GREEN] );
	//Drawing tokens and their symbols using the arrays to make comparison easy later
	DrawCircle(r2_x[mover_r2],r2_y[mover_r2],30,colors[RED]);
	DrawCircle(r1_x[mover_r1],r1_y[mover_r1],30,colors[RED]);
	DrawCircle(r3_x[mover_r3],r3_y[mover_r3],30,colors[RED]);
	DrawCircle(r4_x[mover_r4],r4_y[mover_r4],30,colors[RED]);
	DrawCircle(g1_x[mover_g1],g1_y[mover_g1],30,colors[GREEN]);
	DrawCircle(b1_x[mover_b1],b1_y[mover_b1],30,colors[BLUE]);
	DrawCircle(y1_x[mover_y1],y1_y[mover_y1],30,colors[YELLOW]);
	DrawString(r2_x[mover_r2],r2_y[mover_r2],"/",colors[BLACK]);
	DrawString(r1_x[mover_r1],r1_y[mover_r1],"*",colors[BLACK]);
	DrawString(r3_x[mover_r3],r3_y[mover_r3],"|",colors[BLACK]);
	DrawString(r4_x[mover_r4],r4_y[mover_r4],"^",colors[BLACK]);
	DrawString(g1_x[mover_g1],g1_y[mover_g1],"%",colors[BLACK]);
	DrawString(b1_x[mover_b1],b1_y[mover_b1],"&",colors[BLACK]);
	DrawString(y1_x[mover_y1],y1_y[mover_y1],"$",colors[BLACK]);
	DrawCircle(y2_x[mover_y2],y2_y[mover_y2],30,colors[YELLOW]);
	DrawString(y2_x[mover_y2],y2_y[mover_y2],"?",colors[BLACK]);
	DrawCircle(b3_x[mover_b3],b3_y[mover_b3],30,colors[BLUE]);
	DrawString(b3_x[mover_b3],b3_y[mover_b3],"#",colors[BLACK]);
	DrawCircle(b4_x[mover_b4],b4_y[mover_b4],30,colors[BLUE]);
	DrawString(b4_x[mover_b4],b4_y[mover_b4],"@",colors[BLACK]);
	DrawCircle(b2_x[mover_b2],b2_y[mover_b2],30,colors[BLUE]);
	DrawString(b2_x[mover_b2],b2_y[mover_b2],"!",colors[BLACK]);
	
	
	DrawCircle(y4_x[mover_y4],y4_y[mover_y4],30,colors[YELLOW]);
	DrawString(y4_x[mover_y4],y4_y[mover_y4],";",colors[BLACK]);
	DrawCircle(y3_x[mover_y3],y3_y[mover_y3],30,colors[YELLOW]);
	DrawString(y3_x[mover_y3],y3_y[mover_y3],":",colors[BLACK]);
	
	
	
	DrawCircle(g2_x[mover_g2],g2_y[mover_g2],30,colors[GREEN]);
	DrawString(g2_x[mover_g2],g2_y[mover_g2],"(",colors[BLACK]);
	DrawCircle(g3_x[mover_g3],g3_y[mover_g3],30,colors[GREEN]);
	DrawString(g3_x[mover_g3],g3_y[mover_g3],")",colors[BLACK]);
	DrawCircle(g4_x[mover_g4],g4_y[mover_g4],30,colors[GREEN]);
	DrawString(g4_x[mover_g4],g4_y[mover_g4],"=",colors[BLACK]);
	
	// Display_Random();
	 // telling whose turn is it. this to facilitate the player
	if(turn==0)
	DrawString(40,40,"Red's turn",colors[BLACK]);
	if(turn==1)
	DrawString(200,650,"Blue's turn",colors[BLACK]);
	if(turn==2)
	DrawString(600,40,"Green's turn",colors[BLACK]);
	if(turn==3)
	DrawString(600,650,"Yellow's turn",colors[BLACK]);
	
	draw_dice(dice_number);
	
	
	glutSwapBuffers(); // do not modify this line..
	
	
}
//these functions are used to see if the player can kill the token they have landed on. the arrays were initially used to make this part easier
void killing_by_r1()
{

if(mover_r1!=9 and mover_r1!=14 and mover_r1!=22 and mover_r1!=27 and mover_r1!=35 and mover_r1!=40 and mover_r1!=48 ){
		if(r1_x[mover_r1]==g1_x[mover_g1] and r1_y[mover_r1]==g1_y[mover_g1] and (mover_g1!=mover_g2) and (mover_g1!=mover_g3) and (mover_g1!=mover_g4))
		{
		mover_g1=0;
		red_score=red_score+10;
		}
		if(r1_x[mover_r1]==r2_x[mover_g2] and r1_y[mover_r1]==g2_y[mover_g2] and (mover_g1!=mover_g2) and (mover_g2!=mover_g3) and (mover_g2!=mover_g4))
		{
		mover_g2=0;
		red_score=red_score+10;
		}
		if(r1_x[mover_r1]==g3_x[mover_g3] and r1_y[mover_r1]==g3_y[mover_g3]  and (mover_g1!=mover_g3) and (mover_g2!=mover_g3) and (mover_g3!=mover_g4))
		{
		mover_g3=0;
		red_score=red_score+10;
		}
		if(r1_x[mover_r1]==g4_x[mover_g4] and r1_y[mover_r1]==g4_y[mover_g4] and (mover_g1!=mover_g4) and (mover_g4!=mover_g3) and (mover_g2!=mover_g4))
		{
		mover_g4=0;
		red_score=red_score+10;
		}
		if(b1_x[mover_b1]==r1_x[mover_r1] and b1_y[mover_b1]==r1_y[mover_r1] and (mover_b1!=mover_b2) and (mover_b1!=mover_b4) and (mover_b1!=mover_b3))
		{
		mover_b1=0;
		red_score=red_score+10;
		}
		if(b2_x[mover_b2]==r1_x[mover_r1] and b2_y[mover_b2]==r1_y[mover_r1] and (mover_b1!=mover_b2) and (mover_b2!=mover_b4) and (mover_b2!=mover_b3))
		{
		mover_b2=0;
		red_score=red_score+10;
		}
		if(b4_x[mover_b4]==r1_x[mover_r1] and b4_y[mover_b4]==r1_y[mover_r1] and (mover_b1!=mover_b4) and (mover_b2!=mover_b4) and (mover_b4!=mover_b3))
		{
		mover_b4=0;
		red_score=red_score+10;
		}
		if(b3_x[mover_b3]==r1_x[mover_r1] and b3_y[mover_b3]==r1_y[mover_r1]and (mover_b1!=mover_b3) and (mover_b3!=mover_b4) and (mover_b2!=mover_b3))
		{
		mover_b3=0;
		red_score=red_score+10;
		}
		if(y1_x[mover_y1]==r1_x[mover_r1] and y1_y[mover_y1]==r1_y[mover_r1] and (mover_y1!=mover_y2) and (mover_y1!=mover_y4) and (mover_y1!=mover_y3))
		{
		mover_y1=0;
		red_score=red_score+10;
		}
		if(y2_x[mover_y2]==r1_x[mover_r1] and y2_y[mover_y2]==r1_y[mover_r1]and (mover_y1!=mover_y2) and (mover_y2!=mover_y4) and (mover_y2!=mover_y3)){
		mover_y2=0;
		red_score=red_score+10;
		}
		if(y4_x[mover_y4]==r1_x[mover_r1] and y4_y[mover_y4]==r1_y[mover_r1] and (mover_y1!=mover_y4) and (mover_y2!=mover_y4) and (mover_y4!=mover_y3))
		{
		mover_y4=0;
		red_score=red_score+10;
		}
		if(y3_x[mover_y3]==r1_x[mover_r1] and y3_y[mover_y3]==r1_y[mover_r1] and (mover_y1!=mover_y3) and (mover_y3!=mover_y4) and (mover_y2!=mover_y3))
		{
		mover_y3=0;
		red_score=red_score+10;
		}
		}

}

void killing_by_r2()
{

if(mover_r2!=9 and mover_r2!=14 and mover_r2!=22 and mover_r2!=27 and mover_r2!=35 and mover_r2!=40 and mover_r2!=48 ){
		if(r2_x[mover_r2]==g1_x[mover_g1] and r2_y[mover_r2]==g1_y[mover_g1] and (mover_g1!=mover_g2) and (mover_g1!=mover_g3) and (mover_g1!=mover_g4))
		{
		mover_g1=0;
		red_score=red_score+10;
		}
		if(r2_x[mover_r2]==r2_x[mover_g2] and r2_y[mover_r2]==g2_y[mover_g2] and (mover_g1!=mover_g2) and (mover_g2!=mover_g3) and (mover_g2!=mover_g4))
		{
		mover_g2=0;
		red_score=red_score+10;
		}
		if(r2_x[mover_r2]==g3_x[mover_g3] and r2_y[mover_r2]==g3_y[mover_g3]  and (mover_g1!=mover_g3) and (mover_g2!=mover_g3) and (mover_g3!=mover_g4))
		{
		mover_g3=0;
		red_score=red_score+10;
		}
		if(r2_x[mover_r2]==g4_x[mover_g4] and r2_y[mover_r2]==g4_y[mover_g4] and (mover_g1!=mover_g4) and (mover_g4!=mover_g3) and (mover_g2!=mover_g4))
		{
		mover_g4=0;
		red_score=red_score+10;
		}
		if(b1_x[mover_b1]==r2_x[mover_r2] and b1_y[mover_b1]==r2_y[mover_r2] and (mover_b1!=mover_b2) and (mover_b1!=mover_b4) and (mover_b1!=mover_b3))
		{
		mover_b1=0;
		red_score=red_score+10;
		}
		if(b2_x[mover_b2]==r2_x[mover_r2] and b2_y[mover_b2]==r2_y[mover_r2] and (mover_b1!=mover_b2) and (mover_b2!=mover_b4) and (mover_b2!=mover_b3))
		{
		mover_b2=0;
		red_score=red_score+10;
		}
		if(b4_x[mover_b4]==r2_x[mover_r2] and b4_y[mover_b4]==r2_y[mover_r2] and (mover_b1!=mover_b4) and (mover_b2!=mover_b4) and (mover_b4!=mover_b3))
		{
		mover_b4=0;
		red_score=red_score+10;
		}
		if(b3_x[mover_b3]==r2_x[mover_r2] and b3_y[mover_b3]==r2_y[mover_r2]and (mover_b1!=mover_b3) and (mover_b3!=mover_b4) and (mover_b2!=mover_b3))
		{
		mover_b3=0;
		red_score=red_score+10;
		}
		if(y1_x[mover_y1]==r2_x[mover_r2] and y1_y[mover_y1]==r2_y[mover_r2] and (mover_y1!=mover_y2) and (mover_y1!=mover_y4) and (mover_y1!=mover_y3))
		{
		mover_y1=0;
		red_score=red_score+10;
		}
		if(y2_x[mover_y2]==r2_x[mover_r2] and y2_y[mover_y2]==r2_y[mover_r2]and (mover_y1!=mover_y2) and (mover_y2!=mover_y4) and (mover_y2!=mover_y3)){
		mover_y2=0;
		red_score=red_score+10;
		}
		if(y4_x[mover_y4]==r2_x[mover_r2] and y4_y[mover_y4]==r2_y[mover_r2] and (mover_y1!=mover_y4) and (mover_y2!=mover_y4) and (mover_y4!=mover_y3))
		{
		mover_y4=0;
		red_score=red_score+10;
		}
		if(y3_x[mover_y3]==r2_x[mover_r2] and y3_y[mover_y3]==r2_y[mover_r2] and (mover_y1!=mover_y3) and (mover_y3!=mover_y4) and (mover_y2!=mover_y3))
		{
		mover_y3=0;
		red_score=red_score+10;
		}
		}

}

void killing_by_r3()
{

if(mover_r3!=9 and mover_r3!=14 and mover_r3!=22 and mover_r3!=27 and mover_r3!=35 and mover_r3!=40 and mover_r3!=48 ){
		if(r3_x[mover_r3]==g1_x[mover_g1] and r3_y[mover_r3]==g1_y[mover_g1] and (mover_g1!=mover_g2) and (mover_g1!=mover_g3) and (mover_g1!=mover_g4))
		{
		mover_g1=0;
		red_score=red_score+10;
		}
		if(r3_x[mover_r3]==r3_x[mover_g2] and r3_y[mover_r3]==g2_y[mover_g2] and (mover_g1!=mover_g2) and (mover_g2!=mover_g3) and (mover_g2!=mover_g4))
		{
		mover_g2=0;
		red_score=red_score+10;
		}
		if(r3_x[mover_r3]==g3_x[mover_g3] and r3_y[mover_r3]==g3_y[mover_g3]  and (mover_g1!=mover_g3) and (mover_g2!=mover_g3) and (mover_g3!=mover_g4))
		{
		mover_g3=0;
		red_score=red_score+10;
		}
		if(r3_x[mover_r3]==g4_x[mover_g4] and r3_y[mover_r3]==g4_y[mover_g4] and (mover_g1!=mover_g4) and (mover_g4!=mover_g3) and (mover_g2!=mover_g4))
		{
		mover_g4=0;
		red_score=red_score+10;
		}
		if(b1_x[mover_b1]==r3_x[mover_r3] and b1_y[mover_b1]==r3_y[mover_r3] and (mover_b1!=mover_b2) and (mover_b1!=mover_b4) and (mover_b1!=mover_b3))
		{
		mover_b1=0;
		red_score=red_score+10;
		}
		if(b2_x[mover_b2]==r3_x[mover_r3] and b2_y[mover_b2]==r3_y[mover_r3] and (mover_b1!=mover_b2) and (mover_b2!=mover_b4) and (mover_b2!=mover_b3))
		{
		mover_b2=0;
		red_score=red_score+10;
		}
		if(b4_x[mover_b4]==r3_x[mover_r3] and b4_y[mover_b4]==r3_y[mover_r3] and (mover_b1!=mover_b4) and (mover_b2!=mover_b4) and (mover_b4!=mover_b3))
		{
		mover_b4=0;
		red_score=red_score+10;
		}
		if(b3_x[mover_b3]==r3_x[mover_r3] and b3_y[mover_b3]==r3_y[mover_r3]and (mover_b1!=mover_b3) and (mover_b3!=mover_b4) and (mover_b2!=mover_b3))
		{
		mover_b3=0;
		red_score=red_score+10;
		}
		if(y1_x[mover_y1]==r3_x[mover_r3] and y1_y[mover_y1]==r3_y[mover_r3] and (mover_y1!=mover_y2) and (mover_y1!=mover_y4) and (mover_y1!=mover_y3))
		{
		mover_y1=0;
		red_score=red_score+10;
		}
		if(y2_x[mover_y2]==r3_x[mover_r3] and y2_y[mover_y2]==r3_y[mover_r3]and (mover_y1!=mover_y2) and (mover_y2!=mover_y4) and (mover_y2!=mover_y3)){
		mover_y2=0;
		red_score=red_score+10;
		}
		if(y4_x[mover_y4]==r3_x[mover_r3] and y4_y[mover_y4]==r3_y[mover_r3] and (mover_y1!=mover_y4) and (mover_y2!=mover_y4) and (mover_y4!=mover_y3))
		{
		mover_y4=0;
		red_score=red_score+10;
		}
		if(y3_x[mover_y3]==r3_x[mover_r3] and y3_y[mover_y3]==r3_y[mover_r3] and (mover_y1!=mover_y3) and (mover_y3!=mover_y4) and (mover_y2!=mover_y3))
		{
		mover_y3=0;
		red_score=red_score+10;
		}
		}

}

void killing_by_r4()
{

if(mover_r4!=9 and mover_r4!=14 and mover_r4!=22 and mover_r4!=27 and mover_r4!=35 and mover_r4!=40 and mover_r4!=48 ){
		if(r4_x[mover_r4]==g1_x[mover_g1] and r4_y[mover_r4]==g1_y[mover_g1] and (mover_g1!=mover_g2) and (mover_g1!=mover_g3) and (mover_g1!=mover_g4))
		{
		mover_g1=0;
		red_score=red_score+10;
		}
		if(r4_x[mover_r4]==r4_x[mover_g2] and r4_y[mover_r4]==g2_y[mover_g2] and (mover_g1!=mover_g2) and (mover_g2!=mover_g3) and (mover_g2!=mover_g4))
		{
		mover_g2=0;
		red_score=red_score+10;
		}
		if(r4_x[mover_r4]==g3_x[mover_g3] and r4_y[mover_r4]==g3_y[mover_g3]  and (mover_g1!=mover_g3) and (mover_g2!=mover_g3) and (mover_g3!=mover_g4))
		{
		mover_g3=0;
		red_score=red_score+10;
		}
		if(r4_x[mover_r4]==g4_x[mover_g4] and r4_y[mover_r4]==g4_y[mover_g4] and (mover_g1!=mover_g4) and (mover_g4!=mover_g3) and (mover_g2!=mover_g4))
		{
		mover_g4=0;
		red_score=red_score+10;
		}
		if(b1_x[mover_b1]==r4_x[mover_r4] and b1_y[mover_b1]==r4_y[mover_r4] and (mover_b1!=mover_b2) and (mover_b1!=mover_b4) and (mover_b1!=mover_b3))
		{
		mover_b1=0;
		red_score=red_score+10;
		}
		if(b2_x[mover_b2]==r4_x[mover_r4] and b2_y[mover_b2]==r4_y[mover_r4] and (mover_b1!=mover_b2) and (mover_b2!=mover_b4) and (mover_b2!=mover_b3))
		{
		mover_b2=0;
		red_score=red_score+10;
		}
		if(b4_x[mover_b4]==r4_x[mover_r4] and b4_y[mover_b4]==r4_y[mover_r4] and (mover_b1!=mover_b4) and (mover_b2!=mover_b4) and (mover_b4!=mover_b3))
		{
		mover_b4=0;
		red_score=red_score+10;
		}
		if(b3_x[mover_b3]==r4_x[mover_r4] and b3_y[mover_b3]==r4_y[mover_r4]and (mover_b1!=mover_b3) and (mover_b3!=mover_b4) and (mover_b2!=mover_b3))
		{
		mover_b3=0;
		red_score=red_score+10;
		}
		if(y1_x[mover_y1]==r4_x[mover_r4] and y1_y[mover_y1]==r4_y[mover_r4] and (mover_y1!=mover_y2) and (mover_y1!=mover_y4) and (mover_y1!=mover_y3))
		{
		mover_y1=0;
		red_score=red_score+10;
		}
		if(y2_x[mover_y2]==r4_x[mover_r4] and y2_y[mover_y2]==r4_y[mover_r4]and (mover_y1!=mover_y2) and (mover_y2!=mover_y4) and (mover_y2!=mover_y3)){
		mover_y2=0;
		red_score=red_score+10;
		}
		if(y4_x[mover_y4]==r4_x[mover_r4] and y4_y[mover_y4]==r4_y[mover_r4] and (mover_y1!=mover_y4) and (mover_y2!=mover_y4) and (mover_y4!=mover_y3))
		{
		mover_y4=0;
		red_score=red_score+10;
		}
		if(y3_x[mover_y3]==r4_x[mover_r4] and y3_y[mover_y3]==r4_y[mover_r4] and (mover_y1!=mover_y3) and (mover_y3!=mover_y4) and (mover_y2!=mover_y3))
		{
		mover_y3=0;
		red_score=red_score+10;
		}
		}

}
void killing_by_y1()
{
if(mover_y1!=1 and mover_y1!=9 and mover_y1!=14 and mover_y1!=22 and mover_y1!=27 and mover_y1!=35 and mover_y1!=40 and mover_y1!=48)
	{
	
	
	if(y1_x[mover_y1]==g1_x[mover_g1] and y1_y[mover_y1]==g1_y[mover_g1] and mover_g2!=mover_g1 and mover_g3!=mover_g1 and mover_g1!=mover_g4)
	{
	mover_g1=0;
	yellow_score=yellow_score+10;
	}
	if(y1_x[mover_y1]==g2_x[mover_g2] and y1_y[mover_y1]==g2_y[mover_g2] and mover_g2!=mover_g1 and mover_g3!=mover_g2 and mover_g2!=mover_g4)
	{
	mover_g2=0;
	yellow_score=yellow_score+10;
	}
	if(y1_x[mover_y1]==g3_x[mover_g3] and y1_y[mover_y1]==g3_y[mover_g3]  and mover_g3!=mover_g1 and mover_g3!=mover_g2 and mover_g3!=mover_g4)
	{
	mover_g3=0;
	yellow_score=yellow_score+10;
	}
	if(y1_x[mover_y1]==g4_x[mover_g4] and y1_y[mover_y1]==g4_y[mover_g4] and mover_g4!=mover_g1 and mover_g4!=mover_g2 and mover_g3!=mover_g4)
	{
	mover_g4=0;
	yellow_score=yellow_score+10;
	}
	
	if(y1_x[mover_y1]==b1_x[mover_b1] and y1_y[mover_y1]==b1_y[mover_b1] and mover_b2!=mover_b1 and mover_b3!=mover_b1 and mover_b1!=mover_b4){
	mover_b1=0;
	yellow_score=yellow_score+10;
	}
	if(y1_x[mover_y1]==b2_x[mover_b2] and y1_y[mover_y1]==b2_y[mover_b2] and mover_b2!=mover_b1 and mover_b3!=mover_b2 and mover_b2!=mover_b4){
	mover_b2=0;
	yellow_score=yellow_score+10;
	}
	if(y1_x[mover_y1]==b3_x[mover_b3] and y1_y[mover_y1]==b3_y[mover_b3] and mover_b3!=mover_b1 and mover_b3!=mover_b2 and mover_b3!=mover_b4){
	mover_b3=0;
	yellow_score=yellow_score+10;
	}
	if(y1_x[mover_y1]==b4_x[mover_b4] and y1_y[mover_y1]==b4_y[mover_b4] and mover_b4!=mover_b1 and mover_b4!=mover_b2 and mover_b3!=mover_b4){
	mover_b4=0;
	yellow_score=yellow_score+10;
	}
	if(y1_x[mover_y1]==r1_x[mover_r1] and y1_y[mover_y1]==r1_y[mover_r1] and mover_r2!=mover_r1 and mover_r3!=mover_r1 and mover_r1!=mover_r4){
	mover_r1=0;
	yellow_score=yellow_score+10;
	}
	if(y1_x[mover_y1]==r2_x[mover_r2] and y1_y[mover_y1]==r2_y[mover_r2] and mover_r2!=mover_r1 and mover_r3!=mover_r2 and mover_r2!=mover_r4){
	mover_r2=0;
	yellow_score=yellow_score+10;
	}
	if(y1_x[mover_y1]==r3_x[mover_r3] and y1_y[mover_y1]==r3_y[mover_r3] and mover_r3!=mover_r1 and mover_r3!=mover_r2 and mover_r3!=mover_r4){
	mover_r3=0;
	yellow_score=yellow_score+10;
	}
	if(y1_x[mover_y1]==r4_x[mover_r4] and y1_y[mover_y1]==r4_y[mover_r4] and mover_r4!=mover_r1 and mover_r4!=mover_r2 and mover_r3!=mover_r4){
	mover_r4=0;
	yellow_score=yellow_score+10;
	}
	
	
	

	}
}

void killing_by_y2()
{
if(mover_y2!=1 and mover_y2!=9 and mover_y2!=14 and mover_y2!=22 and mover_y2!=27 and mover_y2!=35 and mover_y2!=40 and mover_y2!=48)
	{
	
	
	if(y2_x[mover_y2]==g1_x[mover_g1] and y2_y[mover_y2]==g1_y[mover_g1] and mover_g2!=mover_g1 and mover_g3!=mover_g1 and mover_g1!=mover_g4)
	{
	mover_g1=0;
	yellow_score=yellow_score+10;
	}
	if(y2_x[mover_y2]==g2_x[mover_g2] and y2_y[mover_y2]==g2_y[mover_g2] and mover_g2!=mover_g1 and mover_g3!=mover_g2 and mover_g2!=mover_g4)
	{
	mover_g2=0;
	yellow_score=yellow_score+10;
	}
	if(y2_x[mover_y2]==g3_x[mover_g3] and y2_y[mover_y2]==g3_y[mover_g3]  and mover_g3!=mover_g1 and mover_g3!=mover_g2 and mover_g3!=mover_g4)
	{
	mover_g3=0;
	yellow_score=yellow_score+10;
	}
	if(y2_x[mover_y2]==g4_x[mover_g4] and y2_y[mover_y2]==g4_y[mover_g4] and mover_g4!=mover_g1 and mover_g4!=mover_g2 and mover_g3!=mover_g4)
	{
	mover_g4=0;
	yellow_score=yellow_score+10;
	}
	
	if(y2_x[mover_y2]==b1_x[mover_b1] and y2_y[mover_y2]==b1_y[mover_b1] and mover_b2!=mover_b1 and mover_b3!=mover_b1 and mover_b1!=mover_b4){
	mover_b1=0;
	yellow_score=yellow_score+10;
	}
	if(y2_x[mover_y2]==b2_x[mover_b2] and y2_y[mover_y2]==b2_y[mover_b2] and mover_b2!=mover_b1 and mover_b3!=mover_b2 and mover_b2!=mover_b4){
	mover_b2=0;
	yellow_score=yellow_score+10;
	}
	if(y2_x[mover_y2]==b3_x[mover_b3] and y2_y[mover_y2]==b3_y[mover_b3] and mover_b3!=mover_b1 and mover_b3!=mover_b2 and mover_b3!=mover_b4){
	mover_b3=0;
	yellow_score=yellow_score+10;
	}
	if(y2_x[mover_y2]==b4_x[mover_b4] and y2_y[mover_y2]==b4_y[mover_b4] and mover_b4!=mover_b1 and mover_b4!=mover_b2 and mover_b3!=mover_b4){
	mover_b4=0;
	yellow_score=yellow_score+10;
	}
	if(y2_x[mover_y2]==r1_x[mover_r1] and y2_y[mover_y2]==r1_y[mover_r1] and mover_r2!=mover_r1 and mover_r3!=mover_r1 and mover_r1!=mover_r4){
	mover_r1=0;
	yellow_score=yellow_score+10;
	}
	if(y2_x[mover_y2]==r2_x[mover_r2] and y2_y[mover_y2]==r2_y[mover_r2] and mover_r2!=mover_r1 and mover_r3!=mover_r2 and mover_r2!=mover_r4){
	mover_r2=0;
	yellow_score=yellow_score+10;
	}
	if(y2_x[mover_y2]==r3_x[mover_r3] and y2_y[mover_y2]==r3_y[mover_r3] and mover_r3!=mover_r1 and mover_r3!=mover_r2 and mover_r3!=mover_r4){
	mover_r3=0;
	yellow_score=yellow_score+10;
	}
	if(y2_x[mover_y2]==r4_x[mover_r4] and y2_y[mover_y2]==r4_y[mover_r4] and mover_r4!=mover_r1 and mover_r4!=mover_r2 and mover_r3!=mover_r4){
	mover_r4=0;
	yellow_score=yellow_score+10;
	}
	
	
	

	}
}
void killing_by_y3()
{
if(mover_y3!=1 and mover_y3!=9 and mover_y3!=14 and mover_y3!=22 and mover_y3!=27 and mover_y3!=35 and mover_y3!=40 and mover_y3!=48)
	{
	
	
	if(y3_x[mover_y3]==g1_x[mover_g1] and y3_y[mover_y3]==g1_y[mover_g1] and mover_g2!=mover_g1 and mover_g3!=mover_g1 and mover_g1!=mover_g4)
	{
	mover_g1=0;
	yellow_score=yellow_score+10;
	}
	if(y3_x[mover_y3]==g2_x[mover_g2] and y3_y[mover_y3]==g2_y[mover_g2] and mover_g2!=mover_g1 and mover_g3!=mover_g2 and mover_g2!=mover_g4)
	{
	mover_g2=0;
	yellow_score=yellow_score+10;
	}
	if(y3_x[mover_y3]==g3_x[mover_g3] and y3_y[mover_y3]==g3_y[mover_g3]  and mover_g3!=mover_g1 and mover_g3!=mover_g2 and mover_g3!=mover_g4)
	{
	mover_g3=0;
	yellow_score=yellow_score+10;
	}
	if(y3_x[mover_y3]==g4_x[mover_g4] and y3_y[mover_y3]==g4_y[mover_g4] and mover_g4!=mover_g1 and mover_g4!=mover_g2 and mover_g3!=mover_g4)
	{
	mover_g4=0;
	yellow_score=yellow_score+10;
	}
	
	if(y3_x[mover_y3]==b1_x[mover_b1] and y3_y[mover_y3]==b1_y[mover_b1] and mover_b2!=mover_b1 and mover_b3!=mover_b1 and mover_b1!=mover_b4){
	mover_b1=0;
	yellow_score=yellow_score+10;
	}
	if(y3_x[mover_y3]==b2_x[mover_b2] and y3_y[mover_y3]==b2_y[mover_b2] and mover_b2!=mover_b1 and mover_b3!=mover_b2 and mover_b2!=mover_b4){
	mover_b2=0;
	yellow_score=yellow_score+10;
	}
	if(y3_x[mover_y3]==b3_x[mover_b3] and y3_y[mover_y3]==b3_y[mover_b3] and mover_b3!=mover_b1 and mover_b3!=mover_b2 and mover_b3!=mover_b4){
	mover_b3=0;
	yellow_score=yellow_score+10;
	}
	if(y3_x[mover_y3]==b4_x[mover_b4] and y3_y[mover_y3]==b4_y[mover_b4] and mover_b4!=mover_b1 and mover_b4!=mover_b2 and mover_b3!=mover_b4){
	mover_b4=0;
	yellow_score=yellow_score+10;
	}
	if(y3_x[mover_y3]==r1_x[mover_r1] and y3_y[mover_y3]==r1_y[mover_r1] and mover_r2!=mover_r1 and mover_r3!=mover_r1 and mover_r1!=mover_r4){
	mover_r1=0;
	yellow_score=yellow_score+10;
	}
	if(y3_x[mover_y3]==r2_x[mover_r2] and y3_y[mover_y3]==r2_y[mover_r2] and mover_r2!=mover_r1 and mover_r3!=mover_r2 and mover_r2!=mover_r4){
	mover_r2=0;
	yellow_score=yellow_score+10;
	}
	if(y3_x[mover_y3]==r3_x[mover_r3] and y3_y[mover_y3]==r3_y[mover_r3] and mover_r3!=mover_r1 and mover_r3!=mover_r2 and mover_r3!=mover_r4){
	mover_r3=0;
	yellow_score=yellow_score+10;
	}
	if(y3_x[mover_y3]==r4_x[mover_r4] and y3_y[mover_y3]==r4_y[mover_r4] and mover_r4!=mover_r1 and mover_r4!=mover_r2 and mover_r3!=mover_r4){
	mover_r4=0;
	yellow_score=yellow_score+10;
	}
	
	
	

	}
}

void killing_by_y4()
{
if(mover_y4!=1 and mover_y4!=9 and mover_y4!=14 and mover_y4!=22 and mover_y4!=27 and mover_y4!=35 and mover_y4!=40 and mover_y4!=48)
	{
	
	
	if(y4_x[mover_y4]==g1_x[mover_g1] and y4_y[mover_y4]==g1_y[mover_g1] and mover_g2!=mover_g1 and mover_g3!=mover_g1 and mover_g1!=mover_g4)
	{
	mover_g1=0;
	yellow_score=yellow_score+10;
	}
	if(y4_x[mover_y4]==g2_x[mover_g2] and y4_y[mover_y4]==g2_y[mover_g2] and mover_g2!=mover_g1 and mover_g3!=mover_g2 and mover_g2!=mover_g4)
	{
	mover_g2=0;
	yellow_score=yellow_score+10;
	}
	if(y4_x[mover_y4]==g3_x[mover_g3] and y4_y[mover_y4]==g3_y[mover_g3]  and mover_g3!=mover_g1 and mover_g3!=mover_g2 and mover_g3!=mover_g4)
	{
	mover_g3=0;
	yellow_score=yellow_score+10;
	}
	if(y4_x[mover_y4]==g4_x[mover_g4] and y4_y[mover_y4]==g4_y[mover_g4] and mover_g4!=mover_g1 and mover_g4!=mover_g2 and mover_g3!=mover_g4)
	{
	mover_g4=0;
	yellow_score=yellow_score+10;
	}
	
	if(y4_x[mover_y4]==b1_x[mover_b1] and y4_y[mover_y4]==b1_y[mover_b1] and mover_b2!=mover_b1 and mover_b3!=mover_b1 and mover_b1!=mover_b4){
	mover_b1=0;
	yellow_score=yellow_score+10;
	}
	if(y4_x[mover_y4]==b2_x[mover_b2] and y4_y[mover_y4]==b2_y[mover_b2] and mover_b2!=mover_b1 and mover_b3!=mover_b2 and mover_b2!=mover_b4){
	mover_b2=0;
	yellow_score=yellow_score+10;
	}
	if(y4_x[mover_y4]==b3_x[mover_b3] and y4_y[mover_y4]==b3_y[mover_b3] and mover_b3!=mover_b1 and mover_b3!=mover_b2 and mover_b3!=mover_b4){
	mover_b3=0;
	yellow_score=yellow_score+10;
	}
	if(y4_x[mover_y4]==b4_x[mover_b4] and y4_y[mover_y4]==b4_y[mover_b4] and mover_b4!=mover_b1 and mover_b4!=mover_b2 and mover_b3!=mover_b4){
	mover_b4=0;
	yellow_score=yellow_score+10;
	}
	if(y4_x[mover_y4]==r1_x[mover_r1] and y4_y[mover_y4]==r1_y[mover_r1] and mover_r2!=mover_r1 and mover_r3!=mover_r1 and mover_r1!=mover_r4){
	mover_r1=0;
	yellow_score=yellow_score+10;
	}
	if(y4_x[mover_y4]==r2_x[mover_r2] and y4_y[mover_y4]==r2_y[mover_r2] and mover_r2!=mover_r1 and mover_r3!=mover_r2 and mover_r2!=mover_r4){
	mover_r2=0;
	yellow_score=yellow_score+10;
	}
	if(y4_x[mover_y4]==r3_x[mover_r3] and y4_y[mover_y4]==r3_y[mover_r3] and mover_r3!=mover_r1 and mover_r3!=mover_r2 and mover_r3!=mover_r4){
	mover_r3=0;
	yellow_score=yellow_score+10;
	}
	if(y4_x[mover_y4]==r4_x[mover_r4] and y4_y[mover_y4]==r4_y[mover_r4] and mover_r4!=mover_r1 and mover_r4!=mover_r2 and mover_r3!=mover_r4){
	mover_r4=0;
	yellow_score=yellow_score+10;
	}
	
	
	

	}
}
void killing_by_b1(){
if(mover_b1!=1 and mover_b1!=9 and mover_b1!=14 and mover_b1!=22 and mover_b1!=27 and mover_b1!=35 and mover_b1!=40 and mover_b1!=48)
		{
		if(b1_x[mover_b1]==r1_x[mover_r1] and b1_y[mover_b1]==r1_y[mover_r1] and (mover_r1!=mover_r2) and (mover_r1!=mover_r4) and (mover_r1!=mover_r3)){
		mover_r1=0;
		blue_score=blue_score+10;
		}
		if(b1_x[mover_b1]==r2_x[mover_r2] and b1_y[mover_b1]==r2_y[mover_r2] and (mover_r1!=mover_r2) and (mover_r2!=mover_r4) and (mover_r2!=mover_r3)){
		mover_r2=0;
		blue_score=blue_score+10;
		}
		if(b1_x[mover_b1]==r3_x[mover_r3] and b1_y[mover_b1]==r3_y[mover_r3] and (mover_r3!=mover_r4) and (mover_r2!=mover_r3) and (mover_r1!=mover_r3)){
		mover_r3=0;
		blue_score=blue_score+10;
		}
		if(b1_x[mover_b1]==r4_x[mover_r4] and b1_y[mover_b1]==r4_y[mover_r4] and (mover_r1!=mover_r4) and (mover_r2!=mover_r4) and (mover_r1!=mover_r3)){
		mover_r4=0;
		 blue_score=blue_score+10;
		 }
		if(b1_x[mover_b1]==y1_x[mover_y1] and b1_y[mover_b1]==y1_y[mover_y1] and (mover_y1!=mover_y2) and (mover_y1!=mover_y3) and (mover_y1!=mover_y4)){
		mover_y1=0;
		blue_score=blue_score+10;
		}
		if(b1_x[mover_b1]==y2_x[mover_y2] and b1_y[mover_b1]==y2_y[mover_y2]  and (mover_y1!=mover_y2) and (mover_y2!=mover_y3) and (mover_y2!=mover_y4)){
		mover_y2=0;
		blue_score=blue_score+10;
		}
		if(b1_x[mover_b1]==y3_x[mover_y3] and b1_y[mover_b1]==y3_y[mover_y3]  and (mover_y1!=mover_y3) and (mover_y2!=mover_y3) and (mover_y3!=mover_y4)){
		mover_y3=0;
		blue_score=blue_score+10;
		}
		if(b1_x[mover_b1]==y4_x[mover_y4] and b1_y[mover_b1]==y4_y[mover_y4]  and (mover_y1!=mover_y4) and mover_y2!=mover_y4 and (mover_y3!=mover_y4)){
		mover_y4=0;
		blue_score=blue_score+10;
		}
		if(b1_x[mover_b1]==g1_x[mover_g1] and b1_y[mover_b1]==g1_y[mover_g1] and mover_g1!=mover_g2 and mover_g3!=mover_g1 and mover_g1!=mover_g4){
		mover_g1=0;
		blue_score=blue_score+10;
		}
		if(b1_x[mover_b1]==g2_x[mover_g2] and b1_y[mover_b1]==g2_y[mover_g2] and (mover_g1!=mover_g2) and mover_g3!=mover_g2 and mover_g2!=mover_g4){
		mover_g2=0;
		blue_score=blue_score+10;
		}
		if(b1_x[mover_b1]==g3_x[mover_g3] and b1_y[mover_b1]==g3_y[mover_g3] and (mover_g1!=mover_g3) and mover_g2!=mover_g3 and mover_g3!=mover_g4){
		mover_g3=0;
		blue_score=blue_score+10;
		}
		if(b1_x[mover_b1]==g4_x[mover_g4] and b1_y[mover_b1]==g4_y[mover_g4] and (mover_g4!=mover_g3) and mover_g2!=mover_g4 and mover_g1!=mover_g4){
		mover_g4=0;
		blue_score=blue_score+10;
		}
		}
		}
		
void killing_by_b2(){
if(mover_b2!=1 and mover_b2!=9 and mover_b2!=14 and mover_b2!=22 and mover_b2!=27 and mover_b2!=35 and mover_b2!=40 and mover_b2!=48)
		{
		if(b2_x[mover_b2]==r1_x[mover_r1] and b2_y[mover_b2]==r1_y[mover_r1] and (mover_r1!=mover_r2) and (mover_r1!=mover_r4) and (mover_r1!=mover_r3)){
		mover_r1=0;
		blue_score=blue_score+10;
		}
		if(b2_x[mover_b2]==r2_x[mover_r2] and b2_y[mover_b2]==r2_y[mover_r2] and (mover_r1!=mover_r2) and (mover_r2!=mover_r4) and (mover_r2!=mover_r3)){
		mover_r2=0;
		blue_score=blue_score+10;
		}
		if(b2_x[mover_b2]==r3_x[mover_r3] and b2_y[mover_b2]==r3_y[mover_r3] and (mover_r3!=mover_r4) and (mover_r2!=mover_r3) and (mover_r1!=mover_r3)){
		mover_r3=0;
		blue_score=blue_score+10;
		}
		if(b2_x[mover_b2]==r4_x[mover_r4] and b2_y[mover_b2]==r4_y[mover_r4] and (mover_r1!=mover_r4) and (mover_r2!=mover_r4) and (mover_r1!=mover_r3)){
		mover_r4=0;
		 blue_score=blue_score+10;
		 }
		if(b2_x[mover_b2]==y1_x[mover_y1] and b2_y[mover_b2]==y1_y[mover_y1] and (mover_y1!=mover_y2) and (mover_y1!=mover_y3) and (mover_y1!=mover_y4)){
		mover_y1=0;
		blue_score=blue_score+10;
		}
		if(b2_x[mover_b2]==y2_x[mover_y2] and b2_y[mover_b2]==y2_y[mover_y2]  and (mover_y1!=mover_y2) and (mover_y2!=mover_y3) and (mover_y2!=mover_y4)){
		mover_y2=0;
		blue_score=blue_score+10;
		}
		if(b2_x[mover_b2]==y3_x[mover_y3] and b2_y[mover_b2]==y3_y[mover_y3]  and (mover_y1!=mover_y3) and (mover_y2!=mover_y3) and (mover_y3!=mover_y4)){
		mover_y3=0;
		blue_score=blue_score+10;
		}
		if(b2_x[mover_b2]==y4_x[mover_y4] and b2_y[mover_b2]==y4_y[mover_y4]  and (mover_y1!=mover_y4) and mover_y2!=mover_y4 and (mover_y3!=mover_y4)){
		mover_y4=0;
		blue_score=blue_score+10;
		}
		if(b2_x[mover_b2]==g1_x[mover_g1] and b2_y[mover_b2]==g1_y[mover_g1] and mover_g1!=mover_g2 and mover_g3!=mover_g1 and mover_g1!=mover_g4){
		mover_g1=0;
		blue_score=blue_score+10;
		}
		if(b2_x[mover_b2]==g2_x[mover_g2] and b2_y[mover_b2]==g2_y[mover_g2] and (mover_g1!=mover_g2) and mover_g3!=mover_g2 and mover_g2!=mover_g4){
		mover_g2=0;
		blue_score=blue_score+10;
		}
		if(b2_x[mover_b2]==g3_x[mover_g3] and b2_y[mover_b2]==g3_y[mover_g3] and (mover_g1!=mover_g3) and mover_g2!=mover_g3 and mover_g3!=mover_g4){
		mover_g3=0;
		blue_score=blue_score+10;
		}
		if(b2_x[mover_b2]==g4_x[mover_g4] and b2_y[mover_b2]==g4_y[mover_g4] and (mover_g4!=mover_g3) and mover_g2!=mover_g4 and mover_g1!=mover_g4){
		mover_g4=0;
		blue_score=blue_score+10;
		}
		}
		}
		
void killing_by_b3(){
if(mover_b3!=1 and mover_b3!=9 and mover_b3!=14 and mover_b3!=22 and mover_b3!=27 and mover_b3!=35 and mover_b3!=40 and mover_b3!=48)
		{
		if(b3_x[mover_b3]==r1_x[mover_r1] and b3_y[mover_b3]==r1_y[mover_r1] and (mover_r1!=mover_r2) and (mover_r1!=mover_r4) and (mover_r1!=mover_r3)){
		mover_r1=0;
		blue_score=blue_score+10;
		}
		if(b3_x[mover_b3]==r2_x[mover_r2] and b3_y[mover_b3]==r2_y[mover_r2] and (mover_r1!=mover_r2) and (mover_r2!=mover_r4) and (mover_r2!=mover_r3)){
		mover_r2=0;
		blue_score=blue_score+10;
		}
		if(b3_x[mover_b3]==r3_x[mover_r3] and b3_y[mover_b3]==r3_y[mover_r3] and (mover_r3!=mover_r4) and (mover_r2!=mover_r3) and (mover_r1!=mover_r3)){
		mover_r3=0;
		blue_score=blue_score+10;
		}
		if(b3_x[mover_b3]==r4_x[mover_r4] and b3_y[mover_b3]==r4_y[mover_r4] and (mover_r1!=mover_r4) and (mover_r2!=mover_r4) and (mover_r1!=mover_r3)){
		mover_r4=0;
		 blue_score=blue_score+10;
		 }
		if(b3_x[mover_b3]==y1_x[mover_y1] and b3_y[mover_b3]==y1_y[mover_y1] and (mover_y1!=mover_y2) and (mover_y1!=mover_y3) and (mover_y1!=mover_y4)){
		mover_y1=0;
		blue_score=blue_score+10;
		}
		if(b3_x[mover_b3]==y2_x[mover_y2] and b3_y[mover_b3]==y2_y[mover_y2]  and (mover_y1!=mover_y2) and (mover_y2!=mover_y3) and (mover_y2!=mover_y4)){
		mover_y2=0;
		blue_score=blue_score+10;
		}
		if(b3_x[mover_b3]==y3_x[mover_y3] and b3_y[mover_b3]==y3_y[mover_y3]  and (mover_y1!=mover_y3) and (mover_y2!=mover_y3) and (mover_y3!=mover_y4)){
		mover_y3=0;
		blue_score=blue_score+10;
		}
		if(b3_x[mover_b3]==y4_x[mover_y4] and b3_y[mover_b3]==y4_y[mover_y4]  and (mover_y1!=mover_y4) and mover_y2!=mover_y4 and (mover_y3!=mover_y4)){
		mover_y4=0;
		blue_score=blue_score+10;
		}
		if(b3_x[mover_b3]==g1_x[mover_g1] and b3_y[mover_b3]==g1_y[mover_g1] and mover_g1!=mover_g2 and mover_g3!=mover_g1 and mover_g1!=mover_g4){
		mover_g1=0;
		blue_score=blue_score+10;
		}
		if(b3_x[mover_b3]==g2_x[mover_g2] and b3_y[mover_b3]==g2_y[mover_g2] and (mover_g1!=mover_g2) and mover_g3!=mover_g2 and mover_g2!=mover_g4){
		mover_g2=0;
		blue_score=blue_score+10;
		}
		if(b3_x[mover_b3]==g3_x[mover_g3] and b3_y[mover_b3]==g3_y[mover_g3] and (mover_g1!=mover_g3) and mover_g2!=mover_g3 and mover_g3!=mover_g4){
		mover_g3=0;
		blue_score=blue_score+10;
		}
		if(b3_x[mover_b3]==g4_x[mover_g4] and b3_y[mover_b3]==g4_y[mover_g4] and (mover_g4!=mover_g3) and mover_g2!=mover_g4 and mover_g1!=mover_g4){
		mover_g4=0;
		blue_score=blue_score+10;
		}
		}
		}
		
void killing_by_b4(){
if(mover_b4!=1 and mover_b4!=9 and mover_b4!=14 and mover_b4!=22 and mover_b4!=27 and mover_b4!=35 and mover_b4!=40 and mover_b4!=48)
		{
		if(b4_x[mover_b4]==r1_x[mover_r1] and b4_y[mover_b4]==r1_y[mover_r1] and (mover_r1!=mover_r2) and (mover_r1!=mover_r4) and (mover_r1!=mover_r3)){
		mover_r1=0;
		blue_score=blue_score+10;
		}
		if(b4_x[mover_b4]==r2_x[mover_r2] and b4_y[mover_b4]==r2_y[mover_r2] and (mover_r1!=mover_r2) and (mover_r2!=mover_r4) and (mover_r2!=mover_r3)){
		mover_r2=0;
		blue_score=blue_score+10;
		}
		if(b4_x[mover_b4]==r3_x[mover_r3] and b4_y[mover_b4]==r3_y[mover_r3] and (mover_r3!=mover_r4) and (mover_r2!=mover_r3) and (mover_r1!=mover_r3)){
		mover_r3=0;
		blue_score=blue_score+10;
		}
		if(b4_x[mover_b4]==r4_x[mover_r4] and b4_y[mover_b4]==r4_y[mover_r4] and (mover_r1!=mover_r4) and (mover_r2!=mover_r4) and (mover_r1!=mover_r3)){
		mover_r4=0;
		 blue_score=blue_score+10;
		 }
		if(b4_x[mover_b4]==y1_x[mover_y1] and b4_y[mover_b4]==y1_y[mover_y1] and (mover_y1!=mover_y2) and (mover_y1!=mover_y3) and (mover_y1!=mover_y4)){
		mover_y1=0;
		blue_score=blue_score+10;
		}
		if(b4_x[mover_b4]==y2_x[mover_y2] and b4_y[mover_b4]==y2_y[mover_y2]  and (mover_y1!=mover_y2) and (mover_y2!=mover_y3) and (mover_y2!=mover_y4)){
		mover_y2=0;
		blue_score=blue_score+10;
		}
		if(b4_x[mover_b4]==y3_x[mover_y3] and b4_y[mover_b4]==y3_y[mover_y3]  and (mover_y1!=mover_y3) and (mover_y2!=mover_y3) and (mover_y3!=mover_y4)){
		mover_y3=0;
		blue_score=blue_score+10;
		}
		if(b4_x[mover_b4]==y4_x[mover_y4] and b4_y[mover_b4]==y4_y[mover_y4]  and (mover_y1!=mover_y4) and mover_y2!=mover_y4 and (mover_y3!=mover_y4)){
		mover_y4=0;
		blue_score=blue_score+10;
		}
		if(b4_x[mover_b4]==g1_x[mover_g1] and b4_y[mover_b4]==g1_y[mover_g1] and mover_g1!=mover_g2 and mover_g3!=mover_g1 and mover_g1!=mover_g4){
		mover_g1=0;
		blue_score=blue_score+10;
		}
		if(b4_x[mover_b4]==g2_x[mover_g2] and b4_y[mover_b4]==g2_y[mover_g2] and (mover_g1!=mover_g2) and mover_g3!=mover_g2 and mover_g2!=mover_g4){
		mover_g2=0;
		blue_score=blue_score+10;
		}
		if(b4_x[mover_b4]==g3_x[mover_g3] and b4_y[mover_b4]==g3_y[mover_g3] and (mover_g1!=mover_g3) and mover_g2!=mover_g3 and mover_g3!=mover_g4){
		mover_g3=0;
		blue_score=blue_score+10;
		}
		if(b4_x[mover_b4]==g4_x[mover_g4] and b4_y[mover_b4]==g4_y[mover_g4] and (mover_g4!=mover_g3) and mover_g2!=mover_g4 and mover_g1!=mover_g4){
		mover_g4=0;
		blue_score=blue_score+10;
		}
		}
		}
		
void killing_by_g4(){
if(mover_g4!=1 and mover_g4!=9 and mover_g4!=14 and mover_g4!=22 and mover_g4!=27 and mover_g4!=35 and mover_g4!=40 and mover_g4!=48)
		{
		if(r1_x[mover_r1]==g4_x[mover_g4] and r1_y[mover_r1]==g4_y[mover_g4]  and (mover_r1!=mover_r2) and (mover_r1!=mover_r3) and (mover_r1!=mover_r4)){
		mover_r1=0;
		green_score=green_score+10;
		}
		if(r2_x[mover_r2]==g4_x[mover_g4] and r2_y[mover_r2]==g4_y[mover_g4] and (mover_r1!=mover_r2) and (mover_r2!=mover_r3) and (mover_r2!=mover_r4)){
		mover_r2=0;
		green_score=green_score+10;
		}
		if(r3_x[mover_r3]==g4_x[mover_g4] and r3_y[mover_r3]==g4_y[mover_g4] and (mover_r1!=mover_r3) and (mover_r2!=mover_r3) and (mover_r3!=mover_r4)){
		mover_r3=0;
		green_score=green_score+10;
		}
		if(r4_x[mover_r4]==g4_x[mover_g4] and r4_y[mover_r4]==g4_y[mover_g4] and (mover_r1!=mover_r4) and (mover_r4!=mover_r3) and (mover_r2!=mover_r4)){
		mover_r4=0;
		green_score=green_score+10;
		}
		
		if(y1_x[mover_y1]==g4_x[mover_g4] and y1_y[mover_y1]==g4_y[mover_g4] and mover_y1!=mover_y2 and mover_y1!=mover_y3 and mover_y1!=mover_y4){
		mover_y1=0;
		green_score=green_score+10;
		}
		if(y2_x[mover_y2]==g4_x[mover_g4] and y2_y[mover_y2]==g4_y[mover_g4] and mover_y1!=mover_y2 and mover_y2!=mover_y3 and mover_y2!=mover_y4){
		mover_y2=0;
		green_score=green_score+10;
		}
		if(y3_x[mover_y3]==g4_x[mover_g4] and y3_y[mover_y3]==g4_y[mover_g4] and mover_y3!=mover_y2 and mover_y2!=mover_y3 and mover_y3!=mover_y4){
		mover_y3=0;
		green_score=green_score+10;
		}
		if(y4_x[mover_y4]==g4_x[mover_g4] and y4_y[mover_y4]==g4_y[mover_g4] and mover_y4!=mover_y2 and mover_y4!=mover_y3 and mover_y1!=mover_y4){
		mover_y4=0;
		green_score=green_score+10;
		}
		if(b1_x[mover_b1]==g4_x[mover_g4] and b1_y[mover_b1]==g4_y[mover_g4] and mover_b1!=mover_b2 and mover_b1!=mover_b3 and mover_b1!=mover_b4){
		mover_b1=0;
		green_score=green_score+10;
		}
		if(b2_x[mover_b2]==g4_x[mover_g4] and b2_y[mover_b2]==g4_y[mover_g4] and mover_b1!=mover_b2 and mover_b2!=mover_b3 and mover_b2!=mover_b4){
		mover_b2=0;
		green_score=green_score+10;
		}
		if(b3_x[mover_b3]==g4_x[mover_g4] and b3_y[mover_b3]==g4_y[mover_g4] and mover_b3!=mover_b2 and mover_b2!=mover_b3 and mover_b3!=mover_b4){
		mover_b3=0;
		green_score=green_score+10;
		}
		if(b4_x[mover_b4]==g4_x[mover_g4] and b4_y[mover_b4]==g4_y[mover_g4] and mover_b4!=mover_b2 and mover_b4!=mover_b3 and mover_b1!=mover_b4){
		mover_b4=0;
		green_score=green_score+10;
		}
		}

}

void killing_by_g3(){
if(mover_g3!=1 and mover_g3!=9 and mover_g3!=14 and mover_g3!=22 and mover_g3!=27 and mover_g3!=35 and mover_g3!=40 and mover_g3!=48)
		{
		if(r1_x[mover_r1]==g3_x[mover_g3] and r1_y[mover_r1]==g3_y[mover_g3]  and (mover_r1!=mover_r2) and (mover_r1!=mover_r3) and (mover_r1!=mover_r4)){
		mover_r1=0;
		green_score=green_score+10;
		}
		if(r2_x[mover_r2]==g3_x[mover_g3] and r2_y[mover_r2]==g3_y[mover_g3] and (mover_r1!=mover_r2) and (mover_r2!=mover_r3) and (mover_r2!=mover_r4)){
		mover_r2=0;
		green_score=green_score+10;
		}
		if(r3_x[mover_r3]==g3_x[mover_g3] and r3_y[mover_r3]==g3_y[mover_g3] and (mover_r1!=mover_r3) and (mover_r2!=mover_r3) and (mover_r3!=mover_r4)){
		mover_r3=0;
		green_score=green_score+10;
		}
		if(r4_x[mover_r4]==g3_x[mover_g3] and r4_y[mover_r4]==g3_y[mover_g3] and (mover_r1!=mover_r4) and (mover_r4!=mover_r3) and (mover_r2!=mover_r4)){
		mover_r4=0;
		green_score=green_score+10;
		}
		
		if(y1_x[mover_y1]==g3_x[mover_g3] and y1_y[mover_y1]==g3_y[mover_g3] and mover_y1!=mover_y2 and mover_y1!=mover_y3 and mover_y1!=mover_y4){
		mover_y1=0;
		green_score=green_score+10;
		}
		if(y2_x[mover_y2]==g3_x[mover_g3] and y2_y[mover_y2]==g3_y[mover_g3] and mover_y1!=mover_y2 and mover_y2!=mover_y3 and mover_y2!=mover_y4){
		mover_y2=0;
		green_score=green_score+10;
		}
		if(y3_x[mover_y3]==g3_x[mover_g3] and y3_y[mover_y3]==g3_y[mover_g3] and mover_y3!=mover_y2 and mover_y2!=mover_y3 and mover_y3!=mover_y4){
		mover_y3=0;
		green_score=green_score+10;
		}
		if(y4_x[mover_y4]==g3_x[mover_g3] and y4_y[mover_y4]==g3_y[mover_g3] and mover_y4!=mover_y2 and mover_y4!=mover_y3 and mover_y1!=mover_y4){
		mover_y4=0;
		green_score=green_score+10;
		}
		if(b1_x[mover_b1]==g3_x[mover_g3] and b1_y[mover_b1]==g3_y[mover_g3] and mover_b1!=mover_b2 and mover_b1!=mover_b3 and mover_b1!=mover_b4){
		mover_b1=0;
		green_score=green_score+10;
		}
		if(b2_x[mover_b2]==g3_x[mover_g3] and b2_y[mover_b2]==g3_y[mover_g3] and mover_b1!=mover_b2 and mover_b2!=mover_b3 and mover_b2!=mover_b4){
		mover_b2=0;
		green_score=green_score+10;
		}
		if(b3_x[mover_b3]==g3_x[mover_g3] and b3_y[mover_b3]==g3_y[mover_g3] and mover_b3!=mover_b2 and mover_b2!=mover_b3 and mover_b3!=mover_b4){
		mover_b3=0;
		green_score=green_score+10;
		}
		if(b4_x[mover_b4]==g3_x[mover_g3] and b4_y[mover_b4]==g3_y[mover_g3] and mover_b4!=mover_b2 and mover_b4!=mover_b3 and mover_b1!=mover_b4){
		mover_b4=0;
		green_score=green_score+10;
		}
		}

}

void killing_by_g2(){
if(mover_g2!=1 and mover_g2!=9 and mover_g2!=14 and mover_g2!=22 and mover_g2!=27 and mover_g2!=35 and mover_g2!=40 and mover_g2!=48)
		{
		if(r1_x[mover_r1]==g2_x[mover_g2] and r1_y[mover_r1]==g2_y[mover_g2]  and (mover_r1!=mover_r2) and (mover_r1!=mover_r3) and (mover_r1!=mover_r4)){
		mover_r1=0;
		green_score=green_score+10;
		}
		if(r2_x[mover_r2]==g2_x[mover_g2] and r2_y[mover_r2]==g2_y[mover_g2] and (mover_r1!=mover_r2) and (mover_r2!=mover_r3) and (mover_r2!=mover_r4)){
		mover_r2=0;
		green_score=green_score+10;
		}
		if(r3_x[mover_r3]==g2_x[mover_g2] and r3_y[mover_r3]==g2_y[mover_g2] and (mover_r1!=mover_r3) and (mover_r2!=mover_r3) and (mover_r3!=mover_r4)){
		mover_r3=0;
		green_score=green_score+10;
		}
		if(r4_x[mover_r4]==g2_x[mover_g2] and r4_y[mover_r4]==g2_y[mover_g2] and (mover_r1!=mover_r4) and (mover_r4!=mover_r3) and (mover_r2!=mover_r4)){
		mover_r4=0;
		green_score=green_score+10;
		}
		
		if(y1_x[mover_y1]==g2_x[mover_g2] and y1_y[mover_y1]==g2_y[mover_g2] and mover_y1!=mover_y2 and mover_y1!=mover_y3 and mover_y1!=mover_y4){
		mover_y1=0;
		green_score=green_score+10;
		}
		if(y2_x[mover_y2]==g2_x[mover_g2] and y2_y[mover_y2]==g2_y[mover_g2] and mover_y1!=mover_y2 and mover_y2!=mover_y3 and mover_y2!=mover_y4){
		mover_y2=0;
		green_score=green_score+10;
		}
		if(y3_x[mover_y3]==g2_x[mover_g2] and y3_y[mover_y3]==g2_y[mover_g2] and mover_y3!=mover_y2 and mover_y2!=mover_y3 and mover_y3!=mover_y4){
		mover_y3=0;
		green_score=green_score+10;
		}
		if(y4_x[mover_y4]==g2_x[mover_g2] and y4_y[mover_y4]==g2_y[mover_g2] and mover_y4!=mover_y2 and mover_y4!=mover_y3 and mover_y1!=mover_y4){
		mover_y4=0;
		green_score=green_score+10;
		}
		if(b1_x[mover_b1]==g2_x[mover_g2] and b1_y[mover_b1]==g2_y[mover_g2] and mover_b1!=mover_b2 and mover_b1!=mover_b3 and mover_b1!=mover_b4){
		mover_b1=0;
		green_score=green_score+10;
		}
		if(b2_x[mover_b2]==g2_x[mover_g2] and b2_y[mover_b2]==g2_y[mover_g2] and mover_b1!=mover_b2 and mover_b2!=mover_b3 and mover_b2!=mover_b4){
		mover_b2=0;
		green_score=green_score+10;
		}
		if(b3_x[mover_b3]==g2_x[mover_g2] and b3_y[mover_b3]==g2_y[mover_g2] and mover_b3!=mover_b2 and mover_b2!=mover_b3 and mover_b3!=mover_b4){
		mover_b3=0;
		green_score=green_score+10;
		}
		if(b4_x[mover_b4]==g2_x[mover_g2] and b4_y[mover_b4]==g2_y[mover_g2] and mover_b4!=mover_b2 and mover_b4!=mover_b3 and mover_b1!=mover_b4){
		mover_b4=0;
		green_score=green_score+10;
		}
		}

}
void killing_by_g1(){
if(mover_g1!=1 and mover_g1!=9 and mover_g1!=14 and mover_g1!=22 and mover_g1!=27 and mover_g1!=35 and mover_g1!=40 and mover_g1!=48)
		{
		if(r1_x[mover_r1]==g1_x[mover_g1] and r1_y[mover_r1]==g1_y[mover_g1]  and (mover_r1!=mover_r2) and (mover_r1!=mover_r3) and (mover_r1!=mover_r4)){
		mover_r1=0;
		green_score=green_score+10;
		}
		if(r2_x[mover_r2]==g1_x[mover_g1] and r2_y[mover_r2]==g1_y[mover_g1] and (mover_r1!=mover_r2) and (mover_r2!=mover_r3) and (mover_r2!=mover_r4)){
		mover_r2=0;
		green_score=green_score+10;
		}
		if(r3_x[mover_r3]==g1_x[mover_g1] and r3_y[mover_r3]==g1_y[mover_g1] and (mover_r1!=mover_r3) and (mover_r2!=mover_r3) and (mover_r3!=mover_r4)){
		mover_r3=0;
		green_score=green_score+10;
		}
		if(r4_x[mover_r4]==g1_x[mover_g1] and r4_y[mover_r4]==g1_y[mover_g1] and (mover_r1!=mover_r4) and (mover_r4!=mover_r3) and (mover_r2!=mover_r4)){
		mover_r4=0;
		green_score=green_score+10;
		}
		
		if(y1_x[mover_y1]==g1_x[mover_g1] and y1_y[mover_y1]==g1_y[mover_g1] and mover_y1!=mover_y2 and mover_y1!=mover_y3 and mover_y1!=mover_y4){
		mover_y1=0;
		green_score=green_score+10;
		}
		if(y2_x[mover_y2]==g1_x[mover_g1] and y2_y[mover_y2]==g1_y[mover_g1] and mover_y1!=mover_y2 and mover_y2!=mover_y3 and mover_y2!=mover_y4){
		mover_y2=0;
		green_score=green_score+10;
		}
		if(y3_x[mover_y3]==g1_x[mover_g1] and y3_y[mover_y3]==g1_y[mover_g1] and mover_y3!=mover_y2 and mover_y2!=mover_y3 and mover_y3!=mover_y4){
		mover_y3=0;
		green_score=green_score+10;
		}
		if(y4_x[mover_y4]==g1_x[mover_g1] and y4_y[mover_y4]==g1_y[mover_g1] and mover_y4!=mover_y2 and mover_y4!=mover_y3 and mover_y1!=mover_y4){
		mover_y4=0;
		green_score=green_score+10;
		}
		if(b1_x[mover_b1]==g1_x[mover_g1] and b1_y[mover_b1]==g1_y[mover_g1] and mover_b1!=mover_b2 and mover_b1!=mover_b3 and mover_b1!=mover_b4){
		mover_b1=0;
		green_score=green_score+10;
		}
		if(b2_x[mover_b2]==g1_x[mover_g1] and b2_y[mover_b2]==g1_y[mover_g1] and mover_b1!=mover_b2 and mover_b2!=mover_b3 and mover_b2!=mover_b4){
		mover_b2=0;
		green_score=green_score+10;
		}
		if(b3_x[mover_b3]==g1_x[mover_g1] and b3_y[mover_b3]==g1_y[mover_g1] and mover_b3!=mover_b2 and mover_b2!=mover_b3 and mover_b3!=mover_b4){
		mover_b3=0;
		green_score=green_score+10;
		}
		if(b4_x[mover_b4]==g1_x[mover_g1] and b4_y[mover_b4]==g1_y[mover_g1] and mover_b4!=mover_b2 and mover_b4!=mover_b3 and mover_b1!=mover_b4){
		mover_b4=0;
		green_score=green_score+10;
		}
		}

}		
//THIS IS TO SEE IF THERE IS A BLOCK IN THE WAY OF MOVING TOKEN
int block_checker_r1()
       {
       int checker=mover_r1+1, found=0, counter=0;
       while(counter<dice_number){
			if(mover_b1==mover_b2 and b1_x[mover_b1]==r1_x[checker] and b1_y[mover_b1]==r1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b2 and b3_x[mover_b3]==r1_x[checker] and b3_y[mover_b3]==r1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b4 and b4_x[mover_b4]==r1_x[checker] and b4_y[mover_b4]==r1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b1 and b1_x[mover_b1]==r1_x[checker] and b1_y[mover_b1]==r1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b1==mover_b4 and b4_x[mover_b4]==r1_x[checker] and b4_y[mover_b4]==r1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b2==mover_b4 and b4_x[mover_b4]==r1_x[checker] and b4_y[mover_b4]==r1_y[checker])
		{
		found=1;
		break;
		}
		
	
		if(mover_g1==mover_g2 and g1_x[mover_g1]==r1_x[checker] and g1_y[mover_g1]==r1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g2 and g3_x[mover_g3]==r1_x[checker] and g3_y[mover_g3]==r1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g4 and g4_x[mover_g4]==r1_x[checker] and g4_y[mover_g4]==r1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g1 and g1_x[mover_g1]==r1_x[checker] and g1_y[mover_g1]==r1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g1==mover_g4 and g4_x[mover_g4]==r1_x[checker] and g4_y[mover_g4]==r1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g2==mover_g4 and g4_x[mover_g4]==r1_x[checker] and g4_y[mover_g4]==r1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y1==mover_y2 and y1_x[mover_y1]==r1_x[checker] and y1_y[mover_y1]==r1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y2 and y3_x[mover_y3]==r1_x[checker] and y3_y[mover_y3]==r1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y4 and y4_x[mover_y4]==r1_x[checker] and y4_y[mover_y4]==r1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y1 and y1_x[mover_y1]==r1_x[checker] and y1_y[mover_y1]==r1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y1==mover_y4 and y4_x[mover_y4]==r1_x[checker] and y4_y[mover_y4]==r1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y2==mover_y4 and y4_x[mover_y4]==r1_x[checker] and y4_y[mover_y4]==r1_y[checker])
		{
		found=1;
		break;
		}
		counter++;
		checker++;
		}
		return found;
		
		}
		
		int block_checker_r2()
       {
       int checker=mover_r2+1, found=0, counter=0;
       while(counter<dice_number){
			if(mover_b1==mover_b2 and b1_x[mover_b1]==r2_x[checker] and b1_y[mover_b1]==r2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b2 and b3_x[mover_b3]==r2_x[checker] and b3_y[mover_b3]==r2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b4 and b4_x[mover_b4]==r2_x[checker] and b4_y[mover_b4]==r2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b1 and b1_x[mover_b1]==r2_x[checker] and b1_y[mover_b1]==r2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b1==mover_b4 and b4_x[mover_b4]==r2_x[checker] and b4_y[mover_b4]==r2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b2==mover_b4 and b4_x[mover_b4]==r2_x[checker] and b4_y[mover_b4]==r2_y[checker])
		{
		found=1;
		break;
		}
		
	
		if(mover_g1==mover_g2 and g1_x[mover_g1]==r2_x[checker] and g1_y[mover_g1]==r2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g2 and g3_x[mover_g3]==r2_x[checker] and g3_y[mover_g3]==r2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g4 and g4_x[mover_g4]==r2_x[checker] and g4_y[mover_g4]==r2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g1 and g1_x[mover_g1]==r2_x[checker] and g1_y[mover_g1]==r2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g1==mover_g4 and g4_x[mover_g4]==r2_x[checker] and g4_y[mover_g4]==r2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g2==mover_g4 and g4_x[mover_g4]==r2_x[checker] and g4_y[mover_g4]==r2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y1==mover_y2 and y1_x[mover_y1]==r2_x[checker] and y1_y[mover_y1]==r2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y2 and y3_x[mover_y3]==r2_x[checker] and y3_y[mover_y3]==r2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y4 and y4_x[mover_y4]==r2_x[checker] and y4_y[mover_y4]==r2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y1 and y1_x[mover_y1]==r2_x[checker] and y1_y[mover_y1]==r2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y1==mover_y4 and y4_x[mover_y4]==r2_x[checker] and y4_y[mover_y4]==r2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y2==mover_y4 and y4_x[mover_y4]==r2_x[checker] and y4_y[mover_y4]==r2_y[checker])
		{
		found=1;
		break;
		}
		counter++;
		checker++;
		}
		return found;
		
		}
		
		int block_checker_r3()
       {
       int checker=mover_r3+1, found=0, counter=0;
       while(counter<dice_number){
			if(mover_b1==mover_b2 and b1_x[mover_b1]==r3_x[checker] and b1_y[mover_b1]==r3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b2 and b3_x[mover_b3]==r3_x[checker] and b3_y[mover_b3]==r3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b4 and b4_x[mover_b4]==r3_x[checker] and b4_y[mover_b4]==r3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b1 and b1_x[mover_b1]==r3_x[checker] and b1_y[mover_b1]==r3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b1==mover_b4 and b4_x[mover_b4]==r3_x[checker] and b4_y[mover_b4]==r3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b2==mover_b4 and b4_x[mover_b4]==r3_x[checker] and b4_y[mover_b4]==r3_y[checker])
		{
		found=1;
		break;
		}
		
	
		if(mover_g1==mover_g2 and g1_x[mover_g1]==r3_x[checker] and g1_y[mover_g1]==r3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g2 and g3_x[mover_g3]==r3_x[checker] and g3_y[mover_g3]==r3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g4 and g4_x[mover_g4]==r3_x[checker] and g4_y[mover_g4]==r3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g1 and g1_x[mover_g1]==r3_x[checker] and g1_y[mover_g1]==r3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g1==mover_g4 and g4_x[mover_g4]==r3_x[checker] and g4_y[mover_g4]==r3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g2==mover_g4 and g4_x[mover_g4]==r3_x[checker] and g4_y[mover_g4]==r3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y1==mover_y2 and y1_x[mover_y1]==r3_x[checker] and y1_y[mover_y1]==r3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y2 and y3_x[mover_y3]==r3_x[checker] and y3_y[mover_y3]==r3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y4 and y4_x[mover_y4]==r3_x[checker] and y4_y[mover_y4]==r3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y1 and y1_x[mover_y1]==r3_x[checker] and y1_y[mover_y1]==r3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y1==mover_y4 and y4_x[mover_y4]==r3_x[checker] and y4_y[mover_y4]==r3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y2==mover_y4 and y4_x[mover_y4]==r3_x[checker] and y4_y[mover_y4]==r3_y[checker])
		{
		found=1;
		break;
		}
		counter++;
		checker++;
		}
		return found;
		
		}
		int block_checker_r4()
       {
       int checker=mover_r4+1, found=0, counter=0;
       while(counter<dice_number){
			if(mover_b1==mover_b2 and b1_x[mover_b1]==r4_x[checker] and b1_y[mover_b1]==r4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b2 and b3_x[mover_b3]==r4_x[checker] and b3_y[mover_b3]==r4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b4 and b4_x[mover_b4]==r4_x[checker] and b4_y[mover_b4]==r4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b1 and b1_x[mover_b1]==r4_x[checker] and b1_y[mover_b1]==r4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b1==mover_b4 and b4_x[mover_b4]==r4_x[checker] and b4_y[mover_b4]==r4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b2==mover_b4 and b4_x[mover_b4]==r4_x[checker] and b4_y[mover_b4]==r4_y[checker])
		{
		found=1;
		break;
		}
		
	
		if(mover_g1==mover_g2 and g1_x[mover_g1]==r4_x[checker] and g1_y[mover_g1]==r4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g2 and g3_x[mover_g3]==r4_x[checker] and g3_y[mover_g3]==r4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g4 and g4_x[mover_g4]==r4_x[checker] and g4_y[mover_g4]==r4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g1 and g1_x[mover_g1]==r4_x[checker] and g1_y[mover_g1]==r4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g1==mover_g4 and g4_x[mover_g4]==r4_x[checker] and g4_y[mover_g4]==r4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g2==mover_g4 and g4_x[mover_g4]==r4_x[checker] and g4_y[mover_g4]==r4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y1==mover_y2 and y1_x[mover_y1]==r4_x[checker] and y1_y[mover_y1]==r4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y2 and y3_x[mover_y3]==r4_x[checker] and y3_y[mover_y3]==r4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y4 and y4_x[mover_y4]==r4_x[checker] and y4_y[mover_y4]==r4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y1 and y1_x[mover_y1]==r4_x[checker] and y1_y[mover_y1]==r4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y1==mover_y4 and y4_x[mover_y4]==r4_x[checker] and y4_y[mover_y4]==r4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y2==mover_y4 and y4_x[mover_y4]==r4_x[checker] and y4_y[mover_y4]==r4_y[checker])
		{
		found=1;
		break;
		}
		counter++;
		checker++;
		}
		return found;
		
		}
		
		int block_checker_b1()
       {
       int checker=mover_b1+1, found=0, counter=0;
       while(counter<dice_number){
			if(mover_r1==mover_r2 and b1_x[checker]==r1_x[mover_r1] and b1_y[checker]==r1_y[mover_r1])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r2 and r3_x[mover_r3]==b1_x[checker] and r3_y[mover_r3]==b1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r4 and r4_x[mover_r4]==b1_x[checker] and r4_y[mover_r4]==b1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r1 and b1_x[checker]==r1_x[mover_r1] and b1_y[checker]==r1_y[mover_r1])
		{
		found=1;
		break;
		}
		if(mover_r1==mover_r4 and r4_x[mover_r4]==b1_x[checker] and r4_y[mover_r4]==b1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r2==mover_r4 and r4_x[mover_r4]==b1_x[checker] and r4_y[mover_r4]==b1_y[checker])
		{
		found=1;
		break;
		}
		
	
		if(mover_g1==mover_g2 and g1_x[mover_g1]==b1_x[checker] and g1_y[mover_g1]==b1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g2 and g3_x[mover_g3]==b1_x[checker] and g3_y[mover_g3]==b1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g4 and g4_x[mover_g4]==b1_x[checker] and g4_y[mover_g4]==b1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g1 and g1_x[mover_g1]==b1_x[checker] and g1_y[mover_g1]==b1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g1==mover_g4 and g4_x[mover_g4]==b1_x[checker] and g4_y[mover_g4]==b1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g2==mover_g4 and g4_x[mover_g4]==b1_x[checker] and g4_y[mover_g4]==b1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y1==mover_y2 and y1_x[mover_y1]==b1_x[checker] and y1_y[mover_y1]==b1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y2 and y3_x[mover_y3]==b1_x[checker] and y3_y[mover_y3]==b1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y4 and y4_x[mover_y4]==b1_x[checker] and y4_y[mover_y4]==b1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y1 and y1_x[mover_y1]==b1_x[checker] and y1_y[mover_y1]==b1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y1==mover_y4 and y4_x[mover_y4]==b1_x[checker] and y4_y[mover_y4]==b1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y2==mover_y4 and y4_x[mover_y4]==b1_x[checker] and y4_y[mover_y4]==b1_y[checker])
		{
		found=1;
		break;
		}
		counter++;
		checker++;
		}
		return found;
		
		}
		
		int block_checker_b2()
       {
       int checker=mover_b2+1, found=0, counter=0;
       while(counter<dice_number){
			if(mover_r1==mover_r2 and b2_x[checker]==r1_x[mover_r1] and b2_y[checker]==r1_y[mover_r1])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r2 and r3_x[mover_r3]==b2_x[checker] and r3_y[mover_r3]==b2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r4 and r4_x[mover_r4]==b2_x[checker] and r4_y[mover_r4]==b2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r1 and b2_x[checker]==r1_x[mover_r1] and b2_y[checker]==r1_y[mover_r1])
		{
		found=1;
		break;
		}
		if(mover_r1==mover_r4 and r4_x[mover_r4]==b2_x[checker] and r4_y[mover_r4]==b2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r2==mover_r4 and r4_x[mover_r4]==b2_x[checker] and r4_y[mover_r4]==b2_y[checker])
		{
		found=1;
		break;
		}
		
	
		if(mover_g1==mover_g2 and g1_x[mover_g1]==b2_x[checker] and g1_y[mover_g1]==b2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g2 and g3_x[mover_g3]==b2_x[checker] and g3_y[mover_g3]==b2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g4 and g4_x[mover_g4]==b2_x[checker] and g4_y[mover_g4]==b2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g1 and g1_x[mover_g1]==b2_x[checker] and g1_y[mover_g1]==b2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g1==mover_g4 and g4_x[mover_g4]==b2_x[checker] and g4_y[mover_g4]==b2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g2==mover_g4 and g4_x[mover_g4]==b2_x[checker] and g4_y[mover_g4]==b2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y1==mover_y2 and y1_x[mover_y1]==b2_x[checker] and y1_y[mover_y1]==b2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y2 and y3_x[mover_y3]==b2_x[checker] and y3_y[mover_y3]==b2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y4 and y4_x[mover_y4]==b2_x[checker] and y4_y[mover_y4]==b2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y1 and y1_x[mover_y1]==b2_x[checker] and y1_y[mover_y1]==b2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y1==mover_y4 and y4_x[mover_y4]==b2_x[checker] and y4_y[mover_y4]==b2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y2==mover_y4 and y4_x[mover_y4]==b2_x[checker] and y4_y[mover_y4]==b2_y[checker])
		{
		found=1;
		break;
		}
		counter++;
		checker++;
		}
		return found;
		
		}
		
			int block_checker_b3()
       {
       int checker=mover_b3+1, found=0, counter=0;
       while(counter<dice_number){
			if(mover_r1==mover_r2 and b3_x[checker]==r1_x[mover_r1] and b3_y[checker]==r1_y[mover_r1])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r2 and r3_x[mover_r3]==b3_x[checker] and r3_y[mover_r3]==b3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r4 and r4_x[mover_r4]==b3_x[checker] and r4_y[mover_r4]==b3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r1 and b3_x[checker]==r1_x[mover_r1] and b3_y[checker]==r1_y[mover_r1])
		{
		found=1;
		break;
		}
		if(mover_r1==mover_r4 and r4_x[mover_r4]==b3_x[checker] and r4_y[mover_r4]==b3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r2==mover_r4 and r4_x[mover_r4]==b3_x[checker] and r4_y[mover_r4]==b3_y[checker])
		{
		found=1;
		break;
		}
		
	
		if(mover_g1==mover_g2 and g1_x[mover_g1]==b3_x[checker] and g1_y[mover_g1]==b3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g2 and g3_x[mover_g3]==b3_x[checker] and g3_y[mover_g3]==b3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g4 and g4_x[mover_g4]==b3_x[checker] and g4_y[mover_g4]==b3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g1 and g1_x[mover_g1]==b3_x[checker] and g1_y[mover_g1]==b3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g1==mover_g4 and g4_x[mover_g4]==b3_x[checker] and g4_y[mover_g4]==b3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g2==mover_g4 and g4_x[mover_g4]==b3_x[checker] and g4_y[mover_g4]==b3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y1==mover_y2 and y1_x[mover_y1]==b3_x[checker] and y1_y[mover_y1]==b3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y2 and y3_x[mover_y3]==b3_x[checker] and y3_y[mover_y3]==b3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y4 and y4_x[mover_y4]==b3_x[checker] and y4_y[mover_y4]==b3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y1 and y1_x[mover_y1]==b3_x[checker] and y1_y[mover_y1]==b3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y1==mover_y4 and y4_x[mover_y4]==b3_x[checker] and y4_y[mover_y4]==b3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y2==mover_y4 and y4_x[mover_y4]==b3_x[checker] and y4_y[mover_y4]==b3_y[checker])
		{
		found=1;
		break;
		}
		counter++;
		checker++;
		}
		return found;
		
		}
		
			int block_checker_b4()
       {
       int checker=mover_b4+1, found=0, counter=0;
       while(counter<dice_number){
			if(mover_r1==mover_r2 and b4_x[checker]==r1_x[mover_r1] and b4_y[checker]==r1_y[mover_r1])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r2 and r3_x[mover_r3]==b4_x[checker] and r3_y[mover_r3]==b4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r4 and r4_x[mover_r4]==b4_x[checker] and r4_y[mover_r4]==b4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r1 and b4_x[checker]==r1_x[mover_r1] and b4_y[checker]==r1_y[mover_r1])
		{
		found=1;
		break;
		}
		if(mover_r1==mover_r4 and r4_x[mover_r4]==b4_x[checker] and r4_y[mover_r4]==b4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r2==mover_r4 and r4_x[mover_r4]==b4_x[checker] and r4_y[mover_r4]==b4_y[checker])
		{
		found=1;
		break;
		}
		
	
		if(mover_g1==mover_g2 and g1_x[mover_g1]==b4_x[checker] and g1_y[mover_g1]==b4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g2 and g3_x[mover_g3]==b4_x[checker] and g3_y[mover_g3]==b4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g4 and g4_x[mover_g4]==b4_x[checker] and g4_y[mover_g4]==b4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g1 and g1_x[mover_g1]==b4_x[checker] and g1_y[mover_g1]==b4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g1==mover_g4 and g4_x[mover_g4]==b4_x[checker] and g4_y[mover_g4]==b4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g2==mover_g4 and g4_x[mover_g4]==b4_x[checker] and g4_y[mover_g4]==b4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y1==mover_y2 and y1_x[mover_y1]==b4_x[checker] and y1_y[mover_y1]==b4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y2 and y3_x[mover_y3]==b4_x[checker] and y3_y[mover_y3]==b4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y4 and y4_x[mover_y4]==b4_x[checker] and y4_y[mover_y4]==b4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y1 and y1_x[mover_y1]==b4_x[checker] and y1_y[mover_y1]==b4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y1==mover_y4 and y4_x[mover_y4]==b4_x[checker] and y4_y[mover_y4]==b4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y2==mover_y4 and y4_x[mover_y4]==b4_x[checker] and y4_y[mover_y4]==b4_y[checker])
		{
		found=1;
		break;
		}
		counter++;
		checker++;
		}
		return found;
		
		}
		
		int block_checker_g1()
       {
       int checker=mover_g1+1, found=0, counter=0;
       while(counter<dice_number){
		if(mover_r1==mover_r2 and g1_x[checker]==r1_x[mover_r1] and g1_y[checker]==r1_y[mover_r1])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r2 and r3_x[mover_r3]==g1_x[checker] and r3_y[mover_r3]==g1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r4 and r4_x[mover_r4]==g1_x[checker] and r4_y[mover_r4]==g1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r1 and g1_x[checker]==r1_x[mover_r1] and g1_y[checker]==r1_y[mover_r1])
		{
		found=1;
		break;
		}
		if(mover_r1==mover_r4 and r4_x[mover_r4]==g1_x[checker] and r4_y[mover_r4]==g1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r2==mover_r4 and r4_x[mover_r4]==g1_x[checker] and r4_y[mover_r4]==g1_y[checker])
		{
		found=1;
		break;
		}
		
	
		if(mover_b1==mover_b2 and g1_x[checker]==b1_x[mover_b1] and g1_y[checker]==b1_y[mover_b1])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b2 and b3_x[mover_b3]==g1_x[checker] and b3_y[mover_b3]==g1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b4 and b4_x[mover_b4]==g1_x[checker] and b4_y[mover_b4]==g1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b1 and b1_x[mover_b1]==g1_x[checker] and b1_y[mover_b1]==g1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b1==mover_b4 and b4_x[mover_b4]==g1_x[checker] and b4_y[mover_g4]==g1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b2==mover_b4 and g1_x[mover_g4]==b4_x[checker] and b4_y[mover_b4]==g1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y1==mover_y2 and y1_x[mover_y1]==g1_x[checker] and y1_y[mover_y1]==g1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y2 and y3_x[mover_y3]==g1_x[checker] and y3_y[mover_y3]==g1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y4 and y4_x[mover_y4]==g1_x[checker] and y4_y[mover_y4]==g1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y1 and y1_x[mover_y1]==g1_x[checker] and y1_y[mover_y1]==g1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y1==mover_y4 and y4_x[mover_y4]==g1_x[checker] and y4_y[mover_y4]==g1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y2==mover_y4 and y4_x[mover_y4]==g1_x[checker] and y4_y[mover_y4]==g1_y[checker])
		{
		found=1;
		break;
		}
		counter++;
		checker++;
		}
		return found;
		
		}
		
		int block_checker_g2()
       {
       int checker=mover_g2+1, found=0, counter=0;
       while(counter<dice_number){
			if(mover_r1==mover_r2 and g2_x[checker]==r1_x[mover_r1] and g2_y[checker]==r1_y[mover_r1])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r2 and r3_x[mover_r3]==g2_x[checker] and r3_y[mover_r3]==g2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r4 and r4_x[mover_r4]==g2_x[checker] and r4_y[mover_r4]==g2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r1 and g2_x[checker]==r1_x[mover_r1] and g2_y[checker]==r1_y[mover_r1])
		{
		found=1;
		break;
		}
		if(mover_r1==mover_r4 and r4_x[mover_r4]==g2_x[checker] and r4_y[mover_r4]==g2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r2==mover_r4 and r4_x[mover_r4]==g2_x[checker] and r4_y[mover_r4]==g2_y[checker])
		{
		found=1;
		break;
		}
		
	
		if(mover_b1==mover_b2 and g2_x[checker]==b1_x[mover_b1] and g2_y[checker]==b1_y[mover_b1])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b2 and b3_x[mover_b3]==g2_x[checker] and b3_y[mover_b3]==g2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b4 and b4_x[mover_b4]==g2_x[checker] and b4_y[mover_b4]==g2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b1 and b1_x[mover_b1]==g2_x[checker] and b1_y[mover_b1]==g2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b1==mover_b4 and b4_x[mover_b4]==g2_x[checker] and b4_y[mover_g4]==g2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b2==mover_b4 and g2_x[mover_g4]==b4_x[checker] and b4_y[mover_b4]==g2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y1==mover_y2 and y1_x[mover_y1]==g2_x[checker] and y1_y[mover_y1]==g2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y2 and y3_x[mover_y3]==g2_x[checker] and y3_y[mover_y3]==g2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y4 and y4_x[mover_y4]==g2_x[checker] and y4_y[mover_y4]==g2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y1 and y1_x[mover_y1]==g2_x[checker] and y1_y[mover_y1]==g2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y1==mover_y4 and y4_x[mover_y4]==g2_x[checker] and y4_y[mover_y4]==g2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y2==mover_y4 and y4_x[mover_y4]==g2_x[checker] and y4_y[mover_y4]==g2_y[checker])
		{
		found=1;
		break;
		}
		counter++;
		checker++;
		}
		return found;
		
		}
		
		
		int block_checker_g3()
       {
       int checker=mover_g3+1, found=0, counter=0;
       while(counter<dice_number){
			if(mover_r1==mover_r2 and g3_x[checker]==r1_x[mover_r1] and g3_y[checker]==r1_y[mover_r1])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r2 and r3_x[mover_r3]==g3_x[checker] and r3_y[mover_r3]==g3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r4 and r4_x[mover_r4]==g3_x[checker] and r4_y[mover_r4]==g3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r1 and g3_x[checker]==r1_x[mover_r1] and g3_y[checker]==r1_y[mover_r1])
		{
		found=1;
		break;
		}
		if(mover_r1==mover_r4 and r4_x[mover_r4]==g3_x[checker] and r4_y[mover_r4]==g3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r2==mover_r4 and r4_x[mover_r4]==g3_x[checker] and r4_y[mover_r4]==g3_y[checker])
		{
		found=1;
		break;
		}
		
	
		if(mover_b1==mover_b2 and g3_x[checker]==b1_x[mover_b1] and g3_y[checker]==b1_y[mover_b1])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b2 and b3_x[mover_b3]==g3_x[checker] and b3_y[mover_b3]==g3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b4 and b4_x[mover_b4]==g3_x[checker] and b4_y[mover_b4]==g3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b1 and b1_x[mover_b1]==g3_x[checker] and b1_y[mover_b1]==g3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b1==mover_b4 and b4_x[mover_b4]==g3_x[checker] and b4_y[mover_g4]==g3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b2==mover_b4 and g3_x[mover_g4]==b4_x[checker] and b4_y[mover_b4]==g3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y1==mover_y2 and y1_x[mover_y1]==g3_x[checker] and y1_y[mover_y1]==g3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y2 and y3_x[mover_y3]==g3_x[checker] and y3_y[mover_y3]==g3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y4 and y4_x[mover_y4]==g3_x[checker] and y4_y[mover_y4]==g3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y1 and y1_x[mover_y1]==g3_x[checker] and y1_y[mover_y1]==g3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y1==mover_y4 and y4_x[mover_y4]==g3_x[checker] and y4_y[mover_y4]==g3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y2==mover_y4 and y4_x[mover_y4]==g3_x[checker] and y4_y[mover_y4]==g3_y[checker])
		{
		found=1;
		break;
		}
		counter++;
		checker++;
		}
		return found;
		
		}
		
		int block_checker_g4()
       {
       int checker=mover_g4+1, found=0, counter=0;
       while(counter<dice_number){
			if(mover_r1==mover_r2 and g4_x[checker]==r1_x[mover_r1] and g4_y[checker]==r1_y[mover_r1])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r2 and r3_x[mover_r3]==g4_x[checker] and r3_y[mover_r3]==g4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r4 and r4_x[mover_r4]==g4_x[checker] and r4_y[mover_r4]==g4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r1 and g4_x[checker]==r1_x[mover_r1] and g4_y[checker]==r1_y[mover_r1])
		{
		found=1;
		break;
		}
		if(mover_r1==mover_r4 and r4_x[mover_r4]==g4_x[checker] and r4_y[mover_r4]==g4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r2==mover_r4 and r4_x[mover_r4]==g4_x[checker] and r4_y[mover_r4]==g4_y[checker])
		{
		found=1;
		break;
		}
		
	
		if(mover_b1==mover_b2 and g4_x[checker]==b1_x[mover_b1] and g4_y[checker]==b1_y[mover_b1])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b2 and b3_x[mover_b3]==g4_x[checker] and b3_y[mover_b3]==g4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b4 and b4_x[mover_b4]==g4_x[checker] and b4_y[mover_b4]==g4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b1 and b1_x[mover_b1]==g4_x[checker] and b1_y[mover_b1]==g4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b1==mover_b4 and b4_x[mover_b4]==g4_x[checker] and b4_y[mover_g4]==g4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b2==mover_b4 and g4_x[mover_g4]==b4_x[checker] and b4_y[mover_b4]==g4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y1==mover_y2 and y1_x[mover_y1]==g4_x[checker] and y1_y[mover_y1]==g4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y2 and y3_x[mover_y3]==g4_x[checker] and y3_y[mover_y3]==g4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y4 and y4_x[mover_y4]==g4_x[checker] and y4_y[mover_y4]==g4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y3==mover_y1 and y1_x[mover_y1]==g4_x[checker] and y1_y[mover_y1]==g4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y1==mover_y4 and y4_x[mover_y4]==g4_x[checker] and y4_y[mover_y4]==g4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_y2==mover_y4 and y4_x[mover_y4]==g4_x[checker] and y4_y[mover_y4]==g4_y[checker])
		{
		found=1;
		break;
		}
		counter++;
		checker++;
		}
		return found;
		
		}
		
		
		
	int block_checker_y1()
       {
       int checker=mover_y1+1, found=0, counter=0;
       while(counter<dice_number){
			if(mover_b1==mover_b2 and b1_x[mover_b1]==y1_x[checker] and b1_y[mover_b1]==y1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b2 and b3_x[mover_b3]==y1_x[checker] and b3_y[mover_b3]==y1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b4 and b4_x[mover_b4]==y1_x[checker] and b4_y[mover_b4]==y1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b1 and b1_x[mover_b1]==y1_x[checker] and b1_y[mover_b1]==y1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b1==mover_b4 and b4_x[mover_b4]==y1_x[checker] and b4_y[mover_b4]==y1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b2==mover_b4 and b4_x[mover_b4]==y1_x[checker] and b4_y[mover_b4]==y1_y[checker])
		{
		found=1;
		break;
		}
		
	
		if(mover_g1==mover_g2 and g1_x[mover_g1]==y1_x[checker] and g1_y[mover_g1]==y1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g2 and g3_x[mover_g3]==y1_x[checker] and g3_y[mover_g3]==y1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g4 and g4_x[mover_g4]==y1_x[checker] and g4_y[mover_g4]==y1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g1 and g1_x[mover_g1]==y1_x[checker] and g1_y[mover_g1]==y1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g1==mover_g4 and g4_x[mover_g4]==y1_x[checker] and g4_y[mover_g4]==y1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g2==mover_g4 and g4_x[mover_g4]==y1_x[checker] and g4_y[mover_g4]==y1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r1==mover_r2 and r1_x[mover_r1]==y1_x[checker] and r1_y[mover_r1]==y1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r2 and r3_x[mover_r3]==y1_x[checker] and r3_y[mover_r3]==y1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r4 and r4_x[mover_r4]==y1_x[checker] and r4_y[mover_r4]==y1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r1 and r1_x[mover_r1]==y1_x[checker] and r1_y[mover_y1]==y1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r1==mover_r4 and r4_x[mover_r4]==y1_x[checker] and r4_y[mover_r4]==y1_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r2==mover_r4 and r4_x[mover_r4]==y1_x[checker] and r4_y[mover_r4]==y1_y[checker])
		{
		found=1;
		break;
		}
		counter++;
		checker++;
		}
		return found;
		
		}
		
		int block_checker_y2()
       {
       int checker=mover_y2+1, found=0, counter=0;
       while(counter<dice_number){
			if(mover_b1==mover_b2 and b1_x[mover_b1]==y2_x[checker] and b1_y[mover_b1]==y2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b2 and b3_x[mover_b3]==y2_x[checker] and b3_y[mover_b3]==y2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b4 and b4_x[mover_b4]==y2_x[checker] and b4_y[mover_b4]==y2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b1 and b1_x[mover_b1]==y2_x[checker] and b1_y[mover_b1]==y2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b1==mover_b4 and b4_x[mover_b4]==y2_x[checker] and b4_y[mover_b4]==y2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b2==mover_b4 and b4_x[mover_b4]==y2_x[checker] and b4_y[mover_b4]==y2_y[checker])
		{
		found=1;
		break;
		}
		
	
		if(mover_g1==mover_g2 and g1_x[mover_g1]==y2_x[checker] and g1_y[mover_g1]==y2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g2 and g3_x[mover_g3]==y2_x[checker] and g3_y[mover_g3]==y2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g4 and g4_x[mover_g4]==y2_x[checker] and g4_y[mover_g4]==y2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g1 and g1_x[mover_g1]==y2_x[checker] and g1_y[mover_g1]==y2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g1==mover_g4 and g4_x[mover_g4]==y2_x[checker] and g4_y[mover_g4]==y2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g2==mover_g4 and g4_x[mover_g4]==y2_x[checker] and g4_y[mover_g4]==y2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r1==mover_r2 and r1_x[mover_r1]==y2_x[checker] and r1_y[mover_r1]==y2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r2 and r3_x[mover_r3]==y2_x[checker] and r3_y[mover_r3]==y2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r4 and r4_x[mover_r4]==y2_x[checker] and r4_y[mover_r4]==y2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r1 and r1_x[mover_r1]==y2_x[checker] and r1_y[mover_y2]==y2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r1==mover_r4 and r4_x[mover_r4]==y2_x[checker] and r4_y[mover_r4]==y2_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r2==mover_r4 and r4_x[mover_r4]==y2_x[checker] and r4_y[mover_r4]==y2_y[checker])
		{
		found=1;
		break;
		}
		counter++;
		checker++;
		}
		return found;
		
		}
		
		
		int block_checker_y3()
       {
       int checker=mover_y3+1, found=0, counter=0;
       while(counter<dice_number){
			if(mover_b1==mover_b2 and b1_x[mover_b1]==y3_x[checker] and b1_y[mover_b1]==y3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b2 and b3_x[mover_b3]==y3_x[checker] and b3_y[mover_b3]==y3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b4 and b4_x[mover_b4]==y3_x[checker] and b4_y[mover_b4]==y3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b1 and b1_x[mover_b1]==y3_x[checker] and b1_y[mover_b1]==y3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b1==mover_b4 and b4_x[mover_b4]==y3_x[checker] and b4_y[mover_b4]==y3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b2==mover_b4 and b4_x[mover_b4]==y3_x[checker] and b4_y[mover_b4]==y3_y[checker])
		{
		found=1;
		break;
		}
		
	
		if(mover_g1==mover_g2 and g1_x[mover_g1]==y3_x[checker] and g1_y[mover_g1]==y3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g2 and g3_x[mover_g3]==y3_x[checker] and g3_y[mover_g3]==y3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g4 and g4_x[mover_g4]==y3_x[checker] and g4_y[mover_g4]==y3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g1 and g1_x[mover_g1]==y3_x[checker] and g1_y[mover_g1]==y3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g1==mover_g4 and g4_x[mover_g4]==y3_x[checker] and g4_y[mover_g4]==y3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g2==mover_g4 and g4_x[mover_g4]==y3_x[checker] and g4_y[mover_g4]==y3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r1==mover_r2 and r1_x[mover_r1]==y3_x[checker] and r1_y[mover_r1]==y3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r2 and r3_x[mover_r3]==y3_x[checker] and r3_y[mover_r3]==y3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r4 and r4_x[mover_r4]==y3_x[checker] and r4_y[mover_r4]==y3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r1 and r1_x[mover_r1]==y3_x[checker] and r1_y[mover_y3]==y3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r1==mover_r4 and r4_x[mover_r4]==y3_x[checker] and r4_y[mover_r4]==y3_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r2==mover_r4 and r4_x[mover_r4]==y3_x[checker] and r4_y[mover_r4]==y3_y[checker])
		{
		found=1;
		break;
		}
		counter++;
		checker++;
		}
		return found;
		
		}
		
		
		int block_checker_y4()
       {
       int checker=mover_y4+1, found=0, counter=0;
       while(counter<dice_number){
			if(mover_b1==mover_b2 and b1_x[mover_b1]==y4_x[checker] and b1_y[mover_b1]==y4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b2 and b3_x[mover_b3]==y4_x[checker] and b3_y[mover_b3]==y4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b4 and b4_x[mover_b4]==y4_x[checker] and b4_y[mover_b4]==y4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b3==mover_b1 and b1_x[mover_b1]==y4_x[checker] and b1_y[mover_b1]==y4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b1==mover_b4 and b4_x[mover_b4]==y4_x[checker] and b4_y[mover_b4]==y4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_b2==mover_b4 and b4_x[mover_b4]==y4_x[checker] and b4_y[mover_b4]==y4_y[checker])
		{
		found=1;
		break;
		}
		
	
		if(mover_g1==mover_g2 and g1_x[mover_g1]==y4_x[checker] and g1_y[mover_g1]==y4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g2 and g3_x[mover_g3]==y4_x[checker] and g3_y[mover_g3]==y4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g4 and g4_x[mover_g4]==y4_x[checker] and g4_y[mover_g4]==y4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g3==mover_g1 and g1_x[mover_g1]==y4_x[checker] and g1_y[mover_g1]==y4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g1==mover_g4 and g4_x[mover_g4]==y4_x[checker] and g4_y[mover_g4]==y4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_g2==mover_g4 and g4_x[mover_g4]==y4_x[checker] and g4_y[mover_g4]==y4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r1==mover_r2 and r1_x[mover_r1]==y4_x[checker] and r1_y[mover_r1]==y4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r2 and r3_x[mover_r3]==y4_x[checker] and r3_y[mover_r3]==y4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r4 and r4_x[mover_r4]==y4_x[checker] and r4_y[mover_r4]==y4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r3==mover_r1 and r1_x[mover_r1]==y4_x[checker] and r1_y[mover_y4]==y4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r1==mover_r4 and r4_x[mover_r4]==y4_x[checker] and r4_y[mover_r4]==y4_y[checker])
		{
		found=1;
		break;
		}
		if(mover_r2==mover_r4 and r4_x[mover_r4]==y4_x[checker] and r4_y[mover_r4]==y4_y[checker])
		{
		found=1;
		break;
		}
		counter++;
		checker++;
		}
		return found;
		
		}
/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */


void NonPrintableKeys(int key, int x, int y) {
	
			
int width = 1020, height = 1000;

int exec_once=0;
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		
			
	
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		
	}
	
	
	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
	
	}
	
	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();
	

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
int counter=0;
void PrintableKeys(unsigned char key, int x, int y) {
int width = 1020, height = 1000;
	int sum=0;
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		}
		
	if(key=='2'){
	number_of_players=2;
	
	SetNameCanvasSize( width,  height);
        glutDisplayFunc(SecondScreen);
	
	}
	if(key=='3'){
	number_of_players=3;
	
	SetNameCanvasSize( width,  height);
        glutDisplayFunc(SecondScreen);
	
	}
	if(key=='4'){
	number_of_players=4;
	SetNameCanvasSize( width,  height);
        glutDisplayFunc(SecondScreen);
	}
	 	 int colour_include_red=0;
		 int colour_include_green=0;
		 int colour_include_blue=0;
		 int colour_include_yellow=0;
		 int count=0;
		 while(count<number_of_players){
		 if (player[count]=='r' )
		 colour_include_red=1;
		 else if(player[count]=='g'   )
		 colour_include_green=1;
		 else if(player[count]=='b' )
		 colour_include_blue=1;
		else if(player[count]=='y' )
		 colour_include_yellow=1;
		
		 count++;
		 }
		 
	/*if(turn==0 and dice_number!=6 and mover_r1==0 and mover_r2==0 and mover_r3==0 and mover_r4==0)
	{
		if(colour_include_blue==1)
		turn=1;
		else if (colour_include_yellow==1)
		turn=3;
		else if(colour_include_green==1)
		turn=2;
		dice_number=0;
		
	}
	else if(turn==1 and dice_number!=6 and mover_b1==0 and mover_b2==0 and mover_b3==0 and mover_b4==0)
	{
		if(colour_include_yellow==1)
		turn=3;
		else if(colour_include_green==1)
		turn=2;
		else if(colour_include_red==1)
		turn=0;
		dice_number=0;
	}
	else if(turn==3 and dice_number!=6  and mover_y1==0 and mover_y2==0 and mover_y3==0 and mover_y4==0)
	{
		if(colour_include_green==1)
		turn=2;
		else if(colour_include_red==1)
		turn=0;
		else if(colour_include_blue==1)
		turn=1;
		dice_number=0;
	}
	else if(turn==2 and dice_number!=6  and  mover_g1==0 and mover_g2==0 and mover_g3==0 and mover_g4==0)
	{
		if(colour_include_red==1)
		turn=0;
		else if(colour_include_blue==1)
		turn=1;
		else if(colour_include_yellow==1)
		turn=3;
		dice_number=0;
	}*/
	// this is to skip the turn if all tokens are in home position
		if(turn==0 and mover_r1==57 and mover_r2==57 and mover_r3==57 and mover_r4==57)
	{
		if(colour_include_blue==1)
		turn=1;
		else if (colour_include_yellow==1)
		turn=3;
		else if(colour_include_green==1)
		turn=2;
	}
	else if(turn==1 and mover_b1==57 and mover_b2==57 and mover_b3==57 and mover_b4==57)
	{
		if(colour_include_yellow==1)
		turn=3;
		else if(colour_include_green==1)
		turn=2;
		else if(colour_include_red==1)
		turn=0;
	}
	else if(turn==3 and mover_y1==57 and mover_y2==57 and mover_y3==57 and mover_y4==57)
	{
		if(colour_include_green==1)
		turn=2;
		else if(colour_include_red==1)
		turn=0;
		else if(colour_include_blue==1)
		turn=1;
	}
	else if(turn==2 and mover_g1==57 and mover_g2==57 and mover_g3==57 and mover_g4==57)
	{
		if(colour_include_red==1)
		turn=0;
		else if(colour_include_blue==1)
		turn=1;
		else if(colour_include_yellow==1)
		turn=3;
	}
		// to move it from the starting position
		if(turn==0 and mover_r1==0 and colour_include_red==1 and key=='*')
		{
		if(dice_number==6){
		mover_r1++;
		counter++;
		dice_number=0;
		red_score=red_score+6;
		}
		else{
		if(colour_include_blue==1)
		turn=1;
		else if (colour_include_yellow==1)
		turn=3;
		else if(colour_include_green==1)
		turn=2;
		dice_number=0;
		}
		}
	        else if(turn==0 and mover_r2==0 and colour_include_red==1 and key=='/')
		{
		if(dice_number==6){
		mover_r2++;
		counter++;
		dice_number=0;
		red_score=red_score+6;
		}
		else{
		if(colour_include_blue==1)
		turn=1;
		else if (colour_include_yellow==1)
		turn=3;
		else if(colour_include_green==1)
		turn=2;
		dice_number=0;
		}
		
		}
		else if(turn==0 and mover_r3==0 and colour_include_red==1 and key=='|')
		{
		if(dice_number==6){
		mover_r3++;
		counter++;
		dice_number=0;
		red_score=red_score+6;
		}
		else{
		if(colour_include_blue==1)
		turn=1;
		else if (colour_include_yellow==1)
		turn=3;
		else if(colour_include_green==1)
		turn=2;
		dice_number=0;
		}
		}
		else if(turn==0 and mover_r4==0 and colour_include_red==1 and key=='^')
		{
		if(dice_number==6){
		mover_r4++;
		counter++;
		dice_number=0;
		red_score=red_score+6;
		}
		else{
		if(colour_include_blue==1)
		turn=1;
		else if (colour_include_yellow==1)
		turn=3;
		else if(colour_include_green==1)
		turn=2;
		dice_number=0;
		}
		}
		else if(turn==1 and mover_b1==0 and colour_include_blue==1 and key=='&'){
		if(dice_number==6){
		mover_b1++;
		counter++;
		dice_number=0;
		blue_score=blue_score+6;
		}
		
		else{
		if(colour_include_yellow==1)
		turn=3;
		else if(colour_include_green==1)
		turn=2;
		else if(colour_include_red==1)
		turn=0;
		dice_number=0;
		}
		}
		else if(turn==1 and mover_b3==0 and colour_include_blue==1 and key=='#'){
		if(dice_number==6){
		mover_b3++;
		counter++;
		dice_number=0;
		blue_score=blue_score+6;
		}
		else{
		if(colour_include_yellow==1)
		turn=3;
		else if(colour_include_green==1)
		turn=2;
		else if(colour_include_red==1)
		turn=0;
		dice_number=0;
		}
		}
		else if(turn==1 and mover_b4==0 and colour_include_blue==1 and key=='@'){
		if(dice_number==6){
		mover_b4++;
		counter++;
		dice_number=0;
		blue_score=blue_score+6;
		}
		else{
		if(colour_include_yellow==1)
		turn=3;
		else if(colour_include_green==1)
		turn=2;
		else if(colour_include_red==1)
		turn=0;
		dice_number=0;
		}
		}
		else if(turn==1 and mover_b2==0 and colour_include_blue==1 and key=='!'){
		if(dice_number==6){
		mover_b2++;
		counter++;
		dice_number=0;
		blue_score=blue_score+6;
		}
		else{
		if(colour_include_yellow==1)
		turn=3;
		else if(colour_include_green==1)
		turn=2;
		else if(colour_include_red==1)
		turn=0;
		dice_number=0;
		}
		}
		else if(turn==3 and mover_y1==0 and colour_include_yellow==1 and key=='$'){
		if(dice_number==6){
		mover_y1++;
		counter++;
		dice_number=0;
		yellow_score=yellow_score+6;
		}
		else{
		if(colour_include_green==1)
		turn=2;
		else if(colour_include_red==1)
		turn=0;
		else if(colour_include_blue==1)
		turn=1;
		dice_number=0;
		}
		}
		else if(turn==3 and mover_y2==0 and colour_include_yellow==1 and key=='?'){
		if(dice_number==6){
		mover_y2++;
		counter++;
		dice_number=0;
		yellow_score=yellow_score+6;
		}
		else{
		if(colour_include_green==1)
		turn=2;
		else if(colour_include_red==1)
		turn=0;
		else if(colour_include_blue==1)
		turn=1;
		dice_number=0;
		}
		}
		else if(turn==3 and mover_y3==0 and colour_include_yellow==1 and key==':'){
		if(dice_number==6){
		mover_y3++;
		counter++;
		dice_number=0;
		yellow_score=yellow_score+6;
		}
		else{
		if(colour_include_green==1)
		turn=2;
		else if(colour_include_red==1)
		turn=0;
		else if(colour_include_blue==1)
		turn=1;
		dice_number=0;
		}
		}
		else if(turn==3 and mover_y4==0 and colour_include_yellow==1 and key==';'){
		if(dice_number==6){
		mover_y4++;
		counter++;
		dice_number=0;
		yellow_score=yellow_score+6;
		}
		else{
		if(colour_include_green==1)
		turn=2;
		else if(colour_include_red==1)
		turn=0;
		else if(colour_include_blue==1)
		turn=1;
		dice_number=0;
		}
		}
		else if(turn==2 and mover_g1==0 and colour_include_green==1 and key=='%'){
		if(dice_number==6){
		mover_g1++;
		counter++;
		dice_number=0;
		green_score=green_score+6;
		}
		else{
		if(colour_include_red==1)
		turn=0;
		else if(colour_include_blue==1)
		turn=1;
		else if(colour_include_yellow==1)
		turn=3;
		dice_number=0;
		}
		}
		else if(turn==2 and mover_g2==0 and colour_include_green==1 and key=='('){
		if(dice_number==6){
		mover_g2++;
		counter++;
		dice_number=0;
		green_score=green_score+6;
		}
		else{
		if(colour_include_red==1)
		turn=0;
		else if(colour_include_blue==1)
		turn=1;
		else if(colour_include_yellow==1)
		turn=3;
		dice_number=0;
		}
		}
			else if(turn==2 and mover_g3==0 and colour_include_green==1 and key==')'){
		if(dice_number==6){
		mover_g3++;
		counter++;
		dice_number=0;
		green_score=green_score+6;
		}
		else{
		if(colour_include_red==1)
		turn=0;
		else if(colour_include_blue==1)
		turn=1;
		else if(colour_include_yellow==1)
		turn=3;
		dice_number=0;
		}
		}
		else if(turn==2 and mover_g4==0 and colour_include_green==1 and key=='='){
		if(dice_number==6){
		mover_g4++;
		counter++;
		dice_number=0;
		green_score=green_score+6;
		}
		else{
		if(colour_include_red==1)
		turn=0;
		else if(colour_include_blue==1)
		turn=1;
		else if(colour_include_yellow==1)
		turn=3;
		dice_number=0;
		}
		}
		
		//after from moving from 0 space if there is a 6
		
		// includes condition for checking if 6 appears 3 times
		else if(dice_number==6 and mover_r1!=0 and turn==0 and colour_include_red==1 and key=='*' and mover_r1+dice_number<=57){
		counter++;
		if(counter==3){
		if(mover_r1==7)
		mover_r1=0;
		else
		mover_r1=mover_r1-12;
		if(colour_include_blue==1)
		turn=1;
		else if(colour_include_yellow==1)
		turn=3;
		else if(colour_include_green==1)
		turn=2;
		counter=0;
		dice_number=0;
		}
		else{
		
		if(block_checker_r1()==0){
		mover_r1=mover_r1+6;
		dice_number=0;
		red_score=red_score+6;
		}
		}
		killing_by_r1();
		}
		else if(dice_number==6 and mover_r2!=0 and turn==0 and colour_include_red==1 and key=='/' and mover_r2+dice_number<=57 ){
		counter++;
		if(counter==3){
		if(mover_r2==7)
		mover_r2=0;
		else
		mover_r2=mover_r2-12;
		if(colour_include_blue==1)
		turn=1;
		else if(colour_include_yellow==1)
		turn=3;
		else if(colour_include_green==1)
		turn=2;
		counter=0;
		dice_number=0;
		}
		else{
		if(block_checker_r2()==0){
		mover_r2=mover_r2+6;
		dice_number=0;
		red_score=red_score+6;
		}
		}
		killing_by_r2();
		}
		else if(dice_number==6 and mover_r3!=0 and turn==0 and colour_include_red==1 and key=='|' and mover_r3+dice_number<=57 ){
		counter++;
		if(counter==3){
		if(mover_r3==7)
		mover_r2=0;
		else
		mover_r3=mover_r3-12;
		if(colour_include_blue==1)
		turn=1;
		else if(colour_include_yellow==1)
		turn=3;
		else if(colour_include_green==1)
		turn=2;
		counter=0;
		dice_number=0;
		}
		else{
		if(block_checker_r3()==0){
		mover_r3=mover_r3+6;
		dice_number=0;
		red_score=red_score+6;
		}
		}
		 killing_by_r3();
		}
		else if(dice_number==6 and mover_r4!=0 and turn==0 and colour_include_red==1 and key=='^' and mover_r4+dice_number<=57){
		counter++;
		if(counter==3){
		if(mover_r4==7)
		mover_r4=0;
		else
		mover_r4=mover_r4-12;
		if(colour_include_blue==1)
		turn=1;
		else if(colour_include_yellow==1)
		turn=3;
		else if(colour_include_green==1)
		turn=2;
		counter=0;
		dice_number=0;
		}
		else{
		if(block_checker_r4()==0){
		mover_r4=mover_r4+6;
		dice_number=0;
		red_score=red_score+6;
		}
		}
		 killing_by_r4();
		}
		else if(dice_number==6 and mover_b1!=0 and turn==1 and colour_include_blue==1 and key=='&' and mover_b1+dice_number<=57)
		{
		counter++;
		if(counter==3){
		if(mover_b1==7)
		mover_b1=0;
		else 
		mover_b1=mover_b1-12;
		if(colour_include_yellow==1)
		turn=3;
		else if(colour_include_green==1)
		turn=2;
		else if(colour_include_red==1)
		turn=0;
		counter=0;
		dice_number=0;
		}
		else
		{
		if(block_checker_b1()==0){
		mover_b1=mover_b1+6;
		dice_number=0;
		blue_score=blue_score+6;
		}
		}
		killing_by_b1();
		}
		else if(dice_number==6 and mover_b3!=0 and turn==1 and colour_include_blue==1 and key=='#' and mover_b3+dice_number<=57)
		{
		counter++;
		if(counter==3){
		if(mover_b3==7)
		mover_b3=0;
		else 
		mover_b3=mover_b3-12;
		if(colour_include_yellow==1)
		turn=3;
		else if(colour_include_green==1)
		turn=2;
		else if(colour_include_red==1)
		turn=0;
		counter=0;
		dice_number=0;
		}
		else
		{
		if(block_checker_b3()==0){
		mover_b3=mover_b3+6;
		dice_number=0;
		blue_score=blue_score+6;
		}
		}
		killing_by_b3();
		}
		else if(dice_number==6 and mover_b4!=0 and turn==1 and colour_include_blue==1 and key=='@' and mover_b4+dice_number<=57)
		{
		counter++;
		if(counter==3){
		if(mover_b4==7)
		mover_b4=0;
		else 
		mover_b4=mover_b4-12;
		if(colour_include_yellow==1)
		turn=3;
		else if(colour_include_green==1)
		turn=2;
		else if(colour_include_red==1)
		turn=0;
		counter=0;
		dice_number=0;
		}
		else
		{
		if(block_checker_b4()==0){
		mover_b4=mover_b4+6;
		dice_number=0;
		blue_score=blue_score+6;
		}
		}
		killing_by_b4();
		}
		else if(dice_number==6 and mover_b2!=0 and turn==1 and colour_include_blue==1 and key=='!' and mover_b2+dice_number<=57)
		{
		counter++;
		if(counter==3){
		if(mover_b2==7)
		mover_b2=0;
		else 
		mover_b2=mover_b2-12;
		if(colour_include_yellow==1)
		turn=3;
		else if(colour_include_green==1)
		turn=2;
		else if(colour_include_red==1)
		turn=0;
		counter=0;
		dice_number=0;
		}
		else
		{
		if(block_checker_b2()==0){
		mover_b2=mover_b2+6;
		dice_number=0;
		blue_score=blue_score+6;
		}
		}
		killing_by_b2();
		}
		else if(dice_number==6 and mover_y1!=0 and colour_include_yellow==1 and turn==3 and key=='$' and mover_y1+dice_number<=57){
		counter++;
		if(counter==3)
		{
		if(mover_y1==7)
		mover_y1=0;
		else{
		mover_y1=mover_y1-12;
		dice_number=0;
		}
		if(colour_include_green==1)
		turn=2;
		else if(colour_include_red==1)
		turn=0;
		else if(colour_include_blue==1)
		turn=1;
		counter=0;
		dice_number=0;
	
	}
	else
	{
	if(block_checker_y1()==0){
	mover_y1=mover_y1+6;
	dice_number=0;
	yellow_score=yellow_score+6;
	}
	}
	killing_by_y1();	
	}
	else if(dice_number==6 and mover_y2!=0 and colour_include_yellow==1 and turn==3 and key=='?' and mover_y2+dice_number<=57){
	counter++;
		if(counter==3)
		{
		if(mover_y2==7)
		mover_y2=0;
		else{
		mover_y2=mover_y2-12;
		
		}
		if(colour_include_green==1)
		turn=2;
		else if(colour_include_red==1)
		turn=0;
		else if(colour_include_blue==1)
		turn=1;
		counter=0;
	dice_number=0;
	}
	else
	{
	if(block_checker_y2()==0){
	mover_y2=mover_y2+6;
	dice_number=0;
	yellow_score=yellow_score+6;
	}
	}
	killing_by_y2();
	
	}
	else if(dice_number==6 and mover_y3!=0 and colour_include_yellow==1 and turn==3 and key==':' and mover_y3+dice_number<=57){
	counter++;
		if(counter==3)
		{
		if(mover_y3==7)
		mover_y3=0;
		else{
		mover_y3=mover_y3-12;
		
		}
		if(colour_include_green==1)
		turn=2;
		else if(colour_include_red==1)
		turn=0;
		else if(colour_include_blue==1)
		turn=1;
		counter=0;
	dice_number=0;
	}
	else
	{
	if(block_checker_y3()==0){
	mover_y3=mover_y3+6;
	dice_number=0;
	yellow_score=yellow_score+6;
	}
	}
	killing_by_y3();
	}
	else if(dice_number==6 and mover_y4!=0 and colour_include_yellow==1 and turn==3 and key==';' and mover_y4+dice_number<=57){
	counter++;
		if(counter==3)
		{
		if(mover_y4==7)
		mover_y4=0;
		else{
		mover_y4=mover_y4-12;
		
		}
		if(colour_include_green==1)
		turn=2;
		else if(colour_include_red==1)
		turn=0;
		else if(colour_include_blue==1)
		turn=1;
		counter=0;
	dice_number=0;
	}
	else
	{
	if(block_checker_y4()==0){
	mover_y4=mover_y4+6;
	dice_number=0;
	yellow_score=yellow_score+6;
	}
	}
	killing_by_y4();
	}
		else if(dice_number==6 and mover_g1!=0 and colour_include_green==1 and turn==2 and key=='%' and mover_g1+dice_number<=57 ){
		counter++;
		if(counter==3)
		{
		if(mover_g1==7)
		mover_g1=0;
		else{
		mover_g1=mover_g1-12;
		
		}
		
		if(colour_include_red==1)
		turn=0;
		else if(colour_include_blue==1)
		turn=1;
		else if(colour_include_yellow==1)
		turn=3;
		counter=0;
	dice_number=0;
	}
	else
	{
	if(block_checker_g1()==0){
	mover_g1=mover_g1+6;
	dice_number=0;
	green_score=green_score+6;
	}
	killing_by_g1();
	}
	}
	
	else if(dice_number==6 and mover_g2!=0 and colour_include_green==1 and turn==2 and key=='(' and mover_g2+dice_number<=57){
		counter++;
		if(counter==3)
		{
		if(mover_g2==7)
		mover_g2=0;
		else{
		mover_g2=mover_g2-12;
		
		}
		if(colour_include_red==1)
		turn=0;
		else if(colour_include_blue==1)
		turn=1;
		else if(colour_include_yellow==1)
		turn=3;
		counter=0;
	dice_number=0;
	}
	else
	{
	if(block_checker_g2()==0){
	mover_g2=mover_g2+6;
	dice_number=0;
	green_score=green_score+6;
	}
	killing_by_g2();
	}
	
	}	
	else if(dice_number==6 and mover_g3!=0 and colour_include_green==1 and turn==2 and key==')'  and mover_g3+dice_number<=57){
		counter++;
		if(counter==3)
		{
		if(mover_g3==7)
		mover_g3=0;
		else{
		mover_g3=mover_g3-12;
		
		}
		if(colour_include_red==1)
		turn=0;
		else if(colour_include_blue==1)
		turn=1;
		else if(colour_include_yellow==1)
		turn=3;
		counter=0;
	dice_number=0;
	}
	else
	{
	if(block_checker_g3){
	mover_g3=mover_g3+6;
	dice_number=0;
	green_score=green_score+6;
	}
	killing_by_g3();
	}
	}			
		
	else if(dice_number==6 and mover_g4!=0 and colour_include_green==1 and turn==2 and key=='=' and mover_g4+dice_number<=57){
		counter++;
		if(counter==3)
		{
		if(mover_g4==7)
		mover_g4=0;
		else{
		mover_g3=mover_g3-12;
		
		}
		if(colour_include_red==1)
		turn=0;
		else if(colour_include_blue==1)
		turn=1;
		else if(colour_include_yellow==1)
		turn=3;
		counter=0;
	dice_number=0;
	}
	else
	{
	if(block_checker_g4()==0){
	mover_g4=mover_g4+6;
	dice_number=0;
	green_score=green_score+6;
	}
	killing_by_g4();
	}
	}					
	/////////////////////////WHEN DICE NUMBER IS NOT 0////////////////
 	else if(dice_number!=6 and turn==0 and colour_include_red==1 and key=='*' and mover_r1+dice_number<=57){
 	if(block_checker_r1()==0){
 	red_score=red_score+dice_number;
 	while(dice_number!=0){
 	dice_number--;
 	mover_r1++;
 	}
 	if(mover_r1==mover_r2 or mover_r1==mover_r3 or mover_r1==mover_r4)
 	red_score=red_score+2;
 	killing_by_r1();
 	if(colour_include_blue==1)
		turn=1;
		else if(colour_include_yellow==1)
		turn=3;
		else if(colour_include_green==1)
		turn=2;
		counter=0;
 	
 	}
 	}
 	else if(dice_number!=6 and turn==0 and colour_include_red==1 and key=='/' and mover_r2+dice_number<=57){
 	if(block_checker_r2()==0){
 	red_score=red_score+dice_number;
 	while(dice_number!=0){
 	dice_number--;
 	mover_r2++;
 	}
 	if(mover_r1==mover_r2 or mover_r2==mover_r3 or mover_r2==mover_r4)
 	red_score=red_score+2;
 	killing_by_r2();
 	if(colour_include_blue==1)
		turn=1;
		else if(colour_include_yellow==1)
		turn=3;
		else if(colour_include_green==1)
		turn=2;
		counter=0;
		
	
 	
 	}
 	}
 		else if(dice_number!=6 and turn==0 and colour_include_red==1 and key=='|' and mover_r3+dice_number<=57){
 		
 		if(block_checker_r3()==0){
 		red_score=red_score+dice_number;
 	while(dice_number!=0){
 	dice_number--;
 	mover_r3++;
 	}
 	if(mover_r1==mover_r3 or mover_r2==mover_r3 or mover_r3==mover_r4)
 	red_score=red_score+2;
 	 killing_by_r3();
 	if(colour_include_blue==1)
		turn=1;
		else if(colour_include_yellow==1)
		turn=3;
		else if(colour_include_green==1)
		turn=2;
		counter=0;
 	
 	}
 	}
 	else if(dice_number!=6 and turn==0 and colour_include_red==1 and key=='^' and mover_r4+dice_number<=57){
 	if(block_checker_r4()==0){
 	red_score=red_score+dice_number;
 	while(dice_number!=0){
 	dice_number--;
 	mover_r4++;
 	}
 	if(mover_r4==mover_r2 or mover_r4==mover_r3 or mover_r1==mover_r4)
 	red_score=red_score+2;
 	killing_by_r4();
 	if(colour_include_blue==1)
		turn=1;
		else if(colour_include_yellow==1)
		turn=3;
		else if(colour_include_green==1)
		turn=2;
		counter=0;
 	
 	}
 	}
 	else if(dice_number!=6 and turn==3 and colour_include_yellow==1 and key=='?' and mover_y2+dice_number<=57){
 	if(block_checker_y2()==0){
 	yellow_score=yellow_score+dice_number;
	while(dice_number!=0){
	
	dice_number--;
	mover_y2++;
	}
	if(mover_y1==mover_y2 or mover_y2==mover_r3 or mover_y2==mover_r4)
 	yellow_score=yellow_score+2;
	if(colour_include_green==1)
		turn=2;
		else if(colour_include_red==1)
		turn=0;
		else if(colour_include_blue==1)
		turn=1;
		counter=0;
	killing_by_y2();
	}
	}
	else if(dice_number!=6 and turn==3 and colour_include_yellow==1 and key=='$' and mover_y1+dice_number<=57){
	if(block_checker_y1()==0){
	yellow_score=yellow_score+dice_number;
	while(dice_number!=0){
	dice_number--;
	mover_y1++;
	}
	if(mover_y1==mover_y2 or mover_y1==mover_r3 or mover_y1==mover_r4)
 	yellow_score=yellow_score+2;
	killing_by_y1();
	if(colour_include_green==1)
		turn=2;
		else if(colour_include_red==1)
		turn=0;
		else if(colour_include_blue==1)
		turn=1;
		counter=0;
	
	}
	}
	else if(dice_number!=6 and turn==3 and colour_include_yellow==1 and key==':' and mover_y3+dice_number<=57){
	if(block_checker_y3()==0){
	yellow_score=yellow_score+dice_number;
	while(dice_number!=0){
	dice_number--;
	mover_y3++;
	}
	if(mover_y3==mover_y2 or mover_y1==mover_r3 or mover_y3==mover_r4)
 	yellow_score=yellow_score+2;
	killing_by_y3();
	if(colour_include_green==1)
		turn=2;
		else if(colour_include_red==1)
		turn=0;
		else if(colour_include_blue==1)
		turn=1;
		counter=0;
	}
	
	}
	else if(dice_number!=6 and turn==3 and colour_include_yellow==1 and key==';' and mover_y4+dice_number<=57){
	if(block_checker_y4()==0){
	yellow_score=yellow_score+dice_number;
	while(dice_number!=0){
	dice_number--;
	mover_y4++;
	}
	if(mover_y4==mover_y2 or mover_y4==mover_r3 or mover_y3==mover_r4)
 	yellow_score=yellow_score+2;
	killing_by_y4();
	if(colour_include_green==1)
		turn=2;
		else if(colour_include_red==1)
		turn=0;
		else if(colour_include_blue==1)
		turn=1;
		counter=0;
		}
	
	}
 	else if(dice_number!=6 and turn==1 and colour_include_blue==1 and key=='&' and mover_b1+dice_number<=57){
 	if(block_checker_b1()==0){
 	blue_score=blue_score+dice_number;
 	while(dice_number!=0){
 	dice_number--;
 	mover_b1++;
	} 
	if(mover_b1==mover_b2 or mover_b1==mover_b3 or mover_b1==mover_r4)
 	blue_score=blue_score+2;
	killing_by_b1();
	if(colour_include_yellow==1)
		turn=3;
		else if(colour_include_green==1)
		turn=2;
		else if(colour_include_red==1)
		turn=0;
		counter=0;
	
	
	}
	}
	else if(dice_number!=6 and turn==1 and colour_include_blue==1 and key=='#' and mover_b3+dice_number<=57){
	if(block_checker_b3()==0){
	blue_score=blue_score+dice_number;
 	while(dice_number!=0){
 	dice_number--;
 	mover_b3++;
	} 
	killing_by_b3();
	if(mover_b3==mover_b2 or mover_b1==mover_b3 or mover_b3==mover_r4)
 	blue_score=blue_score+2;
	if(colour_include_yellow==1)
		turn=3;
		else if(colour_include_green==1)
		turn=2;
		else if(colour_include_red==1)
		turn=0;
		counter=0;
	
	}
	}
	else if(dice_number!=6 and turn==1 and colour_include_blue==1 and key=='@' and (mover_b4+dice_number<=57)){
 	if(block_checker_b4()==0){
 	blue_score=blue_score+dice_number;
 	while(dice_number!=0){
 	dice_number--;
 	mover_b4++;
	} 
	if(mover_b4==mover_b2 or mover_b4==mover_b3 or mover_b1==mover_r4)
 	blue_score=blue_score+2;
	killing_by_b4();
	if(colour_include_yellow==1)
		turn=3;
		else if(colour_include_green==1) 
		turn=2;
		else if(colour_include_red==1)
		turn=0;
		counter=0;
	
	}
	}
	else if(dice_number!=6 and turn==1 and colour_include_blue==1 and key=='!' and mover_b2+dice_number<=57){
	if(block_checker_b2()==0){
	blue_score=blue_score+dice_number;
 	while(dice_number!=0){
 	dice_number--;
 	mover_b2++;
	} 
	if(mover_b1==mover_b2 or mover_b2==mover_b3 or mover_b2==mover_r4)
 	blue_score=blue_score+2;
	killing_by_b2();
	if(colour_include_yellow==1)
		turn=3;
		else if(colour_include_green==1)
		turn=2;
		else if(colour_include_red==1)
		turn=0;
		counter=0;
	
	}
	}
	else if(dice_number!=6 and turn==2 and colour_include_green==1 and key=='%' and mover_g1+dice_number<=57){
	if(block_checker_g1()==0){
	green_score=green_score+dice_number;
	while(dice_number!=0){
	dice_number--;
	mover_g1++;
	}
	if(mover_g1==mover_g2 or mover_g1==mover_g3 or mover_g1==mover_g4)
 	green_score=green_score+2;
	killing_by_g1();
		if(colour_include_red==1)
		turn=0;
		else if(colour_include_blue==1)
		turn=1;
		else if(colour_include_yellow==1)
		turn=3;
		counter=0;
	
	}
	}
	
	else if(dice_number!=6 and turn==2 and colour_include_green==1 and key=='(' and mover_g2+dice_number<=57){
	if(block_checker_g2()==0){
	green_score=green_score+dice_number;
	while(dice_number!=0){
	dice_number--;
	mover_g2++;
	}
	if(mover_g1==mover_g2 or mover_g2==mover_g3 or mover_g2==mover_g4)
 	green_score=green_score+2;
		killing_by_g2();
		if(colour_include_red==1)
		turn=0;
		else if(colour_include_blue==1)
		turn=1;
		else if(colour_include_yellow==1)
		turn=3;
		counter=0;
	}
	}
	else if(dice_number!=6 and turn==2 and colour_include_green==1 and key==')' and mover_g3+dice_number<=57){
	if(block_checker_g3()==0){
	green_score=green_score+dice_number;
	while(dice_number!=0){
	dice_number--;
	mover_g3++;
	}
	if(mover_g3==mover_g2 or mover_g1==mover_g3 or mover_g3==mover_g4)
 	green_score=green_score+2;
	killing_by_g3();
		if(colour_include_red==1)
		turn=0;
		else if(colour_include_blue==1)
		turn=1;
		else if(colour_include_yellow==1)
		turn=3;
		counter=0;
	
	}
	}
	else if(dice_number!=6 and turn==2 and colour_include_green==1 and key=='=' and mover_g4+dice_number<=57){
	if(block_checker_g4()==0){
	green_score=green_score+dice_number;
	while(dice_number!=0){
	dice_number--;
	mover_g4++;
	}
	if(mover_g4==mover_g2 or mover_g1==mover_g4 or mover_g3==mover_g4)
 	green_score=green_score+2;
	
	killing_by_g4();
		if(colour_include_red==1)
		turn=0;
		else if(colour_include_blue==1)
		turn=1;
		else if(colour_include_yellow==1)
		turn=3;
		counter=0;
	
	}
	}

	int i=0;
	//FOR RANDOM SELECTION
	if(key=='R'){
	int check=0;
	char colours[4]={'r','b','g','y'};
	int k=0;
	
	while(k<number_of_players){
	
	check=0;
	player[k]=colours[rand()%4];
	
	i=k-1;
	while(i>=0){
	if(player[i]==player[k]){
	check=1;
	break;}
	else 
	i--;
	}
	if(check==1)
	continue;
	else
	k++;
	
	
	
	
	}
	
	
	}
	
	if(i<number_of_players){
		if(key=='b' )
			{player[i]='b';
			i++;
			}
		if(key=='r' )
		{
			player[i]='r';
			i++;
	
		}
		if(key=='g')
			{
			player[i]='g';
			i++;
			}
		if(key=='y' )
		{
		player[i]='y';
		i++;
		}
	}	
	//TO GENERATE DICE NUMBER
	
	if(key==' '){
	dice_number=rand()%6+1;
	
	}
	if(key==0)
	{
	
	}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << x<< " THIS FOR SELECT" << y << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 1020, height = 1000; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("LUDO "); // set the title of our game window
	
	SetFirstCanvasSize(width, height);
	glutDisplayFunc(FirstScreen);
	
	//SetNameCanvasSize(width, height);
	//glutDisplayFunc(SecondScreen);
	//SetCanvasSize(width, height); // set the number of pixels...
	/*if(number_of_players==0){
	
	
	}*/
	
	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
	
	//glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
