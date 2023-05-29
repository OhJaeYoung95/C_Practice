#include <iostream>

// 클래스 템플릿
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

// 함수 템플릿
template <typename T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    // 클래스 템플릿 사용 예제
    Pair<int> intPair(10, 20);
    std::cout << "First: " << intPair.getFirst() << ", Second: " << intPair.getSecond() << std::endl;

    Pair<std::string> stringPair("Hello", "World");
    std::cout << "First: " << stringPair.getFirst() << ", Second: " << stringPair.getSecond() << std::endl;

    // 함수 템플릿 사용 예제
    int num1 = 10, num2 = 20;
    std::cout << "Max: " << getMax(num1, num2) << std::endl;

    double num3 = 3.14, num4 = 2.71;
    std::cout << "Max: " << getMax(num3, num4) << std::endl;

    return 0;
}