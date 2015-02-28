#ifndef CPUUNIONFINDSEGMENTATOR_H_
#define CPUUNIONFINDSEGMENTATOR_H_

#include "cir/common/Segmentator.h"

namespace cir { namespace cpuprocessing {

class CpuUnionFindSegmentator : public cir::common::Segmentator {
public:
	CpuUnionFindSegmentator();
	virtual ~CpuUnionFindSegmentator();

	void init(int width, int height);
	void shutdown();

	virtual cir::common::SegmentArray* segmentate(const cir::common::MatWrapper& input);

private:
	cir::common::Segment* _segments;
	int* _ids;

	void unionFindSegmentate(int width, int height, int step, int channels, bool* changed);

	int countPos(int x, int y, int width, int height);
	void prepareBestNeighbour(int x, int y, int width, int height, bool* changed);
	int findRoot(int pos);
	void unite(int pos1, int pos2, bool* changed);

	void initInternalStructures(uchar* data, int width, int height, int step, int channels);
};

}}
#endif /* CPUUNIONFINDSEGMENTATOR_H_ */
