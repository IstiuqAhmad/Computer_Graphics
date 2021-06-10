#include <windows.h>
#include <GL/glut.h>
#include<math.h>>
# define PI           3.14159265358979323846

GLfloat m = 0.0f,n = 0.0f, p = 0.0f;
void Init()
{
    // Set display window color to as glClearColor(R,G,B,Alpha)
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    // Set 2D Transformation as gluOrtho2D(Min Width, Max Width, Min Height, Max Height)
    gluOrtho2D(0.0, 1200, 0.0, 1400);
}

void Idle()
{
    glutPostRedisplay(); // marks the current window as needing to be redisplayed
}

void circle(GLfloat rx,GLfloat ry,GLfloat x,GLfloat y)
{
    int i;
    float rad = 0;
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    for(i = 0;i<=360; i++){
    rad = i*(3.1416/180);
    glVertex2f(x+rx*cos(rad),y+ry*sin(rad));

    }
    glEnd();
}
void clock()
{
    glPushMatrix();
    glTranslated(600,800,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(400,490,0,0);
    glPopMatrix();
}
void display()
{

    glClear(GL_COLOR_BUFFER_BIT); // Clear display window
    clock();

    glPushMatrix();
    glTranslatef(600.0,800.0,0.0);
    glRotatef(m,0.0,0.0,1.0);

    glColor3f(0,0,1); //second
    glBegin(GL_LINES);
    glVertex2i(0,0);
    glVertex2i(150,360);
    glEnd();

    glPopMatrix();

    m-=0.01f;


    glPushMatrix();
    glTranslatef(600.0,800.0,0.0);
    glRotatef(n,0.0,0.0,1.0);

    glColor3f(0,1,0);    //minutes
    glBegin(GL_LINES);
    glVertex2i(0,0);
    glVertex2i(100,280);
    glEnd();

    glPopMatrix();

    n-=0.0007f;

    glPushMatrix();
    glTranslatef(600.0,800.0,0.0);
    glRotatef(p,0.0,0.0,1.0);

    glColor3f(1,0,0);  //hour
    glBegin(GL_LINES);
    glVertex2i(0,0);
    glVertex2i(100,200);
    glEnd();

    glPopMatrix();

    p-=0.0002f;

    glFlush();
}

int main(int argc, char** argv)
{
    // Initialize GLUT
    glutInit(&argc, argv);
    // Set display mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Set top - left display window position.
    glutInitWindowPosition(100, 100);
    // Set display window width and height
    glutInitWindowSize(800, 600);
    // Create display window with the given title
    glutCreateWindow("Clock Interface");
    // Execute initialization procedure
    Init();
    // Send graphics to display window
    glutDisplayFunc(display);
    // Display everything and wait.
    glutIdleFunc(Idle);
    glutMainLoop();
    return 0;
}
