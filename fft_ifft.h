#ifndef FFT_IFFT_H
#define FFT_IFFT_H

#include <stddef.h>
#include <stdint.h>

//----------------------------------------------//
/* тип, который будет использоваться в векторах */
typedef double number;

/* убрать комментарий, если необходимо хранение таблицы тригонометрических функций */
//#define TABLE 

//----------------------------------------------//

/* Структура, используемая для хранения комплексных чисел */

typedef struct {
  number Real;
  number Imagine;
} complex;

/* прямое быстрое преобразование Фурье. Вход - массив in_vector типа number,
 * выход - массив комплексных чисел типа complex, содержащих комплексные числа
 * в алгебраической форме 
 */
int fft(number* in_vector, complex* out_vector, size_t size);

int dft(number* in_vector, complex* out_vector, size_t size);

/* обратное преобразование Фурье. Вход - массив комплексных чисел типа complex,
 * содержащий комплексные числа в алгебраической форме, выход - массив типа number
 */

int ifft(complex* in_vector, complex* out_vector, size_t size);

#endif
