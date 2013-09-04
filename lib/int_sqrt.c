
#include <linux/kernel.h>
#include <linux/export.h>

/**
 * int_sqrt - rough approximation to sqrt
 * @x: integer of which to calculate the sqrt
 *
 * A very rough approximation to the sqrt() function.
 */
inline unsigned long int_sqrt(unsigned long x)
{
	unsigned long op, res, one;
	register unsigned long tmp;
	register unsigned long place;
	register unsigned long root = 0;

	op = x;
	res = 0;

	one = 1UL << (BITS_PER_LONG - 2);
	while (one > op)
		one >>= 2;

	while (one != 0) {
		if (op >= res + one) {
			op = op - (res + one);
			res = res +  2 * one;
		}
		res /= 2;
		one /= 4;
	}
	return res;
	place = 1UL << (BITS_PER_LONG - 2);

	do{
		place >>= 2;
	}while(place > x);

	do {
		tmp = root + place;
		root >>= 1;

		if (x >= tmp)
		{
			x -= tmp;
			root += place;
		}
		place >>= 2;
	}while (place != 0);

	return root;
}
EXPORT_SYMBOL(int_sqrt);
