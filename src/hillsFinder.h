#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdint>
#include <ranges>

using size_t = std::size_t;

std::vector<float> readBinaryFile(const std::string &filename);
double median(std::vector<float> data);
std::vector<std::pair<int32_t, int32_t>> findHills(const std::vector<float> &data, int32_t minWidth, int32_t maxWidth);
void saveResults(const std::string &filename, const std::vector<std::pair<int32_t, int32_t>> &hills);

