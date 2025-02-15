#include "hillsFinder.h"

int main(int argc, char *argv[]) {
  if (argc != 5) {
    std::cerr << "Usage: " << argv[0] << " <input_file> <output_file> "
                                         "<min_width> <max_width>" << "\n";
    return 1;
  }

  const std::string inputFile = argv[1];
  const std::string outputFile = argv[2];
  const int32_t minWidth = std::stoi(argv[3]);
  const int32_t maxWidth = std::stoi(argv[4]);

  const std::vector<std::pair<int32_t, int32_t> > hills = findHills(readBinaryFile(inputFile), minWidth, maxWidth);
  saveResults(outputFile, hills);

  std::cout << "Found " << hills.size() << " hills, results you can see in " << outputFile << "\n";
  return 0;
}
