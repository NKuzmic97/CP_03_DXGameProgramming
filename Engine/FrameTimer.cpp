#include "FrameTimer.h"

FrameTimer::FrameTimer() {
	last = std::chrono::steady_clock::now();
}

float FrameTimer::Mark() {
	std::chrono::steady_clock::time_point old = last;
	last = std::chrono::steady_clock::now();
	std::chrono::duration<float> duration = last - old;

	return duration.count();
}