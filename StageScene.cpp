#include "StageScene.h"
#include "game.h"

void StageScene::Init()
{
	title = Novice::LoadTexture("./Resources/images/title.png");
	// ステージ
	stage = Novice::LoadTexture("./Resources/images/background.png");
	//プレイヤー
	player = Novice::LoadTexture("./Resources/images/player.png");
	playerBullet = Novice::LoadTexture("./Resources/images/playerBullet.png");
	//敵
	enemy = Novice::LoadTexture("./Resources/images/enemy.png");
	enemyBullet = Novice::LoadTexture("./Resources/images/enemyBullet.png");
	//爆発画像
	explosion = Novice::LoadTexture("./Resources/images/Explosion.png");

	//ステージ
	bgHeight = 720;
	bgPosX = 0;
	bgPosY = 0;
	bgPosY2 = bgPosY - bgHeight;
	bg1SpeedY = 5; //スクロールスピード
	bg2SpeedY = 5;
	//プレイヤー
	playerPosX = 640;
	playerPosY = 650;
	playerSpeed = 10;
	playerRadius = 16; //プレイヤーの当たり判定の大きさ
	isPlayerAlive = 1; //自機が生きているか
	playerAttackCount = 0; //攻撃を当てた回数
	//敵
	enemyPosX = 0;
	enemyPosY = 50;
	enemySpeed = 5;
	enemyRadius = 50; //敵の当たり判定の大きさ
	//敵の弾
	enemyBulletPosX = -128;
	enemyBulletPosY = -128;
	enemyBulletRadius = 10;
	enemyBulletSpeed = 3;
	isEnemyBulletShot = 0;

	enemyRespawnTimer = 120; //復活タイマー
	isEnemyAlive = 1; //敵が生きているか

	enemyBulletShootTimer = 0; // 敵の弾の発射間隔用のタイマー
	enemyBulletShootInterval = 60; // 敵の弾の発射間隔（フレーム数）

	i = 0; // iをforループの外で宣言


	for (i = 0; i < 1000; i++) {
		bullet[i].pos.x = -128.0f;
		bullet[i].pos.y = -128.0f;
		bullet[i].width = 8.0f;
		bullet[i].height = 16.0f;
		bullet[i].radius = 8.0f;
		bullet[i].speed = 8.0f;
		bullet[i].isShoot = false;
	}
}

