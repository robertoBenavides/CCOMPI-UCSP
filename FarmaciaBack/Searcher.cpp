#include <vector>
#include "Searcher.h"
int Searcher::bBusca(vector<T> L, int e) {
	if (len(L) == 0)return False
		return bBusca(L, e, 0, len(L) - 1)
}
