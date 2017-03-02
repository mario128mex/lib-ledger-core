// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from callback.djinni

#pragma once

#include "../../api/BitcoinLikeWalletCallback.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class BitcoinLikeWalletCallback final : ::djinni::JniInterface<::ledger::core::api::BitcoinLikeWalletCallback, BitcoinLikeWalletCallback> {
public:
    using CppType = std::shared_ptr<::ledger::core::api::BitcoinLikeWalletCallback>;
    using CppOptType = std::shared_ptr<::ledger::core::api::BitcoinLikeWalletCallback>;
    using JniType = jobject;

    using Boxed = BitcoinLikeWalletCallback;

    ~BitcoinLikeWalletCallback();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<BitcoinLikeWalletCallback>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<BitcoinLikeWalletCallback>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    BitcoinLikeWalletCallback();
    friend ::djinni::JniClass<BitcoinLikeWalletCallback>;
    friend ::djinni::JniInterface<::ledger::core::api::BitcoinLikeWalletCallback, BitcoinLikeWalletCallback>;

    class JavaProxy final : ::djinni::JavaProxyHandle<JavaProxy>, public ::ledger::core::api::BitcoinLikeWalletCallback
    {
    public:
        JavaProxy(JniType j);
        ~JavaProxy();

        void onCallback(const std::shared_ptr<::ledger::core::api::BitcoinLikeWallet> & result, const std::experimental::optional<::ledger::core::api::Error> & error) override;

    private:
        friend ::djinni::JniInterface<::ledger::core::api::BitcoinLikeWalletCallback, ::djinni_generated::BitcoinLikeWalletCallback>;
    };

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("co/ledger/core/BitcoinLikeWalletCallback") };
    const jmethodID method_onCallback { ::djinni::jniGetMethodID(clazz.get(), "onCallback", "(Lco/ledger/core/BitcoinLikeWallet;Lco/ledger/core/Error;)V") };
};

}  // namespace djinni_generated
