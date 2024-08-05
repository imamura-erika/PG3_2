#pragma once
#include "game.h"

int title;
int explain;
int winImage; //勝利背景
int loseImage; //敗北背景

// ステージ
int stage;
//プレイヤー
int player;
int playerBullet;

//敵
int enemy;
int enemyBullet;

//爆発画像
int explosion;

const int kWindowWidth = 1280;
const int kWindowHeight = 720;

//typedef struct Bullet {
//	Vector2 pos;
//	float width;
//	float height;
//	float radius;
//	float speed;
//	int isShoot;
// Bullet;

//ステージ
int bgHeight;
int bgPosX;
int bgPosY;
int bgPosY2;
int bg1SpeedY; //スクロールスピード
int bg2SpeedY;

//プレイヤー
int playerPosX;
int playerPosY;
int playerSpeed;
int playerRadius; //プレイヤーの当たり判定の大きさ

// 弾の変数
Bullet bullet[1000];


int isPlayerAlive; //自機が生きているか
int playerAttackCount; //攻撃を当てた回数

//敵
int enemyPosX;
int enemyPosY;
int enemySpeed;
int enemyRadius; //敵の当たり判定の大きさ
//敵の弾
int enemyBulletPosX;
int enemyBulletPosY;
int enemyBulletRadius;
int enemyBulletSpeed;
bool isEnemyBulletShot;

int enemyRespawnTimer; //復活タイマー
int isEnemyAlive; //敵が生きているか

int enemyBulletShootTimer; // 敵の弾の発射間隔用のタイマー
int enemyBulletShootInterval; // 敵の弾の発射間隔（フレーム数）

int i; // iをforループの外で宣言

int plessToTitle;