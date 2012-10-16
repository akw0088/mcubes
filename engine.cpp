#include "include.h"

void Engine::init(void *param1, void *param2)
{
	hwnd = *((HWND *)param1);
	hdc = *((HDC *)param2);

	glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
	glClearStencil(0);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);
	glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
	time = 0;
}

void draw_box()
{
	//123 243 826 842 678 657 137 175 152 256 347 487
	glBegin(GL_LINES);
	glVertex3f(-0.5f, -0.5f, -0.5f); //1
	glVertex3f(-0.5f, -0.5f, 0.5f);  //2
	glVertex3f(-0.5f, 0.5f, -0.5f);  //3

	glVertex3f(-0.5f, -0.5f, 0.5f);  //2
	glVertex3f(-0.5f, 0.5f, 0.5f);   //4
	glVertex3f(-0.5f, 0.5f, -0.5f);  //3

	glVertex3f(0.5f, 0.5f, 0.5f);    //8
	glVertex3f(-0.5f, -0.5f, 0.5f);  //2
	glVertex3f(0.5f, -0.5f, 0.5f);   //6

	glVertex3f(0.5f, 0.5f, 0.5f);    //8
	glVertex3f(-0.5f, 0.5f, 0.5f);   //4
	glVertex3f(-0.5f, -0.5f, 0.5f);  //2

	glVertex3f(0.5f, -0.5f, 0.5f);   //6
	glVertex3f(0.5f, 0.5f, -0.5f);   //7
	glVertex3f(0.5f, 0.5f, 0.5f);    //8


	glVertex3f(0.5f, -0.5f, 0.5f);   //6
	glVertex3f(0.5f, -0.5f, -0.5f);  //5
	glVertex3f(0.5f, 0.5f, -0.5f);   //7

	glVertex3f(-0.5f, -0.5f, -0.5f); //1
	glVertex3f(-0.5f, 0.5f, -0.5f);  //3
	glVertex3f(0.5f, 0.5f, -0.5f);   //7

	glVertex3f(-0.5f, -0.5f, -0.5f); //1
	glVertex3f(0.5f, 0.5f, -0.5f);   //7
	glVertex3f(0.5f, -0.5f, -0.5f);  //5

	glVertex3f(-0.5f, -0.5f, -0.5f); //1
	glVertex3f(0.5f, -0.5f, -0.5f);  //5
	glVertex3f(-0.5f, -0.5f, 0.5f);  //2

	glVertex3f(-0.5f, -0.5f, 0.5f);  //2
	glVertex3f(0.5f, -0.5f, -0.5f);  //5
	glVertex3f(0.5f, -0.5f, 0.5f);   //6

	glVertex3f(-0.5f, 0.5f, -0.5f);  //3
	glVertex3f(-0.5f, 0.5f, 0.5f);   //4
	glVertex3f(0.5f, 0.5f, -0.5f);   //7

	glVertex3f(-0.5f, 0.5f, 0.5f);   //4
	glVertex3f(0.5f, 0.5f, 0.5f);    //8
	glVertex3f(0.5f, 0.5f, -0.5f);   //7
	glEnd();
}

void set_zero(GRIDCELL &grid)
{
	for(int i = 0; i < 8; i++)
	{
		grid.p[i].x = 0.0f;
		grid.p[i].y = 0.0f;
		grid.p[i].z = 0.0f;
		grid.val[i] = 0.0f;
	}
}

