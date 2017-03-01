// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from wallet_pool.djinni

#include "BitcoinLikeWalletCallback.hpp"  // my header
#include "BitcoinLikeWallet.hpp"
#include "Error.hpp"
#include "Marshal.hpp"

namespace djinni_generated {

BitcoinLikeWalletCallback::BitcoinLikeWalletCallback() : ::djinni::JniInterface<::ledger::core::api::BitcoinLikeWalletCallback, BitcoinLikeWalletCallback>() {}

BitcoinLikeWalletCallback::~BitcoinLikeWalletCallback() = default;

BitcoinLikeWalletCallback::JavaProxy::JavaProxy(JniType j) : Handle(::djinni::jniGetThreadEnv(), j) { }

BitcoinLikeWalletCallback::JavaProxy::~JavaProxy() = default;

void BitcoinLikeWalletCallback::JavaProxy::onCallback(const std::shared_ptr<::ledger::core::api::BitcoinLikeWallet> & c_result, const std::experimental::optional<::ledger::core::api::Error> & c_error) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::BitcoinLikeWalletCallback>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_onCallback,
                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni_generated::BitcoinLikeWallet>::fromCpp(jniEnv, c_result)),
                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni_generated::Error>::fromCpp(jniEnv, c_error)));
    ::djinni::jniExceptionCheck(jniEnv);
}

}  // namespace djinni_generated