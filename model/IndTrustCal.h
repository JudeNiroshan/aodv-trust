#pragma once
#include "TrustTable.h"
#include "TrustTableEntry.h"
#include "TRRTable.h"
#include "TRRTableEntry.h"

namespace ns3 {
namespace aodv {

class IndTrustCal {
private:
	TrustTable* trustTable;
	TRRTable* trrTable;
	uint flag1;
public:
	IndTrustCal();
	double* sendTRR(TrustTableEntry node, TrustTableEntry targetNode);
	double calculateWeight(TrustTableEntry node, TrustTableEntry targetNode);
	double calculateRNew(TrustTableEntry node, TrustTableEntry targetNode);
	double* getDTGT(TrustTableEntry node, TrustTableEntry targetNode);
	double calculateMaturityLevel(TrustTableEntry node);
	void setTrustTable(TrustTable* trustTable);
	void setTrrTable(TRRTable* trrTable);
	double calculateIndirectTrust(TrustTableEntry targetNode);
	void setFlag(uint flag1);
	~IndTrustCal();
};

}
}