void set_circle(GRIDCELL &grid, float grid_width, float x, float y, float z, float x0, float y0, float z0)
{
	x -= grid_width / 2.0;
	y -= grid_width / 2.0;
	z -= grid_width / 2.0;

	grid.p[0].x = (x - 0.5);
	grid.p[0].y = (y - 0.5);
	grid.p[0].z = (z - 0.5);

	grid.p[1].x = (x + 0.5);
	grid.p[1].y = (y - 0.5);
	grid.p[1].z = (z - 0.5);

	grid.p[2].x = (x + 0.5);
	grid.p[2].y = (y - 0.5);
	grid.p[2].z = (z + 0.5);

	grid.p[3].x = (x - 0.5);
	grid.p[3].y = (y - 0.5);
	grid.p[3].z = (z + 0.5);


	grid.p[4].x = (x - 0.5);
	grid.p[4].y = (y + 0.5);
	grid.p[4].z = (z - 0.5);


	grid.p[5].x = (x + 0.5);
	grid.p[5].y = (y + 0.5);
	grid.p[5].z = (z - 0.5);


	grid.p[6].x = (x + 0.5);
	grid.p[6].y = (y + 0.5);
	grid.p[6].z = (z + 0.5);


	grid.p[7].x = (x - 0.5);
	grid.p[7].y = (y + 0.5);
	grid.p[7].z = (z + 0.5);

	x -= x0;
	y -= y0;
	z -= y0;

	grid.val[0] += (x - 0.5) * (x - 0.5) + (y - 0.5) * (y - 0.5) + (z - 0.5) * (z - 0.5);
	grid.val[1] += (x + 0.5) * (x + 0.5) + (y - 0.5) * (y - 0.5) + (z - 0.5) * (z - 0.5);
	grid.val[2] += (x + 0.5) * (x + 0.5) + (y - 0.5) * (y - 0.5) + (z + 0.5) * (z + 0.5);
	grid.val[3] += (x - 0.5) * (x - 0.5) + (y - 0.5) * (y - 0.5) + (z + 0.5) * (z + 0.5);
	grid.val[4] = (x - 0.5) * (x - 0.5) + (y + 0.5) * (y + 0.5) + (z - 0.5) * (z - 0.5);
	grid.val[5] += (x + 0.5) * (x + 0.5) + (y + 0.5) * (y + 0.5) + (z - 0.5) * (z - 0.5);
	grid.val[6] += (x + 0.5) * (x + 0.5) + (y + 0.5) * (y + 0.5) + (z + 0.5) * (z + 0.5);
	grid.val[7] += (x - 0.5) * (x - 0.5) + (y + 0.5) * (y + 0.5) + (z + 0.5) * (z + 0.5);
}


//f(x,y,z) = 1 / (x-x0)^2 + (y-y0)^2 + (z-z0)^2
void set_metaball(GRIDCELL &grid, float grid_width, float half_step, float scale, float x, float y, float z, float x0, float y0, float z0)
{
	x -= grid_width / 2.0;
	y -= grid_width / 2.0;
	z -= grid_width / 2.0;

	grid.p[0].x = (x - half_step);
	grid.p[0].y = (y - half_step);
	grid.p[0].z = (z - half_step);

	grid.p[1].x = (x + half_step);
	grid.p[1].y = (y - half_step);
	grid.p[1].z = (z - half_step);

	grid.p[2].x = (x + half_step);
	grid.p[2].y = (y - half_step);
	grid.p[2].z = (z + half_step);

	grid.p[3].x = (x - half_step);
	grid.p[3].y = (y - half_step);
	grid.p[3].z = (z + half_step);


	grid.p[4].x = (x - half_step);
	grid.p[4].y = (y + half_step);
	grid.p[4].z = (z - half_step);

	grid.p[5].x = (x + half_step);
	grid.p[5].y = (y + half_step);
	grid.p[5].z = (z - half_step);

	grid.p[6].x = (x + half_step);
	grid.p[6].y = (y + half_step);
	grid.p[6].z = (z + half_step);

	grid.p[7].x = (x - half_step);
	grid.p[7].y = (y + half_step);
	grid.p[7].z = (z + half_step);

	x -= x0;
	y -= y0;
	z -= y0;

	grid.val[0] += scale / ((x - half_step) * (x - half_step) + (y - half_step) * (y - half_step) + (z - half_step) * (z - half_step) + 1);
	grid.val[1] += scale / ((x + half_step) * (x + half_step) + (y - half_step) * (y - half_step) + (z - half_step) * (z - half_step) + 1);
	grid.val[2] += scale / ((x + half_step) * (x + half_step) + (y - half_step) * (y - half_step) + (z + half_step) * (z + half_step) + 1);
	grid.val[3] += scale / ((x - half_step) * (x - half_step) + (y - half_step) * (y - half_step) + (z + half_step) * (z + half_step) + 1);
	grid.val[4] += scale / ((x - half_step) * (x - half_step) + (y + half_step) * (y + half_step) + (z - half_step) * (z - half_step) + 1);
	grid.val[5] += scale / ((x + half_step) * (x + half_step) + (y + half_step) * (y + half_step) + (z - half_step) * (z - half_step) + 1);
	grid.val[6] += scale / ((x + half_step) * (x + half_step) + (y + half_step) * (y + half_step) + (z + half_step) * (z + half_step) + 1);
	grid.val[7] += scale / ((x - half_step) * (x - half_step) + (y + half_step) * (y + half_step) + (z + half_step) * (z + half_step) + 1);
}

