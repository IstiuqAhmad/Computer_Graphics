#include<Windows.h>       // for MS Windows
#include<GL\glut.h>
#include<math.h>>
# define PI           3.14159265358979323846

GLfloat m = 0.0f, n = 0.0f, x = 0.0f, y = 0.0f,z = 0.0f;

void init()
{
    glClearColor(0.0f,0.8f,0.7f,0.0f);
    gluOrtho2D(0.0, 2000, 0.0, 1400);
}

GLfloat CarPosition = 50.0f;
GLfloat CarSpeed = 10.0f;

GLfloat SkyPosition = 50.0f;
GLfloat SkySpeed = 10.0f;

GLfloat PlanePosition = 50.0f;
GLfloat PlaneSpeed = 20.0f;

GLfloat RainPosition = 50.0f;
GLfloat RainSpeed = 40.0f;

void CarUpdate(int value) {

    if(CarPosition > 1900.0)
         CarPosition = -10.0f;

    CarPosition += CarSpeed; //position=position-speed;1-.1=.9

	glutPostRedisplay();

	glutTimerFunc(100, CarUpdate, 0);
}

void SkyUpdate(int value) {

    if(SkyPosition < -1800.0)
         SkyPosition = 10.0f;

    SkyPosition -= SkySpeed; //position=position-speed;1-.1=.9

	glutPostRedisplay();

	glutTimerFunc(100, SkyUpdate, 0);
}

void PlaneUpdate(int value) {

    if(PlanePosition < -1800.0)
         PlanePosition = 20.0f;

    PlanePosition -= PlaneSpeed; //position=position-speed;1-.1=.9

	glutPostRedisplay();

	glutTimerFunc(100, PlaneUpdate, 0);
}

void RainUpdate(int value) {

    if(RainPosition < -500.0)
         RainPosition = 20.0f;

    RainPosition -= RainSpeed; //position=position-speed;1-.1=.9

	glutPostRedisplay();

	glutTimerFunc(100, RainUpdate, 0);
}

void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
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
void sun()
{
    glPushMatrix();
    glTranslated(1800,1300,0);
    glColor3f(1.0, 0.76, 0.3);
    circle(60,70,0,0);
    glPopMatrix();
}

void clock()
{
    glPushMatrix();
    glTranslated(1130,380,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(105,105,0,0);
    glPopMatrix();
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON){
			CarSpeed += 3.1f;
			SkySpeed += 3.1f;
			}
			if (button == GLUT_RIGHT_BUTTON)
	{CarSpeed -= 1.1f;
	SkySpeed -= 1.1f;
			}
	glutPostRedisplay();
}

void SpecialInput(int key, int x, int y)
{
switch(key)
{case GLUT_KEY_UP:
   CarSpeed=10.5;
   SkySpeed=10.5;
   break;
case GLUT_KEY_DOWN:
   CarSpeed=5.2;
   SkySpeed=5.2;
   break;
case GLUT_KEY_LEFT:
   CarSpeed=20.5;
   SkySpeed=20.5;
   break;
case GLUT_KEY_RIGHT:
   CarSpeed=10.5;
   SkySpeed=10.5;
   break;}

glutPostRedisplay();
}


void night()
{
    glClearColor(0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluOrtho2D(0.0, 2000, 0.0, 1400);

	glColor3f(0,0.5,0.5);
    glBegin(GL_POLYGON);   // 1st floor
    glVertex2i(150, 400);
    glVertex2i(600, 400);
    glVertex2i(600, 250);
    glVertex2i(150, 250);
    glEnd();

    glColor3f(0.8,0.8,0.5);
    glBegin(GL_POLYGON);   // 1st floor door
    glVertex2i(290, 380);
    glVertex2i(450, 380);
    glVertex2i(450, 250);
    glVertex2i(290, 250);
    glEnd();

    glColor3f(0,0,0);     // 1st floor roof
    glBegin(GL_POLYGON);
    glVertex2i(150, 415);
    glVertex2i(600, 415);
    glVertex2i(600, 400);
    glVertex2i(150, 400);
    glEnd();

    glColor3f(0,0.4,0.5);  // 2nd floor
    glBegin(GL_POLYGON);
    glVertex2i(150, 575);
    glVertex2i(600, 575);
    glVertex2i(600, 415);
    glVertex2i(150, 415);
    glEnd();

    glColor3f(0,0,0.4);  // 2nd floor stairs window
    glBegin(GL_POLYGON);
    glVertex2i(340, 550);
    glVertex2i(400, 550);
    glVertex2i(400, 430);
    glVertex2i(340, 430);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_LINES);    // 2nd floor stairs line
    glVertex2i(370, 548);
    glVertex2i(370, 432);
    glVertex2i(342, 460);
    glVertex2i(400, 460);
    glVertex2i(342, 515);
    glVertex2i(400, 515);
    glEnd();


    glColor3f(0.8,0.8,0.5);
    glBegin(GL_POLYGON);    // 2nd floor 1st window
    glVertex2i(200, 520);
    glVertex2i(270, 520);
    glVertex2i(270, 452);
    glVertex2i(200, 452);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_LINES);    // 2nd floor 1st window line
    glVertex2i(235, 520);
    glVertex2i(235, 452);
    glVertex2i(200, 487);
    glVertex2i(270, 487);
    glEnd();

    glColor3f(0.8,0.8,0.5);
    glBegin(GL_POLYGON);    // 2nd floor 2nd window
    glVertex2i(480, 520);
    glVertex2i(550, 520);
    glVertex2i(550, 452);
    glVertex2i(480, 452);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_LINES);    // 2nd floor 2nd window line
    glVertex2i(515, 520);
    glVertex2i(515, 452);
    glVertex2i(480, 487);
    glVertex2i(550, 487);
    glEnd();


    glColor3f(0,0,0);
    glBegin(GL_POLYGON);    // 2nd floor roof
    glVertex2i(150, 590);
    glVertex2i(600, 590);
    glVertex2i(600, 575);
    glVertex2i(150, 575);
    glEnd();

    glColor3f(0,0.5,0.5);
    glBegin(GL_POLYGON);    // 3rd floor
    glVertex2i(150, 765);
    glVertex2i(600, 765);
    glVertex2i(600, 590);
    glVertex2i(150, 590);
    glEnd();

    glColor3f(0,0,0.4);
    glBegin(GL_POLYGON);    // 3rd floor stairs window
    glVertex2i(340, 740);
    glVertex2i(400, 740);
    glVertex2i(400, 610);
    glVertex2i(340, 610);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_LINES);    // 3rd floor stairs line
    glVertex2i(370, 738);
    glVertex2i(370, 612);
    glVertex2i(342, 700);
    glVertex2i(400, 700);
    glVertex2i(342, 645);
    glVertex2i(400, 645);
    glEnd();

    glColor3f(0.8,0.8,0.5);
    glBegin(GL_POLYGON);    // 3rd floor 1st window
    glVertex2i(200, 710);
    glVertex2i(270, 710);
    glVertex2i(270, 635);
    glVertex2i(200, 635);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_LINES);    // 3rd floor 1st window line
    glVertex2i(235, 710);
    glVertex2i(235, 635);
    glVertex2i(200, 670);
    glVertex2i(270, 670);
    glEnd();

    glColor3f(0.8,0.8,0.5);
    glBegin(GL_POLYGON);    // 3rd floor 2nd window
    glVertex2i(480, 710);
    glVertex2i(550, 710);
    glVertex2i(550, 635);
    glVertex2i(480, 635);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_LINES);    // 3rd floor 2nd window line
    glVertex2i(515, 710);
    glVertex2i(515, 635);
    glVertex2i(480, 670);
    glVertex2i(550, 670);
    glEnd();

    glColor3f(0.8,0.4,0);
    glBegin(GL_POLYGON);    // roof top
    glVertex2i(130, 765);
    glVertex2i(620, 765);
    glVertex2i(620, 795);
    glVertex2i(130, 795);
    glEnd();
