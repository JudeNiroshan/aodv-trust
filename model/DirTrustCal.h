#include "TrustTable.h"
#include "ns3/ipv4-address.h"

namespace ns3
{
namespace aodv
{

class DirTrustCal
{
public:
	DirTrustCal();
	void calculateDirectTrust(TrustTable *trustTable);
	double calculateFinalDT(double directTrustValue);
	~DirTrustCal();
};

}
}
