// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from callback.djinni
import Foundation

final class AccountListCallback: NSObject, LGAccountListCallback {
    private var onCallbackBlock: ((NSArray?, LGError?) -> Void)?

    func setOnCallback(_ block: @escaping (NSArray?, LGError?) -> Void) -> AccountListCallback {
        self.onCallbackBlock = block
        return self
    }

    func onCallback(_ result: NSArray?, error: LGError?) -> Void {
        self.onCallbackBlock?(result, error)
    }
}