//

    glColor3f(0.7,0.3,0.2);   //2nd building front
    glBegin(GL_POLYGON);
    glVertex2i(900,550);
    glVertex2i(1350,550);
    glVertex2i(1350,250);
    glVertex2i(900,250);
    glEnd();

    glColor3f(0.6,0.2,0.0);   //2nd building back
    glBegin(GL_POLYGON);
    glVertex2i(750,550);
    glVertex2i(900,550);
    glVertex2i(900,250);
    glVertex2i(750,250);
    glEnd();

    glColor3f(0.9,0.7,0.3);   //2nd building roof front
    glBegin(GL_POLYGON);
    glVertex2i(880,580);
    glVertex2i(1370,580);
    glVertex2i(1370,550);
    glVertex2i(880,550);
    glEnd();

    glColor3f(1.0,0.6,0.1);   //2nd building roof back
    glBegin(GL_POLYGON);
    glVertex2i(730,580);
    glVertex2i(880,580);
    glVertex2i(880,550);
    glVertex2i(730,550);
    glEnd();

    glColor3f(0.7,0.3,0.2);   //2nd building 2nd floor front
    glBegin(GL_POLYGON);
    glVertex2i(900,750);
    glVertex2i(1350,750);
    glVertex2i(1350,580);
    glVertex2i(900,580);
    glEnd();

    glColor3f(0.6,0.2,0.0);   //2nd building 2nd floor back
    glBegin(GL_POLYGON);
    glVertex2i(750,750);
    glVertex2i(900,750);
    glVertex2i(900,580);
    glVertex2i(750,580);
    glEnd();

    glColor3f(0.9,0.7,0.3);   //2nd building 2nd floor roof front
    glBegin(GL_POLYGON);
    glVertex2i(880,780);
    glVertex2i(1370,780);
    glVertex2i(1370,750);
    glVertex2i(880,750);
    glEnd();

    glColor3f(1.0,0.6,0.1);   //2nd building 2nd floor roof back
    glBegin(GL_POLYGON);
    glVertex2i(730,780);
    glVertex2i(880,780);
    glVertex2i(880,750);
    glVertex2i(730,750);
    glEnd();


    glColor3f(0.7,0.8,0.8);   //2nd building window 1
    glBegin(GL_POLYGON);
    glVertex2i(950,720);
    glVertex2i(1050,720);
    glVertex2i(1050,600);
    glVertex2i(950,600);
    glEnd();

    glColor3f(0.7,0.8,0.8);   //2nd building window 2
    glBegin(GL_POLYGON);
    glVertex2i(1075,720);
    glVertex2i(1175,720);
    glVertex2i(1175,600);
    glVertex2i(1075,600);
    glEnd();

    glColor3f(0.7,0.8,0.8);   //2nd building window 3
    glBegin(GL_POLYGON);
    glVertex2i(1205,720);
    glVertex2i(1305,720);
    glVertex2i(1305,600);
    glVertex2i(1205,600);
    glEnd();

    glColor3f(0,0,0);   //2nd building Door black layer
    glBegin(GL_POLYGON);
    glVertex2i(940,520);
    glVertex2i(1310,520);
    glVertex2i(1310,250);
    glVertex2i(940,250);
    glEnd();

    glColor3f(0.7,0.8,0.8);   //2nd building Door silver layer
    glBegin(GL_POLYGON);
    glVertex2i(980,480);
    glVertex2i(1270,480);
    glVertex2i(1270,290);
    glVertex2i(980,290);
    glEnd();

    glColor3f(0.4,1,0.7);  // 3rd building front
    glBegin(GL_POLYGON);
    glVertex2i(1650,650);
    glVertex2i(2000,650);
    glVertex2i(2000,250);
    glVertex2i(1650,250);
    glEnd();

    glColor3f(0.4,1,0.5); // back
    glBegin(GL_POLYGON);
    glVertex2i(1530,650);
    glVertex2i(1650,650);
    glVertex2i(1650,250);
    glVertex2i(1530,250);
    glEnd();

    glColor3f(0,0.6,0.1); // roof
    glBegin(GL_POLYGON);
    glVertex2i(1530,680);
    glVertex2i(1650,680);
    glVertex2i(1650,650);
    glVertex2i(1530,650);
    glEnd();

    glColor3f(0,0.7,0);  //roof
    glBegin(GL_POLYGON);
    glVertex2i(1650,680);
    glVertex2i(2000,680);
    glVertex2i(2000,650);
    glVertex2i(1650,650);
    glEnd();

    glColor3f(0.5,0,0);   //window
    glBegin(GL_POLYGON);
    glVertex2i(1700,620);
    glVertex2i(1780,620);
    glVertex2i(1780,550);
    glVertex2i(1700,550);
    glEnd();

     glColor3f(0.5,0,0);   //window
    glBegin(GL_POLYGON);
    glVertex2i(1900,620);
    glVertex2i(1980,620);
    glVertex2i(1980,550);
    glVertex2i(1900,550);
    glEnd();

    glColor3f(0.5,0,0);   //window
    glBegin(GL_POLYGON);
    glVertex2i(1700,520);
    glVertex2i(1780,520);
    glVertex2i(1780,450);
    glVertex2i(1700,450);
    glEnd();

    glColor3f(0.5,0,0);   //window
    glBegin(GL_POLYGON);
    glVertex2i(1900,520);
    glVertex2i(1980,520);
    glVertex2i(1980,450);
    glVertex2i(1900,450);
    glEnd();

    glColor3f(0.5,0,0);   //window
    glBegin(GL_POLYGON);
    glVertex2i(1900,520);
    glVertex2i(1980,520);
    glVertex2i(1980,450);
    glVertex2i(1900,450);
    glEnd();

    glColor3f(0,0,0);   //Door
    glBegin(GL_POLYGON);
    glVertex2i(1710,420);
    glVertex2i(1970,420);
    glVertex2i(1970,250);
    glVertex2i(1710,250);
    glEnd();


    glColor3f(0.5,0.6,0.6);   //back ground building
    glBegin(GL_POLYGON);
    glVertex2i(820,980);
    glVertex2i(1070,980);
    glVertex2i(1070,780);
    glVertex2i(820,780);
    glEnd();

    glColor3f(0.4,0.4,0.4);   //back ground building dark side
    glBegin(GL_POLYGON);
    glVertex2i(1070,980);
    glVertex2i(1220,980);
    glVertex2i(1220,780);
    glVertex2i(1070,780);
    glEnd();

    glColor3f(0.4,0.5,0.5);   //back ground building roof
    glBegin(GL_POLYGON);
    glVertex2i(810,1000);
    glVertex2i(1080,1000);
    glVertex2i(1080,980);
    glVertex2i(810,980);
    glEnd();

    glColor3f(0.3,0.4,0.4);   //back ground building dark side roof
    glBegin(GL_POLYGON);
    glVertex2i(1080,1000);
    glVertex2i(1230,1000);
    glVertex2i(1230,980);
    glVertex2i(1080,980);
    glEnd();

    glColor3f(0.2,0.2,0.3);   //back ground building dark side line
    glBegin(GL_LINES);
    glVertex2i(1120,980);
    glVertex2i(1120,780);
    glVertex2i(1180,980);
    glVertex2i(1180,780);

    glVertex2i(1070,880);
    glVertex2i(1220,880);
    glEnd();

    glColor3f(0.4,0.5,0.5);   //back ground building window up1
    glBegin(GL_POLYGON);
    glVertex2i(840,950);
    glVertex2i(900,950);
    glVertex2i(900,880);
    glVertex2i(840,880);
    glEnd();

    glColor3f(0.4,0.5,0.5);   //back ground building window up2
    glBegin(GL_POLYGON);
    glVertex2i(915,950);
    glVertex2i(975,950);
    glVertex2i(975,880);
    glVertex2i(915,880);
    glEnd();

    glColor3f(0.4,0.5,0.5);   //back ground building window up3
    glBegin(GL_POLYGON);
    glVertex2i(990,950);
    glVertex2i(1050,950);
    glVertex2i(1050,880);
    glVertex2i(990,880);
    glEnd();

     glColor3f(0.4,0.5,0.5);   //back ground building window down1
    glBegin(GL_POLYGON);
    glVertex2i(840,860);
    glVertex2i(900,860);
    glVertex2i(900,790);
    glVertex2i(840,790);
    glEnd();

    glColor3f(0.4,0.5,0.5);   //back ground building window down2
    glBegin(GL_POLYGON);
    glVertex2i(915,860);
    glVertex2i(975,860);
    glVertex2i(975,790);
    glVertex2i(915,790);
    glEnd();

    glColor3f(0.4,0.5,0.5);   //back ground building window down3
    glBegin(GL_POLYGON);
    glVertex2i(990,860);
    glVertex2i(1050,860);
    glVertex2i(1050,790);
    glVertex2i(990,790);
    glEnd();

    glColor3f(0.5,0.6,0.6);   //back ground building water tank
    glBegin(GL_POLYGON);
    glVertex2i(870,1050);
    glVertex2i(970,1050);
    glVertex2i(970,1000);
    glVertex2i(870,1000);
    glEnd();

