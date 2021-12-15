#include "storage.h"
#include <stdio.h>
#include <string.h>
#include <iostream>

static putFunc CPut = nullptr;
static hasFunc CHas = nullptr;
static getFunc CGet = nullptr;
static delFunc CDel = nullptr;
static mapPutFunc CMapPut = nullptr;
static mapHasFunc CMapHas = nullptr;
static mapGetFunc CMapGet = nullptr;
static mapDelFunc CMapDel = nullptr;
static mapKeysFunc CMapKeys = nullptr;
static mapLenFunc CMapLen = nullptr;

static globalHasFunc CGHas = nullptr;
static globalGetFunc CGGet = nullptr;
static globalMapHasFunc CGMapHas = nullptr;
static globalMapGetFunc CGMapGet = nullptr;
static globalMapKeysFunc CGMapKeys = nullptr;
static globalMapLenFunc CGMapLen = nullptr;

void InitGoStorage(putFunc put, hasFunc has, getFunc get, delFunc del,
    mapPutFunc mput, mapHasFunc mhas, mapGetFunc mget, mapDelFunc mdel, mapKeysFunc mkeys, mapLenFunc mlen,
    globalHasFunc ghas, globalGetFunc gget, globalMapHasFunc gmhas, globalMapGetFunc gmget, globalMapKeysFunc gmkeys, globalMapLenFunc gmlen) {

    CPut = put;
    CHas = has;
    CGet = get;
    CDel = del;
    CMapPut = mput;
    CMapHas = mhas;
    CMapGet = mget;
    CMapDel = mdel;
    CMapKeys = mkeys;
    CMapLen = mlen;
    CGHas = ghas;
    CGGet = gget;
    CGMapHas = gmhas;
    CGMapGet = gmget;
    CGMapKeys = gmkeys;
    CGMapLen = gmlen;
}

char* IOSTContractStorage::Put(const CStr key, const CStr value, const CStr ramPayer) {
    size_t gasUsed = 0;
    char *ret = CPut(sbxPtr, key, value, ramPayer, &gasUsed);
    Sandbox *sbx = static_cast<Sandbox*>(sbxPtr);
    sbx->gasUsed += gasUsed;
    return ret;
}

char* IOSTContractStorage::Has(const CStr key, const CStr ramPayer, bool *result) {
    size_t gasUsed = 0;
    char *ret = CHas(sbxPtr, key, ramPayer, result, &gasUsed);
    Sandbox *sbx = static_cast<Sandbox*>(sbxPtr);
    sbx->gasUsed += gasUsed;
    return ret;
}

char* IOSTContractStorage::Get(const CStr key, const CStr ramPayer, CStr *result) {
    size_t gasUsed = 0;
    char *ret = CGet(sbxPtr, key, ramPayer, result, &gasUsed);
    Sandbox *sbx = static_cast<Sandbox*>(sbxPtr);
    sbx->gasUsed += gasUsed;
    return ret;
}

char* IOSTContractStorage::Del(const CStr key, const CStr ramPayer) {
    size_t gasUsed = 0;
    char *ret = CDel(sbxPtr, key, ramPayer, &gasUsed);
    Sandbox *sbx = static_cast<Sandbox*>(sbxPtr);
    sbx->gasUsed += gasUsed;
    return ret;
}

char* IOSTContractStorage::MapPut(const CStr key, const CStr field, const CStr value, const CStr ramPayer) {
    size_t gasUsed = 0;
    char *ret = CMapPut(sbxPtr, key, field, value, ramPayer, &gasUsed);
    Sandbox *sbx = static_cast<Sandbox*>(sbxPtr);
    sbx->gasUsed += gasUsed;
    return ret;

}

char* IOSTContractStorage::MapHas(const CStr key, const CStr field, const CStr ramPayer, bool *result) {
    size_t gasUsed = 0;
    char *ret = CMapHas(sbxPtr, key, field, ramPayer, result, &gasUsed);
    Sandbox *sbx = static_cast<Sandbox*>(sbxPtr);
    sbx->gasUsed += gasUsed;
    return ret;
}

char* IOSTContractStorage::MapGet(const CStr key, const CStr field, const CStr ramPayer, CStr *result) {
    size_t gasUsed = 0;
    char *ret = CMapGet(sbxPtr, key, field, ramPayer, result, &gasUsed);
    Sandbox *sbx = static_cast<Sandbox*>(sbxPtr);
    sbx->gasUsed += gasUsed;
    return ret;
}

