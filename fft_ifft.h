#ifndef FFT_IFFT_H
#define FFT_IFFT_H

#include <stddef.h>
#include <stdint.h>

//----------------------------------------------//
/* тип, который будет использоваться в векторах */
typedef float number;

/* убрать комментарий, если необходимо хранение таблицы тригонометрических функций */
// #define TABLE 

//----------------------------------------------//

#ifdef TABLE
#include "trig_table.h"
#endif

/* Структура, используемая для хранения комплексных чисел */

typedef struct {
  number Real;
  number Imagine;
} complex;

/* прямое быстрое преобразование Фурье. Вход - массив in_vector типа number,
 * выход - массив комплексных чисел типа complex, содержащиц комплексные числа
 * в алгебраической форме 
 */
complex* fft(number* in_vector, size_t size);

/* обратное преобразование Фурье. Вход - массив комплексных чисел типа complex,
 * содержащий комплексные числа в алгебраической форме, выход - массив типа number
 */

number* ifft(complex* in_vector, size_t size);

#endif