void Engine::render()
{
	float i,j,k;
	int	num_cubes = 16;
	int	grid_width = 16;
	float	step_size = (float)grid_width / num_cubes;
	float	half_step = step_size / 2.0;
	TRIANGLE	triangle[5];
	GRIDCELL	cube;
	int		num_triangle = 0;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(0.0f, 0.0f, -40.0f);
//	glRotatef(time, 0.0f, 1.0f, 0.0f);


	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT );

	for(i = 0; i <= grid_width; i += step_size )
	{
		for(j = 0; j <= grid_width; j += step_size )
		{
			for(k = 0; k <= grid_width; k += step_size )
			{
				set_zero(cube);

				set_metaball(cube, grid_width, half_step, 2.0, i, j, k,
				5.5 * cos(time / 50.0),
				5 * sin(time / 50.0),
				0);

				set_metaball(cube, grid_width, half_step, 2.0, i, j, k,
				5.5 * sin(time / 50.0),
				5 * sin(time / 50.0),
				0);

				num_triangle = Polygonise(cube, 0.25, triangle);

//				glColor3f((int)(i + j + k) % 2, 0, 0);
				if (num_triangle)
				{
					for(int t = 0; t < num_triangle; t++)
					{
						glBegin(GL_TRIANGLES);
						glVertex3f(triangle[t].p[0].x, triangle[t].p[0].y, triangle[t].p[0].z);
						glVertex3f(triangle[t].p[1].x, triangle[t].p[1].y, triangle[t].p[1].z);
						glVertex3f(triangle[t].p[2].x, triangle[t].p[2].y, triangle[t].p[2].z);
						glEnd();
					}
				}
			}
		}
	}

/*
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(-8.0, -8.0, -8.0);
	for(i = 0; i <= num_cubes; i += 1.0f)
	{
		for(j = 0; j <= num_cubes; j += 1.0f)
		{
			for(k = 0; k <= num_cubes; k += 1.0f)
			{
				draw_box();
				glTranslatef(0.0, 0.0, 1.0);
			}
			glTranslatef(0.0, 1.0, 0.0);
			if (k == num_cubes + 1)
				glTranslatef(0.0, 0.0, -num_cubes - 1);
		}
		if (j == num_cubes + 1)
			glTranslatef(0.0, -num_cubes - 1, 0.0);
		glTranslatef(1.0, 0.0, 0.0);
	}
*/

	SwapBuffers(hdc);
}

void Engine::step()
{
	time++;
}


void Engine::resize(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (height != 0)
		gluPerspective( 45.0, (float) width / height, 1.0f, 2001.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Engine::destroy()
{
	printf("Shutting down.\n");
}

void Engine::quit()
{
#ifdef _WINDOWS_
	HWND hwnd = *((HWND *)param1);
	PostMessage(hwnd, WM_CLOSE, 0, 0);
#endif
}
