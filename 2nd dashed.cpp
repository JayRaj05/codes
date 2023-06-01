#include<iostream>
#include<GL/glut.h>
#include<math.h>
#include<GL/gl.h>

using namespace std;

struct point{

	int x;
	int y;

};
point p1,p2;

void bresenham(point p1,point p2)
{
	int dx,dy,xinc,yinc,x,y;
	int e,inc1,inc2;
	dx=p2.x-p1.x;
	dy=p2.y-p1.y;
	
	xinc=(p2.x>p1.x)?1:-1;
	yinc=(p2.y>p1.y)?1:-1;	

	x=p1.x;
	y=p1.y;
	
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	
	if(dx>=dy)
	{
		e=2*dy-dx;
		inc1=2*(dy-dx);
		inc2=2*dy;
		for(int i=0;i<dx;i++){
		if(e>=0)
		{
			y+=yinc;
			e+=inc1;
			
		}
		else
		{
			e+=inc2;
		
		}	
		x+=xinc;
		if(i%9!=0 &&i%10!=0 && i%11!=0 &&i%12!=0 &&i%16!=0&&i%17!=0 && i%18!=0&&i%19!=0)
		{
			glVertex2i(x,y);
		}
		
		}	
	}
	else
	{
	
		e=2*dx-dy;
		inc1=2*(dx-dy);
		inc2=2*dx;
		for(int i=0;i<dy;i++){
		if(e>=0)
		{
			x+=xinc;
			e+=inc1;
			
		}
		else
		{
			e+=inc2;
		
		}	
		y+=yinc;
		if(i%9!=0&&i%10!=0&&i%11!=0&&i%12!=0&&i%16!=0&&i%17!=0&&i%18!=0&&i%19!=0)
		{
			glVertex2i(x,y);
		}
		
		}	
	
	}
	glEnd();
	glFlush();


}
void init()
{
	glClearColor(0.0,0.0,0.0,1.0);
	glColor3f(1.0,0.0,0.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,640.0,0.0,480.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

int main(int argc,char** argv)
{
	int ch,check=0;
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Bresenham");
	init();
	glFlush();
	glBegin(GL_LINES);
		glVertex2i(0,240);
		glVertex2i(640,240);
		glVertex2i(320,0);
		glVertex2i(320,480);
	glEnd();
	glFlush();	
			
	do{
		cout<<"\nMenu\n1.without using mouse\2.exit\nEnter your choice: ";
		cin>>ch;
		switch(ch){
			case 1:
				do{
					cout<<"\nenter the initial coordinates\nEnter the xcoordinate\nenter the ycoordinate";
					cin>>p1.x>>p1.y;
					cout<<"\nenter the final coordinates\nEnter the xcoordinate\nenter the ycoordinate";
					cin>>p2.x>>p2.y;
					p1.x+=320;
					p2.y+=240;
					p2.x+=320;
					p1.y+=240;
					glColor3f(0.0,1.0,1.0);
					bresenham(p1,p2);
					cout<<"\nDo you want continue the without mouse function\nPress 1:yes\nPress 0:No";
					cin>>check;					
					
				}while(check!=0);
				break;
		
			case 2:
				cout<<"\nProgram ends";
				
							
		
		}
	}while(ch!=2);
}
