#include "DxLib.h"
#include "Scenes.h"

#define STR(var) #var

SceneEnum changeScene = SceneEnum::Title;//�ύX�\�肷��V�[���B
SceneEnum nowScene = SceneEnum::Title;//���݂̃V�[���B�S�̂̏������I�������changeScene���̃V�[���ɕύX����

SceneEnum GetScene()//�V�[�����擾
{
	return nowScene;
}

void SetScene(SceneEnum _sceneEnum)
{
	changeScene = _sceneEnum;
}
bool UpdateScene()//�V�[�����X�V�B
{
	if (nowScene != changeScene)
	{
		nowScene = changeScene;
		return true;
	}
	else
	{
		return false;
	}
}