char* IOSTContractStorage::MapDel(const CStr key, const CStr field, const CStr ramPayer) {
    size_t gasUsed = 0;
    char *ret = CMapDel(sbxPtr, key, field, ramPayer, &gasUsed);
    Sandbox *sbx = static_cast<Sandbox*>(sbxPtr);
    sbx->gasUsed += gasUsed;
    return ret;
}

char* IOSTContractStorage::MapKeys(const CStr key, const CStr ramPayer, CStr *result) {
    size_t gasUsed = 0;
    char *ret = CMapKeys(sbxPtr, key, ramPayer, result, &gasUsed);
    Sandbox *sbx = static_cast<Sandbox*>(sbxPtr);
    sbx->gasUsed += gasUsed;
    return ret;
}

char* IOSTContractStorage::MapLen(const CStr key, const CStr ramPayer, size_t *result) {
    size_t gasUsed = 0;
    char *ret = CMapLen(sbxPtr, key, ramPayer, result, &gasUsed);
    Sandbox *sbx = static_cast<Sandbox*>(sbxPtr);
    sbx->gasUsed += gasUsed;
    return ret;
}

char* IOSTContractStorage::GlobalHas(const CStr contract, const CStr key, const CStr ramPayer, bool *result) {
    size_t gasUsed = 0;
    char *ret = CGHas(sbxPtr, contract, key, ramPayer, result, &gasUsed);
    Sandbox *sbx = static_cast<Sandbox*>(sbxPtr);
    sbx->gasUsed += gasUsed;
    return ret;
}

char* IOSTContractStorage::GlobalGet(const CStr contract, const CStr key, const CStr ramPayer, CStr *result) {
    size_t gasUsed = 0;
    char *ret = CGGet(sbxPtr, contract, key, ramPayer, result, &gasUsed);
    Sandbox *sbx = static_cast<Sandbox*>(sbxPtr);
    sbx->gasUsed += gasUsed;
    return ret;
}

char* IOSTContractStorage::GlobalMapHas(const CStr contract, const CStr key, const CStr field, const CStr ramPayer, bool *result) {
    size_t gasUsed = 0;
    char *ret = CGMapHas(sbxPtr, contract, key, field, ramPayer, result, &gasUsed);
    Sandbox *sbx = static_cast<Sandbox*>(sbxPtr);
    sbx->gasUsed += gasUsed;
    return ret;
}

char* IOSTContractStorage::GlobalMapGet(const CStr contract, const CStr key, const CStr field, const CStr ramPayer, CStr *result) {
    size_t gasUsed = 0;
    char *ret = CGMapGet(sbxPtr, contract, key, field, ramPayer, result, &gasUsed);
    Sandbox *sbx = static_cast<Sandbox*>(sbxPtr);
    sbx->gasUsed += gasUsed;
    return ret;
}

char* IOSTContractStorage::GlobalMapKeys(const CStr contract,  const CStr key, const CStr ramPayer, CStr *result) {
    size_t gasUsed = 0;
    char *ret = CGMapKeys(sbxPtr, contract, key, ramPayer, result, &gasUsed);
    Sandbox *sbx = static_cast<Sandbox*>(sbxPtr);
    sbx->gasUsed += gasUsed;
    return ret;
}

char* IOSTContractStorage::GlobalMapLen(const CStr contract, const CStr key, const CStr ramPayer, size_t *result) {
    size_t gasUsed = 0;
    char *ret = CGMapLen(sbxPtr, contract, key, ramPayer, result, &gasUsed);
    Sandbox *sbx = static_cast<Sandbox*>(sbxPtr);
    sbx->gasUsed += gasUsed;
    return ret;
}

void NewIOSTContractStorage(const FunctionCallbackInfo<Value> &args) {
    Isolate *isolate = args.GetIsolate();
    Local<Context> context = isolate->GetCurrentContext();
    Local<Object> global = context->Global();

    Local<Value> val = global->GetInternalField(0);
    if (!val->IsExternal()) {
        std::cout << "NewIOSTContractStorage val error" << std::endl;
        return;
    }
    Sandbox* sbx = static_cast<Sandbox*>(Local<External>::Cast(val)->Value());

    IOSTContractStorage *ics = static_cast<IOSTContractStorage*>(sbx->storage);

    Local<Object> self = args.Holder();
    self->SetInternalField(0, External::New(isolate, ics));

    args.GetReturnValue().Set(self);
}

