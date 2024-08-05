#include "ClearScene.h"
#include "game.h"

void ClearScene::Init()
{
	winImage = Novice::LoadTexture("./Resources/images/clear.png"); //勝利背景
}

void ClearScene::Update(char* keys, char* preKeys) // 更新処理
{
	//ボタン選択
	if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
		plessToTitle = 1; //タイトルが選択された

	}
	if (plessToTitle == 1) {
		plessToTitle = 0;
		sceneNo = TITLE; //タイトル画面へ
	}
}

void ClearScene::Draw() // 描画処理
{
	Novice::DrawSprite(0, 0, winImage, 1, 1, 0, WHITE);
}
