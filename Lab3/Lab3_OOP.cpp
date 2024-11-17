#include <iostream>
#include <vector>
#include "matplotlibcpp.h" // підключення зовнішньої бібліотеки

namespace plt = matplotlibcpp;

int main() {
    // Приклад побудови графіка
    try {
        std::cout << "Побудова графіка функції y = sin(x)...\n";

        // Створення даних
        std::vector<double> x, y;
        for (double i = 0; i <= 2 * M_PI; i += 0.1) {
            x.push_back(i);
            y.push_back(sin(i));
        }

        // Налаштування графіка
        plt::title("Графік функції y = sin(x)");
        plt::xlabel("x");
        plt::ylabel("y");

        // Побудова графіка
        plt::plot(x, y, {{"color", "blue"}, {"label", "y = sin(x)"}});
        plt::legend();

        // Збереження графіка у файл
        std::string filename = "plot.png";
        plt::save(filename);
        std::cout << "Графік збережено у файл: " << filename << "\n";

        // Показати графік
        plt::show();
    } catch (const std::exception& ex) {
        std::cerr << "Помилка: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}
