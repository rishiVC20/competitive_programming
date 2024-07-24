#include<stdio.h>
#include<math.h>
#include<GL/freeglut.h>
#include<GL/gl.h>

//int xc=350;
//int yc=350;

void Init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	//gluOrtho2D(-350.0,350.0,-350.0,350.0);
	gluOrtho2D(0,700,0,700);
	glClear(GL_COLOR_BUFFER_BIT);
}

void plotPoint(int xc, int yc, int x, int y)
{
	glBegin(GL_POINTS);
		glVertex2d(xc+x,yc+y);
		glVertex2d(xc+x,yc-y);
		glVertex2d(xc+y,yc+x);
		glVertex2d(xc+y,yc-x);
		glVertex2d(xc-x,yc-y);
		glVertex2d(xc-y,yc-x);
		glVertex2d(xc-x,yc+y);
		glVertex2d(xc-y,yc+x);
	glEnd();	
		
}

void brCircle(int R, int xc, int yc)
{
	int x = 0;
	int y = R;
	int pk = 5/4;
	plotPoint(xc,yc,x,y);
	while (x<y)
	{
		x += 1;
		if (pk<0)
			pk = pk + 2*x + 1;
		else{
			y--;
			pk = pk+2*(x-y)+1;
		}	
		plotPoint(xc,yc,x,y);
	}
	glFlush();
}

//int arr[4];
int x3, y3, x4, y4;
void mouse_ip(int button, int state, int x, int y)
{
	static int xst, yst, pt=0;
	
	
	if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		if (pt == 0){
			
			xst = x;
			yst = y;
			x3 = xst;
			y3 = yst;
			pt = 1;
		}
		if (pt != 0){
			x4 = x;
			y4 = y;
			int radius = pow((x3-x4)*(x3-x4)+((700-y3)-(700-y4))*((700-y3)-(700-y4)),0.5);
			brCircle(radius,x3,700-y3);
			x3 = x4;
			y3 = y4;
		}
		
	}
	else if(button=GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
		pt = 0;
		
	}
	glFlush();
	
	
}
void Circle()
{
	Init();
	//brCircle(100);
	//brCircle(200);
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(700,700);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Bresenham Line Drawing");
	glutMouseFunc(mouse_ip);
	glutDisplayFunc(Circle);
	
	
	glutMainLoop();
	
	return 0;
}
