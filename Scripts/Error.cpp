#include "Error.h"

bool errorFlag = false;

bool GetErrorFlag()
{
	return errorFlag;
}

/// <summary>
/// �G���[��\��������֐�
/// </summary>
/// <param name="endFlag">���̊֐����Ăяo�������_�ŋ�����true�ɂȂ�</param>
/// 
void Error()
{
	//�G���[���ǉ��\��

	errorFlag = true;
}