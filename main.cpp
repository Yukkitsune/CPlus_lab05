/*
Дан массив натуральных чисел размерности n. Отсортировать массив в порядке
неубывания сумм цифр десятичной записи чисел. Функция должна считать сумму
десятичных цифр натурального числа.
*/
#include <iostream>
#include <string>
#include <ctime>

int getSum(int number) { // Функция суммы цифр в числе
    int sum = 0;
    while (number) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int main(int argc, char * argv[])
{
    int n; // Количество элементов в массиве
    setlocale(LC_ALL, "Russian"); // Русский язык в консоли
    srand(time(0)); // Рандомный сид для генерации аргуметов
    if (argc != 2) // Ошибка
    {
        std::cout << "Ошибка, параметров в командной строке не хватает для задания исходных данных или их количество избыточно. Для завершения нажмите любую клавишу" << std::endl;
        system("pause");
        return 1;
    }
    try // Здесь обработка исключения (ошибки)
    {
        // Читаем значения из командной строки
        n = std::stoi(argv[1]); // преобразование из строки в int
    }
    catch (std::invalid_argument const& ex) // Инструкции при исключении
    {
        std::cout << "Ошибка, неверный формат первого входного параметра. Для завершения нажмите любую клавишу\n";
        std::cout << "std::invalid_argument::what(): " << ex.what() << '\n'; // Вывод сообщения о типе ошибки
        system("pause");
        return 1;
    }
    int* mas = new int [n]; // Создание целочисленного динамического массива
    for (size_t i = 0; i < n;++i) { // Заполнение массива случайными значениями
        mas[i] = rand() % 1000;
    }
    std::cout << "Сгенерированный массив: "; // Вывод сгенерированного массива
    for (size_t i = 0; i < n;++i) {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;
    for (size_t i = 0; i < n; ++i) { // Сортировка массива по сумме цифр
        bool flag = true;
        for (size_t j = 0; j < n - (i + 1); j++) {
            if (getSum(mas[j]) > getSum(mas[j + 1])) {
                flag = false;
                std::swap(mas[j], mas[j + 1]);
                }
            }
        if (flag) {
            break;
        }
    }
    for (size_t i = 0; i < n; ++i) { // Сортировка массива по значениям
        bool flag = true;
        for (size_t j = 0; j < n - (i + 1); j++) {
            if (getSum(mas[j]) == getSum(mas[j + 1]) && (mas[j]>mas[j+1])) {
                flag = false;
                std::swap(mas[j], mas[j + 1]);
            }
        }
        if (flag) {
            break;
        }
    }
    std::cout << "Отсортированный массив: "; // Вывод отсортированного массива
    for (size_t i = 0; i < n;++i) { 
        std::cout << mas[i] << " ";
    }
    return 0;
}
