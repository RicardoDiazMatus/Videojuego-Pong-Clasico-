#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>
#include <iostream>
#include <pthread.h>

void Init();
void *bolita(void *args);
void *cancha(void *args);
void *barras(void *args);
void *marcador(void *args);

int coordy1 = 150;
int coordx1 = 260;
int coordy2 = 150;
int coordx2 = 260;
int YMin=50;
int YMax=600;
int XMin=50;
int XMax=900;//dimensiones del rectangulo

int marc_p1=0,marc_p2=0;
main()
{
	pthread_t proceso;
	pthread_t proceso2;
	pthread_t proceso3;
	pthread_t proceso4;
    Init();
	pthread_create(&proceso, NULL, &bolita, NULL);
	pthread_create(&proceso2, NULL, &cancha, NULL);
	pthread_create(&proceso3, NULL, &barras, NULL);
	pthread_create(&proceso4, NULL, &marcador, NULL);
	pthread_join(proceso, NULL);
	pthread_join(proceso2, NULL);
	pthread_join(proceso3, NULL);
	pthread_join(proceso4, NULL);
	closegraph();
}

void *marcador(void *args){
	while(1==1){
		outtextxy((XMax/2),650, "Marcador:");
		if(marc_p1 == 0 && marc_p2 == 0){
			outtextxy((XMin + 20),660, "0");
			outtextxy((XMax - 50),660, "0");
		}
		if(marc_p1 == 1 && marc_p2 == 0){
			outtextxy((XMin + 20),660, "0");
			outtextxy((XMax - 50),660, "0");
		}
		if(marc_p1 == 2 && marc_p2 == 0){
			outtextxy((XMin + 20),660, "0");
			outtextxy((XMax - 50),660, "0");
		}
		if(marc_p1 == 3 && marc_p2 == 0){
			outtextxy((XMin + 20),660, "0");
			outtextxy((XMax - 50),660, "0");
		}
		if(marc_p1 == 0 && marc_p2 == 1){
			outtextxy((XMin + 20),660, "0");
			outtextxy((XMax - 50),660, "0");
		}
		if(marc_p1 == 0 && marc_p2 == 2){
			outtextxy((XMin + 20),660, "0");
			outtextxy((XMax - 50),660, "0");
		}
		if(marc_p1 == 0 && marc_p2 == 3){
			outtextxy((XMin + 20),660, "0");
			outtextxy((XMax - 50),660, "0");
		}
		if(marc_p1 == 1 && marc_p2 == 1){
			outtextxy((XMin + 20),660, "0");
			outtextxy((XMax - 50),660, "0");
		}
		if(marc_p1 == 2 && marc_p2 == 2){
			outtextxy((XMin + 20),660, "0");
			outtextxy((XMax - 50),660, "0");
		}
		if(marc_p1 == 2 && marc_p2 == 1){
			outtextxy((XMin + 20),660, "0");
			outtextxy((XMax - 50),660, "0");
		}
		if(marc_p1 == 1 && marc_p2 == 2){
			outtextxy((XMin + 20),660, "0");
			outtextxy((XMax - 50),660, "0");
		}
		delay(300);
	}
}

void *bolita(void *args)
{	
	int x=300;
	int y=300;
	int r=15,Dx=1,Dy=1;
	setcolor(WHITE);
	while(1==1)
	{  
		setcolor(WHITE);
	   	setfillstyle(0,14);
		circle(x,y,r);
		delay(1);//aqui cambia el tiempo
		setcolor(0);
		setfillstyle(0,14);
		circle(x,y,r);
        
		x+=Dx;
		y+=Dy;
		
		if ((x==XMin)||(x==XMax))
			Dx*=-1;
		if ((y==YMin)||(y==YMax))
			Dy*=-1;
		if((x==105) && (y>=coordy1) && (y<=coordx1) ){
			Dx*=-1.999;
		}
		if((x==790) && (y>=coordy2) && (y<=coordx2) )
			Dx*=-1.999;
		if(x<90)
			marc_p2 += 1;
		if(x>805)
			marc_p1 += 1;
	}
	
}

void *cancha(void *args){
	int r=15;
	setcolor(WHITE);
	while(1==1){
		rectangle(XMin-(r+1),YMin-(r+1),XMax+(r+1),YMax+(r+1));
	}
}

void *barras(void *args){
		//left, top, right, bottom
	int click = 0;
	rectangle(85,coordx1,95,coordy1);
	rectangle(800,coordy2,810,coordx2);
	while(1==1){
		click = getch();
		
		switch(click){
			case 115:
				if (coordx1 <= YMax){
					coordy1 += 10;
					coordx1 +=10;
				}
				cleardevice();
		    	rectangle(85,coordx1,95,coordy1);
				rectangle(800,coordy2,810,coordx2);
				
				break;
				
			case 119:
				if (coordy1 >= YMin){
					coordy1 -= 10;
					coordx1 -= 10;
				}
				cleardevice();
				rectangle(85,coordx1,95,coordy1);
				rectangle(800,coordy2,810,coordx2);
				break;
			case 108:
				if (coordx2 <= YMax){
					coordy2 += 10;
					coordx2 +=10;
				}
				cleardevice();
				rectangle(85,coordx1,95,coordy1);
				rectangle(800,coordy2,810,coordx2);
				break;
			case 111:
				if (coordy2 >= YMin){
					coordy2 -= 10;
					coordx2 -= 10;
				}
				cleardevice();
				rectangle(85,coordx1,95,coordy1);
				rectangle(800,coordy2,810,coordx2);
				break;
		}
		rectangle(85,coordx1,95,coordy1);
		rectangle(800,coordy2,810,coordx2);
	}
}

void Init()
{	
	int gd = DETECT, gm; //Variables inicializadas anteriormente, esto no se debe de modificar, ya que alteraría los argumentos
 	initgraph(&gd, &gm, "C:\\TC\\BGI"); //	Se abre la consola auxiliar, en la cual podremos dibujar
 	initwindow(1080,720);
}



