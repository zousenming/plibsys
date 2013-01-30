/* plibconfig.h
 *
 * This is a generated file.  Please modify 'configure.ac'
 */

#ifndef __PLIBCONFIG_H__
#define __PLIBCONFIG_H__

#include <winsock2.h>
#include <windows.h>

#include <pmacros.h>

#include <limits.h>
#include <float.h>

P_BEGIN_DECLS

#define P_MINFLOAT	FLT_MIN
#define P_MAXFLOAT	FLT_MAX
#define P_MINDOUBLE	DBL_MIN
#define P_MAXDOUBLE	DBL_MAX
#define P_MINSHORT	SHRT_MIN
#define P_MAXSHORT	SHRT_MAX
#define P_MAXUSHORT	USHRT_MAX
#define P_MININT	INT_MIN
#define P_MAXINT	INT_MAX
#define P_MAXUINT	UINT_MAX
#define P_MINLONG	LONG_MIN
#define P_MAXLONG	LONG_MAX
#define P_MAXULONG	ULONG_MAX

typedef signed char	pint8;
typedef unsigned char	puint8;
typedef signed short	pint16;
typedef unsigned short	puint16;
typedef signed int	pint32;
typedef unsigned int	puint32;
typedef signed int	pssize;
typedef unsigned int	psize;

#define PINT16_MODIFIER	"h"
#define PINT16_FORMAT	"hi"
#define PUINT16_FORMAT	"hu"
#define PINT32_MODIFIER	""
#define PINT32_FORMAT	"i"
#define PUINT32_FORMAT	"u"
#define PINT64_MODIFIER	"I64"
#define PINT64_FORMAT	"I64i"
#define PUINT64_FORMAT	"I64u"

#ifdef P_CC_MSVC
typedef signed __int64		pint64;
typedef unsigned __int64	puint64;
#else
typedef signed long long	pint64;
typedef unsigned long long	puint64;
#endif

typedef pint64 poffset;

#define POFFSET_MODIFIER	PINT64_MODIFIER
#define POFFSET_FORMAT		PINT64_FORMAT

#ifdef P_OS_WIN64

#define PLIB_SIZEOF_VOID_P	8
#define PLIB_SIZEOF_LONG	4
#define PLIB_SIZEOF_SIZE_T	8

#ifdef P_CC_MSVC
typedef signed __int64		pssize;
typedef unsigned __int64	psize;
#else
typedef signed long long	pssize;
typedef unsigned long long	psize;
#endif

#define PSIZE_MODIFIER		"I64"
#define PSSIZE_FORMAT		"I64d"
#define PSIZE_FORMAT		"I64u"

#define P_MAXSIZE		P_MAXUINT64
#define P_MINSSIZE		P_MININT64
#define P_MAXSSIZE		P_MAXINT64

#else

#define PLIB_SIZEOF_VOID_P	4
#define PLIB_SIZEOF_LONG	4
#define PLIB_SIZEOF_SIZE_T	4

typedef signed int		pssize;
typedef unsigned int		psize;

#define PSIZE_MODIFIER		""
#define PSSIZE_FORMAT		"i"
#define PSIZE_FORMAT		"u"

#define P_MAXSIZE		P_MAXUINT
#define P_MINSSIZE		P_MININT
#define P_MAXSSIZE		P_MAXINT

#endif


#ifndef P_OS_WIN64

#define PPOINTER_TO_INT(p)	((pint)   (p))
#define PPOINTER_TO_UINT(p)	((puint)  (p))

#define PINT_TO_POINTER(i)	((ppointer)  (i))
#define PUINT_TO_POINTER(u)	((ppointer)  (u))

typedef signed int		pintptr;
typedef unsigned int		puintptr;

#define PINTPTR_MODIFIER	""
#define PINTPTR_FORMAT		"i"
#define PUINTPTR_FORMAT		"u"

#else

#define PPOINTER_TO_INT(p)	((pint)  (pint64) (p))
#define PPOINTER_TO_UINT(p)	((puint) (puint64) (p))

#define PINT_TO_POINTER(i)	((ppointer) (pint64) (i))
#define PUINT_TO_POINTER(u)	((ppointer) (puint64) (u))

#ifndef P_CC_MSVC
typedef signed long long	pintptr;
typedef unsigned long long	puintptr;
#else
typedef signed __int64		pintptr;
typedef unsigned __int64	puintptr;
#endif

#define PINTPTR_MODIFIER	"I64"
#define PINTPTR_FORMAT		"I64i"
#define PUINTPTR_FORMAT		"I64u"

#endif

typedef struct _PMutex* PStaticMutex;
#define	P_STATIC_MUTEX_INIT		NULL
extern P_LIB_API PStaticMutex p_static_mutex_get_mutex_impl (PStaticMutex *mutex);
#define p_static_mutex_get_mutex(mutex)	(p_static_mutex_get_mutex_impl (mutex))


#define PINT16_TO_LE(val)	((pint16) (val))
#define PUINT16_TO_LE(val)	((puint16) (val))
#define PINT16_TO_BE(val)	((pint16) PUINT16_SWAP_BYTES (val))
#define PUINT16_TO_BE(val)	(PUINT16_SWAP_BYTES (val))
#define PINT32_TO_LE(val)	((pint32) (val))
#define PUINT32_TO_LE(val)	((puint32) (val))
#define PINT32_TO_BE(val)	((pint32) PUINT32_SWAP_BYTES (val))
#define PUINT32_TO_BE(val)	(PUINT32_SWAP_BYTES (val))
#define PINT64_TO_LE(val)	((pint64) (val))
#define PUINT64_TO_LE(val)	((puint64) (val))
#define PINT64_TO_BE(val)	((pint64) PUINT64_SWAP_BYTES (val))
#define PUINT64_TO_BE(val)	(PUINT64_SWAP_BYTES (val))
#define PLONG_TO_LE(val)	((plong) PINT32_TO_LE (val))
#define PULONG_TO_LE(val)	((pulong) PUINT32_TO_LE (val))
#define PLONG_TO_BE(val)	((plong) PINT32_TO_BE (val))
#define PULONG_TO_BE(val)	((pulong) PUINT32_TO_BE (val))
#define PINT_TO_LE(val)		((pint) PINT32_TO_LE (val))
#define PUINT_TO_LE(val)	((puint) PUINT32_TO_LE (val))
#define PINT_TO_BE(val)		((pint) PINT32_TO_BE (val))
#define PUINT_TO_BE(val)	((puint) PUINT32_TO_BE (val))
#define PSIZE_TO_LE(val)	((psize) PUINT32_TO_LE (val))
#define PSSIZE_TO_LE(val)	((pssize) PINT32_TO_LE (val))
#define PSIZE_TO_BE(val)	((psize) PUINT32_TO_BE (val))
#define PSSIZE_TO_BE(val)	((pssize) PINT32_TO_BE (val))
#define P_BYTE_ORDER		P_LITTLE_ENDIAN

P_END_DECLS

#endif /* __PLIBCONFIG_H__ */