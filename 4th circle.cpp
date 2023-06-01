#include<iostream>
#include<GL/glut.h>
#include<math.h>

using namespace std;

typedef struct Point{
	int x;
	int y;

}Point;
int radius;


void init()
{
	glClearColor(0.0,0.0,0.0,1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,1024.0,0.0,764.0);
	glPointSize(3);
}
void drawCircle(int r,int cx,int cy)
{
	Point p;
	
	p.x=0;
	p.y=r;
	
	float Pi=3-2*r;
		glColor3f(0.0,1.0,0.0);
	
	glBegin(GL_POINTS);
	
	while(p.x<=p.y)
	{
		if(Pi>=0)
		{
			p.x++;
			p.y--;
			Pi+=4*(p.x-p.y)+10;
		
		}
		else
		{
			p.x++;
			Pi+=4*p.x+6;
		}
		glVertex2i(cx+p.x,cy+p.y);
		glVertex2i(cx+p.y,cy+p.x);
		glVertex2i(cx+p.x,cy-p.y);
		glVertex2i(cx-p.x,cy+p.y);
		glVertex2i(cx-p.x,cy-p.y);
		glVertex2i(cx-p.y,cy+p.x);
		glVertex2i(cx+p.y,cy-p.x);
		glVertex2i(cx-p.y,cy-p.x);
		
		
	}glEnd();
	glFlush();	

}
void start()
{
	Point Max;
	Max.x=glutGet(GLUT_WINDOW_WIDTH);
	Max.y=glutGet(GLUT_WINDOW_HEIGHT);
	
	Point Origin;
	Origin.x=Max.x/2;
	Origin.y=Max.y/2;
	
	drawCircle(radius,Origin.x,Origin.y);
	
	



}
int main(int argc,char** argv)
{	cout<<"\nEnter the radius of cicle: ";
	cin>>radius;
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1024,764);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Circle");
	init();
	glutDisplayFunc(start);
	glutMainLoop();
	return 0;
}

