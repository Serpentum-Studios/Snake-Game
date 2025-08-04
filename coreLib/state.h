
#pragma once

enum class GameStateType { Start, Playing, Paused, GameOver };

class GameState {

public:
	virtual void HandleInput() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render() = 0;
	virtual GameStateType GetType() const = 0;
	virtual ~GameState() {}

};
