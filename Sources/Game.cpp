#include "Game.hpp"

Game::Game() {
	this->inputKey = 0;
	this->currentState = State::TITLE;
	this->deck = new Deck();
	this->player = new Player();
	this->dealer = new Person();
	this->startTime = std::chrono::system_clock::now();
	this->endTime = std::chrono::system_clock::now();
	this->resultTime = std::chrono::duration<double>(0.0);
}

Game::~Game() {
	delete this->deck;
	delete this->player;
	delete this->dealer;
}

/*
* @brief ゲームの状態に応じた画面の描画をする。
*/
void Game::Display() const {
	this->DisplayClear();

	switch (this->currentState) {
	case State::TITLE:
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayLine(" ######  ########  ######## ######## ########     ########  ##          ###     ######  ##    ##       ##    ###     ######  ##    ##");
		this->DisplayLine("##    ## ##     ## ##       ##       ##     ##    ##     ## ##         ## ##   ##    ## ##   ##        ##   ## ##   ##    ## ##   ## ");
		this->DisplayLine("##       ##     ## ##       ##       ##     ##    ##     ## ##        ##   ##  ##       ##  ##         ##  ##   ##  ##       ##  ##  ");
		this->DisplayLine(" ######  ########  ######   ######   ##     ##    ########  ##       ##     ## ##       #####          ## ##     ## ##       #####   ");
		this->DisplayLine("      ## ##        ##       ##       ##     ##    ##     ## ##       ######### ##       ##  ##   ##    ## ######### ##       ##  ##  ");
		this->DisplayLine("##    ## ##        ##       ##       ##     ##    ##     ## ##       ##     ## ##    ## ##   ##  ##    ## ##     ## ##    ## ##   ## ");
		this->DisplayLine(" ######  ##        ######## ######## ########     ########  ######## ##     ##  ######  ##    ##  ######  ##     ##  ######  ##    ##");
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayPadding(11);
		this->DisplayLine("                                                       Press [Space] to Start.                                                       ");
		break;
	case State::DESCRIPTION:
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayLine("                    ########  ########  ######   ######  ########  #### ########  ######## ####  #######  ##    ##                   ");
		this->DisplayLine("                    ##     ## ##       ##    ## ##    ## ##     ##  ##  ##     ##    ##     ##  ##     ## ###   ##                   ");
		this->DisplayLine("                    ##     ## ##       ##       ##       ##     ##  ##  ##     ##    ##     ##  ##     ## ####  ##                   ");
		this->DisplayLine("                    ##     ## ######    ######  ##       ########   ##  ########     ##     ##  ##     ## ## ## ##                   ");
		this->DisplayLine("                    ##     ## ##             ## ##       ##   ##    ##  ##           ##     ##  ##     ## ##  ####                   ");
		this->DisplayLine("                    ##     ## ##       ##    ## ##    ## ##    ##   ##  ##           ##     ##  ##     ## ##   ###                   ");
		this->DisplayLine("                    ########  ########  ######   ######  ##     ## #### ##           ##    ####  #######  ##    ##                   ");
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayLine(" * This game is a \"Time Attack\" Blackjack where you aim to reach a target score.");
		this->DisplayLine(" * The time it takes to increase your points to the target score is measured.");
		this->DisplayLine(" * The initial score is 25, and the target score is 50.");
		this->DisplayLine(" * Players can choose to \"Hit\" or \"Stand\".");
		this->DisplayLine(" * The dealer will \"Hit\" until reaching at least 17 points.");
		this->DisplayLine(" * The game is over if the player's points drop to 0 or below, or if the remaining cards in the deck are less than 20.");
		this->DisplayLine(" * The minimum bet is 1 point, and the maximum bet is 10 points.");
		this->DisplayPadding(4);
		this->DisplayLine("                                                        Press [Space] to Next.                                                       ");
		this->DisplayLine("                                                    Press [Q] to Return to Title.                                                    ");
		break;
	case State::READY:
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayLine("        ###    ########  ########    ##    ##  #######  ##     ##    ########  ########    ###    ########  ##    ##     #######     ");
		this->DisplayLine("       ## ##   ##     ## ##           ##  ##  ##     ## ##     ##    ##     ## ##         ## ##   ##     ##  ##  ##     ##     ##    ");
		this->DisplayLine("      ##   ##  ##     ## ##            ####   ##     ## ##     ##    ##     ## ##        ##   ##  ##     ##   ####            ##     ");
		this->DisplayLine("     ##     ## ########  ######         ##    ##     ## ##     ##    ########  ######   ##     ## ##     ##    ##           ###      ");
		this->DisplayLine("     ######### ##   ##   ##             ##    ##     ## ##     ##    ##   ##   ##       ######### ##     ##    ##          ##        ");
		this->DisplayLine("     ##     ## ##    ##  ##             ##    ##     ## ##     ##    ##    ##  ##       ##     ## ##     ##    ##                    ");
		this->DisplayLine("     ##     ## ##     ## ########       ##     #######   #######     ##     ## ######## ##     ## ########     ##          ##        ");
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayPadding(11);
		this->DisplayLine("                                                       Press [Space] to Start.                                                       ");
		this->DisplayLine("                                                 Press [Q] to Return to Description.                                                 ");
		break;
	case State::BETTING:
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayLine("                  ########  ######## ######## ######## #### ##    ##  ######      ######## #### ##     ## ########                   ");
		this->DisplayLine("                  ##     ## ##          ##       ##     ##  ###   ## ##    ##        ##     ##  ###   ### ##                         ");
		this->DisplayLine("                  ##     ## ##          ##       ##     ##  ####  ## ##              ##     ##  #### #### ##                         ");
		this->DisplayLine("                  ########  ######      ##       ##     ##  ## ## ## ##   ####       ##     ##  ## ### ## ######                     ");
		this->DisplayLine("                  ##     ## ##          ##       ##     ##  ##  #### ##    ##        ##     ##  ##     ## ##                         ");
		this->DisplayLine("                  ##     ## ##          ##       ##     ##  ##   ### ##    ##        ##     ##  ##     ## ##                         ");
		this->DisplayLine("                  ########  ########    ##       ##    #### ##    ##  ######         ##    #### ##     ## ########                   ");
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayLine("* [1]:  1 Point ");
		this->DisplayLine("* [2]:  2 Points");
		this->DisplayLine("        :       ");
		this->DisplayLine("* [9]:  9 Points");
		this->DisplayLine("* [0]: 10 Points");
		this->DisplayPadding(6);
		this->DisplayLine("                                              Press the Number Button [0] ~ [9] to Bet.                                              ");
		break;
	case State::PLAYER_TURN:
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayLine("                  ########  ##          ###    ##    ## ######## ########     ######## ##     ## ########  ##    ##                  ");
		this->DisplayLine("                  ##     ## ##         ## ##    ##  ##  ##       ##     ##       ##    ##     ## ##     ## ###   ##                  ");
		this->DisplayLine("                  ##     ## ##        ##   ##    ####   ##       ##     ##       ##    ##     ## ##     ## ####  ##                  ");
		this->DisplayLine("                  ########  ##       ##     ##    ##    ######   ########        ##    ##     ## ########  ## ## ##                  ");
		this->DisplayLine("                  ##        ##       #########    ##    ##       ##   ##         ##    ##     ## ##   ##   ##  ####                  ");
		this->DisplayLine("                  ##        ##       ##     ##    ##    ##       ##    ##        ##    ##     ## ##    ##  ##   ###                  ");
		this->DisplayLine("                  ##        ######## ##     ##    ##    ######## ##     ##       ##     #######  ##     ## ##    ##                  ");
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayLine("Player");
		this->DisplayLine(this->player->GetHand()->ToString());
		this->DisplayPadding(1);
		this->DisplayLine("Dealer");
		this->DisplayLine(this->dealer->GetHand()->ToString());
		this->DisplayPadding(1);
		this->DisplayLine("Card Remaining : " + std::to_string(this->deck->GetNumCards()));
		this->DisplayLine("Score          : " + std::to_string(this->player->GetScore()));
		this->DisplayLine("Bet            : " + std::to_string(this->player->GetHand()->GetBet()));
		this->DisplayPadding(1);
		this->DisplayLine("                                                          Press [H] to Hit.                                                          ");
		this->DisplayLine("                                                         Press [S] to Stand.                                                         ");
		break;
	case State::RESULT:
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayLine("                                       ########  ########  ######  ##     ## ##       ########                                       ");
		this->DisplayLine("                                       ##     ## ##       ##    ## ##     ## ##          ##                                          ");
		this->DisplayLine("                                       ##     ## ##       ##       ##     ## ##          ##                                          ");
		this->DisplayLine("                                       ########  ######    ######  ##     ## ##          ##                                          ");
		this->DisplayLine("                                       ##   ##   ##             ## ##     ## ##          ##                                          ");
		this->DisplayLine("                                       ##    ##  ##       ##    ## ##     ## ##          ##                                          ");
		this->DisplayLine("                                       ##     ## ########  ######   #######  ########    ##                                          ");
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayLine("Player");
		this->DisplayLine(this->player->GetHand()->ToString());
		this->DisplayPadding(1);
		this->DisplayLine("Dealer");
		this->DisplayLine(this->dealer->GetHand()->ToString());
		this->DisplayPadding(1);
		this->DisplayLine("Card Remaining : " + std::to_string(this->deck->GetNumCards()));
		this->DisplayLine("Score : " + std::to_string(this->player->GetScore()));
		this->DisplayPadding(1);
		this->DisplayLine("                                                          Press [Space] to Next.                                                      ");
		break;
	case State::GAMECLEAR:
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayLine("                   ######      ###    ##     ## ########     ######  ##       ########    ###    ########     ####                   ");
		this->DisplayLine("                  ##    ##    ## ##   ###   ### ##          ##    ## ##       ##         ## ##   ##     ##    ####                   ");
		this->DisplayLine("                  ##         ##   ##  #### #### ##          ##       ##       ##        ##   ##  ##     ##    ####                   ");
		this->DisplayLine("                  ##   #### ##     ## ## ### ## ######      ##       ##       ######   ##     ## ########      ##                    ");
		this->DisplayLine("                  ##    ##  ######### ##     ## ##          ##       ##       ##       ######### ##   ##                             ");
		this->DisplayLine("                  ##    ##  ##     ## ##     ## ##          ##    ## ##       ##       ##     ## ##    ##     ####                   ");
		this->DisplayLine("                   ######   ##     ## ##     ## ########     ######  ######## ######## ##     ## ##     ##    ####                   ");
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayLine("Time  : " + std::to_string(this->GetResultTime().count()) + " sec");
		this->DisplayLine("Score : " + std::to_string(this->player->GetScore()));
		this->DisplayPadding(9);
		this->DisplayLine("                                                             Press [Space]                                                           ");
		break;
	case State::GAMEOVER:
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayLine("                    ######      ###    ##     ## ########     #######  ##     ## ######## ########                                   ");
		this->DisplayLine("                   ##    ##    ## ##   ###   ### ##          ##     ## ##     ## ##       ##     ##                                  ");
		this->DisplayLine("                   ##         ##   ##  #### #### ##          ##     ## ##     ## ##       ##     ##                                  ");
		this->DisplayLine("                   ##   #### ##     ## ## ### ## ######      ##     ## ##     ## ######   ########                                   ");
		this->DisplayLine("                   ##    ##  ######### ##     ## ##          ##     ##  ##   ##  ##       ##   ##                                    ");
		this->DisplayLine("                   ##    ##  ##     ## ##     ## ##          ##     ##   ## ##   ##       ##    ##     ### ### ###                   ");
		this->DisplayLine("                    ######   ##     ## ##     ## ########     #######     ###    ######## ##     ##    ### ### ###                   ");
		this->DisplayPadding(2);
		this->DisplayLine("*************************************************************************************************************************************");
		this->DisplayPadding(2);
		this->DisplayLine("Time  : " + std::to_string(this->GetResultTime().count()) + " sec");
		this->DisplayLine("Score : " + std::to_string(this->player->GetScore()));
		this->DisplayPadding(9);
		this->DisplayLine("                                                             Press [Space]                                                           ");
		break;
	}
}

