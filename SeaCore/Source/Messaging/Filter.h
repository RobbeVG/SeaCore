#pragma once
#include "SendAndReceiveInterface.h"

//PIPES ARE JUST POINTERS

namespace sea_core
{
	class Filter : public Sender, public Receiver {};
}
