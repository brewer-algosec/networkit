/*
 * ApproxGroupBetweenness.h
 *
 *  Created on: 13.03.2018
 *      Author: Marvin Pogoda
 */
#ifndef APPROXGROUPBETWEENNESS_H_
#define APPROXGROUPBETWEENNESS_H_

#include "../base/Algorithm.h"
#include "../graph/Graph.h"

namespace NetworKit {

class ApproxGroupBetweenness : public Algorithm {

public:
	/** Constructs the ApproxGroupBetweenness class for a given undirected graph
	 * @a G.
	 * @param groupSize Size of the set of nodes.
	 * @þaram epsilon Determines the accuracy of the approximation.
	 */
	ApproxGroupBetweenness(const Graph &G, const count groupSize,
	                       const double epsilon);

	/**
	 * Approximately computes a set of nodes with maximum groupbetweenness. Based
	 * on the algorithm of Mahmoody,Tsourakakis and Upfal.
	 */
	void run() override;

	/**
	 * Returns a vector of nodes containing the set of nodes with approximated
	 * maximum group betweenness.
	 */
	std::vector<node> groupMaxBetweenness() const;

protected:
	const Graph &G;
	std::vector<node> maxGroup;
	const count groupSize;
	const double epsilon;
};

inline std::vector<node> ApproxGroupBetweenness::groupMaxBetweenness() const {
	if (!hasRun) {
		throw std::runtime_error("run method has not been called");
	}
	return maxGroup;
}

} /* namespace NetworKit */

#endif /* APPROXGROUPBETWEENNESS_H_ */
