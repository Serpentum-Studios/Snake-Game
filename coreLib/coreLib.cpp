#include "coreLib.h"
#include "startState.h"
#include "playingState.h"
#include "gameOverState.h"

namespace coreLib {
	GameState* currentState = nullptr;
	bool exitRequested = false;
	GameStateType currentType = GameStateType::Start;

	void Init() {
		// Initial Game Setup (title screen)

	}

	void Shutdown() {
		delete currentState;
		currentState = nullptr;
	}

	void ChangeState(GameState* newState) {
		delete currentState;
		currentState = newState;
		currentType = newState->GetType();
	}

	void PollInput() {
		if (currentState)
			currentState->HandleInput();
	}

	void UpdateGame(float deltaTime) {
		if (currentState)
			currentState->Update(deltaTime);
	}


}