void IOSTContractStorage_Put(const FunctionCallbackInfo<Value> &args) {
    Isolate *isolate = args.GetIsolate();
    Local<Object> self = args.Holder();

    if (args.Length() != 3) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_Put invalid argument length.")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> key = args[0];
    if (!key->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_Put key must be string.")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> val = args[1];
    if (!val->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_Put value must be string.")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> ramPayer = args[2];
    if (!val->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_Put ramPayer must be string.")
        );
        isolate->ThrowException(err);
        return;
    }

    NewCStrChecked(keyStr, key, isolate);
    NewCStrChecked(valStr, val, isolate);
    NewCStrChecked(ramPayerStr, ramPayer, isolate);

    Local<External> extVal = Local<External>::Cast(self->GetInternalField(0));
    if (!extVal->IsExternal()) {
        std::cout << "IOSTContractStorage_Put val error" << std::endl;
        return;
    }

    IOSTContractStorage *ics = static_cast<IOSTContractStorage *>(extVal->Value());
    char* ret = ics->Put(keyStr, valStr, ramPayerStr);
    if (ret != nullptr) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, ret)
        );
        isolate->ThrowException(err);
        free(ret);
        return;
    }
    args.GetReturnValue().SetNull();
}

void IOSTContractStorage_Has(const FunctionCallbackInfo<Value> &args) {
    Isolate *isolate = args.GetIsolate();
    Local<Object> self = args.Holder();

    if (args.Length() != 2) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_Has invalid argument length")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> key = args[0];
    if (!key->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_Has key must be string")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> ramPayer = args[1];
    if (!ramPayer->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_Has ramPayer must be string.")
        );
        isolate->ThrowException(err);
        return;
    }

    NewCStrChecked(keyStr, key, isolate);
    NewCStrChecked(ramPayerStr, ramPayer, isolate);
    bool result;

    Local<External> extVal = Local<External>::Cast(self->GetInternalField(0));
    if (!extVal->IsExternal()) {
        std::cout << "IOSTContractStorage_Has val error" << std::endl;
        return;
    }

    IOSTContractStorage *ics = static_cast<IOSTContractStorage *>(extVal->Value());
    char *ret = ics->Has(keyStr, ramPayerStr, &result);
    if (ret != nullptr) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, ret)
        );
        isolate->ThrowException(err);
        free(ret);
        return;
    }
    args.GetReturnValue().Set(result);
}

void IOSTContractStorage_Get(const FunctionCallbackInfo<Value> &args) {
    Isolate *isolate = args.GetIsolate();
    Local<Object> self = args.Holder();

    if (args.Length() != 2) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_Get invalid argument length")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> key = args[0];
    if (!key->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_Get key must be string")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> ramPayer = args[1];
    if (!ramPayer->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_Get ramPayer must be string.")
        );
        isolate->ThrowException(err);
        return;
    }

    NewCStrChecked(keyStr, key, isolate);
    NewCStrChecked(ramPayerStr, ramPayer, isolate);
    CStr resultStr = {nullptr, 0};

    Local<External> extVal = Local<External>::Cast(self->GetInternalField(0));
    if (!extVal->IsExternal()) {
        std::cout << "IOSTContractStorage_Get val error" << std::endl;
        return;
    }

    IOSTContractStorage *ics = static_cast<IOSTContractStorage *>(extVal->Value());
    char *ret = ics->Get(keyStr, ramPayerStr, &resultStr);
    if (ret != nullptr) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, ret)
        );
        isolate->ThrowException(err);
        free(ret);
        return;
    }

    if (resultStr.data == nullptr) {
        args.GetReturnValue().SetNull();
    } else {
        args.GetReturnValue().Set(String::NewFromUtf8(isolate, resultStr.data, String::kNormalString, resultStr.size));
        free(resultStr.data);
    }
}

