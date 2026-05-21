Code-

#include <GL/glut.h>
#include <math.h>

float angle = 0.0;
float posX = -1.0;

void drawCircle(float cx, float cy, float r) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float theta = 2.0f * 3.1416f * i / 100;
        float x = r * cos(theta);
        float y = r * sin(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void drawCar() {

    glColor3f(0.0, 0.6, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(-0.5, -0.2);
        glVertex2f(0.5, -0.2);
        glVertex2f(0.5, 0.2);
        glVertex2f(-0.5, 0.2);
    glEnd();


    glPushMatrix();
    glTranslatef(-0.3, -0.3, 0);
    glRotatef(angle, 0, 0, 1);
    drawCircle(0, 0, 0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3, -0.3, 0);
    glRotatef(angle, 0, 0, 1);
    drawCircle(0, 0, 0.1);
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(posX, 0.0, 0.0);
    drawCar();

    glutSwapBuffers();
}

void update(int value) {
    posX += 0.01f;
    angle += 5.0;

    if (posX > 1.2)
        posX = -1.2;

    if (angle > 360)
        angle -= 360;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void init() {
    glClearColor(1, 1, 1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Moving Car");
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}

