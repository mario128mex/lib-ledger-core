const CommNodeHid = require("@ledgerhq/hw-transport-node-hid").default;
const Btc = require("@ledgerhq/hw-app-btc").default;

const {
  createWallet,
  createAccount,
  createAmount,
  getCurrency,
  subscribeToEventBus
} = require("../index");

console.log(`>> Waiting for device...`);

// const CURRENCY = {
//   walletType: "bitcoin",
//   name: "bitcoin",
//   bip44CoinType: 0,
//   paymentUriScheme: "bitcoin",
//   units: [
//     {
//       name: "bitcoin",
//       symbol: "BTC",
//       code: "BTC",
//       numberOfDecimal: 8
//     }
//   ],
//   bitcoinLikeNetworkParameters: getBitcoinLikeNetworkParameters()
// };

CommNodeHid.listen({
  error: () => {},
  complete: () => {},
  next: async e => {
    if (!e.device) {
      return;
    }

    if (e.type === "add") {
      console.log(`added ${JSON.stringify(e)}`);
      try {
        const transport = await CommNodeHid.open(e.device.path);
        const btc = new Btc(transport);

        const currency = await getCurrency("bitcoin_testnet");

        const wallet = await createWallet("khalil", currency);
        const accountCreationInfos = await wallet.getNextAccountCreationInfo();

        await accountCreationInfos.derivations.reduce((promise, derivation) => {
          return promise.then(async () => {
            const {
              publicKey,
              chainCode,
              bitcoinAddress
            } = await btc.getWalletPublicKey(derivation);
            accountCreationInfos.publicKeys.push(fromHexToBytes(publicKey));
            accountCreationInfos.chainCodes.push(fromHexToBytes(chainCode));
          });
        }, Promise.resolve());

        const ADDRESS_TO_SEND = "mzaYScsZFRECzTnn6kbcbK2UcX6bri5Ck4";

        console.log(`> Creating account...`);
        const account = await createAccount(wallet, accountCreationInfos);
        const freshAddresses = await account.getFreshPublicAddresses();

        const eventBus = account.synchronize();

        subscribeToEventBus(eventBus, async e => {
          console.log(`we are here-----------------------------------------`);
          console.log(e.getPayload().dump());
          // const balance = await account.getBalance();
          // console.log(e);
        });

        return;

        const balance = await account.getBalance();
        console.log(balance.toString());

        console.log(balance);

        console.log(`> Creating transaction...`);
        const bitcoinLikeAccount = account.asBitcoinLikeAccount();
        const walletCurrency = wallet.getCurrency();
        const amount = createAmount(walletCurrency, 10000);
        const fees = createAmount(walletCurrency, 10);

        const transactionBuilder = bitcoinLikeAccount.buildTransaction();
        transactionBuilder.sendToAddress(amount, ADDRESS_TO_SEND);
        transactionBuilder.pickInputs(1, 0xffffff);
        transactionBuilder.setFeesPerByte(fees);
        const bitcoinLikeTransaction = await transactionBuilder.build();
        console.log(bitcoinLikeTransaction);

        process.exit(0);

        // console.log(account.getIndex());
        // console.log(account.isSynchronizing());
      } catch (err) {
        console.log(err);
      }
    }

    if (e.type === "remove") {
      console.log(`removed ${JSON.stringify(e)}`);
    }
  }
});

function fromHexToBytes(str) {
  for (var bytes = [], c = 0; c < str.length; c += 2) {
    bytes.push(parseInt(str.substr(c, 2), 16));
  }
  return bytes;
}
