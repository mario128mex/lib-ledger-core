// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from callback.djinni

#include "StringCompletionBlock.hpp"  // my header
#include "Error.hpp"
#include "Marshal.hpp"

namespace djinni_generated {

StringCompletionBlock::StringCompletionBlock() : ::djinni::JniInterface<::ledger::core::api::StringCompletionBlock, StringCompletionBlock>("co/ledger/core/StringCompletionBlock$CppProxy") {}

StringCompletionBlock::~StringCompletionBlock() = default;


CJNIEXPORT void JNICALL Java_co_ledger_core_StringCompletionBlock_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::ledger::core::api::StringCompletionBlock>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_co_ledger_core_StringCompletionBlock_00024CppProxy_native_1complete(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_result, jobject j_error)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::StringCompletionBlock>(nativeRef);
        ref->complete(::djinni::Optional<std::experimental::optional, ::djinni::String>::toCpp(jniEnv, j_result),
                      ::djinni::Optional<std::experimental::optional, ::djinni_generated::Error>::toCpp(jniEnv, j_error));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

}  // namespace djinni_generated
