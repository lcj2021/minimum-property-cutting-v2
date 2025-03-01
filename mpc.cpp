#include "graph.hpp"
#include <ctime>
clock_t st, ed;
double endtime;
int main(int argc, char *argv[])
{
	string txt_name = argv[1];
	string name = argv[2];
	string sign = (string(argv[3]) == "1") ? " " : "\t";
	int part = atoi(argv[4]);

	st = clock();
		graph *test = new graph();
		test->init();
		test->RDF = name;
		test->part = part;
		test->loadGraph(txt_name, sign);
		int predNum = test->getPreNum();
		long long entityNum = test->getEntityNum();
		cout << "predNum: " << predNum << endl << "entityNum: " << entityNum << endl;
		// Find the optimal partitioning results when the count of properties is smaller than 20
		if (predNum <= 20)
			test->unionEdgeForEnum();
		// Use similarity & WCC combo greed trategy based on bitset, must set stack size before start
		else if (predNum <= 40 && entityNum <= 20000000)
			test->unionEdgeForGreed1_2(1);
		// Use only WCC greed strategy
		else if (predNum <= 120)
			test->unionEdgeForGreed1_2(2);
		// Select directly after sorting properties by descending order until limit reached
		else if (predNum > 120)
			test->greed3();

	ed = clock();

	test->partition(txt_name, sign, name);

	endtime = (double)(ed - st) / CLOCKS_PER_SEC;
	cout << "partition : " << endtime << " s" << endl;

	delete test;

	return 0;
}

// ./bin/mpc ./dataset/watdiv100K.nt MPC_watdiv100K_data 2 8
// nohup ./bin/mpc ./dataset/watdiv100M.txt MPC_watdiv100M_data 2 8 > watdivres &
// nohup ./bin/mpc ../metis2/dbpedia2014.nt MPC_dbpedia_data 1 8 > dbres1 &
// ./bin/mpc LUBM100M.nt LUBM100M_Enum 1 8
// ./bin/mpc LUBM100M.nt LUBM100M_Greed1 1 8
// ./bin/mpc LUBM1M.nt LUBM1M_test 2 4
