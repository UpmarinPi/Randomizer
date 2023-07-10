#include "DxLib.h"
#include "Scenes.h"

#define STR(var) #var

SceneEnum changeScene = SceneEnum::Title;//変更予定するシーン。
SceneEnum nowScene = SceneEnum::Title;//現在のシーン。全体の処理が終わったらchangeScene内のシーンに変更する

SceneEnum GetScene()//シーンを取得
{
	return nowScene;
}

void SetScene(SceneEnum _sceneEnum)
{
	changeScene = _sceneEnum;
}
bool UpdateScene()//シーンを更新。
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