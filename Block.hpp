
#include "Block.h"
#include "sha256.h"

namespace metac {

Block::Block(uint32_t nIndexIn, const string &sDataIn):_nIndex(nIndexIn),_sData(sDataIn) {
    _nNonce = -1;
	_tTime = time(nullptr);
}

string Block::GetHash() {
    return _sHash;
}

} // metac

