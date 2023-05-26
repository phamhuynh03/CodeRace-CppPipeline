#include <assert.h>
#include "code_with_bugs.cpp"
#include <cifuzz/cifuzz.h>
#include <fuzzer/FuzzedDataProvider.h>

FUZZ_TEST_SETUP()
{
  // Perform any one-time setup required by the FUZZ_TEST function.
}

FUZZ_TEST(const uint8_t *data, size_t size)
{
  FuzzDataProvider fuzzed_data(data, size);
  int a = fuzzed_data.ConsumeIntegral();
  int b = fuzzed_data.ConsumeIntegral();
  std::string c = fuzzed_data.ConsumeRandomLengthString();
  exploreMe(a, b, c);
}
