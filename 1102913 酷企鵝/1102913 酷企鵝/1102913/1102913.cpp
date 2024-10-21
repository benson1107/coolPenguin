#include <GL/glut.h>
#include <math.h>
GLsizei wh = 500, ww = 500; /* initial window size */
GLfloat size = 3.0;
GLfloat posX = 0, posY = 0;
GLfloat angle = 0;

GLfloat footL = 20.0f;
GLfloat footR = 20.0f;
bool LF_check = 0;
bool RF_check = 0;

GLfloat handL = 0.0f;
bool LH_check = 0;
GLfloat handR = 0.0f;
bool RH_check = 0;

float eyeL_x = -2.2;
float eyeL_y = 0.8;
float eyeR_x = 2.2;
float eyeR_y = 0.8;
float eyeMove_x = 0.01;
float eyeMove_y = 0.01;

void student_num()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);


	int x = 10;
	int y = -15;
	glBegin(GL_LINE_LOOP);
	glVertex2f(x, y);
	glVertex2f(x + 2, y);
	glVertex2f(x + 2, y - 2);
	glVertex2f(x, y - 2);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(x + 2, y - 2);
	glVertex2f(x + 2, y - 4);
	glVertex2f(x + 2, y - 4);
	glVertex2f(x, y - 4);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(x + 4, y);
	glVertex2f(x + 4, y - 4);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(x + 6, y);
	glVertex2f(x + 8, y);
	glVertex2f(x + 8, y - 4);
	glVertex2f(x + 6, y - 4);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(x + 6, y - 2);
	glVertex2f(x + 8, y - 2);
	glEnd();
}

void head(GLUquadricObj* quadricPtr)
{
	glTranslatef(0, 9, 0);
	glColor3f(0, 0, 0);
	gluSphere(quadricPtr, 6, 30, 10); //ball

	
}

void eye_L(GLUquadricObj* quadricPtr)
{
	//left eye white
	glTranslatef(-2.3, 0, -6);
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 300; ++i)
		glVertex3f(1.5 * sin(2 * 3.14 / 300 * i), 1.1 * cos(2 * 3.14 / 300 * i), 0);

	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-1.5, 1.1, 0);
	glVertex3f(1.5, 1.1, 0);
	glVertex3f(1.5, 0, 0);
	glVertex3f(-1.5, 0, 0);
	glEnd();
	glTranslatef(2.3, 0, 0);

	//pupil
	glTranslatef(eyeL_x, eyeL_y, 0);
	//glTranslatef(-2.2, 0.8, 0);
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 300; ++i)
		glVertex3f(0.4 * sin(2 * 3.14 / 300 * i), 0.4 * cos(2 * 3.14 / 300 * i), 0);

	glEnd();
	glTranslatef(-eyeL_x, -eyeL_y, 0);
	//glTranslatef(2.2, -0.8, 0);
}

void eye_R(GLUquadricObj* quadricPtr)
{	
	//right eye white
	glTranslatef(2.3, 0, 0);
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 300; ++i)
		glVertex3f(1.5 * sin(2 * 3.14 / 300 * i), 1.1 * cos(2 * 3.14 / 300 * i), 0);

	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-1.5, 1.1, 0);
	glVertex3f(1.5, 1.1, 0);
	glVertex3f(1.5, 0, 0);
	glVertex3f(-1.5, 0, 0);
	glEnd();
	glTranslatef(-2.3, 0, 0);

	//pupil
	glTranslatef(eyeR_x, eyeR_y, 0);
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 300; ++i)
		glVertex3f(0.4 * sin(2 * 3.14 / 300 * i), 0.4 * cos(2 * 3.14 / 300 * i), 0);

	glEnd();
	glTranslatef(-eyeR_x, -eyeR_y, 0);
	
}

