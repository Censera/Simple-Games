#ifndef	CeLIB_H_
#	define	CeLIB_H_

#	include	<stdint.h>
#	include	<stddef.h>

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

typedef	u8	b8;

#	define	true	1
#	define	false	0

typedef	struct
{
	char	*data;
	usize	len;
	usize	cap;
}	string;

string	new_string(usize cap);
void	free_string(string *s);
void	push_string(string *s1, string *s2);

i64	random(i64 min, i64 max);

#	define	MAX(a, b)	((a) > (b) ? (a) : (b))
#	define	MIN(a, b)	((a) > (b) ? (b) : (a))
#	define	ARRAY_LEN(x)	(sizeof x  / sizeof x[0] )
#	define	UNUSED(x)	(void)(x)

#endif
