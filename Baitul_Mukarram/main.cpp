#include<Windows.h>       // for MS Windows
#include<GL\glut.h>
#include<math.h>>
#define PI    3.14159265358979323846

GLfloat m = 0.0f, n = 0.0f, x = 0.0f, y = 0.0f,z = 0.0f;

void init()
{
    glClearColor(0.5f,0.9f,0.9f,0.0f);
    gluOrtho2D(0.0, 2000, 0.0, 1800);
}

GLfloat Car1Position = 50.0f;
GLfloat Car1Speed = 20.0f;

GLfloat Car2Position = 50.0f;
GLfloat Car2Speed = 20.0f;

GLfloat SkyPosition = 50.0f;
GLfloat SkySpeed = 10.0f;

GLfloat RainPosition = 50.0f;
GLfloat RainSpeed = 40.0f;



void Car1Update(int value) {

    if(Car1Position > 2000.0)
         Car1Position = -10.0f;

    Car1Position += Car1Speed; //position=position-speed;1-.1=.9

	glutPostRedisplay();

	glutTimerFunc(100, Car1Update, 0);
}

void Car2Update(int value) {

    if(Car2Position < -2000.0)
         Car2Position = 20.0f;

    Car2Position -= Car2Speed; //position=position-speed;1-.1=.9

	glutPostRedisplay();

	glutTimerFunc(100, Car2Update, 0);
}


void SkyUpdate(int value) {

    if(SkyPosition < -2000.0)
         SkyPosition = 10.0f;

    SkyPosition -= SkySpeed; //position=position-speed;1-.1=.9

	glutPostRedisplay();

	glutTimerFunc(100, SkyUpdate, 0);
}

void RainUpdate(int value) {

    if(RainPosition < -100.0)
         RainPosition = 10.0f;

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
    glTranslated(1870,1700,0);
    glColor3f(1.0, 0.76, 0.3);
    circle(60,70,0,0);
    glPopMatrix();
}

void moon()
{
    glPushMatrix();
    glTranslated(100,1700,0);
    glColor3f(1.0, 1.0, 1.0);
    circle(60,70,0,0);
    glPopMatrix();
}

void clock()
{
    glPushMatrix();
    glTranslated(1000,1285,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(80,80,0,0);
    glPopMatrix();
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON){
			Car1Speed += 3.1f;
			SkySpeed += 3.1f;
			Car2Speed += 3.1f;
			}
			if (button == GLUT_RIGHT_BUTTON)
	{Car1Speed -= 1.1f;
	SkySpeed -= 1.1f;
	Car2Speed -= 1.1f;
			}
	glutPostRedisplay();
}

void SpecialInput(int key, int x, int y)
{
switch(key)
{case GLUT_KEY_UP:
   Car1Speed=10.5;
   Car2Speed=10.5;
   SkySpeed=10.5;
   break;
case GLUT_KEY_DOWN:
   Car1Speed=5.2;
   Car2Speed=5.2;
   SkySpeed=5.2;
   break;
case GLUT_KEY_LEFT:
   Car1Speed=20.5;
   Car2Speed=20.5;
   SkySpeed=20.5;
   break;
case GLUT_KEY_RIGHT:
   Car1Speed=10.5;
   Car2Speed=10.5;
   SkySpeed=10.5;
   break;}

glutPostRedisplay();
}