////
    clock();

    glPushMatrix();
    glTranslatef(1130.0,390.0,0.0);
    glRotatef(x,0.0,0.0,1.0);

    glColor3f(0,0,1); //second
    glBegin(GL_LINES);
    glVertex2i(0,0);
    glVertex2i(70,60);
    glEnd();

    glPopMatrix();

    x-=0.01f;

    glPushMatrix();
    glTranslatef(1130.0,390.0,0.0);
    glRotatef(y,0.0,0.0,1.0);

    glColor3f(0,1,0);    //minutes
    glBegin(GL_LINES);
    glVertex2i(0,0);
    glVertex2i(60,40);
    glEnd();

    glPopMatrix();

    y-=0.0007f;

    glPushMatrix();
    glTranslatef(1130.0,390.0,0.0);
    glRotatef(z,0.0,0.0,1.0);

    glColor3f(1,0,0);  //hour
    glBegin(GL_LINES);
    glVertex2i(0,0);
    glVertex2i(50,30);
    glEnd();

    glPopMatrix();

    z-=0.0002f;

    //

    glColor3f(0.7,0.8,0.8); //wind mill
    glBegin(GL_POLYGON);
    glVertex2f(1680.0,900.0);
    glVertex2f(1730.0,900.0);
    glVertex2f(1730.0,680.0);
    glVertex2f(1680.0,680.0);
    glEnd();


    glPushMatrix();
    glTranslatef(1705.0,900.0,0.0);
    glRotatef(m,0.0,0.0,1.0);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f( 150.0f,70.0f);
    glVertex2f( 150.0f,-50.0f);
    glEnd();

    glPopMatrix();

    m-=0.1f;


    glPushMatrix();
    glTranslatef(1705.0,900.0,0.0);
    glRotatef(n,0.0,0.0,1.0);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f( -150.0f,70.0f);
    glVertex2f( -150.0f,-50.0f);
    glEnd();

    glPopMatrix();

    n-=0.1f;


    glColor3f(0.3,0.3,0.3);
    glBegin(GL_POLYGON);    // road
    glVertex2i(0, 250);
    glVertex2i(2000,250);
    glVertex2i(2000,0);
    glVertex2i(0,0);
    glEnd();

    glColor3f(1.0,1.0,0.3);
    glBegin(GL_POLYGON);    // road yellow line up
    glVertex2i(0, 250);
    glVertex2i(2000,250);
    glVertex2i(2000,240);
    glVertex2i(0,240);
    glEnd();

    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);    // road yellow line down
    glVertex2i(0, 10);
    glVertex2i(2000,10);
    glVertex2i(2000,0);
    glVertex2i(0,0);
    glEnd();


    glColor3f(1.0,1.0,0.3); //road line middle
    glBegin(GL_LINES);
    glVertex2i(0,125);
    glVertex2i(200,125);
    glVertex2i(400,125);
    glVertex2i(700,125);
    glVertex2i(900,125);
    glVertex2i(1200,125);
    glVertex2i(1400,125);
    glVertex2i(1700,125);
    glEnd();


    glPushMatrix();                  //car
    glTranslatef(CarPosition,0,0);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.4f, 0.5f);
    glVertex2f(55.f, 100.0f);
    glVertex2f(435.0f, 100.0f);
    glVertex2f(465.0f, 35.0f);
    glVertex2f(15.0f, 35.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f,0.2f,0.7f);
    glVertex2f(100,100);
    glVertex2f(150,150);
    glVertex2f(350,150);
    glVertex2f(400,100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(120,100);
    glVertex2f(160,140);
    glVertex2f(340,140);
    glVertex2f(380,100);
    glEnd();

    glTranslated(130,50,0);   //wheels 1
    glColor3f(0.0, 0.0, 0.0);
    circle(25,35,0,0);

    glTranslated(220,00,0);  //wheels 2
    glColor3f(0.0, 0.0, 0.0);
    circle(25,35,0,0);

    glPopMatrix();


    glPushMatrix();
    glTranslatef(SkyPosition,0,0);

    glTranslated(1500,1300,0);  //sky
    glColor3f(1.0, 1.0, 1.0);
    circle(50,60,0,0);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(SkyPosition,0,0);

    glTranslated(1560,1320,0);  //sky
    glColor3f(1.0, 1.0, 1.0);
    circle(50,60,0,0);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(SkyPosition,0,0);

    glTranslated(1630,1300,0);  //sky
    glColor3f(1.0, 1.0, 1.0);
    circle(50,60,0,0);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(SkyPosition,0,0);

    glTranslated(1560,1270,0);  //sky
    glColor3f(1.0, 1.0, 1.0);
    circle(50,60,0,0);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(PlanePosition,0,0);

    glColor3f(0.5,0.6,0.5);
    glBegin(GL_POLYGON);    // plane
    glVertex2i(1550,1220);
    glVertex2i(1850,1220);
    glVertex2i(1850,1150);
    glVertex2i(1550,1150);
    glEnd();

    glColor3f(0.5,0.5,0.5);
    glBegin(GL_TRIANGLES);    // plane back wing
    glVertex2i(1850,1220);
    glVertex2i(1950,1270);
    glVertex2i(1850,1150);
    glEnd();

    glColor3f(0.5,0.5,0.5);
    glBegin(GL_TRIANGLES);    // plane up wing
    glVertex2i(1650,1220);
    glVertex2i(1750,1270);
    glVertex2i(1730,1220);
    glEnd();


    glTranslated(1545,1185,0);  // plane front
    glColor3f(0.5, 0.5,0.5);
    circle(50,35,0,0);


    glPopMatrix();

    glColor3f(0.8,0.4,0.0);   // Tree body
    glBegin(GL_POLYGON);
    glVertex2i(20,500);
    glVertex2i(80,500);
    glVertex2i(80,250);
    glVertex2i(20,250);
    glEnd();

    glColor3f(0.0,0.7,0.0);  // Tree green
    circle(70,80,20,550);
    circle(70,80,75,560);
    circle(90,80,45,650);



    glPushMatrix();
    glTranslatef(0,RainPosition,0);
    glColor3f(1.0,1.0,1.0);          //rain
    glBegin(GL_LINES);
    glVertex2i(200,1400);
    glVertex2i(200,1200);
    glVertex2i(200,1000);
    glVertex2i(200,800);

    glVertex2i(500,1400);
    glVertex2i(500,1200);
    glVertex2i(500,1000);
    glVertex2i(500,800);

    glVertex2i(800,1400);
    glVertex2i(800,1200);
    glVertex2i(800,1000);
    glVertex2i(800,800);

    glVertex2i(1100,1400);
    glVertex2i(1100,1200);
    glVertex2i(1100,1000);
    glVertex2i(1100,800);

    glVertex2i(1400,1400);
    glVertex2i(1400,1200);
    glVertex2i(1400,1000);
    glVertex2i(1400,800);

    glVertex2i(1700,1400);
    glVertex2i(1700,1200);
    glVertex2i(1700,1000);
    glVertex2i(1700,800);
    glEnd();

    glPopMatrix();

    glFlush();

    glutPostRedisplay();
}



