#include <iostream>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
  //FUNCION PRINCIPAL
 main()
{
  int gdrive=DETECT,gmode;
  // TIPO DE VARIABLES
  int i,c,b,d,e,f,t,k;
  int p;/*declarar*/
  
  initgraph(&gdrive,&gmode,"C:\\TC\\BGI");/*iniciar graficos*/
  delay(1000);/*retardo*/


  do  /*hacer*/
  {
  setcolor(WHITE); /*contorno*/
  setfillstyle(1,WHITE); /*estilo*/
  for(i=0;i<70;i++)/*contador*/
  {
  delay(10);/*retardo*/
  t=i*3;/*valor*/
  pieslice(50+t,220+t,0,360,15); /*circulo*/
  delay(20);/*retardo*/
  cleardevice();/*LIMPIAR*/
  }
  for(b=0;b<75;b++)/*contador*/
  {
  delay(4);/*retardo*/
  f=(b*5)+28;/*valor*/
  pieslice((50+t)+f,(240+t)-f,0,360,15);/*circulo*/
  delay(10);/*retardo*/
  cleardevice();/*LIMPIAR*/
  }

  for(c=0;c<20;c++)  /*contador*/
  {
  delay(3);/*retardo*/
  e=(c*2);/*valor*/
  pieslice((50+t+f)-e,(240+t-f)-e,0,360,15);/*circulo*/
  delay(20);/*retardo*/
  cleardevice();/*LIMPIAR*/
  }

  for(d=0;d<55;d++)  /*contador*/
  {
  delay(4);/*retardo*/
  k=(d*4);/*valor*/
  i=0;/*valor*/
  i=(d*9)+55;/*valor*/
  pieslice((50+t+f-e)-i,(240+t-f-e)+k,0,360,15);/*circulo*/
  delay(10);/*retardo*/
  cleardevice();/*LIMPIAR*/
  }
  }
  while(!kbhit());
  closegraph();//Cerrar Graficos

}
