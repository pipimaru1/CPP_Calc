#define NOMINMAX
#include <iostream>
#include <limits>
#include <windows.h>
#include <string>
#include <sstream>
#include <cmath> // pow用

///////////////////////////////////////////////////////////////////////
// 計算クラス
class Calc
{
private:
    double num1;
    double num2;
    double answer;
    char op;
    bool validOp;

    void showErrorMessage(const std::wstring& message) const;

public:
    Calc();

    void setNum1(double n);
    void setNum2(double n);
    void setOp(char o);

    double getNum1() const;
    double getNum2() const;
    double getAnswer() const;
    char getOp() const;

    double plus();
    double minus();
    double multiply();
    double divide();
    double power();  // べき乗追加

    double Proc();
    std::wstring getResultString() const;
	int displayResultBox() const;
    int displayResultCon() const;
};

////////////////////////////////
// コンストラクタ
Calc::Calc()
    : num1(0.0), num2(0.0), answer(0.0), op('\0'), validOp(false)
{
}

//////////////////////////////////////////////////////////////////////
// メンバ関数の定義
void Calc::setNum1(double n) { num1 = n; }
void Calc::setNum2(double n) { num2 = n; }
void Calc::setOp(char o) { op = o; }

double Calc::getNum1() const { return num1; }
double Calc::getNum2() const { return num2; }
double Calc::getAnswer() const { return answer; }
char Calc::getOp() const { return op; }

void Calc::showErrorMessage(const std::wstring& message) const
{
    MessageBoxW(NULL, message.c_str(), L"Error", MB_OK);
}

double Calc::plus()
{
    answer = num1 + num2;
    validOp = true;
    return answer;
}

double Calc::minus()
{
    answer = num1 - num2;
    validOp = true;
    return answer;
}

double Calc::multiply()
{
    answer = num1 * num2;
    validOp = true;
    return answer;
}

double Calc::divide()
{
    if (num2 == 0)
    {
        showErrorMessage(L"Error: Division by zero is undefined.");
        validOp = false;
        return 0.0;
    }
    answer = num1 / num2;
    validOp = true;
    return answer;
}

double Calc::power()
{
    answer = std::pow(num1, num2);
    validOp = true;
    return answer;
}

//////////////////////////////////////////////////////////////////////
// 計算実行処理
// Proc関数は演算子に応じて適切な計算メソッドを呼び出す
// プロシージャ
double Calc::Proc()
{
    // validOpは各演算関数で設定される
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
        case '^': 
            return power();  // べき乗
        default:
            showErrorMessage(L"Error: Unknown operator.");
            validOp = false;
            return 0.0;
    }
}
//////////////////////////////////////////////////////////////////////
// 計算結果を文字列として取得
std::wstring Calc::getResultString() const
{
    if (validOp)
    {
        std::wostringstream res;
        res << num1 << L" " << op << L" " << num2 << L" = " << answer;
        return res.str();
    }
    else
    {
        return L"Error: Calculation failed.";
    }
}
//////////////////////////////////////////////////////////////////////
// 計算結果をメッセージボックスで表示
int Calc::displayResultBox() const
{
	if (validOp)
	{
        std::wstring res = getResultString();

		MessageBoxW(NULL, res.c_str(), L"計算結果", MB_OK);
	}
	else
	{
		showErrorMessage(L"Error: Calculation failed.");
	}
    return 0;
}
//////////////////////////////////////////////////////////////////////
// 計算結果をコンソールに表示
int Calc::displayResultCon() const
{
	if (validOp)
	{
		std::wcout << getResultString() << std::endl;
	}
	else
	{
		showErrorMessage(L"Error: Calculation failed.");
	}
    return 0;
}


////////////////////////////////////////////////////
// メイン関数
// メイン関数は処理の流れがわかるようにするのが定石
int main()
{
    Calc calc;

    std::wcout.imbue(std::locale("Japanese"));

    std::wcout << L"\n--- 簡易電卓 ---\n";
    std::wcout << L"式を入力してください（例: 5 + 3）\n";
    std::wcout << L"対応演算子: + - * / ^\n";
    std::wcout << L"終了するには 'q' を入力してください\n\n";

	//ここからループ
    while (true)
    {
        std::wstring input;
        std::wcout << L"> ";
        std::getline(std::wcin, input);

        if (input == L"q" || input == L"Q") {
            break;
        }

        std::wstringstream ss(input);
        double num1, num2;
        wchar_t op;

        ss >> num1 >> op >> num2;

        if (ss.fail()) {
            MessageBoxW(NULL, L"入力形式が正しくありません。例: 5 + 3", L"入力エラー", MB_OK);
            continue;
        }

        //パラメータのセット
        calc.setNum1(num1);
        calc.setNum2(num2);
        calc.setOp(static_cast<char>(op));

		//計算を実行(プロシージャ)
        calc.Proc();
        
		//結果を表示
        calc.displayResultCon();
        calc.displayResultBox();
    }

    return 0;
}

////////////////////////////////////////////////////////
// 課題: sin.cos,tan 計算を行うメンバ関数を追加してください。
// sin(30) のような形を扱うには、opに's'を使う？ 引数の数をどう管理する？
// それとも、"sin 30" という形式を入力させる？

////////////////////////////////////////////////////////
// 課題: 3要素以上の計算を行う機能を追加してください。
//　ヒント:メンバ関数の追加だけでは不可能です。全体のフロー設計の改変が必要です。

////////////////////////////////////////////////////////
// 課題：直前の計算結果を次の計算に使えるようにしてください。
// 例）5 + 3 → 8（保存）→ + 2 → 10
