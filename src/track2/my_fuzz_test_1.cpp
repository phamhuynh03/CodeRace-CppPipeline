#include <assert.h>

#include <cifuzz/cifuzz.h>
#include <fuzzer/FuzzedDataProvider.h>

FUZZ_TEST_SETUP() {
  // Perform any one-time setup required by the FUZZ_TEST function.
}

FUZZ_TEST(const uint8_t *data, size_t size) {
  // FuzzedDataProvider provides convenience methods that turn the raw fuzzer
  // data into common types. Use it to generate parameters for the function you
  // want to fuzz:
  //
  // FuzzedDataProvider fuzzed_data(data, size);
  // int my_int = fuzzed_data.ConsumeIntegral<int8_t>();
  // std::string my_string = fuzzed_data.ConsumeRandomLengthString();

  // Call the functions you want to test with the provided data and optionally
  // assert that the results are as expected:
  //
  // int res = DoSomething(my_int, my_string);
  // assert(res != -1);

  // If you want to know more about writing fuzz tests you can check out the
  // example projects at https://github.com/CodeIntelligenceTesting/cifuzz/tree/main/examples
  // or have a look at our docs at https://docs.code-intelligence.com/
}
