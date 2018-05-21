#pragma once
#include "BackupTable.h"
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
	static RecommendationTable* getDummyRecommendationTableByTrustTable(TrustTable* trustTable);
	static BackupTable* getDummyBackupTableByTrustTable(TrustTable* trustTable);
	~TestValueGenerator();
};

}
}
