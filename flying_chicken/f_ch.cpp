#include <GL/glut.h>
#include <math.h>
#include<iostream>
#include<cstring>
#define FPS 60
using namespace std;
float egg_x = 0.6;
float bird_x = 0.6;
float egg_y = 0.6;
float sp = -0.0004;
int egg_score = 0;
int missed_eggs = 0;
int i;
float xr = 0.0;
void basket() {
    //trapezium
    glBegin(GL_QUADS);
    glColor3f(0.792f, 0.584f, 0.360f);
    glVertex2f(-0.2f, -0.3f);
    glVertex2f(-0.4f, -0.3f);
    glVertex2f(-0.35687f, -0.50005f);
    glVertex2f(-0.25f, -0.5f);
    glEnd();
}
void background() {
    //square
    glBegin(GL_QUADS);
    glColor3f(0.329f, 0.7058f, 0.207f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(-1.0f, -0.5f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glEnd();
}
void egg() {
    //egg
    float theta7;
    glColor3f(0.96f, 0.835f, 0.682f);
    glPointSize(1);
    glBegin(GL_POLYGON);
    for (float i = 0; i < 360; i += 10) {
        theta7 = i * 3.14 / 180;
        glVertex2f(0.1 + 0.09 * cos(theta7), -0.5 + 0.2 * sin(theta7));
    }
    glEnd();
}
//bird
void bird() {
    glBegin(GL_QUADS);
    glColor3f(0.94f, 1.0f, 0.258f);
    //square
    glVertex2f(0.2, 0.4f);
    glVertex2f(-0.2f, 0.4f);
    glVertex2f(-0.2f, -0.4f);
    glVertex2f(0.2, -0.4f);
    glEnd();
    //triangle
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.0f, 0.2f);
    glVertex2f(0.3, 0.0f);
    glVertex2f(0.2f, 0.0f);
    glVertex2f(0.2, -0.3446f);
    glEnd();
    //two triangles
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.0f, 0.2f);
    glVertex2f(0.1f, 0.4f);
    glVertex2f(0.0f, 0.6f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(-0.1f, 0.7f);
    glVertex2f(-0.1f, 0.4f);
    glEnd();
    //right line
    glBegin(GL_LINES);
    glPointSize(10);
    glColor3f(0.8f, 0.5f, 0.2f);
    glVertex2f(0.2f, -0.4f);
    glVertex2f(0.1f, -0.2f);
    glEnd();
    //left line
    glBegin(GL_LINES);
    glPointSize(10);
    glColor3f(0.8f, 0.5f, 0.2f);
    glVertex2f(-0.2f, -0.4f);
    glVertex2f(-0.1f, -0.2f);
    glEnd();
    //left circle
    float theta1;
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(1);
    glBegin(GL_POLYGON);
    for (float i = 0; i < 360; i += 0.1) {
        theta1 = i * 3.14 / 180;
        glVertex2f(-0.1 + 0.06 * cos(theta1), 0.2 + 0.06 * sin(theta1));
    }
    glEnd();
    //center circle
    float theta2;
    glColor3f(0.0f, 0.90f, 1.0f);
    glPointSize(1);
    glBegin(GL_POLYGON);
    for (float i = 0; i < 360; i += 10) {
        theta2 = i * 3.14 / 180;
        glVertex2f(-0.1 + 0.03 * cos(theta2), 0.2 + 0.03 * sin(theta2));
    }
    glEnd();
    //right circle
    float theta3;
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(1);
    glBegin(GL_POLYGON);
    for (float i = 0; i < 360; i += 10) {
        theta3 = i * 3.14 / 180;
        glVertex2f(0.1 + 0.06 * cos(theta3), 0.2 + 0.06 * sin(theta3));
    }
    glEnd();
    //center circle
    float theta4;
    glColor3f(0.0f, 0.90f, 1.0f);
    glPointSize(1);
    glBegin(GL_POLYGON);
    for (float i = 0; i < 360; i += 10) {
        theta4 = i * 3.14 / 180;
        glVertex2f(0.1 + 0.03 * cos(theta4), 0.2 + 0.03 * sin(theta4));
    }
    glEnd();
    //right leg
    float theta5;
    glColor3f(0.956f, 0.615f, 0.10f);
    glPointSize(1);
    glBegin(GL_POLYGON);
    for (float i = 0; i < 180; i += 10) {
        theta5 = i * 3.14 / 180;
        glVertex2f(-0.075 + 0.07 * cos(theta5), -0.4 + 0.07 * sin(theta5));
    }
    glEnd();
    //left leg
    float theta6;
    glColor3f(0.956f, 0.615f, 0.10f);
    glPointSize(1);
    glBegin(GL_POLYGON);
    for (float i = 0; i < 180; i += 10) {
        theta6 = i * 3.14 / 180;
        glVertex2f(0.075 + 0.07 * cos(theta6), -0.4 + 0.07 * sin(theta6));
    }
    glEnd();
    //mouth
    glBegin(GL_POLYGON);
    glColor3f(0.956f, 0.615f, 0.10f);
    glVertex2f(.1, 0.0);
    glVertex2f(0.0f, 0.076f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(0.0, -0.1f);
    glEnd();
}

void score() {
    if (egg_y <= 0 && egg_x >= xr - 0.5 && egg_x <= xr - 0.2) {
        egg_y = 0.6;
        egg_score++;
        }}
void game_over() {
    missed_eggs++;
    if (missed_eggs >= 5) {
        sp = 0;
        cout<<"game over";}}
void displayMe(void)
{
    glEnable(GL_POINT_SMOOTH);
    glPointSize(10);
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-0.6843270309967,0.7480682592497,0);

    glBegin(GL_POLYGON);
    glColor3f(1, 1,1);
    float cx = 0;
    float cy = 0;
    float r = 0.2122154;
    int num_segments = 1000;

    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        glVertex2f(x + cx, y + cy);//output vertex
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0, 0,0);
    float cx1= 0.09;
    float cy1 = 0.05;
    float r1 = .2;
    int num_segments1 = 1000;
    for(int iii = 0; iii < num_segments1; iii++)
    {
        float theta = 2.0f * 3.1415926f * float(iii) / float(num_segments1);//get the current angle
        float x1 = r1 * cosf(theta);//calculate the x component
        float y1 = r1 * sinf(theta);//calculate the y component
        glVertex2f(x1 + cx1, y1 + cy1);//output vertex
    }
    glEnd();
//STAES
        glPointSize(2.2);
    glBegin(GL_POINTS);
    glColor3f(1, 1, 1);
    glVertex2f(1,0);
    glVertex2f(.5,0);
    glVertex2f(.4, -.5);
    glVertex2f(.7, -.8);
    glVertex2f(1, -.3);
    glVertex2f(.6,-.5);
    glVertex2f(.3,.1);
    glVertex2f(.2,-.5);
    glVertex2f(.8, -.6);
    glVertex2f(1,0);
    glVertex2f(.3,0);
    glVertex2f(.2, .5);
    glVertex2f(-.8, .8);
    glVertex2f(-.37, -.4);
    glVertex2f(-.69,.59);
    glVertex2f(.488,.18);
    glVertex2f(.366,.59);
    glVertex2f(1, -.69);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(xr, 0.0f, 0.0f);
    basket();
    glPopMatrix();
    background();
    glPushMatrix();
    glTranslatef(egg_x, egg_y, 0);
    glScalef(.4, .4, 0);
    egg_x += sp;
    if (egg_x <= -0.9) {
        sp *= -1.05;
    }
    if (egg_x >= 0.9) {
        sp *= -1.05;
    }
    if (egg_x >= bird_x || egg_x <= bird_x) {
        egg_y += -0.0004;
        if (egg_y <= -0.2) {
            egg_y = 0.6;
            game_over();}}
    egg();
    glPopMatrix();
    score();
    glPushMatrix();
    glTranslatef(bird_x, .6, 0);
    glScalef(.3, .5, 0);
    bird_x += sp;
    if (bird_x <= -0.9) {
        sp *= -1.05;
    }
    if (bird_x >= 0.9) {
        sp *= -1.05;
    }
    bird();
    glPopMatrix();
    glFlush();
    glutPostRedisplay();
}
void specialkey(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
        xr -= 0.1;
        cout << x << endl;
        glutPostRedisplay();
        break;
    case GLUT_KEY_RIGHT:
        xr += 0.1;
        cout << x << endl;
        glutPostRedisplay();
        break;}}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("shape");
    glutDisplayFunc(displayMe);
    glutSpecialFunc(specialkey);
    glutMainLoop();
    return 0;
}

