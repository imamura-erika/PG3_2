#include "Player.h"

// コンストラクタ
Player::Player() :pos_x(100), pos_y(100), speed_(5) {}

void Player::Init() // 初期化
{
}

void Player::Update() // 更新
{
}

void Player::Draw() // 描画
{
	// オブジェクトの描画
	Novice::DrawBox(pos_x, pos_y, 50, 50, 0.0f, WHITE, kFillModeSolid);
}

void Player::MoveLeft() // 左移動
{
	this->pos_x -= this->speed_;
}

void Player::MoveRight() // 右移動
{
	this->pos_x += this->speed_;
}