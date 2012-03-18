// Mandelbrot Fun! - Dennis@VR
// z(n+1) = z(n+1)^2 + c
// OR z = z*z + c

#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <time.h>

void main(int argc, char** argv)
{
	int mwidth = 800; 
	int mheight = 600;
	
	//Initialize GL and set Window
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize(mwidth, mheight);
	glutCreateWindow("Mandelbrot");		
    glutReshapeWindow(mwidth, mheight);
	
	//Set GL Coordinates to 0,0 - Pixel mode
	glViewport(0, 0, mwidth, mheight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, mwidth, mheight, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
		
	glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(1); 	
	
	short int h;
	int hx, hy;
	double real,imaginary;
	double z, zx, zy;

	clock_t t1 = clock(); 	
    glBegin(GL_POINTS); 	

	for (hx=1; hx<=mwidth; hx++)
	{
		real = (float)hx / 300 - 2.0;

		for (hy=1; hy<=mheight; hy++)  
			{
			imaginary = (float)hy / 300 - 1.0;
			zx = 0.0; 
			zy = 0.0;
			
			for (h=1; h<25; h++)  
			{
				//(x + yi) (x + yi) = (xx - yy) + (xy + xy)i. Complex Numbers by hand.
				z  = zx*zx - zy*zy + real;
				zy = zx*zy + zx*zy + imaginary;
				zx = z;
				
				if ( zx*zx + zy*zy > 4)  
				{
				glColor3b(h*6, h*3, h*1);
				glVertex2i(hx, hy);
				break;
				}
								
			}

		}
	}
	
	glEnd();
	
	glFlush();
	clock_t t2 = clock(); 
	float mtime = ( ( (float)t2 - (float)t1 ) / CLOCKS_PER_SEC ) * 1000;   
	printf("%f milliseconds\n", mtime);   
	glutMainLoop();  

}


