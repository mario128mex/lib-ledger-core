// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from callback.djinni

#include "BitcoinLikePublicKeyCompletionBlock.hpp"  // my header
#include "BitcoinLikePublicKey.hpp"
#include "Error.hpp"
#include "Marshal.hpp"

namespace djinni_generated {

BitcoinLikePublicKeyCompletionBlock::BitcoinLikePublicKeyCompletionBlock() : ::djinni::JniInterface<::ledger::core::api::BitcoinLikePublicKeyCompletionBlock, BitcoinLikePublicKeyCompletionBlock>("co/ledger/core/BitcoinLikePublicKeyCompletionBlock$CppProxy") {}

BitcoinLikePublicKeyCompletionBlock::~BitcoinLikePublicKeyCompletionBlock() = default;


CJNIEXPORT void JNICALL Java_co_ledger_core_BitcoinLikePublicKeyCompletionBlock_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::ledger::core::api::BitcoinLikePublicKeyCompletionBlock>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_co_ledger_core_BitcoinLikePublicKeyCompletionBlock_00024CppProxy_native_1complete(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_result, jobject j_error)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::BitcoinLikePublicKeyCompletionBlock>(nativeRef);
        ref->complete(::djinni::Optional<std::experimental::optional, ::djinni_generated::BitcoinLikePublicKey>::toCpp(jniEnv, j_result),
                      ::djinni::Optional<std::experimental::optional, ::djinni_generated::Error>::toCpp(jniEnv, j_error));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

}  // namespace djinni_generated
