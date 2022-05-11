#pragma once

#ifdef LR_PLATFORM_WINDOWS

extern Learner::Application* Learner::CreateApplication();

int main(int argc, char** argv)
{
	printf("Start Learner Engine\n");
	auto app = Learner::CreateApplication();
	app->Run();
	delete app;
}
#else
#error Learner only suppot Windows now!
#endif // LR_PLATFORM_WINDOWS
