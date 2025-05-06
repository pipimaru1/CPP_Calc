#define NOMINMAX
#include <iostream>
#include <limits>
#include <windows.h> // For MessageBox
#include <string>   // For std::to_string
#include <sstream>  // For std::ostringstream

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
			    ///////////////////////////////////////////////////////////////////////////////
			    //課題1 ここもメッセージボックスを使用してエラーメッセージを表示するように変更
			    //課題2 UTF-16(日本語)に対応するため、全ての入出力、文字列をwchar_t型対応に変更
                std::cout << "Error: Unknown operator '" << op << "'. Supported operators are +, -, *, /." << std::endl;
                validOp = false;
                break;
        }

        if (validOp)
        {
            //////////////////////////////////////////////////
			// 出力ストリームを使用して計算結果の文字列を作成
			std::wostringstream _res;
			_res << num1 << L" " << op << L" " << num2 << L" = " << result;

            //////////////////////////////////////////////////
            // MessageBoxWを使用して計算結果を表示
			MessageBoxW(NULL, _res.str().c_str(), L"計算結果", MB_OK);
        }

        // Clear input buffer before next iteration
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Calculator terminated. Goodbye!" << std::endl;
    return 0;
}

// 宿題 Calcクラスを作成し、main関数を簡素化しなさい。
// クラスに以下の機能を持たせること。
//  - 数値入力の処理
//  - 演算処理（+ - * /）
//  - 結果の出力
//  - エラー処理（0除算、無効な演算子など）
//  - エラーメッセージはMessageBoxWを使用して表示すること。
//  - UTF-16(日本語)に対応するため、全ての入出力、文字列をwchar_t型対応に変更すること。
//  - chatGPTを使っても構いませんが、main()関数で行うべき処理と、クラスで行うべき処理を分けてください。
// 　 chatGPTを使っても、コード全体のバランスは人間が考える必要があります。
//  - メンバ関数やコンストラクタの役割も明記し、
//    構造と処理の関係を意識してコードを作成すること。