void IOSTContractStorage_Del(const FunctionCallbackInfo<Value> &args) {
    Isolate *isolate = args.GetIsolate();
    Local<Object> self = args.Holder();

    if (args.Length() != 2) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_Del invalid argument length.")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> key = args[0];
    if (!key->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_Del key must be string.")
        );
        isolate->ThrowException(err);
        return;
    }
    Local<Value> ramPayer = args[1];
    if (!ramPayer->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_Del ramPayer must be string.")
        );
        isolate->ThrowException(err);
        return;
    }

    NewCStrChecked(keyStr, key, isolate);
    NewCStrChecked(ramPayerStr, ramPayer, isolate);

    Local<External> extVal = Local<External>::Cast(self->GetInternalField(0));
    if (!extVal->IsExternal()) {
        std::cout << "IOSTContractStorage_Del val error" << std::endl;
        return;
    }

    IOSTContractStorage *ics = static_cast<IOSTContractStorage *>(extVal->Value());
    char *ret = ics->Del(keyStr, ramPayerStr);
    if (ret != nullptr) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, ret)
        );
        isolate->ThrowException(err);
        free(ret);
        return;
    }
    args.GetReturnValue().SetNull();
}

void IOSTContractStorage_MapPut(const FunctionCallbackInfo<Value> &args) {
    Isolate *isolate = args.GetIsolate();
    Local<Object> self = args.Holder();

    if (args.Length() != 4) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_MapPut invalid argument length.")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> key = args[0];
    if (!key->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_MapPut key must be string.")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> field = args[1];
    if (!field->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_MapPut key must be string.")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> val = args[2];
    if (!val->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_MapPut value must be string.")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> ramPayer = args[3];
    if (!val->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_MapPut ramPayer must be string.")
        );
        isolate->ThrowException(err);
        return;
    }

    NewCStrChecked(keyStr, key, isolate);
    NewCStrChecked(fieldStr, field, isolate);
    NewCStrChecked(valStr, val, isolate);
    NewCStrChecked(ramPayerStr, ramPayer, isolate);

    Local<External> extVal = Local<External>::Cast(self->GetInternalField(0));
    if (!extVal->IsExternal()) {
        std::cout << "IOSTContractStorage_MapPut val error" << std::endl;
        return;
    }

    IOSTContractStorage *ics = static_cast<IOSTContractStorage *>(extVal->Value());
    char *ret = ics->MapPut(keyStr, fieldStr, valStr, ramPayerStr);
    if (ret != nullptr) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, ret)
        );
        isolate->ThrowException(err);
        free(ret);
        return;
    }
    args.GetReturnValue().SetNull();
}

void IOSTContractStorage_MapHas(const FunctionCallbackInfo<Value> &args) {
    Isolate *isolate = args.GetIsolate();
    Local<Object> self = args.Holder();

    if (args.Length() != 3) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_MapHas invalid argument length")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> key = args[0];
    if (!key->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_MapHas key must be string")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> field = args[1];
    if (!field->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_MapHas key must be string")
        );
        isolate->ThrowException(err);
        return;
    }
    Local<Value> ramPayer = args[2];
    if (!ramPayer->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_MapHas ramPayer must be string.")
        );
        isolate->ThrowException(err);
        return;
    }

    NewCStrChecked(keyStr, key, isolate);
    NewCStrChecked(fieldStr, field, isolate);
    NewCStrChecked(ramPayerStr, ramPayer, isolate);
    bool result;

    Local<External> extVal = Local<External>::Cast(self->GetInternalField(0));
    if (!extVal->IsExternal()) {
        std::cout << "IOSTContractStorage_MapHas val error" << std::endl;
        return;
    }

    IOSTContractStorage *ics = static_cast<IOSTContractStorage *>(extVal->Value());
    char *ret = ics->MapHas(keyStr, fieldStr, ramPayerStr, &result);
    if (ret != nullptr) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, ret)
        );
        isolate->ThrowException(err);
        free(ret);
        return;
    }
    args.GetReturnValue().Set(result);
}

void IOSTContractStorage_MapGet(const FunctionCallbackInfo<Value> &args) {
    Isolate *isolate = args.GetIsolate();
    Local<Object> self = args.Holder();

    if (args.Length() != 3) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_MapGet invalid argument length")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> key = args[0];
    if (!key->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_MapGet key must be string")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> field = args[1];
    if (!field->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_MapGet key must be string")
        );
        isolate->ThrowException(err);
        return;
    }
    Local<Value> ramPayer = args[2];
    if (!ramPayer->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_MapGet ramPayer must be string.")
        );
        isolate->ThrowException(err);
        return;
    }

    NewCStrChecked(keyStr, key, isolate);
    NewCStrChecked(fieldStr, field, isolate);
    NewCStrChecked(ramPayerStr, ramPayer, isolate);
    CStr resultStr = {nullptr, 0};

    Local<External> extVal = Local<External>::Cast(self->GetInternalField(0));
    if (!extVal->IsExternal()) {
        std::cout << "IOSTContractStorage_MapGet val error" << std::endl;
        return;
    }

    IOSTContractStorage *ics = static_cast<IOSTContractStorage *>(extVal->Value());
    char *ret = ics->MapGet(keyStr, fieldStr, ramPayerStr, &resultStr);
    if (ret != nullptr) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, ret)
        );
        isolate->ThrowException(err);
        free(ret);
        return;
    }
    if (resultStr.data == nullptr) {
        args.GetReturnValue().SetNull();
    } else {
        args.GetReturnValue().Set(String::NewFromUtf8(isolate, resultStr.data, String::kNormalString, resultStr.size));
        free(resultStr.data);
    }
}

