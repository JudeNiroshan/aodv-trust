#include "NodeEntry.h"

namespace ns3
{
namespace aodv
{


class DirTrustHelper
{
public:
	DirTrustHelper();
	static int getNoOfRREQ(NodeEntry p_node);
	static int getNoOfRPLY(NodeEntry p_node);
	static int getNoOfHELLO(NodeEntry p_node);
	static int getNoOfERR(NodeEntry p_node);
	static int getNoOfSentDataPackets(NodeEntry p_node);
	static int getNoOfReceivedDataPackets(NodeEntry p_node);
	static NodeEntry* getAllNeiNodes();
	~DirTrustHelper();

};

}
}

