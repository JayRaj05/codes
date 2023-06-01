#include<iostream>
#include<GL/glut.h>
#include<math.h>

int xl=50,yl=50,xh=200,yh=200;
int flag=0;
float u1,v1,u2,v2;
 struct code{
 
 int t,b,r,l;
 
 };
 void init()
 {
 	glClearColor(1,1,1,0);
 	glClear(GL_COLOR_BUFFER_BIT);
 	glColor3f(0,0,0);
 	glMatrixMode(GL_PROJECTION);
 	 
}

void line(float x1,float y1,float x2,float y2)
{
	float dx,dy,x,y;
	int steps,i;
	dx=x2-x1;
	dy=y2-y1;
	steps=(abs(dx)>abs(dy))?abs(dx):abs(dy);
	float xinc=dx/(float)steps;
	float yinc=dy/(float)steps;
	x=x1;
	y=y1;
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POINTS);
	
	for(i=0;i<=                                                                                                                                                               steps;i++)
	{	glVertex2i(x,y);
		x+=xinc;
		y+=yinc;
		
	
	}
	glEnd();
	glFlush();
}
void mouse(int button,int state,int x,int y)
{
	if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN&&flag==0)
	{
		u1=x;
		v1=480-y;
		flag=1;
	
	
	
	}
	else if(button==GLUT_LEFT_BUTTON&& state==GLUT_DOWN&&flag==1)
	{
		u2=x;
		v2=480-y;
		line(u1,v1,u2,v2);
		flag=2;
	
	
	}



}

code getCode(int u ,int v)
{
	code c={0,0,0,0};
	
	if(u<xl)
	{
		c.l=1;
	}
	if(u>xh)
	{
		c.r=1;
	}
	if(v<yl)
	{
		c.b=1;
	}
	if(v>yh)
	{
		c.t=1;
	}



	return c;



}

void drawWindow()
{
	line(50,50,200,50);
	line(200,50,200,200);
	line(50,50,50,200);
	line(50,200,200,200);

}
void cohen()
{
	code c1,c2,c;
	int xi;
	int yi;
	int flag;
	
	
	float m=(v2-v1)/(u2-u1);
	
	c1=getCode(u1,v1);
	c2=getCode(u2,v2);
	
	while(1)
	{	
		//if line inside the window , draw the line as it is.
		if( c1.t==0 && c2.t==0 && c1.b==0 && c2.b==0 && c1.r==0 && c2.r==0 && c1.l==0 && c2.l==0 )
		break;
		
		//if the ANDING of opcodes is non-zero then don't draw the line. 
		else if( ( (c1.t  && c2.t) || (c1.b && c2.b) || (c1.r && c2.r) || (c1.l && c2.l) ) !=0)
		{
			u1=v1=u2=v2=0;
			break;
		}
		
		//if line partially inside the window changing the co-ordinates as per following conditions.
		else
		{
			if( c1.l==1 || c2.l==1)
			{
				xi=xl;
				yi=v1+m*(xl-u1);
				
				if(c1.l==1)
				flag=0;
				
				else
				flag=1;
				
			}
			
			if( c1.r==1 || c2.r==1 )
			{
				xi=xh;
				yi=v1+m*(xh-u1);
				
				if(c1.r==1)
				flag=0;
				
				else
				flag=1;
			}
			
			if( c1.b==1 || c2.b==1 )
			{
				xi=u1+((1/m)*(yl-v1));
				yi=yl;
				
				if(c1.b==1)
				flag=0;
				
				else
				flag=1;
			}
			if( c1.t==1 || c2.t==1 )
			{
				xi=u1+((1/m)*(yh-v1));
				yi=yh;
				
				if(c1.t==1)
				flag=0;
				
				else
				flag=1;
			}
			
			//get the code of xi and yi.
			c=getCode(xi,yi);
			
			if(flag==0)
			{
				u1=xi;
				v1=yi;
				c1=c;
			}
			else if(flag==1)
			{
				u2=xi;
				v2=yi;
				c2=c;
			}
			
		}//end_else
	
	}
	drawWindow();
	line(u1,v1,u2,v2);
}
void mykey(char unsigned key,int x,int y)
{
	if(key=='c')
	{
		init();
		cohen();
	
	
	
	}
	if(key=='r')
	{
		init();
		drawWindow();
		flag=0;
	
	
	
	}




}
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(200,200);
	glutCreateWindow("Clip");
	gluOrtho2D(0.0,640.0,0.0,480.0);
	init();
	glFlush();
	
	drawWindow();
	glutMouseFunc(mouse);
	glutKeyboardFunc(mykey);
	glutMainLoop();
	return 0;
}