void IOSTContractStorage_MapDel(const FunctionCallbackInfo<Value> &args) {
    Isolate *isolate = args.GetIsolate();
    Local<Object> self = args.Holder();

    if (args.Length() != 3) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_MapDel invalid argument length")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> key = args[0];
    if (!key->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_MapDel key must be string")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> field = args[1];
    if (!field->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_MapDel key must be string")
        );
        isolate->ThrowException(err);
        return;
    }
    Local<Value> ramPayer = args[2];
    if (!ramPayer->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_MapDel ramPayer must be string.")
        );
        isolate->ThrowException(err);
        return;
    }

    NewCStrChecked(keyStr, key, isolate);
    NewCStrChecked(fieldStr, field, isolate);
    NewCStrChecked(ramPayerStr, ramPayer, isolate);

    Local<External> extVal = Local<External>::Cast(self->GetInternalField(0));
    if (!extVal->IsExternal()) {
        std::cout << "IOSTContractStorage_MapDel val error" << std::endl;
        return;
    }

    IOSTContractStorage *ics = static_cast<IOSTContractStorage *>(extVal->Value());
    char *ret = ics->MapDel(keyStr, fieldStr, ramPayerStr);
    if (ret != nullptr) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, ret)
        );
        isolate->ThrowException(err);
        free(ret);
        return;
    }
    args.GetReturnValue().SetNull();
}

void IOSTContractStorage_MapKeys(const FunctionCallbackInfo<Value> &args) {
    Isolate *isolate = args.GetIsolate();
    Local<Object> self = args.Holder();

    if (args.Length() != 2) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_MapKeys invalid argument length")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> key = args[0];
    if (!key->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_MapKeys key must be string")
        );
        isolate->ThrowException(err);
        return;
    }
    Local<Value> ramPayer = args[1];
    if (!ramPayer->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_MapKeys ramPayer must be string.")
        );
        isolate->ThrowException(err);
        return;
    }

    NewCStrChecked(keyStr, key, isolate);
    NewCStrChecked(ramPayerStr, ramPayer, isolate);
    CStr resultStr = {nullptr, 0};

    Local<External> extVal = Local<External>::Cast(self->GetInternalField(0));
    if (!extVal->IsExternal()) {
        std::cout << "IOSTContractStorage_MapKeys val error" << std::endl;
        return;
    }

    IOSTContractStorage *ics = static_cast<IOSTContractStorage *>(extVal->Value());
    char *ret = ics->MapKeys(keyStr, ramPayerStr, &resultStr);
    if (ret != nullptr) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, ret)
        );
        isolate->ThrowException(err);
        free(ret);
        return;
    }
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, resultStr.data, String::kNormalString, resultStr.size));
    if (resultStr.data != nullptr) free(resultStr.data);
}

void IOSTContractStorage_MapLen(const FunctionCallbackInfo<Value> &args) {
    Isolate *isolate = args.GetIsolate();
    Local<Object> self = args.Holder();

    if (args.Length() != 2) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_MapLen invalid argument length")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> key = args[0];
    if (!key->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_MapLen key must be string")
        );
        isolate->ThrowException(err);
        return;
    }
    Local<Value> ramPayer = args[1];
    if (!ramPayer->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_MapLen ramPayer must be string.")
        );
        isolate->ThrowException(err);
        return;
    }

    NewCStrChecked(keyStr, key, isolate);
    NewCStrChecked(ramPayerStr, ramPayer, isolate);
    size_t result;

    Local<External> extVal = Local<External>::Cast(self->GetInternalField(0));
    if (!extVal->IsExternal()) {
        std::cout << "IOSTContractStorage_MapLen val error" << std::endl;
        return;
    }

    IOSTContractStorage *ics = static_cast<IOSTContractStorage *>(extVal->Value());
    char *ret = ics->MapLen(keyStr, ramPayerStr, &result);
    if (ret != nullptr) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, ret)
        );
        isolate->ThrowException(err);
        free(ret);
        return;
    }
    args.GetReturnValue().Set((int)result);
}

