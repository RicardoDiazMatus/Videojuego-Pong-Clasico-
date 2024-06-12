#include<iostream>
#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include <time.h>


main()
{

	int gd = DETECT, gm; //Variables inicializadas anteriormente, esto no se debe de modificar, ya que alteraría los argumentos
 	initgraph(&gd, &gm, "C:\\TC\\BGI"); //	Se abre la consola auxiliar, en la cual podremos dibujar
	
	
	//left, top, right, bottom
	//int coordy1 = 10;
	//int coordx1 = 110;
	int coordy2 = 10;
	int coordx2 = 110;
	//rectangle(85,coordx1,95,coordy1);
	rectangle(470,coordy2,480,coordx2);
	
	//rectangle(470,10,95,555);
	int click = 0;
	while(true){
		 click = getch();
		
		switch(click){
			//case 115:
				//coordy1 += 10;
				//coordx1 +=10;
				//cleardevice();
				
		    	//rectangle(85,coordx1,95,coordy1);
		    	rectangle(470,coordy2,480,coordx2);
			
				break;
				
			//case 119:
				//coordy1 -= 10;
				//coordx1 -= 10;
				//cleardevice();
				
				//rectangle(85,coordx1,95,coordy1);
				rectangle(470,coordy2,480,coordx2);
				break;
				
			case 108:
				coordy2 += 10;
				coordx2 += 10;
				cleardevice();
				
				
				rectangle(470,coordy2,480,coordx2);
				//rectangle(85,coordx1,95,coordy1);
				break;
			case 111:
				coordy2 -= 10;
				coordx2 -= 10;
				cleardevice();
				
				
				rectangle(470,coordy2,480,coordx2);
				//rectangle(85,coordx1,95,coordy1);
				break;
				
				
			
	}
}
		
    getch();
    closegraph();
   
   
}
 
	

