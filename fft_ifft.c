#include "fft_ifft.h"

#define PI 3.1415926535897932385

#ifdef TABLE
#include "trig_table.h"

static inline number sinx(number arg) {
  size_t current_index = 0;
  char sign = 1;

  
  if(arg < 0) {
    sign = -1;
    arg = -arg;
  } 
  if((int)(arg / (2*PI)) != 0) {arg = arg - (number) ( (int) (arg/(PI)) ) *PI;}

  /* Преобразования, приводящие arg в промежуто от 0 до PI/2 */

  if((arg>=0) && (arg<=PI/2)) {
    current_index = (size_t) (arg/TABLESTEP);
    if(current_index == TABLESIZE - 1) return sign;
  }
  else if((arg>PI/2) && (arg<=PI)) {
    arg = PI - arg;
    current_index = (size_t) (arg/TABLESTEP);
    if(current_index == 0) return 0;
  }
  else if((arg>PI) && (arg<=3*PI/2)) {
    sign = -sign;
    arg = arg - PI;
    current_index = (size_t) (arg/TABLESTEP);
    if(current_index == TABLESIZE-1) return sign;
  }
  else if((arg>3*PI/2) && (arg<=2*PI)) {
    sign = -sign;
    arg = 2*PI - arg;
    current_index = (size_t) (arg/TABLESTEP);
    if(current_index == 0) return 0;
  }

  /* Аппроксимация промежутка между узлами таблицы линейной функцией */
  return (sin_table[current_index] + ((sin_table[current_index+1] - sin_table[current_index])*(arg-current_index*TABLESTEP))/(TABLESTEP))*sign;

}

/* Макрос для умножения комплексного числа в алгебраической форме на комплексное число в показательной */

#define EXPMULTBODY \
  complex temp = {0,0}; \
  temp.Real = arg->Real*sinx(*pow + PI/2) - arg->Imagine*sinx(*pow); \
  temp.Imagine = arg->Imagine*sinx(*pow + PI/2) + arg->Real*sinx(*pow); \
  return temp;
#endif

#ifndef TABLE
#include <math.h>

#define EXPMULTBODY \
  complex temp = {0,0}; \
  temp.Real = arg->Real*sin(*pow + PI/2) - arg->Imagine*sin(*pow); \
  temp.Imagine = arg->Imagine*sin(*pow + PI/2) + arg->Real*sin(*pow); \
  return temp;
#endif

static inline complex expMult(const complex* arg, const number* pow) { EXPMULTBODY }

int fft(number* in_vector, complex* out_vector, size_t size) {
  return NULL;
}

int ifft(complex* in_vector, number* out_vector, size_t size) {
  return NULL;
}