/*
* @brief 画面をクリアする。
*/
void Game::DisplayClear() const {
	std::system("cls");
}

/*
* @brief 画面に文字列を1行表示する。
* @param std::string text 表示する文字列。
*/
void Game::DisplayLine(std::string text) const {
	std::cout << text << std::endl;
}

/*
* @brief 画面に空白行を表示する。
* @param int numLine 表示する空白行の数。

*/
void Game::DisplayPadding(int numLine = 1) const {
	for (int i = 0; i < numLine; i++) {
		std::cout << std::endl;
	}
}

/*
* @brief キー入力を受け付ける。
* 
* @details 現在の状態に応じて有効なキー入力であるかを判定する。
* @details 有効なキー入力であればそのキーを返す。
*/
void Game::KeyInput() {
	int key = this->NULL_KEY;
	bool isValidKey = false;

	// 有効なキーまたはESCキーが押されるまでループする。
	while (!isValidKey) {
		key = _getch();	// キー入力を受け付ける。

		// ESCキーは常に有効である。
		if (key == this->ESCAPE_KEY) {
			isValidKey = true;
			continue;
		}

		switch (currentState) {
		case State::TITLE:
		case State::RESULT:
		case State::GAMECLEAR:
		case State::GAMEOVER:
			if (key == this->SPACE_KEY) {
				isValidKey = true;
			}
			break;
		case State::DESCRIPTION:
		case State::READY:
			if (key == this->SPACE_KEY || key == this->Q_KEY) {
				isValidKey = true;
			}
			break;
		case State::BETTING:
			if (key >= this->ZERO_KEY && key <= this->NINE_KEY) {
				isValidKey = true;
			}
			break;
		case State::PLAYER_TURN:
			if (key == this->H_KEY || key == this->S_KEY) {
				isValidKey = true;
			}
			break;
		}
	}

	this->inputKey = key;
}