void lip(GLUquadricObj* quadricPtr)
{
	glTranslatef(0, 0, -6);
	glColor3f(1, 1, 0);

	glBegin(GL_TRIANGLES);
	glVertex3f(0.0, -1.5, 0.0);
	glVertex3f(1.5, -2.5, 0.0);
	glVertex3f(0.0, -2.5, -1.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(0.0, -2.5, -1.0);
	glVertex3f(-1.5, -2.5, 0.0);
	glVertex3f(0.0, -1.5, 0.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(0.0, -2.6, -1.0);
	glVertex3f(1.5, -2.6, 0.0);
	glVertex3f(0.0, -3.4, 1.5);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(0.0, -3.4, 1.5);
	glVertex3f(-1.5, -2.6, 0.0);
	glVertex3f(0.0, -2.6, -1.0);
	glEnd();
	glTranslatef(0, 0, 6);
}

void hair(GLUquadricObj* quadricPtr)
{
	glColor3f(0, 0, 0);
	glRotatef(90, 1, 0, 0);
	glTranslatef(-3, 0, -8);
	//最左
	glTranslatef(-2, 0, 1);
	glRotatef(15, 0, 1, 0);
	gluCylinder(quadricPtr, 0, 2, 6, 5, 5);
	glRotatef(-15, 0, 1, 0);
	glTranslatef(2, 0, -1);

	//左
	glTranslatef(2, 0, 0);
	glTranslatef(-0.7, 1, 0);
	glRotatef(10, 0, 1, 0);
	gluCylinder(quadricPtr, 0, 2, 6, 5, 5);
	glRotatef(-10, 0, 1, 0);
	glTranslatef(0.7, -1, 0);

	//右
	glTranslatef(2, 0, 0);
	glTranslatef(0.7, 1, 0);
	glRotatef(-10, 0, 1, 0);
	gluCylinder(quadricPtr, 0, 2, 6, 5, 5);
	glRotatef(10, 0, 1, 0);
	glTranslatef(-0.7, -1, 0);

	//最右
	glTranslatef(2, 0, 0);
	glTranslatef(2, 0, 1);
	glRotatef(-15, 0, 1, 0);
	gluCylinder(quadricPtr, 0, 2, 6, 5, 5);
	glRotatef(15, 0, 1, 0);
	glTranslatef(-2, 0, -1);
	
	

	glTranslatef(-3, 0, 8);
	glRotatef(-90, 1, 0, 0);
}

void hand_L(GLUquadricObj* quadricPtr)
{
	glRotatef(handR, 0, 1, 0);
	glTranslatef(-3, 4.5, 0);
	glColor3f(0, 0, 0);
	glRotatef(90, 1, 0, 0);
	glRotatef(-60, 0, 1, 0);
	gluCylinder(quadricPtr, 1, 1, 5, 15, 5);

	glTranslatef(0, 0, 5); //
	gluSphere(quadricPtr, 1, 30, 10);
	glTranslatef(0, 0, -5);

	glRotatef(60, 0, 1, 0);
	glRotatef(-90,1 , 0, 0);
	glTranslatef(3 , -4.5 ,0);
	glRotatef(handR, 0, 1, 0);
}

void hand_R(GLUquadricObj* quadricPtr)
{
	glRotatef(handL, 0, 1, 0);
	glTranslatef(3, 4.5, 0);
	glColor3f(0, 0, 0);
	glRotatef(90, 1, 0, 0);
	glRotatef(60, 0, 1, 0);
	gluCylinder(quadricPtr, 1, 1, 5, 15, 5);

	glTranslatef(0, 0, 5); 
	gluSphere(quadricPtr, 1, 30, 10);
	glTranslatef(0, 0, -5);

	glRotatef(-60, 0, 1, 0);
	glRotatef(-90, 1, 0, 0);
	glTranslatef(-3, -4.5, 0);
	glRotatef(-handL, 0, -1, 0);

}

void foot_L(GLUquadricObj* quadricPtr)
{
	glRotatef(footL, 1, 0, 0);//
	glDisable(GL_CULL_FACE);
	glTranslatef(-1, -4.5, 0);
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-2, 2.2, 0);
	glVertex3f(0, 1.8, 0);
	glVertex3f(0.2, 0, 0);
	glVertex3f(-2.2, 0, 0);
	glEnd();
	glTranslatef(1, 4.5, 0);
	glRotatef(-footL, 1, 0, 0);
}

void foot_R(GLUquadricObj* quadricPtr)
{
	glRotatef(footR, 1, 0, 0);
	glTranslatef(-1, -4.5, 0);
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	glVertex3f(2, 1.8, 0);
	glVertex3f(4, 2.2, 0);
	glVertex3f(4.2, 0, 0);
	glVertex3f(2, 0, 0);
	glEnd();
	glTranslatef(1, 4.5, 0);
	glEnable(GL_CULL_FACE);
	glRotatef(-footR, 1, 0, 0);
}

void belly()
{
	//belly
	glTranslatef(0, 0, -4.5);
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 300; ++i)
		glVertex3f(3 * sin(2 * 3.14 / 300 * i), 2.5 * cos(2 * 3.14 / 300 * i), 0);

	glEnd();
	glTranslatef(0, 0, 4.5);
}

