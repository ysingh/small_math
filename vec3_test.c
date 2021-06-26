#include <assert.h>
#include "smath.h"

int main(void) {
	vec3 *emptyVec = vec3_new_empty();
	vec3 *testVec = vec3_new(1.00, 1.00, 1.00);

	assert(emptyVec->x == 0.00);
	assert(emptyVec->y == 0.00);
	assert(emptyVec->z == 0.00);

	emptyVec->elements[0] = 7.00;
	emptyVec->elements[1] = 7.00;
	emptyVec->elements[2] = 7.00;

	assert(emptyVec->x == 7.00);
	assert(emptyVec->y == 7.00);
	assert(emptyVec->z == 7.00);

	emptyVec->x = 3.00;
	emptyVec->y = 4.00;
	emptyVec->z = 5.00;

	assert(emptyVec->x == 3.00);
	assert(emptyVec->y == 4.00);
	assert(emptyVec->z == 5.00);

	vec3 *initVec = vec3_new(1.15F, -2.00, 0.5);

	assert(initVec->x == 1.15F);
	assert(initVec->y == -2.00);
	assert(initVec->z == 0.50);

	vec3_muls(8.00, initVec);


	vec3_divs(4.00, testVec);
	vec3_neg(emptyVec);

	printf("Should be: -3, -4, -5\n");
	vec3_prnt(emptyVec);

	printf("Should be: 9.20, 16, 24\n");
	vec3_prnt(initVec);

	printf("Should be .25, .25, .25\n");
	vec3_prnt(testVec);

	float m = vec3_mag(emptyVec);
	printf("Should be 7.07106781187 MAGN: %f\n", m);

	vec3_norm(initVec);

	return 0;
}
