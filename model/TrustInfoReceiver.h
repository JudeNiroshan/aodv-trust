#pragma once
#include "NodeEntry.h"

namespace ns3
{
namespace aodv
{

class TrustInfoReceiver
{
public:
	TrustInfoReceiver();
	void validateReceivedTrustInfo();
	void sendMaliciousBroadcast(NodeEntry* node);
	~TrustInfoReceiver();
};

}
}
