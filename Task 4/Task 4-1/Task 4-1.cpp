#include <iostream>
#include "random"

using namespace std;

/**
 * \brief Класс переменных метода ввода
 */
enum class INPUT 
{
USER,
COMP
};

/**
 * \brief Функция выводит заданное сообщение и позволяет пользователю ввести чило
 * \param str Строка для вывода
 * \return Введённое число
 */
int Input_integer(const string str);
/**
 * \brief Функция автоматически заполняет массив целыми числами от -1000 до 1000
 * \param array Передаваемый массив
 * \param size Размера массива
 */
void Auto_fill(int* array, const size_t size);
/**
 * \brief Функция позволяет вручную заполнить массив
 * \param array Передаваемый массив
 * \param size Размер массива
 */
void Manual_fill(int* array, const size_t size);
/**
 * \brief Функция ищет сумму отрицательных элементов, кратных 10-ти
 * \param array Передаваемый массив
 * \param size Размер массива
 * \return Сумму отрицательных элементов кратных 10-ти
 */
int Find_neg10_sum(const int array[], const size_t size);
/**
 * \brief Функция меняет первые Х элементов на те же, но в обратном порядке
 * \param array Передаваемый массив
 * \param size Размер массива
 */
void Change_k_elements(int* array, const size_t size);
/**
 * \brief Функция проверяет массив на наличие пары соседних элементов, произведение которых равно заданному числу
 * \param array Передаваемый массив
 * \param size Размер массива
 * \return "true" если пара нашлась, "false" если такой пары нет
 */
bool Check_pair(int* array, size_t size);
/**
 * \brief Функция меняет местами две переменные типа int
 * \param first Первая переменная для замены
 * \param second Вторая переменная для замены
 */
void Switch(int& first, int& second);
/**
 * \brief Функция выводит массив в консоль
 * \param array Передаваемый массив
 * \param size Размер массива
 */
void Show_array(const int array[], const size_t size);

/**
 * \brief Точка входа в программу
 * \return 0 в случае успеха
 */
int main() {
    int size = Input_integer("Enter array size = ");
    int* array = new int[size];
    cout << "How to output an array?\n" <<
        static_cast<int>(INPUT::USER) << " - Manually\n" <<
        static_cast<int>(INPUT::COMP) << " - Automatically\n";
    int choose = Input_integer("");
    try {
        auto choosed = static_cast<INPUT>(choose);
        switch (choosed) {
        case INPUT::COMP: {
            Auto_fill(array, size);
            Show_array(array, size);
            break;
        }
        case INPUT::USER: {
            Manual_fill(array, size);
            Show_array(array, size);
            break;
        }
        default: {
            cout << "Going beyond";
            return 2;
        }
        }
    }
    catch (out_of_range) {
        return 1;
    }
    cout << "Sum of negative elements of multiples of 10 = " << Find_neg10_sum(array, size) << endl;
    try {
        Change_k_elements(array, size);
    }
    catch (out_of_range&) {
        cout << "Going beyond";
    }
    cout << "Is there a pair of neighboring elements in the array whose product is equal to the given one? ";
    if (Check_pair(array, size)) {
        cout << "yes\n";
    }
    else {
        cout << "no\n";
    }
    Show_array(array, size);
    delete[] array;

    return 0;
}

int Input_integer(const string str) {
    cout << str;
    int temp = 0;
    cin >> temp;
    if (temp < 0) {
        temp = 0;
    }
    return temp;
}

void Auto_fill(int* array, const size_t size) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> uniformIntDistribution(-1000, 1000);
    for (int i = 0; i < size; i++) {
        array[i] = uniformIntDistribution(gen);
    }
}

void Manual_fill(int* array, const size_t size) {
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }
}

int Find_neg10_sum(const int array[], const size_t size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] < 0 && abs(array[i]) % 10 == 0) {
            sum += array[i];
        }
    }
    return sum;
}

void Change_k_elements(int* array, const size_t size) {
    int number = 0;
    do {
        number = Input_integer("Enter the number of items needed to replace =");
    } while (number > size);
    for (int i = 0; i < number; ) {
        for (int j = number - 1; j > 0; ) {
            if (i < j) {
                Switch(array[i], array[j]);
            }
            i++;
            j--;
        }
    }
}

void Switch(int& first, int& second) {
    int temp = first;
    first = second;
    second = temp;
}

bool Check_pair(int* array, size_t size) {
    int multi = Input_integer("Enter the required product = ");
    for (int i = 0; i < size - 1; i++) {
        if (array[i] * array[i + 1] == multi) {
            return true;
        }
    }
    return false;
}

void Show_array(const int array[], const size_t size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << ' ';
    }
    cout << endl;
}