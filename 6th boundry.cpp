#include<iostream>
#include<GL/glut.h>
#include<math.h>

using namespace std;

float R=0,G=0,B=0;

void init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,640,0,480);
}

void boundary(int x,int y,float* fillcolor,float* bcolor)
{
	float color[3];
	glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,color);
	if((color[0]!=bcolor[0]||color[1]!=bcolor[1]||color[2]!=bcolor[2])&&(color[0]!=fillcolor[0]||color[1]!=fillcolor[1]||color[2]!=fillcolor[2]))
	{
		glColor3f(fillcolor[0],fillcolor[1],fillcolor[2]);
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();
		glFlush();
		boundary(x+1,y,fillcolor,bcolor);
		boundary(x-1,y,fillcolor,bcolor);
		boundary(x,y+1,fillcolor,bcolor);
		boundary(x,y-1,fillcolor,bcolor);
	}


}
void mouse(int btn,int state,int x,int y)
{
	y=480-y;
	if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
	{
		float bcolor[]={1,0,0};
		float newcolor[]={R,G,B};
		boundary(x,y,newcolor,bcolor);
	
	}


}
void gomenu(int value)
{
	switch(value)
	{
		case 1:
			R=0;G=1;B=0;
			break;
		case 2:
			R=1;G=1;B=0;
			break;
		case 3:
			R=1;G=0;B=1;
			break;
	}
glutPostRedisplay();
}
void B_DRAW()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(150,100);
	glVertex2i(300,300);
	glVertex2i(450,100);
	glEnd();
	glFlush();
	
}
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(200,200);
	glutCreateWindow("Boundary");
	init();
	glutDisplayFunc(B_DRAW);
	glutCreateMenu(gomenu);
	glutAddMenuEntry("Green 1",1);
	glutAddMenuEntry("Yellow 2",2);
	glutAddMenuEntry("Pink 3",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;

}
