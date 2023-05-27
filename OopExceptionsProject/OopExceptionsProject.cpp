#include <iostream>

class Exception
{
    std::string message;
public:
    Exception(std::string message = "error") : message{ message } {}
    std::string Message() { return message; }
};

enum ErrorCode
{
    OutOfRange,
    DivideByZero
};

class Fraction
{
    int numerator;
    int denominator;
public:
    Fraction(int numerator, int denominator) : numerator{ numerator }
    {
        if (denominator == 0)
            throw new Exception("divide by zero");

        this->denominator = denominator;
    }
    int& Numerator() { return this->numerator; }
    void SetDenominator(int d)
    {
        if (d == 0)
            throw new Exception("divide by zero");
        this->denominator = d;
    }
};

void C()
{
    std::cout << "C start\n";
    throw 1;
    std::cout << "C finish\n";
}

void B()
{
    std::cout << "B start\n";
    C();
    std::cout << "B finish\n";
}


void A()
{
    std::cout << "A start\n";
    try
    {
        B();
    }
    catch (...)
    {
        std::cout << "A catch exception!\n";
        throw;
    }
    std::cout << "A finish\n";
}

int main()
{
    /*
    Fraction f(5, 2);
    try
    {
        f.SetDenominator(0);
    }
    catch (ErrorCode e)
    {
        std::cout << "enum exception! error! divide by zero\n";
    }
    catch (int e)
    {
        std::cout << "int exception! error! divide by zero\n";
    }
    catch (Exception* e)
    {
        std::cout << e->Message() << "\n";
    }
    catch (...)
    {
        std::cout << "uniform exception! error! divide by zero\n";
    }

    std::cout << "other code...\n";
    std::cout << f.Numerator();
    */
    
    std::cout << "main start\n";
    try {
        A();
    }
    catch (...)
    {
        std::cout << "main catch exception!\n";
    }

    std::cout << "main finish\n";
}
