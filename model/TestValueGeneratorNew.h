#pragma once
#include "TrustTable.h"
#include "RecommendationTable.h"

namespace ns3
{
namespace aodv
{

class TestValueGeneratorNew
{
public:
	TestValueGeneratorNew();
	static TrustTable* getDummyDirTrustTable();
	static TrustTable* getDummyTrustTable();
	static RecommendationTable* getDummyRecommendationTableByTrustTable(TrustTable* trustTable);
	~TestValueGeneratorNew();
};

}
}
