#include "Services.h"

Services* Services::mspInstance = NULL;

Services::Services() :
mpGraphicsSystem(NULL)
{
}

bool Services::init()
{
	if (mspInstance == NULL)
	{
		mspInstance = new Services();
		return true;
	}
	return false;
}

void Services::cleanup()
{
	if (mspInstance != NULL)
	{
		delete mspInstance;
		mspInstance = NULL;
	}
}
