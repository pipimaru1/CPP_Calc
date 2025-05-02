#include <iostream>
#include <limits>

/////////////////////////////////////////////////////////////////
//　課題1: 下記のコードを読んでフローチャートを作成してください。

int main()
{
    double num1 = 0.0, num2 = 0.0;
    char op = '\0';

    while (true)
    {
        /////////////////////////////////////////////////////////////////
        //使い方を表示
        std::cout << "Enter an expression (e.g., 2 + 3) or 'q' to quit: ";

		// 入力を数値変数に格納
        if (!(std::cin >> num1)) 
        {
            //数値変換に失敗したら
            std::cin.clear();
            char c;
            std::cin >> c;
			// qかQが入力された場合、ループを終了
            if (c == 'q' || c == 'Q')
            {
				//ループを終了
                break;
            }
			//それ以外の文字が入力された場合、エラーメッセージを表示
            else
            {
                std::cout << "Invalid input. Please try again." << std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				//ループの先頭に戻る
                continue;
            }
        }
		//二番目の入力は演算子
        std::cin >> op;

		//三番目の入力は数値
        if (!(std::cin >> num2))
        {
			//数値変換に失敗したらエラーメッセージを表示
            std::cout << "Invalid second operand. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            //ループの先頭に戻る
            continue;
        }
		//演算結果を格納する変数
        double result = 0.0;
        bool validOp = false;

        ///////////////////////////////////////////////////////////////
        //計算処理
		//演算子の種類によって処理を分岐
        switch (op)
        {
            case '+':
                result = num1 + num2;
			    validOp = true;
                break;
            case '-':
                result = num1 - num2;
                validOp = true;
                break;
            case '*':
                result = num1 * num2;
                validOp = true;
                break;
            case '/':
			    ///////////////////////////////////////////////////////////
			    //課題3: num2が0のとき、エラーメッセージを
                // 　　　表示するようにコードを追加してください
                //       計算結果は0.0にしてください。
                result = num1 / num2;
                validOp = true;
                break;
            default:
			    //課題4: エラーメッセージを表示するコードをcase文の外に出し一か所にまとめてください。
                std::cout << "Error: Unknown operator '" << op << "'. Supported operators are +, -, *, /." << std::endl;
                validOp = false;
                break;
        }
        ///////////////////////////////////////////////////////////
		//課題2: validOpの役割は何ですか？
        if (validOp)
        {
            std::cout << "Result: " << result << std::endl;
        }

		//インプットバッファをクリア    
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Calculator terminated. Goodbye!" << std::endl;
    return 0;
}