void day()
{

    glClear(GL_COLOR_BUFFER_BIT);    // Clear display window
    glClearColor(0.0f,0.8f,0.7f,0.0f);
    sun();


    glColor3f(0,0.5,0.5);
    glBegin(GL_POLYGON);   // 1st floor
    glVertex2i(150, 400);
    glVertex2i(600, 400);
    glVertex2i(600, 250);
    glVertex2i(150, 250);
    glEnd();

    glColor3f(0.8,0.8,0.5);
    glBegin(GL_POLYGON);   // 1st floor door
    glVertex2i(290, 380);
    glVertex2i(450, 380);
    glVertex2i(450, 250);
    glVertex2i(290, 250);
    glEnd();

    glColor3f(0,0,0);     // 1st floor roof
    glBegin(GL_POLYGON);
    glVertex2i(150, 415);
    glVertex2i(600, 415);
    glVertex2i(600, 400);
    glVertex2i(150, 400);
    glEnd();

    glColor3f(0,0.4,0.5);  // 2nd floor
    glBegin(GL_POLYGON);
    glVertex2i(150, 575);
    glVertex2i(600, 575);
    glVertex2i(600, 415);
    glVertex2i(150, 415);
    glEnd();

    glColor3f(0,0,0.4);  // 2nd floor stairs window
    glBegin(GL_POLYGON);
    glVertex2i(340, 550);
    glVertex2i(400, 550);
    glVertex2i(400, 430);
    glVertex2i(340, 430);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_LINES);    // 2nd floor stairs line
    glVertex2i(370, 548);
    glVertex2i(370, 432);
    glVertex2i(342, 460);
    glVertex2i(400, 460);
    glVertex2i(342, 515);
    glVertex2i(400, 515);
    glEnd();


    glColor3f(0.8,0.8,0.5);
    glBegin(GL_POLYGON);    // 2nd floor 1st window
    glVertex2i(200, 520);
    glVertex2i(270, 520);
    glVertex2i(270, 452);
    glVertex2i(200, 452);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_LINES);    // 2nd floor 1st window line
    glVertex2i(235, 520);
    glVertex2i(235, 452);
    glVertex2i(200, 487);
    glVertex2i(270, 487);
    glEnd();

    glColor3f(0.8,0.8,0.5);
    glBegin(GL_POLYGON);    // 2nd floor 2nd window
    glVertex2i(480, 520);
    glVertex2i(550, 520);
    glVertex2i(550, 452);
    glVertex2i(480, 452);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_LINES);    // 2nd floor 2nd window line
    glVertex2i(515, 520);
    glVertex2i(515, 452);
    glVertex2i(480, 487);
    glVertex2i(550, 487);
    glEnd();


    glColor3f(0,0,0);
    glBegin(GL_POLYGON);    // 2nd floor roof
    glVertex2i(150, 590);
    glVertex2i(600, 590);
    glVertex2i(600, 575);
    glVertex2i(150, 575);
    glEnd();

    glColor3f(0,0.5,0.5);
    glBegin(GL_POLYGON);    // 3rd floor
    glVertex2i(150, 765);
    glVertex2i(600, 765);
    glVertex2i(600, 590);
    glVertex2i(150, 590);
    glEnd();

    glColor3f(0,0,0.4);
    glBegin(GL_POLYGON);    // 3rd floor stairs window
    glVertex2i(340, 740);
    glVertex2i(400, 740);
    glVertex2i(400, 610);
    glVertex2i(340, 610);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_LINES);    // 3rd floor stairs line
    glVertex2i(370, 738);
    glVertex2i(370, 612);
    glVertex2i(342, 700);
    glVertex2i(400, 700);
    glVertex2i(342, 645);
    glVertex2i(400, 645);
    glEnd();

    glColor3f(0.8,0.8,0.5);
    glBegin(GL_POLYGON);    // 3rd floor 1st window
    glVertex2i(200, 710);
    glVertex2i(270, 710);
    glVertex2i(270, 635);
    glVertex2i(200, 635);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_LINES);    // 3rd floor 1st window line
    glVertex2i(235, 710);
    glVertex2i(235, 635);
    glVertex2i(200, 670);
    glVertex2i(270, 670);
    glEnd();

    glColor3f(0.8,0.8,0.5);
    glBegin(GL_POLYGON);    // 3rd floor 2nd window
    glVertex2i(480, 710);
    glVertex2i(550, 710);
    glVertex2i(550, 635);
    glVertex2i(480, 635);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_LINES);    // 3rd floor 2nd window line
    glVertex2i(515, 710);
    glVertex2i(515, 635);
    glVertex2i(480, 670);
    glVertex2i(550, 670);
    glEnd();

    glColor3f(0.8,0.4,0);
    glBegin(GL_POLYGON);    // roof top
    glVertex2i(130, 765);
    glVertex2i(620, 765);
    glVertex2i(620, 795);
    glVertex2i(130, 795);
    glEnd();
