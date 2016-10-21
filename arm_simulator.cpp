#include <cmath>
#include <iostream>
#include <GL/glut.h>

using namespace std;

int l1=4, l2=3, l3=5;
int dage1=0, dage2=30, dage3=-30;

GLdouble CoordinateVertex[][3] = {
    {0.0, 0.0, 0.0},
    {3.0, 0.0, 0.0},
    {0.0, 3.0, 0.0},
    {0.0, 0.0, 3.0}
};

int CoordinateEdge[][2] = {
    {0, 1},
    {0, 2},
    {0, 3}
};

GLdouble ArmVertex[][3] = {
    {0.0, 0.0, 0.0},
    {0.0, l1, 0.0},
    {l2*cos(dage2)*sin(dage1), l1 + l2*sin(dage2), l2*cos(dage1)*cos(dage2)},
    {(cos(dage2)*cos(dage3)*sin(dage1) - sin(dage1)*sin(dage2)*sin(dage3))*(l3 + 1) + l2*cos(dage2)*sin(dage1), l1 + (cos(dage2)*sin(dage3) + cos(dage3)*sin(dage2))*(l3 + 1) + l2*sin(dage2), (l3 + 1)*(cos(dage1)*cos(dage2)*cos(dage3) - cos(dage1)*sin(dage2)*sin(dage3)) + l2*cos(dage1)*cos(dage2)}
};

int ArmEdge[][2] = {
    {0.0, 1.0},
    {1.0, 2.0},
    {2.0, 3.0},
};

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    /* 図形の描画 */
    glBegin(GL_LINES);

    glColor3d(0.0, 1.0, 0.0);
    glVertex3dv(CoordinateVertex[CoordinateEdge[0][0]]);
    glVertex3dv(CoordinateVertex[CoordinateEdge[0][1]]);

    glColor3d(0.0, 0.0, 1.0);
    glVertex3dv(CoordinateVertex[CoordinateEdge[1][0]]);
    glVertex3dv(CoordinateVertex[CoordinateEdge[1][1]]);

    glColor3d(1.0, 0.0, 0.0);
    glVertex3dv(CoordinateVertex[CoordinateEdge[2][0]]);
    glVertex3dv(CoordinateVertex[CoordinateEdge[2][1]]);

    cout << sin(30) << endl;

    glColor3d(1.0, 1.0, 1.0);
    for(int i=0; i<3; ++i){
        glVertex3dv(ArmVertex[ArmEdge[i][0]]);
        glVertex3dv(ArmVertex[ArmEdge[i][1]]);
    }

    glEnd();

    glFlush();
}

void resize(int w, int h)
{
    glViewport(0, 0, w, h);

    glLoadIdentity();
    gluPerspective(30.0, (double)w / (double)h, 1.0, 100.0);
    glTranslated(0.0, 0.0, -5.0);
    gluLookAt(-16.0, 3.0, 2.5, 0.0, 2.5, 2.5, 0.0, 1.0, 0.0);
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key){
        case 'q':
            exit(0);
            break;
        default:
            break;
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow("arm_simulator");
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    init();
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
