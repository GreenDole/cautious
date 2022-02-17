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
int input_integer(const string& str);
/**
 * \brief Функция автоматически заполняет массив целыми числами от -1000 до 1000
 * \param array Передаваемый массив
 * \param size Размера массива
 */
void auto_fill(int* array, const size_t size);
/**
 * \brief Функция позволяет вручную заполнить массив
 * \param array Передаваемый массив
 * \param size Размер массива
 */
void manual_fill(int* array, const size_t size);
/**
 * \brief Функция ищет сумму отрицательных элементов, кратных 10-ти
 * \param array Передаваемый массив
 * \param size Размер массива
 * \return Сумму отрицательных элементов кратных 10-ти
 */
int find_neg10_sum(const int* array, const size_t size);
/**
 * \brief Функция меняет первые Х элементов на те же, но в обратном порядке
 * \param array Передаваемый массив
 * \param size Размер массива
 */
void change_k_elements(int* array, const size_t size);
/**
 * \brief Функция проверяет массив на наличие пары соседних элементов, произведение которых равно заданному числу
 * \param array Передаваемый массив
 * \param size Размер массива
 * \return "true" если пара нашлась, "false" если такой пары нет
 */
bool check_pair(const int* array, const size_t size);
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
void show_array(const int* array, const size_t size);

/**
 * \brief Точка входа в программу
 * \return 0 в случае успеха
 */
int main() {
    int size = input_integer("Enter array size = ");
    int* array = new int[size];
    cout << "How to output an array?\n" <<
        static_cast<int>(INPUT::USER) << " - Manually\n" <<
        static_cast<int>(INPUT::COMP) << " - Automatically\n";
    int choose = input_integer("");
    try {
        auto choosed = static_cast<INPUT>(choose);
        switch (choosed) {
        case INPUT::COMP: {
            auto_fill(array, size);
            show_array(array, size);
            break;
        }
        case INPUT::USER: {
            manual_fill(array, size);
            show_array(array, size);
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
    cout << "Sum of negative elements of multiples of 10 = " << find_neg10_sum(array, size) << endl;
    try {
        change_k_elements(array, size);
    }
    catch (out_of_range&) {
        cout << "Going beyond";
    }
    cout << "Is there a pair of neighboring elements in the array whose product is equal to the given one? ";
    if (check_pair(array, size)) {
        cout << "yes\n";
    }
    else {
        cout << "no\n";
    }
    show_array(array, size);

    if (array != nullptr)
    {
        delete[] array;
        array = nullptr;
    }

    return 0;
}

int input_integer(const string& str) {
    int size = -1;
    cout << str;
    cin >> size;
    if (size < 0)
    {
        throw out_of_range("Incorrect size. Value has to be greater or equal zero.");
    }
    return size;
}

void auto_fill(int* array, const size_t size) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> uniformIntDistribution(-1000, 1000);
    for (int i = 0; i < size; i++) {
        array[i] = uniformIntDistribution(gen);
    }
}

void manual_fill(int* array, const size_t size) {
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }
}

int find_neg10_sum(const int* array, const size_t size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] < 0 && abs(array[i]) % 10 == 0) {
            sum += array[i];
        }
    }
    return sum;
}

void change_k_elements(int* array, const size_t size) {
    int number = 0;
    do {
        number = input_integer("Enter the number of items needed to replace =");
    } while (number > size);
    for (int i = 0; i < number / 2; i++) {
        int temp;
        temp = array[i];
        array[i] = array[number - i];
        array[number - i] = temp;
        }
    }


void Switch(int& first, int& second) {
    int temp = first;
    first = second;
    second = temp;
}

bool check_pair(const int* array, const size_t size) {
    int multi = input_integer("Enter the required product = ");
    for (int i = 0; i < size - 1; i++) {
        if (array[i] * array[i + 1] == multi) {
            return true;
        }
    }
    return false;
}

void show_array(const int* array, const size_t size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << ' ';
    }
    cout << endl;
}