/**
 * @file
 * @brief This file contains the declarations of all exported functions in the maths library.
 */

#ifndef MATHSLIB_ADDER_H
#define MATHSLIB_ADDER_H

 // Check if we are on Windows
#if defined(WIN32)|defined(_WIN32)
#ifdef maths_STATIC
#define MATHSLIB_API
#else
#ifdef maths_EXPORTS
#define MATHSLIB_API __declspec(dllexport)
#else
#define MATHSLIB_API __declspec(dllimport)
#endif
#endif
#else
#define MATHSLIB_API
#endif

/**
 * @brief Adding function
 *
 * function adds two numbers
 * * @param a is the first number
 * @param b is the second number
 * @return sum of a and b
 */
MATHSLIB_API int add(int a, int b);

#endif