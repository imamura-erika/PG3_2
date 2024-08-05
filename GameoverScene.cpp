#include "GameoverScene.h"
#include "game.h"

void GameoverScene::Init()
{
	loseImage = Novice::LoadTexture("./Resources/images/gameOver.png");
}

void GameoverScene::Update(char* keys, char* preKeys) // 更新処理
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

void GameoverScene::Draw() // 描画処理
{
	Novice::DrawSprite(0, 0, loseImage, 1, 1, 0, WHITE);
}
