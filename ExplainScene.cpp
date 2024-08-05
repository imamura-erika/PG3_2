#include "ExplainScene.h"
#include "game.h"

void ExplainScene::Init()
{
	explain = Novice::LoadTexture("./Resources/images/explain2.png");
}

void ExplainScene::Update(char* keys, char* preKeys) // 更新処理
{
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		sceneNo = STAGE; //スペースが押されたらゲーム開始
		//スクロール初期位置の初期化
		bgPosY = 0;
		bgPosY2 = bgPosY - bgHeight;

	}
}

void ExplainScene::Draw() // 描画処理
{
	Novice::DrawSprite(0, 0, explain, 1, 1, 0, WHITE);
}