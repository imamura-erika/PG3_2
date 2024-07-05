#include "ClearScene.h"

void ClearScene::Init()
{
}

void ClearScene::Update(char* keys, char* preKeys) // 更新処理
{
	// シーン切り替え
	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE]) { // スペースを押したら
		sceneNo = TITLE; // タイトル画面へ
	}
}

void ClearScene::Draw() // 描画処理
{
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, GREEN, kFillModeSolid);
	Novice::ScreenPrintf(600, 300, "CLEAR");
	Novice::ScreenPrintf(600, 400, "PRESS SPACE");
}
