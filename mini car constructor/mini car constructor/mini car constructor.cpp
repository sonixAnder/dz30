#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Структура для описания автомобиля
struct Car
{
    double length;         // Длина (в метрах)
    double clearance;      // Клиренс (высота посадки, в метрах)
    double engineVolume;   // Объем двигателя (в литрах)
    int enginePower;       // Мощность двигателя (в лошадиных силах)
    int wheelDiameter;     // Диаметр колес (в дюймах)
    string color;     // Цвет
    string gearbox;   // Тип коробки передач (например, "механика", "автомат")
};

// Функция для задания значений автомобиля
void setCarValues(Car& car)
{
    cout << "Введите длину автомобиля (в метрах): ";
    cin >> car.length;

    cout << "Введите клиренс (в метрах): ";
    cin >> car.clearance;

    cout << "Введите объем двигателя (в литрах): ";
    cin >> car.engineVolume;

    cout << "Введите мощность двигателя (в л.с.): ";
    cin >> car.enginePower;

    cout << "Введите диаметр колес (в дюймах): ";
    cin >> car.wheelDiameter;

    cout << "Введите цвет: ";
    cin >> car.color;

    cout << "Введите тип коробки передач: ";
    cin >> car.gearbox;
}

// Функция для отображения значений автомобиля
void displayCarValues(const Car& car)
{
    cout << "Длина: " << car.length << " м" << endl;
    cout << "Клиренс: " << car.clearance << " м" << endl;
    cout << "Объем двигателя: " << car.engineVolume << " л" << endl;
    cout << "Мощность двигателя: " << car.enginePower << " л.с." << endl;
    cout << "Диаметр колес: " << car.wheelDiameter << "\"" << endl;
    cout << "Цвет: " << car.color << endl;
    cout << "Коробка передач: " << car.gearbox << endl;
}

// Функция для поиска автомобилей по цвету
vector<Car> searchByColor(const vector<Car>& cars, const string& color)
{
    vector<Car> foundCars;
    for (const Car& car : cars)
    {
        if (car.color == color)
        {
            foundCars.push_back(car);
        }
    }
    return foundCars;
}

int main()
{
    setlocale(LC_ALL, "ru");
    vector<Car> cars;

    while (true) {
        cout << "\nВыберите действие:\n";
        cout << "1. Добавить автомобиль\n";
        cout << "2. Отобразить информацию об автомобиле\n";
        cout << "3. Поиск автомобилей по цвету\n";
        cout << "4. Выход\n";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        { // Добавить автомобиль
            Car newCar;
            setCarValues(newCar);
            cars.push_back(newCar);
            cout << "Автомобиль добавлен!\n";
            break;
        }
        case 2:
        { // Отобразить информацию об автомобиле
            if (cars.empty())
            {
                cout << "Список автомобилей пуст.\n";
            }
            else
            {
                cout << "Введите номер автомобиля (1-" << cars.size() << "): ";
                int index;
                cin >> index;
                if (index >= 1 && index <= cars.size())
                {
                    displayCarValues(cars[index - 1]);
                }
                else
                {
                    cout << "Неверный номер автомобиля.\n";
                }
            }
            break;
        }
        case 3:
        { // Поиск автомобилей по цвету
            string color;
            cout << "Введите цвет для поиска: ";
            cin >> color;
            vector<Car> foundCars = searchByColor(cars, color);
            if (foundCars.empty())
            {
                cout << "Автомобили с таким цветом не найдены.\n";
            }
            else
            {
                cout << "Найденные автомобили:\n";
                for (const Car& car : foundCars)
                {
                    displayCarValues(car);
                }
            }
            break;
        }
        case 4: // Выход
            return 0;
        default:
            cout << "Неверный выбор.\n";
        }
    }

    return 0;
}