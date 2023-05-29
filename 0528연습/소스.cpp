#include <iostream>

// Ŭ���� ���ø�
template <typename T>
class Pair {
private:
    T first;
    T second;

public:
    Pair(T f, T s) : first(f), second(s) {}

    T getFirst() const { return first; }
    T getSecond() const { return second; }
};

// �Լ� ���ø�
template <typename T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    // Ŭ���� ���ø� ��� ����
    Pair<int> intPair(10, 20);
    std::cout << "First: " << intPair.getFirst() << ", Second: " << intPair.getSecond() << std::endl;

    Pair<std::string> stringPair("Hello", "World");
    std::cout << "First: " << stringPair.getFirst() << ", Second: " << stringPair.getSecond() << std::endl;

    // �Լ� ���ø� ��� ����
    int num1 = 10, num2 = 20;
    std::cout << "Max: " << getMax(num1, num2) << std::endl;

    double num3 = 3.14, num4 = 2.71;
    std::cout << "Max: " << getMax(num3, num4) << std::endl;

    return 0;
}