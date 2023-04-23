/*
 *   This file is part of the MLV Library.
 *
 *   Copyright (C) 2010 Adrien Boussicault, Marc Zipstein
 *
 *
 *    This Library is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This Library is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this Library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __MLV__WARNING_ERROR_H__
#define __MLV__WARNING_ERROR_H__

#include <stdio.h>
#include <stdlib.h>

#define ERROR(x) { fprintf( stderr, "Error detected by the function %s() in LibMLV : %s \n", __FUNCTION__, (x) ); exit(1); }

#define WARNING(x) { fprintf( stderr, "Warning generated by the function %s() in LibMLV : %s \n", __FUNCTION__, (x) ); }

#define TODO { fprintf( stderr, "The function %s() in LibThis Library is not implemented. \n", __FUNCTION__ ); exit(1); }

#define DEPRECATED(x) { fprintf( stderr, "The function %s() is deprecated. In the future, this function will disapear. Please use the %s() function instead of.\n", __FUNCTION__, (x) ); }

#define ERROR_FULL(x) { fprintf( stderr, "Error detected by the function %s() in LibMLV : %s ( file : %s, line : %i) \n", __FUNCTION__, (x), __FILE__, __LINE__ ); exit(1); }

#define WARNING_FULL(x) { fprintf( stderr, "Warning generated by the function %s() in LibMLV : %s ( file : %s, line : %i) \n", __FUNCTION__, (x), __FILE__, __LINE__ ); }

#define DEBUG(x) { fprintf( stderr, "DEBUG : %s - line : %i, file : %s\n", (x), __LINE__, __FILE__ ); }

#define NOT_IMPLEMENTED { fprintf( stderr, "The function %s() in LibMLV ( file : %s, line : %i ) is not implemented.\n", __FUNCTION__, __FILE__, __LINE__ ); exit(1); }

#endif