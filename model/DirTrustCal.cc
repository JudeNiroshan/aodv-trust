//#include "stdafx.h"
#include "DirTrustCal.h"
#include "DirTrustHelper.h"
#include "MetaDataTool.h"
#include<math.h>

namespace ns3
{
namespace aodv
{

DirTrustCal::DirTrustCal()
{
}


void DirTrustCal::calculateDirectTrust(TrustTable *trustTable)
{
	//double dt = 0;
	std::vector<TrustTableEntry>& node_entry_vector = trustTable->getTrustTableEntries();

	for (std::vector<TrustTableEntry>::iterator it = node_entry_vector.begin(); it != node_entry_vector.end(); it++)
	{
		 
		double rreq = DirTrustHelper::getNoOfRREQ(*it->getDestinationNode());
		double rply = DirTrustHelper::getNoOfRPLY(*it->getDestinationNode());
		double hello = DirTrustHelper::getNoOfHELLO(*it->getDestinationNode());
		double err = DirTrustHelper::getNoOfERR(*it->getDestinationNode());
		
		double cp = (rreq + rply + hello + err) / 4;

		double sent = DirTrustHelper::getNoOfHELLO(*it->getDestinationNode());
		double received = DirTrustHelper::getNoOfERR(*it->getDestinationNode());

		double dp = sent / received;

		double dt = cp + dp;

		double finaldt = calculateFinalDT(dt);


		it->setDirectTrust(finaldt);
	}

}

double DirTrustCal::calculateFinalDT(double directTrustValue)
{
	double scaledDT = 1 - (1 / pow(directTrustValue , 0.5));
	return scaledDT;
}

DirTrustCal::~DirTrustCal()
{
}

}
}
