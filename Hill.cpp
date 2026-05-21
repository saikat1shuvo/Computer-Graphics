
#include <GL/glut.h>
#include <cmath>

// Function to draw a circle for the sun
void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void display() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // White background
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); // Black ink color
    glLineWidth(2.0);

    // --- 1. The Sun ---
    drawCircle(0.2, 0.6, 0.15, 100);

    // --- 2. Left Mountain ---
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.7, -0.2);
        glVertex2f(-0.3, 0.5);
        glVertex2f(0.1, -0.2);
    glEnd();

    // --- 3. Right Mountain ---
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.1, -0.2);
        glVertex2f(0.3, 0.3);
        glVertex2f(0.7, -0.2);
    glEnd();

    // --- 4. Ground Curves ---
    glBegin(GL_LINE_STRIP);
        for(float x = -0.8; x <= 0.8; x += 0.01) {
            float y = -0.3 + 0.05 * sin(x * 4);
            glVertex2f(x, y);
        }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mountain Scene - OpenGL");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

