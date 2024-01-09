#   Быстрое преобразование Фурье и обратное быстрое преобразование Фурье
Низкое потребление памяти. Пространственная сложность алгоритма - O(1).
Временная сложность алгоритма - O(Nlog(N)) в случае, если N - степень двойки.

# Системные требования
- [gcc](https://gcc.gnu.org/install/)
- [python 3](https://www.python.org/downloads/) или выше
- [make](https://www.gnu.org/software/make/)

# Сборка (только Linux)

## Клонирование репозитория
Если у вас установлен `git`, то клонирование можно выполнить командой
```bash
git clone https://github.com/s4kkkk/FFT_IFFT.git
```
Если нет, то можно просто скачать архив с исходным кодом, а затем распаковать его в любом месте.

## Сборка

Если необходимо использование таблицы тригонометрических функций, раскомментировать макрос `TABLE` в `fft_ifft.h`, затем выполнить команду
```bash
make TABLE=yes SAMPLES=<кол-во узлов в таблице. может быть пустым> 
```
В противном случае
```bash
make TABLE=no
```
После выполнения команд в корневом каталоге репозитория появится файл `libfft_ifft.a`

# Использование
Интерфейс к коду описан в файле `fft_ifft.h`

Для компоновки библиотеки, в случае, если не используется таблица тригонометрических функций (указано `TABLE=no`), необходимо к компонуемому файлу подлючить `libm`.


Например, если файл, использующий библиотеку `libfft_ifft.a` , называется `myCode.c`, то команда для компиляции будет выглядеть следующим образом (`libfft_ifft.a` переместить в каталог, где находится myCode.c):
```bash
gcc -o myCode myCode.c -L. -lfft_ifft -lm
```



# Fast Fourier transform and inverse fast Fourier transform
Low memory consumption. The memory complexity of the algorithm is O(1).
The time complexity of the algorithm is O(Nlog(N)) if N is a power of two.

# System requirements
- [gcc](https://gcc.gnu.org/install/)
- [python 3](https://www.python.org/downloads/) or higher
- [make](https://www.gnu.org/software/make/)

# Build (Linux only)

## Cloning the repository
If you have `git` installed, then cloning can be performed with the command
```bash
git clone https://github.com/s4kkkk/FFT_IFFT.git
```
If not, you can simply download the archive with the source code, and then unzip it anywhere.

## Assembly

If you need to use a table of trigonometric functions, uncomment the macro `TABLE` in `fft_ifft.h`, then run the command
```bash
make TABLE=yes SAMPLES=<number of nodes in the table. may be empty>
```
Otherwise
```bash
make TABLE=no
```
After executing the commands, the file `libfft_ifft.a` will appear in the root directory of the repository

# Usage
The interface to the code is described in the file `fft_ifft.h`

To build the library, if the table of trigonometric functions is not used (`TABLE=no` is specified), it is necessary to attach `libm` to the component file.


For example, if the file using the library `libfft_ifft.a` is called `myCode.c`, then the compilation command will look like this (`libfft_ifft.a` move to the directory where myCode.c is located):
```bash
gcc -o myCode myCode.c -L. -lfft_ifft -lm
```

