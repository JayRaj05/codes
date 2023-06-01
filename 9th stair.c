#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

int xf1,yf1;
int l;
bool selected=false;

void init()
{
	glClearColor(1.0,0.0,0.0,1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,640.0,0.0,480.0);
	glFlush();
}
void plot(int x,int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();

}
void bresenham(int x1,int y1,int x2,int y2)
{
	int dx=x2-x1;
	int dy=y2-y1;
	
	int x=x1;
	int y=y1;
	
	int xinc=(x2>=x1)?1:-1;
	int yinc=(y2>=y1)?1:-1;
	
	int p=2*dy-dx;
	
	plot(x,y);
	
	if(dx>=dy)
	{	for(int i=0;i<dx;i++)
		{
		if(p>0)
		{
			y=y+yinc;
			p=p-2*dx;
		}
		x+=xinc;
		p+=2*dy;
		plot(x,y);
		}
	}
	else
	{
		for(int i=0;i<dy;i++)
		{
		if(p>0)
		{
			x=x+xinc;
			p=p-2*dy;
		}
		y+=yinc;
		p+=2*dx;
		plot(x,y);
		}
	
	
	}
	
	glFlush();
	

}
void drawLine()
{
	int h=l/6;
	int b=l/6;
	glColor3f(1.0,1.0,1.0);
	bresenham(xf1,yf1,xf1+l,yf1);
	bresenham(xf1+l,yf1,xf1+l,yf1+l);
	int x=xf1;
	int y=yf1;
	
	for(int i=0;i<6;i++)
	{
		bresenham(x,y,x,y+h);
		bresenham(x,y+h,x+b,y+h);
		x=x+b;
		y=y+h;
	
	}

glFlush();
}
void mouse(int button,int state,int x,int y)
{
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{	xf1=x;
		yf1=480-y;
		glColor3f(0.0,0.0,0.0);
		glPointSize(5);
		plot(xf1,yf1);
		glPointSize(2);
		drawLine();

	
	}
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}
int main(int argc,char** argv)
{	printf("\nEnter the length: ");
	scanf("%d",&l);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Staircase");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;

}
