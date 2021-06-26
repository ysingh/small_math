#include "ymath.h"

int main(void) {
				vec3* emptyVec = vec3_new_empty();
				vec3* initVec = vec3_new(1.15F, 2.00, 3.00);
				vec3* testVec = vec3_new(1.00, 1.00, 1.00);

				printf("Should be: 0, 0, 0\n");
				vec3_prnt(emptyVec);

				emptyVec->x = 3.00;
				emptyVec->y = 4.00;
				emptyVec->z = 5.00;

				printf("Should be: 3, 4, 5\n");
				vec3_prnt(emptyVec);
				
				printf("Should be: 1.15, 2, 3\n");
				vec3_prnt(initVec);

				printf("Should be: 1, 1, 1\n");
				vec3_prnt(testVec);

				vec3_mul_s(8.00, initVec);
				vec3_div_s(4.00, testVec);
				vec3_negate(emptyVec);

				printf("Should be: -3, -4, -5\n");
				vec3_prnt(emptyVec);

				printf("Should be: 9.20, 16, 24\n");
				vec3_prnt(initVec);

				printf("Should be .25, .25, .25\n");
				vec3_prnt(testVec);

				float m = vec3_magnitude(emptyVec);
				printf("Should be 7.07106781187 MAGN: %f\n", m);

				vec3_normalize(initVec);
				printf("Should be: 
				vec3_print(initVec);
}
