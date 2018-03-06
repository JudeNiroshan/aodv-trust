
#include "RecommendationTable.h"
#include "aodv-routing-protocol.h"
#include <string>
#include <iostream>
#include <vector>

namespace ns3
{
namespace aodv
{

RecommendationHandler::RecommendationHandler(RoutingProtocol aodvRoutingProtocol) {
	m_RoutingProtocol = aodvRoutingProtocol;

}

void RecommendationHandler::execute(Ipv4Address node, TrustTable* trustTable) {

	std::vector<TrustTableEntry>& node_entry_vector = trustTable->getTrustTableEntries();

	for (std::vector<TrustTableEntry>::iterator it = node_entry_vector.begin(); it != node_entry_vector.end(); it++) {
		Ipv4Address selectedTarget = it->getDestinationNode();

		for (std::vector<TrustTableEntry>::iterator it2 = node_entry_vector.begin(); it2 != node_entry_vector.end(); it2++) {
			sendTRR(node, it2->getDestinationNode(), selectedTarget);
		}
	}
}

/**
  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  |                    A ---------> B ---------> D                 |
  |                    ^----------> C -----------^                 |
  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

* source: A
* receiver: B
* targetNode: D
*/
void
RecommendationHandler::sendTRR(Ipv4Address source, Ipv4Address receiver, Ipv4Address targetNode)
{
	  // Create TRR header
	  TRRHeader trrHeader;
	  trrHeader.SetDst (receiver);
	  trrHeader.SetOrigin (source);
	  trrHeader.SetTarget(targetNode);
	  trrHeader.SetTrrLifetime(Simulator::Now());

      Ptr<Packet> packet = Create<Packet> ();
      packet->AddHeader (trrHeader);
      TypeHeader tHeader (AODVTYPE_TRR);
      packet->AddHeader (tHeader);

      Simulator::Schedule (Time (500), &RoutingProtocol::SendTo, this, socket, packet, targetNode);

}

/**
  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  |                    A ---------> B ---------> D                 |
  |                     \----------> C ----------^                 |
  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

* receiver: B
* sender: A
*/
void
RecommendationHandler::RecvTrr (Ipv4Address sender, Ptr<Packet> packet )
{
  RoutingTableEntry rt;
  TRRHeader trrHeader;
  packet->RemoveHeader(trrHeader);
  std::cout << "RECEIVE TRR TARGET: "<< trrHeader.GetDst() << std::endl;

  if (m_RoutingProtocol.IsMyOwnAddress (trrHeader.GetDst ()))
  {
//	  rec = sendTRR(node, targetNode);
	  Time time = trrHeader.GetTrrLifetime();
	  Time currentTime = Simulator::Now();

	  if((currentTime - time) < Time(1500).GetMilliSeconds()){
		  TRRTableEntry entry;
		  entry.setSentTime(trrHeader.GetTrrLifetime().GetMilliSeconds());
		  entry.setReceivedTime(currentTime.GetMilliSeconds());
		  entry.setDirectTrust(trrHeader.GetDT());
		  entry.setGlobalTrust(trrHeader.GetGT());
		  entry.setTargetNodeId(trrHeader.GetTarget());

		  m_TRRTable.addTrrTableEntry(entry);
	  }

    return;
  }

  bool status = false;

  for (std::vector<TrustTableEntry>::iterator it = m_RoutingProtocol.m_trustTable.getTrustTableEntries().begin(); it != m_RoutingProtocol.m_trustTable.getTrustTableEntries().end(); it++)
   {
 	  if(it->getDestinationNode() == trrHeader.GetDst())
 	  {
 		trrHeader.setDT(it->getDirectTrust());
 		trrHeader.setDT(it->getGlobalTrust());
 		status = true;
 	  }
   }

   Ptr<Packet> packetReply = Create<Packet> ();
   packetReply->AddHeader (trrHeader);
   TypeHeader tHeader (AODVTYPE_TRR);
   packetReply->AddHeader (tHeader);

   if(status)
   {
	   Simulator::Schedule (Time (500), &RoutingProtocol::SendTo, this, socket, packetReply, sender);
   }
/*  if(m_routingTable.LookupRoute (sender, rt))
    {
      rt.m_ackTimer.Cancel ();
      rt.SetFlag (VALID);
      m_routingTable.Update (rt);
    }*/
 }
RecommendationHandler::~RecommendationHandler() {
	// TODO Auto-generated destructor stub
}

}
}
