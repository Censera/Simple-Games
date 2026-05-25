#ifndef	CeLIB_H_
#	define	CeLIB_H_

#	include	<stdint.h>
#	include	<stddef.h>
#	include	<stdlib.h>
#	include	<string.h>
#	include	<ctype.h>

typedef	uint8_t	u8;
typedef	uint16_t	u16;
typedef	uint32_t	u32;
typedef	uint64_t	u64;

typedef	int8_t	i8;
typedef	int16_t	i16;
typedef	int32_t	i32;
typedef	int64_t	i64;

typedef	float	f32;
typedef	double	f64;
typedef	size_t	usize;
typedef	ptrdiff_t	isize;
typedef	signed _BitInt(128)	i128;
typedef	unsigned _BitInt(128)	u128;

typedef	u8	b8;

#	define	true	1
#	define	false	0

typedef	struct
{
	char	*cstr;
	usize	len;
	usize	cap;
}	string;

string	string_new(usize cap);
string	string_from(const char *str);
void	string_free(string *str);
void	string_push(string *str1, const string *str2);
void	string_trim(string *str);
void	string_clear(string *str);

i8	string_parse_i8(const string *raw);
i16	string_parse_i16(const string *raw);
i32	string_parse_i32(const string *raw);
i64	string_parse_i64(const string *raw);
i128	string_parse_i128(const string *raw);

#	define	parse_int(target, raw)	_Generic((target),	\
i8:	(target) = string_parse_i8(raw),	\
i16:	(target) = string_parse_i16(raw),	\
i32:	(target) = string_parse_i32(raw),	\
i64:	(target) = string_parse_i64(raw)	\
i128:	(target) = string_parse_i128(raw)	\
)

i64	ce_random(i64 min, i64 max);

#	define	MAX(a, b)	((a) > (b) ? (a) : (b))
#	define	MIN(a, b)	((a) > (b) ? (b) : (a))
#	define	ARRAY_LEN(x)	(sizeof x  / sizeof x[0] )
#	define	UNUSED(x)	(void)(x)

#endif
