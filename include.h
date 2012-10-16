#ifndef INCLUDE_H
#define INCLUDE_H

#ifdef _WIN32
	#define _USE_MATH_DEFINES
	#define WIN32_EXTRA_LEAN
	#define _CRT_SECURE_NO_DEPRECATE
	#define NOMINMAX
	#include <windows.h>
	#include <GL/gl.h>
	#include <GL/glu.h>
#endif


//std
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

#include "vector.h"
#include "matrix.h"
#include "plane.h"
#include "mcubes.h"
#include "engine.h"

float abs32(float val);

#define MY_PI 3.14159265359f
#define MY_HALF_PI 1.5707963268f

#endif
