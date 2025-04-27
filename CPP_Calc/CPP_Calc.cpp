//このテキストをそっくりコピーして貼り付ける

#include <iostream>
#include <limits>

int main()
{
    double num1 = 0.0, num2 = 0.0;
    char op = '\0';

    while (true)
    {
        std::cout << "Enter an expression (e.g., 2 + 3) or 'q' to quit: ";
        if (!(std::cin >> num1))
        {
            // Check if user entered 'q' to quit
            std::cin.clear();
            char c;
            std::cin >> c;
            if (c == 'q' || c == 'Q')
            {
                break;
            }
            else
            {
                std::cout << "Invalid input. Please try again." << std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
        }

        std::cin >> op;

        if (!(std::cin >> num2))
        {
            std::cout << "Invalid second operand. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        double result = 0.0;
        bool validOp = true;

        switch (op)
        {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0)
            {
                std::cout << "Error: Division by zero is undefined." << std::endl;
                validOp = false;
            }
            else
            {
                result = num1 / num2;
            }
            break;
        default:
            std::cout << "Error: Unknown operator '" << op << "'. Supported operators are +, -, *, /." << std::endl;
            validOp = false;
            break;
        }

        if (validOp)
        {
            std::cout << "Result: " << result << std::endl;
        }

        // Clear input buffer before next iteration
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Calculator terminated. Goodbye!" << std::endl;
    return 0;
}
