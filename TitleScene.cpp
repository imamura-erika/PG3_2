#include "TitleScene.h"

void TitleScene::Init()
{
}

void TitleScene::Update(char* keys, char* preKeys) // 更新処理
{
	// シーン切り替え
	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE]) { // スペースを押したら
		sceneNo = STAGE; // ステージ画面へ
	}
}

void TitleScene::Draw() // 描画処理
{
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);
	Novice::ScreenPrintf(600, 300, "TITLE");
	Novice::ScreenPrintf(600, 400, "PRESS SPACE");
}