void body(GLUquadricObj* quadricPtr)
{
	glTranslatef(0, 2, 0);
	glColor3f(0, 0, 0);
	gluSphere(quadricPtr, 5, 30, 10); 
	glTranslatef(0, -2, 0);

	belly();
	hand_L(quadricPtr);
	hand_R(quadricPtr);


	foot_L (quadricPtr);
	foot_R (quadricPtr);
	

}


void mydisplay() {

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	student_num();

	GLUquadricObj* quadricPtr;
	quadricPtr = gluNewQuadric();
	gluQuadricNormals(quadricPtr, GLU_LINE);
	gluQuadricTexture(quadricPtr, GLU_NONE);
	gluQuadricDrawStyle(quadricPtr, GLU_FALSE);
	
	
	glRotatef(angle , 0, 1, 0); //旋轉
	body(quadricPtr);
	head(quadricPtr);
	hair(quadricPtr);
	lip(quadricPtr);
	eye_L(quadricPtr);
	eye_R(quadricPtr);

	gluDeleteQuadric(quadricPtr);

	glPopMatrix();

	glFlush();
}

void myidle() {
	glutPostRedisplay();
	angle += 0.01;

	//右腳擺動
	if (footL > 40.0f)
		LF_check = 1;
	else if (footL < -20.0f)
		LF_check = 0;
	LF_check ? footL -= 0.025 : footL += 0.025;
	
	//左腳擺動
	if (footR > 40.0f)
		RF_check = 0;
	else if (footR < -20.0f)
		RF_check = 1;
	RF_check ? footR += 0.025 : footR -= 0.025;

	//右手擺動
	if (handL > 60.0f)
		LH_check = 1;
	else if (handL < -60.0f)
		LH_check = 0;
	LH_check ? handL -= 0.05 : handL += 0.05;

	//左手擺動
	if (handR > 60.0f)
		RH_check = 0;
	else if (handR < -60.0f)
		RH_check = 1;
	RH_check ? handR += 0.05 : handR -= 0.05;
	
	//瞳孔擺動
	if (eyeL_x >= 1.3 || eyeL_x <= -0.3)
		eyeMove_x = -eyeMove_x;
	if (eyeL_y >= 0.8 || eyeL_y <= -0.8)
		eyeMove_y = -eyeMove_y;
	eyeL_x += eyeMove_x;
	eyeR_x += eyeMove_x;
	eyeL_y += eyeMove_y;
	eyeR_y += eyeMove_y;
}

void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-20.0, 20.0, -20.0 * (GLfloat)h / (GLfloat)w,
			20.0 * (GLfloat)h / (GLfloat)w, -20.0, 20.0);
	else
		glOrtho(-20.0 * (GLfloat)w / (GLfloat)h,
			20.0 * (GLfloat)w / (GLfloat)h, -20.0, 20.0, -20.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glOrtho(0.0, (GLdouble)w, 0.0, (GLdouble)h, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glViewport(0, 0, w, h);
}

void myinit(void) {
	glViewport(0, 0, ww, wh);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, (GLdouble)ww, 0.0, (GLdouble)wh, -1.0, 1.0);
	glutReshapeFunc(myReshape);
	glMatrixMode(GL_MODELVIEW);
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutCreateWindow("1102913_酷企鵝");
	glutDisplayFunc(mydisplay);
	glutIdleFunc(myidle);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	myinit();
	glutReshapeFunc(myReshape);
	glutMainLoop();
}