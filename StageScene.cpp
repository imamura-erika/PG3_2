#include "StageScene.h"

void StageScene::Init()
{
}

void StageScene::Update(char* keys, char* preKeys) // 更新処理
{
	// シーン切り替え
	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE]) { // スペースを押したら
		sceneNo = CLEAR; // クリア画面へ
	}
}

void StageScene::Draw() // 描画処理
{
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLUE, kFillModeSolid);
	Novice::ScreenPrintf(600, 300, "STAGE");
	Novice::ScreenPrintf(600, 400, "PRESS SPACE");
}

