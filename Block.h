

#ifndef ESSENTIAL_CPP_BLOCK
#define ESSENTIAL_CPP_BLOCK

#include <cstdint>
#include <iostream>

using namespace std;

// https://davenash.com/2017/10/build-a-blockchain-with-c/
// https://github.com/teaandcode/TestChain
namespace metac {

    class Block {

	public:

	    string sPrevHash;
		Block(uint32_t nIndexIn, const string &sDataIn);
		string GetHash();
		void MineBlock(uint32_t nDifficulty);

	private:

	    uint32_t _nIndex;
		int64_t _nNonce;
		string _sData;
		string _sHash;
		time_t _tTime;

		string _CalculateHash() const;

	}

}

#endif

