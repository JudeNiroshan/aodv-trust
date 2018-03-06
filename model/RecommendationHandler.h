#pragma once
#include "TRRTable.h"
#include "TRRTableEntry.h"

namespace ns3
{
namespace aodv
{
class RecommendationHandler {

private:
	TRRTable m_TRRTable;
	RoutingProtocol m_RoutingProtocol;

public:
	RecommendationHandler(RoutingProtocol aodvRoutingProtocol);
	void execute(Ipv4Address node, TrustTable* trustTable);
	void sendTRR(Ipv4Address source, Ipv4Address node, Ipv4Address targetNode);
	void RecvTrr (Ipv4Address sender, Ptr<Packet> packet )
	virtual ~RecommendationHandler();
};

}
}
