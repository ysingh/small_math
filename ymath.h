#ifndef YMATH_H
#define YMATH_H
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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

vec3* vec3_new_empty(void) {
				vec3* vec3 = malloc(sizeof(vec3));
				if (!vec3) {
								printf("Malloc vector 3 failed\n");
				}
				return vec3;
}

vec3* vec3_new(float x, float y, float z) {
				vec3* vec3 = malloc(sizeof(vec3));
				if (!vec3) {
								printf("Malloc vector 3 failed\n");
				}
				vec3->x = x;
				vec3->y = y;
				vec3->z = z;
				return vec3;
}

void vec3_mul_s(float s, vec3* vec3) {
				vec3->x *= s;
				vec3->y *= s;
				vec3->z *= s;
}

void vec3_div_s(float s, vec3* vec3) {
				s = 1.00F/s;
				vec3->x *= s;
				vec3->y *= s;
				vec3->z *= s;
}

void vec3_negate(vec3* vec3) {
				vec3->x *= -1;
				vec3->y *= -1;
				vec3->z *= -1;
}

float vec3_magnitude(vec3* vec3) {
				return sqrt((vec3->x * vec3->x) + (vec3->y * vec3->y) + (vec3->z * vec3->z));
}

void vec3_normalize(vec3* vec3) {
				float mag_inv = 1.00F/vec3_magnitude(vec3);
				vec3->x *= mag_inv;
				vec3->y *= mag_inv;
				vec3->z *= mag_inv;
}

void vec3_addv(vec3* a, vec3* b) {
				a->x += b->x;
				a->y += b->y;
				a->z += b->z;
}

void vec3_addvr(vec3* a, vec3* b, vec3* res) {
				res->x = a->x + b->x;
				res->y = a->y + b->y;
				res->z = a->z + b->z;
}

void vec3_addvn(vec3* a, vec3* b) {
				vec3* res = malloc(sizeof(vec3));
				if (!res) {
								printf("Malloc vec3 failed\n");
				}
				res->x = a->x + b->x;
				res->y = a->y + b->y;
				res->z = a->z + b->z;
}

void vec3_subv(vec3* a, vec3* b) {
				a->x -= b->x;
				a->y -= b->y;
				a->z -= b->z;
}

void vec3_subvr(vec3* a, vec3* b, vec3* res) {
				res->x = a->x - b->x;
				res->y = a->y - b->y;
				res->z = a->z - b->z;
}

void vec3_subvn(vec3* a, vec3* b) {
				vec3* res = malloc(sizeof(vec3));
				if (!res) {
								printf("Malloc vec3 failed\n");
				}
				res->x = a->x - b->x;
				res->y = a->y - b->y;
				res->z = a->z - b->z;
}

void vec3_prnt(vec3* a) {
				printf("x: %f y: %f, z: %f\t 0: %f 1: %f 2: %fi\n", a->x, a->y, a->z, a->elements[0], a->elements[1], a->elements[2]);
}

#endif

