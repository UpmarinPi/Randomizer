#include "Error.h"

bool errorFlag = false;

bool GetErrorFlag()
{
	return errorFlag;
}

/// <summary>
/// エラーを表示させる関数
/// </summary>
/// <param name="endFlag">この関数を呼び出した時点で強制でtrueになる</param>
/// 
void Error()
{
	//エラー文追加予定

	errorFlag = true;
}