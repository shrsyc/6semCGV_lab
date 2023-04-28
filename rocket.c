#include<GL/glut.h>
#include<stdio.h>
GLfloat  r1=1.0, r2=0.5,r3=0.5;
GLfloat b1=1.0, b2=1.0, b3=1.0;
GLfloat t1=1.0, t2=0.5, t3=0.0;
void change();
void display();
void  top()
{
glBegin(GL_TRIANGLES);
glColor3f(r1,r2,r3);
glVertex2f(100.0,400.0);
glVertex2f(150.0,400.0);
glVertex2f(125.0,450.0);
glEnd();
glFlush();
}

void  body()
{
glBegin(GL_QUADS);
glColor3f(b1,b2,b3);
glVertex2f(100.0,400.0);
glVertex2f(150.0,400.0);
glVertex2f(150.0,250.0);
glVertex2f(100.0,250.0);
glEnd();
glFlush();
}

void  tail()
{
glBegin(GL_TRIANGLES);
glColor3f(t1,t2,t3);
glVertex2f(100.0,250.0);
glVertex2f(150.0,250.0);
glVertex2f(75.0,100.0);
glVertex2f(100.0,250.0);
glVertex2f(150.0,250.0);
glVertex2f(175.0,100.0);
glEnd();
glFlush();
}
void display()
{
char key;
glClear(GL_COLOR_BUFFER_BIT);
top();
body();
tail();
printf("press C to change color and Q to quit");
scanf("%c",&key);
if(key=='c'||key=='C')
change();
if(key=='q'||key=='Q')
exit(0);
}

void change()
{
int x;
do
{
printf("1.top\n 2.body\n 3.tail\n 4.quit\n enter your choice\n");
scanf("%d",&x);
switch(x)
{
case 1:printf("enter components of new top\n");
          scanf("%f%f%f",&r1,&r2,&r3);
	break;
case 2:printf("enter components of new body\n");
          scanf("%f%f%f",&b1,&b2,&b3);
	break;
case 3:printf("enter components of new tail\n");
          scanf("%f%f%f",&t1,&t2,&t3);
	break;
case 4:break;
}
}while(x!=4);
display();
}
void myinit()
{
glClearColor(0.0,0.0,0.0,1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,500.0,0.0,500.0);
glMatrixMode(GL_MODELVIEW);
}

void main(int argc, char**argv)
{
 glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(750.0,0.0);
glutCreateWindow("Rocket");
glutDisplayFunc(display);
myinit();
glutMainLoop();
}
