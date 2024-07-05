#include "GameManager.h"

GameManager::GameManager() // コンストラクタの定義
{
	// 各シーンの配列
	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	sceneArr_[STAGE] = std::make_unique<StageScene>();
	sceneArr_[CLEAR] = std::make_unique<ClearScene>();

	// 初期シーン
	currentSceneNo_ = TITLE;
}

GameManager::~GameManager() // デストラクタ
{
}

int GameManager::Run(char* keys, char* preKeys) // ゲームループ
{
//	while (Novice::ProcessMessage() == 0) {
//		Novice::BeginFrame(); // フレームの開始

		// シーンのチェック
		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

		// シーン変更チェック
		if (prevSceneNo_ != currentSceneNo_) {
			sceneArr_[currentSceneNo_]->Init();
		}

		/// 更新処理
		sceneArr_[currentSceneNo_]->Update(keys, preKeys); // シーンごとの更新処理

		/// 描画処理
		sceneArr_[currentSceneNo_]->Draw(); // シーンごとの描画処理

//		Novice::EndFrame(); // フレームの終了

//		// ESCキーが押されたらループを抜ける
//		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
//			break;
//		}
//	}

	return 0;
}