void rain()
{
    glClearColor(0.7f,0.8f,0.8f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT);    // Clear display window

    glLoadIdentity();
    gluOrtho2D(0.0, 2000, 0.0, 1800);

    //sun();

    glColor3f(1.0,1.0,1.0);  // basic shape
    glBegin(GL_POLYGON);
    glVertex2i(0, 1100);
    glVertex2i(2000, 1100);
    glVertex2i(2000, 780);
    glVertex2i(0, 780);
    glEnd();

    glColor3f(1.0,1.0,1.0);  // upper square shape
    glBegin(GL_POLYGON);
    glVertex2i(750, 1500);
    glVertex2i(1250, 1500);
    glVertex2i(1250, 1100);
    glVertex2i(750, 1100);
    glEnd();

    glColor3f(0.0,0.0,0.0); //upper 3 line
    glBegin(GL_POLYGON);
    glVertex2i(750, 1440);
    glVertex2i(1250, 1440);
    glVertex2i(1250, 1430);
    glVertex2i(750, 1430);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(750, 1410);
    glVertex2i(1250, 1410);
    glVertex2i(1250, 1400);
    glVertex2i(750, 1400);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(750, 1380);
    glVertex2i(1250, 1380);
    glVertex2i(1250, 1370);
    glVertex2i(750, 1370);
    glEnd();

    clock();

    glPushMatrix();
    glTranslatef(1000.0,1285,0.0);
    glRotatef(x,0.0,0.0,1.0);

    glColor3f(0,0,1); //second
    glBegin(GL_LINES);
    glVertex2i(0,0);
    glVertex2i(55,45);
    glEnd();

    glPopMatrix();

    x-=0.01f;

    glPushMatrix();
    glTranslatef(1000.0,1285.0,0.0);
    glRotatef(y,0.0,0.0,1.0);

    glColor3f(0,1,0);    //minutes
    glBegin(GL_LINES);
    glVertex2i(0,0);
    glVertex2i(45,25);
    glEnd();

    glPopMatrix();

    y-=0.0007f;

    glPushMatrix();
    glTranslatef(1000.0,1285.0,0.0);
    glRotatef(z,0.0,0.0,1.0);

    glColor3f(1,0,0);  //hour
    glBegin(GL_LINES);
    glVertex2i(0,0);
    glVertex2i(35,15);
    glEnd();

    glPopMatrix();

    z-=0.0002f;

    // front door design

    glColor3f(0.6,0.6,0.6);
    glBegin(GL_LINES);
    glVertex2i(860,1200);
    glVertex2i(860,950);

    glVertex2i(860,1200);
    glVertex2i(1140,1200);

    glVertex2i(1140,1200);
    glVertex2i(1140,950);


    glEnd();

    glColor3f(0.0,0.0,0.0);  //middle door
    glBegin(GL_POLYGON);
    glVertex2i(960, 1130);
    glVertex2i(1040, 1130);
    glVertex2i(1040, 880);
    glVertex2i(960, 880);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(940, 1030);
    glVertex2i(960, 1030);
    glVertex2i(960, 880);
    glVertex2i(940, 880);
    glEnd();

    glColor3f(1.0,1.0,1.0);  //white column
    glBegin(GL_POLYGON);
    glVertex2i(948, 1030);
    glVertex2i(953, 1030);
    glVertex2i(953, 880);
    glVertex2i(948, 880);
    glEnd();


    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(880, 1060);
    glVertex2i(940, 1060);
    glVertex2i(940, 880);
    glVertex2i(880, 880);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1040, 1030);
    glVertex2i(1060, 1030);
    glVertex2i(1060, 880);
    glVertex2i(1040, 880);
    glEnd();

    glColor3f(1.0,1.0,1.0);  //white column
    glBegin(GL_POLYGON);
    glVertex2i(1048, 1030);
    glVertex2i(1053, 1030);
    glVertex2i(1053, 880);
    glVertex2i(1048, 880);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1060, 1060);
    glVertex2i(1120, 1060);
    glVertex2i(1120, 880);
    glVertex2i(1060, 880);
    glEnd();

    glPushMatrix();

    glTranslated(910,1060,0);  // door round shape
    glColor3f(0.0, 0.0, 0.0);
    circle(30,35,0,0);

    glTranslated(180,0,0);  // door round shape
    glColor3f(0.0, 0.0, 0.0);
    circle(30,35,0,0);

    glTranslated(-90,80,0);  // door round shape
    glColor3f(0.0, 0.0, 0.0);
    circle(40,45,0,0);

    glPopMatrix();


    glColor3f(0.7,0.5,0.3);  // ground
    glBegin(GL_POLYGON);
    glVertex2i(0, 780);
    glVertex2i(2000, 780);
    glVertex2i(2000, 0);
    glVertex2i(0,0);
    glEnd();

    glColor3f(0.6,0.9,0.9);  // aquarium white water
    glBegin(GL_POLYGON);
    glVertex2i(800, 600);
    glVertex2i(1200, 600);
    glVertex2i(1400, 400);
    glVertex2i(600,400);
    glEnd();

    glColor3f(0.3,0.5,1.0);  // aquarium blue water
    glBegin(GL_POLYGON);
    glVertex2i(800, 550);
    glVertex2i(1200, 550);
    glVertex2i(1350, 400);
    glVertex2i(650,400);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2i(800,600);
    glVertex2i(1200,600);

    glVertex2i(1400,400);
    glVertex2i(600,400);

    glVertex2i(800,600);
    glVertex2i(600,400);

    glVertex2i(1200,600);
    glVertex2i(1400,400);
    glEnd();

    glColor3f(0.9,0.9,1.0);  // aquarium light
    glBegin(GL_POLYGON);
    glVertex2i(980,700);
    glVertex2i(995,700);
    glVertex2i(995,600);
    glVertex2i(980,600);
    glEnd();

    glColor3f(0.9,0.9,1.0);
    glBegin(GL_POLYGON);
    glVertex2i(995,700);
    glVertex2i(1030,700);
    glVertex2i(1030,690);
    glVertex2i(995,690);
    glEnd();

    glColor3f(0.9,0.9,1.0); // triangles
    glBegin(GL_TRIANGLES);
    glVertex2i(1030, 700);
    glVertex2i(1060, 670);
    glVertex2i(1000, 670);
    glEnd();

    glColor3f(0.9,0.9,1.0);
    glBegin(GL_POLYGON);
    glVertex2i(710,660);
    glVertex2i(725,660);
    glVertex2i(725,520);
    glVertex2i(710,505);
    glEnd();

    glColor3f(0.9,0.9,1.0);
    glBegin(GL_POLYGON);
    glVertex2i(725,660);
    glVertex2i(770,660);
    glVertex2i(770,650);
    glVertex2i(725,650);
    glEnd();

    glColor3f(0.9,0.9,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(770, 660);
    glVertex2i(800, 630);
    glVertex2i(740, 630);
    glEnd();

    glColor3f(0.9,0.9,1.0);
    glBegin(GL_POLYGON);
    glVertex2i(960,530);
    glVertex2i(975,530);
    glVertex2i(975,400);
    glVertex2i(960,400);
    glEnd();

    glColor3f(0.9,0.9,1.0);
    glBegin(GL_POLYGON);
    glVertex2i(975,530);
    glVertex2i(1015,530);
    glVertex2i(1015,520);
    glVertex2i(975,520);
    glEnd();

    glColor3f(0.9,0.9,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(1015, 530);
    glVertex2i(1045, 500);
    glVertex2i(985, 500);
    glEnd();

    glColor3f(0.9,0.9,1.0);
    glBegin(GL_POLYGON);
    glVertex2i(1280,650);
    glVertex2i(1295,650);
    glVertex2i(1295,505);
    glVertex2i(1280,515);
    glEnd();

    glColor3f(0.9,0.9,1.0);
    glBegin(GL_POLYGON);
    glVertex2i(1235,640);
    glVertex2i(1280,640);
    glVertex2i(1280,650);
    glVertex2i(1235,650);
    glEnd();

    glColor3f(0.9,0.9,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(1235, 650);
    glVertex2i(1265, 620);
    glVertex2i(1205, 620);
    glEnd();


    //middle to right

    glColor3f(0.0,0.0,0.0);  // mosque upper window
    glBegin(GL_POLYGON);
    glVertex2i(1165, 1065);
    glVertex2i(1185, 1065);
    glVertex2i(1185, 970);
    glVertex2i(1165, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1195, 1065);
    glVertex2i(1215, 1065);
    glVertex2i(1215, 970);
    glVertex2i(1195, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0); // triangles
    glBegin(GL_TRIANGLES);
    glVertex2i(1170, 1070);
    glVertex2i(1190, 1100);
    glVertex2i(1210, 1070);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1240, 1050);
    glVertex2i(1260, 1050);
    glVertex2i(1260, 970);
    glVertex2i(1240, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1280, 1050);
    glVertex2i(1300, 1050);
    glVertex2i(1300, 970);
    glVertex2i(1280, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1320, 1050);
    glVertex2i(1340, 1050);
    glVertex2i(1340, 970);
    glVertex2i(1320, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1360, 1050);
    glVertex2i(1380, 1050);
    glVertex2i(1380, 970);
    glVertex2i(1360, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1400, 1050);
    glVertex2i(1420, 1050);
    glVertex2i(1420, 970);
    glVertex2i(1400, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1440, 1050);
    glVertex2i(1460, 1050);
    glVertex2i(1460, 970);
    glVertex2i(1440, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1480, 1050);
    glVertex2i(1500, 1050);
    glVertex2i(1500, 970);
    glVertex2i(1480, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1520, 1050);
    glVertex2i(1540, 1050);
    glVertex2i(1540, 970);
    glVertex2i(1520, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1560, 1050);
    glVertex2i(1580, 1050);
    glVertex2i(1580, 970);
    glVertex2i(1560, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1600, 1050);
    glVertex2i(1620, 1050);
    glVertex2i(1620, 970);
    glVertex2i(1600, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1640, 1050);
    glVertex2i(1660, 1050);
    glVertex2i(1660, 970);
    glVertex2i(1640, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1680, 1050);
    glVertex2i(1700, 1050);
    glVertex2i(1700, 970);
    glVertex2i(1680, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1720, 1050);
    glVertex2i(1740, 1050);
    glVertex2i(1740, 970);
    glVertex2i(1720, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1760, 1050);
    glVertex2i(1780, 1050);
    glVertex2i(1780, 970);
    glVertex2i(1760, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1800, 1050);
    glVertex2i(1820, 1050);
    glVertex2i(1820, 970);
    glVertex2i(1800, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1840, 1050);
    glVertex2i(1860, 1050);
    glVertex2i(1860, 970);
    glVertex2i(1840, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1880, 1050);
    glVertex2i(1900, 1050);
    glVertex2i(1900, 970);
    glVertex2i(1880, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1920, 1050);
    glVertex2i(1940, 1050);
    glVertex2i(1940, 970);
    glVertex2i(1920, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1960, 1050);
    glVertex2i(1980, 1050);
    glVertex2i(1980, 970);
    glVertex2i(1960, 970);
    glEnd();


    // middle to left

    glColor3f(0.0,0.0,0.0);  // mosque upper widow
    glBegin(GL_POLYGON);
    glVertex2i(815, 1065);
    glVertex2i(835, 1065);
    glVertex2i(835, 970);
    glVertex2i(815, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(785, 1065);
    glVertex2i(805, 1065);
    glVertex2i(805, 970);
    glVertex2i(785, 970);
    glEnd();


    glColor3f(0.0,0.0,0.0); // triangles
    glBegin(GL_TRIANGLES);
    glVertex2i(790, 1070);
    glVertex2i(810, 1100);
    glVertex2i(830, 1070);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(760, 1050);
    glVertex2i(740, 1050);
    glVertex2i(740, 970);
    glVertex2i(760, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(720, 1050);
    glVertex2i(700, 1050);
    glVertex2i(700, 970);
    glVertex2i(720, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(680, 1050);
    glVertex2i(660, 1050);
    glVertex2i(660, 970);
    glVertex2i(680, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(640, 1050);
    glVertex2i(620, 1050);
    glVertex2i(620, 970);
    glVertex2i(640, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(600, 1050);
    glVertex2i(580, 1050);
    glVertex2i(580, 970);
    glVertex2i(600, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(560, 1050);
    glVertex2i(540, 1050);
    glVertex2i(540, 970);
    glVertex2i(560, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(520, 1050);
    glVertex2i(500, 1050);
    glVertex2i(500, 970);
    glVertex2i(520, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(480, 1050);
    glVertex2i(460, 1050);
    glVertex2i(460, 970);
    glVertex2i(480, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(440, 1050);
    glVertex2i(420, 1050);
    glVertex2i(420, 970);
    glVertex2i(440, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(400, 1050);
    glVertex2i(380, 1050);
    glVertex2i(380, 970);
    glVertex2i(400, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(360, 1050);
    glVertex2i(340, 1050);
    glVertex2i(340, 970);
    glVertex2i(360, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(320, 1050);
    glVertex2i(300, 1050);
    glVertex2i(300, 970);
    glVertex2i(320, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(280, 1050);
    glVertex2i(260, 1050);
    glVertex2i(260, 970);
    glVertex2i(280, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(240, 1050);
    glVertex2i(220, 1050);
    glVertex2i(220, 970);
    glVertex2i(240, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(200, 1050);
    glVertex2i(180, 1050);
    glVertex2i(180, 970);
    glVertex2i(200, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(160, 1050);
    glVertex2i(140, 1050);
    glVertex2i(140, 970);
    glVertex2i(160, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(120, 1050);
    glVertex2i(100, 1050);
    glVertex2i(100, 970);
    glVertex2i(120, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(80, 1050);
    glVertex2i(60, 1050);
    glVertex2i(60, 970);
    glVertex2i(80, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(40, 1050);
    glVertex2i(20, 1050);
    glVertex2i(20, 970);
    glVertex2i(40, 970);
    glEnd();


    //stairs design

    glColor3f(0.5,0.6,0.6);
    glBegin(GL_POLYGON);
    glVertex2i(845, 950);     // ash color
    glVertex2i(1155, 950);
    glVertex2i(1080, 910);
    glVertex2i(920, 910);
    glEnd();

    glColor3f(0.6,0.6,0.5); // middle stairs
    glBegin(GL_POLYGON);
    glVertex2i(920, 910);
    glVertex2i(1080, 910);
    glVertex2i(1200, 710);
    glVertex2i(800, 710);
    glEnd();


    glColor3f(0.6,0.6,0.5);  // left stairs
    glBegin(GL_POLYGON);
    glVertex2i(845, 950);
    glVertex2i(920, 910);
    glVertex2i(800, 710);
    glVertex2i(700, 740);
    glEnd();

    glColor3f(0.6,0.6,0.5);  // right stairs
    glBegin(GL_POLYGON);
    glVertex2i(1080, 910);
    glVertex2i(1155, 950);
    glVertex2i(1300, 740);
    glVertex2i(1200, 710);
    glEnd();



    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);

    glVertex2i(904,880);
    glVertex2i(1098,880);

    glVertex2i(904,880);
    glVertex2i(820,920);

    glVertex2i(1098,880);
    glVertex2i(1175,920);

    glVertex2i(883,850);
    glVertex2i(1117,850);

    glVertex2i(883,850);
    glVertex2i(800,888);

    glVertex2i(1117,850);
    glVertex2i(1198,893);

    glVertex2i(865,820);
    glVertex2i(1137,820);

    glVertex2i(865,820);
    glVertex2i(778,860);

    glVertex2i(1137,820);
    glVertex2i(1213,863);

    glVertex2i(850,790);
    glVertex2i(1153,790);

    glVertex2i(850,790);
    glVertex2i(758,832);

    glVertex2i(1153,790);
    glVertex2i(1235,838);

    glVertex2i(830,760);
    glVertex2i(1170,760);

    glVertex2i(830,760);
    glVertex2i(737,800);

    glVertex2i(1170,760);
    glVertex2i(1250,808);

    glVertex2i(810,730);
    glVertex2i(1190,730);

    glVertex2i(810,730);
    glVertex2i(717,767);

    glVertex2i(1190,730);
    glVertex2i(1280,773);



    /////


    glVertex2i(800,710);
    glVertex2i(1200,710);

    glVertex2i(1200,710);
    glVertex2i(1300,740);

    glVertex2i(1300,740);
    glVertex2i(1155,950);

    glVertex2i(800,710);
    glVertex2i(700,740);

    glVertex2i(700,740);
    glVertex2i(845,950);
    glEnd();

    glColor3f(1.0,1.0,1.0);  // Lower side wall right
    glBegin(GL_TRIANGLES);
    glVertex2i(1280, 780);
    glVertex2i(2000, 780);
    glVertex2i(2000, 720);
    glEnd();

    glColor3f(1.0,1.0,1.0);  // Lower side wall Left
    glBegin(GL_TRIANGLES);
    glVertex2i(0, 780);
    glVertex2i(728,780);
    glVertex2i(0, 720);
    glEnd();

    //lower window left

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(705, 930);
    glVertex2i(745, 930);
    glVertex2i(745, 810);
    glVertex2i(705, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(655, 930);
    glVertex2i(695, 930);
    glVertex2i(695, 810);
    glVertex2i(655, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(605, 930);
    glVertex2i(645, 930);
    glVertex2i(645, 810);
    glVertex2i(605, 810);
    glEnd();

    //lower window right

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1250, 930);
    glVertex2i(1290, 930);
    glVertex2i(1290, 810);
    glVertex2i(1250, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1300, 930);
    glVertex2i(1340, 930);
    glVertex2i(1340, 810);
    glVertex2i(1300, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1350, 930);
    glVertex2i(1390, 930);
    glVertex2i(1390, 810);
    glVertex2i(1350, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0); //right side wide window
    glBegin(GL_POLYGON);
    glVertex2i(1420, 880);
    glVertex2i(1510, 880);
    glVertex2i(1510, 810);
    glVertex2i(1420, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1540, 880);
    glVertex2i(1630, 880);
    glVertex2i(1630, 810);
    glVertex2i(1540, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1660, 880);
    glVertex2i(1750, 880);
    glVertex2i(1750, 810);
    glVertex2i(1660, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1780, 880);
    glVertex2i(1870, 880);
    glVertex2i(1870, 810);
    glVertex2i(1780, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1900, 880);
    glVertex2i(1990, 880);
    glVertex2i(1990, 810);
    glVertex2i(1900, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);//left side wide window
    glBegin(GL_POLYGON);
    glVertex2i(485, 880);
    glVertex2i(575, 880);
    glVertex2i(575, 810);
    glVertex2i(485, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(365, 880);
    glVertex2i(455, 880);
    glVertex2i(455, 810);
    glVertex2i(365, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(245, 880);
    glVertex2i(335, 880);
    glVertex2i(335, 810);
    glVertex2i(245, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(125, 880);
    glVertex2i(215, 880);
    glVertex2i(215, 810);
    glVertex2i(125, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(5, 880);
    glVertex2i(95, 880);
    glVertex2i(95, 810);
    glVertex2i(5, 810);
    glEnd();

    glPushMatrix();
    glTranslated(50,880,0);  //window top shape left to right
    glColor3f(0.0, 0.0, 0.0);
    circle(45,50,0,0);

    glTranslated(120,0,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(45,50,0,0);

    glTranslated(120,0,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(45,50,0,0);

    glTranslated(120,0,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(45,50,0,0);

    glTranslated(120,0,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(45,50,0,0);

    glTranslated(935,0,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(45,50,0,0);

    glTranslated(120,0,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(45,50,0,0);

    glTranslated(120,0,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(45,50,0,0);

    glTranslated(120,0,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(45,50,0,0);

    glTranslated(120,0,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(45,50,0,0);

    glPopMatrix();

    glColor3f(0.0,0.7,0.0); // Field
    glBegin(GL_POLYGON);
    glVertex2i(0, 680);
    glVertex2i(720, 680);
    glVertex2i(360, 280);
    glVertex2i(0, 280);
    glEnd();

    glColor3f(0.0,0.7,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1280, 680);
    glVertex2i(2000, 680);
    glVertex2i(2000, 280);
    glVertex2i(1640, 280);
    glEnd();

    glColor3f(0.3,0.9,0.1); // Field left
    glBegin(GL_POLYGON);
    glVertex2i(150, 680);
    glVertex2i(290, 680);
    glVertex2i(0, 490);
    glVertex2i(0, 590);
    glEnd();

    glColor3f(0.3,0.9,0.1);
    glBegin(GL_POLYGON);
    glVertex2i(380, 680);
    glVertex2i(500, 680);
    glVertex2i(0, 290);
    glVertex2i(0, 400);
    glEnd();

    glColor3f(0.3,0.9,0.1);
    glBegin(GL_POLYGON);
    glVertex2i(580, 680);
    glVertex2i(690, 680);
    glVertex2i(250, 280);
    glVertex2i(100, 280);
    glEnd();

    glColor3f(0.3,0.9,0.1); // Field right
    glBegin(GL_POLYGON);
    glVertex2i(1850, 680);
    glVertex2i(1710, 680);
    glVertex2i(2000, 490);
    glVertex2i(2000, 590);
    glEnd();

    glColor3f(0.3,0.9,0.1);
    glBegin(GL_POLYGON);
    glVertex2i(1620, 680);
    glVertex2i(1500, 680);
    glVertex2i(2000, 290);
    glVertex2i(2000, 400);
    glEnd();

    glColor3f(0.3,0.9,0.1);
    glBegin(GL_POLYGON);
    glVertex2i(1420, 680);
    glVertex2i(1310, 680);
    glVertex2i(1750, 280);
    glVertex2i(1900, 280);
    glEnd();

    glPushMatrix();
    glTranslated(90,640,0);    // Tree
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(-10,-190,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(250,190,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(-120,-300,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(170,160,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(180,140,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(880,0,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(170,-140,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(170,-150,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(110,120,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(-220,170,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(230,0,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glPopMatrix();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);    // tree body
    glVertex2i(80, 600);
    glVertex2i(100,600);
    glVertex2i(100,590);
    glVertex2i(80,590);
    glEnd();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(320, 600);
    glVertex2i(340,600);
    glVertex2i(340,590);
    glVertex2i(320,590);
    glEnd();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(70, 410);
    glVertex2i(90,410);
    glVertex2i(90,400);
    glVertex2i(70,400);
    glEnd();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(550, 600);
    glVertex2i(570,600);
    glVertex2i(570,590);
    glVertex2i(550,590);
    glEnd();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(370, 462);
    glVertex2i(390,462);
    glVertex2i(390,452);
    glVertex2i(370,452);
    glEnd();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(200, 300);
    glVertex2i(220,300);
    glVertex2i(220,290);
    glVertex2i(200,290);
    glEnd();

    glColor3f(0.7,0.4,0.0);  //right
    glBegin(GL_POLYGON);
    glVertex2i(1430, 600);
    glVertex2i(1450,600);
    glVertex2i(1450,590);
    glVertex2i(1430,590);
    glEnd();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1600, 462);
    glVertex2i(1620,462);
    glVertex2i(1620,452);
    glVertex2i(1600,452);
    glEnd();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1770,312);
    glVertex2i(1790,312);
    glVertex2i(1790,302);
    glVertex2i(1770,302);
    glEnd();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1880,432);
    glVertex2i(1900,432);
    glVertex2i(1900,422);
    glVertex2i(1880,422);
    glEnd();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1660,600);
    glVertex2i(1680,600);
    glVertex2i(1680,590);
    glVertex2i(1660,590);
    glEnd();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1890,600);
    glVertex2i(1910,600);
    glVertex2i(1910,590);
    glVertex2i(1890,590);
    glEnd();




    glColor3f(0.3,0.3,0.3);
    glBegin(GL_POLYGON);    // road
    glVertex2i(0, 280);
    glVertex2i(2000,280);
    glVertex2i(2000,0);
    glVertex2i(0,0);
    glEnd();

    glColor3f(1.0,1.0,0.3);
    glBegin(GL_POLYGON);    // road yellow line up
    glVertex2i(0, 280);
    glVertex2i(2000,280);
    glVertex2i(2000,270);
    glVertex2i(0,270);
    glEnd();

    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);    // road yellow line down
    glVertex2i(0, 10);
    glVertex2i(2000,10);
    glVertex2i(2000,0);
    glVertex2i(0,0);
    glEnd();


    glColor3f(1.0,1.0,1.0); //road line middle
    glBegin(GL_LINES);
    glVertex2i(100,140);
    glVertex2i(350,140);
    glVertex2i(550,140);
    glVertex2i(850,140);
    glVertex2i(1050,140);
    glVertex2i(1350,140);
    glVertex2i(1550,140);
    glVertex2i(1850,140);
    glEnd();

    glPushMatrix();                  //car 1st
    glTranslatef(Car1Position,0,0);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.4f, 0.5f);
    glVertex2f(75.0f, 100.0f);
    glVertex2f(415.0f, 100.0f);
    glVertex2f(435.0f, 35.0f);
    glVertex2f(65.0f, 35.0f);
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

    glPushMatrix();                  //car 2nd
    glTranslatef(Car2Position,0,0);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(1925.0f, 230.0f);
    glVertex2f(1585.0f, 230.0f);
    glVertex2f(1565.0f, 170.0f);
    glVertex2f(1935.0f, 170.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(1900,230);
    glVertex2f(1850,280);
    glVertex2f(1650,280);
    glVertex2f(1600,230);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(1880,230);
    glVertex2f(1840,270);
    glVertex2f(1660,270);
    glVertex2f(1620,230);
    glEnd();

    glTranslated(1870,170,0);   //wheels 1
    glColor3f(0.0, 0.0, 0.0);
    circle(25,35,0,0);

    glTranslated(-220,00,0);  //wheels 2
    glColor3f(0.0, 0.0, 0.0);
    circle(25,35,0,0);

    glPopMatrix();




    glPushMatrix();
   // glTranslatef(SkyPosition,0,0);

    glTranslated(1580,1680,0);  //sky
    glColor3f(0.5, 0.6, 0.6);
    circle(50,60,0,0);

    glPopMatrix();

    glPushMatrix();
    //glTranslatef(SkyPosition,0,0);

    glTranslated(1640,1700,0);  //sky
    glColor3f(0.5, 0.6, 0.6);
    circle(50,60,0,0);

    glPopMatrix();

    glPushMatrix();
    //glTranslatef(SkyPosition,0,0);

    glTranslated(1710,1680,0);  //sky
    glColor3f(0.5, 0.6, 0.6);
    circle(50,60,0,0);

    glPopMatrix();

    glPushMatrix();
    //glTranslatef(SkyPosition,0,0);

    glTranslated(1640,1650,0);  //sky
    glColor3f(0.5, 0.6, 0.6);
    circle(50,60,0,0);

    glPopMatrix();

    ////

    glPushMatrix();

    glTranslated(180,1660,0);  //sky
    glColor3f(0.5, 0.6, 0.6);
    circle(50,60,0,0);
    glPopMatrix();


    glPushMatrix();
    glTranslated(240,1680,0);  //sky
    glColor3f(0.5, 0.6, 0.6);
    circle(50,60,0,0);
    glPopMatrix();


    glPushMatrix();
    glTranslated(310,1660,0);  //sky
    glColor3f(0.5, 0.6, 0.6);
    circle(50,60,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(240,1630,0);  //sky
    glColor3f(0.5, 0.6, 0.6);
    circle(50,60,0,0);


    glPopMatrix();
    glTranslatef(RainPosition,RainPosition,0);

    glColor3f(1.0,1.0,1.0);          //rain
    glBegin(GL_LINES);
    glVertex2i(50,1800);
    glVertex2i(45,1750);
    glVertex2i(150,1800);
    glVertex2i(145,1750);
    glVertex2i(250,1800);
    glVertex2i(245,1750);
    glVertex2i(350,1800);
    glVertex2i(345,1750);
    glVertex2i(450,1800);
    glVertex2i(445,1750);
    glVertex2i(550,1800);
    glVertex2i(545,1750);
    glVertex2i(650,1800);
    glVertex2i(645,1750);
    glVertex2i(750,1800);
    glVertex2i(745,1750);
    glVertex2i(850,1800);
    glVertex2i(845,1750);
    glVertex2i(950,1800);
    glVertex2i(945,1750);
    glVertex2i(1050,1800);
    glVertex2i(1045,1750);
    glVertex2i(1150,1800);
    glVertex2i(1145,1750);
    glVertex2i(1250,1800);
    glVertex2i(1245,1750);
    glVertex2i(1350,1800);
    glVertex2i(1345,1750);
    glVertex2i(1450,1800);
    glVertex2i(1445,1750);
    glVertex2i(1550,1800);
    glVertex2i(1545,1750);
    glVertex2i(1650,1800);
    glVertex2i(1645,1750);
    glVertex2i(1750,1800);
    glVertex2i(1745,1750);
    glVertex2i(1850,1800);
    glVertex2i(1845,1750);
    glVertex2i(1950,1800);
    glVertex2i(1945,1750);

    glVertex2i(30,1700);
    glVertex2i(20,1650);
    glVertex2i(130,1700);
    glVertex2i(120,1650);
    glVertex2i(230,1700);
    glVertex2i(220,1650);
    glVertex2i(330,1700);
    glVertex2i(320,1650);
    glVertex2i(430,1700);
    glVertex2i(420,1650);
    glVertex2i(530,1700);
    glVertex2i(520,1650);
    glVertex2i(630,1700);
    glVertex2i(620,1650);
    glVertex2i(730,1700);
    glVertex2i(720,1650);
    glVertex2i(830,1700);
    glVertex2i(820,1650);
    glVertex2i(930,1700);
    glVertex2i(920,1650);
    glVertex2i(1030,1700);
    glVertex2i(1020,1650);
    glVertex2i(1130,1700);
    glVertex2i(1120,1650);
    glVertex2i(1230,1700);
    glVertex2i(1220,1650);
    glVertex2i(1330,1700);
    glVertex2i(1320,1650);
    glVertex2i(1430,1700);
    glVertex2i(1420,1650);
    glVertex2i(1530,1700);
    glVertex2i(1520,1650);
    glVertex2i(1630,1700);
    glVertex2i(1620,1650);
    glVertex2i(1730,1700);
    glVertex2i(1720,1650);
    glVertex2i(1830,1700);
    glVertex2i(1820,1650);
    glVertex2i(1930,1700);
    glVertex2i(1920,1650);

    glVertex2i(30,1600);
    glVertex2i(20,1550);
    glVertex2i(130,1600);
    glVertex2i(120,1550);
    glVertex2i(230,1600);
    glVertex2i(220,1550);
    glVertex2i(330,1600);
    glVertex2i(320,1550);
    glVertex2i(430,1600);
    glVertex2i(420,1550);
    glVertex2i(530,1600);
    glVertex2i(520,1550);
    glVertex2i(630,1600);
    glVertex2i(620,1550);
    glVertex2i(730,1600);
    glVertex2i(720,1550);
    glVertex2i(830,1600);
    glVertex2i(820,1550);
    glVertex2i(930,1600);
    glVertex2i(920,1550);
    glVertex2i(1030,1600);
    glVertex2i(1020,1550);
    glVertex2i(1130,1600);
    glVertex2i(1120,1550);
    glVertex2i(1230,1600);
    glVertex2i(1220,1550);
    glVertex2i(1330,1600);
    glVertex2i(1320,1550);
    glVertex2i(1430,1600);
    glVertex2i(1420,1550);
    glVertex2i(1530,1600);
    glVertex2i(1520,1550);
    glVertex2i(1630,1600);
    glVertex2i(1620,1550);
    glVertex2i(1730,1600);
    glVertex2i(1720,1550);
    glVertex2i(1830,1600);
    glVertex2i(1820,1550);
    glVertex2i(1930,1600);
    glVertex2i(1920,1550);

    glVertex2i(30,1500);
    glVertex2i(20,1450);
    glVertex2i(130,1500);
    glVertex2i(120,1450);
    glVertex2i(230,1500);
    glVertex2i(220,1450);
    glVertex2i(330,1500);
    glVertex2i(320,1450);
    glVertex2i(430,1500);
    glVertex2i(420,1450);
    glVertex2i(530,1500);
    glVertex2i(520,1450);
    glVertex2i(630,1500);
    glVertex2i(620,1450);
    glVertex2i(730,1500);
    glVertex2i(720,1450);
    glVertex2i(830,1500);
    glVertex2i(820,1450);
    glVertex2i(930,1500);
    glVertex2i(920,1450);
    glVertex2i(1030,1500);
    glVertex2i(1020,1450);
    glVertex2i(1130,1500);
    glVertex2i(1120,1450);
    glVertex2i(1230,1500);
    glVertex2i(1220,1450);
    glVertex2i(1330,1500);
    glVertex2i(1320,1450);
    glVertex2i(1430,1500);
    glVertex2i(1420,1450);
    glVertex2i(1530,1500);
    glVertex2i(1520,1450);
    glVertex2i(1630,1500);
    glVertex2i(1620,1450);
    glVertex2i(1730,1500);
    glVertex2i(1720,1450);
    glVertex2i(1830,1500);
    glVertex2i(1820,1450);
    glVertex2i(1930,1500);
    glVertex2i(1920,1450);

    glVertex2i(30,1400);
    glVertex2i(20,1350);
    glVertex2i(130,1400);
    glVertex2i(120,1350);
    glVertex2i(230,1400);
    glVertex2i(220,1350);
    glVertex2i(330,1400);
    glVertex2i(320,1350);
    glVertex2i(430,1400);
    glVertex2i(420,1350);
    glVertex2i(530,1400);
    glVertex2i(520,1350);
    glVertex2i(630,1400);
    glVertex2i(620,1350);
    glVertex2i(730,1400);
    glVertex2i(720,1350);
    glVertex2i(830,1400);
    glVertex2i(820,1350);
    glVertex2i(930,1400);
    glVertex2i(920,1350);
    glVertex2i(1030,1400);
    glVertex2i(1020,1350);
    glVertex2i(1130,1400);
    glVertex2i(1120,1350);
    glVertex2i(1230,1400);
    glVertex2i(1220,1350);
    glVertex2i(1330,1400);
    glVertex2i(1320,1350);
    glVertex2i(1430,1400);
    glVertex2i(1420,1350);
    glVertex2i(1530,1400);
    glVertex2i(1520,1350);
    glVertex2i(1630,1400);
    glVertex2i(1620,1350);
    glVertex2i(1730,1400);
    glVertex2i(1720,1350);
    glVertex2i(1830,1400);
    glVertex2i(1820,1350);
    glVertex2i(1930,1400);
    glVertex2i(1920,1350);

    glVertex2i(30,1300);
    glVertex2i(20,1250);
    glVertex2i(130,1300);
    glVertex2i(120,1250);
    glVertex2i(230,1300);
    glVertex2i(220,1250);
    glVertex2i(330,1300);
    glVertex2i(320,1250);
    glVertex2i(430,1300);
    glVertex2i(420,1250);
    glVertex2i(530,1300);
    glVertex2i(520,1250);
    glVertex2i(630,1300);
    glVertex2i(620,1250);
    glVertex2i(730,1300);
    glVertex2i(720,1250);
    glVertex2i(830,1300);
    glVertex2i(820,1250);
    glVertex2i(930,1300);
    glVertex2i(920,1250);
    glVertex2i(1030,1300);
    glVertex2i(1020,1250);
    glVertex2i(1130,1300);
    glVertex2i(1120,1250);
    glVertex2i(1230,1300);
    glVertex2i(1220,1250);
    glVertex2i(1330,1300);
    glVertex2i(1320,1250);
    glVertex2i(1430,1300);
    glVertex2i(1420,1250);
    glVertex2i(1530,1300);
    glVertex2i(1520,1250);
    glVertex2i(1630,1300);
    glVertex2i(1620,1250);
    glVertex2i(1730,1300);
    glVertex2i(1720,1250);
    glVertex2i(1830,1300);
    glVertex2i(1820,1250);
    glVertex2i(1930,1300);
    glVertex2i(1920,1250);

    glVertex2i(30,1200);
    glVertex2i(20,1150);
    glVertex2i(130,1200);
    glVertex2i(120,1150);
    glVertex2i(230,1200);
    glVertex2i(220,1150);
    glVertex2i(330,1200);
    glVertex2i(320,1150);
    glVertex2i(430,1200);
    glVertex2i(420,1150);
    glVertex2i(530,1200);
    glVertex2i(520,1150);
    glVertex2i(630,1200);
    glVertex2i(620,1150);
    glVertex2i(730,1200);
    glVertex2i(720,1150);
    glVertex2i(830,1200);
    glVertex2i(820,1150);
    glVertex2i(930,1200);
    glVertex2i(920,1150);
    glVertex2i(1030,1200);
    glVertex2i(1020,1150);
    glVertex2i(1130,1200);
    glVertex2i(1120,1150);
    glVertex2i(1230,1200);
    glVertex2i(1220,1150);
    glVertex2i(1330,1200);
    glVertex2i(1320,1150);
    glVertex2i(1430,1200);
    glVertex2i(1420,1150);
    glVertex2i(1530,1200);
    glVertex2i(1520,1150);
    glVertex2i(1630,1200);
    glVertex2i(1620,1150);
    glVertex2i(1730,1200);
    glVertex2i(1720,1150);
    glVertex2i(1830,1200);
    glVertex2i(1820,1150);
    glVertex2i(1930,1200);
    glVertex2i(1920,1150);

    glVertex2i(30,1100);
    glVertex2i(20,1050);
    glVertex2i(130,1100);
    glVertex2i(120,1050);
    glVertex2i(230,1100);
    glVertex2i(220,1050);
    glVertex2i(330,1100);
    glVertex2i(320,1050);
    glVertex2i(430,1100);
    glVertex2i(420,1050);
    glVertex2i(530,1100);
    glVertex2i(520,1050);
    glVertex2i(630,1100);
    glVertex2i(620,1050);
    glVertex2i(730,1100);
    glVertex2i(720,1050);
    glVertex2i(830,1100);
    glVertex2i(820,1050);
    glVertex2i(930,1100);
    glVertex2i(920,1050);
    glVertex2i(1030,1100);
    glVertex2i(1020,1050);
    glVertex2i(1130,1100);
    glVertex2i(1120,1050);
    glVertex2i(1230,1100);
    glVertex2i(1220,1050);
    glVertex2i(1330,1100);
    glVertex2i(1320,1050);
    glVertex2i(1430,1100);
    glVertex2i(1420,1050);
    glVertex2i(1530,1100);
    glVertex2i(1520,1050);
    glVertex2i(1630,1100);
    glVertex2i(1620,1050);
    glVertex2i(1730,1100);
    glVertex2i(1720,1050);
    glVertex2i(1830,1100);
    glVertex2i(1820,1050);
    glVertex2i(1930,1100);
    glVertex2i(1920,1050);

    glVertex2i(30,1000);
    glVertex2i(20,950);
    glVertex2i(130,1000);
    glVertex2i(120,950);
    glVertex2i(230,1000);
    glVertex2i(220,950);
    glVertex2i(330,1000);
    glVertex2i(320,950);
    glVertex2i(430,1000);
    glVertex2i(420,950);
    glVertex2i(530,1000);
    glVertex2i(520,950);
    glVertex2i(630,1000);
    glVertex2i(620,950);
    glVertex2i(730,1000);
    glVertex2i(720,950);
    glVertex2i(830,1000);
    glVertex2i(820,950);
    glVertex2i(930,1000);
    glVertex2i(920,950);
    glVertex2i(1030,1000);
    glVertex2i(1020,950);
    glVertex2i(1130,1000);
    glVertex2i(1120,950);
    glVertex2i(1230,1000);
    glVertex2i(1220,950);
    glVertex2i(1330,1000);
    glVertex2i(1320,950);
    glVertex2i(1430,1000);
    glVertex2i(1420,950);
    glVertex2i(1530,1000);
    glVertex2i(1520,950);
    glVertex2i(1630,1000);
    glVertex2i(1620,950);
    glVertex2i(1730,1000);
    glVertex2i(1720,950);
    glVertex2i(1830,1000);
    glVertex2i(1820,950);
    glVertex2i(1930,1000);
    glVertex2i(1920,950);

    glVertex2i(30,900);
    glVertex2i(20,850);
    glVertex2i(130,900);
    glVertex2i(120,850);
    glVertex2i(230,900);
    glVertex2i(220,850);
    glVertex2i(330,900);
    glVertex2i(320,850);
    glVertex2i(430,900);
    glVertex2i(420,850);
    glVertex2i(530,900);
    glVertex2i(520,850);
    glVertex2i(630,900);
    glVertex2i(620,850);
    glVertex2i(730,900);
    glVertex2i(720,850);
    glVertex2i(830,900);
    glVertex2i(820,850);
    glVertex2i(930,900);
    glVertex2i(920,850);
    glVertex2i(1030,900);
    glVertex2i(1020,850);
    glVertex2i(1130,900);
    glVertex2i(1120,850);
    glVertex2i(1230,900);
    glVertex2i(1220,850);
    glVertex2i(1330,900);
    glVertex2i(1320,850);
    glVertex2i(1430,900);
    glVertex2i(1420,850);
    glVertex2i(1530,900);
    glVertex2i(1520,850);
    glVertex2i(1630,900);
    glVertex2i(1620,850);
    glVertex2i(1730,900);
    glVertex2i(1720,850);
    glVertex2i(1830,900);
    glVertex2i(1820,850);
    glVertex2i(1930,900);
    glVertex2i(1920,850);

    glVertex2i(30,800);
    glVertex2i(20,750);
    glVertex2i(130,800);
    glVertex2i(120,750);
    glVertex2i(230,800);
    glVertex2i(220,750);
    glVertex2i(330,800);
    glVertex2i(320,750);
    glVertex2i(430,800);
    glVertex2i(420,750);
    glVertex2i(530,800);
    glVertex2i(520,750);
    glVertex2i(630,800);
    glVertex2i(620,750);
    glVertex2i(730,800);
    glVertex2i(720,750);
    glVertex2i(830,800);
    glVertex2i(820,750);
    glVertex2i(930,800);
    glVertex2i(920,750);
    glVertex2i(1030,800);
    glVertex2i(1020,750);
    glVertex2i(1130,800);
    glVertex2i(1120,750);
    glVertex2i(1230,800);
    glVertex2i(1220,750);
    glVertex2i(1330,800);
    glVertex2i(1320,750);
    glVertex2i(1430,800);
    glVertex2i(1420,750);
    glVertex2i(1530,800);
    glVertex2i(1520,750);
    glVertex2i(1630,800);
    glVertex2i(1620,750);
    glVertex2i(1730,800);
    glVertex2i(1720,750);
    glVertex2i(1830,800);
    glVertex2i(1820,750);
    glVertex2i(1930,800);
    glVertex2i(1920,750);

    glVertex2i(30,700);
    glVertex2i(20,650);
    glVertex2i(130,700);
    glVertex2i(120,650);
    glVertex2i(230,700);
    glVertex2i(220,650);
    glVertex2i(330,700);
    glVertex2i(320,650);
    glVertex2i(430,700);
    glVertex2i(420,650);
    glVertex2i(530,700);
    glVertex2i(520,650);
    glVertex2i(630,700);
    glVertex2i(620,650);
    glVertex2i(730,700);
    glVertex2i(720,650);
    glVertex2i(830,700);
    glVertex2i(820,650);
    glVertex2i(930,700);
    glVertex2i(920,650);
    glVertex2i(1030,700);
    glVertex2i(1020,650);
    glVertex2i(1130,700);
    glVertex2i(1120,650);
    glVertex2i(1230,700);
    glVertex2i(1220,650);
    glVertex2i(1330,700);
    glVertex2i(1320,650);
    glVertex2i(1430,700);
    glVertex2i(1420,650);
    glVertex2i(1530,700);
    glVertex2i(1520,650);
    glVertex2i(1630,700);
    glVertex2i(1620,650);
    glVertex2i(1730,700);
    glVertex2i(1720,650);
    glVertex2i(1830,700);
    glVertex2i(1820,650);
    glVertex2i(1930,700);
    glVertex2i(1920,650);

    glVertex2i(30,600);
    glVertex2i(20,550);
    glVertex2i(130,600);
    glVertex2i(120,550);
    glVertex2i(230,600);
    glVertex2i(220,550);
    glVertex2i(330,600);
    glVertex2i(320,550);
    glVertex2i(430,600);
    glVertex2i(420,550);
    glVertex2i(530,600);
    glVertex2i(520,550);
    glVertex2i(630,600);
    glVertex2i(620,550);
    glVertex2i(730,600);
    glVertex2i(720,550);
    glVertex2i(830,600);
    glVertex2i(820,550);
    glVertex2i(930,600);
    glVertex2i(920,550);
    glVertex2i(1030,600);
    glVertex2i(1020,550);
    glVertex2i(1130,600);
    glVertex2i(1120,550);
    glVertex2i(1230,600);
    glVertex2i(1220,550);
    glVertex2i(1330,600);
    glVertex2i(1320,550);
    glVertex2i(1430,600);
    glVertex2i(1420,550);
    glVertex2i(1530,600);
    glVertex2i(1520,550);
    glVertex2i(1630,600);
    glVertex2i(1620,550);
    glVertex2i(1730,600);
    glVertex2i(1720,550);
    glVertex2i(1830,600);
    glVertex2i(1820,550);
    glVertex2i(1930,600);
    glVertex2i(1920,550);

    glVertex2i(30,500);
    glVertex2i(20,450);
    glVertex2i(130,500);
    glVertex2i(120,450);
    glVertex2i(230,500);
    glVertex2i(220,450);
    glVertex2i(330,500);
    glVertex2i(320,450);
    glVertex2i(430,500);
    glVertex2i(420,450);
    glVertex2i(530,500);
    glVertex2i(520,450);
    glVertex2i(630,500);
    glVertex2i(620,450);
    glVertex2i(730,500);
    glVertex2i(720,450);
    glVertex2i(830,500);
    glVertex2i(820,450);
    glVertex2i(930,500);
    glVertex2i(920,450);
    glVertex2i(1030,500);
    glVertex2i(1020,450);
    glVertex2i(1130,500);
    glVertex2i(1120,450);
    glVertex2i(1230,500);
    glVertex2i(1220,450);
    glVertex2i(1330,500);
    glVertex2i(1320,450);
    glVertex2i(1430,500);
    glVertex2i(1420,450);
    glVertex2i(1530,500);
    glVertex2i(1520,450);
    glVertex2i(1630,500);
    glVertex2i(1620,450);
    glVertex2i(1730,500);
    glVertex2i(1720,450);
    glVertex2i(1830,500);
    glVertex2i(1820,450);
    glVertex2i(1930,500);
    glVertex2i(1920,450);

    glVertex2i(30,400);
    glVertex2i(20,350);
    glVertex2i(130,400);
    glVertex2i(120,350);
    glVertex2i(230,400);
    glVertex2i(220,350);
    glVertex2i(330,400);
    glVertex2i(320,350);
    glVertex2i(430,400);
    glVertex2i(420,350);
    glVertex2i(530,400);
    glVertex2i(520,350);
    glVertex2i(630,400);
    glVertex2i(620,350);
    glVertex2i(730,400);
    glVertex2i(720,350);
    glVertex2i(830,400);
    glVertex2i(820,350);
    glVertex2i(930,400);
    glVertex2i(920,350);
    glVertex2i(1030,400);
    glVertex2i(1020,350);
    glVertex2i(1130,400);
    glVertex2i(1120,350);
    glVertex2i(1230,400);
    glVertex2i(1220,350);
    glVertex2i(1330,400);
    glVertex2i(1320,350);
    glVertex2i(1430,400);
    glVertex2i(1420,350);
    glVertex2i(1530,400);
    glVertex2i(1520,350);
    glVertex2i(1630,400);
    glVertex2i(1620,350);
    glVertex2i(1730,400);
    glVertex2i(1720,350);
    glVertex2i(1830,400);
    glVertex2i(1820,350);
    glVertex2i(1930,400);
    glVertex2i(1920,350);

    glVertex2i(30,300);
    glVertex2i(20,250);
    glVertex2i(130,300);
    glVertex2i(120,250);
    glVertex2i(230,300);
    glVertex2i(220,250);
    glVertex2i(330,300);
    glVertex2i(320,250);
    glVertex2i(430,300);
    glVertex2i(420,250);
    glVertex2i(530,300);
    glVertex2i(520,250);
    glVertex2i(630,300);
    glVertex2i(620,250);
    glVertex2i(730,300);
    glVertex2i(720,250);
    glVertex2i(830,300);
    glVertex2i(820,250);
    glVertex2i(930,300);
    glVertex2i(920,250);
    glVertex2i(1030,300);
    glVertex2i(1020,250);
    glVertex2i(1130,300);
    glVertex2i(1120,250);
    glVertex2i(1230,300);
    glVertex2i(1220,250);
    glVertex2i(1330,300);
    glVertex2i(1320,250);
    glVertex2i(1430,300);
    glVertex2i(1420,250);
    glVertex2i(1530,300);
    glVertex2i(1520,250);
    glVertex2i(1630,300);
    glVertex2i(1620,250);
    glVertex2i(1730,300);
    glVertex2i(1720,250);
    glVertex2i(1830,300);
    glVertex2i(1820,250);
    glVertex2i(1930,300);
    glVertex2i(1920,250);

    glVertex2i(30,200);
    glVertex2i(20,150);
    glVertex2i(130,200);
    glVertex2i(120,150);
    glVertex2i(230,200);
    glVertex2i(220,150);
    glVertex2i(330,200);
    glVertex2i(320,150);
    glVertex2i(430,200);
    glVertex2i(420,150);
    glVertex2i(530,200);
    glVertex2i(520,150);
    glVertex2i(630,200);
    glVertex2i(620,150);
    glVertex2i(730,200);
    glVertex2i(720,150);
    glVertex2i(830,200);
    glVertex2i(820,150);
    glVertex2i(930,200);
    glVertex2i(920,150);
    glVertex2i(1030,200);
    glVertex2i(1020,150);
    glVertex2i(1130,200);
    glVertex2i(1120,150);
    glVertex2i(1230,200);
    glVertex2i(1220,150);
    glVertex2i(1330,200);
    glVertex2i(1320,150);
    glVertex2i(1430,200);
    glVertex2i(1420,150);
    glVertex2i(1530,200);
    glVertex2i(1520,150);
    glVertex2i(1630,200);
    glVertex2i(1620,150);
    glVertex2i(1730,200);
    glVertex2i(1720,150);
    glVertex2i(1830,200);
    glVertex2i(1820,150);
    glVertex2i(1930,200);
    glVertex2i(1920,150);

    glVertex2i(30,100);
    glVertex2i(20,50);
    glVertex2i(130,100);
    glVertex2i(120,50);
    glVertex2i(230,100);
    glVertex2i(220,50);
    glVertex2i(330,100);
    glVertex2i(320,50);
    glVertex2i(430,100);
    glVertex2i(420,50);
    glVertex2i(530,100);
    glVertex2i(520,50);
    glVertex2i(630,100);
    glVertex2i(620,50);
    glVertex2i(730,100);
    glVertex2i(720,50);
    glVertex2i(830,100);
    glVertex2i(820,50);
    glVertex2i(930,100);
    glVertex2i(920,50);
    glVertex2i(1030,100);
    glVertex2i(1020,50);
    glVertex2i(1130,100);
    glVertex2i(1120,50);
    glVertex2i(1230,100);
    glVertex2i(1220,50);
    glVertex2i(1330,100);
    glVertex2i(1320,50);
    glVertex2i(1430,100);
    glVertex2i(1420,50);
    glVertex2i(1530,100);
    glVertex2i(1520,50);
    glVertex2i(1630,100);
    glVertex2i(1620,50);
    glVertex2i(1730,100);
    glVertex2i(1720,50);
    glVertex2i(1830,100);
    glVertex2i(1820,50);
    glVertex2i(1930,100);
    glVertex2i(1920,50);

    glEnd();

    glPopMatrix();

	glFlush();
	glutPostRedisplay();
}

void night()
{
    glClearColor(0.0,0.0,0.2,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluOrtho2D(0.0, 2000, 0.0, 1800);

	moon();


	glColor3f(1.0,1.0,0.9);  // basic shape
    glBegin(GL_POLYGON);
    glVertex2i(0, 1100);
    glVertex2i(2000, 1100);
    glVertex2i(2000, 780);
    glVertex2i(0, 780);
    glEnd();

    glColor3f(1.0,1.0,0.9);  // upper square shape
    glBegin(GL_POLYGON);
    glVertex2i(750, 1500);
    glVertex2i(1250, 1500);
    glVertex2i(1250, 1100);
    glVertex2i(750, 1100);
    glEnd();

    glColor3f(0.0,0.0,0.0); //upper 3 line
    glBegin(GL_POLYGON);
    glVertex2i(750, 1440);
    glVertex2i(1250, 1440);
    glVertex2i(1250, 1430);
    glVertex2i(750, 1430);
    glEnd();

    clock();

    glPushMatrix();
    glTranslatef(1000.0,1285,0.0);
    glRotatef(x,0.0,0.0,1.0);

    glColor3f(0,0,1); //second
    glBegin(GL_LINES);
    glVertex2i(0,0);
    glVertex2i(55,45);
    glEnd();

    glPopMatrix();

    x-=0.01f;

    glPushMatrix();
    glTranslatef(1000.0,1285.0,0.0);
    glRotatef(y,0.0,0.0,1.0);

    glColor3f(0,1,0);    //minutes
    glBegin(GL_LINES);
    glVertex2i(0,0);
    glVertex2i(45,25);
    glEnd();

    glPopMatrix();

    y-=0.0007f;

    glPushMatrix();
    glTranslatef(1000.0,1285.0,0.0);
    glRotatef(z,0.0,0.0,1.0);

    glColor3f(1,0,0);  //hour
    glBegin(GL_LINES);
    glVertex2i(0,0);
    glVertex2i(35,15);
    glEnd();

    glPopMatrix();

    z-=0.0002f;

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(750, 1410);
    glVertex2i(1250, 1410);
    glVertex2i(1250, 1400);
    glVertex2i(750, 1400);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(750, 1380);
    glVertex2i(1250, 1380);
    glVertex2i(1250, 1370);
    glVertex2i(750, 1370);
    glEnd();

    // front door design

    glColor3f(0.6,0.6,0.6);
    glBegin(GL_LINES);
    glVertex2i(860,1200);
    glVertex2i(860,950);

    glVertex2i(860,1200);
    glVertex2i(1140,1200);

    glVertex2i(1140,1200);
    glVertex2i(1140,950);


    glEnd();

    glColor3f(0.0,0.0,0.0);  //middle door
    glBegin(GL_POLYGON);
    glVertex2i(960, 1130);
    glVertex2i(1040, 1130);
    glVertex2i(1040, 880);
    glVertex2i(960, 880);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(940, 1030);
    glVertex2i(960, 1030);
    glVertex2i(960, 880);
    glVertex2i(940, 880);
    glEnd();

    glColor3f(1.0,1.0,1.0);  //white column
    glBegin(GL_POLYGON);
    glVertex2i(948, 1030);
    glVertex2i(953, 1030);
    glVertex2i(953, 880);
    glVertex2i(948, 880);
    glEnd();


    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(880, 1060);
    glVertex2i(940, 1060);
    glVertex2i(940, 880);
    glVertex2i(880, 880);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1040, 1030);
    glVertex2i(1060, 1030);
    glVertex2i(1060, 880);
    glVertex2i(1040, 880);
    glEnd();

    glColor3f(1.0,1.0,1.0);  //white column
    glBegin(GL_POLYGON);
    glVertex2i(1048, 1030);
    glVertex2i(1053, 1030);
    glVertex2i(1053, 880);
    glVertex2i(1048, 880);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1060, 1060);
    glVertex2i(1120, 1060);
    glVertex2i(1120, 880);
    glVertex2i(1060, 880);
    glEnd();

    glPushMatrix();

    glTranslated(910,1060,0);  // door round shape
    glColor3f(0.0, 0.0, 0.0);
    circle(30,35,0,0);

    glTranslated(180,0,0);  // door round shape
    glColor3f(0.0, 0.0, 0.0);
    circle(30,35,0,0);

    glTranslated(-90,80,0);  // door round shape
    glColor3f(0.0, 0.0, 0.0);
    circle(40,45,0,0);

    glPopMatrix();


    glColor3f(0.3,0.2,0.1);  // ground
    glBegin(GL_POLYGON);
    glVertex2i(0, 780);
    glVertex2i(2000, 780);
    glVertex2i(2000, 0);
    glVertex2i(0,0);
    glEnd();

    glColor3f(0.6,0.9,0.9);  // aquarium white water
    glBegin(GL_POLYGON);
    glVertex2i(800, 600);
    glVertex2i(1200, 600);
    glVertex2i(1400, 400);
    glVertex2i(600,400);
    glEnd();

    glColor3f(0.3,0.5,0.7);  // aquarium blue water
    glBegin(GL_POLYGON);
    glVertex2i(800, 550);
    glVertex2i(1200, 550);
    glVertex2i(1350, 400);
    glVertex2i(650,400);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2i(800,600);
    glVertex2i(1200,600);

    glVertex2i(1400,400);
    glVertex2i(600,400);

    glVertex2i(800,600);
    glVertex2i(600,400);

    glVertex2i(1200,600);
    glVertex2i(1400,400);
    glEnd();

    glColor3f(0.9,0.9,1.0);  // aquarium light
    glBegin(GL_POLYGON);
    glVertex2i(980,700);
    glVertex2i(995,700);
    glVertex2i(995,600);
    glVertex2i(980,600);
    glEnd();

    glColor3f(0.9,0.9,1.0);
    glBegin(GL_POLYGON);
    glVertex2i(995,700);
    glVertex2i(1030,700);
    glVertex2i(1030,690);
    glVertex2i(995,690);
    glEnd();

    glColor3f(0.9,0.9,1.0); // triangles
    glBegin(GL_TRIANGLES);
    glVertex2i(1030, 700);
    glVertex2i(1060, 670);
    glVertex2i(1000, 670);
    glEnd();


    glColor3f(0.9,0.9,1.0);
    glBegin(GL_POLYGON);
    glVertex2i(710,660);
    glVertex2i(725,660);
    glVertex2i(725,520);
    glVertex2i(710,505);
    glEnd();

    glColor3f(0.9,0.9,1.0);
    glBegin(GL_POLYGON);
    glVertex2i(725,660);
    glVertex2i(770,660);
    glVertex2i(770,650);
    glVertex2i(725,650);
    glEnd();

    glColor3f(0.9,0.9,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(770, 660);
    glVertex2i(800, 630);
    glVertex2i(740, 630);
    glEnd();



    glColor3f(0.9,0.9,1.0);
    glBegin(GL_POLYGON);
    glVertex2i(960,530);
    glVertex2i(975,530);
    glVertex2i(975,400);
    glVertex2i(960,400);
    glEnd();

    glColor3f(0.9,0.9,1.0);
    glBegin(GL_POLYGON);
    glVertex2i(975,530);
    glVertex2i(1015,530);
    glVertex2i(1015,520);
    glVertex2i(975,520);
    glEnd();

    glColor3f(0.9,0.9,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(1015, 530);
    glVertex2i(1045, 500);
    glVertex2i(985, 500);
    glEnd();

    glColor3f(0.9,0.9,1.0);
    glBegin(GL_POLYGON);
    glVertex2i(1280,650);
    glVertex2i(1295,650);
    glVertex2i(1295,505);
    glVertex2i(1280,515);
    glEnd();

    glColor3f(0.9,0.9,1.0);
    glBegin(GL_POLYGON);
    glVertex2i(1235,640);
    glVertex2i(1280,640);
    glVertex2i(1280,650);
    glVertex2i(1235,650);
    glEnd();

    glColor3f(0.9,0.9,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(1235, 650);
    glVertex2i(1265, 620);
    glVertex2i(1205, 620);
    glEnd();

    glEnable(GL_LIGHTING);
    GLfloat global_ambient[] = {6.0,6.0,0.0,};//ambient RGBA intensity of light
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);//A lighting model parameter.


    glColor3f(1.0,1.0,0.0); // yellow light
    glBegin(GL_TRIANGLES);
    glVertex2i(1030,670);
    glVertex2i(1070,580);
    glVertex2i(990, 580);
    glEnd();

    glColor3f(1.0,1.0,0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(770, 630);
    glVertex2i(810, 550);
    glVertex2i(730, 550);
    glEnd();

    glColor3f(1.0,1.0,0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(1015, 500);
    glVertex2i(1055, 410);
    glVertex2i(975, 410);
    glEnd();

    glColor3f(1.0,1.0,0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(1235, 620);
    glVertex2i(1275, 530);
    glVertex2i(1195, 530);
    glEnd();

    glDisable(GL_LIGHTING);


    //middle to right

    glColor3f(0.0,0.0,0.0);  // mosque upper window
    glBegin(GL_POLYGON);
    glVertex2i(1165, 1065);
    glVertex2i(1185, 1065);
    glVertex2i(1185, 970);
    glVertex2i(1165, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1195, 1065);
    glVertex2i(1215, 1065);
    glVertex2i(1215, 970);
    glVertex2i(1195, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0); // triangles
    glBegin(GL_TRIANGLES);
    glVertex2i(1170, 1070);
    glVertex2i(1190, 1100);
    glVertex2i(1210, 1070);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1240, 1050);
    glVertex2i(1260, 1050);
    glVertex2i(1260, 970);
    glVertex2i(1240, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1280, 1050);
    glVertex2i(1300, 1050);
    glVertex2i(1300, 970);
    glVertex2i(1280, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1320, 1050);
    glVertex2i(1340, 1050);
    glVertex2i(1340, 970);
    glVertex2i(1320, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1360, 1050);
    glVertex2i(1380, 1050);
    glVertex2i(1380, 970);
    glVertex2i(1360, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1400, 1050);
    glVertex2i(1420, 1050);
    glVertex2i(1420, 970);
    glVertex2i(1400, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1440, 1050);
    glVertex2i(1460, 1050);
    glVertex2i(1460, 970);
    glVertex2i(1440, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1480, 1050);
    glVertex2i(1500, 1050);
    glVertex2i(1500, 970);
    glVertex2i(1480, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1520, 1050);
    glVertex2i(1540, 1050);
    glVertex2i(1540, 970);
    glVertex2i(1520, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1560, 1050);
    glVertex2i(1580, 1050);
    glVertex2i(1580, 970);
    glVertex2i(1560, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1600, 1050);
    glVertex2i(1620, 1050);
    glVertex2i(1620, 970);
    glVertex2i(1600, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1640, 1050);
    glVertex2i(1660, 1050);
    glVertex2i(1660, 970);
    glVertex2i(1640, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1680, 1050);
    glVertex2i(1700, 1050);
    glVertex2i(1700, 970);
    glVertex2i(1680, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1720, 1050);
    glVertex2i(1740, 1050);
    glVertex2i(1740, 970);
    glVertex2i(1720, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1760, 1050);
    glVertex2i(1780, 1050);
    glVertex2i(1780, 970);
    glVertex2i(1760, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1800, 1050);
    glVertex2i(1820, 1050);
    glVertex2i(1820, 970);
    glVertex2i(1800, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1840, 1050);
    glVertex2i(1860, 1050);
    glVertex2i(1860, 970);
    glVertex2i(1840, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1880, 1050);
    glVertex2i(1900, 1050);
    glVertex2i(1900, 970);
    glVertex2i(1880, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1920, 1050);
    glVertex2i(1940, 1050);
    glVertex2i(1940, 970);
    glVertex2i(1920, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1960, 1050);
    glVertex2i(1980, 1050);
    glVertex2i(1980, 970);
    glVertex2i(1960, 970);
    glEnd();


    // middle to left

    glColor3f(0.0,0.0,0.0);  // mosque upper widow
    glBegin(GL_POLYGON);
    glVertex2i(815, 1065);
    glVertex2i(835, 1065);
    glVertex2i(835, 970);
    glVertex2i(815, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(785, 1065);
    glVertex2i(805, 1065);
    glVertex2i(805, 970);
    glVertex2i(785, 970);
    glEnd();


    glColor3f(0.0,0.0,0.0); // triangles
    glBegin(GL_TRIANGLES);
    glVertex2i(790, 1070);
    glVertex2i(810, 1100);
    glVertex2i(830, 1070);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(760, 1050);
    glVertex2i(740, 1050);
    glVertex2i(740, 970);
    glVertex2i(760, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(720, 1050);
    glVertex2i(700, 1050);
    glVertex2i(700, 970);
    glVertex2i(720, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(680, 1050);
    glVertex2i(660, 1050);
    glVertex2i(660, 970);
    glVertex2i(680, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(640, 1050);
    glVertex2i(620, 1050);
    glVertex2i(620, 970);
    glVertex2i(640, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(600, 1050);
    glVertex2i(580, 1050);
    glVertex2i(580, 970);
    glVertex2i(600, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(560, 1050);
    glVertex2i(540, 1050);
    glVertex2i(540, 970);
    glVertex2i(560, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(520, 1050);
    glVertex2i(500, 1050);
    glVertex2i(500, 970);
    glVertex2i(520, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(480, 1050);
    glVertex2i(460, 1050);
    glVertex2i(460, 970);
    glVertex2i(480, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(440, 1050);
    glVertex2i(420, 1050);
    glVertex2i(420, 970);
    glVertex2i(440, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(400, 1050);
    glVertex2i(380, 1050);
    glVertex2i(380, 970);
    glVertex2i(400, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(360, 1050);
    glVertex2i(340, 1050);
    glVertex2i(340, 970);
    glVertex2i(360, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(320, 1050);
    glVertex2i(300, 1050);
    glVertex2i(300, 970);
    glVertex2i(320, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(280, 1050);
    glVertex2i(260, 1050);
    glVertex2i(260, 970);
    glVertex2i(280, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(240, 1050);
    glVertex2i(220, 1050);
    glVertex2i(220, 970);
    glVertex2i(240, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(200, 1050);
    glVertex2i(180, 1050);
    glVertex2i(180, 970);
    glVertex2i(200, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(160, 1050);
    glVertex2i(140, 1050);
    glVertex2i(140, 970);
    glVertex2i(160, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(120, 1050);
    glVertex2i(100, 1050);
    glVertex2i(100, 970);
    glVertex2i(120, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(80, 1050);
    glVertex2i(60, 1050);
    glVertex2i(60, 970);
    glVertex2i(80, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(40, 1050);
    glVertex2i(20, 1050);
    glVertex2i(20, 970);
    glVertex2i(40, 970);
    glEnd();


    //stairs design

    glColor3f(0.5,0.6,0.6);
    glBegin(GL_POLYGON);
    glVertex2i(845, 950);     // ash color
    glVertex2i(1155, 950);
    glVertex2i(1080, 910);
    glVertex2i(920, 910);
    glEnd();

    glColor3f(0.6,0.6,0.5); // middle stairs
    glBegin(GL_POLYGON);
    glVertex2i(920, 910);
    glVertex2i(1080, 910);
    glVertex2i(1200, 710);
    glVertex2i(800, 710);
    glEnd();


    glColor3f(0.6,0.6,0.5);  // left stairs
    glBegin(GL_POLYGON);
    glVertex2i(845, 950);
    glVertex2i(920, 910);
    glVertex2i(800, 710);
    glVertex2i(700, 740);
    glEnd();

    glColor3f(0.6,0.6,0.5);  // right stairs
    glBegin(GL_POLYGON);
    glVertex2i(1080, 910);
    glVertex2i(1155, 950);
    glVertex2i(1300, 740);
    glVertex2i(1200, 710);
    glEnd();



    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);

    glVertex2i(904,880);
    glVertex2i(1098,880);

    glVertex2i(904,880);
    glVertex2i(820,920);

    glVertex2i(1098,880);
    glVertex2i(1175,920);

    glVertex2i(883,850);
    glVertex2i(1117,850);

    glVertex2i(883,850);
    glVertex2i(800,888);

    glVertex2i(1117,850);
    glVertex2i(1198,893);

    glVertex2i(865,820);
    glVertex2i(1137,820);

    glVertex2i(865,820);
    glVertex2i(778,860);

    glVertex2i(1137,820);
    glVertex2i(1213,863);

    glVertex2i(850,790);
    glVertex2i(1153,790);

    glVertex2i(850,790);
    glVertex2i(758,832);

    glVertex2i(1153,790);
    glVertex2i(1235,838);

    glVertex2i(830,760);
    glVertex2i(1170,760);

    glVertex2i(830,760);
    glVertex2i(737,800);

    glVertex2i(1170,760);
    glVertex2i(1250,808);

    glVertex2i(810,730);
    glVertex2i(1190,730);

    glVertex2i(810,730);
    glVertex2i(717,767);

    glVertex2i(1190,730);
    glVertex2i(1280,773);



    /////


    glVertex2i(800,710);
    glVertex2i(1200,710);

    glVertex2i(1200,710);
    glVertex2i(1300,740);

    glVertex2i(1300,740);
    glVertex2i(1155,950);

    glVertex2i(800,710);
    glVertex2i(700,740);

    glVertex2i(700,740);
    glVertex2i(845,950);
    glEnd();

    glColor3f(1.0,1.0,0.9);  // Lower side wall right
    glBegin(GL_TRIANGLES);
    glVertex2i(1280, 780);
    glVertex2i(2000, 780);
    glVertex2i(2000, 720);
    glEnd();

    glColor3f(1.0,1.0,0.9);  // Lower side wall Left
    glBegin(GL_TRIANGLES);
    glVertex2i(0, 780);
    glVertex2i(728,780);
    glVertex2i(0, 720);
    glEnd();

    //lower window left

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(705, 930);
    glVertex2i(745, 930);
    glVertex2i(745, 810);
    glVertex2i(705, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(655, 930);
    glVertex2i(695, 930);
    glVertex2i(695, 810);
    glVertex2i(655, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(605, 930);
    glVertex2i(645, 930);
    glVertex2i(645, 810);
    glVertex2i(605, 810);
    glEnd();

    //lower window right

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1250, 930);
    glVertex2i(1290, 930);
    glVertex2i(1290, 810);
    glVertex2i(1250, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1300, 930);
    glVertex2i(1340, 930);
    glVertex2i(1340, 810);
    glVertex2i(1300, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1350, 930);
    glVertex2i(1390, 930);
    glVertex2i(1390, 810);
    glVertex2i(1350, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0); //right side wide window
    glBegin(GL_POLYGON);
    glVertex2i(1420, 880);
    glVertex2i(1510, 880);
    glVertex2i(1510, 810);
    glVertex2i(1420, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1540, 880);
    glVertex2i(1630, 880);
    glVertex2i(1630, 810);
    glVertex2i(1540, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1660, 880);
    glVertex2i(1750, 880);
    glVertex2i(1750, 810);
    glVertex2i(1660, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1780, 880);
    glVertex2i(1870, 880);
    glVertex2i(1870, 810);
    glVertex2i(1780, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1900, 880);
    glVertex2i(1990, 880);
    glVertex2i(1990, 810);
    glVertex2i(1900, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);//left side wide window
    glBegin(GL_POLYGON);
    glVertex2i(485, 880);
    glVertex2i(575, 880);
    glVertex2i(575, 810);
    glVertex2i(485, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(365, 880);
    glVertex2i(455, 880);
    glVertex2i(455, 810);
    glVertex2i(365, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(245, 880);
    glVertex2i(335, 880);
    glVertex2i(335, 810);
    glVertex2i(245, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(125, 880);
    glVertex2i(215, 880);
    glVertex2i(215, 810);
    glVertex2i(125, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(5, 880);
    glVertex2i(95, 880);
    glVertex2i(95, 810);
    glVertex2i(5, 810);
    glEnd();

    glPushMatrix();
    glTranslated(50,880,0);  //window top shape left to right
    glColor3f(0.0, 0.0, 0.0);
    circle(45,50,0,0);

    glTranslated(120,0,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(45,50,0,0);

    glTranslated(120,0,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(45,50,0,0);

    glTranslated(120,0,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(45,50,0,0);

    glTranslated(120,0,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(45,50,0,0);

    glTranslated(935,0,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(45,50,0,0);

    glTranslated(120,0,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(45,50,0,0);

    glTranslated(120,0,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(45,50,0,0);

    glTranslated(120,0,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(45,50,0,0);

    glTranslated(120,0,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(45,50,0,0);

    glPopMatrix();

    glColor3f(0.0,0.4,0.0); // Field
    glBegin(GL_POLYGON);
    glVertex2i(0, 680);
    glVertex2i(720, 680);
    glVertex2i(360, 280);
    glVertex2i(0, 280);
    glEnd();

    glColor3f(0.0,0.4,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1280, 680);
    glVertex2i(2000, 680);
    glVertex2i(2000, 280);
    glVertex2i(1640, 280);
    glEnd();

    glColor3f(0.3,0.8,0.0); // Field left
    glBegin(GL_POLYGON);
    glVertex2i(150, 680);
    glVertex2i(290, 680);
    glVertex2i(0, 490);
    glVertex2i(0, 590);
    glEnd();

    glColor3f(0.3,0.8,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(380, 680);
    glVertex2i(500, 680);
    glVertex2i(0, 290);
    glVertex2i(0, 400);
    glEnd();

    glColor3f(0.3,0.8,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(580, 680);
    glVertex2i(690, 680);
    glVertex2i(250, 280);
    glVertex2i(100, 280);
    glEnd();

    glColor3f(0.3,0.8,0.0); // Field right
    glBegin(GL_POLYGON);
    glVertex2i(1850, 680);
    glVertex2i(1710, 680);
    glVertex2i(2000, 490);
    glVertex2i(2000, 590);
    glEnd();

    glColor3f(0.3,0.8,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1620, 680);
    glVertex2i(1500, 680);
    glVertex2i(2000, 290);
    glVertex2i(2000, 400);
    glEnd();

    glColor3f(0.3,0.8,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1420, 680);
    glVertex2i(1310, 680);
    glVertex2i(1750, 280);
    glVertex2i(1900, 280);
    glEnd();

    glPushMatrix();
    glTranslated(90,640,0);    // Tree
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(-10,-190,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(250,190,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(-120,-300,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(170,160,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(180,140,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(880,0,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(170,-140,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(170,-150,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(110,120,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(-220,170,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(230,0,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glPopMatrix();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);    // tree body
    glVertex2i(80, 600);
    glVertex2i(100,600);
    glVertex2i(100,590);
    glVertex2i(80,590);
    glEnd();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(320, 600);
    glVertex2i(340,600);
    glVertex2i(340,590);
    glVertex2i(320,590);
    glEnd();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(70, 410);
    glVertex2i(90,410);
    glVertex2i(90,400);
    glVertex2i(70,400);
    glEnd();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(550, 600);
    glVertex2i(570,600);
    glVertex2i(570,590);
    glVertex2i(550,590);
    glEnd();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(370, 462);
    glVertex2i(390,462);
    glVertex2i(390,452);
    glVertex2i(370,452);
    glEnd();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(200, 300);
    glVertex2i(220,300);
    glVertex2i(220,290);
    glVertex2i(200,290);
    glEnd();

    glColor3f(0.7,0.4,0.0);  //right
    glBegin(GL_POLYGON);
    glVertex2i(1430, 600);
    glVertex2i(1450,600);
    glVertex2i(1450,590);
    glVertex2i(1430,590);
    glEnd();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1600, 462);
    glVertex2i(1620,462);
    glVertex2i(1620,452);
    glVertex2i(1600,452);
    glEnd();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1770,312);
    glVertex2i(1790,312);
    glVertex2i(1790,302);
    glVertex2i(1770,302);
    glEnd();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1880,432);
    glVertex2i(1900,432);
    glVertex2i(1900,422);
    glVertex2i(1880,422);
    glEnd();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1660,600);
    glVertex2i(1680,600);
    glVertex2i(1680,590);
    glVertex2i(1660,590);
    glEnd();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1890,600);
    glVertex2i(1910,600);
    glVertex2i(1910,590);
    glVertex2i(1890,590);
    glEnd();




    glColor3f(0.3,0.3,0.3);
    glBegin(GL_POLYGON);    // road
    glVertex2i(0, 280);
    glVertex2i(2000,280);
    glVertex2i(2000,0);
    glVertex2i(0,0);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);    // road white line up
    glVertex2i(0, 280);
    glVertex2i(2000,280);
    glVertex2i(2000,270);
    glVertex2i(0,270);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);    // road white line down
    glVertex2i(0, 10);
    glVertex2i(2000,10);
    glVertex2i(2000,0);
    glVertex2i(0,0);
    glEnd();


    glColor3f(1.0,1.0,1.0); //road line middle
    glBegin(GL_LINES);
    glVertex2i(100,140);
    glVertex2i(350,140);
    glVertex2i(550,140);
    glVertex2i(850,140);
    glVertex2i(1050,140);
    glVertex2i(1350,140);
    glVertex2i(1550,140);
    glVertex2i(1850,140);
    glEnd();

    glPushMatrix();                  //car
    glTranslatef(Car1Position,0,0);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.4f, 0.5f);
    glVertex2f(75.0f, 100.0f);
    glVertex2f(415.0f, 100.0f);
    glVertex2f(435.0f, 35.0f);
    glVertex2f(65.0f, 35.0f);
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

    glPushMatrix();                  //car 2nd
    glTranslatef(Car2Position,0,0);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(1925.0f, 230.0f);
    glVertex2f(1585.0f, 230.0f);
    glVertex2f(1565.0f, 170.0f);
    glVertex2f(1935.0f, 170.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(1900,230);
    glVertex2f(1850,280);
    glVertex2f(1650,280);
    glVertex2f(1600,230);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(1880,230);
    glVertex2f(1840,270);
    glVertex2f(1660,270);
    glVertex2f(1620,230);
    glEnd();

    glTranslated(1870,170,0);   //wheels 1
    glColor3f(0.0, 0.0, 0.0);
    circle(25,35,0,0);

    glTranslated(-220,00,0);  //wheels 2
    glColor3f(0.0, 0.0, 0.0);
    circle(25,35,0,0);

    glPopMatrix();

	glFlush();
	glutPostRedisplay();
}


void day()
{

    glClearColor(0.5f,0.9f,0.9f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT);  // Clear display window
	glLoadIdentity();
	gluOrtho2D(0.0, 2000, 0.0, 1800);

	sun();

    glColor3f(1.0,1.0,1.0);  // basic shape
    glBegin(GL_POLYGON);
    glVertex2i(0, 1100);
    glVertex2i(2000, 1100);
    glVertex2i(2000, 780);
    glVertex2i(0, 780);
    glEnd();

    glColor3f(1.0,1.0,1.0);  // upper square shape
    glBegin(GL_POLYGON);
    glVertex2i(750, 1500);
    glVertex2i(1250, 1500);
    glVertex2i(1250, 1100);
    glVertex2i(750, 1100);
    glEnd();

    glColor3f(0.0,0.0,0.0); //upper 3 line
    glBegin(GL_POLYGON);
    glVertex2i(750, 1440);
    glVertex2i(1250, 1440);
    glVertex2i(1250, 1430);
    glVertex2i(750, 1430);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(750, 1410);
    glVertex2i(1250, 1410);
    glVertex2i(1250, 1400);
    glVertex2i(750, 1400);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(750, 1380);
    glVertex2i(1250, 1380);
    glVertex2i(1250, 1370);
    glVertex2i(750, 1370);
    glEnd();

    clock();

    glPushMatrix();
    glTranslatef(1000.0,1285,0.0);
    glRotatef(x,0.0,0.0,1.0);

    glColor3f(0,0,1); //second
    glBegin(GL_LINES);
    glVertex2i(0,0);
    glVertex2i(55,45);
    glEnd();

    glPopMatrix();

    x-=0.01f;

    glPushMatrix();
    glTranslatef(1000.0,1285.0,0.0);
    glRotatef(y,0.0,0.0,1.0);

    glColor3f(0,1,0);    //minutes
    glBegin(GL_LINES);
    glVertex2i(0,0);
    glVertex2i(45,25);
    glEnd();

    glPopMatrix();

    y-=0.0007f;

    glPushMatrix();
    glTranslatef(1000.0,1285.0,0.0);
    glRotatef(z,0.0,0.0,1.0);

    glColor3f(1,0,0);  //hour
    glBegin(GL_LINES);
    glVertex2i(0,0);
    glVertex2i(35,15);
    glEnd();

    glPopMatrix();

    z-=0.0002f;

    // front door design

    glColor3f(0.6,0.6,0.6);
    glBegin(GL_LINES);
    glVertex2i(860,1200);
    glVertex2i(860,950);

    glVertex2i(860,1200);
    glVertex2i(1140,1200);

    glVertex2i(1140,1200);
    glVertex2i(1140,950);


    glEnd();

    glColor3f(0.0,0.0,0.0);  //middle door
    glBegin(GL_POLYGON);
    glVertex2i(960, 1130);
    glVertex2i(1040, 1130);
    glVertex2i(1040, 880);
    glVertex2i(960, 880);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(940, 1030);
    glVertex2i(960, 1030);
    glVertex2i(960, 880);
    glVertex2i(940, 880);
    glEnd();

    glColor3f(1.0,1.0,1.0);  //white column
    glBegin(GL_POLYGON);
    glVertex2i(948, 1030);
    glVertex2i(953, 1030);
    glVertex2i(953, 880);
    glVertex2i(948, 880);
    glEnd();


    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(880, 1060);
    glVertex2i(940, 1060);
    glVertex2i(940, 880);
    glVertex2i(880, 880);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1040, 1030);
    glVertex2i(1060, 1030);
    glVertex2i(1060, 880);
    glVertex2i(1040, 880);
    glEnd();

    glColor3f(1.0,1.0,1.0);  //white column
    glBegin(GL_POLYGON);
    glVertex2i(1048, 1030);
    glVertex2i(1053, 1030);
    glVertex2i(1053, 880);
    glVertex2i(1048, 880);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1060, 1060);
    glVertex2i(1120, 1060);
    glVertex2i(1120, 880);
    glVertex2i(1060, 880);
    glEnd();

    glPushMatrix();

    glTranslated(910,1060,0);  // door round shape
    glColor3f(0.0, 0.0, 0.0);
    circle(30,35,0,0);

    glTranslated(180,0,0);  // door round shape
    glColor3f(0.0, 0.0, 0.0);
    circle(30,35,0,0);

    glTranslated(-90,80,0);  // door round shape
    glColor3f(0.0, 0.0, 0.0);
    circle(40,45,0,0);

    glPopMatrix();


    glColor3f(0.7,0.5,0.3);  // ground
    glBegin(GL_POLYGON);
    glVertex2i(0, 780);
    glVertex2i(2000, 780);
    glVertex2i(2000, 0);
    glVertex2i(0,0);
    glEnd();

    glColor3f(0.6,0.9,0.9);  // aquarium white water
    glBegin(GL_POLYGON);
    glVertex2i(800, 600);
    glVertex2i(1200, 600);
    glVertex2i(1400, 400);
    glVertex2i(600,400);
    glEnd();

    glColor3f(0.3,0.5,1.0);  // aquarium blue water
    glBegin(GL_POLYGON);
    glVertex2i(800, 550);
    glVertex2i(1200, 550);
    glVertex2i(1350, 400);
    glVertex2i(650,400);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2i(800,600);
    glVertex2i(1200,600);

    glVertex2i(1400,400);
    glVertex2i(600,400);

    glVertex2i(800,600);
    glVertex2i(600,400);

    glVertex2i(1200,600);
    glVertex2i(1400,400);
    glEnd();

    glColor3f(0.9,0.9,1.0);  // aquarium light
    glBegin(GL_POLYGON);
    glVertex2i(980,700);
    glVertex2i(995,700);
    glVertex2i(995,600);
    glVertex2i(980,600);
    glEnd();

    glColor3f(0.9,0.9,1.0);
    glBegin(GL_POLYGON);
    glVertex2i(995,700);
    glVertex2i(1030,700);
    glVertex2i(1030,690);
    glVertex2i(995,690);
    glEnd();

    glColor3f(0.9,0.9,1.0); // triangles
    glBegin(GL_TRIANGLES);
    glVertex2i(1030, 700);
    glVertex2i(1060, 670);
    glVertex2i(1000, 670);
    glEnd();

    glColor3f(0.9,0.9,1.0);
    glBegin(GL_POLYGON);
    glVertex2i(710,660);
    glVertex2i(725,660);
    glVertex2i(725,520);
    glVertex2i(710,505);
    glEnd();

    glColor3f(0.9,0.9,1.0);
    glBegin(GL_POLYGON);
    glVertex2i(725,660);
    glVertex2i(770,660);
    glVertex2i(770,650);
    glVertex2i(725,650);
    glEnd();

    glColor3f(0.9,0.9,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(770, 660);
    glVertex2i(800, 630);
    glVertex2i(740, 630);
    glEnd();

    glColor3f(0.9,0.9,1.0);
    glBegin(GL_POLYGON);
    glVertex2i(960,530);
    glVertex2i(975,530);
    glVertex2i(975,400);
    glVertex2i(960,400);
    glEnd();

    glColor3f(0.9,0.9,1.0);
    glBegin(GL_POLYGON);
    glVertex2i(975,530);
    glVertex2i(1015,530);
    glVertex2i(1015,520);
    glVertex2i(975,520);
    glEnd();

    glColor3f(0.9,0.9,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(1015, 530);
    glVertex2i(1045, 500);
    glVertex2i(985, 500);
    glEnd();

    glColor3f(0.9,0.9,1.0);
    glBegin(GL_POLYGON);
    glVertex2i(1280,650);
    glVertex2i(1295,650);
    glVertex2i(1295,505);
    glVertex2i(1280,515);
    glEnd();

    glColor3f(0.9,0.9,1.0);
    glBegin(GL_POLYGON);
    glVertex2i(1235,640);
    glVertex2i(1280,640);
    glVertex2i(1280,650);
    glVertex2i(1235,650);
    glEnd();

    glColor3f(0.9,0.9,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(1235, 650);
    glVertex2i(1265, 620);
    glVertex2i(1205, 620);
    glEnd();


    //middle to right

    glColor3f(0.0,0.0,0.0);  // mosque upper window
    glBegin(GL_POLYGON);
    glVertex2i(1165, 1065);
    glVertex2i(1185, 1065);
    glVertex2i(1185, 970);
    glVertex2i(1165, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1195, 1065);
    glVertex2i(1215, 1065);
    glVertex2i(1215, 970);
    glVertex2i(1195, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0); // triangles
    glBegin(GL_TRIANGLES);
    glVertex2i(1170, 1070);
    glVertex2i(1190, 1100);
    glVertex2i(1210, 1070);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1240, 1050);
    glVertex2i(1260, 1050);
    glVertex2i(1260, 970);
    glVertex2i(1240, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1280, 1050);
    glVertex2i(1300, 1050);
    glVertex2i(1300, 970);
    glVertex2i(1280, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1320, 1050);
    glVertex2i(1340, 1050);
    glVertex2i(1340, 970);
    glVertex2i(1320, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1360, 1050);
    glVertex2i(1380, 1050);
    glVertex2i(1380, 970);
    glVertex2i(1360, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1400, 1050);
    glVertex2i(1420, 1050);
    glVertex2i(1420, 970);
    glVertex2i(1400, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1440, 1050);
    glVertex2i(1460, 1050);
    glVertex2i(1460, 970);
    glVertex2i(1440, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1480, 1050);
    glVertex2i(1500, 1050);
    glVertex2i(1500, 970);
    glVertex2i(1480, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1520, 1050);
    glVertex2i(1540, 1050);
    glVertex2i(1540, 970);
    glVertex2i(1520, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1560, 1050);
    glVertex2i(1580, 1050);
    glVertex2i(1580, 970);
    glVertex2i(1560, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1600, 1050);
    glVertex2i(1620, 1050);
    glVertex2i(1620, 970);
    glVertex2i(1600, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1640, 1050);
    glVertex2i(1660, 1050);
    glVertex2i(1660, 970);
    glVertex2i(1640, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1680, 1050);
    glVertex2i(1700, 1050);
    glVertex2i(1700, 970);
    glVertex2i(1680, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1720, 1050);
    glVertex2i(1740, 1050);
    glVertex2i(1740, 970);
    glVertex2i(1720, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1760, 1050);
    glVertex2i(1780, 1050);
    glVertex2i(1780, 970);
    glVertex2i(1760, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1800, 1050);
    glVertex2i(1820, 1050);
    glVertex2i(1820, 970);
    glVertex2i(1800, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1840, 1050);
    glVertex2i(1860, 1050);
    glVertex2i(1860, 970);
    glVertex2i(1840, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1880, 1050);
    glVertex2i(1900, 1050);
    glVertex2i(1900, 970);
    glVertex2i(1880, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1920, 1050);
    glVertex2i(1940, 1050);
    glVertex2i(1940, 970);
    glVertex2i(1920, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1960, 1050);
    glVertex2i(1980, 1050);
    glVertex2i(1980, 970);
    glVertex2i(1960, 970);
    glEnd();


    // middle to left

    glColor3f(0.0,0.0,0.0);  // mosque upper widow
    glBegin(GL_POLYGON);
    glVertex2i(815, 1065);
    glVertex2i(835, 1065);
    glVertex2i(835, 970);
    glVertex2i(815, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(785, 1065);
    glVertex2i(805, 1065);
    glVertex2i(805, 970);
    glVertex2i(785, 970);
    glEnd();


    glColor3f(0.0,0.0,0.0); // triangles
    glBegin(GL_TRIANGLES);
    glVertex2i(790, 1070);
    glVertex2i(810, 1100);
    glVertex2i(830, 1070);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(760, 1050);
    glVertex2i(740, 1050);
    glVertex2i(740, 970);
    glVertex2i(760, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(720, 1050);
    glVertex2i(700, 1050);
    glVertex2i(700, 970);
    glVertex2i(720, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(680, 1050);
    glVertex2i(660, 1050);
    glVertex2i(660, 970);
    glVertex2i(680, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(640, 1050);
    glVertex2i(620, 1050);
    glVertex2i(620, 970);
    glVertex2i(640, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(600, 1050);
    glVertex2i(580, 1050);
    glVertex2i(580, 970);
    glVertex2i(600, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(560, 1050);
    glVertex2i(540, 1050);
    glVertex2i(540, 970);
    glVertex2i(560, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(520, 1050);
    glVertex2i(500, 1050);
    glVertex2i(500, 970);
    glVertex2i(520, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(480, 1050);
    glVertex2i(460, 1050);
    glVertex2i(460, 970);
    glVertex2i(480, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(440, 1050);
    glVertex2i(420, 1050);
    glVertex2i(420, 970);
    glVertex2i(440, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(400, 1050);
    glVertex2i(380, 1050);
    glVertex2i(380, 970);
    glVertex2i(400, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(360, 1050);
    glVertex2i(340, 1050);
    glVertex2i(340, 970);
    glVertex2i(360, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(320, 1050);
    glVertex2i(300, 1050);
    glVertex2i(300, 970);
    glVertex2i(320, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(280, 1050);
    glVertex2i(260, 1050);
    glVertex2i(260, 970);
    glVertex2i(280, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(240, 1050);
    glVertex2i(220, 1050);
    glVertex2i(220, 970);
    glVertex2i(240, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(200, 1050);
    glVertex2i(180, 1050);
    glVertex2i(180, 970);
    glVertex2i(200, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(160, 1050);
    glVertex2i(140, 1050);
    glVertex2i(140, 970);
    glVertex2i(160, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(120, 1050);
    glVertex2i(100, 1050);
    glVertex2i(100, 970);
    glVertex2i(120, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(80, 1050);
    glVertex2i(60, 1050);
    glVertex2i(60, 970);
    glVertex2i(80, 970);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(40, 1050);
    glVertex2i(20, 1050);
    glVertex2i(20, 970);
    glVertex2i(40, 970);
    glEnd();


    //stairs design

    glColor3f(0.5,0.6,0.6);
    glBegin(GL_POLYGON);
    glVertex2i(845, 950);     // ash color
    glVertex2i(1155, 950);
    glVertex2i(1080, 910);
    glVertex2i(920, 910);
    glEnd();

    glColor3f(0.6,0.6,0.5); // middle stairs
    glBegin(GL_POLYGON);
    glVertex2i(920, 910);
    glVertex2i(1080, 910);
    glVertex2i(1200, 710);
    glVertex2i(800, 710);
    glEnd();


    glColor3f(0.6,0.6,0.5);  // left stairs
    glBegin(GL_POLYGON);
    glVertex2i(845, 950);
    glVertex2i(920, 910);
    glVertex2i(800, 710);
    glVertex2i(700, 740);
    glEnd();

    glColor3f(0.6,0.6,0.5);  // right stairs
    glBegin(GL_POLYGON);
    glVertex2i(1080, 910);
    glVertex2i(1155, 950);
    glVertex2i(1300, 740);
    glVertex2i(1200, 710);
    glEnd();



    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);

    glVertex2i(904,880);
    glVertex2i(1098,880);

    glVertex2i(904,880);
    glVertex2i(820,920);

    glVertex2i(1098,880);
    glVertex2i(1175,920);

    glVertex2i(883,850);
    glVertex2i(1117,850);

    glVertex2i(883,850);
    glVertex2i(800,888);

    glVertex2i(1117,850);
    glVertex2i(1198,893);

    glVertex2i(865,820);
    glVertex2i(1137,820);

    glVertex2i(865,820);
    glVertex2i(778,860);

    glVertex2i(1137,820);
    glVertex2i(1213,863);

    glVertex2i(850,790);
    glVertex2i(1153,790);

    glVertex2i(850,790);
    glVertex2i(758,832);

    glVertex2i(1153,790);
    glVertex2i(1235,838);

    glVertex2i(830,760);
    glVertex2i(1170,760);

    glVertex2i(830,760);
    glVertex2i(737,800);

    glVertex2i(1170,760);
    glVertex2i(1250,808);

    glVertex2i(810,730);
    glVertex2i(1190,730);

    glVertex2i(810,730);
    glVertex2i(717,767);

    glVertex2i(1190,730);
    glVertex2i(1280,773);



    /////


    glVertex2i(800,710);
    glVertex2i(1200,710);

    glVertex2i(1200,710);
    glVertex2i(1300,740);

    glVertex2i(1300,740);
    glVertex2i(1155,950);

    glVertex2i(800,710);
    glVertex2i(700,740);

    glVertex2i(700,740);
    glVertex2i(845,950);
    glEnd();

    glColor3f(1.0,1.0,1.0);  // Lower side wall right
    glBegin(GL_TRIANGLES);
    glVertex2i(1280, 780);
    glVertex2i(2000, 780);
    glVertex2i(2000, 720);
    glEnd();

    glColor3f(1.0,1.0,1.0);  // Lower side wall Left
    glBegin(GL_TRIANGLES);
    glVertex2i(0, 780);
    glVertex2i(728,780);
    glVertex2i(0, 720);
    glEnd();

    //lower window left

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(705, 930);
    glVertex2i(745, 930);
    glVertex2i(745, 810);
    glVertex2i(705, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(655, 930);
    glVertex2i(695, 930);
    glVertex2i(695, 810);
    glVertex2i(655, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(605, 930);
    glVertex2i(645, 930);
    glVertex2i(645, 810);
    glVertex2i(605, 810);
    glEnd();

    //lower window right

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1250, 930);
    glVertex2i(1290, 930);
    glVertex2i(1290, 810);
    glVertex2i(1250, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1300, 930);
    glVertex2i(1340, 930);
    glVertex2i(1340, 810);
    glVertex2i(1300, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1350, 930);
    glVertex2i(1390, 930);
    glVertex2i(1390, 810);
    glVertex2i(1350, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0); //right side wide window
    glBegin(GL_POLYGON);
    glVertex2i(1420, 880);
    glVertex2i(1510, 880);
    glVertex2i(1510, 810);
    glVertex2i(1420, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1540, 880);
    glVertex2i(1630, 880);
    glVertex2i(1630, 810);
    glVertex2i(1540, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1660, 880);
    glVertex2i(1750, 880);
    glVertex2i(1750, 810);
    glVertex2i(1660, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1780, 880);
    glVertex2i(1870, 880);
    glVertex2i(1870, 810);
    glVertex2i(1780, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1900, 880);
    glVertex2i(1990, 880);
    glVertex2i(1990, 810);
    glVertex2i(1900, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);//left side wide window
    glBegin(GL_POLYGON);
    glVertex2i(485, 880);
    glVertex2i(575, 880);
    glVertex2i(575, 810);
    glVertex2i(485, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(365, 880);
    glVertex2i(455, 880);
    glVertex2i(455, 810);
    glVertex2i(365, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(245, 880);
    glVertex2i(335, 880);
    glVertex2i(335, 810);
    glVertex2i(245, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(125, 880);
    glVertex2i(215, 880);
    glVertex2i(215, 810);
    glVertex2i(125, 810);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(5, 880);
    glVertex2i(95, 880);
    glVertex2i(95, 810);
    glVertex2i(5, 810);
    glEnd();

    glPushMatrix();
    glTranslated(50,880,0);  //window top shape left to right
    glColor3f(0.0, 0.0, 0.0);
    circle(45,50,0,0);

    glTranslated(120,0,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(45,50,0,0);

    glTranslated(120,0,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(45,50,0,0);

    glTranslated(120,0,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(45,50,0,0);

    glTranslated(120,0,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(45,50,0,0);

    glTranslated(935,0,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(45,50,0,0);

    glTranslated(120,0,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(45,50,0,0);

    glTranslated(120,0,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(45,50,0,0);

    glTranslated(120,0,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(45,50,0,0);

    glTranslated(120,0,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(45,50,0,0);

    glPopMatrix();

    glColor3f(0.0,0.7,0.0); // Field
    glBegin(GL_POLYGON);
    glVertex2i(0, 680);
    glVertex2i(720, 680);
    glVertex2i(360, 280);
    glVertex2i(0, 280);
    glEnd();

    glColor3f(0.0,0.7,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1280, 680);
    glVertex2i(2000, 680);
    glVertex2i(2000, 280);
    glVertex2i(1640, 280);
    glEnd();

    glColor3f(0.3,0.9,0.1); // Field left
    glBegin(GL_POLYGON);
    glVertex2i(150, 680);
    glVertex2i(290, 680);
    glVertex2i(0, 490);
    glVertex2i(0, 590);
    glEnd();

    glColor3f(0.3,0.9,0.1);
    glBegin(GL_POLYGON);
    glVertex2i(380, 680);
    glVertex2i(500, 680);
    glVertex2i(0, 290);
    glVertex2i(0, 400);
    glEnd();

    glColor3f(0.3,0.9,0.1);
    glBegin(GL_POLYGON);
    glVertex2i(580, 680);
    glVertex2i(690, 680);
    glVertex2i(250, 280);
    glVertex2i(100, 280);
    glEnd();

    glColor3f(0.3,0.9,0.1); // Field right
    glBegin(GL_POLYGON);
    glVertex2i(1850, 680);
    glVertex2i(1710, 680);
    glVertex2i(2000, 490);
    glVertex2i(2000, 590);
    glEnd();

    glColor3f(0.3,0.9,0.1);
    glBegin(GL_POLYGON);
    glVertex2i(1620, 680);
    glVertex2i(1500, 680);
    glVertex2i(2000, 290);
    glVertex2i(2000, 400);
    glEnd();

    glColor3f(0.3,0.9,0.1);
    glBegin(GL_POLYGON);
    glVertex2i(1420, 680);
    glVertex2i(1310, 680);
    glVertex2i(1750, 280);
    glVertex2i(1900, 280);
    glEnd();

    glPushMatrix();
    glTranslated(90,640,0);    // Tree
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(-10,-190,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(250,190,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(-120,-300,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(170,160,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(180,140,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(880,0,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(170,-140,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(170,-150,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(110,120,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(-220,170,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glTranslated(230,0,0);
    glColor3f(0.0, 0.6, 0.1);
    circle(35,40,0,0);

    glPopMatrix();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);    // tree body
    glVertex2i(80, 600);
    glVertex2i(100,600);
    glVertex2i(100,590);
    glVertex2i(80,590);
    glEnd();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(320, 600);
    glVertex2i(340,600);
    glVertex2i(340,590);
    glVertex2i(320,590);
    glEnd();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(70, 410);
    glVertex2i(90,410);
    glVertex2i(90,400);
    glVertex2i(70,400);
    glEnd();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(550, 600);
    glVertex2i(570,600);
    glVertex2i(570,590);
    glVertex2i(550,590);
    glEnd();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(370, 462);
    glVertex2i(390,462);
    glVertex2i(390,452);
    glVertex2i(370,452);
    glEnd();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(200, 300);
    glVertex2i(220,300);
    glVertex2i(220,290);
    glVertex2i(200,290);
    glEnd();

    glColor3f(0.7,0.4,0.0);  //right
    glBegin(GL_POLYGON);
    glVertex2i(1430, 600);
    glVertex2i(1450,600);
    glVertex2i(1450,590);
    glVertex2i(1430,590);
    glEnd();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1600, 462);
    glVertex2i(1620,462);
    glVertex2i(1620,452);
    glVertex2i(1600,452);
    glEnd();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1770,312);
    glVertex2i(1790,312);
    glVertex2i(1790,302);
    glVertex2i(1770,302);
    glEnd();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1880,432);
    glVertex2i(1900,432);
    glVertex2i(1900,422);
    glVertex2i(1880,422);
    glEnd();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1660,600);
    glVertex2i(1680,600);
    glVertex2i(1680,590);
    glVertex2i(1660,590);
    glEnd();

    glColor3f(0.7,0.4,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(1890,600);
    glVertex2i(1910,600);
    glVertex2i(1910,590);
    glVertex2i(1890,590);
    glEnd();




    glColor3f(0.3,0.3,0.3);
    glBegin(GL_POLYGON);    // road
    glVertex2i(0, 280);
    glVertex2i(2000,280);
    glVertex2i(2000,0);
    glVertex2i(0,0);
    glEnd();

    glColor3f(1.0,1.0,0.3);
    glBegin(GL_POLYGON);    // road yellow line up
    glVertex2i(0, 280);
    glVertex2i(2000,280);
    glVertex2i(2000,270);
    glVertex2i(0,270);
    glEnd();

    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);    // road yellow line down
    glVertex2i(0, 10);
    glVertex2i(2000,10);
    glVertex2i(2000,0);
    glVertex2i(0,0);
    glEnd();


    glColor3f(1.0,1.0,1.0); //road line middle
    glBegin(GL_LINES);
    glVertex2i(100,140);
    glVertex2i(350,140);
    glVertex2i(550,140);
    glVertex2i(850,140);
    glVertex2i(1050,140);
    glVertex2i(1350,140);
    glVertex2i(1550,140);
    glVertex2i(1850,140);
    glEnd();

    glPushMatrix();                  //car 1st
    glTranslatef(Car1Position,0,0);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.4f, 0.5f);
    glVertex2f(75.0f, 100.0f);
    glVertex2f(415.0f, 100.0f);
    glVertex2f(435.0f, 35.0f);
    glVertex2f(65.0f, 35.0f);
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

    glPushMatrix();                  //car 2nd
    glTranslatef(Car2Position,0,0);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(1925.0f, 230.0f);
    glVertex2f(1585.0f, 230.0f);
    glVertex2f(1565.0f, 170.0f);
    glVertex2f(1935.0f, 170.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(1900,230);
    glVertex2f(1850,280);
    glVertex2f(1650,280);
    glVertex2f(1600,230);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(1880,230);
    glVertex2f(1840,270);
    glVertex2f(1660,270);
    glVertex2f(1620,230);
    glEnd();

    glTranslated(1870,180,0);   //wheels 1
    glColor3f(0.0, 0.0, 0.0);
    circle(25,35,0,0);

    glTranslated(-220,0,0);  //wheels 2
    glColor3f(0.0, 0.0, 0.0);
    circle(25,35,0,0);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(SkyPosition,0,0);

    glTranslated(1580,1680,0);  //sky
    glColor3f(1.0, 1.0, 1.0);
    circle(50,60,0,0);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(SkyPosition,0,0);

    glTranslated(1640,1700,0);  //sky
    glColor3f(1.0, 1.0, 1.0);
    circle(50,60,0,0);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(SkyPosition,0,0);

    glTranslated(1710,1680,0);  //sky
    glColor3f(1.0, 1.0, 1.0);
    circle(50,60,0,0);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(SkyPosition,0,0);

    glTranslated(1640,1650,0);  //sky
    glColor3f(1.0, 1.0, 1.0);
    circle(50,60,0,0);

    glPopMatrix();


    ////


    glPushMatrix();

    glTranslated(180,1660,0);  //sky
    glColor3f(1.0, 1.0, 1.0);
    circle(50,60,0,0);
    glPopMatrix();


    glPushMatrix();
    glTranslated(240,1680,0);  //sky
    glColor3f(1.0, 1.0, 1.0);
    circle(50,60,0,0);
    glPopMatrix();


    glPushMatrix();
    glTranslated(310,1660,0);  //sky
    glColor3f(1.0, 1.0, 1.0);
    circle(50,60,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(240,1630,0);  //sky
    glColor3f(1.0, 1.0, 1.0);
    circle(50,60,0,0);

    glPopMatrix();


	glFlush();
}

void sound()
{
    PlaySound("ajan.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
}

void sound2()
{
    PlaySound("rain.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
}

void sound3()
{

    PlaySound(NULL, NULL, SND_ASYNC|SND_FILENAME);

}


void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
case 'p':
    Car1Speed = 0.0f;
    Car2Speed = 0.0f;
    SkySpeed = 0.0f;
    break;
case 's':
    Car1Speed = 20.0f;
    Car2Speed = 20.0f;
    SkySpeed = 10.0f;
    break;
case 'd':
    glutDisplayFunc(day);
    sound3();
    glutPostRedisplay();
    break;
case 'n':
    glutDisplayFunc(night);
    sound();
    glutPostRedisplay();
    break;
case 'r':
    glutDisplayFunc(rain);
    sound2();
    glutPostRedisplay();
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
    glutCreateWindow("Press D: Day; Press N: Night; Press R: Rain; Press P: Pause Vehicle and Sky; Press S: Start Vehicle and Sky; Use mouse button and Arrow key for increase and decrease speed;");
    // Execute initialization procedure
    init();
    // Send graphics to display window
    glutDisplayFunc(day);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutSpecialFunc(SpecialInput);
    // Display everything and wait.
    glutIdleFunc(Idle);
    glutTimerFunc(100, Car1Update, 0);
    glutTimerFunc(100, Car2Update, 0);
    glutTimerFunc(100, SkyUpdate, 0);
    glutTimerFunc(100, RainUpdate, 0);
    glutMainLoop();
    glLoadIdentity();

    return 0;
}

