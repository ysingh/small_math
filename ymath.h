#ifndef YMATH_H
#define YMATH_H
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SQ(x) (x * x)

/************* 
*  VECTORS   
*************/

typedef union vec2 {
	struct {
		float x, y;
	};
	float elements[2];
} vec2;

typedef union vec3 {
	struct {
		float x, y, z;
	};
	float elements[3];
} vec3;

typedef union vec4 {
	struct {
		float x, y, z, w;
	};
	float elements[4];
} vec4;

vec3 *vec3_new_empty(void) {
	vec3 *res = malloc(sizeof(vec3));
	if (!res) {
		printf("Malloc vector 3 failed\n");
		return NULL;
	}
	return res;
}

vec3 *vec3_new(float x, float y, float z) {
	vec3 *res = malloc(sizeof(vec3));
	if (!res) {
		printf("Malloc vector 3 failed\n");
		return NULL;
	}
	res->x = x;
	res->y = y;
	res->z = z;

	return res;
}

void vec3_muls(float s, vec3 *vec) {
	vec->x *= s;
	vec->y *= s;
	vec->z *= s;
}

void vec3_divs(float s, vec3 *vec) {
	s = 1.00F / s;
	vec->x *= s;
	vec->y *= s;
	vec->z *= s;
}

void vec3_neg(vec3 *vec) {
	vec->x *= -1;
	vec->y *= -1;
	vec->z *= -1;
}

float vec3_mag(vec3 *vec) {
	return sqrt(SQ(vec->x) + SQ(vec->y) + SQ(vec->z));
}

void vec3_norm(vec3 *vec) {
	float mag_inv = 1.00F / vec3_mag(vec);
	vec->x *= mag_inv;
	vec->y *= mag_inv;
	vec->z *= mag_inv;
}

vec3* vec_normn(vec3* vec) {
	vec3* res = malloc(sizeof(vec3));
	if (!res) {
		printf("Malloc vec3 failed\n");
	}
	float mag_inv = vec3_mag(vec);
	res->x = vec->x * mag_inv;
	res->y = vec->y * mag_inv;
	res->z = vec->z * mag_inv;
	
	return res;
}

void vec3_addv(vec3 *a, vec3 *b) {
	a->x += b->x;
	a->y += b->y;
	a->z += b->z;
}

void vec3_addvr(vec3 *a, vec3 *b, vec3 *res) {
	res->x = a->x + b->x;
	res->y = a->y + b->y;
	res->z = a->z + b->z;
}

vec3* vec3_addvn(vec3 *a, vec3 *b) {
	vec3 *res = malloc(sizeof(vec3));
	if (!res) {
		printf("Malloc vec3 failed\n");
		return NULL;
	}
	res->x = a->x + b->x;
	res->y = a->y + b->y;
	res->z = a->z + b->z;

	return res;
}

void vec3_subv(vec3 *a, vec3 *b) {
	a->x -= b->x;
	a->y -= b->y;
	a->z -= b->z;
}

void vec3_subvr(vec3 *a, vec3 *b, vec3 *res)
{
	res->x = a->x - b->x;
	res->y = a->y - b->y;
	res->z = a->z - b->z;
}

vec3* vec3_subvn(vec3 *a, vec3 *b)
{
	vec3 *res = malloc(sizeof(vec3));
	if (!res)
	{
		printf("Malloc vec3 failed\n");
		return NULL;
	}
	res->x = a->x - b->x;
	res->y = a->y - b->y;
	res->z = a->z - b->z;

	return res;
}

void vec3_prnt(vec3 *a) {
	printf("x: %f y: %f, z: %f\n", a->x, a->y, a->z);
}

/**********************
 *    MATRICES
 *********************/
#endif