/*
* @brief ゲームの状態に応じた処理を実行する。
* 
* @details 主に、キー入力に応じてゲームの状態を遷移する。
* @details その他、状態遷移前にすべき処理を実行する。
*/
void Game::Process() {
	if (this->inputKey == this->ESCAPE_KEY) {
		this->currentState = State::TERMINATE;
		return;
	}

	switch (this->currentState) {
	case State::TITLE:
		if (this->inputKey == this->SPACE_KEY) {
			this->currentState = State::DESCRIPTION;
		}
		break;
	case State::DESCRIPTION:
		if (this->inputKey == this->SPACE_KEY) {
			this->currentState = State::READY;
		}
		else if (this->inputKey == this->Q_KEY) {
			this->currentState = State::TITLE;
		}
		break;
	case State::READY:
		if (this->inputKey == this->SPACE_KEY) {
			this->deck->Reset();
			this->player->Reset();
			this->player->SetScore(this->PLAYER_INITIAL_POINT);
			this->dealer->Reset();
			this->SetTime();

			this->currentState = State::BETTING;
		}
		else if (this->inputKey == this->Q_KEY) {
			this->currentState = State::DESCRIPTION;
		}
		break;
	case State::BETTING:
		// ベット額を設定する。
		if (this->inputKey == this->ZERO_KEY) {
			this->player->Bet(10);
		}
		else {
			this->player->Bet(this->inputKey - this->ZERO_KEY);
		}

		// プレイヤーとディーラーにカードを2枚ずつ配る。
		this->player->GetHand()->AddCard(this->deck->Draw());
		this->dealer->GetHand()->AddCard(this->deck->Draw());
		this->player->GetHand()->AddCard(this->deck->Draw());
		this->dealer->GetHand()->AddCard(this->deck->Draw());

		// ディーラーの2枚目のカードを裏向きにする。
		this->dealer->GetHand()->FaceDown(1);

		this->currentState = State::PLAYER_TURN;

		break;
	case State::PLAYER_TURN:
		if (this->inputKey == this->H_KEY) {
			this->player->GetHand()->AddCard(this->deck->Draw());
		}

		if (this->inputKey == this->H_KEY && this->player->GetHand()->GetPoint() < 21) {
			break;
		}
		
		// プレイヤーがスタンドまたはバーストした場合、ディーラーのターンに移行する。
		this->currentState = State::DEALER_TURN;
	case State::DEALER_TURN:
		// ディーラーの2枚目のカードを表向きにする。
		this->dealer->GetHand()->FaceUp(1);

		// ディーラーが17点以上になるまでカードを引く。
		while (this->dealer->GetHand()->GetPoint() < 17) {
			this->dealer->GetHand()->AddCard(this->deck->Draw());
		}

		// そのまま勝敗判定に移行する。
		this->currentState = State::JUDGEMENT;
	case State::JUDGEMENT:
		// プレイヤーがバーストしている場合、ディーラーの勝ち。
		if (this->player->GetHand()->GetIsBust()) {
			this->player->Lose();
		}
		// プレイヤーがナチュラルの場合
		else if (this->player->GetHand()->GetIsNatural()) {
			if (this->dealer->GetHand()->GetIsNatural()) {
				this->player->Tie();
			}
			else {
				this->player->NaturalWin();
			}
		}
		// ディーラーがバーストしている場合、プレイヤーの勝ち。
		else if (this->dealer->GetHand()->GetIsBust()) {
			this->player->Win();
		}
		// プレイヤーの点数がティーラーの点数より大きい場合、プレイヤーの勝ち。
		else if (this->player->GetHand()->GetPoint() > this->dealer->GetHand()->GetPoint()) {
			this->player->Win();
		}
		// プレイヤーの点数がディーラーの点数と同じ場合、引き分け。
		else if (this->player->GetHand()->GetPoint() == this->dealer->GetHand()->GetPoint()) {
			this->player->Tie();
		}
		// プレイヤーの点数がディーラーの点数より小さい場合、プレイヤーの負け。
		else if (this->player->GetHand()->GetPoint() < this->dealer->GetHand()->GetPoint()) {
			this->player->Lose();
		}

		// そのまま結果表示に移行する。
		this->currentState = State::RESULT;
	case State::RESULT:
		if (this->inputKey != this->SPACE_KEY) {
			break;
		}

		this->player->GetHand()->Reset();
		this->dealer->GetHand()->Reset();

		if (this->player->GetScore() >= this->PLAYER_TARGET_POINT) {
			this->SetTime();
			this->currentState = State::GAMECLEAR;
		}
		else if (this->player->GetScore() <= 0 || this->deck->GetNumCards() < 20) {
			this->SetTime();
			this->currentState = State::GAMEOVER;
		}
		else {
			this->currentState = State::BETTING;
		}
		
		break;
	case State::GAMECLEAR:
	case State::GAMEOVER:
		if (this->inputKey == this->SPACE_KEY) {
			this->currentState = State::READY;
		}
		break;
	}

	this->inputKey = this->NULL_KEY;
}

/*
* @brief ゲームを実行するためのサブルーチン。
*/
void Game::Run() {
	// ESCキーが押されるまでループ
	while (this->inputKey != this->ESCAPE_KEY) {
		this->Display();	// 画面の描画
		this->KeyInput();	// キー入力の受付
		this->Process();	// 処理の実行
	}
}

/*
* @brief 経過時間を設定する。
* 
* @details 経過時間を計測するための開始時刻と終了時刻を設定する。
* @details 前回の終了時刻を開始時刻に設定し、現在の時刻を終了時刻に設定する。
*/
void Game::SetTime() {
	this->startTime = this->endTime;
	this->endTime = std::chrono::system_clock::now();
	this->resultTime = this->endTime - this->startTime;
}

/*
* @brief 経過時間を取得する。
* 
* @return std::chrono::duration<double> 経過時間。
*/
std::chrono::duration<double> Game::GetResultTime() const {
	return this->resultTime;
}
