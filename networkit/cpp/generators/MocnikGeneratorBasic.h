/*
 * MocnikGeneratorBasic.h
 *
 * Created on: July 7, 2018
 * Author: Franz-Benjamin Mocnik <mail@mocnik-science.net>
 */

#ifndef MOCNIKGENERATORBASIC_H_
#define MOCNIKGENERATORBASIC_H_

#include "StaticGraphGenerator.h"
#include <unordered_map>

namespace NetworKit {

/**
 * @ingroup generators
 */
class MocnikGeneratorBasic: public StaticGraphGenerator {
private:
	// GENERAL DATA
	
	/**
	 * Position of each node in space.  The index of the vector is also the number of
	 * the node.
	 */
	std::vector<std::vector<double>> nodePositions;

protected:
	count dim;
	count n;
	double k;

public:
	/**
	 * Creates random spatial graphs according to the Mocnik model.
	 *
	 * Please cite the following publications, in which you will find a
	 * description of the model:
	 * 
	 * Franz-Benjamin Mocnik, Andrew Frank: "Modelling Spatial Structures",
	 * Proceedings of the 12th Conference on Spatial Information Theory (COSIT),
	 * 2015, pages 44-64. doi: 10.1007/978-3-319-23374-1_3
	 *
	 * Non-improved algorithm.
	 *
	 * @param dim  Dimension of the space.
	 * @param n  Number of nodes in the graph.
	 * @param k  Density parameter, determining the ratio of edges to nodes.
	 */
	MocnikGeneratorBasic(count dim, count n, double k);

	virtual Graph generate();
};

} /* namespace NetworKit */
#endif /* MOCNIKGENERATORBASIC_H_ */
