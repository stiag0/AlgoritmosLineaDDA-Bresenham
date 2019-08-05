/*Libreria usada solo en Windows - debe ir antes que las demás librerias*/
#include<windows.h>
/*Libreria del OpenGL*/
#include<GL/glut.h>
#include <cmath> 
#include <iostream> 
using namespace std;
void draw(void)

{

	glClear(GL_COLOR_BUFFER_BIT);

	/*todo lo que se quiera pintar*/
	int Xini = 10;
	int Yini = 10;
	int Xfin = 255;
	int Yfin = 255;
	
	cout << "introdusca las coordenadas de los puntos x1,y1 ; x2,y2" << '\n' << "x1"<<'\n';
	cin >> Xini;
	cout << "y1" << '\n';
	cin >> Yini;
	cout << "x2" << '\n';
	cin >> Xfin;
	cout << "y2 \n";
	cin >> Yfin;
	
	
	//DDA algoritm
	int dx = Xfin - Xini;
	int dy = Yfin - Yini;
	int pasos;
	if (dx > dy) {
		pasos = dx;
	}
	else {
		pasos = dy;
	}
	//incrementos en cada eje
	float Xincr = (float) dx / (float)pasos;
	float Yincr = (float) dy / (float)pasos;

	float x = Xini;
	float y = Yini;
	glBegin(GL_POINTS);
	glColor3f(255, 0, 0);
	glVertex2i(Xini,Yini);
	glColor3f(255, 0, 0);
	glVertex2i(Xfin, Yfin);


	for (int i = 0; i < pasos; i++)
	{
		glColor3f(255, 0, 0);
		glVertex2i(round(x), round(y));
		x += Xincr;
		y += Yincr;
	}

	
	//bresenham algoritm
	int end;
	dx = abs(Xini - Xfin);
	dy = abs(Yini - Yfin);
	int p = 2 * dy - dx;

	if (Xini > Xfin)
	{
		x = Xfin;
		y = Yfin;
		end = Xini;
	}
	else
	{
		x = Xini;
		y = Yini;
		end = Xfin;
	}
	
	glColor3f(0, 255, 0);
	glVertex2i(x+10, y);

	while (x <= end)
	{
		if (p < 0)
		{
			x++;
			p = p + 2 * dy;
		}
		else
		{
			x++;
			y++;
			p = p + 2 * (dy - dx);
		}

		glColor3f(0, 255, 0);
		glVertex2i(x+10, y);
		
	}
	glEnd();
	glFlush();

}

int main(int argc, char** argv)

{

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(760, 600);

	glutInitWindowPosition(300, 100);

	glutCreateWindow("dibujando lineas DDA & Bresenham 2D  OpenGL freeglut");

	glClearColor(1.0, 1.0, 1.0, 0.0);

	glMatrixMode(GL_PROJECTION);

	gluOrtho2D(0, 800,0, 800);

	glutDisplayFunc(draw);

	glutMainLoop();

}