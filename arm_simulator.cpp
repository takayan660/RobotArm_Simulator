#include <iostream>
#include <math.h>
#include <GL/glut.h>

using namespace std;

static const double pi=3.14;

int l1=4, l2=3, l3=4;
double deg1 = 0 * pi/180.0,
       deg2 = 30 * pi/180.0,
       deg3 = -30 * pi/180.0;

double l2x = l2*cos(deg1)*cos(deg2),
       l2y = l2*cos(deg2)*sin(deg1),
       l2z = l1 + l2*sin(deg2);

double l3x = (l3 + 1)*(cos(deg1)*cos(deg2)*cos(deg3) - cos(deg1)*sin(deg2)*sin(deg3)) + l2*cos(deg1)*cos(deg2),
       l3y = (cos(deg2)*cos(deg3)*sin(deg1) - sin(deg1)*sin(deg2)*sin(deg3))*(l3 + 1) + l2*cos(deg2)*sin(deg1),
       l3z = l1 + (cos(deg2)*sin(deg3) + cos(deg3)*sin(deg2))*(l3 + 1) + l2*sin(deg2);

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
    {0.0,  l1, 0.0},
    {l2y, l2z, l2x},
    {l3y, l3z, l3x}
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
    gluLookAt(-14.0, 5.0, 4.0, 0.0, 3.0, 4.0, 0.0, 1.0, 0.0);
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
