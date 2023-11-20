#include "fft_ifft.h"
#include <stdio.h>
#include <stdlib.h>

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

/* Вспомогательная функция для умножения комплексного числа в алгебраической форме на комплексное число в показательной */

static inline complex expMult(const complex* arg, const number* pow) { EXPMULTBODY }

/* Вспомогательный макрос для умножения комплексных чисел в алгебраической форме */

#define COMPLEXMULT(out, op1, op2) \
  out.Real = (op1.Real)*(op2.Real) - (op1.Imagine)*(op2.Imagine); \
  out.Imagine = (op1.Real)*(op2.Imagine) + (op1.Imagine)*(op2.Real)

/* Вспомогательный макрос для сложения комплексных чисел в алгебраической форме */

#define COMPLEXADD(out, op1, op2) \
  out.Real = op1.Real + op2.Real; \
  out.Imagine = op1.Imagine + op2.Imagine

static int fft_rec(number* in_vector, complex* out_vector, size_t size, complex* lsum, complex* rsum) {

  if(0 == size%2) {
    /* Рекурсия по первой части вектора */

    fft_rec(in_vector, out_vector, size/2, lsum, rsum);

    /* Вторая часть рассчитывается проще */

    complex temp1 = {0,0}, temp2 = {0,0}, temp3 = {(number) 1/size,0};

    for(size_t k=size/2; k<size; k++) {

      COMPLEXMULT(temp1, temp3, lsum[k-size/2]);
      COMPLEXMULT(temp2, temp3, rsum[k-size/2]);
      number pow = (-2*PI*k)/(size);
      temp2 = expMult(&temp2, &pow);
      COMPLEXADD(&(out_vector[k]), temp1, temp2);
    }

  }

  else {
    /* Прямое вычисление */

  }

  return 0;


}

int fft(number* in_vector, complex* out_vector, size_t size) {
  complex *lsum, *rsum;

  if(0 == size%2) {
    lsum = (complex* ) malloc((size/2)*sizeof(complex));
    rsum = (complex* ) malloc((size/2)*sizeof(complex));
  }

  return fft_rec(in_vector, out_vector, size, lsum, rsum);
}

int ifft(complex* in_vector, number* out_vector, size_t size) {
  return NULL;
}
