#pragma once
#include "Core.h"

namespace Learner {

	class LEARNER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in CLIENT
	Application* CreateApplication();
}
