#define NOMINMAX
#include <iostream>
#include <limits>
#include <windows.h> // For MessageBox
#include <string>   // For std::to_string
#include <sstream>  // For std::ostringstream


class Calc
{
	//課題: メンバ変数の初期化をコンストラクタで行うようにしてください。
private:
    double num1 = 0.0;
    double num2 = 0.0;
    double answer = 0.0;
    char op = '\0';
    bool validOp = false;

public:
    void setNum1(double n) { num1 = n; }
    void setNum2(double n) { num2 = n; }
    void setOp(char o) { op = o; }

    double getNum1() const { return num1; }
    double getNum2() const { return num2; }
    double getAnswer() const { return answer; }
    char getOp() const { return op; }

	//課題: メンバ関数の定義をクラスの外に出してください。
    //課題: べき乗計算を行うメンバ関数を追加してください。
    double plus()
    {
        answer = num1 + num2;
		validOp = true;
        return answer;
    }
    double minus()
    {
        answer = num1 - num2;
        validOp = true;
        return answer;
    }
    double multiply()
    {
        answer = num1 * num2;
        validOp = true;
        return answer;
    }
    double divide()
    {
        if (num2 == 0)
        {
			//課題: エラーメッセージ処理は一か所にまとめてください。
            MessageBoxW(NULL, L"Error: Division by zero is undefined.", L"Error", MB_OK);
            validOp = false;
            return 0.0;
        }
        else
        {
            answer = num1 / num2;
			validOp = true;
            return answer;
        }
    }
    
	//計算を実行
	double run()
	{
		//課題: validOpの初期化はここで良いか検討してください。
        validOp = false;
        switch (op)
        {
        case '+':
            return plus();
        case '-':
            return minus();
        case '*':
            return multiply();
        case '/':
            return divide();
		default:
			MessageBoxW(NULL, L"Error: Unknown operator.", L"Error", MB_OK);
			return 0.0;
        }
    }
	
	std::wstring getResultString()
	{
		//課題: 計算が成功した場合のみ、計算結果を表示するようにしてください。
		//課題: 計算が成功していない場合、エラーメッセージを表示するようにしてください。
		std::wostringstream _res;
		_res << num1 << L" " << op << L" " << num2 << L" = " << answer;
		return _res.str();
	}
};

int main()
{
	//課題: Calcクラスを使って計算を行うようにしてください。


    return 0;
}
