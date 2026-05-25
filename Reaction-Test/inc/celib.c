#	include	"celib.h"
#	include	<stdio.h>
#	include	<sys/random.h>

i64	random(i64 min, i64 max)
{
	if (min > max)
	{
		i64	tmp = min;
		min = max;
		max = tmp;
	}

	u64	rng = (u64)max - (u64)min + 1;
	u64	lmt = UINT64_MAX - (UINT64_MAX % rng);
	i64	rnd = 0;

	do
	{
		if (getrandom(&rnd, sizeof rnd, 0) == -1)
			return -1;
	} while (rnd >= lmt);

	return (i64)(rnd % rng) + min;
}