void StageScene::Update(char* keys, char* preKeys) // 更新処理
{
	//ステージ背景のスクロール
	bgPosY += bg1SpeedY;
	bgPosY2 += bg2SpeedY;
	//画像が画面の一番下を超えたら上に移動させる
	if (bgPosY >= kWindowHeight) {
		bgPosY = bgPosY2 - bgHeight;
	}
	//画像が画面の一番下を超えたら上に移動させる
	if (bgPosY2 >= kWindowHeight) {
		bgPosY2 = bgPosY - bgHeight;
	}

	//自機 キー移動
	if (keys[DIK_A]) {
		playerPosX -= playerSpeed;
	}
	if (keys[DIK_D]) {
		playerPosX += playerSpeed;
	}

	// 単発弾の発射処理
	for (i = 0; i < 100; i++) {
		// スペースキーが押された瞬間に実行する処理（単発）
		if (!bullet[i].isShoot && keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {

			if (!bullet[i].isShoot) {
				bullet[i].isShoot = true;
				bullet[i].pos.x = (float)playerPosX;
				bullet[i].pos.y = (float)playerPosY;
				bullet[i].speed = 10;
				break;
			}
		}
		//}
		if (bullet[i].pos.y < -15) { //2発目以降を撃てるようにする処理
			bullet[i].isShoot = false;

		}

	}
	enemyBulletShootTimer++; // タイマーをインクリメント

	if (enemyBulletShootTimer >= enemyBulletShootInterval) {
		// 一定の間隔で弾を発射する処理
		enemyBulletPosX = enemyPosX + 20;
		enemyBulletPosY = enemyPosY + 20; // 敵の位置から下に向かって発射
		enemyBulletSpeed = 10; // 下向きに移動させる速度を設定
		isEnemyBulletShot = true;

		// タイマーをリセット
		enemyBulletShootTimer = 0;
	}

	// 弾の移動
	for (i = 0; i < 100; i++) {
		if (bullet[i].isShoot) {
			bullet[i].pos.y -= bullet[i].speed; // プレイヤーの弾の位置を変更
		}
	}


	//当たり判定 - 敵と自機の弾
	for (i = 0; i < 100; i++) {
		if (bullet[i].isShoot) {
			if (isEnemyAlive && bullet[i].isShoot) { //敵が生きているかつ自機の弾が発射されている
				//二点間の距離を計算
				int bulletToEnemyX = enemyPosX - (int)bullet[i].pos.x;
				int bulletToEnemyY = enemyPosY - (int)bullet[i].pos.y;
				//衝突しているか
				if ((enemyRadius + bullet[i].radius) * (enemyRadius + bullet[i].radius)
					>= (bulletToEnemyX * bulletToEnemyX) + (bulletToEnemyY * bulletToEnemyY)) {
					isEnemyAlive = 0;
					bullet[i].isShoot = 0;
					playerAttackCount++;

					//3回攻撃を当てたらゲームクリア
					if (playerAttackCount >= 3) {

						bullet[i].pos.x = -128.0f;
						bullet[i].pos.y = -128.0f;
						bullet[i].width = 8.0f;
						bullet[i].height = 16.0f;
						bullet[i].radius = 8.0f;
						bullet[i].speed = 8.0f;

						//リセット
						bullet[i].isShoot = false;
						enemyBulletPosX = -128;
						enemyBulletPosY = -128;
						enemyBulletSpeed = 0;
						isEnemyBulletShot = 0;

						sceneNo = CLEAR;
					}


				}
			}
		}
	}


	//当たり判定 - 自機と敵の弾
	if (isPlayerAlive && isEnemyBulletShot) { //自機が生きているかつ敵の弾が発射されている
		int playerToBulletX = playerPosX - enemyBulletPosX;
		int playerToBulletY = playerPosY - enemyBulletPosY;

		// 衝突判定（円と円の衝突判定）
		if ((playerRadius + enemyBulletRadius) * (playerRadius + enemyBulletRadius) >=
			(playerToBulletX * playerToBulletX) + (playerToBulletY * playerToBulletY)) {
			isPlayerAlive = 0; // プレイヤー死亡

			//攻撃を受けたらゲームオーバー
			if (isPlayerAlive == 0) {
				//初期化
				enemyBulletPosX = -128;
				enemyBulletPosY = -128;
				enemyBulletSpeed = 0;
				isEnemyBulletShot = 0;
				//ゲームオーバー画面に移動
				sceneNo = GAMEOVER;
			}
		}

		//リスポーン
		if (!isEnemyAlive) { //敵が死んでいるか
			enemyRespawnTimer--; //復活用タイマーを1減らす
			if (enemyRespawnTimer <= 0) { //復活用タイマーが0以下か
				isEnemyAlive = true; //敵フラグを1に変更
				enemyRespawnTimer = 120; //復活用タイマーを120に戻す
				enemySpeed = 5;

				// 敵の弾を初期化
				enemyBulletPosX = -128;
				enemyBulletPosY = -128;
				enemyBulletSpeed = 0;
				isEnemyBulletShot = false;
			}
		}
	}


	//弾の移動
	enemyBulletPosY = enemyBulletPosY + enemyBulletSpeed;

	//敵の移動
	enemyPosX = enemyPosX + enemySpeed;
	if (isEnemyAlive) {
		enemyPosX += enemySpeed; //フラグが立ってるなら敵を動かす

		if (enemyPosX >= 1280 - enemyRadius) { //右端での反射
			enemySpeed *= -1;
		}
		if (enemyPosX <= 0) { //左端での反射
			enemySpeed *= -1;
		}
	}


	//画面外に行かせない処理
	if (playerPosX > kWindowWidth - playerRadius) {
		playerPosX = kWindowWidth - playerRadius;
		//playerSpeed = 0;
	}
	if (playerPosX < playerRadius) {
		playerPosX = playerRadius;
		//playerSpeed = 0;
	}

}

void StageScene::Draw() // 描画処理
{
	
	Novice::DrawSprite(bgPosX, bgPosY, stage, 1, 1, 0, WHITE);
	Novice::DrawSprite(bgPosX, bgPosY2, stage, 1, 1, 0, WHITE);

	//プレイヤーの描画
	Novice::DrawSprite(playerPosX - playerRadius, playerPosY - playerRadius, player, 1, 1, 0.0f, WHITE);

	//弾の描画
	for (i = 0; i < 100; i++) {
		if (bullet[i].isShoot) {
			Novice::DrawSprite((int)bullet[i].pos.x, (int)bullet[i].pos.y, playerBullet, 1, 1, 0.0f, WHITE); //自機の弾
		}
	}

	Novice::DrawSprite(enemyBulletPosX, enemyBulletPosY, enemyBullet, 1, 1, 0.0f, WHITE); //敵の弾

	//敵の描画
	if (isEnemyAlive) { //敵が生きている場合に描画
		Novice::DrawSprite(enemyPosX, enemyPosY, enemy, 1, 1, 0.0f, WHITE);
	}

	//撃破直後のみ爆発画像に差し替え
	if (!isEnemyAlive) { //敵が死んでいるか
		enemyRespawnTimer--;
		if (enemyRespawnTimer <= 120 || enemyRespawnTimer >= 90) {
			Novice::DrawSprite(enemyPosX, enemyPosY, explosion, 1.0f, 1.0f, 0.0f, WHITE);
			enemySpeed = 0;
		}
	}

	
	//Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLUE, kFillModeSolid);
	//Novice::ScreenPrintf(600, 300, "STAGE");
	//Novice::ScreenPrintf(600, 400, "PRESS SPACE");
}

