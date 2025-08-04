#pragma once
#include "state.h"

namespace coreLib {
	void Init();
	void Shutdown();

	void PollInput();
	void UpdateGame(float deltaTime);

	void ChangeState(GameState* newState);
	GameState* GetCurrentState();

	bool ShouldExit();

	enum class GameStateType {
		Start,
		Playing,
		Paused,
		GameOver
	};
	GameStateType GetGameState();
}