#pragma once
#include "TrustTable.h"
#include "RecommendationTable.h"

namespace ns3
{
namespace aodv
{

class TestValueGenerator
{
public:
	TestValueGenerator();
	static TrustTable* getDummyTrustTable();
	static TrustTable* getDummyDirTrustTable();
	static RecommendationTable* getDummyRecommendationTable();
	static RecommendationTable* getDummyRecommendationTableByTrustTable(TrustTable* trustTable);

	~TestValueGenerator();
};

}
}
