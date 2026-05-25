#	include	"celib.h"
#	include	<stdio.h>
#	include	<sys/random.h>

static char	empty_buffer[1] = { '\0' };

string	string_new(usize cap)
{
	string	str = { .cstr = NULL, .len = 0, .cap = 0};

	if (cap > 0)
	{
		str.cstr = calloc(cap + 1, sizeof(char));
		if (str.cstr)	str.cap = cap;
		else		str.cstr = empty_buffer;
	}
	return str;
}

string	string_from(const char *cstr)
{
	if (!cstr)
		return string_new(0);

	usize	len = strlen(cstr);

	string	str = string_new(len);
	if (!str.cstr)
		return str;

	memcpy(str.cstr, cstr, len);
	str.len = len;
	str.cstr[str.len] = '\0';

	return str;
}

void	string_free(string *str)
{
	if (!str)	return;
	if (str->cap > 0 && str->cstr != empty_buffer)
		free(str->cstr);

	str->cstr = empty_buffer;
	str->len = 0;
	str->cap = 0;
}

void	string_push(string *str1, const string *str2)
{
	if (!str1 || !str2 || !str1->cstr || !str2->cstr || str2->len == 0)
		return;

	usize	full_len = str1->len + str2->len;

	if (full_len > str1->cap)
	{
		usize	new_cap = str1->cap == 0 ? 16 : str1->cap + (str1->cap>>1);

		if (new_cap < full_len)
			new_cap = full_len;

		char	*new_cstr = realloc(str1->cstr, new_cap + 1);
		if (!new_cstr)	return;

		str1->cstr = new_cstr;
		str1->len = new_cap;
	}

	memmove(str1->cstr + str1->len, str2->cstr, str2->len);
	str1->len = full_len;

	str1->cstr[str1->len] = '\0';
}

void	string_trim(string *str)
{
	if(!str || !str->cstr || str->len == 0)
		return;

	while (str->len > 0 && isspace((unsigned char)str->cstr[str->len - 1]))
		str->len--;
	str->cstr[str->len] = '\0';

	usize	start = 0;
	while (start < str->len && isspace((unsigned char)str->cstr[start]))
		start++;

	if (start > 0)
	{
		str->cstr += start;
		str->len -= start;
		str->cap -= start;
	}
}

void	string_clear(string *str)
{
	if (!str || !str->cstr)	return;
	str->len = 0;
	str->cstr[0] = '\0';
}

i128	string_parse_i128(const string *raw)
{
	if (!raw || !raw->cstr)	return 0;

	i128	res = 0;
	i128	sign = +1;

	const char	*cursor = raw->cstr;

	while (isspace((unsigned char)*cursor))
		cursor++;

	if (*cursor == '-')
	{
		sign = -1;
		cursor++;
	}
	else if (*cursor == '+')
	{
		cursor++;
	}

	while (isdigit((unsigned char)*cursor))
	{
		res *= 10 + (*cursor - '0');
		cursor++;
	}

	return res * sign;
}

i64	string_parse_i64(const string *raw)	{ return (i64)string_parse_i128(raw); }
i32	string_parse_i32(const string *raw)	{ return (i32)string_parse_i128(raw); }
i16	string_parse_i16(const string *raw)	{ return (i16)string_parse_i128(raw); }
i8	string_parse_i8(const string *raw)	{ return (i8)string_parse_i128(raw); }

i64	ce_random(i64 min, i64 max)
{
	if (min > max)
	{
		i64	tmp = min;
		min = max;
		max = tmp;
	}

	u64	rng = (u64)max - (u64)min + 1;
	u64	lmt = UINT64_MAX - (UINT64_MAX % rng);
	u64	rnd = 0;

	do
	{
		if (getrandom(&rnd, sizeof rnd, 0) == -1)
			return -1;
	} while (rnd >= lmt);

	return (i64)(rnd % rng) + min;
}
