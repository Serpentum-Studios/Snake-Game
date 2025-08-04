#include "coreLib.h"
#include "renderLib.h"
#include <chrono>
#include <thread>

int main() {
	// Initialization
	coreLib::Init();
	renderLib::Init();
	coreLib::ChangeState(new StartState());

	const int target_FPS		= 60;
	const int frame_delay_ms	= 1000 / target_FPS;

	using clock = std::chrono::steady_clock;
	auto prevTime = clock::now();

	bool running = true;
	while (running && !coreLib::ShouldExit()) {
		auto frameStart = clock::now();
		float deltaTime = std::chrono::duration<float>(frameStart - prevTime).count();
		prevTime = frameStart;

		// Update Logic
		coreLib::PollInput();
		coreLib::UpdateGame(deltaTime);
		
		// Render 
		renderLib::BeginFrame();
		renderLib::DrawFrame(coreLib::GetGameState());
		renderLib::EndFrame();

		// Frame Rate Control
		auto frameTime = std::chrono::duration_cast<std::chrono::milliseconds>(frameEnd - frameStart).count();
		if (frameTime < frame_delay_ms) {
			std::this_thread::sleep_for(std::chrono::milliseconds(frame_delay_ms - frameDuration));
		}
	}

	// Shutdown
	renderLib::Shutdown();
	coreLib::Shutdown();

}