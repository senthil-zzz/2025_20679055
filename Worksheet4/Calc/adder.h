#ifndef MATHSLIB_ADDER_H
#define MATHSLIB_ADDER_H

// check OS for Windows
#if defined(WIN32)|defined(_WIN32)
#ifdef maths_STATIC

#define MATHSLIB_API
#else
#ifdef maths_EXPORTS
  // if BUILDING the DLL, then EXPORT
#define MATHSLIB_API __declspec(dllexport)
#else
  // If USING the DLL, IMPORT
#define MATHSLIB_API __declspec(dllimport)
#endif
#endif
#else

#define MATHSLIB_API
#endif

MATHSLIB_API int add(int a, int b);

#endif