void IOSTContractStorage_GlobalHas(const FunctionCallbackInfo<Value> &args) {
    Isolate *isolate = args.GetIsolate();
    Local<Object> self = args.Holder();

    if (args.Length() != 3) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_GlobalHas invalid argument length")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> contract = args[0];
    if (!contract->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_GlobalHas contract must be string")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> key = args[1];
    if (!key->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_GlobalHas key must be string")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> ramPayer = args[2];
    if (!ramPayer->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_GlobalHas ramPayer must be string.")
        );
        isolate->ThrowException(err);
        return;
    }

    NewCStrChecked(contractStr, contract, isolate);
    NewCStrChecked(keyStr, key, isolate);
    NewCStrChecked(ramPayerStr, ramPayer, isolate);
    bool result;

    Local<External> extVal = Local<External>::Cast(self->GetInternalField(0));
    if (!extVal->IsExternal()) {
        std::cout << "IOSTContractStorage_GlobalHas val error" << std::endl;
        return;
    }

    IOSTContractStorage *ics = static_cast<IOSTContractStorage *>(extVal->Value());
    char *ret = ics->GlobalHas(contractStr, keyStr, ramPayerStr, &result);
    if (ret != nullptr) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, ret)
        );
        isolate->ThrowException(err);
        free(ret);
        return;
    }
    args.GetReturnValue().Set(result);
}

void IOSTContractStorage_GlobalGet(const FunctionCallbackInfo<Value> &args) {
    Isolate *isolate = args.GetIsolate();
    Local<Object> self = args.Holder();

    if (args.Length() != 3) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_GlobalGet invalid argument length")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> contract = args[0];
    if (!contract->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_GlobalGet contract must be string")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> key = args[1];
    if (!key->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_GlobalGet key must be string")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> ramPayer = args[2];
    if (!ramPayer->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_GlobalGet ramPayer must be string.")
        );
        isolate->ThrowException(err);
        return;
    }

    NewCStrChecked(contractStr, contract, isolate);
    NewCStrChecked(keyStr, key, isolate);
    NewCStrChecked(ramPayerStr, ramPayer, isolate);
    CStr resultStr = {nullptr, 0};

    Local<External> extVal = Local<External>::Cast(self->GetInternalField(0));
    if (!extVal->IsExternal()) {
        std::cout << "IOSTContractStorage_GlobalGet val error" << std::endl;
        return;
    }

    IOSTContractStorage *ics = static_cast<IOSTContractStorage *>(extVal->Value());
    char *ret = ics->GlobalGet(contractStr, keyStr, ramPayerStr, &resultStr);
    if (ret != nullptr) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, ret)
        );
        isolate->ThrowException(err);
        free(ret);
        return;
    }
    if (resultStr.data == nullptr) {
        args.GetReturnValue().SetNull();
    } else {
        args.GetReturnValue().Set(String::NewFromUtf8(isolate, resultStr.data, String::kNormalString, resultStr.size));
        free(resultStr.data);
    }
}

void IOSTContractStorage_GlobalMapHas(const FunctionCallbackInfo<Value> &args) {
    Isolate *isolate = args.GetIsolate();
    Local<Object> self = args.Holder();

    if (args.Length() != 4) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_GlobalMapHas invalid argument length")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> contract = args[0];
    if (!contract->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_GlobalMapHas contract must be string")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> key = args[1];
    if (!key->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_GlobalMapHas key must be string")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> field = args[2];
    if (!field->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_GlobalMapHas field must be string")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> ramPayer = args[3];
    if (!ramPayer->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_GlobalMapHas ramPayer must be string.")
        );
        isolate->ThrowException(err);
        return;
    }

    NewCStrChecked(contractStr, contract, isolate);
    NewCStrChecked(keyStr, key, isolate);
    NewCStrChecked(fieldStr, field, isolate);
    NewCStrChecked(ramPayerStr, ramPayer, isolate);
    bool result;

    Local<External> extVal = Local<External>::Cast(self->GetInternalField(0));
    if (!extVal->IsExternal()) {
        std::cout << "IOSTContractStorage_GlobalMapHas val error" << std::endl;
        return;
    }

    IOSTContractStorage *ics = static_cast<IOSTContractStorage *>(extVal->Value());
    char *ret = ics->GlobalMapHas(contractStr, keyStr, fieldStr, ramPayerStr, &result);
    if (ret != nullptr) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, ret)
        );
        isolate->ThrowException(err);
        free(ret);
        return;
    }
    args.GetReturnValue().Set(result);
}