//

    glColor3f(0.7,0.3,0.2);   //2nd building front
    glBegin(GL_POLYGON);
    glVertex2i(900,550);
    glVertex2i(1350,550);
    glVertex2i(1350,250);
    glVertex2i(900,250);
    glEnd();

    glColor3f(0.6,0.2,0.0);   //2nd building back
    glBegin(GL_POLYGON);
    glVertex2i(750,550);
    glVertex2i(900,550);
    glVertex2i(900,250);
    glVertex2i(750,250);
    glEnd();

    glColor3f(0.9,0.7,0.3);   //2nd building roof front
    glBegin(GL_POLYGON);
    glVertex2i(880,580);
    glVertex2i(1370,580);
    glVertex2i(1370,550);
    glVertex2i(880,550);
    glEnd();

    glColor3f(1.0,0.6,0.1);   //2nd building roof back
    glBegin(GL_POLYGON);
    glVertex2i(730,580);
    glVertex2i(880,580);
    glVertex2i(880,550);
    glVertex2i(730,550);
    glEnd();

    glColor3f(0.7,0.3,0.2);   //2nd building 2nd floor front
    glBegin(GL_POLYGON);
    glVertex2i(900,750);
    glVertex2i(1350,750);
    glVertex2i(1350,580);
    glVertex2i(900,580);
    glEnd();

    glColor3f(0.6,0.2,0.0);   //2nd building 2nd floor back
    glBegin(GL_POLYGON);
    glVertex2i(750,750);
    glVertex2i(900,750);
    glVertex2i(900,580);
    glVertex2i(750,580);
    glEnd();

    glColor3f(0.9,0.7,0.3);   //2nd building 2nd floor roof front
    glBegin(GL_POLYGON);
    glVertex2i(880,780);
    glVertex2i(1370,780);
    glVertex2i(1370,750);
    glVertex2i(880,750);
    glEnd();

    glColor3f(1.0,0.6,0.1);   //2nd building 2nd floor roof back
    glBegin(GL_POLYGON);
    glVertex2i(730,780);
    glVertex2i(880,780);
    glVertex2i(880,750);
    glVertex2i(730,750);
    glEnd();


    glColor3f(0.7,0.8,0.8);   //2nd building window 1
    glBegin(GL_POLYGON);
    glVertex2i(950,720);
    glVertex2i(1050,720);
    glVertex2i(1050,600);
    glVertex2i(950,600);
    glEnd();

    glColor3f(0.7,0.8,0.8);   //2nd building window 2
    glBegin(GL_POLYGON);
    glVertex2i(1075,720);
    glVertex2i(1175,720);
    glVertex2i(1175,600);
    glVertex2i(1075,600);
    glEnd();

    glColor3f(0.7,0.8,0.8);   //2nd building window 3
    glBegin(GL_POLYGON);
    glVertex2i(1205,720);
    glVertex2i(1305,720);
    glVertex2i(1305,600);
    glVertex2i(1205,600);
    glEnd();

    glColor3f(0,0,0);   //2nd building Door black layer
    glBegin(GL_POLYGON);
    glVertex2i(940,520);
    glVertex2i(1310,520);
    glVertex2i(1310,250);
    glVertex2i(940,250);
    glEnd();

    glColor3f(0.7,0.8,0.8);   //2nd building Door silver layer
    glBegin(GL_POLYGON);
    glVertex2i(980,480);
    glVertex2i(1270,480);
    glVertex2i(1270,290);
    glVertex2i(980,290);
    glEnd();

    glColor3f(0.4,1,0.7);  // 3rd building front
    glBegin(GL_POLYGON);
    glVertex2i(1650,650);
    glVertex2i(2000,650);
    glVertex2i(2000,250);
    glVertex2i(1650,250);
    glEnd();

    glColor3f(0.4,1,0.5); // back
    glBegin(GL_POLYGON);
    glVertex2i(1530,650);
    glVertex2i(1650,650);
    glVertex2i(1650,250);
    glVertex2i(1530,250);
    glEnd();

    glColor3f(0,0.6,0.1); // roof
    glBegin(GL_POLYGON);
    glVertex2i(1530,680);
    glVertex2i(1650,680);
    glVertex2i(1650,650);
    glVertex2i(1530,650);
    glEnd();

    glColor3f(0,0.7,0);  //roof
    glBegin(GL_POLYGON);
    glVertex2i(1650,680);
    glVertex2i(2000,680);
    glVertex2i(2000,650);
    glVertex2i(1650,650);
    glEnd();

    glColor3f(0.5,0,0);   //window
    glBegin(GL_POLYGON);
    glVertex2i(1700,620);
    glVertex2i(1780,620);
    glVertex2i(1780,550);
    glVertex2i(1700,550);
    glEnd();

     glColor3f(0.5,0,0);   //window
    glBegin(GL_POLYGON);
    glVertex2i(1900,620);
    glVertex2i(1980,620);
    glVertex2i(1980,550);
    glVertex2i(1900,550);
    glEnd();

    glColor3f(0.5,0,0);   //window
    glBegin(GL_POLYGON);
    glVertex2i(1700,520);
    glVertex2i(1780,520);
    glVertex2i(1780,450);
    glVertex2i(1700,450);
    glEnd();

    glColor3f(0.5,0,0);   //window
    glBegin(GL_POLYGON);
    glVertex2i(1900,520);
    glVertex2i(1980,520);
    glVertex2i(1980,450);
    glVertex2i(1900,450);
    glEnd();

    glColor3f(0.5,0,0);   //window
    glBegin(GL_POLYGON);
    glVertex2i(1900,520);
    glVertex2i(1980,520);
    glVertex2i(1980,450);
    glVertex2i(1900,450);
    glEnd();

    glColor3f(0,0,0);   //Door
    glBegin(GL_POLYGON);
    glVertex2i(1710,420);
    glVertex2i(1970,420);
    glVertex2i(1970,250);
    glVertex2i(1710,250);
    glEnd();


    glColor3f(0.5,0.6,0.6);   //back ground building
    glBegin(GL_POLYGON);
    glVertex2i(820,980);
    glVertex2i(1070,980);
    glVertex2i(1070,780);
    glVertex2i(820,780);
    glEnd();

    glColor3f(0.4,0.4,0.4);   //back ground building dark side
    glBegin(GL_POLYGON);
    glVertex2i(1070,980);
    glVertex2i(1220,980);
    glVertex2i(1220,780);
    glVertex2i(1070,780);
    glEnd();

    glColor3f(0.4,0.5,0.5);   //back ground building roof
    glBegin(GL_POLYGON);
    glVertex2i(810,1000);
    glVertex2i(1080,1000);
    glVertex2i(1080,980);
    glVertex2i(810,980);
    glEnd();

    glColor3f(0.3,0.4,0.4);   //back ground building dark side roof
    glBegin(GL_POLYGON);
    glVertex2i(1080,1000);
    glVertex2i(1230,1000);
    glVertex2i(1230,980);
    glVertex2i(1080,980);
    glEnd();

    glColor3f(0.2,0.2,0.3);   //back ground building dark side line
    glBegin(GL_LINES);
    glVertex2i(1120,980);
    glVertex2i(1120,780);
    glVertex2i(1180,980);
    glVertex2i(1180,780);

    glVertex2i(1070,880);
    glVertex2i(1220,880);
    glEnd();

    glColor3f(0.4,0.5,0.5);   //back ground building window up1
    glBegin(GL_POLYGON);
    glVertex2i(840,950);
    glVertex2i(900,950);
    glVertex2i(900,880);
    glVertex2i(840,880);
    glEnd();

    glColor3f(0.4,0.5,0.5);   //back ground building window up2
    glBegin(GL_POLYGON);
    glVertex2i(915,950);
    glVertex2i(975,950);
    glVertex2i(975,880);
    glVertex2i(915,880);
    glEnd();

    glColor3f(0.4,0.5,0.5);   //back ground building window up3
    glBegin(GL_POLYGON);
    glVertex2i(990,950);
    glVertex2i(1050,950);
    glVertex2i(1050,880);
    glVertex2i(990,880);
    glEnd();

     glColor3f(0.4,0.5,0.5);   //back ground building window down1
    glBegin(GL_POLYGON);
    glVertex2i(840,860);
    glVertex2i(900,860);
    glVertex2i(900,790);
    glVertex2i(840,790);
    glEnd();

    glColor3f(0.4,0.5,0.5);   //back ground building window down2
    glBegin(GL_POLYGON);
    glVertex2i(915,860);
    glVertex2i(975,860);
    glVertex2i(975,790);
    glVertex2i(915,790);
    glEnd();

    glColor3f(0.4,0.5,0.5);   //back ground building window down3
    glBegin(GL_POLYGON);
    glVertex2i(990,860);
    glVertex2i(1050,860);
    glVertex2i(1050,790);
    glVertex2i(990,790);
    glEnd();

    glColor3f(0.5,0.6,0.6);   //back ground building water tank
    glBegin(GL_POLYGON);
    glVertex2i(870,1050);
    glVertex2i(970,1050);
    glVertex2i(970,1000);
    glVertex2i(870,1000);
    glEnd();

