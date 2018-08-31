
#ifndef ESSENTIAL_BLOCKCHAIN_H
#define ESSENTIAL_BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include "Block.h"

using namespace std;

namespace metac {

	class Blockchain {

	public:
		Blockchian();
		void AddBlock(Block bNew);

	private:
		uint32_t _nDifficulty;
		vector<Block> _vChain;
		Block _GetLastBlock() const;

	}

}

#endif


