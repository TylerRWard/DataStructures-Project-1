#ifndef SORT_HPP
#define SORT_HPP

#include <string>

void bubble(std::string * arr, int n);

void merge(std::string * arr, int left, int right);

void quick(std::string * arr, int low, int high);

void heap(std::string * arr, int n);

#endif