////
    clock();

    glPushMatrix();
    glTranslatef(1130.0,390.0,0.0);
    glRotatef(x,0.0,0.0,1.0);

    glColor3f(0,0,1); //second
    glBegin(GL_LINES);
    glVertex2i(0,0);
    glVertex2i(70,60);
    glEnd();

    glPopMatrix();

    x-=0.01f;

    glPushMatrix();
    glTranslatef(1130.0,390.0,0.0);
    glRotatef(y,0.0,0.0,1.0);

    glColor3f(0,1,0);    //minutes
    glBegin(GL_LINES);
    glVertex2i(0,0);
    glVertex2i(60,40);
    glEnd();

    glPopMatrix();

    y-=0.0007f;

    glPushMatrix();
    glTranslatef(1130.0,390.0,0.0);
    glRotatef(z,0.0,0.0,1.0);

    glColor3f(1,0,0);  //hour
    glBegin(GL_LINES);
    glVertex2i(0,0);
    glVertex2i(50,30);
    glEnd();

    glPopMatrix();

    z-=0.0002f;

    //

    glColor3f(0.7,0.8,0.8); //wind mill
    glBegin(GL_POLYGON);
    glVertex2f(1680.0,900.0);
    glVertex2f(1730.0,900.0);
    glVertex2f(1730.0,680.0);
    glVertex2f(1680.0,680.0);
    glEnd();


    glPushMatrix();
    glTranslatef(1705.0,900.0,0.0);
    glRotatef(m,0.0,0.0,1.0);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f( 150.0f,70.0f);
    glVertex2f( 150.0f,-50.0f);
    glEnd();

    glPopMatrix();

    m-=0.1f;


    glPushMatrix();
    glTranslatef(1705.0,900.0,0.0);
    glRotatef(n,0.0,0.0,1.0);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f( -150.0f,70.0f);
    glVertex2f( -150.0f,-50.0f);
    glEnd();

    glPopMatrix();

    n-=0.1f;


    glColor3f(0.3,0.3,0.3);
    glBegin(GL_POLYGON);    // road
    glVertex2i(0, 250);
    glVertex2i(2000,250);
    glVertex2i(2000,0);
    glVertex2i(0,0);
    glEnd();

    glColor3f(1.0,1.0,0.3);
    glBegin(GL_POLYGON);    // road yellow line up
    glVertex2i(0, 250);
    glVertex2i(2000,250);
    glVertex2i(2000,240);
    glVertex2i(0,240);
    glEnd();

    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);    // road yellow line down
    glVertex2i(0, 10);
    glVertex2i(2000,10);
    glVertex2i(2000,0);
    glVertex2i(0,0);
    glEnd();


    glColor3f(1.0,1.0,0.3); //road line middle
    glBegin(GL_LINES);
    glVertex2i(0,125);
    glVertex2i(200,125);
    glVertex2i(400,125);
    glVertex2i(700,125);
    glVertex2i(900,125);
    glVertex2i(1200,125);
    glVertex2i(1400,125);
    glVertex2i(1700,125);
    glEnd();


    glPushMatrix();                  //car
    glTranslatef(CarPosition,0,0);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.4f, 0.5f);
    glVertex2f(55.f, 100.0f);
    glVertex2f(435.0f, 100.0f);
    glVertex2f(465.0f, 35.0f);
    glVertex2f(15.0f, 35.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f,0.2f,0.7f);
    glVertex2f(100,100);
    glVertex2f(150,150);
    glVertex2f(350,150);
    glVertex2f(400,100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(120,100);
    glVertex2f(160,140);
    glVertex2f(340,140);
    glVertex2f(380,100);
    glEnd();

    glTranslated(130,50,0);   //wheels 1
    glColor3f(0.0, 0.0, 0.0);
    circle(25,35,0,0);

    glTranslated(220,00,0);  //wheels 2
    glColor3f(0.0, 0.0, 0.0);
    circle(25,35,0,0);

    glPopMatrix();


    glPushMatrix();
    glTranslatef(SkyPosition,0,0);

    glTranslated(1500,1300,0);  //sky
    glColor3f(1.0, 1.0, 1.0);
    circle(50,60,0,0);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(SkyPosition,0,0);

    glTranslated(1560,1320,0);  //sky
    glColor3f(1.0, 1.0, 1.0);
    circle(50,60,0,0);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(SkyPosition,0,0);

    glTranslated(1630,1300,0);  //sky
    glColor3f(1.0, 1.0, 1.0);
    circle(50,60,0,0);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(SkyPosition,0,0);

    glTranslated(1560,1270,0);  //sky
    glColor3f(1.0, 1.0, 1.0);
    circle(50,60,0,0);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(PlanePosition,0,0);

    glColor3f(0.5,0.6,0.5);
    glBegin(GL_POLYGON);    // plane
    glVertex2i(1550,1220);
    glVertex2i(1850,1220);
    glVertex2i(1850,1150);
    glVertex2i(1550,1150);
    glEnd();

    glColor3f(0.5,0.5,0.5);
    glBegin(GL_TRIANGLES);    // plane back wing
    glVertex2i(1850,1220);
    glVertex2i(1950,1270);
    glVertex2i(1850,1150);
    glEnd();

    glColor3f(0.5,0.5,0.5);
    glBegin(GL_TRIANGLES);    // plane up wing
    glVertex2i(1650,1220);
    glVertex2i(1750,1270);
    glVertex2i(1730,1220);
    glEnd();


    glTranslated(1545,1185,0);  // plane front
    glColor3f(0.5, 0.5,0.5);
    circle(50,35,0,0);


    glPopMatrix();

    glColor3f(0.8,0.4,0.0);   // Tree body
    glBegin(GL_POLYGON);
    glVertex2i(20,500);
    glVertex2i(80,500);
    glVertex2i(80,250);
    glVertex2i(20,250);
    glEnd();

    glColor3f(0.0,0.7,0.0);  // Tree green
    circle(70,80,20,550);
    circle(70,80,75,560);
    circle(90,80,45,650);

	glFlush();
}

void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
case 'p':
    CarSpeed = 0.0f;
    SkySpeed = 0.0f;
    break;
case 'r':
    CarSpeed = 10.0f;
    SkySpeed = 10.0f;
    break;
case 'd':
    glutDisplayFunc(day);
    break;
case 'n':
    glutDisplayFunc(night);
    break;

glutPostRedisplay();
	}
}

int main(int argc, char ** argv)
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
    glutCreateWindow("City view in OpenGL ");
    // Execute initialization procedure
    init();
    // Send graphics to display window
    glutDisplayFunc(day);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutSpecialFunc(SpecialInput);
    // Display everything and wait.
    glutIdleFunc(Idle);
    glutTimerFunc(100, CarUpdate, 0);
    glutTimerFunc(100, SkyUpdate, 0);
    glutTimerFunc(100, PlaneUpdate, 0);
    glutTimerFunc(100, RainUpdate, 0);
    glutMainLoop();
    glLoadIdentity();

    return 0;
}

