#include "hillsFinder.h"

using size_t = std::size_t;

std::vector<float> readBinaryFile(const std::string &filename) {
  std::ifstream file(filename, std::ios::binary);
  if (!file) {
    std::cerr << "Error opening file: " << filename << "\n";
    exit(1);
  }

  std::vector<float> data;
  float value;
  // C-style (reinterpret) cast because i need to take data from file as float
  // (i could use memcpy, but i choose this way)
  while (file.read(reinterpret_cast<char *>(&value), sizeof(float))) {
    data.push_back(value);
  }

  return data;
}

// I choose median method not window
// because it can detect hills like the biggest in file
double median(std::vector<float> data) {
  const size_t size = data.size();
  std::ranges::sort(data);
  if (size % 2 == 0)
    return (data[size / 2 - 1] + data[size / 2]) / 2.0;
  return data[size / 2];
}

// without copy elision for reusability
std::vector<std::pair<int32_t, int32_t> > findHills(const std::vector<float> &data, const int32_t minWidth,
                                                    const int32_t maxWidth) {
  std::vector<std::pair<int32_t, int32_t> > hills;
  const double med = median(data);
  bool inHill = false;
  int32_t left = 0;

  for (int32_t i = 0; i < data.size(); ++i) {
    if (!inHill && data[i] > med) {
      inHill = true;
      left = i;
    } else if (inHill && data[i] <= med) {
      int32_t right = i;
      if (const int32_t width = right - left;
        width >= minWidth && width <= maxWidth) {
        hills.emplace_back(left, right);
        }
      inHill = false;
    }
  }
  return hills;
}

void saveResults(const std::string &filename, const std::vector<std::pair<int32_t, int32_t> > &hills) {
  std::ofstream file(filename);
  if (!file) {
    std::cerr << "Error opening output file: " << filename << "\n";
    exit(1);
  }
  for (const auto &[fst, snd]: hills) {
    file << fst << " " << snd << "\n";
  }
}