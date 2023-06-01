#include<iostream>
#include<GL/glut.h>
#include<GL/freeglut.h>
#include<math.h>
using namespace std;

void init()
{
	glClearColor(0.0,0.0,0.0,1.0);
	glColor3f(1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,1200.0,0.0,800.0);
	glPointSize(6.0);
	
}

void drawLine()
{	init();
	int x0=300,y0=300,x1=30,y1=30;
	int dx,dy,steps;
	float x,y;
	 dx=abs (x1-x0);
	 dy=abs (y1-y0);
	 steps = (dx) > (dy) ? (dx) : (dy); 
	float xinc=dx / (float)steps;
	float yinc=dy / (float)steps;
	
	 x=x0;
	 y=y0;
	glBegin(GL_POINTS);
	for(int i=0;i<=steps;i++)
	{
		glVertex2i(round(x),round(y));
		x+=xinc;
		y+=yinc;
		
	}
	glEnd();
	glFlush();

}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1200,800);
	glutInitWindowPosition(0,0);
	glutCreateWindow("DDA");
	glutDisplayFunc(drawLine);
	glutMainLoop();
	
	return 0;



}
	

	
