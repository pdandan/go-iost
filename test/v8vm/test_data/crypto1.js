'use strict';
class crypto1 {
    sha3(msg) {
        return IOSTCrypto.sha3(msg);
    }
    verify(algo, msg, sig, pubkey) {
        return IOSTCrypto.verify(algo, msg, sig, pubkey);
    }

}

module.exports = crypto1;