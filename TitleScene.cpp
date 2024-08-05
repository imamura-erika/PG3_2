#include "TitleScene.h"
#include "game.h"

void TitleScene::Init()
{
	title = Novice::LoadTexture("./Resources/images/title.png");
}

void TitleScene::Update(char* keys, char* preKeys) // 更新処理
{
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		sceneNo = EXPLAIN; //スペースが押されたら説明画面へ
	}
}

void TitleScene::Draw() // 描画処理
{
	Novice::DrawSprite(0, 0, title, 1, 1, 0, WHITE);
}