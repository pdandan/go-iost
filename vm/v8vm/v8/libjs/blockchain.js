let BlockChain = (function () {
    let bc = new IOSTBlockchain;
    let storage = new IOSTStorage;
    // get contractName
    let contractName = function () {
        let ctxInfo = JSON.parse(bc.contextInfo());
        return ctxInfo["contract_name"];
    };
    // get publisher
    let publisher = function () {
        let ctxInfo = JSON.parse(bc.contextInfo());
        return ctxInfo["publisher"];
    };
    // transfer IOSToken
    let transfer = function (from, to, amount, memo) {
        if (!(amount instanceof Float64)) {
            amount = new Float64(amount);
        }
        const args = ["iost", from, to, amount.toString(), memo.toString()];
        return JSON.parse(bc.callWithAuth("token.iost", "transfer", JSON.stringify(args)));
    };
    return {
        // transfer IOSToken
        transfer: transfer,
        // withdraw IOSToken
        withdraw: function (to, amount, memo) {
            return transfer(contractName(), to, amount, memo);
        },
        // deposit IOSToken
        deposit: function (from, amount, memo) {
            return transfer(from, contractName(), amount, memo);
        },
        // get blockInfo
        blockInfo: function () {
            return bc.blockInfo();
        },
        // get transactionInfo
        txInfo: function () {
            return bc.txInfo();
        },
        // get transactionInfo
        contextInfo: function () {
            return bc.contextInfo();
        },
        // get contractName
        contractName: contractName,
        // get publisher
        publisher: publisher,
        // get contractOwner
        contractOwner: function() {
            return storage.globalMapGet("system.iost", "contract_owner", contractName(), "")
        },
        // call contract's api using args
        call: function (contract, api, args) {
            if (typeof args == "object") {
                args = JSON.stringify(args);
            }
            return JSON.parse(bc.call(contract, api, args));
        },
        // call contract's api using args with auth
        callWithAuth: function (contract, api, args) {
            if (typeof args == "object") {
                args = JSON.stringify(args);
            }
            return JSON.parse(bc.callWithAuth(contract, api, args));
        },
        // check account's permission
        requireAuth: function (accountID, permission) {
            return bc.requireAuth(accountID, permission);
        },
        // generate receipt
        receipt: function (content) {
            return bc.receipt(content);
        },
        // post event
        event: function (content) {
            return bc.event(content);
        },
    }
})();

module.exports = BlockChain;
