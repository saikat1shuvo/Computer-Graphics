#include <windows.h>
#include <GL/glut.h>
#include <math.h>   // ⭐ FIXED (for sin, cos)

// Function to draw rectangle
void drawRectangle(float x1, float y1, float x2, float y2, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

// Function to draw circle
void drawCircle(float cx, float cy, float r, float red, float green, float blue) {
    glColor3f(red, green, blue);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);

    for(int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        glVertex2f(cx + cos(angle) * r, cy + sin(angle) * r);
    }

    glEnd();
}

void display() {
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);

    // Bangladesh
    drawRectangle(-0.9f, 0.4f, -0.3f, 0.8f, 0.0f, 0.5f, 0.0f);
    drawCircle(-0.6f, 0.6f, 0.08f, 1.0f, 0.0f, 0.0f);

    // Japan
    drawRectangle(-0.2f, 0.4f, 0.4f, 0.8f, 1.0f, 1.0f, 1.0f);
    drawCircle(0.1f, 0.6f, 0.08f, 1.0f, 0.0f, 0.0f);

    // France
    drawRectangle(-0.9f, -0.1f, -0.7f, 0.3f, 0.0f, 0.0f, 1.0f);
    drawRectangle(-0.7f, -0.1f, -0.5f, 0.3f, 1.0f, 1.0f, 1.0f);
    drawRectangle(-0.5f, -0.1f, -0.3f, 0.3f, 1.0f, 0.0f, 0.0f);

    // Germany
    drawRectangle(-0.2f, 0.1f, 0.4f, 0.3f, 0.0f, 0.0f, 0.0f);
    drawRectangle(-0.2f, -0.1f, 0.4f, 0.1f, 1.0f, 0.0f, 0.0f);
    drawRectangle(-0.2f, -0.3f, 0.4f, -0.1f, 1.0f, 1.0f, 0.0f);

    // Italy
    drawRectangle(-0.9f, -0.8f, -0.7f, -0.4f, 0.0f, 0.6f, 0.0f);
    drawRectangle(-0.7f, -0.8f, -0.5f, -0.4f, 1.0f, 1.0f, 1.0f);
    drawRectangle(-0.5f, -0.8f, -0.3f, -0.4f, 1.0f, 0.0f, 0.0f);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutCreateWindow("5 Country Flags - Lab Task 2");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
