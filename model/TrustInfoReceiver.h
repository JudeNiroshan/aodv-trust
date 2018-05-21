#pragma once
#include "NodeEntry.h"
#include "ns3/ipv4-address.h"

namespace ns3
{
namespace aodv
{

class TrustInfoReceiver
{
public:
	TrustInfoReceiver();
	void validateReceivedTrustInfo();
	void sendMaliciousBroadcast(Ipv4Address node);
	~TrustInfoReceiver();
};

}
}
