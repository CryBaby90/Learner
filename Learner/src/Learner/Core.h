#pragma once

#ifdef LR_PLATFORM_WINDOWS
	#ifdef LEARNER_BUILD_DLL
		#define LEARNER_API _declspec(dllexport)
	#else
		#define LEARNER_API _declspec(dllimport)
	#endif // LR_BUILD_DLL
#else
#error Learner only suppot Windows now!
#endif // LR_PLATFORM_WINDOWS
