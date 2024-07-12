#include "StageScene.h"

// コンストラクタ
StageScene::StageScene() :inputHandler_(nullptr), player_(nullptr) {}

StageScene::~StageScene() // デストラクタ
{
}

void StageScene::Init() // 初期化
{
	inputHandler_ = new InputHandler();
	
	// キーにコマンドを割り当て
	inputHandler_->AssignMoveLeftCommand2PressKeyA();
	inputHandler_->AssignMoveRightCommand2PressKeyD();

	player_ = new Player();
}

void StageScene::Update() // 更新
{
	// 入力の確認
	iCommand_ = inputHandler_->HandleInput();

	// 対象コマンドの実行
	if (this->iCommand_) {
		iCommand_->Exec(*player_);
	}

	player_->Update(); // 呼び出し プレイヤーの更新
}

void StageScene::Draw() // 描画
{
	player_->Draw(); // 呼び出し プレイヤーの描画
}
