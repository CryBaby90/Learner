#include <Learner.h>

class Sandbox : public Learner::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};


Learner::Application* Learner::CreateApplication()
{
	return new Sandbox();
}