void IOSTContractStorage_GlobalMapGet(const FunctionCallbackInfo<Value> &args) {
    Isolate *isolate = args.GetIsolate();
    Local<Object> self = args.Holder();

    if (args.Length() != 4) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_GlobalMapGet invalid argument length")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> contract = args[0];
    if (!contract->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_GlobalMapGet contract must be string")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> key = args[1];
    if (!key->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_GlobalMapGet key must be string")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> field = args[2];
    if (!field->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_GlobalMapGet field must be string")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> ramPayer = args[3];
    if (!ramPayer->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_GlobalMapGet ramPayer must be string.")
        );
        isolate->ThrowException(err);
        return;
    }

    NewCStrChecked(contractStr, contract, isolate);
    NewCStrChecked(keyStr, key, isolate);
    NewCStrChecked(fieldStr, field, isolate);
    NewCStrChecked(ramPayerStr, ramPayer, isolate);
    CStr resultStr = {nullptr, 0};

    Local<External> extVal = Local<External>::Cast(self->GetInternalField(0));
    if (!extVal->IsExternal()) {
        std::cout << "IOSTContractStorage_GlobalMapGet val error" << std::endl;
        return;
    }

    IOSTContractStorage *ics = static_cast<IOSTContractStorage *>(extVal->Value());
    char *ret = ics->GlobalMapGet(contractStr, keyStr, fieldStr, ramPayerStr, &resultStr);
    if (ret != nullptr) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, ret)
        );
        isolate->ThrowException(err);
        free(ret);
        return;
    }
    if (resultStr.data == nullptr) {
        args.GetReturnValue().SetNull();
    } else {
        args.GetReturnValue().Set(String::NewFromUtf8(isolate, resultStr.data, String::kNormalString, resultStr.size));
        free(resultStr.data);
    }
}

void IOSTContractStorage_GlobalMapKeys(const FunctionCallbackInfo<Value> &args) {
    Isolate *isolate = args.GetIsolate();
    Local<Object> self = args.Holder();

    if (args.Length() != 3) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_GlobalMapKeys invalid argument length")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> contract = args[0];
    if (!contract->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_GlobalMapKeys contract must be string")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> key = args[1];
    if (!key->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_GlobalMapKeys key must be string")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> ramPayer = args[2];
    if (!ramPayer->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_GlobalMapKeys ramPayer must be string.")
        );
        isolate->ThrowException(err);
        return;
    }

    NewCStrChecked(contractStr, contract, isolate);
    NewCStrChecked(keyStr, key, isolate);
    NewCStrChecked(ramPayerStr, ramPayer, isolate);
    CStr resultStr = {nullptr, 0};

    Local<External> extVal = Local<External>::Cast(self->GetInternalField(0));
    if (!extVal->IsExternal()) {
        std::cout << "IOSTContractStorage_GlobalMapKeys val error" << std::endl;
        return;
    }

    IOSTContractStorage *ics = static_cast<IOSTContractStorage *>(extVal->Value());
    char *ret = ics->GlobalMapKeys(contractStr, keyStr, ramPayerStr, &resultStr);
    if (ret != nullptr) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, ret)
        );
        isolate->ThrowException(err);
        free(ret);
        return;
    }
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, resultStr.data, String::kNormalString, resultStr.size));
    if (resultStr.data != nullptr) free(resultStr.data);
}

