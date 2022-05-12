#pragma once

#ifdef LR_PLATFORM_WINDOWS

extern Learner::Application* Learner::CreateApplication();

int main(int argc, char** argv)
{
	Learner::Log::Init();
	LR_CORE_WARN("Initialized Engine Log!!!");
	LR_INFO("Initialized App Log! Var={0}", 5);

	auto app = Learner::CreateApplication();
	app->Run();
	delete app;
}
#else
#error Learner only suppot Windows now!
#endif // LR_PLATFORM_WINDOWS
