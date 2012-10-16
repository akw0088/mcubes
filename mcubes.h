typedef struct
{
	float x;
	float y;
	float z;
} XYZ;


typedef struct
{
	XYZ p[3];
} TRIANGLE;

typedef struct
{
	XYZ p[8];
	double val[8];
} GRIDCELL;

extern "C"
{
XYZ VertexInterp(double isolevel, XYZ p1, XYZ p2, double valp1, double valp2);
int Polygonise(GRIDCELL grid, double isolevel, TRIANGLE *triangles);
float abs32(float val);
}