void IOSTContractStorage_GlobalMapLen(const FunctionCallbackInfo<Value> &args) {
    Isolate *isolate = args.GetIsolate();
    Local<Object> self = args.Holder();

    if (args.Length() != 3) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_GlobalMapLen invalid argument length")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> contract = args[0];
    if (!contract->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_GlobalMapLen contract must be string")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> key = args[1];
    if (!key->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_GlobalMapLen key must be string")
        );
        isolate->ThrowException(err);
        return;
    }

    Local<Value> ramPayer = args[2];
    if (!ramPayer->IsString()) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, "IOSTContractStorage_GlobalMapLen ramPayer must be string.")
        );
        isolate->ThrowException(err);
        return;
    }

    NewCStrChecked(contractStr, contract, isolate);
    NewCStrChecked(keyStr, key, isolate);
    NewCStrChecked(ramPayerStr, ramPayer, isolate);
    size_t result;

    Local<External> extVal = Local<External>::Cast(self->GetInternalField(0));
    if (!extVal->IsExternal()) {
        std::cout << "IOSTContractStorage_GlobalMapLen val error" << std::endl;
        return;
    }

    IOSTContractStorage *ics = static_cast<IOSTContractStorage *>(extVal->Value());
    char *ret = ics->GlobalMapLen(contractStr, keyStr, ramPayerStr, &result);
    if (ret != nullptr) {
        Local<Value> err = Exception::Error(
            String::NewFromUtf8(isolate, ret)
        );
        isolate->ThrowException(err);
        free(ret);
        return;
    }
    args.GetReturnValue().Set((int)result);
}

void InitStorage(Isolate *isolate, Local<ObjectTemplate> globalTpl) {
    Local<FunctionTemplate> storageClass =
        FunctionTemplate::New(isolate, NewIOSTContractStorage);
    Local<String> storageClassName = String::NewFromUtf8(isolate, "IOSTStorage");
    storageClass->SetClassName(storageClassName);

    Local<ObjectTemplate> storageTpl = storageClass->InstanceTemplate();
    storageTpl->SetInternalFieldCount(1);
    storageTpl->Set(
        String::NewFromUtf8(isolate, "put"),
        FunctionTemplate::New(isolate, IOSTContractStorage_Put)
    );
    storageTpl->Set(
        String::NewFromUtf8(isolate, "has"),
        FunctionTemplate::New(isolate, IOSTContractStorage_Has)
    );
    storageTpl->Set(
        String::NewFromUtf8(isolate, "get"),
        FunctionTemplate::New(isolate, IOSTContractStorage_Get)
    );
    storageTpl->Set(
            String::NewFromUtf8(isolate, "del"),
            FunctionTemplate::New(isolate, IOSTContractStorage_Del)
    );
    storageTpl->Set(
        String::NewFromUtf8(isolate, "mapPut"),
        FunctionTemplate::New(isolate, IOSTContractStorage_MapPut)
    );
    storageTpl->Set(
        String::NewFromUtf8(isolate, "mapHas"),
        FunctionTemplate::New(isolate, IOSTContractStorage_MapHas)
    );
    storageTpl->Set(
        String::NewFromUtf8(isolate, "mapGet"),
        FunctionTemplate::New(isolate, IOSTContractStorage_MapGet)
    );
    storageTpl->Set(
        String::NewFromUtf8(isolate, "mapDel"),
        FunctionTemplate::New(isolate, IOSTContractStorage_MapDel)
    );
    storageTpl->Set(
        String::NewFromUtf8(isolate, "mapKeys"),
        FunctionTemplate::New(isolate, IOSTContractStorage_MapKeys)
    );
    storageTpl->Set(
        String::NewFromUtf8(isolate, "mapLen"),
        FunctionTemplate::New(isolate, IOSTContractStorage_MapLen)
    );
    // todo
    storageTpl->Set(
        String::NewFromUtf8(isolate, "globalGet"),
        FunctionTemplate::New(isolate, IOSTContractStorage_GlobalGet)
    );
    storageTpl->Set(
        String::NewFromUtf8(isolate, "globalHas"),
        FunctionTemplate::New(isolate, IOSTContractStorage_GlobalHas)
    );
    storageTpl->Set(
        String::NewFromUtf8(isolate, "globalMapHas"),
        FunctionTemplate::New(isolate, IOSTContractStorage_GlobalMapHas)
    );
    storageTpl->Set(
        String::NewFromUtf8(isolate, "globalMapGet"),
        FunctionTemplate::New(isolate, IOSTContractStorage_GlobalMapGet)
    );
    storageTpl->Set(
        String::NewFromUtf8(isolate, "globalMapKeys"),
        FunctionTemplate::New(isolate, IOSTContractStorage_GlobalMapKeys)
    );
    storageTpl->Set(
        String::NewFromUtf8(isolate, "globalMapLen"),
        FunctionTemplate::New(isolate, IOSTContractStorage_GlobalMapLen)
    );


    globalTpl->Set(storageClassName, storageClass);
}
