#include <GL/glut.h>

float angle = 0.0;

void drawBlade() {
    glBegin(GL_TRIANGLES);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.05, 0.5);
        glVertex2f(-0.05, 0.5);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);


    glColor3f(0.5, 0.3, 0.1);
    glBegin(GL_QUADS);
        glVertex2f(-0.05, -1.0);
        glVertex2f(0.05, -1.0);
        glVertex2f(0.05, 0.0);
        glVertex2f(-0.05, 0.0);
    glEnd();


    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    glRotatef(angle, 0, 0, 1);

    glColor3f(0.0, 0.0, 1.0);

    for (int i = 0; i < 4; i++) {
        drawBlade();
        glRotatef(90, 0, 0, 1);
    }

    glPopMatrix();

    glutSwapBuffers();
}

void update(int value) {
    angle += 2.0;
    if (angle > 360) angle -= 360;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void init() {
    glClearColor(1, 1, 1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Windmill Animation");
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}

