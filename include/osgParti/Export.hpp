#ifndef _OSGPARTI_EXPORT_HPP_
#define _OSGPARTI_EXPORT_HPP_

// define BASE_USE_DEPRECATED_API is used to include in API which is being fazed out
// if you can compile your apps with this turned off you are
// well placed for compatablity with future versions.
//#define BASE_USE_DEPRECATED_API

#if defined(_MSC_VER)
#pragma warning( disable : 4251 )
#endif

#if defined(_MSC_VER) || defined(__CYGWIN__) || defined(__MINGW32__) || defined( __BCPLUSPLUS__)  || defined( __MWERKS__)
#  if defined( _LIB ) || defined( USE_STATIC )
#    define OSGPARTI_EXPORT
#  elif defined( OSGPARTI_LIBRARY )
#    define OSGPARTI_EXPORT   __declspec(dllexport)
#  else
#    define OSGPARTI_EXPORT   __declspec(dllimport)
#  endif /* OSGPARTI_EXPORT */
#else
#  define OSGPARTI_EXPORT
#endif  

// set up define for whether member templates
// are supported by VisualStudio compilers.
#ifdef _MSC_VER
# if (_MSC_VER >= 1300)
#  define __STL_MEMBER_TEMPLATES
# endif
#endif

/* Define NULL pointer value */

#ifndef NULL
#ifdef  __cplusplus
#define NULL    0
#else
#define NULL    ((void *)0)
#endif
#endif

#endif

